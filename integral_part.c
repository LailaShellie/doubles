/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:05:15 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/10 17:29:27 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

void				sum_tmp(t_number *lst, int tmp)
{
	t_number	*prev;

	while (lst)
	{
		tmp += lst->num;
		lst->num = tmp % 10;
		tmp = tmp / 10;
		prev = lst;
		lst = lst->next;
	}
	if (tmp)
		prev->next = new_num(tmp);
}

static void			sum_lst(t_number *lst1, t_number *lst2)
{
	t_number	*prev;
	int			tmp;

	tmp = 0;
	while (lst2)
	{
		tmp += lst1->num + lst2->num;
		lst1->num = tmp % 10;
		tmp = tmp / 10;
		prev = lst1;
		lst1 = lst1->next;
		lst2 = lst2->next;
	}
	if (tmp && prev->next)
		sum_tmp(prev->next, tmp);
	else if (tmp && !lst1)
		prev->next = new_num(tmp);
}

t_number			*get_integral_part(int exp, char *frac)
{
	t_number	*lst;
	t_number	*tmp;

	lst = 0;
	while (exp >= 0 && *frac)
	{
		if (*frac == '1')
		{
			if (!lst)
			{
				lst = ft_big_pow(exp);
			}
			else
			{
				tmp = ft_big_pow(exp);
				sum_lst(lst, tmp);
				free(tmp);
			}
		}
		--exp;
		++frac;
	}
	if (!lst)
		lst = new_num(0);
	return (lst);
}
