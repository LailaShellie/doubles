/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:38:49 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/12 10:38:52 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

char	*make_double(double p)
{
	char		*frac;
	int			exp;
	char		*str;
	t_number	*integral;
	t_number	*fractional;

	frac = get_frac(p);
	exp = get_exp(p);
	integral = get_integral_part(exp, frac);
	fractional = get_fractional_part(exp, frac);
	str = make_str(integral, fractional, get_sign(p));
	free_num(fractional);
	free_num(integral);
	return (str);
}
