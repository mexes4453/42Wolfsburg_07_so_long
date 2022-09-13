/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:43:09 by cudoh             #+#    #+#             */
/*   Updated: 2022/05/26 09:14:37 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			idx;
	unsigned char	*src;
	unsigned char	*chr;

	idx = 0;
	chr = 0;
	src = (unsigned char *)s;
	while (idx < n)
	{
		if ((*(src + idx)) == (unsigned char)c)
		{
			chr = (src + idx);
			return ((void *)chr);
		}
		idx++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	if (s == NULL)
		return (0);
	idx = 0;
	while (*(s + idx) != '\0')
	{
		idx++;
	}
	return (idx);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	idx;
	size_t	src_len;

	idx = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (*(src + idx) != '\0' && (idx < (size - 1)))
	{
		(*(dst + idx)) = (*(src + idx));
		idx++;
	}
	(*(dst + idx)) = '\0';
	return (src_len);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			idx;
	unsigned char	*mem_adr;

	idx = 0;
	mem_adr = (unsigned char *)s;
	while (idx < n)
	{
		*(mem_adr + idx) = c;
		idx++;
	}
	return ((void *)s);
}

void	*ft_realloc(void *src, size_t offset_size)
{
	void	*new_buf;

	if (src == NULL)
	{
		new_buf = malloc(offset_size + 1);
		if (new_buf == NULL)
			return (0);
		ft_memset(new_buf, 0, offset_size + 1);
		return (new_buf);
	}
	new_buf = malloc(ft_strlen(src) + offset_size + 1);
	if (new_buf == NULL)
		return (0);
	ft_memset(new_buf, 0, ft_strlen(src) + offset_size + 1);
	ft_strlcpy((char *)new_buf, (char *)src, ft_strlen(src) + 1);
	free(src);
	src = NULL;
	return (new_buf);
}
