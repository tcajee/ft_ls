/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:53:05 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:20 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t n)
{
	char	*new;
	size_t	i;

	new = NULL;
	if (s)
	{
		i = -1;
		FT_(!(new = (char *)malloc(sizeof(char) * n + 1)), NULL);
		ft_memset((new + (n + 1)), '\0', 1);
		while (++i < n && s[i])
			new[i] = s[start + i];
	}
	return (new);
}
