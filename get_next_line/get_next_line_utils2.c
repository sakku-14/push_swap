#include "get_next_line.h"

int	first_set_save(char **save, int fd)
{
	save[fd] = ft_calloc(1, sizeof(char));
	if (save[fd] == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int	read_buf(ssize_t *len, int fd, char *buf, int buf_size)
{
	*len = read(fd, buf, buf_size);
	if (*len >= 0)
		return (SUCCESS);
	return (FAILURE);
}
