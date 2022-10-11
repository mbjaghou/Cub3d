/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:31:18 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/10/11 18:32:00 by mbjaghou         ###   ########.fr       */
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
    if (!str || !*str)
        return (1);
    int size = ft_strlen(str[0]);
    if (str[0] && ft_strncmp(str[0], "NO", size) && ft_strncmp(str[0], "SO", size) && ft_strncmp(str[0], "WE", size) && \
     ft_strncmp(str[0], "EA", size) && ft_strncmp(str[0], "F", size) && ft_strncmp(str[0], "C", size) && ft_strncmp(str[0], "1", 1) \
      && ft_strncmp(str[0], "0", 1) && ft_strncmp(str[0], "N", 1) && ft_strncmp(str[0], "S", 1) && \
      ft_strncmp(str[0], "W", 1) && ft_strncmp(str[0], "E", 1))
    {
        printf("error for textures\n");
        return (0);
    }
    else
        return (1);
    return (1);
}

int check_xpm(char *tmp)
{
    char **str;

    str = ft_split2(tmp, " \t\n");
    if (!str || !*str)
        return (1);
    int size = ft_strlen(str[0]);
    if (!ft_strncmp(str[0], "SO", size) || !ft_strncmp(str[0], "NO", size) || \
    !ft_strncmp(str[0], "WE", size) || !ft_strncmp(str[0], "EA", size))
    {
        if (ft_strncmp(".xpm", str[1] + ft_strlen(str[1]) - 4, 4))
        {
            printf("error\n");
            return (0);
        }
        if (str[2])
        {
            printf("error 2\n");
            return 0;
        }
           
    }
    return (1);
        
}

void check_color(char *tmp)
{
    char **str;
    int color;
    int i;
    int j;

    i = 0;
    j = 0;
    str = ft_split2(tmp, ", \t");
    if (!ft_strncmp(str[0], "F", 1) || !ft_strncmp(str[0], "C", 1))
    {
        while(str[i])
        {
            printf("%s ", str[i]);
            i++;
        }
        printf("\n");
    }
    // while(str[i])
    // {
    //     printf("%s\n", str[i]);
    //     i++;
    // }

    
}

int checker(int ac, char **av)
{
    if (ac != 2) {
        write(2, "Error usage: cub3d <filename>\n", 31);
        return (1);
    }
    if(!check_ext(av[1]))
    {
        write(2, "Error file extension : <filename>.cub\n", 38);
        return (1);
    }
    return (0);
}

int get_len(int fd)
{
    char *line;
    int len;

    len = 0;
    line = get_next_line(fd);
    while(line)
    {
        len++;
        line = get_next_line(fd);
    }
    return(len);
}

int fill_map(char *str, t_data *data)
{
    int i;
    int fd;

    fd = open(str, O_RDONLY);
    if (fd < 0)
    {
        perror("Error ");
        return(1);
    }
    data->map = (char **)malloc(sizeof(char *) * (data->len + 1));
    if (!data->map)
        return (0);
    i = 0;
    while (i < data->len)
    {
        data->map[i++] = get_next_line(fd);
    }
    data->map[i] = NULL;
    if (close(fd) == -1)
        exit (0);
    return(0);
}

int parssing(int ac, char **av, t_data *data)
{
    int fd;

    if (checker(ac,av))
        return(1);
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error ");
        return(1);
    }
    data->len = get_len(fd);
    if (data->len == 0)
    {
        write(2, "Error: file is empty\n", 21);
        return(1);
    }
    if (close(fd) == -1)
        exit (0);
    fill_map(av[1], data);
    return (0);   
}

int fill_path(char *str, t_data *data)
{
    char **str_spl;
    str_spl = ft_split2(str, " \t\n");

    if (str_spl[0] && (!ft_strcmp(str_spl[0], "NO") || !ft_strcmp(str_spl[0], "SO") || !ft_strcmp(str_spl[0], "WE") || !ft_strcmp(str_spl[0], "EA")))
    {
        if(str_spl[1] && !ft_strncmp(".xpm", str_spl[1] + ft_strlen(str_spl[1]) - 4, 4) && !str_spl[2])
        {
            if (!data->no && !ft_strcmp(str_spl[0], "NO"))
                    data->no = ft_strdup(str_spl[1]);
            else if (!data->so && !ft_strcmp(str_spl[0], "SO"))
                    data->so = ft_strdup(str_spl[1]);
            else if (!data->we && !ft_strcmp(str_spl[0], "WE"))
                    data->we = ft_strdup(str_spl[1]);
            else if (!data->ea && !ft_strcmp(str_spl[0], "EA"))
                    data->ea = ft_strdup(str_spl[1]);
            else 
            {
                printf("Error: some textures are duplicated\n");
                return(1);        
            }
        }
        else
        {
            printf("Error: xpm path\n");
            return (1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    t_data data1;
    char *line;
    int i;
    char **str;

    
    if (parssing(ac, av, &data1))
        return(1);
    
    // while (data1.map[i])
    // {
    //     int size = ft_strlen(data1.map[i]);
    //     if (!ft_strncmp(str[0], "NO", size) && !ft_strncmp(str[0], "SO", size) && !ft_strncmp(str[0], "WE", size) && \
    //         !ft_strncmp(str[0], "EA", size))
    //         return (check_textures(data1.map[i]), 1);
    //     i++;
    // }
    i = -1;
    
    while (++i < data1.len)
    {
        if(fill_path(data1.map[i], &data1))
            return (1);
    }
    if (!data1.no || !data1.ea || !data1.we || !data1.so)
    {
        printf("some path deos not exist\n");
        return (1);
    }
    printf("%s\n", data1.ea);
    printf("%s\n", data1.no);
    printf("%s\n", data1.so);
    printf("%s\n", data1.we);
    return (0);
}
