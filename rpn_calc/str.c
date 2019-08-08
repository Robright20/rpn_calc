/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 06:06:28 by fokrober          #+#    #+#             */
/*   Updated: 2019/08/08 14:00:04 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.h"

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*build(char *str, int len)
{
	char	*s;
	int		i;

	if (!(s = (char *)malloc(len + 1)))
		return (NULL);
	s[len] = '\0';
	i = 0;
	while (--len)
		s[i++] = str[len];
	s[i] = str[len];
	return (s);
}

int		isp(char *s, int i)
{
	if (i && s[i++] == ' ')
		return (isnum(s, i) > i || isop(s, i) > i);
	return (0);
}
