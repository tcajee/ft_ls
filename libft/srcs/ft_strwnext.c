/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwnext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:35:35 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:20 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

const char	*ft_strwnext(const char *s, char c)
{
	if (s)
	{
		while (*s && *s == c)
			s++;
	}
	return (s);
}
