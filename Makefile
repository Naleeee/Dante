##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

# Solver Related Stuff
SRC_SOLVER	=	solver/src/solver.c	\
				solver/src/map.c

OBJ_SOLVER	=	$(SRC_SOLVER:.c=.o)

SRC_MAIN_SOLVER	=	solver/src/main.c

OBJ_MAIN_SOLVER	=	 $(SRC_MAIN_SOLVER:.c=.o)

NAME_SOLVER	=	my_solver


# Generator Related Stuff
SRC_GENE	=	generator/src/generator.c	\
				generator/src/diger.c	\
				generator/src/randomizer.c

OBJ_GENE	=	$(SRC_GENE:.c=.o)

SRC_MAIN_GENE	=	generator/src/main.c

OBJ_MAIN_GENE	=	 $(SRC_MAIN_GENE:.c=.o)

NAME_GENE	=	my_generator



# Global Stuff
CFLAGS	+=	-W -Wall -Wextra

CFLAGS	+=	-Iinclude

CC	=	gcc

RM	=	rm -f

LDFLAGS	=	-Llib/ -lmy


# Unit Tests Related Stuff
TESTS	=	generator/tests/test_generator.c \
			solver/tests/test_solver.c

UNAME	=	unit_tests

CRITFLAGS	=	-lcriterion --coverage

HTMLFLAGS	=	--html --html-details -o website_test.html
HTMLFLAGS	+=	--html-title Test_criterion

PATH_COVERAGE	=	coverage/


# Rules
%.o: %.c
	@printf "[\033[0;32mLink\033[0m] % 36s\n" $< | tr ' ' '-'
	@$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

all:	solver	generator

debug:	CFLAGS	+=	-g
debug:	all

solver:	$(NAME_SOLVER)

generator:	$(NAME_GENE)

$(NAME_SOLVER):	$(OBJ_SOLVER)	$(OBJ_MAIN_SOLVER)
	@printf "[\033[0;35mLibrary\033[0m] % 33s\n" "MAKE" | tr ' ' '-'
	@make -C lib/my --no-print-directory
	@$(CC) -o $(NAME_SOLVER) $(OBJ_SOLVER) $(OBJ_MAIN_SOLVER) $(LDFLAGS)
	@printf "[\033[0;34mBuild\033[0m] % 35s\n" $(NAME_SOLVER) | tr ' ' '-'

$(NAME_GENE):	$(OBJ_GENE)	$(OBJ_MAIN_GENE)
	@printf "[\033[0;35mLibrary\033[0m] % 33s\n" "MAKE" | tr ' ' '-'
	@make -C lib/my --no-print-directory
	@$(CC) -o $(NAME_GENE) $(OBJ_GENE) $(OBJ_MAIN_GENE) $(LDFLAGS)
	@printf "[\033[0;34mBuild\033[0m] % 35s\n" $(NAME_GENE) | tr ' ' '-'

tests_run:	all
	@mkdir -p $(PATH_COVERAGE)
	@printf "[\033[0;35mSetup\033[0m] % 35s\n" $(PATH_COVERAGE) | tr ' ' '-'
	@printf "[\033[0;32mLink\033[0m] % 36s\n" $(TESTS) | tr ' ' '-'
	@$(CC) -o $(UNAME) $(SRC_SOLVER) $(SRC_GENE) $(TESTS) $(CRITFLAGS) $(LDFLAGS) $(CFLAGS)
	@printf "[\033[0;34mBuild\033[0m] % 35s\n" $(UNAME) | tr ' ' '-'
	@./$(UNAME)
	@mv *.gc* $(PATH_COVERAGE)
	@$(RM) $(UNAME)
	@printf "[\033[0;33mDelete\033[0m] % 34s\n" $(UNAME) | tr ' ' '-'

coverage:	tests_run
	@printf "[\033[0;35mCoverage\033[0m] % 32s\n" "Lines" | tr ' ' '-'
	@gcovr --exclude tests/
	@printf "[\033[0;35mCoverage\033[0m] % 32s\n" "Branches" | tr ' ' '-'
	@gcovr --exclude tests/ --branches

html:	tests_run
	@printf "[\033[0;35mCoverage\033[0m] % 32s\n" "Lines/Branches" | tr ' ' '-'
	@gcovr $(HTMLFLAGS) -r ./ --exclude tests/
	@mv *.html $(PATH_COVERAGE)
	@printf "[\033[0;35mWebVersion\033[0m] % 30s\n" $(PATH_COVERAGE) | tr ' ' '-'
	@/usr/bin/firefox $(PATH_COVERAGE)/website_test.html

clean:
	@$(RM) $(NAME_SOLVER)
	@printf "[\033[0;33mDelete\033[0m] % 34s\n" $(NAME_SOLVER) | tr ' ' '-'
	@$(RM) $(NAME_GENE)
	@printf "[\033[0;33mDelete\033[0m] % 34s\n" $(NAME_GENE) | tr ' ' '-'

tclean:
	@$(RM) $(PATH_COVERAGE)*
	@printf "[\033[0;33mDelete\033[0m] % 34s\n" $(PATH_COVERAGE) | tr ' ' '-'

fclean:	clean	tclean
	@printf "[\033[0;35mLibrary\033[0m] % 33s\n" "FCLEAN" | tr ' ' '-'
	@make -C lib/my --no-print-directory fclean
	@$(RM) $(OBJ_SOLVER)
	@printf "[\033[0;31mDelete\033[0m] % 34s\n" $(OBJ_SOLVER) | tr ' ' '-'
	@$(RM) $(OBJ_MAIN_SOLVER)
	@printf "[\033[0;31mDelete\033[0m] % 34s\n" $(OBJ_MAIN_SOLVER) | tr ' ' '-'
	@$(RM) $(OBJ_GENE)
	@printf "[\033[0;31mDelete\033[0m] % 34s\n" $(OBJ_GENE) | tr ' ' '-'
	@$(RM) $(OBJ_MAIN_GENE)
	@printf "[\033[0;31mDelete\033[0m] % 34s\n" $(OBJ_MAIN_GENE) | tr ' ' '-'
	@$(RM) *.html
	@printf "[\033[0;33mDelete\033[0m] % 34s\n" ".html" | tr ' ' '-'
	@$(RM) *.css
	@printf "[\033[0;33mDelete\033[0m] % 34s\n" ".css" | tr ' ' '-'
	@$(RM) vgcore*
	@printf "[\033[0;33mDelete\033[0m] % 34s\n" ".vgcore" | tr ' ' '-'
	@$(RM) *.gc*
	@printf "[\033[0;33mDelete\033[0m] % 34s\n" ".gcno" | tr ' ' '-'
	@printf "[\033[0;33mDelete\033[0m] % 34s\n" ".gcda" | tr ' ' '-'

re: fclean all

.PHONY: re fclean tclean clean html coverage tests_run generator solver debug all
