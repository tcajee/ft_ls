/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:36:21 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 15:07:50 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <errno.h>
# include <time.h>
# include <sys/acl.h>
# include <limits.h>

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

int					ft_ls(int argc, char** argv);
int					ft_parse_ls(int argc, char **argv);
int					ft_flags_ls(int i, char **argv);
int					ft_error_ls(int ERROR);

#endif
