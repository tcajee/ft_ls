#! /bin/bash

echo "Testing ft_ls submission by: tcajee"
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls"
cd ~/Desktop/smsibi && ./ft_ls
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -a"
cd ~/Desktop/smsibi && ./ft_ls -a
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -l"
cd ~/Desktop/smsibi && ./ft_ls -l
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -l /"
cd ~/Desktop/smsibi && ./ft_ls -l /
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -r"
cd ~/Desktop/smsibi && ./ft_ls -r
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -t"
cd ~/Desktop/smsibi && ./ft_ls -lt
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -Rl"
cd ~/Desktop/smsibi && ./ft_ls -Rl
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -r author build Makefile srcs"
cd ~/Desktop/smsibi && ./ft_ls -r author build Makefile srcs
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -l author build Makefile srcs"
cd ~/Desktop/smsibi && ./ft_ls -l author build Makefile srcs
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -l -t -a -r"
cd ~/Desktop/smsibi && ./ft_ls -l -t -a
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -ltar"
cd ~/Desktop/smsibi && ./ft_ls -ltar
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls invalid"
cd ~/Desktop/smsibi && ./ft_ls invalid
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls with inaccesible folder"
echo "Making temp folder"
cd ~/Desktop/smsibi && mkdir temp
echo "Setting permissions"
cd ~/Desktop/smsibi && chmod 000 temp
echo "Testing ./ft_ls temp"
cd ~/Desktop/smsibi && ./ft_ls temp
read -p "Press enter to continue"
echo "Re-setting permissions"
cd ~/Desktop/smsibi && chmod 777 temp
echo "Cleaning"
cd ~/Desktop/smsibi && rm -rf temp
read -p "Press enter to continue"
clear
echo "Testing ./ft_ls -laXr"
cd ~/Desktop/smsibi && ./ft_ls -laXr
read -p "Press enter to continue"
clear
echo "Testing Complete"
read -p "Press enter to continue"
clear
