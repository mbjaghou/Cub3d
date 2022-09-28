/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:32:34 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/09/28 13:17:48 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "get_next_line/get_next_line.h"
#include <printf.h>
typedef struct Cub3d
{
    char **map;
    int len;
} t_data;

int	    ft_strncmp(const char *s1, const char *s2, size_t n);
#endif