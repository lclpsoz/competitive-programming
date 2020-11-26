for i in {1..100000}; do
    python3 ger.py > in
    EXECTIME=$({ TIMEFORMAT=%E; time ./E < in > outTest; } 2>&1)
    if [ $i -eq 0 ]
    then
        MAXI=$EXECTIME
    fi
    ./E_AC < in > outAC
    result=$(diff -y -W 72 outTest outAC)
    if  [ $? -eq 0 ]
    then
        var=$(awk 'BEGIN{ print "'$MAXI'"<"'$EXECTIME'" }')
        if [ "$var" -eq 1 ]; then
            MAXI=$EXECTIME
            cp in in-$MAXI.txt
        fi
        echo -ne $i $EXECTIME $MAXI ok!\\r
    else
	    echo "WA"
	    break
    fi
done
