NAME		:= libio.a 
CC			:= gcc
CFLAGS 		:= -Wall -Wextra -Werror -g3 
SRCS_DIR	:= srcs
OBJS_DIR	:= .objs
INCS_DIR	:= incs

SRCS :=                \
	fstringf.c         \
	stringf.c          \
	sstringf.c         \
	snstringf.c        \
	cnstringf.c        \
	do_formatting.c    \
	\
	format/__int.c     \
	format/__str.c     \
	format/__hex.c     \
	format/__ptr.c     \
	\
	utils/writer.c     \
	utils/init_iob.c   \
	utils/write_all.c  \

