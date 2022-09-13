/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:15:27 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/22 19:43:17 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int     fd;
    char    *msg;

    fd = 0;
    msg = NULL;
    fd = open("map_00.ber", O_RDONLY, S_IRUSR);
    if (fd < 0)
    {
        write(1, "Error: open\n", 12);
        return (0);
    }
    msg = get_next_line(fd);
    while (msg != NULL)
    {
        write(1, msg, ft_strlen(msg));
        free(msg);
        msg = get_next_line(fd);
    }
    //free(msg);
    return (0);
}
