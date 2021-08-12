# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 16:04:19 by user42            #+#    #+#              #
#    Updated: 2021/08/11 21:06:37 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#AUTHOR mmateo-t
#USAGE

#make          #compile all binary
#make clean		#remove all binaries
#make fclean		#remove all binaries and executable 

SRCS_DIR:= srcs/

#SRCS_DIR_BONUS:= files/srcs/bonus/

SRCS := $(wildcard $(SRCS_DIR)*.c) \

#SRCS_BONUS :=	$(wildcard $(SRCS_DIR_BONUS)*.c) \

OBJS := $(SRCS:%.c=%.o)
#OBJS_BONUS := $(SRCS_BONUS:%.c=%.o)
NAME:= pipex
CC:= gcc 
CFLAGS:= -Wall -Werror -Wextra
RM :=	rm -rvf
DEBUG_FLAG:= -g

all:	$(NAME) msg

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

bonus: $(OBJS_BONUS) 
	$(CC) $(OBJS_BONUS) -o $(NAME) $(CFLAGS) 

$(%.o): $(%.c)
		$(CC) -c $^ -o $@ 
		@echo "Creating objects"

clean:
		@echo "Removing objects"
		$(RM) $(OBJS) #$(OBJS_BONUS)
fclean:
		make clean
		$(RM) $(NAME) 
		@echo "Removed executable"
msg:
		@echo  "\e[42m                   \e[0m"
		@echo  "\e[92mAll files compiled"
		@echo  "pipex command compilled"
		@echo  "Execute--> ./pipex file1 cmd1 cmd2 file2"
		@echo  "Use in prompt-->$ < file1 cmd1 | cmd2 > file2"
		@echo  "\e[93mDONE! ;)"
		@echo  "\e[42m                   \e[0m"

re:
	make fclean all
	@echo "All files has been deleted and recompiled"


.PHONY: clean fclean all re objects debug minilibx libft objects bonus
