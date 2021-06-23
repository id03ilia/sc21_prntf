#include "ft_printf.h"

static int	fpr_flg_p_C6(t_fpnt_list flagi, int u_l)
{
	int	i;

	i = 0;
	if (flagi.f_tochnost == 0)
	{
		i = flagi.f_shirina - u_l;
		while (i-- > 0)
			flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	}
	if (flagi.f_tochnost > 0)
	{
		i = flagi.f_tochnost + 1;
		while (i-- > 0)
			flagi.length = ft_putchar_fd_p(1, '0', flagi);
		i = flagi.f_shirina - flagi.f_tochnost - u_l - 1;
		while (i-- > 0)
			flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	}
	return (flagi.length);
}

static int	fpr_flg_p_C7(t_fpnt_list flagi, int u_l)
{
	int	i;

	i = 0;
	if (flagi.f_tochnost == -1 && flagi.f_zero == 0)
	{
		i = flagi.f_shirina - u_l - 2 + flagi.toch_empty;
		while (i-- > 0)
			flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	}
	if (flagi.f_tochnost == -1 && flagi.f_zero == 1)
	{
		i = flagi.f_shirina - u_l;
		while (i-- > 0)
			flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	}
	return (flagi.length);
}

int	fpr_flg_p_fmin1(t_fpnt_list flagi, char *s, int u_l)
{
	int	u_l_minus;

	u_l_minus = u_l;
	if (u_l_minus > 0)
		flagi.length = ft_putchar_fd_p_0x(1, flagi);
	while (u_l_minus > 0)
	{
		flagi.length = ft_putchar_fd_p(1, *s, flagi);
		s++;
		u_l_minus--;
	}
	flagi.length = fpr_flg_p_C6(flagi, u_l);
	flagi.length = fpr_flg_p_C7(flagi, u_l);
	return (flagi.length);
}
