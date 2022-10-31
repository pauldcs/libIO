include libstringf.mak

SRCS_OBJS := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@mkdir -vp $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I $(INCS_DIR)

all: $(NAME)

-include $(SRCS_OBJS:.o=.d)

$(NAME): $(SRCS_OBJS)
	ar rc $(NAME) $(SRCS_OBJS)

test: all
	@bash tester/tester.sh

clean:
	rm -f $(SRCS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJS_DIR)
	rm -rf tester/infiles

re: fclean all

.PHONY	: all clean fclean re
