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

printf "Currently Doing Valid tests"
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
printf "\n\nBasic Error tests & leaks\n\n" >> leakstests_outfile.txt
printf "\n\nBasic Error tests & leaks\n\n" >> leakstests_errfile.txt
printf "\033[2K\rCurrently Doing Basic Error tests"

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
printf "\n\na_errors tests & leaks\n\n" >> leakstests_outfile.txt
printf "\n\na_errors tests & leaks\n\n" >> leakstests_errfile.txt
# These should only print error messages in STDERR, so we will get STDERR too
printf "\033[2K\rCurrently Doing A Error tests"

ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/ratio.data.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/ratio.data.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/a_errors/ratio.data.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/ratio.input.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/ratio.input.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/a_errors/ratio.input.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/ratio.missing.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/ratio.missing.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/a_errors/ratio.missing.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/rgb.data.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/rgb.data.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/a_errors/rgb.data.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/rgb.incomplete.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/rgb.incomplete.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/a_errors/rgb.incomplete.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/rgb.input.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/rgb.input.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/a_errors/rgb.input.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/rgb.missing.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/a_errors/rgb.missing.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/a_errors/rgb.missing.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt

######################################################################################################################################################
# L Error tests ######################################################################################################################################
######################################################################################################################################################
printf "\n\nl_errors tests & leaks\n\n" >> leakstests_outfile.txt
printf "\n\nl_errors tests & leaks\n\n" >> leakstests_errfile.txt
printf "\033[2K\rCurrently Doing L Error tests"

ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/dir.data.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/dir.data.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/c_errors/dir.data.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/dir.incomplete.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/dir.incomplete.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/c_errors/dir.incomplete.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/dir.input.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/dir.input.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/c_errors/dir.input.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/dir.missing.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/dir.missing.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/c_errors/dir.missing.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/fov.data.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/fov.data.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/c_errors/fov.data.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/fov.input.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/fov.input.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/c_errors/fov.input.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/fov.missing.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/fov.missing.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/c_errors/fov.missing.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/pos.data.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/pos.data.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/c_errors/pos.data.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/pos.incomplete.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/pos.incomplete.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/c_errors/pos.incomplete.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/pos.input.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/pos.input.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/c_errors/pos.input.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/pos.missing.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/c_errors/pos.missing.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/c_errors/pos.missing.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt

######################################################################################################################################################
# C Error tests ######################################################################################################################################
######################################################################################################################################################
printf "\n\nc_errors tests & leaks\n\n" >> leakstests_outfile.txt
printf "\n\nc_errors tests & leaks\n\n" >> leakstests_errfile.txt
printf "\033[2K\rCurrently Doing C Error tests"

ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/l_errors/pos.data.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/l_errors/pos.data.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/l_errors/pos.data.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/l_errors/pos.incomplete.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/l_errors/pos.incomplete.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/l_errors/pos.incomplete.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/l_errors/pos.input.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/l_errors/pos.input.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/l_errors/pos.input.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/l_errors/pos.missing.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/l_errors/pos.missing.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/l_errors/pos.missing.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/l_errors/ratio.data.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/l_errors/ratio.data.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/l_errors/ratio.data.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/l_errors/ratio.input.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/l_errors/ratio.input.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/l_errors/ratio.input.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt
ft_print_lines
printf "\nleaks -atExit -q -- ./miniRT scenes/error/l_errors/ratio.missing.rt\n" >> leakstests_outfile.txt
printf "\nleaks -atExit -q -- ./miniRT scenes/error/l_errors/ratio.missing.rt\n" >> leakstests_errfile.txt
leaks -atExit -q -- ./miniRT scenes/error/l_errors/ratio.missing.rt >> leakstests_outfile.txt 2>> leakstests_errfile.txt