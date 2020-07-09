#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int i, j;
pair <int, int> arr[MAXN], *aux = NULL;
int tasks, hours;

bool sort_pair_vals (const pair <int, int> &a, const pair <int, int> &b){

	if (a.second > b.second)
		return true;
	else if (a.second == b.second && a.first > b.first)
		return true;

	return false;

}

int main (){

	int val, tim, sub, larger;
	while (scanf("%d %d", &tasks, &hours) != EOF){

		sub = 0;
		for (i = 0; i < tasks; i++){

			scanf("%d %d", &val, &tim);
			sub += val;
			arr[i] = make_pair (val, tim);

		}

		sort (arr, arr + tasks, sort_pair_vals);

		for (i = hours; i > 0; i--){

			larger = 0;
			for (j = 0; j < tasks && arr[j].second >= i; j++){

				if (arr[j].first > larger){

					aux = &arr[j];
					larger = aux->first;

				}

			}

			sub -= larger;
			//printf("SUB: %d\n", sub);
			if (larger)
				aux->first = -1;

		}

		printf("%d\n", sub);

	}

	return 0;
}
