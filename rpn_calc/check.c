/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:22:35 by fokrober          #+#    #+#             */
/*   Updated: 2019/08/08 23:11:22 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.h"

int		isnum(char *s, int i)
{
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (!(s[i]) || isp(s, i))
		return (i);
	return (-1);
}

int		isopchr(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int		isop(char *s, int i)
{
	if (isopchr(s[i++]) && isp(s, i))
		return (i);
	return (-1);
}

int		chk(char *s, int i, int len)
{
	int		rep;

	if (i >= len)
		return (i);
	if ((rep = isop(s, i)) > 0)
	{
		if ((rep = chk(s, rep + 1, len)) > 0 && (rep = chk(s, rep + 1, len)) > 0)
			return (rep);
		return (rep);
	}
	else if (i != 0 && (rep = isnum(s, i)) > 0)
		return (rep);
	return (-1);
}

int		check(int ac, char **av)
{
	char	*s;
	int		len;

	if (ac != 2)
		return (-1);
	len = ft_strlen(av[1]);
	s = build(av[1], len);
	return (chk(s, 0, ft_strlen(s)));
}
