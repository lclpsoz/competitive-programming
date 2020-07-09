#include <bits/stdc++.h>
using namespace std;

const int MAXN = 550;

int i;
int n, k, aux, wins[MAXN];
queue< pair<int,int> > table;
pair<int, int> p1, p2;

int main (){

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++){

		scanf("%d", &aux);
		table.push(make_pair(i+1, aux));

	}

	for (i = 0; wins[p1.first] < k && wins[p2.first] < k && i < 2000; i++){

		if (p1.first == 0){

			p1 = make_pair(table.front().first, table.front().second);
			table.pop();

		}
		if (p2.first == 0){

			p2 = make_pair(table.front().first, table.front().second);
			table.pop();

		}
		if (p1.second > p2.second){

			wins[p1.first]++;
			table.push(p2);
			p2 = make_pair(0, 0);

		}
		else{

			wins[p2.first]++;
			table.push(p1);
			p1 = make_pair(0, 0);

		}

	}

	if (p1.first == 0)
		p1.second = p2.second;

	printf("%d\n", p1.second);

	for (i = 1; i <= n; i++)
		printf("%d: %d\n", i, wins[i]);

	return 0;
}
