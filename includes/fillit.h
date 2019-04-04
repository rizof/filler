/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:28:46 by kecosmon          #+#    #+#             */
/*   Updated: 2017/11/21 19:28:48 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# define EMPTY .
# define LETTRE 'A'
# define BLOCK '#'
# define BUFF_SIZE 546

typedef struct		s_mem
{
	char			lettre;
	char			*malloc_tetri;
	char			**map_tetri;
	char			heigth;
	char			width;
	struct s_mem	*next;
}					t_mem;

char				**delete_map(char **map);
void				set_pos(t_mem **lst);
void				ft_show(char **tetri);
char				*del(char *tetri);
int					map_sqrt(int n);
char				**intens_map(char **map, int *size, int y, int x);
t_mem				*ft_lstmew(void const *tetriminos, t_mem *lst);
int					engine_tetri(t_mem *lst, int i);
void				ft_lstrev(t_mem **alst);
int					check_size_tetris(char **tetris);
int					verif_caractere(char *tetris, int i_lst);
int					check_link(char *str);
void				posx_tetris(char **tetris);
void				posy_tetris(char **tetris);
void				solved_map(t_mem **lst, int size_list);
void				reader_map(int size);

#endif
