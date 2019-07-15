/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 12:04:43 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:19 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (s)
	{
		i = ft_strlen(s);
		while (i >= 0)
		{
			FT_(s[i] == (char)c, ((char *)&s[i]));
			i--;
		}
	}
	return (NULL);
}
