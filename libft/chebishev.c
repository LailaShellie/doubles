#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "libft.h"

long double		u_to_x(long double u, long double a,long double b)
{
	return (u * (b - a) / 2 + (a + b) / 2);
}

long double		x_to_u(long double x, long double a, long double b)
{
	return ((2 * x - a - b) / (b - a));
}

long double		Tn(long double u, int n)
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

void		get_nodes(int n, long double *u)
{
	int i;

	i = 0;
	while (i < n)
	{
		u[i] = cos((2 * (i + 1) - 1) * 3.14159265 / (2 * n));
		++i;
	}
}

int			main()
{
	int i = 0;
	int j;
	long double a = 0;
	long double b = 1;
	int n = 8;
	long double y[n];
	long double c[n];
	long double u[n];

	get_nodes(n, u);
	i = 0;
	while (i < n)
	{
		y[i] = exp(u_to_x(u[i], a, b));
		++i;
	}
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c[i] += Tn(u[j], i) * y[j];
			++j;
		}
		if (!i)
			c[i] = c[i] / n;
		else
			c[i] = 2 * c[i] / n;
		++i;
	}
	i = 0;
//	while (i < n)
//	{
//		printf("%Lf\n", c[i]);
//		++i;
//	}
	double p = 1020;
	printf("%########+++#######++#########++++0+++#############+++10.10lf",p);
//	double x = 3.14159265 / 6;
//	printf("%.10lf\n", cos(x));
//	printf("%.10lf\n", ft_cos(x));
	return (0);
}