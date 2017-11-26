#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char	*buf;
	int		ret;

	if (fd == -1)
		return (0);
	(*line) = (char*)malloc(sizeof(char));
	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		(*line) = ft_strjoin((*line), buf);
	}
	return (1);
}