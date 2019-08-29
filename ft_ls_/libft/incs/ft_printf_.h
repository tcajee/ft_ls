/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:04:29 by sminnaar          #+#    #+#             */
/*   Updated: 2019/08/29 14:49:38 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#ifndef FT_PRINTF_H
//# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

void	ft_printf_(char *format, ...);
int		ft_spec(char *spec, va_list list);
void	ft_slash(char id);
char	*ft_width(char width, va_list list);
void	ft_d(int width, va_list list);
void	ft_l(int width, va_list list);
void	ft_s(int width, va_list list);
void	ft_x(int width, va_list list);
