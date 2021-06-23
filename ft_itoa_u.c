/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:18:22 by dflorenc          #+#    #+#             */
/*   Updated: 2021/05/18 11:22:44 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_out_u(char	*mem, unsigned int n)
{
	int		i;
	int		l;
	char	tmp;

	i = 0;
	while (n > 0)
	{
		mem[i++] = (n % 10) + '0';
		n = n / 10;
	}
	if (i == 0)
		mem[i++] = 48;
	mem[i] = '\0';
	l = ft_strlen(mem);
	i = -1;
	while (++i < (l / 2))
	{
		tmp = mem[i];
		mem[i] = mem[l - 1 - i];
		mem[l - 1 - i] = tmp;
	}
	return (mem);
}

int	ft_itoa_len_u(unsigned int n)
{
	unsigned int		nn;
	unsigned int		len_num;

	len_num = 0;
	nn = n;
	while (nn > 0)
	{
		nn = nn / 10;
		len_num++;
	}
	if (n == 0)
		len_num++;
	return (len_num);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*mem;

	mem = (char *)malloc(sizeof(char) * (ft_itoa_len_u(n) + 1));
	if (!mem)
		return (NULL);
	ft_itoa_out_u(mem, n);
	return (mem);
}
