#include <bits/stdc++.h>
using namespace std;

int i;
int lst, qnt, now, bef, aux, ans;

int main (){

	scanf("%d %d", &lst, &qnt);
	bef = 1;
	scanf("%d", &now);
	aux = now - bef;
	ans = max(ans, aux);
	bef = now;
	for (i = 1; i < qnt; i++){

		scanf("%d", &now);
		aux = (now - bef)/2;
		ans = max(aux, ans);
		bef = now;

	}
	aux = lst - bef;
	ans = max(aux, ans);

	printf("%d\n", ans);

	return 0;
}
