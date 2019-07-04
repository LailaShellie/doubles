/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   massives.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:54:27 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/02 12:54:28 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"


static int get_len(double num)
{
	int		n;

	n = 0;
	while (num != 0)
	{
		num = num * NUM;
		num = num - (int)num;
		++n;
	}
	return (n);
}

static unsigned int	*split_fractional(double nbr, int n)
{
	unsigned int		*mas;

	if (!(mas = (unsigned int *)malloc(sizeof(unsigned int) * n)))
		return (0);
	while (n > 0)
	{
		nbr = nbr * NUM;
		mas[n - 1] = (int)nbr;
		nbr = nbr - (int)nbr;
		--n;
	}
	return (mas);
}

static unsigned int	*sum_all(unsigned int **all, int num, int n)
{
	unsigned int		*res;
	int		i;
	int		j;
	unsigned int		tmp;

	i = 0;
	tmp = 0;
	if (!(res = (unsigned int *)malloc(sizeof(unsigned int) * n)))
		return (0);
	while (i < n)
	{
		j = 0;
		while (j < num)
		{
			tmp += all[j][i];
			++j;
		}
		res[i] = tmp % NUM;
		tmp = tmp / NUM;
		++i;
	}
	return (res);
}

static char *split_all_fractional(double *mas, int num)
{
	unsigned int		**all;
	unsigned int		*res;
	char				*str;
	int 	n;
	int i;

	i = 0;
	if (!(all = (unsigned int **)malloc(sizeof(unsigned int *) * num)))
		return (0);
	n = get_len(mas[num - 1]);
	all[num - 1] = split_fractional(mas[num - 1], n);
	while (i < num)
	{
		all[i] = split_fractional(mas[i], n);
		++i;
	}
	res = sum_all(all, num, n);
	free_all(all, num);
	str = make_str(res, n);
	free(res);
	return (str);
}

char		*get_fractional_part(double **mas, char *frac, int exp)
{
	int num;
	int i;
	int j;
	int k;

	j = 0;
	k = 0;
	num = 0;
	i = 0;
	while (frac[i] && exp >= 0)
	{
		++i;
		--exp;
	}
	k = i;
	while (frac[i])
	{
		if (frac[i] == '1')
			++num;
		++i;
	}
	if (!(*mas = (double *)ft_memalloc(sizeof(double) * num)))
		return (0);
	i = k;
	while (frac[i] && j < num)
	{
		if (frac[i] == '1')
		{
			(*mas)[j] = ft_pow(2, exp);
			++j;
		}
		--exp;
		++i;
	}
	return (split_all_fractional(*mas, num));
}
