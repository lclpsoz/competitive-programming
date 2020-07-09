#include <bits/stdc++.h>
using namespace std;

const int MAXN = 550;

int i;
int n, aux, p1, p2;
long long unsigned k;
queue<int> table;
pair<int, int> wins;

int main (){

	scanf("%d %l64d", &n, &k);
	for (i = 0; i < n; i++){

		scanf("%d", &aux);
		table.push(aux);

	}

	for (i = 0; wins.second < k && i < 1e5; i++){

		if (p1 == 0){

			p1 = table.front();
			table.pop();

		}
		if (p2 == 0){

			p2 = table.front();
			table.pop();

		}

		if (p1 > p2){

			aux = 1;
			table.push(p2);
			p2 = 0;

		}
		else{

			aux = 2;
			table.push(p1);
			p1 = 0;

		}

		if (wins.first != aux)
			wins.second = 0;

		wins.first = aux;
		wins.second++;

	}

	if (p1)
		printf("%d\n", p1);
	else
		printf("%d\n", p2);

	return 0;
}
