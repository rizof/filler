/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postetris.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:42:22 by kecosmon          #+#    #+#             */
/*   Updated: 2017/12/13 16:42:23 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

static void		pos_y_tetris(char **tetris, int y)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (tetris[i])
	{
		while (tetris[i][x])
		{
			if (tetris[i][x] == '#')
			{
				tetris[i][x] = '.';
				tetris[i - y][x] = '#';
			}
			x++;
		}
		x = 0;
		i++;
	}
}

void			posy_tetris(char **tetris)
{
	int i;
	int x;
	int check;

	check = 0;
	x = 0;
	i = 0;
	while (tetris[i] && check == 0)
	{
		x = 0;
		while (tetris[i][x] && check == 0)
		{
			if (tetris[i][x] == '#' && check == 0)
				check = 1;
			x++;
		}
		i++;
	}
	i -= 1;
	pos_y_tetris(tetris, i);
}

static	void	pos_x_tetris(char **tetris, int pos_x)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (x < 4)
	{
		i = 0;
		while (tetris[i])
		{
			if (tetris[i][x] == '#')
			{
				tetris[i][x] = '.';
				tetris[i][x - pos_x] = '#';
			}
			i++;
		}
		x++;
	}
}

void			posx_tetris(char **tetris)
{
	int i;
	int x;
	int check;

	check = 0;
	x = 0;
	i = 0;
	while (x < 4 && check == 0)
	{
		i = 0;
		while (tetris[i] && check == 0)
		{
			if (tetris[i][x] == '#')
			{
				check = 1;
			}
			i++;
		}
		x++;
	}
	x -= 1;
	pos_x_tetris(tetris, x);
}
