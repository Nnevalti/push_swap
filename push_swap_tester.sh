#!/bin/bash

PS_DIR="./push_swap"

LOOP=0
CORRECT=0
RANGEARRAY="2 3 4 5 10 50 100 200 500"
# RANGEARRAY="5"
NBTEST=10
MOVEMAX=0
MOVETMP=0
MOVE=0
RESULT=$BOLD"\nResult :\n\n"$SET

BOLD='\033[1m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
SET='\033[0m'

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
	else
		NBTEST=$1
	fi
fi

clear
echo
echo "  "$GREEN"██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗     "
echo "  "$GREEN"██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗    "
echo "  "$GREEN"██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝    "
echo "  "$GREEN"██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝     "
echo "  "$GREEN"██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║         "
echo "  "$GREEN"╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝         "
echo $BOLD$YELLOW"\nAUTHOR:$SET Nnevalti (github) / vdescham@42.student.fr"
echo $BOLD$YELLOW
echo -n "USAGE:$SET"
echo "\tsh push_swap_tester.sh \$NBTEST"
echo "\tsh push_swap_tester.sh -r \$CUSTOMRANGEARRAY \$NBTEST\n"
echo $BOLD$YELLOW"DEFAULT:$SET\$CUSTOMRANGEARRAY = \"2 3 4 5 10 50 100 200 500\""
echo "\t\$NBTEST = 10\n"
echo -n $BOLD$YELLOW"Tested range$SET: ["
echo -n $RANGEARRAY | sed "s/ /, /g"
echo "]\n"
echo "This script will test push_swap and checker $NBTEST times."
echo "It will generate a random array for each test from 1 to RANGE$SET"
echo "Press enter to start the test !"
read -r REPLY
for RANGE in $RANGEARRAY
do
	while [ "$LOOP" != "$NBTEST" ]; do
		printf "\033[2K"
		echo "RANGE 1-$RANGE"
		echo "Test completed $LOOP/$NBTEST"
		printf "\033[2A"
		ARG=`ruby -e "puts (1..$RANGE).to_a.shuffle.join(' ')"`; ./push_swap $ARG > op.log
		./checker $ARG < op.log >> status.log
		MOVETMP=$(wc -l op.log | cut -d ' ' -f1)
		if [ $((MOVETMP)) -gt "$MOVEMAX" ]; then
			MOVEMAX=$MOVETMP
		fi
		MOVE=$((MOVE+MOVETMP))
		MOVETMP=0
		LOOP=$((LOOP+1))
	done
	if [ $? -eq 0 ]; then
		printf "\033[2K"
		echo $GREEN"RANGE 1-$RANGE\t [ ✅]$SET"
		printf "\033[2K"
	else
		printf "\033[2K"
		echo $RED"RANGE 1-$RANGE\t [ ❌]$SET"
		printf "\033[2K"
	fi
	while read LINE
	do
		if [ "$LINE" = "OK" ]; then
			CORRECT=$((CORRECT+1))
		fi
	done < status.log
	rm -f status.log
	RESULT=$RESULT$BOLD"RANGE: 1-$RANGE\n"$SET
	if [ "$CORRECT" = "$NBTEST" ]; then
		RESULT=$RESULT$GREEN"$CORRECT/$NBTEST correct answers\n$SET"
	elif [ "$CORRECT" -gt 0 ]; then
		COLOR=$YELLOW
		RESULT=$RESULT$YELLOW"$CORRECT/$NBTEST correct answers\n$SET"
	else
		COLOR=$RED
		RESULT=$RESULT$RED"$CORRECT/$NBTEST correct answers\n$SET"
	fi

	RESULT=$RESULT"Average Nb move: "$((MOVE/NBTEST))"\n"

	if [ "$RANGE" -le 3 -a "$MOVEMAX" -gt 3 ] || [ "$RANGE" -le 5 -a "$MOVEMAX" -gt 12 ] || [ "$RANGE" -le 100 -a "$MOVEMAX" -gt 700 ] || [ "$RANGE" -le 500 -a "$MOVEMAX" -gt 5300 ]; then
		RESULT=$RESULT$RED"Max move: $MOVEMAX[ ❌]\n\n$SET"
	else
		RESULT=$RESULT$GREEN"Max move: $MOVEMAX[ ✅]\n\n$SET"
	fi

	MOVE=0
	MOVEMAX=0
	RANGE=$((RANGE+1))
	LOOP=0
	CORRECT=0
done
rm op.log
echo $RESULT
