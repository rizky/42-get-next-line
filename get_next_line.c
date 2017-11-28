/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:00:07 by rnugroho          #+#    #+#             */
/*   Updated: 2017/11/27 18:00:07 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*choose_file(t_list **files, int fd)
{
	t_list	*file;
	t_file	f;

	file = *files;
	while (file)
	{
		if (((t_file*)((file->content)))->fd == fd)
			return (file);
		file = file->next;
	}
	f.fd = fd;
	f.content = ft_strnew(1);
	ft_lstadd((files), ft_lstnew((void*)&f, sizeof(t_file)));
	return (*files);
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	size_t			ret;
	static t_list	*files;
	t_list			*file;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	file = choose_file(&files, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		ALLOCATED((CONTENT(file) = ft_strjoin(CONTENT(file), buf)));
		if (ft_strchr(CONTENT(file), '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(CONTENT(file)))
		return (0);
	ret = ft_strlen(CONTENT(file));
	if (ft_strchr(CONTENT(file), '\n'))
		ret = ft_strchr(CONTENT(file), '\n') - CONTENT(file);
	*line = ft_strncpy(ft_strnew(ret), CONTENT(file), ret);
	(ret < ft_strlen(CONTENT(file)))
		? CONTENT(file) += (ret + 1)
		: ft_strclr(CONTENT(file));
	return (1);
}
