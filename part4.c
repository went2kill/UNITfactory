/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrobotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 16:08:19 by yrobotko          #+#    #+#             */
/*   Updated: 2017/08/13 16:08:26 by yrobotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     parse_star(char *str)
{
  while (!is_convers(*str, "sSpdDioOuUxXcC"))
    {
      if (*str == '*')
	exit(0);
      str++;
    }
  return 0;
}
