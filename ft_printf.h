/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:32:30 by dflorenc          #+#    #+#             */
/*   Updated: 2021/05/21 12:24:38 by dflorenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	int			f_minus;
	int			f_shirina;
	int			f_tochnost;
	int			f_tip;
	int			f_zero;
	int			length;
	int			ii;
	int			toch_empty;
}				t_fpnt_list;

int				ft_putchar_fd_p(int fd, unsigned char c, t_fpnt_list flagi);
int				ft_putchar_fd_p_0x(int fd, t_fpnt_list flagi);
int				ft_printf(const char *str, ...);
int				ft_strlen(const char *str);
int				ft_atoi(const char *str);
int				ft_itoa_len_u(unsigned int n);
char			*ft_itoa_u(unsigned int n);
char			*ft_itoa_di(int n);
int				ft_itoa_len_di(int n);
int				fprint_flag_c(t_fpnt_list flagi, va_list ap);//
int				fprint_flag_s(t_fpnt_list flagi, char *s);
int				fprint_flag_u(t_fpnt_list flagi, va_list ap);
int				fprint_flg_d_p2(t_fpnt_list flagi, char *s, int u, int u_l);
int				fprint_flg_d_p2_m(t_fpnt_list flagi, char *s, int u, int u_l);
int				fprint_flag_di(t_fpnt_list flagi, va_list ap);
char			*ft_itoa_base_x(unsigned long u);
int				fprint_flag_xX(t_fpnt_list flagi, va_list ap);
int				fpr_flg_p_fmin0(t_fpnt_list flagi, char *s, int u, int u_l);
int				fpr_flg_p_fmin1(t_fpnt_list flagi, char *s, int u_l);
int				fprint_flag_p(t_fpnt_list flagi, va_list ap);
t_fpnt_list		initial_list(t_fpnt_list flagi);
t_fpnt_list		a_flag(const char *st, t_fpnt_list flagi, int i, va_list ap);
int				ft_flag_print(va_list ap, t_fpnt_list flagi);
int				fpr_flg_d_A2(t_fpnt_list flagi, int u, int u_l);
int				fpr_flg_d_fmin0(t_fpnt_list flagi, char *s, int u, int u_l);
int				fpr_flg_d_fmin1(t_fpnt_list flagi, char *s, int u, int u_l);
int				fpr_f_mind_fmi0(t_fpnt_list flagi, char *s, int u, int u_l);
int				fpr_f_mind_fmi1(t_fpnt_list flagi, char *s, int u, int u_l);

#endif
