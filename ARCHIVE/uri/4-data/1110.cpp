#include <bits/stdc++.h>
using namespace std;

int main (){

	int i;
	int qnt;
	deque<int> bar;

	scanf("%d", &qnt);
	while (qnt){

		printf("Discarded cards:");
		for (i = 1; i <= qnt; i++)
			bar.push_back(i);

		if (qnt > 1){

			printf(" %d", bar.front());

			for (i = 2; i <= qnt; i++){

				bar.pop_front();
				bar.push_back(bar.front());
				bar.pop_front();
				if (i == qnt && bar.front() % 2 == 0) break;
				printf(", %d", bar.front());

			}
		}
		printf("\n");

		printf("Remaining card: %d\n", bar.front());
		bar.clear();

		scanf("%d", &qnt);
	}

	return 0;
}
