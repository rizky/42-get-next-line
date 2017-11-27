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

char	*ft_strjoinch(char const *s1, char c)
{
	char	*new_str;
	size_t	i;
	size_t	s1_len;

	if (!s1 || !c)
		return (NULL);
	s1_len = ft_strlen(s1);
	new_str = ft_strnew(s1_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	*(new_str + i) = c;
	return (new_str);
}

int			ft_copyuntil(char **dst, char *src, char c)
{
	int		i;
	int		count;
	int		pos;

	i = -1;
	count = 0;
	while (src[++i])
		if (src[i] == c)
			break ;
	pos = i;
	if (!(*dst = ft_strnew(i)))
		return (0);
	while (src[count] && count < i)
	{
		if (!(*dst = ft_strjoinch(*dst, src[count])))
			return (0);
		count++;
	}
	return (pos);
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
	if (ft_strchr(CONTENT(file), '\n'))
		len = ft_strchr(CONTENT(file), '\n') - CONTENT(file);
	else
		len = ft_strlen(CONTENT(file));
	ALLOCATED((*line = ft_strnew(len)));
	*line = ft_strncpy(*line, CONTENT(file), len);
	(len < ft_strlen(CONTENT(file)))
		? CONTENT(file) += (len + 1)
		: ft_strclr(CONTENT(file));
	return (1);
}
