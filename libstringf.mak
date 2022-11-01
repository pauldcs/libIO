NAME		:= libstringf.a 
CC			:= gcc
CFLAGS 		:= -Wall -Wextra -Werror -g3
SRCS_DIR	:= srcs
OBJS_DIR	:= .objs
INCS_DIR	:= incs

IOBUF_SIZE  := 1024

SRCS :=                   \
	stringf.c             \
	fstringf.c            \
	sstringf.c            \
	snstringf.c           \
	cnstringf.c           \
	\
	format/__int.c        \
	format/__str.c        \
	format/__hex.c        \
	format/__ptr.c        \
	\
	utils/iob_write.c      \
	utils/field_pad.c      \
	utils/write_all.c      \
	utils/iob_format_str.c \
	utils/str_to_uint.c    \

