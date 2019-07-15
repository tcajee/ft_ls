/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:58:02 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:19 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		minsize;
	const char	*cursor;

	minsize = ft_strlen(needle);
	cursor = haystack;
	FT_(minsize == 0, ((char *)haystack));
	while (*cursor && (cursor + minsize) <= (haystack + len))
	{
		FT_(*cursor == *needle && \
				ft_strncmp(cursor, needle, minsize) == 0, (char *)cursor);
		cursor++;
	}
	return (NULL);
}
