/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:53:05 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/27 16:29:34 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	new = NULL;
	if (s)
	{
		i = -1;
		FT_(!(new = ft_strnew(len)), NULL);
		while (++i < len && s[i])
			new[i] = s[start + i];
	}
	return (new);
}
