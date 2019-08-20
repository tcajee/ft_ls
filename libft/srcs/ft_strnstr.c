/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:58:02 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 09:43:36 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strnstr(const char *hstack, const char *needle, size_t len)
{
	size_t		minsize;
	const char	*c;

	minsize = ft_strlen(needle);
	c = hstack;
	F_(minsize == 0, ((char *)hstack));
	while (*c && (c + minsize) <= (hstack + len))
	{
		F_(*c == *needle && !ft_strncmp(c, needle, minsize), (char *)c);
		c++;
	}
	return (NULL);
}
