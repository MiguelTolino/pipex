# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 16:04:19 by user42            #+#    #+#              #
#    Updated: 2021/11/11 00:20:25 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#AUTHOR mmateo-t
#USAGE

#make          #compile all binary
#make clean		#remove all binaries
#make fclean		#remove all binaries and executable

SRCS_DIR:=srcs/
#BUILD_DIR:=build/

#SRCS_DIR_BONUS:= files/srcs/bonus/

SRCS := $(wildcard $(SRCS_DIR)*.c)

#SRCS_BONUS :=	$(wildcard $(SRCS_DIR_BONUS)*.c) \

OBJS := $(SRCS:%.c=%.o)
#BUILD_OBJS:= $(BUILD_DIR)*.o
#OBJS_BONUS := $(SRCS_BONUS:%.c=%.o)
NAME:= pipex
CC:= cc
CFLAGS:= -Wall -Werror -Wextra
RM :=	rm -rvf
DEBUG_FLAG:= -g

all:	$(NAME) msg

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

#bonus: $(OBJS_BONUS)
#	$(CC) $(OBJS_BONUS) -o $(NAME) $(CFLAGS)

$(%.o): $(%.c)
		$(CC) -c $^ -o $@
		@echo "Creating objects"

debug: $(OBJS)
	$(CC) $(DEBUG_FLAG) $(CFLAGS) $(OBJS) -o $(NAME)

#build:
#		mkdir -pv build
#		mv $(SRCS_DIR)*.o $(BUILD_DIR)

clean:
		@echo "Removing objects"
		$(RM) $(OBJS)
fclean:
		make clean
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
