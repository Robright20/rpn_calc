/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:24:02 by fokrober          #+#    #+#             */
/*   Updated: 2019/08/08 19:05:05 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.h"

int		ft_atoi(char *str, int i, int rep)
{
	char	*s;
	int		k;

	s = build(&str[i], rep - i);
	k = atoi(s);
	free(s);
	return (k);
}
int		op(char c, int rep1, int rep2)
{
	if (c == '-')
		return (rep1 - rep2);
	else if (c == '+')
		return (rep1 + rep2);
	else if (c == '*')
		return (rep1 * rep2);
	else if (c == '/')
		return (rep1 / rep2);
	else if (c == '%')
		return (rep1 % rep2);
	return (0);
}

int		calc(int rep1, char c, int rep2)
{
	int		rep;

	rep = op(c, rep1, rep2);
	printf("rep1 %d\trep2 %d\tc [%c]\t rep [%d]\n", rep1, rep2, c, rep);
	return (rep);
}

int		rpn_calc(char *s, int i, int len, int *ret)
{
	int		rep;
	
	if (i >= len)
		return (i);
	if ((*ret = isop(s, i)) > 0)
	{
		rep = rpn_calc(s, *ret + 1, len, ret);
		printf("ret + 1 %d\n", *ret + 1);
		return (calc(rpn_calc(s, *ret + 1, len, ret), s[i], rep));
	}
	else if (i > 1 && (*ret = isnum(s, i)) > 0)
		return (ft_atoi(s, i, *ret));
	return (0);
}
