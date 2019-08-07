/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:10:17 by fokrober          #+#    #+#             */
/*   Updated: 2019/08/07 17:28:43 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MATE_H
# define CHECK_MATE_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *s);
int		ft_strlen(char *s);
int		pawn(int pos, char *s, int size, int e);
int		bishop(int pos, char *s, int size);
int		rook(int pos, char *s, int size);
int		queen(int pos, char *s, int size);
int		ft_strcpy(char *dst, char *src);
char	*build(int ac, char **av);
int		check(char *s, int len);
int		isp(char c);
#endif
