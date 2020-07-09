#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int i;
int score, diff[MAXN];
int games, extra, sco, rec, aux;

int main (){

	while(scanf("%d %d", &games, &extra) != EOF){

		score = 0;
		for (i = 0; i < games; i++){

			scanf("%d %d", &sco, &rec);
			if (sco > rec) score += 3;
			else diff[rec - sco]++;

		}

		i = 0;
		while (extra && i < 101){

			i = 0;
			while (!diff[i] && i < 101) i++;

			aux = extra / (i+1);
			aux = min(aux, diff[i]);
			if (aux){

				score += (3 * aux);
				extra -= (i + 1) * aux;
				diff[i] -= aux;

			}
			else if (extra == i){

				diff[0]++;
				extra = 0;
				diff[i]--;

			}
			else
				extra = 0;

		}
		score += diff[0];

		printf("%d\n", score);

		for (i = 0; i < 101; i++) diff[i] = 0;

	}

	return 0;
}
