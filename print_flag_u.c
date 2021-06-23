#include "ft_printf.h"

int	fprint_flag_u(t_fpnt_list flagi, va_list ap)
{
	char			*s;
	unsigned int	u;
	int				u_l;

	u = va_arg(ap, unsigned int);
	u_l = ft_itoa_len_u(u);
	s = ft_itoa_u(u);
	if (s == NULL)
		return (-1);
	flagi.length = fprint_flg_d_p2(flagi, s, u, u_l);
	free(s);
	return (flagi.length);
}
