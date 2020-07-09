MAXI=0.0
for i in {1..100000}; do
    python3 ger.py > in
    EXECTIME=$({ TIMEFORMAT=%E; time ./D_1 < in > out1; } 2>&1)
    ./D < in > out2
    result=$(diff -y -W 72 out1 out2)
    if  [ $? -eq 0 ]
    then
	if (( $(bc <<<$EXECTIME'>'$MAXI) )); then
	    MAXI=$EXECTIME
	    cp in in-$MAXI.txt
	fi
	echo -ne $i $EXECTIME $MAXI ok!\\r
    else
	echo "WA"
	break
    fi
done
