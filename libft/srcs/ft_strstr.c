/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:39:08 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:19 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strstr(const char *hstack, const char *needle)
{
	int i;

	i = -1;
	FT_(!*needle, ((char *)hstack));
	while (hstack[++i])
		FT_(hstack[i] == *needle && !ft_strncmp
				(&hstack[i], needle, ft_strlen(needle)), ((char *)&hstack[i]));
	return (NULL);
}
