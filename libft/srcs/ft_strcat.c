/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:56:49 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:18 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	FT_(!s2, NULL);
	if (s1)
		ft_strcpy(s1 + ft_strlen(s1), s2);
	return (s1);
}
