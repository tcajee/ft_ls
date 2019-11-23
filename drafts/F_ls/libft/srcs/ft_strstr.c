/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:39:08 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 09:43:36 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strstr(const char *hstack, const char *needle)
{
	int i;

	i = -1;
	F_(!*needle, ((char *)hstack));
	___(hstack[++i], F_(hstack[i] == *needle &&
	!ft_strncmp(&hstack[i], needle, ft_strlen(needle)), ((char *)&hstack[i])));
	return (NULL);
}
