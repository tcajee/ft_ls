/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/24 15:54:05 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

void	ft_print_flags(unsigned char c)
{
	size_t i;

	i = 32;
	while (i--)
	{
		ft_putnbr(c >> i & 1);
		if (i % 8 == 0 && i != 32)
			ft_putchar(' ');
	}
}

void	ft_check_flags(size_t flag, t_flags *flags)
{
	printf("checking flags\n");
	if (!(*flags & flag))
			*flags |= flag;
	printf("FLAGS: \n");
	ft_print_flags(*flags);
	printf("\n");
}

void	ft_set_flags(char *arg, t_flags *flags)
{
	size_t i = 0;
	size_t len = ft_strlen(arg);

	if (len > 1)
		FT_((arg[0] == '-' && arg[1] == '-') && arg[2],);
	while (arg[++i] && i < len)
	{
		printf("arg[%zu]: %c\n", i, arg[i]);
		if (arg[i] == 'l')
			ft_check_flags(F_L, flags);
		else if (arg[i] == 'R')
			ft_check_flags(F_R, flags);
		else if (arg[i] == 'a')
			ft_check_flags(F_A, flags);
		else if (arg[i] == 'r')
			ft_check_flags(F_r, flags);
		else if (arg[i] == 't')
			ft_check_flags(F_T, flags);
		else if (arg[i] == 'u')
			ft_check_flags(F_U, flags);
		else if (arg[i] == 'f')
			ft_check_flags(F_F, flags);
		else if (arg[i] == 'g')
			ft_check_flags(F_G, flags);
		else if (arg[i] == 'd')
			ft_check_flags(F_D, flags);
		else
		{
			ft_errors(99);
			break ;
		}
	}
}

int	ft_flags(char **argv, t_flags *flags)
{
	int i;

	i = 0;
	while (argv[++i])
	{
		printf("argv[%d]\n", i);
		if (argv[i][0] != '-')
		{
			printf("NO -\n");
			return (0);
		}
		else if (!ft_strcmp(argv[i], "--"))
		{
			printf("found --\n");
			break ;
		}
		else if (argv[i][0] == '-' && argv[i][1])
		{
			printf("setting flags\n");
			ft_set_flags(argv[i], flags);
		}
		else
		{
			ft_errors(99);
			perror("FLAG ERROR");
			break ;
		}
	}
	return (i);
}
/* int	ft_flags(char **argv, t_flags *flags) */
/* { */
/* 	int parse; */
/* 	parse = 0; */
/* 	while (argv[i][parse]) */
/* 	{ */
/* 	/1* return (ft_strdup(flags)); *1/ */
/* 	return (0); */
/* } */

/* void long_option_flag(char *option, t_flags *flags) { */
/*   if (ft_strequ(option, "help")) */
/*     return ; */
/* 	  help_handler(); */
/*   else if (ft_strequ(option, "recursive")) */
/*     *flags |= RECURSIVE_FLAG; */
/*   else if (ft_strequ(option, "all")) */
/*     *flags |= ALL_FLAG; */
/*   else if (ft_strequ(option, "reverse")) */
/*     *flags |= REVERSE_FLAG; */
/*   else { */
/*     return ; */
/* 	  error_handler(FLAG_ERR, target); */
/*   } */
/* } */

/* void display_flag_handler(t_flags *flags, char f) */
/* { */
/*   if (f == '1') */
/*   { */
/*     if (*flags & COLUMN_DISPLAY) */
/*       *flags &= ~COLUMN_DISPLAY; */
/*     if (*flags & LONG_LISTING_FLAG) */
/*       *flags &= ~LONG_LISTING_FLAG; */
/*     *flags |= ONE_ENTRY_PER_LINE; */
/*   } */
/*   else if (f == 'l' || f == 'g') */
/*   { */
/*     if (f == 'g') */
/*       *flags |= SUPRESS_OWNER; */
/*     if (*flags & COLUMN_DISPLAY) */
/*       *flags &= ~COLUMN_DISPLAY; */
/*     if (*flags & ONE_ENTRY_PER_LINE) */
/*       *flags &= ~ONE_ENTRY_PER_LINE; */
/*     *flags |= LONG_LISTING_FLAG; */
/*   } */
/*   else */
/*   { */
/*     if (*flags & ONE_ENTRY_PER_LINE) */
/*       *flags &= ~ONE_ENTRY_PER_LINE; */
/*     if (*flags & LONG_LISTING_FLAG) */
/*       *flags &= ~LONG_LISTING_FLAG; */
/*     *flags |= COLUMN_DISPLAY; */
/*   } */
/* } */

/* void sort_flag_handler(t_flags *flags, char f) */
/* { */
/*   printf("flags sfh: %d\n", *flags); */
/*   if (f == 't' && !(*flags & FILE_SIZE_SORT)) */
/*   { */
/*     *flags |= MODIFICATION_DATE_SORT; */
/*   	/1* printf("flags column: %d\n", *flags); *1/ */
/*   } */
/*   else if (f == 'U') */
/*   { */
/*     if (*flags & LAST_ACCESS_DATE_SORT) */
/* 	{ */
/*       *flags &= ~LAST_ACCESS_DATE_SORT; */
/*   		printf("flags U: %d\n", *flags); */
/* 	} */
/*     if (*flags & LAST_STATUS_CHANGE_SORT) */
/*       *flags &= ~LAST_STATUS_CHANGE_SORT; */
/*     *flags |= CREATION_DATE_SORT; */
/*   } */
/*   else if (f == 'u') */
/*   { */
/*     if (*flags & CREATION_DATE_SORT) */
/* 	{ */
/* 		*flags &= ~CREATION_DATE_SORT; */
/*   		printf("flags u: %d\n", *flags); */
/* 	} */   
/*     if (*flags & LAST_STATUS_CHANGE_SORT) */
/*       *flags &= ~LAST_STATUS_CHANGE_SORT; */
/*     *flags |= LAST_ACCESS_DATE_SORT; */
/*   } */
/*   else if (f == 'c') */
/*   { */
/*     if (*flags & CREATION_DATE_SORT) */
/*       *flags &= ~CREATION_DATE_SORT; */
/*     if (*flags & LAST_ACCESS_DATE_SORT) */
/*       *flags &= ~LAST_ACCESS_DATE_SORT; */
/*     *flags |= LAST_STATUS_CHANGE_SORT; */
/*   } */
/*   else */
/*   {gg */
/*     if (*flags & MODIFICATION_DATE_SORT) */
/*       *flags &= ~MODIFICATION_DATE_SORT; */
/*     *flags |= FILE_SIZE_SORT; */
/*   } */
/* } */
/* } */



