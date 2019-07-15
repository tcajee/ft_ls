/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:13:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/07/15 11:00:21 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int main(int argc, char **argv)
{
	struct stat fstat;

	FT_((argc != 2), 1);
	FT_((stat(argv[1], &fstat) < 0), 1);

	printf("Information for %s\n", argv[1]);
	printf("---------------------------\n");
	printf("File Size: \t\t%lld bytes\n", fstat.st_size);
	printf("Number of Links: \t%hu\n", fstat.st_nlink);
	printf("File inode: \t\t%lld\n", fstat.st_ino);
	printf("File Permissions: \t");
	printf( (S_ISDIR(fstat.st_mode)) ? "d" : "-");
	printf( (fstat.st_mode & S_IRUSR) ? "r" : "-");
	printf( (fstat.st_mode & S_IWUSR) ? "w" : "-");
	printf( (fstat.st_mode & S_IXUSR) ? "x" : "-");
	printf( (fstat.st_mode & S_IRGRP) ? "r" : "-");
	printf( (fstat.st_mode & S_IWGRP) ? "w" : "-");
	printf( (fstat.st_mode & S_IXGRP) ? "x" : "-");
	printf( (fstat.st_mode & S_IROTH) ? "r" : "-");
	printf( (fstat.st_mode & S_IWOTH) ? "w" : "-");
	printf( (fstat.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n\n");
	printf("The file %s a symbolic link\n", (S_ISLNK(fstat.st_mode)) ? "is" : "is not");
	return (0);
}

