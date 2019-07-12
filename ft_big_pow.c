/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_pow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:38:29 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/12 10:38:31 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

void			set_int(char *str, t_number *integral)
{
	int len;

	len = get_lst_len(integral);
	while (integral)
	{
		str[--len] = integral->num + 48;
		integral = integral->next;
	}
}

char			*make_str(t_number *integral, t_number *fractional, int sign)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) *
			(2 + sign + get_lst_len(integral) + get_lst_len(fractional)))))
		return (0);
	if (sign)
		str[i++] = '-';
	set_int(&str[i], integral);
	i += get_lst_len(integral);
	str[i++] = '.';
	while (fractional)
	{
		str[i++] = fractional->num + 48;
		fractional = fractional->next;
	}
	str[i] = 0;
	return (str);
}

static void		div_lst(t_number *lst)
{
	int			tmp;
	t_number	*prev;

	tmp = 0;
	while (lst)
	{
		tmp = tmp * 10 + lst->num;
		lst->num = tmp / 2;
		tmp = tmp % 2;
		prev = lst;
		lst = lst->next;
	}
	if (tmp)
		prev->next = new_num(tmp * 10 / 2);
}

static void		mul_lst(t_number *lst)
{
	int			tmp;
	t_number	*prev;

	tmp = 0;
	while (lst)
	{
		tmp += lst->num * 2;
		lst->num = tmp % 10;
		tmp = tmp / 10;
		prev = lst;
		lst = lst->next;
	}
	if (tmp)
		prev->next = new_num(tmp);
}

t_number		*ft_big_pow(int a)
{
	t_number	*lst;

	if (a >= 0)
	{
		lst = new_num(1);
		if (a == 0)
			return (lst);
		while (a--)
			mul_lst(lst);
		return (lst);
	}
	else
	{
		lst = new_num(5);
		if (a == -1)
			return (lst);
		while (a++ != -1)
			div_lst(lst);
		return (lst);
	}
	return (0);
}
