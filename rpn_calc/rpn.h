/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:01:32 by fokrober          #+#    #+#             */
/*   Updated: 2019/08/08 18:38:56 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H
# include <stdlib.h>
# include <stdio.h>

int		check(int ac, char **av);
int		isnum(char *s, int i);
char	*build(char *s, int	len);
int		ft_strlen(char *s);
int		isop(char *s, int i);
int		isp(char *s, int i);
int		rpn_calc(char *s, int i, int len, int *ret);
#endif
