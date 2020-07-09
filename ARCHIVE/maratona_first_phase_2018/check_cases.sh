# echo "$FILE"
for VAR in {1..54}; do
    OUT=out/B_$VAR
    echo ---------- START
    echo output/B_$VAR
    echo input/B_$VAR
    ./run < input/B_$VAR > dif && diff $OUT dif
    echo OK!
    echo ---------- END
done
