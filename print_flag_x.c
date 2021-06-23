#include "ft_printf.h"

char	*ft_itoa_base_x(unsigned long u)
{
	char				*mem_str;
	unsigned long		t;
	int					len;

	len = 2;
	t = u;
	while (t >= 16)
	{
		t /= 16;
		len++;
	}
	mem_str = (char *)malloc(sizeof(char) * len);
	if (mem_str == NULL)
		return (NULL);
	mem_str[--len] = '\0';
	while (len--)
	{
		t = u % 16;
		if (t < 10)
			mem_str[len] = t + 48;
		else
			mem_str[len] = t + 87;
		u = u / 16;
	}
	return (mem_str);
}

static char	*ft_itoa_base_X(unsigned long u)
{
	char				*mem_str;
	unsigned long		t;
	int					len;

	len = 2;
	t = u;
	while (t >= 16)
	{
		t /= 16;
		len++;
	}
	mem_str = (char *)malloc(sizeof(char) * len);
	if (mem_str == NULL)
		return (NULL);
	mem_str[--len] = '\0';
	while (len--)
	{
		t = u % 16;
		if (t < 10)
			mem_str[len] = t + 48;
		else
			mem_str[len] = t + 55;
		u = u / 16;
	}
	return (mem_str);
}

int	fprint_flag_xX(t_fpnt_list flagi, va_list ap)
{
	char			*s;
	unsigned int	u;
	int				u_l;

	u = va_arg(ap, int);
	if (flagi.f_tip == 5)
		s = ft_itoa_base_x(u);
	else
		s = ft_itoa_base_X(u);
	if (s == NULL)
		return (-1);
	u_l = ft_strlen(s);
	flagi.length = fprint_flg_d_p2(flagi, s, u, u_l);
	free(s);
	return (flagi.length);
}
