# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 16:04:19 by user42            #+#    #+#              #
#    Updated: 2021/11/12 13:50:16 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#AUTHOR mmateo-t
#USAGE

#make          #compile all binary
#make clean		#remove all binaries
#make fclean		#remove all binaries and executable

SRCS_DIR:=srcs/
SRCS := $(wildcard $(SRCS_DIR)*.c)
OBJS := $(SRCS:%.c=%.o)
NAME:= pipex
CC:= cc
CFLAGS:= -Wall -Werror -Wextra
RM :=	rm -rvf
LIBFT_PATH:= lib/libft
LIBFT_LIB:= -L$(LIBFT_PATH) $(LIBFT_PATH)/libft.a
DEBUG_FLAG:= -g

all:	libft $(NAME) msg

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LIB)

$(%.o): $(%.c)
		$(CC) -c $^ -o $@
		@echo "Creating objects"

libft:
		make -C $(LIBFT_PATH)

clean:
		@echo "Removing objects"
		$(RM) $(OBJS)
fclean:
		make clean
		cd ./lib/libft && $(MAKE) fclean
		$(RM) $(NAME) ./*.txt
msg:
		@echo  "\e[42m                                                                        \e[0m"
		@echo  "\e[92mAll files compiled"
		@echo  "pipex command compiled"
		@echo  "\e[93mTo Execute --> 	 	./pipex \e[94m file1 \e[95m cmd1 cmd2 \e[94m file2 \e[0m"
		@echo  "\e[93mUsed in console -->$ \e[94m	< file1 \e[95m cmd1 | cmd2 \e[94m > file2"
		@echo  "\e[42m                                                                        \e[0m"

re:
	make fclean all
	@echo "All files has been deleted and recompiled"


.PHONY: clean fclean all re objects debug bonus
