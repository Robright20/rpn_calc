/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:24:02 by fokrober          #+#    #+#             */
/*   Updated: 2019/08/08 09:23:30 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.h"

int		rpn_calc(char *s, int i, int len)
{
	int		rep;

	if (i >= len)
		return (i);
	if ((rep = isop(s, i)) > 0)
	{
		if ((rep = chk(s, rep + 1, len)) > 0 && isp(s, rep))
				return (chk(s, rep + 1, len));
		return (-1);
	}
	else if (i != 0 && (rep = isnum(s, i)) > 0)
		return (rep);
	return (-1);
}
