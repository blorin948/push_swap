$(VERBOSE).SILENT:
NAME =  push_swap\
        checker\

FLAGS = gcc

INCLUDES = -Werror -Wextra -Wall

HEADERS =	push_swap.h\
			get_next_line.h

SRC_PUSH_SWAP =		main.c\
 					all_move.c\
					fcts.c\
					sort_tab.c\
					fonctions2.c\
					three_nbr.c\
					hundred_nbr.c\
					pa_pb.c\
					sa_sb_ra.c\
					ft_split.c

SRC_CHECKER =   checker.c\
				get_next_line.c\
				get_next_line_utils.c\
				fcts.c\
				all_move.c\
				sort_tab.c\
				fonctions2.c\
				pa_pb.c\
				sa_sb_ra.c\
				ft_split.c

OBJ_PUSH_SWAP = $(patsubst %.c, obj/%.o, $(SRC_PUSH_SWAP))

OBJ_CHECKER = $(patsubst %.c, obj/%.o, $(SRC_CHECKER))

all: $(NAME)

$(OBJ): ${HEADERS}

$(NAME): $(OBJ_PUSH_SWAP) $(OBJ_CHECKER)
	@echo "\n==> Making Push_Swap"
	$(FLAGS) $(INCLUDES) $(OBJ_PUSH_SWAP) -o push_swap
	@echo "\nPush_Swap Done !"
	@echo "\n==> Making Checker"
	$(FLAGS) $(INCLUDES) $(OBJ_CHECKER) -o checker
	@echo "\nChecker Done !"

obj/%.o: %.c
	mkdir -p obj
	$(FLAGS) $(INCLUDES) -c $< -o $@

norme:
	norminette *.c *.h

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all