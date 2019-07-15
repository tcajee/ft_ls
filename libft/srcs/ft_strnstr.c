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

char	*ft_strnstr(const char *hstack, const char *needle, size_t len)
{
	size_t		minsize;
	const char	*_;

	minsize = ft_strlen(needle);
	_ = hstack;
	FT_(minsize == 0, ((char *)hstack));
	while (*_ && (_ + minsize) <= (hstack + len))
	{
		FT_(*_ == *needle && !ft_strncmp(_, needle, minsize), (char *)_);
		_++;
	}
	return (NULL);
}
