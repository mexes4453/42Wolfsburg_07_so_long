/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:54:00 by cudoh             #+#    #+#             */
/*   Updated: 2022/05/26 10:28:17 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_proc_buf_fd(char *nl_ptr, char *fb, char *lb, size_t *idx_start)
{
	size_t	bytes_rem;

	bytes_rem = 0;
	nl_ptr = ft_memchr((void *)fb, (unsigned char) '\n', BUFFER_SIZE);
	if (nl_ptr)
	{
		*idx_start = nl_ptr - fb + 1;
		bytes_rem = ft_strlen(&fb[*idx_start]);
		ft_memset((void *)nl_ptr, 0, 1);
		if (BUFFER_SIZE > 1 && bytes_rem == 0)
			nl_ptr = NULL;
	}
	nl_ptr = ft_memchr((void *)fb, (unsigned char) '\n', BUFFER_SIZE);
	if (nl_ptr == NULL && bytes_rem)
	{
		lb = ft_realloc((void *)lb, bytes_rem + 1);
		if (lb == NULL)
			return ((void *)1);
		ft_strlcpy((char *)lb, &fb[*idx_start], bytes_rem + 1);
		ft_memset((void *)&fb[*idx_start], 0, bytes_rem);
	}
	return ((char *)lb);
}

static char	*ft_err_on_read(ssize_t num_read, void *lb)
{
	if (num_read == -1)
	{
		free(lb);
		return ((void *)1);
	}
	else if (num_read == 0)
	{
		if (lb)
			return ((char *)lb);
		else
			return ((void *)1);
	}
	return ((char *)lb);
}

static char	*ft_read_fd(char *fb, char *lb, int fd, size_t *idx_start)
{
	ssize_t	num_read;
	char	*nl_ptr;

	nl_ptr = ft_memchr((void *)fb, (unsigned char) '\n', BUFFER_SIZE);
	while (nl_ptr == NULL)
	{
		*idx_start = 0;
		num_read = read(fd, (void *)fb, BUFFER_SIZE);
		lb = ft_err_on_read(num_read, (void *)lb);
		if (lb == (void *) 1)
			return (0);
		if (!num_read && lb)
			return ((char *)lb);
		if (ft_memchr((void *)fb, (unsigned char) '\n', num_read))
			break ;
		if (num_read)
		{
			lb = ft_realloc((void *)(lb), BUFFER_SIZE + 1);
			if (lb == NULL)
				return (0);
			ft_strlcpy((char *)(lb) + ft_strlen(lb), fb, BUFFER_SIZE + 1);
			ft_memset((void *)fb, 0, BUFFER_SIZE);
		}
	}
	return ((char *)(lb));
}

/**
 * @brief This function processes the buffer whenever a newline is found within
 *
 * @param nl_ptr
 * @param fb
 * @param lb
 * @param idx_start
 * @return char*
 */
static char	*ft_proc_nl_buf(char *nl_ptr, char *fb, void *lb, size_t idx_start)
{
	ssize_t	num_read;
	size_t	cnt_byte;

	nl_ptr = ft_memchr((void *)fb, (unsigned char) '\n', BUFFER_SIZE);
	num_read = (nl_ptr - &fb[idx_start]);
	lb = ft_realloc((void *)lb, num_read + 1 + 1);
	if (lb == NULL)
		return (0);
	cnt_byte = ft_strlen((char *)lb);
	ft_strlcpy((char *)lb + cnt_byte, &fb[idx_start], num_read + 1 + 1);
	if (*((char *)(lb + 0)) == 0)
	{
		ft_memset(lb + 0, '\n', 1);
		return ((char *)lb);
	}
	ft_memset((void *)&fb[idx_start], 0, num_read);
	return ((char *)lb);
}

char	*get_next_line(int fd)
{
	void		*line_buf;
	char		*nl_ptr;
	static char	file_buf[BUFFER_SIZE + 1];
	size_t		idx_start;

	file_buf[BUFFER_SIZE] = '\0';
	nl_ptr = NULL;
	line_buf = NULL;
	idx_start = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	line_buf = ft_proc_buf_fd(nl_ptr, file_buf, (char *)line_buf, &idx_start);
	if (line_buf == (void *)1)
		return (0);
	line_buf = ft_read_fd(file_buf, (char *)line_buf, fd, &idx_start);
	nl_ptr = ft_memchr((void *)file_buf, (unsigned char) '\n', BUFFER_SIZE);
	if (line_buf == 0 && nl_ptr == 0)
		return (0);
	else if (line_buf && nl_ptr == 0)
		return ((char *) line_buf);
	line_buf = ft_proc_nl_buf(nl_ptr, file_buf, line_buf, idx_start);
	return ((char *)line_buf);
}
