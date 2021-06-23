#include "ft_printf.h"

static int	ft_putstr_tochnst_s(char *s, int fd, t_fpnt_list flagi)
{
	int	i;

	i = ft_strlen(s);
	if (s)
	{
		if (flagi.f_tochnost < i && flagi.f_tochnost > -1)
		{
			while (flagi.f_tochnost > 0)
			{
				flagi.length = ft_putchar_fd_p(fd, *s, flagi);
				s++;
				flagi.f_tochnost--;
			}
		}
		else
		{
			if (flagi.f_tochnost == -2)
				return (flagi.length);
			else
				while (*s)
					flagi.length = ft_putchar_fd_p(fd, *s++, flagi);
		}
	}
	return (flagi.length);
}

static int	fprint_flag_s_part2(t_fpnt_list flagi, int ls)
{
	int	i;

	if (flagi.f_tochnost == -2)
		i = flagi.f_shirina;
	else
		i =flagi.f_shirina - (ls - (ls - flagi.f_tochnost));
	if (flagi.f_zero == 1)
		while (i-- > 0)
			flagi.length = ft_putchar_fd_p(1, '0', flagi);
	if (flagi.f_zero == 0)
		while (i-- > 0)
			flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	return (flagi.length);
}

static int	fprint_flag_s_part3(t_fpnt_list flagi, int ls)
{
	int	i;

	if (flagi.f_tochnost == -2)
		i = flagi.f_shirina;
	else
		i =flagi.f_shirina - (ls - (ls - flagi.f_tochnost));
	if (flagi.f_zero == 1)
		while (i-- > 0)
			flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	if (flagi.f_zero == 0)
		while (i-- > 0)
			flagi.length = ft_putchar_fd_p(1, ' ', flagi);
	return (flagi.length);
}

int	fprint_flag_s(t_fpnt_list flagi, char *s)
{
	int	ls;

	if (flagi.f_shirina > 0 && (flagi.f_tochnost == -2 || flagi.f_tochnost == 0)
		&& s == NULL)
	{
		s = "";
		flagi.f_tochnost = 0;
	}
	if (s == NULL)
		s = "(null)";
	ls = ft_strlen(s);
	if (flagi.f_tochnost > ls || flagi.f_tochnost == -1)
		flagi.f_tochnost = ls;
	if (flagi.f_shirina > 0 && (flagi.f_minus == 0))
		flagi.length =fprint_flag_s_part2(flagi, ls);
	flagi.length = ft_putstr_tochnst_s(s, 1, flagi);
	if (flagi.f_shirina > 0 && (flagi.f_minus == 1))
		flagi.length = fprint_flag_s_part3(flagi, ls);
	return (flagi.length);
}
