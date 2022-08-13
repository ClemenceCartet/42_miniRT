#!/bin/bash

# Valid tests, should work without leaks or crash or anything
# of course, don't test leaks command with -fsanitize=address combined..
# test_battery.c and rt_write_errors.c are displaying informations on STDERR
# This script will display everything on STDOUT and in file leakstests_outfile.txt

ft_print_lines()
{
	a=0
	while [ $a -lt 3 ]; do
		printf "====================================================================================================\n" >> leakstests_outfile.txt
		printf "====================================================================================================\n" >> leakstests_errfile.txt
		a=$(($a + 1))
	done
}

######################################################################################################################################################
# Valid tests ########################################################################################################################################
######################################################################################################################################################
printf "Valid tests & leaks\n\n" > leakstests_outfile.txt
printf "Valid tests & leaks\n\n" > leakstests_errfile.txt

printf "\033[2K\rCurrently Doing \033[36mValid\033[0m tests, \033[33m\033[1m\033[4mPlease Wait\033[0m"
x=1
while [ $x -le 20 ]; do
	ft_print_lines
	printf "\nleaks -atExit -q -- ./miniRT scenes/valid/valid$x.rt\n" >> leakstests_outfile.txt
	printf "\nleaks -atExit -q -- ./miniRT scenes/valid/valid$x.rt\n" >> leakstests_errfile.txt
	leaks -atExit -q -- ./miniRT scenes/valid/valid$x.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
	x=$(($x + 1))
done

######################################################################################################################################################
# Basic Error tests ##################################################################################################################################
######################################################################################################################################################
ft_print_lines
ft_print_lines
ft_print_lines
printf "\n\nBasic Error tests & leaks\n\n" >> leakstests_outfile.txt
printf "\n\nBasic Error tests & leaks\n\n" >> leakstests_errfile.txt
printf "\033[2K\rCurrently Doing \033[36mBasic Error\033[0m tests, \033[33m\033[1m\033[4mPlease Wait\033[0m"

ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/empty.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/empty.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/empty.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/missA.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/missA.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/missA.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/missC.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/missC.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/missC.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/missL.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/missL.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/missL.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/missO.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/missO.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/missO.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/nlonly.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/nlonly.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/nlonly.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/noext\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/noext\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/noext >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/randomData.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/randomData.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/randomData.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/syntaxError.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/syntaxError.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/syntaxError.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/text.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/text.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/text.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/toomuchA.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/toomuchA.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/toomuchA.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/toomuchC.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/toomuchC.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/toomuchC.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/toomuchL.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/toomuchL.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/toomuchL.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/unknownID.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/unknownID.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/unknownID.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongext.rtr\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongext.rtr\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongext.rtr >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderA.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderA.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderA.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderC.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderC.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderC.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderCY.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderCY.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderCY.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderL.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderL.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderL.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderPL.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderPL.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderPL.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderSP.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderSP.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/basic_errors/wrongorderSP.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt

######################################################################################################################################################
# A Error tests ######################################################################################################################################
######################################################################################################################################################
ft_print_lines
ft_print_lines
ft_print_lines
printf "\n\nA Error tests & leaks\n\n" >> leakstests_outfile.txt
printf "\n\nA Error tests & leaks\n\n" >> leakstests_errfile.txt
printf "\033[2K\rCurrently Doing \033[36mA Ratio Error\033[0m tests, \033[33m\033[1m\033[4mPlease Wait\033[0m"

x=1
while [ $x -le 10 ]; do
	ft_print_lines
	printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/a_ratio/a.ratio.$x.rt\n" >> leakstests_outfile.txt
	printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/a_ratio/a.ratio.$x.rt\n" >> leakstests_errfile.txt
	leaks -atExit -q -- ./miniRT scenes/error/a_errors/a_ratio/a.ratio.$x.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
	x=$(($x + 1))
done

printf "\033[2K\rCurrently Doing \033[36mA RGB Error\033[0m tests, \033[33m\033[1m\033[4mPlease Wait\033[0m"

ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/a_rgb/a.rgb.0.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/a_rgb/a.rgb.0.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/a_errors/a_rgb/a.rgb.0.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
y=1
while [ $y -le 3 ]; do
	x=1
	while [ $x -le 10 ]; do
		ft_print_lines
		printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/a_rgb/a_rgb$y/a.rgb$y.$x.rt\n" >> leakstests_outfile.txt
		printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/a_rgb/a_rgb$y/a.rgb$y.$x.rt\n" >> leakstests_errfile.txt
		leaks -atExit -q -- ./miniRT scenes/error/a_errors/a_rgb/a_rgb$y/a.rgb$y.$x.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
		x=$(($x + 1))
	done
	y=$(($y + 1))
done