/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:00:11 by rnugroho          #+#    #+#             */
/*   Updated: 2017/11/27 18:00:12 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"

# define BUFF_SIZE 1
# define ALLOCATED(x) if (!x) return (-1);
# define CONTENT(x) ((t_file*)((x->content)))->content
# define START(x) ((t_file*)((x->content)))->content_start

typedef struct	s_file
{
	int			fd;
	char		*content;
	char		*content_start;
}				t_file;

int				get_next_line(int fd, char **line);

#endif
