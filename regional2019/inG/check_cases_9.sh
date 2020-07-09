# echo "$FILE"
for VAR in {1..40}; do
    OUT=output/G_$VAR
    echo ---------- START $VAR
    #echo output/B_$VAR
    #echo input/B_$VAR
    ./G < input/G_$VAR > dif && diff $OUT dif
    echo OK!
    echo ---------- END
done
