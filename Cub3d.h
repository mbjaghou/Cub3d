/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:32:34 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/10/11 17:40:36 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "get_next_line/get_next_line.h"
#include <printf.h>
typedef struct s_data
{
    char **map;
    int len;
    char *no;
    char *so;
    char *we;
    char *ea;
} t_data;

int	    ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split2(char *str, char *charset);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
#endif