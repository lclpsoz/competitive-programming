#include <bits/stdc++.h>
using namespace std;

int i, j;
int qnt, qnt_stu, scr, ans;
vector< pair<int,int> > queue_can;

bool ord (const pair<int, int> &a, const pair<int, int> &b){

	return a.first > b.first;

}

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%d", &qnt_stu);
		for (j = 0; j < qnt_stu; j++){

			scanf("%d", &scr);
			queue_can.push_back(make_pair(scr, j + 1));

		}

		sort(queue_can.begin(), queue_can.end(), ord);

		ans = 0;
		for (j = 0; j < qnt_stu; j++)
			if (queue_can[j].second == j+1) ans++;

		printf("%d\n", ans);

		queue_can.clear();

	}

	return 0;
}
