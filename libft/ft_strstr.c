/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:39:08 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/17 11:23:38 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	i = 0;
	FT_(needle[0] == '\0', ((char *)haystack));
	while (haystack[i])
	{
		FT_(haystack[i] == needle[0] && (ft_strncmp(&haystack[i], needle, \
						ft_strlen(needle))) == 0, ((char *)&haystack[i]));
		i++;
	}
	return (NULL);
}
