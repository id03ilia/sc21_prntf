#include "ft_printf.h"

int	fprint_flg_d_p2(t_fpnt_list flagi, char *s, int u, int u_l)
{
	flagi.toch_empty = 0;
	if (flagi.f_tochnost == -2)
	{
		flagi.f_tochnost = -1;
		flagi.toch_empty = 1;
	}
	if (flagi.f_minus == 0)
		flagi.length = fpr_flg_d_fmin0(flagi, s, u, u_l);
	else
		flagi.length = fpr_flg_d_fmin1(flagi, s, u, u_l);
	return (flagi.length);
}

int	fprint_flg_d_p2_m(t_fpnt_list flagi, char *s, int u, int u_l)
{
	flagi.toch_empty = 0;
	if (flagi.f_tochnost == -2)
	{
		flagi.f_tochnost = -1;
		flagi.toch_empty = 1;
	}
	if (flagi.f_minus == 0)
		flagi.length = fpr_f_mind_fmi0(flagi, s, u, u_l);
	else
		flagi.length = fpr_f_mind_fmi1(flagi, s, u, u_l);
	return (flagi.length);
}

static int	flag_di_otrizat(int *di, int otrizatelnoe)
{
	if (*di < 0)
	{
		otrizatelnoe = 1;
		*di = *di * -1;
	}
	else
		otrizatelnoe = 0;
	return (otrizatelnoe);
}

int	fprint_flag_di(t_fpnt_list flagi, va_list ap)
{
	char	*s;
	int		di;
	int		di_l;
	int		otrizatelnoe;

	di = va_arg(ap, int);
	if (di == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	otrizatelnoe = 0;
	otrizatelnoe = flag_di_otrizat(&di, otrizatelnoe);
	di_l = ft_itoa_len_di(di);
	s = ft_itoa_di(di);
	if (s == NULL)
		return (-1);
	if (otrizatelnoe == 1)
		flagi.length = fprint_flg_d_p2_m(flagi, s, di, di_l);
	else
		flagi.length = fprint_flg_d_p2(flagi, s, di, di_l);
	free(s);
	return (flagi.length);
}
