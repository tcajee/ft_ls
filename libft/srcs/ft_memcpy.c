/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:54:04 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:18 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_h;
	char	*src_h;

	FT_(!src, NULL);
	if (dst)
	{
		i = -1;
		dst_h = (char *)dst;
		src_h = (char *)src;
		while (++i < n && (dst || src))
			dst_h[i] = src_h[i];
	}
	return (dst);
}
