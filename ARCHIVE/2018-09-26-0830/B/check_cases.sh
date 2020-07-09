# echo "$FILE"
for VAR in {1..36}; do
    OUT=output/B_$VAR
    echo ---------- START $VAR
    #echo output/B_$VAR
    #echo input/B_$VAR
    ./run < input/B_$VAR > dif && diff $OUT dif
    echo OK!
    echo ---------- END
done
