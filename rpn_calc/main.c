/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:10:46 by fokrober          #+#    #+#             */
/*   Updated: 2019/08/08 09:30:37 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.h"

int		main(int ac, char **av)
{
	if (check(ac, av) <= 0)
		printf("Error");
	else
		printf("%d\n", rpn_calc(av[1], 0, ft_strlen(av[1])));
	return (0);
}
