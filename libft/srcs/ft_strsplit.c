/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 12:28:11 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:19 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char		**array;
	char		**insert;
	const char	*start;
	size_t		len;
	size_t		words;

	array = NULL;
	if (s)
	{
		words = ft_strwcount(s, c);
		FT_(!(array = (char **)malloc(words * sizeof(char *) + 1)), NULL);
		insert = array;
		while (words-- > 0)
		{
			start = ft_strwnext(s, c);
			len = ft_strwlen(start, c);
			FT_(!(*insert++ = ft_strsub(start, 0, len)), NULL);
			s = (start + len);
		}
		*insert = NULL;
	}
	return (array);
}
