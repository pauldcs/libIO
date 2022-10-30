CC	:= gcc
NAME        :=
INFILE_DIR	:= infiles
INCS_DIR	:= ../incs

SRCS := \
	stringf_001.c \
	stringf_002.c \

TESTS := $(patsubst %.c,$(INFILE_DIR)/%.in,$(SRCS))

$(INFILE_DIR)/%.in:$(INFILE_DIR)/%.c
	$(CC) $(CFLAGS) -g3 $< -o $@ -L../ -lstringf -I $(INCS_DIR)

all: $(TESTS)


clean:
	rm -f $(TESTS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(INFILE_DIR)/*.dSYM

re: fclean all

.PHONY	: all clean fclean re
