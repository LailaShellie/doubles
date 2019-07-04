/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 19:42:49 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/02 19:42:50 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

void	print_mas(unsigned int *mas, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		printf("%u ", mas[i]);
		++i;
	}
	printf("\n");
}

static int get_len(double num)
{
	int		n;

	n = 1;
	while (num > 10)
	{
		num = num / NUM;
		++n;
	}
	return (n);
}

static unsigned int	*split_integral(double nbr, int n)
{
	unsigned int		*mas;
	int					i;

	i = 0;
	if (!(mas = (unsigned int *)malloc(sizeof(unsigned int) * n)))
		return (0);
	while (i < n)
	{
		mas[i] = (unsigned long long int)(nbr / ft_pow(NUM, n - i - 1)) % NUM;
		++i;
	}
	return (mas);
}

static unsigned int	*sum_all(unsigned int **all, int num, int n)
{
	unsigned int		*res;
	int					j;
	unsigned int		tmp;
	int					k;

	k = 0;
	tmp = 0;
	if (!(res = (unsigned int *)malloc(sizeof(unsigned int) * (n + 1))))
		return (0);
	while (--n != -1)
	{
		j = 0;
		while (j < num)
		{
			tmp += all[j][n];
			++j;
		}
		res[k++] = tmp % NUM;
		tmp = tmp / NUM;
	}
	res[k] = tmp;
	return (res);
}

static char *split_all_integral(double *mas, int num)
{
	unsigned int		**all;
	unsigned int		*res;
	char				*str;
	int					n;
	int					i;

	i = 0;
	if (!(all = (unsigned int **)malloc(sizeof(unsigned int *) * num)))
		return (0);
	n = get_len(mas[i]);
	all[i] = split_integral(mas[i], n);
//	print_mas(all[i], n);
	while (++i < num)
	{
		all[i] = split_integral(mas[i], n);
//		print_mas(all[i], n);
	}
	res = sum_all(all, num, n);
	free_all(all, num);
	str = make_str(res, n + 1);
	free(res);
	return (str);
}

char		*get_integral_part(double **mas, char *frac, int exp)
{
	int num;
	int tmp;
	int i;
	int j;

	tmp = exp;
	j = 0;
	num = 0;
	i = 0;
	while (frac[i] && tmp >= 0)
	{
		if (frac[i] == '1')
			++num;
		++i;
		--tmp;
	}
	printf("!!%d %d!!\n", exp, num);
	if (!(*mas = (double *)ft_memalloc(sizeof(double) * num)))
		return (0);
	i = 0;
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
	return (split_all_integral(*mas, num));
}
