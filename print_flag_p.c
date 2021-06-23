#include "ft_printf.h"

static int	fprint_flg_pprint(t_fpnt_list flagi, char *s, int u, int u_l)
{
	flagi.toch_empty = 0;
	if (flagi.f_tochnost == -2)
	{
		flagi.f_tochnost = -1;
		flagi.toch_empty = 1;
	}
	if (flagi.f_minus == 0)
		flagi.length = fpr_flg_p_fmin0(flagi, s, u, u_l);
	else
		flagi.length = fpr_flg_p_fmin1(flagi, s, u_l);
	return (flagi.length);
}

int	fprint_flag_p(t_fpnt_list flagi, va_list ap)
{
	unsigned long	p;
	char			*s;
	int				u_l;

	p = va_arg(ap, unsigned long);
	s = ft_itoa_base_x(p);
	if (s == NULL)
		return (-1);
	u_l = ft_strlen(s);
	flagi.length = fprint_flg_pprint(flagi, s, p, u_l);
	free(s);
	return (flagi.length);
}
