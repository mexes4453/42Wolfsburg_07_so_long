/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:50:17 by cudoh             #+#    #+#             */
/*   Updated: 2022/04/25 13:52:28 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	int	rc;

	rc = 0;
	if (c >= 0 && c <= 127)
	{
		rc = 1;
	}
	return (rc);
}
