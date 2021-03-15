#!/bin/bash

# PATH to push_swap directory
PS_DIR="./"

BOLD='\033[1m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
SET='\033[0m'

LOOP=0
CORRECT=0
RANGEARRAY="2 3 4 5 10 50 100 200 500"
NBTEST=10
MOVEMAX=0
MOVEMIN=0
MOVETMP=0
MOVE=0
ERROR=0
RESULT=$BOLD$YELLOW"RANGE: CORRECT_ANSWERS: AVERAGE_NB_MOVE: MIN_MOVE: MAX_MOVE:\n"$SET

verification_and_set_options()
{
	cd $PS_DIR
	if [ ! -e "push_swap" ] || [ ! -e "checker" ]; then
		echo "Push swap or checker not found trying to build project..."
		if [ ! -e "Makefile" ]; then
			echo "Makefile not found exiting."
			exit
		fi
		make
		if [ $? -ne 0 ]; then
			echo "Push_swap_tester: Make failed: exiting."
			exit 1
		fi
	fi

	if [ -n "$1" ]; then
		if  [ "$1" = "-r" ] && [ -n "$2" ]; then
			RANGEARRAY=$2
			if [ -n "$3" ]; then
				NBTEST=$3
			fi
		elif [ "$1" = "-r" ] && [ -z "$2" ]; then
			echo $RED$BOLD"Error arguments:$SET"
			echo -n $BOLD$YELLOW"USAGE:$SET"
			echo "\tsh push_swap_tester.sh \$NBTEST"
			echo "\tsh push_swap_tester.sh -r \$CUSTOMRANGEARRAY \$NBTEST\n"
			exit 1
		else
			NBTEST=$1
		fi
	fi
}

display_header()
{
	clear
	echo
	echo "  $GREEN""██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗     "
	echo "  $GREEN""██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗    "
	echo "  $GREEN""██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝    "
	echo "  $GREEN""██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝     "
	echo "  $GREEN""██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║         "
	echo "  $GREEN""╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝         "
	echo $BOLD$YELLOW"\nAUTHOR:$SET Nnevalti (github) / vdescham@42.student.fr\n"
	echo -n $BOLD$YELLOW"USAGE:$SET"
	echo "\tsh push_swap_tester.sh \$NBTEST"
	echo "\tsh push_swap_tester.sh -r \$CUSTOMRANGEARRAY \$NBTEST\n"
	echo $BOLD$YELLOW"DEFAULT:$SET\$CUSTOMRANGEARRAY = \"2 3 4 5 10 50 100 200 500\""
	echo "\t\$NBTEST = 10\n"
	echo -n $BOLD$YELLOW"Tested range$SET: ["
	echo -n $RANGEARRAY | sed "s/ /, /g"
	echo "]\n"
	echo "This script will test push_swap and checker $NBTEST times."
	echo "It will generate a random array for each test from 1..RANGE$SET"
	echo "Press enter to start the test !"
	read -r REPLY
}

calc_move_min_and_max()
{
	MOVETMP=$(wc -l op.log | cut -d ' ' -f1)
	if [ $((MOVETMP)) -gt "$MOVEMAX" ]; then
		MOVEMAX=$MOVETMP
	fi
	if [ "$MOVEMIN" -eq 0 ]; then
		MOVEMIN=$MOVETMP
	elif [ "$MOVETMP" -lt "$MOVEMIN" ]; then
		MOVEMIN=$MOVETMP;
	fi
	MOVE=$((MOVE+MOVETMP))
	MOVETMP=0
}

display_progress()
{
	printf "\033[2K"
	echo "RANGE 1-$RANGE"
	echo "Test completed $LOOP/$NBTEST"
	printf "\033[2A"
}

display_progress_check()
{
	if [ $ERROR -eq 0 ]; then
		printf "\033[2K"
		echo $GREEN"RANGE 1-$RANGE\t [ ✅]$SET"
		printf "\033[2K"
	else
		printf "\033[2K"
		echo $RED"RANGE 1-$RANGE\t [ ❌]$SET"
		printf "\033[2K"
	fi
	ERROR=0
}

calc_result()
{
	while read LINE
	do
		if [ "$LINE" = "OK" ]; then
			CORRECT=$((CORRECT+1))
		fi
	done < status.log
	rm -f status.log
	RESULT=$RESULT"1..$RANGE\t"
	if [ "$CORRECT" = "$NBTEST" ]; then
		RESULT=$RESULT$GREEN"$CORRECT/$NBTEST[✅]$SET "
	elif [ "$CORRECT" -gt 0 ]; then
		COLOR=$YELLOW
		RESULT=$RESULT$YELLOW"$CORRECT/$NBTEST[-]$SET "
	else
		COLOR=$RED
		RESULT=$RESULT$RED"$CORRECT/$NBTEST[❌]$SET "
	fi

	RESULT=$RESULT$((MOVE/NBTEST))" "
	RESULT=$RESULT"$MOVEMIN "

	if [ "$RANGE" -le 3 -a "$MOVEMAX" -gt 3 ] || [ "$RANGE" -le 5 -a "$MOVEMAX" -gt 12 ] || [ "$RANGE" -le 100 -a "$MOVEMAX" -gt 700 ] || [ "$RANGE" -le 500 -a "$MOVEMAX" -gt 5500 ]; then
		RESULT=$RESULT$RED$MOVEMAX"[❌]$SET\n"
	else
		RESULT=$RESULT$GREEN$MOVEMAX"[✅]$SET\n"
	fi
}

reset_variable()
{
	MOVE=0
	MOVEMAX=0
	MOVEMIN=0
	LOOP=0
	CORRECT=0
}

# START SCRIPT
verification_and_set_options $1 $2 $3
display_header
for RANGE in $RANGEARRAY
do
	while [ "$LOOP" != "$NBTEST" ]; do
		display_progress
		ARG=`ruby -e "puts (1..$RANGE).to_a.shuffle.join(' ')"`; ./push_swap $ARG > op.log
		ERROR=$?
		./checker $ARG < op.log >> status.log
		ERROR=$((ERROR+$?))
		calc_move_min_and_max
		LOOP=$((LOOP+1))
	done
	display_progress_check
	calc_result
	reset_variable
	RANGE=$((RANGE+1))
done
rm op.log
echo $BOLD"\nRESULT :\n"$SET
echo $RESULT | column -t -e
