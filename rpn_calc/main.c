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

int	main(int ac, char **av)
{
	int	len;
	int	ret;
	char	*s;

	if ((ret = check(ac, av, &len, &s)) < 0)
		printf("Error\n");
	else
	{
		if (ret != len)
		{
			printf("Error\n");
			return (0);
		}
		len = rpn_calc(s, 0, len, &ret);
		if (ret > 0)
			printf("%d\n", len);
		free(s);
	}
	return (0);
}
