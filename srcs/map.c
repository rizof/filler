/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:41:48 by kecosmon          #+#    #+#             */
/*   Updated: 2017/12/13 16:41:52 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

static int		check_valid_push(t_mem *lst, char **map, int size)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			if (lst->map_tetri[y][x] != '.' && (lst->width + x >= size \
						|| lst->heigth + y >= size))
				return (0);
			if (lst->map_tetri[y][x] != '.' && \
					ft_isalpha(map[lst->heigth + y][lst->width + x]))
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

static void		push_tetri(t_mem *lst, char **map)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			if (lst->map_tetri[y][x] != '.')
			{
				map[lst->heigth + y][lst->width + x] = lst->lettre;
			}
			x++;
		}
		x = 0;
		y++;
	}
	// set_pos(&lst);
}

static void		delete_lettre(t_mem *lst, char **map)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == lst->lettre)
				map[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
}

int				resolve_map(t_mem *lst, char **map, int size)
{
	if (lst == NULL)
		return (1);
	while (lst->heigth < size)
	{
		if (check_valid_push(lst, map, size))
		{
			push_tetri(lst, map);
			if (resolve_map(lst->next , map, size))
				return (1);
			delete_lettre(lst , map);
		}
		if (lst->width <= size)
			lst->width++;
		else
		{
			lst->width = 0;
			lst->heigth++;
		}
	}
	lst->width = 0;
	lst->heigth = 0;
	return (0);
}

void			solved_map(t_mem **lst, int size_list)
{
	t_mem	*new;
	int		size;
	char	**map;

	new = *lst;
	map = NULL;
	size = map_sqrt(size_list * 4);
	map = intens_map(map, &size, 0, 0);
	while (resolve_map(new, map = intens_map(map, &size, 0, 0), size) != 1)
		size++;
	ft_show(map);
}
