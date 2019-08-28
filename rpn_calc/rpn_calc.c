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

int	ft_atoi(char *str, int i, int rep)
{
	char	*s;
	int	k;

	s = build(&str[i], rep - i);
	k = atoi(s);
	free(s);
	return (k);
}

int	calc(int rep1, char c, int rep2, int *ret)
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
		*ret = -1;
	}
	return (-1);
}

int	rpn_calc(char *s, int i, int len, int *ret)
{
	int	rep;

	if (i >= len)
		return (i);
	if ((*ret = isop(s, i)) > 0)
	{
		rep = rpn_calc(s, *ret + 1, len, ret);
		return (calc(rpn_calc(s, *ret + 1, len, ret), s[i], rep, ret));
	}
	else if (i > 1 && (*ret = isnum(s, i)) > 0)
		return (ft_atoi(s, i, *ret));
	return (-1);
}
