/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:34:12 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:19 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;

	new = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		FT_(!(new = (char *)malloc(sizeof(char) * len)), NULL);
		ft_memset((new + len), '\0', 1);
		new = ft_strcat(ft_strcat(new, s1), s2);
	}
	return (new);
}
