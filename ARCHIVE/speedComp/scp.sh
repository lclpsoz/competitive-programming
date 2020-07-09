for i in {1..1000000}; do
	EXEC1=$({ TIMEFORMAT=%E; time g++ -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wcast-qual -Wcast-align -Wsign-conversion -fsanitize=address -std=c++14 bits.cpp -o bits$i; } 2>&1)
	EXEC2=$({ TIMEFORMAT=%E; time g++ -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wcast-qual -Wcast-align -Wsign-conversion -std=c++14 bits.cpp -o bits$i; } 2>&1)

	echo $EXEC1"|"$EXEC2
done
