/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob <fokrober@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 09:16:05 by bob               #+#    #+#             */
/*   Updated: 2020/09/09 22:49:45 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.h"

static char	*check(char *expr)
{
	int		i;
	int		space;

	if (!expr)
		return (NULL);
	while (*expr)
	{
		space = 0;
		i = -1;
		while (SPACE[++i])
			space += (*expr == SPACE[i]);
		if (!space)
			break ;
		expr += 1;
	}
	return (expr);
}

static void	getnext(t_val *prev, char *expr, int op)
{
	t_val		cur;
	int			len;
	static int	size;

	size += 1;
	cur = (t_val){0, 0, 0};
	if ((expr = check(expr)) && is_operator(expr))
	{
		if (size <= 1)
			prev->err = TRUE;
		else if (size-- || TRUE)
			*prev = (t_val){op, 0, expr};
	}
	else if ((len = isnumber(expr)))
	{
		getnext(&cur, expr + len, atoi(expr));
		if (!is_operator(cur.sign))
			prev->err = TRUE;
		else if (size-- && (!(prev->err = compute(&op, cur.op, cur.sign))))
			getnext(prev, cur.sign + 1, op);
	}
	else
		prev->err = (*expr != 0);
	(*expr == 0) ? prev->op = op : 0;
}

int			main(int ac, char **av)
{
	t_val	cur;
	char	*result;
	char	*expr;
	int		len;

	if (ac != 2)
		return (printf("Error\n"));
	cur.op = 0;
	cur.sign = NULL;
	cur.err = FALSE;
	result = NULL;
	expr = check(av[1]);
	if ((len = isnumber(expr)))
	{
		getnext(&cur, expr + len, atoi(expr));
		result = ft_itoa(cur.op);
	}
	printf("%s\n", result && !cur.err ? result : ERR);
	if (result)
		free(result);
	return (0);
}
