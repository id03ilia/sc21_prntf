#include "ft_printf.h"

t_fpnt_list	initial_list(t_fpnt_list flagi)
{
	flagi.f_shirina = 0;
	flagi.f_tochnost = -1;
	flagi.f_tip = 0;
	flagi.f_zero = 0;
	flagi.ii = 0;
	flagi.f_minus = 0;
	flagi.length = 0;
	return (flagi);
}
