/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:31:18 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/09/29 16:27:16 by mbjaghou         ###   ########.fr       */
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

int check_textures(char *av)
{
    char **str;
    int i = 0;
    int j;
    
    str = ft_split2(av, " \t\n");
    int size = ft_strlen(str[0]);
    if (str[0] && ft_strncmp(str[0], "NO", size) && ft_strncmp(str[0], "SO", size) && ft_strncmp(str[0], "WE", size) && \
     ft_strncmp(str[0], "EA", size) && ft_strncmp(str[0], "F", size) && ft_strncmp(str[0], "C", size) && ft_strncmp(str[0], "1", 1) \
      && ft_strncmp(str[0], "0", 1) && ft_strncmp(str[0], "N", 1) && ft_strncmp(str[0], "S", 1) && \
      ft_strncmp(str[0], "W", 1) && ft_strncmp(str[0], "E", 1))
    {
        printf("error for textures\n");
        return (0);
    }
    return (1);
}

int main(int ac, char **av)
{
    t_data data1;
    char *line;
    int i = 0;
    
    if (ac != 2) {
        printf("Error argument\n");
        return 0;
    }
    if(!check_ext(av[1]))
    {
        printf("Error\n");
        return (0);
    } 
    data1.len = 0;
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
    data1.map[i] = NULL;
    if (close(fd) == -1)
        exit (0);
    i = -1;
    while (++i < data1.len)
    {
        if (!check_textures(data1.map[i]))
        {
            break;  
        }
    }
   
    // i = 0;
    // while (i < data1.len)
    // {
    //     printf("%s", data1.map[i++]);
    // }
   
}