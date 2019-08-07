/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:28:24 by fokrober          #+#    #+#             */
/*   Updated: 2019/08/07 17:48:37 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int		pawn(int pos, char *s, int size, int e)
{
	int		up;
	int		rep;
	int		i;

	i = e;
	while (i--)
		pos -= size;
	up = pos;
	rep = 0;
	if (up >= 0 && (up - e) >= 0)
		rep += (s[up - e] == 'K');
	if (up + e < (size * size))
		rep += (s[up + e] == 'K');
	return (rep);
}

int		bishop(int pos, char *s, int size)
{
	int		up;
	int		down;
	int		e;
	int		rep;

	up = pos / size;
	down = size - (up + 1);
	e = 0;
	rep = 0;
	while (++e <= up && !isp(s[pos + e]) && !isp(s[pos - e]))
		rep += pawn(pos, s, size, e);
	e = 0;
	while (++e <= down && !isp(s[pos + e]) && !isp(s[pos - e]))
		rep += pawn(pos, s, -size, e);
	return (rep);
}

int		rook(int pos, char *s, int size)
{
	int		up;
	int		down;
	int		e;
	int		rep;

	up = pos / size;
	down = size - (up + 1);
	e = 0;
	rep = 0;
	while (++e <= up && !isp(s[pos - (e * (size))]))
		rep += (s[pos - (e * (size))] == 'K');
	e = 0;
	while ((++e <= down) && !isp(s[pos + (e * (size))]))
		rep += (s[pos + (e * (size))] == 'K');
	e = 0;
	while (++e < size && !isp(s[pos + e]))
		rep += (s[pos + e] == 'K');
	e = 0;
	while (++e < size && !isp(s[pos - e]))
		rep += (s[pos - e] == 'K');
	return (rep);
}

int		queen(int pos, char *s, int size)
{
	int		rep;

	rep = 0;
	rep += rook(pos, s, size);
	rep += bishop(pos, s, size);
	return (rep);
}

int		check(char *s, int len)
{
	int		i;
	int		rep;

	i = 0;
	rep = 0;
	while (s[i])
	{
		if (s[i] == 'P')
			rep += pawn(i, s, len, 1);
		else if (s[i] == 'R')
			rep += rook(i, s, len);
		else if (s[i] == 'B')
			rep += bishop(i, s, len);
		else if (s[i] == 'Q')
			rep += queen(i, s, len);
		i++;
	}
	return (rep);
}
