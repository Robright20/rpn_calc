/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:10:46 by fokrober          #+#    #+#             */
/*   Updated: 2019/08/09 00:18:52 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.h"

int		main(int ac, char **av)
{
	int		len;
	int		ret;
	char	*s;

	if ((ret = check(ac, av)) < 0)
		printf("Error\n");
	else
	{
		len = ft_strlen(av[1]);
		if (ret != len)
		{
			printf("Error\n");
			return (0);
		}
		s = build(av[1], len);
		printf("%d\n", rpn_calc(s, 0, len, &ret));
		free(s);
	}
	return (0);
}
