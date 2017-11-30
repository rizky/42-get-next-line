/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:32:59 by rnugroho          #+#    #+#             */
/*   Updated: 2017/11/29 13:32:59 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	*line;

	line = NULL;
	fd = 0;
	fd2 = 0;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			ft_putendl(line);
			ft_putendl("-----");
			free(line);
		}
		close(fd);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			ft_putendl(line);
			ft_putendl("-----");
			free(line);
			if (get_next_line(fd2, &line) == 1)
			{
				ft_putendl(line);
				ft_putendl("*****");
				free(line);
			}
		}
		close(fd);
		close(fd2);
	}
}
