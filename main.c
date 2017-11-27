#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	*line;

	fd = 0;
	fd2 = 0;
	if (argc == 1)
		fd = 0;
	else if (argc == 2){
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			ft_putendl(line);
			ft_putendl("-----");
			free(line);
		}
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		get_next_line(fd, &line);
		get_next_line(fd2, &line);
		get_next_line(fd, &line);
	}
	if (argc == 2)
		close(fd);
	else
		{
			close(fd);
			close(fd2);
		}
}
