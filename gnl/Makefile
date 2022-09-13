# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 15:08:09 by cudoh             #+#    #+#              #
#    Updated: 2022/08/22 19:51:11by cudoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SRCS:= $(shell ls *.c | grep -v lst | xargs)
SRCS:= get_next_line.c get_next_line_utils.c
OBJS:= $(SRCS:.c=.o)
SRCS_BONUS:= get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS_BONUS:= $(SRCS_BONUS:.c=.o)

NAME = gnl.a 

AR = ar
CFLAGS = -Wall -Wextra -Werror
LIBFLAGS_STATIC = rcs
INCLUDES = -I./

NAME : all
all : $(NAME)
$(NAME) : $(OBJS)
	@echo
	@echo "\033[1;33mCompiling LIB: ${NAME} \033[0m"
	$(AR) $(LIBFLAGS_STATIC) $@ $^
	@echo; echo "\033[1;32mCompilation Successful. \033[0m"
	@echo; echo

	
bonus: $(OBJS_BONUS)
	@echo # line spacing
	@echo "\033[1;33mCompiling LIB BONUS: ${NAME} \033[0m"
	$(AR) $(LIBFLAGS_STATIC) $@ $^
	@echo "\033[1;32mCompilation Successful. \033[0m"
	@echo


# obj files output
%.o : %.c
	$(CC) -c $^ $(CFLAGS) $(INCLUDES) -o $@


# remove all object files
fclean:
	rm -rf *.o

# remove final target files
clean: fclean
	rm -rf $(NAME)
	rm -rf *.a

# recompile everything
re: clean all

.PHONY : all fclean clean re 
