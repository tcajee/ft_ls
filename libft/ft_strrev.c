/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:09:55 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/13 14:50:40 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char temp;
	char *end;
	char *start;

	if (s)
	{
		start = s;
		end = (s + (ft_strlen(s) - 1));
		while (start < end)
		{
			temp = *start;
			*start++ = *end;
			*end-- = temp;
		}
	}
	return (s);
}
