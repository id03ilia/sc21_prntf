#include "ft_printf.h"

static int	fpr_flg_p_C1(t_fpnt_list flagi, int u_l)
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
			flagi.length = ft_putchar_fd_p(1, '0', flagi);
	}
	if (flagi.f_tochnost == 0)
	{
		i = flagi.f_shirina - u_l;
		while (i-- > 0)
			flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	}
	return (flagi.length);
}

static int	fpr_flg_p_C3(t_fpnt_list flagi, int u_l)
{
	int	i;

	i = 0;
	if (flagi.f_shirina - u_l > flagi.f_tochnost)
		i = flagi.f_shirina - u_l - flagi.f_tochnost - 1;
	if (flagi.f_tochnost <= u_l)
		i = flagi.f_shirina - u_l - 2;
	while (i-- > 0)
		flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	return (flagi.length);
}

static int	fpr_flg_p_C4(t_fpnt_list flagi, int u_l, int *temp)
{
	int	i;

	i = 0;
	if (flagi.f_shirina - u_l <= flagi.f_tochnost)
		i = flagi.f_tochnost - u_l;
	if (flagi.f_tochnost > u_l)
		i = flagi.f_tochnost - u_l;
	if (i > 0)
		flagi.length = ft_putchar_fd_p_0x(1, flagi);
	while (i-- > 0)
	{
		flagi.length = ft_putchar_fd_p(1, '0', flagi);
		*temp = 1;
	}
	return (flagi.length);
}

static int	fpr_flg_p_C5(t_fpnt_list flagi, int u_l)
{
	int	i;

	i = 0;
	if (flagi.f_shirina - u_l < flagi.f_tochnost)
		i = flagi.f_shirina - u_l - flagi.f_tochnost - 1;
	while (i-- > 0)
		flagi.length = ft_putchar_fd_p(1, '0', flagi);
	return (flagi.length);
}

int	fpr_flg_p_fmin0(t_fpnt_list flagi, char *s, int u, int u_l)
{
	int	temp;

	flagi.length = fpr_flg_p_C1(flagi, u_l);
	if (flagi.f_tochnost > 0)
		flagi.length = fpr_flg_p_C3(flagi, u_l);
	temp = 0;
	if (flagi.f_tochnost > 0)
		flagi.length = fpr_flg_p_C4(flagi, u_l, &temp);
	if (u_l > 0 && temp == 0)
		flagi.length = ft_putchar_fd_p_0x(1, flagi);
	while (u_l > 0 && (!((flagi.toch_empty == 1
					|| flagi.f_tochnost == 0) && u == 0)))
	{
		flagi.length = ft_putchar_fd_p(1, *s, flagi);
		s++;
		u_l--;
	}
	if (flagi.f_tochnost > 0)
		flagi.length = fpr_flg_p_C5(flagi, u_l);
	return (flagi.length);
}
