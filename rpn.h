/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bob <fokrober@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 09:17:18 by bob               #+#    #+#             */
/*   Updated: 2020/09/09 18:43:33 by bob              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H
# include <stdio.h>
# include <stdlib.h>
# define SPACE " \t"
# define SIGN "+-*/%"
# define TRUE 1
# define FALSE 0
# define ERR "Error"

typedef struct	s_val
{
	int		op;
	int		err;
	char	*sign;
}				t_val;

int				isnumber(char *s);
int				is_operator(char *s);
char			*ft_itoa(int n);
int				compute(int *op, int next_op, char *cur_sign);
#endif
