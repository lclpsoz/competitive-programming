#include <bits/stdc++.h>
using namespace std;

int const MAXS = 1e5+10;

int i;
int qnt;
int zeros, ones, ans;
char str[MAXS];
map<int, int> comp;

int main (){

	scanf("%d", &qnt);
	scanf("%s", str);

	ans = 0;
	comp[0] = 0;
	for (i = 1; i <= qnt; i++){

		if (str[i-1]-'0') ones++;
		else zeros++;

		if (comp.count(ones - zeros))
			ans = max(ans, i - comp[ones-zeros]);
		else
			comp[ones - zeros] = i;

	}

	printf("%d\n", ans);

	return 0;
}
