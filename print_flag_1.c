#include "ft_printf.h"

int	ft_flag_print(va_list ap, t_fpnt_list flagi)
{
	if (flagi.f_tip == 1)
		flagi.length = fprint_flag_c(flagi, ap);
	if (flagi.f_tip == 2)
		flagi.length = fprint_flag_s(flagi, va_arg(ap, char *));
	if (flagi.f_tip == 4)
		flagi.length = fprint_flag_u(flagi, ap);
	if (flagi.f_tip == 5)
		flagi.length = fprint_flag_xX(flagi, ap);
	if (flagi.f_tip == 6)
		flagi.length = fprint_flag_xX(flagi, ap);
	if (flagi.f_tip == 7)
		flagi.length = fprint_flag_p(flagi, ap);
	if (flagi.f_tip == 8)
		flagi.length = fprint_flag_di(flagi, ap);
	if (flagi.f_tip == 3)
		flagi.length = fprint_flag_s(flagi, "%");
	if (flagi.f_tip == -1)
		flagi.length = -1;
	return (flagi.length);
}
