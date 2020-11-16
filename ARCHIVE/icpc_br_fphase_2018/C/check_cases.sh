# echo "$FILE"
for VAR in {1..15}; do
    OUT=output/C_$VAR
    echo ---------- START
    echo output/C_$VAR
    echo input/C_$VAR
    time ./run < input/C_$VAR > dif && diff $OUT dif
    echo OK!
    echo ---------- END
done
