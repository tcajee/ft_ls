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
	FT_(!src && !dst, NULL);
	return (ft_memcpy(dst, src, ft_strlen(src) + 1));
}
