/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:47:41 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/10 16:47:42 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

static char			*make_frac_str(double num)
{
	unsigned char	*a;
	int				i;
	char			*str;
	int				j;
	int				k;

	i = sizeof(double);
	a = (unsigned char *)&num;
	if (!(str = (char *)malloc(sizeof(double) * 8 + 1)))
		return (0);
	k = 0;
	while (--i >= 0)
	{
		j = 8;
		while (--j >= 0)
		{
			if (a[i] & (1 << j))
				str[k++] = '1';
			else
				str[k++] = '0';
		}
	}
	str[k] = 0;
	return (str);
}

void				print_bits_double(double octet)
{
	unsigned char		*a;
	int					i;
	int					j;
	int					k;

	a = (unsigned char *)&octet;
	i = sizeof(double);
	k = 0;
	while (--i >= 0)
	{
		j = 8;
		while (--j >= 0)
		{
			if (a[i] & (1 << j))
				write(1, "1", 1);
			else
				write(1, "0", 1);
			++k;
			if (k == 1 || k == 12)
				write(1, "|", 1);
		}
	}
}

char				*get_frac(double num)
{
	char *bin;
	char *frac;

	bin = make_frac_str(num);
	frac = ft_strjoin("1", &bin[12]);
	free(bin);
	return (frac);
}

int					get_sign(double sign)
{
	unsigned char		*a;
	int					i;

	a = (unsigned char *)&sign;
	i = sizeof(double) - 1;
	return (a[i] & (1 << 7));
}

int					get_exp(double exp)
{
	unsigned char	*a;
	int				exp_i;
	int				res_i;
	int				res;

	a = (unsigned char *)&exp;
	res = 0;
	res_i = 10;
	exp_i = 6;
	while (exp_i >= 0)
	{
		if (a[7] & (1 << exp_i))
			res ^= (1 << res_i);
		--exp_i;
		--res_i;
	}
	exp_i = 7;
	while (exp_i >= 4)
	{
		if (a[6] & (1 << exp_i))
			res ^= (1 << res_i);
		--exp_i;
		--res_i;
	}
	return (res - 1023);
}
