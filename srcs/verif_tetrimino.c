/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:42:05 by kecosmon          #+#    #+#             */
/*   Updated: 2017/12/13 16:42:06 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int		check_link(char *tetri)
{
	int check;
	int i;

	check = 0;
	i = 0;
	while (i < 20)
	{
		if (tetri[i] == '#')
		{
			if ((i + 1) < 20 && tetri[i + 1] == '#')
				check++;
			if ((i - 1) >= 0 && tetri[i - 1] == '#')
				check++;
			if ((i + 5) < 20 && tetri[i + 5] == '#')
				check++;
			if ((i - 5) >= 0 && tetri[i - 5] == '#')
				check++;
		}
		i++;
	}
	return (!(check == 6 || check == 8));
}

int		check_size_tetris(char **tetris)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (tetris[i])
	{
		while (tetris[i][x])
		{
			x++;
		}
		if (x != 4)
			return (1);
		x = 0;
		i++;
	}
	if (i != 4)
		return (1);
	return (0);
}

int		verif_caractere(char *tetris, int i_lst)
{
	int i;
	int count_h;

	count_h = 0;
	i = 0;
	if (tetris[i] =='\n')
		return (1);
	while (tetris[i])
	{
		if (tetris[i] != '.' && tetris[i] != '#' && tetris[i] != '\n')
			return (1);
		if (tetris[i] == '#')
			count_h++;
		i++;
	}

	if (i_lst != 1)
		if ((tetris[i - 3] != '.' && tetris[i - 3] != '#' )|| tetris[i - 2] != '\n')
			return (1);
	if (i_lst == 1)
		if ((tetris[i - 2] != '.' && tetris[i - 2] != '#') || tetris[i - 1] != '\n')
			return (1);
	if (count_h != 4)
		return (1);
	return (0);
}
