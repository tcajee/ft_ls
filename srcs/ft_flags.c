/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:11:56 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/22 16:27:48 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

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



void	ft_add_flags(char flag, t_flags *flags)
{
	printf("adding flags\n");
	char *temp;
	char *temp2;

	temp = ft_strnew(1);
	temp[0] = flag;
	temp2 = flags->flags;
	flags->flags = ft_strjoin(temp2, temp);
	free(temp);
	free(temp2);
}

void	ft_check_flags(char flag, t_flags *flags)
{
	printf("checking flags\n");
	if (ft_strchr(flags->vflags, flag))
	{
		printf("vflag\n");
		if (!ft_strchr(flags->flags, flag))
			ft_add_flags(flag, flags);
	}
	else
	{
		printf("vflag\n");
		return ;
	}
}

void	ft_set_flags(char *arg, t_flags *flags)
{
	size_t i = 0;
	size_t len = ft_strlen(arg);

	if (len > 1)
		FT_((arg[0] == '-' && arg[1] == '-') && arg[2],);
	while (arg[++i] && i < len)
	{
		printf("arg[%zu]\n", i);
		if (arg[i] == 'R')
			ft_check_flags(arg[i], flags);
		else if (arg[i] == 'R')
			ft_check_flags(arg[i], flags);
		else if (arg[i] == 'a')
			ft_check_flags(arg[i], flags);
		else if (arg[i] == 'r')
			ft_check_flags(arg[i], flags);
		else if (arg[i] == 't')
			ft_check_flags(arg[i], flags);
		else if (arg[i] == 'u')
			ft_check_flags(arg[i], flags);
		else if (arg[i] == 'f')
			ft_check_flags(arg[i], flags);
		else if (arg[i] == 'g')
			ft_check_flags(arg[i], flags);
		else if (arg[i] == 'd')
			ft_check_flags(arg[i], flags);
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
			break;
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
			break ;
	}
	printf("%s\n", flags->flags);
	return (i);
}
