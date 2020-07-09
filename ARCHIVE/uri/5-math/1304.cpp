#include <bits/stdc++.h>
using namespace std;

int i;
int tempo[2][4]; //hr:min:sec total in secs. First row is the 'last tempo', second is the tempo readed
double speed_now, speed_bef, dist;
char str[50];

int main (){

	while (scanf("%[^\n]\n", str) != EOF){

		if (strlen(str) > 8){

			sscanf(str, "%d:%d:%d %lf", &tempo[1][0], &tempo[1][1], &tempo[1][2], &speed_now);
			speed_now /= 3600; //Make it km/s
			tempo[1][3] = (tempo[1][0] * 3600) + (tempo[1][1] * 60) + tempo[1][2];

			if (tempo[0][3])
				dist += speed_bef * (tempo[1][3] - tempo[0][3]);

			for (i = 0; i < 4; i++)
				tempo[0][i] = tempo[1][i];
			speed_bef = speed_now;

		}
		else{

			sscanf(str, "%d:%d:%d", &tempo[1][0], &tempo[1][1], &tempo[1][2]);
			tempo[1][3] = (tempo[1][0] * 3600) + (tempo[1][1] * 60) + tempo[1][2];
			//printf("%d %d %d   %d\n", tempo[1][0], tempo[1][1], tempo[1][2], tempo[1][3]);

			if (tempo[0][3])
				dist += speed_bef * (tempo[1][3] - tempo[0][3]);

			printf("%02d:%02d:%02d %.2lf km\n", tempo[1][0], tempo[1][1], tempo[1][2], dist);

			for (i = 0; i < 4; i++)
				tempo[0][i] = tempo[1][i];
			speed_bef = speed_now;

		}

		//printf("TOTAL: %d|%lf\n\n", tempo[1][3], dist);
	}

	return 0;
}
