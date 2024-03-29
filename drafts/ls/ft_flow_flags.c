/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flow_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:11:08 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/26 14:12:18 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void long_option_flag(char *option, t_flags *flags) {
  if (ft_strequ(option, "help"))
    return ;
	  help_handler();
  else if (ft_strequ(option, "recursive"))
    *flags |= RECURSIVE_FLAG;
  else if (ft_strequ(option, "all"))
    *flags |= ALL_FLAG;
  else if (ft_strequ(option, "reverse"))
    *flags |= REVERSE_FLAG;
  else {
    return ;
	  error_handler(FLAG_ERR, target);
  }
}

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



