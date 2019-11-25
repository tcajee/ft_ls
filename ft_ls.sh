#! /bin/bash

echo "Testing ft_ls submission by: tcajee"
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && ./ft_ls
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -a"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && ./ft_ls -a
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -l"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && ./ft_ls -l
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -l /"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && ./ft_ls -l /
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -r"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && ./ft_ls -r
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -t"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && ./ft_ls -lt
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -Rl"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && ./ft_ls -Rl
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -r author build Makefile srcs"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && ./ft_ls -r author build Makefile srcs
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -l author build Makefile srcs"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && ./ft_ls -l author build Makefile srcs
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -l -t -a -r"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && ./ft_ls -l -t -a
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -ltar"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && ./ft_ls -ltar
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls invalid"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && ./ft_ls invalid
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls with inaccesible folder"
echo "Making temp folder"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && mkdir temp
echo "Setting permissions"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && chmod 000 temp
echo "Testing ./ft_ls temp"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && ./ft_ls temp
read -p "Press enter to continue"
echo "Re-setting permissions"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && chmod 777 temp
echo "Cleaning"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && rm -rf temp
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -laXr"
cd /home/emptycee/Desktop/repos/ft_ls_git/ft_ls_final && ./ft_ls -laXr
read -p "Press enter to continue"
clear
echo "Testing Complete"
read -p "Press enter to continue"
clear
