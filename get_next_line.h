#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"

# define BUFF_SIZE 8

# define ALLOCATED(x) if (!x) return (-1);

int		get_next_line(int fd, char **line);

#endif
