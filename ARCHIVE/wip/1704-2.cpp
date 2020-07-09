#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;
const int MAXN = 1e4;

int i, j;
int qnt_tasks, qnt_hours, val, max_t, tasks[MAXN], aux, min_v, min_t;
llu lost;

int main (){

	while(scanf("%d %d", &qnt_tasks, &qnt_hours) != EOF){

		lost = 0;
		for (i = 0; i < qnt_tasks; i++){

			scanf("%d %d", &val, &max_t);

			if (tasks[max_t]){

				aux = min(tasks[max_t], val);
				tasks[max_t] = max(tasks[max_t], val);

				min_v = tasks[max_t];
				min_t = max_t;
				for (j = 1; j < max_t; j++)
					if (tasks[j] < min_v){

						min_v = tasks[j];
						min_t = j;

					}

				lost += min(aux, tasks[min_t]);
				tasks[min_t] = max(aux, tasks[min_t]);

			}
			else tasks[max_t] = val;

			/*for (j = 1; j <= qnt_hours; j++)
				printf("%d ", tasks[j]);
			printf("\n\n");*/

		}

		printf("%llu\n", lost);

		for (i = 0; i <= qnt_hours; i++)
			tasks[i] = 0;

	}


	return 0;
}
