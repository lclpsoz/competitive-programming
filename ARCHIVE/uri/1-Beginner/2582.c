#include <stdio.h>

int i;
char songs[][20] = {	{"PROXYCITY\n"},
					{"P.Y.N.G.\n"},
					{"DNSUEY!\n"},
					{"SERVERS\n"},
					{"HOST!\n"},
					{"CRIPTONIZE\n"},
					{"OFFLINE DAY\n"},
					{"SALT\n"},
					{"ANSWER!\n"},
					{"RAR?\n"},
					{"WIFI ANTENNAS\n"}};
int runs, button1, button2;

int main (void){

	scanf("%d", &runs);

	for (i = 0; i < runs; i++){

		scanf("%d %d", &button1, &button2);

		printf("%s", songs[button1 + button2]);

	}

	return 0;
}
