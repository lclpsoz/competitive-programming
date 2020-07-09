#include <bits/stdc++.h>
using namespace std;

typedef struct _coord{

	int x;
	int y;

}Coord;

int i, j;
int qnt_games, qnt_balls, dist_now, dist_min, closest;
Coord white, other;

int main (){

	scanf("%d", &qnt_games);
	for (i = 0; i < qnt_games; i++){

		dist_min = 1e9;
		scanf("%d", &qnt_balls);
		scanf("%d %d", &white.x, &white.y);

		for (j = 0; j < qnt_balls; j++){

			scanf("%d %d", &other.x, &other.y);

			dist_now = pow(abs(white.x - other.x), 2) + pow(abs(white.y - other.y), 2);
			if (dist_now < dist_min){

				dist_min = dist_now;
				closest = j+1;

			}
		}

		printf("%d\n", closest);

	}

	return 0;
}
