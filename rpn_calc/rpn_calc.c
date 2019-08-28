/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 00:42:41 by fokrober          #+#    #+#             */
/*   Updated: 2019/08/18 21:12:18 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.h"

int	ft_atoi(char *str, int start, int end)
{
	char	*s;
	int	k;

	s = build(&str[start], end - start);
	k = atoi(s);
	free(s);
	return (k);
}

int	calc(int rep1, char c, int rep2, int *err)
{
	int	rep;

	if (c == '-')
		return (rep1 - rep2);
	else if (c == '+')
		return (rep1 + rep2);
	else if (c == '*')
		return (rep1 * rep2);
	else if (c == '/' || c == '%')
	{
		if (rep2 != 0)
			return ((rep = (c == '/') ? rep1 / rep2 : rep1 % rep2));
		printf("Error\n");
		*err = -1;
	}
	return (-1);
}

int	rpn_calc(char *s, int i, int len, int *ret)
{
	int	rep1;
	int	rep2;

	if (i >= len)
		return (i);
	if ((*ret = isop(s, i)) > 0)
	{
		rep2 = rpn_calc(s, *ret + 1, len, ret);
		rep1 = rpn_calc(s, *ret + 1, len, ret);
		return (calc(rep1, s[i], rep2, ret));
	}
	else if (i > 1 && (*ret = isnum(s, i)) > 0)
		return (ft_atoi(s, i, *ret));
	return (-1);
}
