/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:08:19 by fokrober          #+#    #+#             */
/*   Updated: 2019/08/06 18:21:25 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int		main(int ac, char **av)
{
	char	*s;
	int		rep;
	int		len;

	rep = 0;
	s = NULL;
	if (ac >= 2)
	{
		s = build(ac, av);
		len = ft_strlen(av[1]);
		rep = check(s, len);
		if (rep)
			ft_putstr("Success");
		else
			ft_putstr("Fail");
		free(s);
	}
	ft_putstr("\n");
	return (0);
}
