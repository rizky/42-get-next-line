#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"

# define BUFF_SIZE 300

# define ALLOCATED(x) if (!x) return (-1);

typedef struct	s_file
{
	int			fd;
	char		*content;
}				t_file;

int		get_next_line(int fd, char **line);

#endif
