include tests.mak

TESTS := $(patsubst %.c,$(INFILE_DIR)/%.in,$(TEST_SRCS))

$(INFILE_DIR)/%.in:$(INFILE_DIR)/%.c
	$(CC) -g3 $< -o $@ -L../ -lstringf -I $(INCS_DIR)

all: $(TESTS)

clean:
	rm -f $(TESTS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(INFILE_DIR)/*.dSYM

re: fclean all

.PHONY	: all clean fclean re
