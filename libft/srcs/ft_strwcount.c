/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:34:04 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:20 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

size_t	ft_strwcount(const char *s, int c)
{
	size_t	words;

	words = 0;
	if (s)
	{
		while (*s)
		{
			while (*s && *s == c)
				s++;
			if (*s && *s != c)
				words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}
