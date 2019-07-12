/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:12:15 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/10 16:12:16 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

int			get_lst_len(t_number *lst)
{
	int len;

	len = 0;
	while (lst)
	{
		++len;
		lst = lst->next;
	}
	return (len);
}

void		show_num(t_number *lst, int a)
{
	if (lst && a == 0)
	{
		show_num(lst->next, 0);
		printf("%d", lst->num);
	}
	else if (lst && a == 1)
	{
		while (lst)
		{
			printf("%d", lst->num);
			lst = lst->next;
		}
	}
}

void		free_num(t_number *lst)
{
	t_number *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

t_number	*new_num(int num)
{
	t_number *new;

	if (!(new = (t_number *)malloc(sizeof(t_number))))
		return (0);
	new->next = 0;
	new->num = num;
	return (new);
}
