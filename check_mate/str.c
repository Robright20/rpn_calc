/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:13:45 by fokrober          #+#    #+#             */
/*   Updated: 2019/08/07 17:31:32 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_strcpy(char *dst, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	return (i);
}

char	*build(int ac, char **av)
{
	int		len;
	int		i;
	char	*rep;
	char	*s;

	i = 1;
	len = 0;
	while (i < ac)
		len += ft_strlen(av[i++]);
	s = (char *)malloc(len + 1);
	s[len] = '\0';
	i = 1;
	rep = s;
	while (i < ac)
	{
		len = ft_strcpy(s, av[i]);
		s += len;
		i++;
	}
	return (rep);
}

int		isp(char c)
{
	return (c == 'P' || c == 'B' || c == 'R' || c == 'Q');
}
