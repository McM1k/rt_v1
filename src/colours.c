/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 13:00:45 by gboudrie          #+#    #+#             */
/*   Updated: 2017/02/11 14:43:03 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		shadow(int col, int percent)
{
	unsigned char	*ptr;

	if (percent > 100 || percent < 0)
		return (col);
	ptr = (unsigned char *)&col;
	ptr[0] = ptr[0] * percent / 100;
	ptr[1] = ptr[1] * percent / 100;
	ptr[2] = ptr[2] * percent / 100;
	return (col);
}
