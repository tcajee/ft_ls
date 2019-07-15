/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 09:55:21 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:19 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*cursor;
	char	*new;
	size_t	len;
	size_t	i;

	new = NULL;
	if (s && f)
	{
		i = 0;
		len = ft_strlen(s) + 1;
		FT_(!(new = (char *)malloc(sizeof(char) * len)), NULL);
		ft_memset((new + len), '\0', 1);
		cursor = new;
		while (*s)
			*cursor++ = f(i++, *s++);
	}
	return (new);
}
