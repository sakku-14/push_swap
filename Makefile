PUSH_SWAP		= push_swap
CHECKER			= checker
PUSH_SWAP_DIR	= ./ps_srcs
CHECKER_DIR		= ./ch_srcs

all:
	make -C $(PUSH_SWAP_DIR)
	cp $(PUSH_SWAP_DIR)/$(PUSH_SWAP) ./
	make -C $(CHECKER_DIR)
	cp $(CHECKER_DIR)/$(CHECKER) ./

clean:
	make -C $(CHECKER_DIR) clean;
	make -C $(PUSH_SWAP_DIR) clean;

fclean:
	make -C $(CHECKER_DIR) fclean;
	make -C $(PUSH_SWAP_DIR) fclean;
	rm -f $(PUSH_SWAP)
	rm -f $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
