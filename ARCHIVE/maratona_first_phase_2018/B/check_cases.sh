# echo "$FILE"
for VAR in {1..54}; do
    OUT=out/B_$VAR
    echo ---------- START
    echo out/B_$VAR
    echo in/B_$VAR
    ./run < in/B_$VAR > dif && diff $OUT dif
    echo OK!
    echo ---------- END
done
