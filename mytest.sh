LOOP=0
CORRECT=0
RANGE=500
MAXRANGE=500
NBTEST=10
MOVEMAX=0
MOVETMP=0
MOVE=0

if [ ! -e "push_swap" ]; then
	echo "Push swap not found"
	exit 1
fi

if [ ! -e "checker" ]; then
	echo "Checker not found"
	exit 1
fi

if [ -n "$1" ]; then
	NBTEST=$1
fi

if [ -n "$2" ]; then
	MAXRANGE=$2
fi

while [ "$RANGE" -le "$MAXRANGE" ]; do
	while [ "$LOOP" != "$NBTEST" ]; do
		ARG=`ruby -e "puts (1..$RANGE).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG >> status.log
		LOOP=$((LOOP+1))
	done
	while read LINE
	do
		if [ "$LINE" = "OK" ]; then
			CORRECT=$((CORRECT+1))
		fi
		MOVETMP=`echo $LINE | grep MOVE | cut -d ' ' -f3`
		if [ $((MOVETMP)) -gt "$MOVEMAX" ]; then
			MOVEMAX=$MOVETMP
		fi
		MOVE=$((MOVE+MOVETMP))
		MOVETMP=0
	done < status.log
	rm -f status.log
	echo "$CORRECT/$NBTEST correct answer"
	echo "RANGE is 1-$RANGE"
	echo "AVERAGE NB OF MOVE = "$((MOVE/NBTEST))
	echo "MAX MOVE =" $MOVEMAX "\n"
	MOVE=0
	MOVEMAX=0
	RANGE=$((RANGE+1))
	LOOP=0
	CORRECT=0
done
