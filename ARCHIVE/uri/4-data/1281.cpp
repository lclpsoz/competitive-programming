#include <bits/stdc++.h>
using namespace std;

int i, j;
int qnt_tests, qnt_sub, amount;
double price, ans;
string str;
map <string, double> prices;

int main (){

	scanf("%d", &qnt_tests);
	for (i = 0; i < qnt_tests; i++){

		scanf("%d", &qnt_sub);
		for (j = 0; j < qnt_sub; j++){

			cin >> str;
			scanf("%lf", &price);
			prices[str] = price;

		}

		ans = 0;
		scanf("%d", &qnt_sub);
		for (j = 0; j < qnt_sub; j++){

			cin >> str;
			scanf("%d", &amount);
			ans += (double) amount * prices[str];

		}

		printf("R$ %.2lf\n", ans);

	}

	return 0;
}
