/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:42:40 by kecosmon          #+#    #+#             */
/*   Updated: 2017/09/14 13:52:07 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define A(c) (c != '\0' && c != '\n' && c != ' ' && c != '\t')
#define B(c) (c == ' ' || c == '\n' || c ==  '\t' || c == '\0')

static int		count_word(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (A(str[i]) && B(str[i + 1]))
			len++;
		i++;
	}
	return (len);
}

static	int		ft_strlene(char *str, int b)
{
	int i;

	i = 0;
	while (A(str[b]))
	{
		b++;
		i++;
	}
	return (i);
}

static int		pushtotab(char *str, char *tab, int b)
{
	int x;

	x = 0;
	while (A(str[b]))
		tab[x++] = str[b++];
	tab[x] = '\0';
	return (x);
}

char			**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		x;
	int		b;

	b = 0;
	i = 0;
	x = 0;
	tab = NULL;
	if (!str)
		return (tab);
	tab = (char**)malloc(sizeof(char*) * (count_word(str) + 1));
	while (str[b] != '\0')
	{
		if (A(str[b]))
		{
			tab[i] = (char*)malloc(sizeof(char) * (ft_strlene(str, b) + 1));
			b += pushtotab(str, tab[i], b);
			i++;
		}
		else
			b++;
	}
	tab[i] = 0;
	return (tab);
}
