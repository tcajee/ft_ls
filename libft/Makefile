# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/18 14:40:51 by tcajee            #+#    #+#              #
#    Updated: 2019/07/15 15:46:17 by tcajee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project file
NAME = libft.a

# Project builds and dirs
SRCDIR		= ./srcs/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC			= $(addprefix $(SRCDIR), $(SRCNAMES))
INCDIR		= ./incs/
OBJDIR		= ./objs/
BUILDOBJS	= $(addprefix $(OBJDIR), $(SRCNAMES:.c=.o))

# Optimization and Compiler flags and commands
CC			= clang
OPFLAGS		= -g3 -funroll-loops
CFLAGS		= -Wall -Werror -Wextra

# Debugging flags
DEBUG = -g

# Main rule
all: $(OBJDIR) $(LIBFT) $(NAME)

# Object dir rule
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Objects rule
$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(DEBUG) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

# Project file rule
$(NAME): $(BUILDOBJS)
	$(CC) $(DEBUG) $(CFLAGS) -o $(NAME) $(BUILDOBJS)

# Cleaning up the object files
clean:
	rm -rf $(OBJDIR)
	make -C $(OBJDIR) clean

# Getting rid of the project file
fclean: clean
	rm -rf $(NAME)
	make -C $(OBJDIR) fclean

# Do both of the above
re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re
