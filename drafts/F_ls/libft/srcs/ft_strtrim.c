/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:03:32 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 09:43:36 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strtrim(char const *s)
{
	const char	*start;
	const char	*end;
	char		*new;
	size_t		len;

	new = NULL;
	if (s)
	{
		len = 0;
		end = (s + (ft_strlen(s)));
		___(ft_isspace(*s) && *s, s++);
		start = s;
		___(ft_isspace(*(end - 1)) && end != s, end--);
		___(s++ != end, len++);
		F_(!(new = ft_strsub(start, 0, len)), NULL);
	}
	return (new);
}
