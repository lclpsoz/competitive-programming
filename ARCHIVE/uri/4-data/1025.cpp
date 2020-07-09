//Implementation using array of pair, first is the position and second is the amount
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long llu;
const int MAXN = 1e4+100;

int i;
llu marbles, queries, n, first, last, amnt, pos, turn;
pair<llu,llu> arr[MAXN];

int main (){

	scanf("%llu %llu", &marbles, &queries);
	turn = 1;
	while (marbles || queries){

		//Marbles
		first = MAXN;
		last = 0;
		for (i = 0; i < marbles; i++){

			scanf("%llu", &n);
			arr[n].second++;

			if (n > last) last = n;
			if (n < first) first = n;

		}

		amnt = 1;
		for (i = first; i <= last; i++){

			if (arr[i].second){

				//printf("%llu: %llu\n", i, arr[i].second);
				arr[i].first = amnt;
				amnt += arr[i].second;
				arr[i].second = 0;	//Amount will not be used after that

			}
		}

		//Queries
		printf("CASE# %llu:\n", turn++);
		for (i = 0; i < queries; i++){

			scanf("%llu", &n);
			pos = arr[n].first;

			if (pos) printf("%llu found at %llu\n", n, pos);
			else printf("%llu not found\n", n);

		}

		for (i = first; i <= last; i++)
			arr[i].first = 0;

		scanf("%llu %llu", &marbles, &queries);

	}

	return 0;
}
