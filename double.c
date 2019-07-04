/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:42:50 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/01 12:42:52 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"



void	free_all(unsigned int **all, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		free(all[i]);
		++i;
	}
	free(all);
}

double	ft_pow(double a, int b)
{
	double res;
	int flag;

	flag = 0;
	if (b < 0)
	{
		flag = 1;
		b = -b;
	}
	res = 1;
	while (b)
	{
		if (b & 1)
			res *= a;
		a *= a;
		b >>= 1;
	}
	if (flag)
		return (1 / res);
	return (res);
}

void print(unsigned int *mas, int n)
{
	int i = n - 1;
	while (i >= 0)
	{
		printf("%u", mas[i]);
		--i;
	}
}

char *make_str(unsigned int *mas, int n)
{
	char *str;
	int j;
	int i;

	j = 0;
	i = n;
	if (!(str = (char *)malloc(n + 1)))
		return (0);
	while (--i >= 0)
	{
		str[j] = mas[i] % 10 + '0';
		++j;
	}
	str[j] = 0;
	return (str);
}

char	*ft_join(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*str;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	if (*s1 == '0')
		++s1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = len1 + len2 + 2;
	if (!(str = (char *)ft_memalloc(sizeof(str) * len)))
		return (0);
	while (i < len1)
		str[i++] = *s1++;
	str[i++] = '.';
	while (i < len)
		str[i++] = *s2++;
	str[len] = 0;
	return (str);
}

int main()
{
	double p = 213.00009;
	int exp;
	double *mas;
	char *frac;
	char *str1;
	char *str2;

	exp = get_exp(p) - 1023;
	print_bits_double(p);
	printf("\n%.300lf\n", p);
	frac = get_frac(p);
	str1 = get_fractional_part(&mas, frac, exp);
	free(mas);
	mas = 0;
	str2 = get_integral_part(&mas, frac, exp);
	printf("%s\n", ft_join(str2, str1));
	free(mas);
	free(str1);
	free(str2);
	free(frac);
	return (0);
}
