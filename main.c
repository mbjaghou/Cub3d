/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:31:18 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/09/28 13:18:33 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"
#include "get_next_line/get_next_line.h"

int	check_ext(char *map)
{
	int		i;
	char	*str;

	i = ft_strlen(map);
	str = map + i - 4;
	if (!ft_strncmp(str, ".cub", 4))
		return (1);
	else
		return (0);
}

int main(int ac, char **av)
{
    t_data data1;
    char *line;
    int i = 0;
    data1.len = 0;
    if (ac != 2)
        printf("Error argument\n");
    int fd = open(av[1], O_RDONLY);
    if (fd == -1)
        exit(0);
    line = get_next_line(fd);
    while(line)
    {
        data1.len++;
        // free(line);
        line = get_next_line(fd);
    }
    data1.map = (char **)malloc(sizeof(char *) * (data1.len + 1));
    if (close(fd) == -1)
        exit (0);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        exit(0);
    while (i < data1.len)
    {
        data1.map[i++] = get_next_line(fd);
    }
    if (close(fd) == -1)
        exit (0);
    if(check_ext(av[1]) == 0)
    {
        printf("Error\n");
    } 
    i = 0;
    while (i < data1.len)
    {
        printf("%s", data1.map[i++]);
    }
   
}