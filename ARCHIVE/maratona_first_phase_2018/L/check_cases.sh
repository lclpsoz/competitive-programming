# echo "$FILE"
for VAR in {1..26}; do
    OUT=output/L_$VAR
    echo ---------- START
    echo output/L_$VAR
    echo input/L_$VAR
    time ./run < input/L_$VAR > dif && diff $OUT dif
    echo OK!
    echo ---------- END
done
