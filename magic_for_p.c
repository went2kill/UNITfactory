/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_for_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrobotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 18:49:35 by yrobotko          #+#    #+#             */
/*   Updated: 2017/08/14 16:30:00 by yrobotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			app_flags_p(int size, char *strn, t_print *ls)
{
	int		size1;
	char	*fl;

	size1 = (int)ft_strlen(strn);
	if (ls->flags[0] == '1')
	{
		if (size < size1)
			strn = ft_strjoin(&strn[size1 - size], newstr(size1 - size, ' '));
	}
	if (ls->flags[2] == '1' && ls->flags[0] != '1')
	{
		size1 = 0;
		if (ls->prec_fl == 0)
			while (!ft_isdigit(strn[size1]))
				strn[size1++] = '0';
	}
	ft_putstr(strn);
	return ((int)ft_strlen(strn));
}

int			next_step_for_p(t_print *list, va_list ptr)
{
	char	*str;
	int		size_n;
	int		size2;

	str = ft_itoa_base(va_arg(ptr, unsigned long int), 16, 0);
	if (list->precision == 0 && list->prec_fl == 1 && *str == '0' && *(str + 1) == '\0')
	{
		ft_putstr("0x");
		return (2);
	}
	size_n = (int)ft_strlen(str);
	if (list->precision > size_n)
		str = ft_strjoin(newstr(list->precision - size_n, '0'), str);
	size_n = (int)ft_strlen(str);
	if (list->width > size_n)
		str = ft_strjoin(newstr(list->width - size_n, ' '), str);
    next_step_for_p2(list, ptr, size_n, size2);
}

int			next_step_for_p2(t_print *list, va_list ptr, char *str, int snn, int s2)
{
    if (size_n < list->width || size_n < list->precision)
    {
        size2 = 0;
        while (!ft_isdigit(str[size2]))
            size2++;
        str[--size2] = 'x';
        if (size2 == 0)
            str = ft_strjoin("0", str);
        else
            str[--size2] = '0';
    }
    else
        str = ft_strjoin("0x", str);
    size_n += 2;
    return (app_flags_p(size_n, str, list));
}
