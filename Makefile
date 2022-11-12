# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 14:04:11 by yachehbo          #+#    #+#              #
#    Updated: 2022/11/10 13:04:20 by mbjaghou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

GNL = GNL/get_next_line.c GNL/get_next_line_utils.c 

PARSS = parssing/parssing.c parssing/checker/check_arg.c \
parssing/checker/check_scene.c parssing/fill/color.c parssing/fill/fill.c \
parssing/fill/fill_data.c parssing/fill/fill_scene.c

UTILS = src/ft_isdigit.c src/ft_splite.c  src/ft_strdup.c  src/ft_strncmp.c \
src/ft_atoi.c  src/ft_strcmp.c  src/ft_strlcpy.c src/ft_strtrim.c

SRCS =  cub3d.c init.c drawing.c update.c move.c hook.c rcasting.c $(GNL) $(UTILS) $(PARSS)

OBJS = $(SRCS:.c=.o)

HDR = cub3d.h GNL/get_next_line.h

all: $(NAME)

$(NAME): $(OBJS)
	cc  $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(HDR)
	cc $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re