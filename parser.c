#include "ft_printf.h"

static t_fpnt_list	flg_min_f0(const char *st, t_fpnt_list flagi, int i)
{
	i++;
	flagi.ii = i;
	while (st[flagi.ii] == '-' || st[flagi.ii] == '0')
	{
		if (st[flagi.ii] == '-')
		{
			flagi.f_minus++;
			i++;
		}
		else if (st[flagi.ii] == '0')
		{
			flagi.f_zero = 1;
			i++;
		}
		flagi.ii++;
	}
	flagi.ii = i;
	return (flagi);
}

static int	a_flag_shirina_minus(t_fpnt_list flagi)
{
	if (flagi.f_shirina < 0)
		flagi.f_shirina = flagi.f_shirina * -1;
	return (flagi.f_shirina);
}

static t_fpnt_list	flg_shi(const char *st, t_fpnt_list flagi, va_list ap)
{
	if (st[flagi.ii] == '*')
	{
		flagi.f_shirina = va_arg(ap, int);
		if (flagi.f_shirina < 0)
			flagi.f_minus = 1;
		flagi.f_shirina = a_flag_shirina_minus(flagi);
		while (st[flagi.ii] == '*')
			flagi.ii++;
	}
	if ((st[flagi.ii] >= '0') && (st[flagi.ii] <= '9'))
	{
		flagi.f_shirina = ft_atoi(&st[flagi.ii]);
		while ((st[flagi.ii] >= '0') && (st[flagi.ii] <= '9'))
		{
			flagi.ii++;
			if (st[flagi.ii] == '*')
			{
				flagi.f_shirina = va_arg(ap, int);
				flagi.f_shirina = a_flag_shirina_minus(flagi);
				while (st[flagi.ii] == '*')
					flagi.ii++;
			}
		}
	}
	return (flagi);
}

static t_fpnt_list	flg_tch(const char *st, t_fpnt_list flagi, va_list ap)
{
	int	precision;

	if (st[flagi.ii] == '.')
	{
		flagi.ii++;
		if ((st[flagi.ii] >= '0') && (st[flagi.ii] <= '9'))
		{
			flagi.f_tochnost = ft_atoi(&st[flagi.ii]);
			while ((st[flagi.ii] >= '0') && (st[flagi.ii] <= '9'))
				flagi.ii++;
		}
		else if (st[flagi.ii] == '*')
		{
			precision = va_arg(ap, int);
			if (precision >= 0)
				flagi.f_tochnost = precision;
			else
				flagi.f_tochnost = -1;
			while (st[flagi.ii] == '*')
				flagi.ii++;
		}
		else
			flagi.f_tochnost = -2;
	}
	return (flagi);
}

t_fpnt_list	a_flag(const char *st, t_fpnt_list flagi, int i, va_list ap)
{
	flagi = initial_list(flagi);
	flagi = flg_min_f0(st, flagi, i);
	flagi = flg_shi(st, flagi, ap);
	flagi = flg_tch(st, flagi, ap);
	if (st[flagi.ii] == 'c')
		flagi.f_tip = 1;
	else if (st[flagi.ii] == 's')
		flagi.f_tip = 2;
	else if (st[flagi.ii] == '%')
		flagi.f_tip = 3;
	else if (st[flagi.ii] == 'u')
		flagi.f_tip = 4;
	else if (st[flagi.ii] == 'x')
		flagi.f_tip = 5;
	else if (st[flagi.ii] == 'X')
		flagi.f_tip = 6;
	else if (st[flagi.ii] == 'p')
		flagi.f_tip = 7;
	else if ((st[flagi.ii] == 'd') || (st[flagi.ii] == 'i'))
		flagi.f_tip = 8;
	else
		flagi.f_tip = -1;
	flagi.ii++;
	return (flagi);
}
