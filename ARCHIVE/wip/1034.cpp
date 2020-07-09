//Solution using greedy is not correct, others better variations of values exist, exemple in 1 4 6 to get 8
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;

int i, j;
int qnt, qnt_b, val, n, ans;
vector<int> blocks;

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%d %d", &qnt_b, &n);
		for (j = 0; j < qnt_b; j++){

			scanf("%d", &val);
			blocks.push_back(val);

		}

		sort(blocks.begin(), blocks.end());
		ans = 0;
		for (j = blocks.size()-1; j >= 0 && n; j--){
			if (blocks[j] <= n){

				ans += n / blocks[j];
				n -= blocks[j] * (n/blocks[j]);

			}
		}

		printf("%d\n", ans);
		blocks.clear();

	}

	return 0;
}
