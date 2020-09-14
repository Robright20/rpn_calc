/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob <fokrober@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 09:50:30 by bob               #+#    #+#             */
/*   Updated: 2020/09/09 16:34:41 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.h"

int		isnumber(char *s)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	if (s == NULL || !*s)
		return (FALSE);
	i = (s[0] == '+' || s[0] == '-') && (s[1] >= '0' && s[1] <= '9');
	start = i;
	while (s[i] && i < 10)
	{
		j = -1;
		while (SPACE[++j])
		{
			if (SPACE[j] == s[i])
				return (i);
		}
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (FALSE);
		i++;
	}
	if (i == 10 && (s[start] - '0' > 2 ||
				(s[start] == '2' && s[start + 1] != '1')))
		return (FALSE);
	return (i);
}

int		is_operator(char *s)
{
	int		i;

	i = 0;
	if (!s || !*s)
		return (FALSE);
	while (SIGN[i] && SIGN[i] != s[0])
		i++;
	if (SIGN[i] != s[0])
		return (FALSE);
	i = 0;
	while (SPACE[i] && SPACE[i] != s[1])
		i++;
	if (SPACE[i] != s[1] && s[1])
		return (FALSE);
	return (TRUE);
}

char	*ft_itoa(int number)
{
	unsigned int	u_number;
	int				len;
	char			sign;
	char			*buf;

	sign = number < 0;
	u_number = (1 - 2 * sign) * number;
	len = 0;
	while (++len && number / 10)
		number /= 10;
	len += sign;
	if (!(buf = malloc(len + 1)))
		return (NULL);
	buf[len] = 0;
	if (u_number == 0 || sign)
		buf[0] = sign ? '-' : '0';
	while (u_number > 0)
	{
		len--;
		buf[len] = u_number % 10 + '0';
		u_number /= 10;
	}
	return (buf);
}

int		compute(int *cur_op, int next_op, char *sign)
{
	int		err;
	int		op;

	err = FALSE;
	op = *cur_op;
	if (!sign)
		return (0);
	if (*sign == '+')
		*cur_op = op + next_op;
	else if (*sign == '-')
		*cur_op = op - next_op;
	else if (*sign == '*')
		*cur_op = op * next_op;
	else if (next_op == 0)
		err = TRUE;
	else if (*sign == '/')
		*cur_op = op / next_op;
	else if (*sign == '%')
		*cur_op = op % next_op;
	return (err);
}
