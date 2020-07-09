#include <bits/stdc++.h>
using namespace std;

int i, j;
int qnt_birds, qnt_places, qnt_laps, qnt_laps_tp;
int qnt_spec, now, bef;
int main (){

	scanf("%d %d", &qnt_birds, &qnt_places);

	qnt_laps = 1;
	for (i = 0; i < qnt_birds; i++){

		qnt_laps_tp = 1;
		scanf("%d", &qnt_spec);
		scanf("%d", &bef);
		for (j = 2; j <= qnt_spec; j++){

			scanf("%d", &now);
			if (now < bef)
				qnt_laps_tp++;

			bef = now;

		}
		if (bef == 0)
			qnt_laps_tp--;

		if (qnt_laps_tp > qnt_laps)
			qnt_laps = qnt_laps_tp;

	}

	printf("%d\n", qnt_laps);

	return 0;
}
