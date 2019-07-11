/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:33:30 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/27 15:58:08 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	if (src)
		FT_(ft_strlen(src) < len, ft_memcpy(\
					ft_memset(dst, '\0', len), src, ft_strlen(src)));
	return (ft_memcpy(dst, src, len));
}
