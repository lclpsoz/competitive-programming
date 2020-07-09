# echo "$FILE"
for VAR in {1..40}; do
    OUT=output/I_$VAR
    echo ---------- START $VAR
    #echo output/B_$VAR
    #echo input/B_$VAR
    ./I < input/I_$VAR > dif && diff $OUT dif
    echo OK!
    echo ---------- END
done
