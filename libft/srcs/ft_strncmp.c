/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:35:23 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:19 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		result;
	size_t	len1;
	size_t	len2;

	result = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (s1 && s2)
	{
		if (n > len1)
			n = len1 + 1;
		if (n > len2)
			n = len2 + 1;
		result = ft_memcmp(s1, s2, n);
		FT_(result > 0, 1);
		FT_(result < 0, -1);
	}
	return (result);
}
