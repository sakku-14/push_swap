NAME		= push_swap
CHECKER			= checker
PUSH_SWAP_DIR	= ./ps_srcs
CHECKER_DIR		= ./ch_srcs

$(NAME):
	make -C $(PUSH_SWAP_DIR)
	cp $(PUSH_SWAP_DIR)/$(NAME) ./

all:	${NAME}

bonus:
	make -C $(CHECKER_DIR)
	cp $(CHECKER_DIR)/$(CHECKER) ./

clean:
	make -C $(CHECKER_DIR) clean;
	make -C $(PUSH_SWAP_DIR) clean;

fclean:
	make -C $(CHECKER_DIR) fclean;
	make -C $(PUSH_SWAP_DIR) fclean;
	rm -f $(NAME)
	rm -f $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re
