/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrobotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 18:41:24 by yrobotko          #+#    #+#             */
/*   Updated: 2017/08/14 16:34:50 by yrobotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>
# include <wchar.h>
# include <stdarg.h>

typedef struct			s_print
{
	char				*flags;
	int					width;
	int					precision;
	int					size;
	char				convers;
	int					prec_fl;
	int					star;
}						t_print;

typedef struct			s_print_list
{
	t_print				*lst;
	struct s_print_list	*next;
}						t_print_list;
char					*newstr(int n, char s);
t_print					*new_struc();
t_print_list			*new_struc_list();
char					*up_or(int up);
char					*ft_itoa_base(uintmax_t value, int base, int up);
char					*ft_uitoa(uintmax_t value);
int						parse_star(char *str);
int						print_some(char **str);
void					pass_some(char **str);
char					is_convers(char c, char *str);
void					pass_this(char **str);
char					*parse_flags(char *str);
int						parse_width(char *str);
int						parse_precision(char *str, t_print **l);
int						parse_size(char *str);
char					parse_convers(char *str);
t_print					*do_parse(char **str);
t_print_list			*parse_this(char **str);
int						app_flags_ddi(int size, char *strn, char l,
		t_print *ls);
int app_flags_ddi2(int size,char *strn, char l, t_print* ls, int size1);
int						apply_w_p_ddi(t_print *lst, char *strnum, char lb);
int						next_step_for_ddi(t_print *list, va_list ptr);
int						app_flags_uu(int size, char *strn, t_print *ls);
int						apply_w_p_uu(t_print *lst, char *strnum);
int						next_step_for_uu(t_print *list, va_list ptr);
void					ft_putstr_my(char *str, size_t num, char st);
int						app_flags_cc(int size, char *strn, t_print *ls,
		char st);
int						apply_w_p_cc(t_print *lst, char st);
int						next_step_for_cc(t_print *list, va_list ptr);
int						wchar_strlen(wchar_t *s);
char					*make_norm_str(wchar_t *str);
int						app_flags_ss(int size, char *strn, t_print *ls);
int						apply_w_p_ss(t_print *lst, char *st);
int						next_step_for_ss(t_print *list, va_list ptr);
int						app_flags_oo(int size, char *strn, t_print *ls);
int						apply_w_p_oo(t_print *lst, char *strnum);
int						next_step_for_oo(t_print *list, va_list ptr);
int						app_flags_xx(int size, char *strn, t_print *ls);
int						apply_w_p_xx(t_print *lst, char *strnum);
int						next_step_for_x(t_print *list, va_list ptr);
int						next_step_for_xx(t_print *list, va_list ptr);
int						app_flags_p(int size, char *strn, t_print *ls);
int						next_step_for_p(t_print *list, va_list ptr);
int						next_step_for_p2(t_print *list, va_list ptr,
		char *str, int sn);
int						print_param(t_print *list, va_list ptr);
int						ft_printf(char *tmp_format, ...);

#endif
