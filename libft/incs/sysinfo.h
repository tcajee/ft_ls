/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sysinfo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 08:55:00 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/29 12:25:40 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSINFO_H
# define SYSINFO_H

// {{{	DEFINITIONS

#ifndef S_ISREG
#ifndef S_IFREG
#ifndef _S_IFREG
#define S_IFREG		(-1)
#else
#define S_IFREG		_S_IFREG
#endif
#endif
#define S_ISREG(m)	(((m)&S_IFREG)==S_IFREG)
#endif

#ifndef S_ISBLK
#ifndef S_IFBLK
#ifndef _S_IFBLK
#define S_IFBLK		(-1)
#else
#define S_IFBLK		_S_IFBLK
#endif
#endif
#define S_ISBLK(m)	(((m)&S_IFBLK)==S_IFBLK)
#endif

#ifndef S_ISCHR
#ifndef S_IFCHR
#ifndef _S_IFCHR
#define S_IFCHR		(-1)
#else
#define S_IFCHR		_S_IFCHR
#endif
#endif
#define S_ISCHR(m)	(((m)&S_IFCHR)==S_IFCHR)
#endif

#ifndef S_ISDIR
#ifndef S_IFDIR
#ifndef _S_IFDIR
#define S_IFDIR		(-1)
#else
#define S_IFDIR		_S_IFDIR
#endif
#endif
#define S_ISDIR(m)	(((m)&S_IFDIR)==S_IFDIR)
#endif

#ifndef S_ISFIFO
#ifndef S_IFIFO
#ifndef _S_IFIFO
#define S_IFIFO		(-1)
#else
#define S_IFIFO		_S_IFIFO
#endif
#endif
#define S_ISFIFO(m)	(((m)&S_IFIFO)==S_IFIFO)
#endif

#ifndef S_ISSUID
#ifndef S_ISUID
#ifndef _S_ISUID
#define S_ISUID		(-1)
#else
#define S_ISUID		_S_ISUID
#endif
#endif
#define S_ISSUID(m)	(((m)&S_ISUID)==S_ISUID)
#endif

#ifndef S_ISSGID
#ifndef S_ISGID
#ifndef _S_ISGID
#define S_ISGID		(-1)
#else
#define S_ISGID		_S_ISGID
#endif
#endif
#define S_ISSGID(m)	(((m)&S_ISGID)==S_ISGID)
#endif

#ifndef S_IRUSR
#define S_IRUSR		0x0100
#endif
#ifndef S_IWUSR
#define S_IWUSR		0x0080
#endif
#ifndef S_IXUSR
#define S_IXUSR		0x0040
#endif
#ifndef S_IRGRP
#define S_IRGRP		0x0020
#endif
#ifndef S_IWGRP
#define S_IWGRP		0x0010
#endif
#ifndef S_IXGRP
#define S_IXGRP		0x0008
#endif
#ifndef S_IROTH
#define S_IROTH		0x0004
#endif
#ifndef S_IWOTH
#define S_IWOTH		0x0002
#endif
#ifndef S_IXOTH
#define S_IXOTH		0x0001
#endif


 //}}}



void	ft_print_stat(void);
void	ft_print_dirent(void);
void	ft_print_passwd(void);
void	ft_print_group(void);
char	*filemode(int mode);
char	*getuname(int uid);
char	*getgname(int gid);
char	*dirname(char *fname, char *buf);
void	ft_prints(char *fname, struct stat *buf);

#endif

