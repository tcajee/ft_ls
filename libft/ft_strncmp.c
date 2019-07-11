/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:35:23 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/27 16:38:58 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		result;

	result = 0;
	if (s1 && s2)
	{
		if (n > ft_strlen(s1))
			n = ft_strlen(s1) + 1;
		if (n > ft_strlen(s2))
			n = ft_strlen(s2) + 1;
		result = ft_memcmp(s1, s2, n);
		FT_(result > 0, 1);
		FT_(result < 0, -1);
	}
	return (result);
}
