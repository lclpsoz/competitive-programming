make i
while true
do
    python ger.py > in5.txt
    if ! ./i < in5.txt; then
        break
    fi
done