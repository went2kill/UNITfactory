/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrobotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:32:58 by yrobotko          #+#    #+#             */
/*   Updated: 2016/12/08 19:15:08 by yrobotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
    long	num;
    char	*str;
    int		i;
    
    num = n;
    i = 0;
    if (n < 0)
        i = 1;
    while ((n > 9 || n < -9) && ++i)
        n /= 10;
    if (!(str = ft_strnew(i + 1)))
        return (NULL);
    if (num < 0)
    {
        str[0] = '-';
        num = -num;
    }
    while (str[i] != '-' && i >= 0)
    {
        str[i--] = '0' + num % 10;
        num /= 10;
    }
    return (str);
}
