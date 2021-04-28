/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:39:50 by ysakuma           #+#    #+#             */
/*   Updated: 2021/04/28 14:59:23 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_erroract(char **save, char **line, char *buf)
{
	free(*save);
	*save = NULL;
	free(buf);
	buf = NULL;
	if (line)
	{
		free(*line);
		*line = NULL;
	}
	return (-1);
}

static int	gnl_overwite(char **save, char **line, char *buf)
{
	size_t	len;
	size_t	len_after;
	char	*tmp;

	len = 0;
	while (*(*save + len) != '\n')
		len++;
	*line = malloc(sizeof(char) * (len + 1));
	if (*line == NULL)
		return (gnl_erroract(save, NULL, buf));
	ft_strlcpy(*line, *save, len + 1);
	len_after = ft_strlen(*save + len + 1);
	tmp = malloc(sizeof(char) * (len_after + 1));
	if (tmp == NULL)
		return (gnl_erroract(save, line, buf));
	ft_strlcpy(tmp, *save + len + 1, len_after + 1);
	free(*save);
	*save = tmp;
	free(buf);
	buf = NULL;
	return (1);
}

static int	gnl_attach(char *buf, char **save, ssize_t len)
{
	size_t	ori_len;
	char	*tmp;

	ori_len = ft_strlen(*save);
	tmp = malloc(sizeof(char) * (ori_len + len + 1));
	if (tmp == NULL)
		return (1);
	ft_strlcpy(tmp, *save, ori_len + 1);
	ft_strlcat(tmp, buf, ori_len + len + 1);
	free(*save);
	*save = tmp;
	return (0);
}

static int	gnl_lastact(char **save, char **line, char *buf)
{
	size_t	len;

	len = ft_strlen(*save);
	*line = malloc(sizeof(char) * (len + 1));
	if (*line == NULL)
		return (gnl_erroract(save, NULL, buf));
	ft_strlcpy(*line, *save, len + 1);
	free(buf);
	buf = NULL;
	free(*save);
	*save = NULL;
	return (0);
}

int	first_set_save(char **save, int fd)
{
	save[fd] = ft_calloc(1, sizeof(char));
	if (save[fd] == NULL)
		return (FALSE);
	return (TRUE);
}

int	read_buf(ssize_t *len, int fd, char *buf, int buf_size)
{
	*len = read(fd, buf, buf_size);
	if (*len >= 0)
		return (TRUE);
	return (FALSE);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		len;
	static char	*save[MAX_FD];
	char		*buf;

	if (!line || fd < 0 || fd > MAX_FD)
		return (-1);
	if (!save[fd])
		if (first_set_save(save, fd) == FALSE)
			return (-1);
	buf = malloc(BUFFER_SIZE);
	if (buf == NULL)
		return (gnl_erroract(&save[fd], NULL, NULL));
	if (ft_memchr(save[fd], '\n', ft_strlen(save[fd])))
		return (gnl_overwite(&save[fd], line, buf));
	while (read_buf(&len, fd, buf, BUFFER_SIZE) == TRUE)
	{
		if (gnl_attach(buf, &save[fd], len))
			return (gnl_erroract(&save[fd], NULL, buf));
		if (ft_memchr(buf, '\n', len))
			return (gnl_overwite(&save[fd], line, buf));
		if (len < BUFFER_SIZE)
			return (gnl_lastact(&save[fd], line, buf));
	}
	return (gnl_erroract(&save[fd], NULL, buf));
}
