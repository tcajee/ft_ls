/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/29 13:18:05 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Within your mandatory part you are allowed to use the following functions: */
/* ◦ write */
/* ◦ opendir */
/* ◦ readdir */
/* ◦ closedir */
/* ◦ stat */
/* ◦ lstat */
/* ◦ getpwuid */
/* ◦ getgrgid */
/* ◦ listxattr */
/* ◦ getxattr */
/* ◦ time */
/* ◦ ctime */
/* ◦ readlink */
/* ◦ malloc */
/* ◦ free */
/* ◦ perror */
/* ◦ strerror */
/* ◦ exit */

/* You are allowed to use other functions to carry out the bonus part as long as their */
/* use is justified during your defence. For example, to use tcgetattr is justified in */
/* certain case, to use printf because you are lazy isn’t. Be smart! */

/* You must recode the system’s command ls. */

/* Its behavior must be identical to the original ls command with the following variations: */
/* ◦ Amongst the numerous options available, we are asking you to create the following: -l, -R, -a, -r and -t. */
/* ◦ We strongly recommend that you account for the implications of the option -R from the very beginning of your code... */
/* ◦ You do not have to deal with the multiple column format for the exit when the option -l isn’t in the arguments. */
/* ◦ You are not required to deal with ACL and extended attributes. */
/* ◦ The overall display, depending on each option, must stay as identical as possible to the system command. We will be cordial when grading either the padding or the pagination, but no information can be missing. */

/* man ls */
