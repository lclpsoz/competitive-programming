#include <bits/stdc++.h>
using namespace std;

int i;
int n, m;
int ans, aux, val;

int main (){

	scanf("%d %d", &n, &m);
	aux = 0;
	for (i = 0; i < n; i++){

		scanf("%d", &val);
		aux = m - (val + aux);
		ans += abs(aux);

	}
	printf("%d\n", ans);

	return 0;
}
