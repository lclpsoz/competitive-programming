#include <stdio.h>
#include <string.h>

int main(){

	int i;
	char *table[12][2] = {	{"1", "January"},	{"2", "February"},	{"3", "March"},
							{"4", "April"},		{"5", "May"},		{"6", "June"},
							{"7", "July"},		{"8", "August"},	{"9", "September"},
							{"10", "October"},	{"11", "November"},	{"12", "December"}};	
	char num_month[2] = {'\0'};
	scanf("%2s", num_month);

	for (i = 0; i < 12; ++i)	{
		
		if (strcmp(table[i][0], num_month) == 0){

			printf("%s\n", table[i][1]);

		}
	}

	return 0;
}