/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:42:15 by kecosmon          #+#    #+#             */
/*   Updated: 2017/12/13 16:42:16 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

void	set_pos(t_mem **lst)
{
	t_mem *new;

	new = *lst;
	while (new)
	{
		new->width = 0;
		new->heigth = 0;
		new = new->next;
	}
}

char	**intens_map(char **map, int *size, int y, int x)
{
	if (map)
		while (map[y])
		{
			free(map[y]);
			y++;
		}
	map = NULL;
	y = 0;
	map = (char**)malloc(sizeof(char*) * (*size) + 1);
	while (y < (*size))
	{
		map[y] = (char*)malloc(sizeof(char) * (*size) + 1);
		while (x < (*size))
		{
			map[y][x] = '.';
			x++;
		}
		map[y][x] = 0;
		x = 0;
		y++;
	}
	map[y] = NULL;
	return (map);
}

int		map_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

char	*del(char *del)
{
	free(del);
	del = NULL;
	return (del);
}

void	ft_show(char **tetri)
{
	while (*tetri)
		ft_putendl(*tetri++);
}
