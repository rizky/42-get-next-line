#include "get_next_line.h"

t_list	*choose_file(t_list **files, int fd)
{
	t_list	*file;
	t_file	f;

	file = *files;
	while (file)
	{
		if  (((t_file*)((file->content)))->fd == fd)
			return (file);
		file = file->next;
	}
	f.fd = fd;
	ft_lstadd((files), ft_lstnew((void*)&f, sizeof(t_file)));
	return (*files);
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_list	*files;
	t_list			*file;

	file = choose_file(files, fd);
	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (0);
	ALLOCATED((*line = ft_strnew(1)));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		ALLOCATED(((*line) = ft_strjoin((*line), buf)));
	}
	if (ret < BUFF_SIZE && !ft_strlen((*line)))
		return (0);
	return (1);
}