#include <bits/stdc++.h>
using namespace std;

int i, j;
int players, matches, ans, val;
bool goals;

int main (){

	while (scanf("%d %d", &players, &matches) != EOF){

		ans = 0;
		for (i = 0; i < players; i++){

			goals = true;
			for (j = 0; j < matches; j++){

				scanf("%d", &val);
				if (!val) goals = false;

			}
			if (goals) ans++;

		}

		printf("%d\n", ans);

	}

	return 0;
}

