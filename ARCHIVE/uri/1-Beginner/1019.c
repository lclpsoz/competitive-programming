#include <stdio.h>

int main(){
	
	int hours, mins, secs;

	scanf("%d", &secs);

	hours = secs / 3600;
	secs -= hours * 3600;

	mins = secs / 60;
	secs -= mins * 60;

	printf("%d:%d:%d\n", hours, mins, secs);

	return 0;

}