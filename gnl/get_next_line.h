/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:43:05 by cudoh             #+#    #+#             */
/*   Updated: 2022/05/26 10:36:46 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
// Includes for test purpose
//# include <sys/types.h>
//# include <sys/stat.h>
//# include <fcntl.h>
//# include <stdio.h>

// Allow "compiler cc/gcc/clang -D" to override definition
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// FUNCTION DECLARATIONS
char	*get_next_line(int fd);
// UTILS FUNCTION  DECLARATIONS
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_realloc(void *src, size_t offset_size);
void	*ft_memset(void *s, int c, size_t n);
#endif
