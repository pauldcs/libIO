NAME		:= libstringf.a 
CC			:= gcc
CFLAGS 		:= -Wall -Wextra -Werror -g3 
SRCS_DIR	:= srcs
OBJS_DIR	:= .objs
INCS_DIR	:= incs

SRCS :=                \
	stringf.c          \
	fstringf.c         \
	sstringf.c         \
	snstringf.c        \
	cnstringf.c        \
	\
	format/__int.c     \
	format/__str.c     \
	format/__hex.c     \
	format/__ptr.c     \
	\
	utils/writer.c     \
	utils/write_all.c  \
	utils/do_formatting.c \

