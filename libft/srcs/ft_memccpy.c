/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:13:32 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:18 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_h;

	if (src && dst)
	{
		i = -1;
		dst_h = (unsigned char *)dst;
		while (++i < n)
		{
			dst_h[i] = *((unsigned char *)src + i);
			FT_((*((unsigned char *)src + i) == (unsigned char)c), &dst_h[++i]);
		}
	}
	return (NULL);
}
