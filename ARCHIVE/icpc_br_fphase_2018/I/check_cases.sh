# echo "$FILE"
for VAR in {1..26}; do
    OUT=output/I_$VAR
    echo ---------- START $VAR
    #echo output/I_$VAR
    #echo input/I_$VAR
    ./run < input/I_$VAR > dif && diff $OUT dif
    echo OK!
    echo ---------- END
done
