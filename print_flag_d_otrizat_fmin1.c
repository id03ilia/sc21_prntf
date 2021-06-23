#include "ft_printf.h"

static int	fpr_flg_d_B4(t_fpnt_list flagi, int u_l)
{
	int	i;

	i = 0;
	if (flagi.f_tochnost == -1)
		flagi.length = ft_putchar_fd_p(1, '-', flagi);
	if (flagi.f_tochnost > 0)
	{
		flagi.length = ft_putchar_fd_p(1, '-', flagi);
		i = flagi.f_tochnost - u_l;
		while (i-- > 0)
			flagi.length = ft_putchar_fd_p(1, '0', flagi);
	}
	return (flagi.length);
}

static int	fpr_flg_d_B5(t_fpnt_list flagi, int u_l)
{
	int	i;

	i = 0;
	if (flagi.f_tochnost > 0)
	{
		if (flagi.f_tochnost > u_l)
			i = flagi.f_shirina - flagi.f_tochnost - 1;
		if (flagi.f_tochnost <= u_l)
			i = flagi.f_shirina - u_l - 1;
		while (i-- > 0)
			flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	}
	return (flagi.length);
}

static int	fpr_flg_d_B6(t_fpnt_list flagi, int u_l)
{
	int	i;

	i = 0;
	if (flagi.f_tochnost == -1 && flagi.f_zero == 0)
	{
		i = flagi.f_shirina - u_l - 1;
		while (i-- > 0)
			flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	}
	if (flagi.f_tochnost == -1 && flagi.f_zero == 1)
	{
		i = flagi.f_shirina - u_l - 1;
		while (i-- > 0)
			flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	}
	return (flagi.length);
}

static int	fpr_flg_d_B7(t_fpnt_list flagi, int u, int u_l)
{
	int	i;

	i = flagi.f_shirina - u_l - 1;
	while (i-- > 0)
		flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	if (u == 0)
	{
		if (flagi.f_shirina > 0)
			flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	}
	return (flagi.length);
}

int	fpr_f_mind_fmi1(t_fpnt_list flagi, char *s, int u, int u_l)
{
	int	u_l_minus;

	u_l_minus = u_l;
	flagi.length = fpr_flg_d_B4(flagi, u_l);
	if (flagi.f_tochnost == 0)
		flagi.length = ft_putchar_fd_p(1, '-', flagi);
	while (u_l_minus > 0)
	{
		flagi.length = ft_putchar_fd_p(1, *s, flagi);
		s++;
		u_l_minus--;
	}
	flagi.length = fpr_flg_d_B5(flagi, u_l);
	flagi.length = fpr_flg_d_B6(flagi, u_l);
	if (flagi.f_tochnost == 0)
	{
		flagi.length = fpr_flg_d_B7(flagi, u, u_l);
		if (u == 0)
			return (flagi.length);
	}
	return (flagi.length);
}
