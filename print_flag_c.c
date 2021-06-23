#include "ft_printf.h"

int	fprint_flag_c(t_fpnt_list flagi, va_list ap)
{
	char	c;

	if (flagi.f_shirina > 0 && (flagi.f_minus == 0 || flagi.f_minus > 1))
	{
		while (--flagi.f_shirina > 0)
			flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	}
	c = va_arg(ap, int);
	flagi.length = ft_putchar_fd_p(1, c, flagi);
	if (flagi.f_shirina > 0 && (flagi.f_minus == 1))
	{
		while (--flagi.f_shirina > 0)
			flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	}
	return (flagi.length);
}
