#include <bits/stdc++.h>
using namespace std;

int i;
int qnt_h, qnt_d, val, pos, mini, ans;
map<int, int> houses;

int main (){

	scanf("%d %d", &qnt_h, &qnt_d);
	mini = 1e7;
	for (i = 0; i < qnt_h; i++){

		scanf("%d", &val);
		houses[val] = i+1;
		if (val < mini){

			mini = val;
			pos = i+1;

		}

	}

	for (i = 0; i < qnt_d; i++){

		scanf("%d", &val);

		ans += abs(pos - houses[val]);
		pos = houses[val];

	}

	printf("%d\n", ans);

	return 0;
}
