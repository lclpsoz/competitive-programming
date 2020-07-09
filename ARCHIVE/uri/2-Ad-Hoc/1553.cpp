#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int i;
int qnt, mini, num, ans;
int nums[MAXN];

int main (){

	while(scanf("%d %d", &qnt, &mini), qnt || mini){

		for (i = 0; i < qnt; i++){

			scanf("%d", &num);
			nums[num]++;

		}

		ans = 0;
		for (i = 1; i < 101; i++){

			if (nums[i] >= mini) ans++;
			nums[i] = 0;

		}

		printf("%d\n", ans);

	}

	return 0;
}
