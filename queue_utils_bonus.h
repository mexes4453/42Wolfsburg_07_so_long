/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 03:26:07 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/03 03:26:07 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_UTILS_BONUS_H
# define QUEUE_UTILS_BONUS_H
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_queue
{
	int		head;
	int		tail;
	int		sz;
	int		len;
	void	*data;
}			t_queue;

t_queue	*ft_queue_create(int sz);
int		ft_queue_pop(t_queue *q, int *data);
int		ft_queue_enqueue(t_queue *q, int nbr);
int		ft_queue_is_empty(t_queue *q);
void	ft_queue_del(t_queue *q);
#endif
