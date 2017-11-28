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

t_list	*manage_file(t_list **files, int fd)
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
	f.offset = 0;
	ft_lstadd((files), ft_lstnew((void*)&f, sizeof(t_file)));
	return (*files);
}

void	delete_file(void *file, size_t size)
{
	size = 0;
	ft_strdel(&(((t_file*)file)->content));
}

int		compare_file(void *file1, void *file2)
{
	if ((((t_file*)file1)->fd)== (((t_file*)file2)->fd))
		return 1;
	else
		return 0;
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_list	*files;
	t_list			*file;
	size_t			len;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	file = manage_file(&files, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		ALLOCATED((FILE->content = ft_strjoin(CONTENT(file), buf)));
		if (ft_strchr(CONTENT(file), '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(CONTENT(file)))
	{
		ft_lstremoveif(&files, FILE->content, &compare_file, &delete_file);
		return (0);
	}
	if (ft_strchr(CONTENT(file), '\n'))
		len = ft_strchr(CONTENT(file), '\n') - CONTENT(file);
	else
		len = ft_strlen(CONTENT(file));
	ALLOCATED((*line = ft_strnew(len)));
	*line = ft_strncpy(*line, CONTENT(file), len);
	(len < ft_strlen(CONTENT(file)))
		? OFFSET(file) += (len + 1)
		: ft_strclr(FILE->content);
	return (1);
}
