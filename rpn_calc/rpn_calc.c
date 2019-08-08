/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:24:02 by fokrober          #+#    #+#             */
/*   Updated: 2019/08/08 14:00:00 by fokrober         ###   ########.fr       */
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
void	op(char c, int k, int *ans)
{
	if (c == '-')
		*ans -= k;
	else if (c == '+')
		*ans += k;
	else if (c == '*')
		*ans *= k;
	else if (c == '/')
		*ans /= k;
	else if (c == '%')
		*ans %= k;
	printf("ans inside %d\n", *ans);
}

int		calc(char *s, int rep, int i, int *ans, char c)
{
	int			k;
	static char	sign;

	k = ft_atoi(s, i, rep);
	if (i - 2 == 0)
		*ans = k;
	else
		op(sign, k, ans);
	sign = c;
	printf("sign [%c]\t k [%d]\n", c, k);
	return (rep);
}

int		rpn_calc(char *s, int i, int len, int *ans, char c)
{
	int		rep;
	
	if (i >= len)
		return (i);
	if ((rep = isop(s, i)) > 0)
	{
		if ((rep = rpn_calc(s, rep + 1, len, ans, s[i])) > 0 && isp(s, rep))
				return (rpn_calc(s, rep + 1, len, ans, s[i]));
		return (-1);
	}
	else if (i > 1 && (rep = isnum(s, i)) > 0)
		return (calc(s, rep, i, ans, c));
	return (-1);
}
