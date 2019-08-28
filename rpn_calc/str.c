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

int	ft_strlen(char *s)
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
	int	i;

	if (!(s = (char *)malloc(len + 1)))
		return (NULL);
	s[len] = '\0';
	i = 0;
	while (--len)
		s[i++] = str[len];
	s[i] = str[len];
	return (s);
}

int	isp(char *s, int i)
{
	if (i && s[i++] == ' ')
		return (isnum(s, i) > i || isop(s, i) > i);
	return (0);
}

int	count_nonsp(char *s)
{
	int	nonsp_len;
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	nonsp_len = 0;
	while (s[i])
	{
		while (s[i] != ' ' && s[i])
		{
			nonsp_len++;
			i++;
			if (s[i] == ' ')
				j++;
		}
		if (!s[i])
			break ;
		i++;
	}
	return (nonsp_len + j);
}

char	*ft_split(char *s)
{
	char	*str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	str = (char *)malloc(count_nonsp(s) + 1);
	while (s[i])
	{
		while (s[i] != ' ' && s[i])
		{
			str[j++] = s[i++];
			if (s[i] == ' ')
				str[j++] = ' ';
		}
		if (!s[i])
			break ;
		i++;
	}
	if (str[j - 1] == ' ')
		j--;
	str[j] = s[i];
	return (str);
}
