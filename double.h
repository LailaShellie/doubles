/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:59:17 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/02 12:59:19 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_DOUBLE_H
#define FT_PRINTF_DOUBLE_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM 10

void	print_mas(unsigned int *mas, int n);
void				print_bits_double(double octet);
int					get_exp(double exp);
double				ft_pow(double a, int b);
char				*get_integral_part(double **mas, char *frac, int exp);
void				print(unsigned int *mas, int n);
char				*get_fractional_part(double **mas, char *frac, int exp);
void				free_all_fractional(unsigned int **all, int num);
char				*get_frac(double num);
char				*make_str(unsigned int *mas, int n);
void				free_all(unsigned int **all, int num);

#endif
