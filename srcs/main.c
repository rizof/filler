/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:41:59 by kecosmon          #+#    #+#             */
/*   Updated: 2017/12/13 16:42:00 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int		read_map(int fd, int i)
{
	t_mem	*lst;
	char	buff[21];
	int		ret;

	lst = NULL;
	while ((ret = read(fd, &buff, 21)))
	{
		if (i > 25)
		{
			ft_putendl("error");
			return (1);
		}
		buff[ret] = '\0';
		lst = ft_lstmew(buff, lst);
		i++;
	}
	ft_lstrev(&lst);
	if (lst)
	{
		if (engine_tetri(lst, i))
		{
			ft_putendl("error");
			return (1);
		}
		solved_map(&lst, i);
	}
	else
		ft_putendl("error");
	return (0);
}

int		main(int argc, char **argv)
{
	int fd;
	int i;

	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putendl("error");
			return (0);
		}
		read_map(fd, i);
	}
	return (0);
}

