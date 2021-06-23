/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:32:24 by dflorenc          #+#    #+#             */
/*   Updated: 2021/05/23 12:11:10 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putstr_printf(int i, const char *st)
{
	write(1, &st[i], 1);
	i++;
	return (i);
}

static t_fpnt_list	a_p(const char *st, t_fpnt_list flagi, int i, va_list ap)
{
	flagi = a_flag(st, flagi, i, ap);
	flagi.length = ft_flag_print(ap, flagi);
	return (flagi);
}

static void	init_i(int *i, int *kol_arg, int *t)
{
	*i = 0;
	*t = 0;
	*kol_arg = 0;
}

static void	count_i(int *i, int *kol_arg, int *t, t_fpnt_list flagi)
{
	flagi.ii = flagi.ii - *i;
	*kol_arg = *kol_arg + flagi.ii;
	*i = *i + flagi.ii;
	*t = *t + flagi.length;
}

int	ft_printf(const char *st, ...)
{
	va_list			ap;
	t_fpnt_list		flagi;
	int				i;
	int				t;
	int				kol_arg;

	init_i(&i, &kol_arg, &t);
	va_start(ap, st);
	while (st[i] != '\0')
	{
		if (st[i] == '%')
		{
			flagi = a_p(st, flagi, i, ap);
			if (flagi.length == -1)
			{
				va_end (ap);
				return (-1);
			}
			count_i(&i, &kol_arg, &t, flagi);
		}
		else
			i = putstr_printf(i, st);
	}
	va_end (ap);
	return (t + i - kol_arg);
}
