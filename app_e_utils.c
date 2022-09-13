/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_e_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:21:51 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/01 13:23:08 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_utils.h"

int	ft_app_chk_node(t_app *a, t_queue *qp_r, t_queue *qp_c)
{
	char	**g_map;

	g_map = a->map->gmap;
	if (a->matrix[a->p_r][a->p_c] == 0)
	{
		if (g_map[a->p_r][a->p_c] == '0' || g_map[a->p_r][a->p_c] == 'C')
		{
			ft_queue_enqueue(qp_r, a->p_r);
			ft_queue_enqueue(qp_c, a->p_c);
		}
	}
	return (0);
}

int	ft_app_chk_nodes(t_app *a, t_queue *qp_r, t_queue *qp_c)
{
	a->p_r = 0;
	a->p_c = 0;
	while (qp_r->len > 0)
	{
		ft_queue_pop(qp_r, &(a->p_r));
		ft_queue_pop(qp_c, &(a->p_c));
		a->matrix[a->p_r][a->p_c] = 1;
		if (a->p_r == a->t_r && a->p_c == a->t_c)
			return (0);
		a->p_c -= 1;
		ft_app_chk_node(a, qp_r, qp_c);
		a->p_c += 2;
		ft_app_chk_node(a, qp_r, qp_c);
		a->p_c -= 1;
		a->p_r += 1;
		ft_app_chk_node(a, qp_r, qp_c);
		a->p_r -= 2;
		ft_app_chk_node(a, qp_r, qp_c);
	}
	return (-1);
}

int	ft_app_srch_paths(t_app *a, t_queue *qp_r, t_queue *qp_c)
{
	while (a->cq->len > 0)
	{
		a->matrix = ft_app_create_matrix(a->map);
		if (a->matrix == NULL)
			ft_printf("\nError\ncreating matrix");
		ft_queue_pop(a->rq, &(a->t_r));
		ft_queue_pop(a->cq, &(a->t_c));
		if (ft_app_chk_nodes(a, qp_r, qp_c) < 0)
		{
			ft_printf("\nError\nGame is not playable");
			ft_app_matrix_del(a->map, a->matrix);
			return (-1);
		}
		ft_app_matrix_del(a->map, a->matrix);
	}
	return (0);
}

void	ft_app_del_queues(t_app *a, t_queue *qp_r, t_queue *qp_c)
{
	ft_queue_del(a->rq);
	ft_queue_del(a->cq);
	ft_queue_del(qp_c);
	ft_queue_del(qp_r);
}

int	ft_app_is_playable(t_app *a)
{
	t_queue	*qp_c;
	t_queue	*qp_r;
	char	*str;
	int		idx;

	str = "PE";
	idx = 0;
	qp_r = ft_queue_create((int)(a->map->x * a->map->y) * 4);
	qp_c = ft_queue_create((int)(a->map->x * a->map->y) * 4);
	ft_app_init_collectible_queue(a);
	while (str[idx] != '\0' && a->rc == 0)
	{
		a->map->chr_srch = str[idx];
		ft_map_iter(a, ft_map_find_chr);
		ft_queue_enqueue(qp_r, (int)a->map->idx_y);
		ft_queue_enqueue(qp_c, (int)a->map->idx_x);
		a->map->chr_srch = 'C';
		if (ft_map_iter(a, ft_map_get_chr_cord) < 0)
			return (-1);
		if (ft_app_srch_paths(a, qp_r, qp_c) < 0)
			a->rc = -1;
		idx ++;
	}
	ft_app_del_queues(a, qp_r, qp_c);
	return (a->rc);
}
