#include "ft_printf.h"

static int	fpr_flg_d_A4(t_fpnt_list flagi, int u_l)
{
	int	i;

	i = 0;
	if (flagi.f_tochnost > u_l)
		i = flagi.f_tochnost - u_l;
	if (flagi.f_tochnost <= u_l)
		i = 0;
	while (i-- > 0)
		flagi.length = ft_putchar_fd_p(1, '0', flagi);
	return (flagi.length);
}

static int	fpr_flg_d_A5(t_fpnt_list flagi, int u_l)
{
	int	i;

	i = 0;
	if (flagi.f_tochnost > 0)
	{
		if (flagi.f_tochnost > u_l)
			i = flagi.f_shirina - flagi.f_tochnost;
		if (flagi.f_tochnost <= u_l)
			i = flagi.f_shirina - u_l;
		while (i-- > 0)
			flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	}
	return (flagi.length);
}

static int	fpr_flg_d_A6(t_fpnt_list flagi, int u_l)
{
	int	i;

	i = 0;
	if (flagi.f_tochnost == -1 && flagi.f_zero == 0)
		i = flagi.f_shirina - u_l;
	while (i-- > 0)
		flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	if (flagi.f_tochnost == -1 && flagi.f_zero == 1)
		i = flagi.f_shirina - u_l;
	while (i-- > 0)
		flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	return (flagi.length);
}

int	fpr_flg_d_fmin1(t_fpnt_list flagi, char *s, int u, int u_l)
{
	int	u_l_minus;

	u_l_minus = u_l;
	if (flagi.f_tochnost > 0)
		flagi.length = fpr_flg_d_A4(flagi, u_l);
	if (u_l_minus > 0 && *s == '0' && flagi.toch_empty == 1
		&& flagi.f_shirina > 0)
		flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	while (u_l_minus > 0 && (!((flagi.toch_empty == 1
					|| flagi.f_tochnost == 0) && u == 0)))
	{
		flagi.length = ft_putchar_fd_p(1, *s, flagi);
		s++;
		u_l_minus--;
	}
	if (flagi.f_tochnost == 0)
	{
		flagi.length = fpr_flg_d_A2(flagi, u, u_l);
		if (u == 0)
			return (flagi.length);
	}
	flagi.length = fpr_flg_d_A5(flagi, u_l);
	flagi.length = fpr_flg_d_A6(flagi, u_l);
	return (flagi.length);
}
