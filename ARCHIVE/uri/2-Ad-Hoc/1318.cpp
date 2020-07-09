#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int i;
int ori, qnt, fake, val;
int tickets[MAXN];
int tickets_fakes[MAXN];

int main (){

	scanf("%d %d", &ori, &qnt);
	while (ori || qnt){

		fake = 0;
		for (i = 0; i < qnt; i++){

			scanf("%d", &val);
			if (tickets[val] && !tickets_fakes[val]){

				tickets_fakes[val] = true;
				fake++;

			}
			else tickets[val] = true;

		}

		printf("%d\n", fake);

		for (i = 0; i <= ori; i++){

			tickets[i] = false;
			tickets_fakes[i] = false;

		}

		scanf("%d %d", &ori, &qnt);

	}

	return 0;
}
