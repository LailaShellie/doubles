/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chebishev_polinoms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 18:56:47 by lshellie          #+#    #+#             */
/*   Updated: 2019/06/28 18:56:49 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double		Tn(double u, int n)
{
	long double Tprev;
	long double T;
	long double Tnext;
	int i;

	Tnext = 1;
	Tprev = 1;
	T = u;
	i = 1;
	if (n == 0)
		return (1);
	else if (n == 1)
		return (u);
	while (i < n)
	{
		Tnext = 2 * u * T - Tprev;
		Tprev = T;
		T = Tnext;
		++i;
	}
	return (Tnext);
}

static double		x_to_u(double x, double a, double b)
{
	return ((2 * x - a - b) / (b - a));
}

double				f_x(double x, double *c, double a, double b, int n)
{
	int i = 0;
	double res = 0;

	while (i < n)
	{
		res += c[i] * Tn(x_to_u(x, a, b), i);
		++i;
	}
	return (res);
}