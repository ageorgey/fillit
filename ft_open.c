/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muamdah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 04:57:26 by muamdah           #+#    #+#             */
/*   Updated: 2018/04/02 15:47:36 by muamdah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_open2(char **tab, char **argv)
{
	char	buf[BUF_SIZE + 1];
	char	**s;
	int		fd;
	int		ret;
	int		i;

	s = tab;
	i = 0;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		exit(0);
	if (!(s))
		return (NULL);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		s[i++] = ft_strdup(buf);
	}
	s[i] = NULL;
	if (close(fd) == -1)
		exit(0);
	return (s);
}

char			**ft_open(char **argv)
{
	char	buf[BUF_SIZE + 1];
	int		fd;
	int		ret;
	int		i;
	char	**tab;

	i = 0;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		ft_putendl("error");
		exit(0);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
		i++;
	if (!(tab = (char**)malloc(sizeof(char*) * i + 1)))
		return (NULL);
	tab[i] = NULL;
	if (close(fd) == -1)
	{
		ft_putendl("error");
		exit(0);
	}
	tab = ft_open2(tab, argv);
	return (tab);
}
