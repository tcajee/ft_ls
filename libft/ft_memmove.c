/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 11:21:02 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/27 16:16:09 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_h;
	unsigned char	*src_h;

	if (src && dst)
	{
		i = -1;
		dst_h = (unsigned char *)dst;
		src_h = (unsigned char *)src;
		if (dst_h < src_h)
		{
			while (++i < len)
				dst_h[i] = src_h[i];
		}
		else if (dst_h > src_h)
		{
			while (len-- > 0)
				dst_h[len] = src_h[len];
		}
	}
	return (dst);
}
