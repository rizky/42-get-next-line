#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

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