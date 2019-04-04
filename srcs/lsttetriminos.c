/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsttetriminos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:42:09 by kecosmon          #+#    #+#             */
/*   Updated: 2017/12/13 16:42:10 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

void			ft_lstrev(t_mem **alst)
{
	t_mem	*prev;
	t_mem	*cur;
	t_mem	*next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

static void		initialise(char lettre, char **tetris)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (tetris[i])
	{
		x = 0;
		if (tetris[i][x] == '#')
		{
			tetris[i][x] = lettre;
		}
		while (tetris[i][x])
		{
			if (tetris[i][x] == '#')
			{
				tetris[i][x] = lettre;
			}
			x++;
		}
		i++;
	}
}

int				engine_tetri(t_mem *lst, int i_lst)
{
	int i;

	i = 0;
	if (lst)
	{
		while (lst)
		{
			if (verif_caractere(lst->malloc_tetri, i_lst)\
				|| check_link(lst->malloc_tetri))
				return (1);
			lst->map_tetri = ft_split_whitespaces(lst->malloc_tetri);
			lst->malloc_tetri = del(lst->malloc_tetri);
			if (check_size_tetris(lst->map_tetri))
				return (1);
			posy_tetris(lst->map_tetri);
			posx_tetris(lst->map_tetri);
			initialise(lst->lettre = LETTRE + i, lst->map_tetri);
			lst = lst->next;
			i_lst--;
			i++;
		}
	}
	return (0);
}

t_mem			*ft_lstmew(void const *tetriminos, t_mem *lst)
{
	t_mem *new;

	new = malloc(sizeof(t_mem));
	if (tetriminos)
	{
		new->malloc_tetri = malloc(sizeof(size_t) * (21));
		new->malloc_tetri = \
		ft_memcpy(new->malloc_tetri, (void *)tetriminos, 21);
	}
	else
	{
		new->malloc_tetri = NULL;
	}
	new->lettre = 0;
	new->map_tetri = NULL;
	new->heigth = 0;
	new->width = 0;
	new->next = lst;
	return (new);
}
