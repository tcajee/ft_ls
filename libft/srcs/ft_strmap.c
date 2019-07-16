/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:19:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:05:19 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strmap(int func, ...)

ft_strmap(func, int (*f1)(int), int (*f2)(int), char (*f3)(int))
{
	va_list	v_list
	int *out;

	*out = 4;
	va_start(v_list, func);

	while (*out)
	va_arg()


	va_end(v_list);


}

char	*ft_strmap(char const *s, 
		char (*f)(char))
{
	char	*cursor;
	char	*new;
	size_t	len;

	new = NULL;
	if (s && f)
	{
		len = ft_strlen(s) + 1;
		FT_(!(new = (char *)malloc(sizeof(char) * len)), NULL);
		ft_memset((new + len), '\0', 1);
		cursor = new;
		while (*s)
			*cursor++ = f(*s++);
	}
	return (new);
}
