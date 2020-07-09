#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;

int i;
int sections, team;
double dist, total_secs, avr, resp_min, resp_sec;
double tim[3];
char str[MAXN];
bool test;

int main (){

	scanf("%d %lf", &sections, &dist);

	while(scanf("%d", &team) != EOF){

		total_secs = 0;
		test = true;
		for (i = 0; i < sections; i++){

			scanf("%s", str);

			if (str[0] == '-')
				test = false;

			if (test){

				tim[0] = str[0] - '0';
				tim[1] = ((str[2] - '0') * 10) + (str[3] - '0');
				tim[2] = ((str[5] - '0') * 10) + (str[6] - '0');

				total_secs += (tim[0] * 3600) + (tim[1] * 60) + tim[2];

			}
		}

		avr = total_secs / dist;
		//printf("%lf %lf %lf\n", total_secs, avr, dist);

		resp_min = floor(avr / 60);
		resp_sec = avr - (resp_min * 60);

		if (round(resp_sec) == 60){

			resp_sec = 0;
			resp_min++;

		}

		for (i = 3; i > floor(log10(team) + 1); i--)
			printf(" ");

		if (test)
			printf("%d: %.0lf:%02.0lf min/km\n", team, resp_min, resp_sec);
		else
			printf("%d: -\n", team);

	}

	return 0;
}
