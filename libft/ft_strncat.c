/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 09:01:34 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/28 13:48:10 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	offset;

	FT_(!s2, NULL);
	if (s1)
	{
		offset = ft_strlen(s1);
		if (ft_strlen(s2) < n)
			return (ft_memcpy(s1 + offset, s2, ft_strlen(s2) + 1) - offset);
		else
		{
			s1 = ft_memcpy(s1 + offset, s2, n) - offset;
			s1[offset + n] = '\0';
		}
	}
	return (s1);
}
