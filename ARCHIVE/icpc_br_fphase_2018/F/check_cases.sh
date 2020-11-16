# echo "$FILE"
for VAR in {1..40}; do
    OUT=output/F_$VAR
    echo ---------- START
    echo output/F_$VAR
    echo input/F_$VAR
    time ./run < input/F_$VAR > dif && diff $OUT dif
    echo OK!
    echo ---------- END
done
