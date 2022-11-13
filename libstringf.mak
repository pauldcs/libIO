NAME		:= libstringf.a 
CC			:= gcc
CFLAGS 		:= -Wall -Wextra -Werror -g3
SRCS_DIR	:= srcs
OBJS_DIR	:= .objs
INCS_DIR	:= incs

IOBUF_MAX  := 1024

SRCS :=                      \
	cpyf.c                   \
	putstr.c                 \
	fputstr.c                \
	scpyf.c                  \
	slcpyf.c                 \
	ssavef.c                 \
	\
	format/__int.c           \
	format/__str.c           \
	format/__hex.c           \
	format/__ptr.c           \
	\
	utils/iob_write.c        \
	utils/field_pad.c        \
	utils/iob_format_str.c   \
	utils/libstringf_utils.c \

