##
## EPITECH PROJECT, 2018
## nm objdump
## File description:
## makefile
##

CC		=	gcc -g3

RM		=	rm -rf

NM_NAME		=	my_nm

DUMP_NAME	=	my_objdump

TEST_NAME	=	test_run

CFLAGS		+=	-I./nm/includes/ -I./objdump/includes/ -I./common/includes/ -W -Wall -Wextra #-Werror

LDFLAGS		+=	-lcriterion

COMMON_SRC	=	common/src/check.c		\
			common/src/mapping.c		\
			common/src/assignation.c

NM_SRC		=	nm/src/nm.c			\
			nm/src/display.c		\
			nm/src/assignation.c		\
			nm/src/symbol_flag_finder.c	\
			nm/src/symbol_manipulation.c

DUMP_SRC	=	objdump/src/objdump.c		\
			objdump/src/display.c

NM_MAIN_SRC	=	nm/src/main.c

DUMP_MAIN_SRC	=	objdump/src/main.c

NM_OBJ		=	$(NM_SRC:.c=.o)

DUMP_OBJ	=	$(DUMP_SRC:.c=.o)

COMMON_OBJ	=	$(COMMON_SRC:.c=.o)

NM_OBJ_MAIN	=	$(NM_MAIN_SRC:.c=.o)

DUMP_OBJ_MAIN	=	$(DUMP_MAIN_SRC:.c=.o)

TEST_SRC	=	tests/outputs.c

TEST_OBJ	=	$(TEST_SRC:.c=.o)

$(NAME):		all

all:			$(NM_NAME) $(DUMP_NAME)

$(NM_NAME):			$(COMMON_OBJ) $(NM_OBJ) $(NM_OBJ_MAIN)
			$(CC) -o $(NM_NAME) $(COMMON_OBJ) $(NM_OBJ) $(NM_OBJ_MAIN)

$(DUMP_NAME):			$(COMMON_OBJ) $(DUMP_OBJ) $(DUMP_OBJ_MAIN)
			$(CC) -o $(DUMP_NAME) $(COMMON_OBJ) $(DUMP_OBJ) $(DUMP_OBJ_MAIN)

tests_run:			$(COMMON_OBJ) $(NM_OBJ) $(TEST_OBJ)
			$(CC) -o $(TEST_NAME) $(COMMON_OBJ) $(NM_OBJ) $(TEST_OBJ) $(LDFLAGS) --coverage
			./test_run

nm:			$(NM_NAME)

objdump:		$(DUMP_NAME)

clean:
			$(RM) $(NM_OBJ) $(TEST_OBJ) $(NM_OBJ_MAIN) $(DUMP_OBJ) $(DUMP_OBJ_MAIN) $(COMMON_OBJ)

fclean:			clean
			$(RM) $(NM_NAME) $(DUMP_NAME) $(TEST_NAME)

re:			fclean all

go:			re
			$(RM) $(NM_OBJ) $(DUMP_OBJ) $(COMMON_OBJ) $(TEST_OBJ) $(NM_OBJ_MAIN) $(DUMP_OBJ_MAIN)

.PHONY: 		all clean fclean re go test_run nm objdump
