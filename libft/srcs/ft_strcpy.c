/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:31:04 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:19 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strcpy(char *dst, const char *src)
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
		while (src_h[++i])
			dst_h[i] = src_h[i];
	}
	return (dst);
}
