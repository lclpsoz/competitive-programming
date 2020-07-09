# echo "$FILE"
for VAR in {1..64}; do
    OUT=output/M_$VAR
    echo ---------- START $VAR
    #echo output/M_$VAR
    #echo input/M_$VAR
    ./run < input/M_$VAR > dif && diff $OUT dif
    echo OK!
    echo ---------- END
done
