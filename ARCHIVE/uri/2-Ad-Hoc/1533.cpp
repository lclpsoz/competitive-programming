#include <bits/stdc++.h>
using namespace std;

int main (){

	int i;
	int qnt, val;
	pair<int, int> fst, sec;

	scanf("%d", &qnt);
	while (qnt){

		fst.second = sec.second = 0;
		for (i = 1; i <= qnt; i++){

			scanf("%d", &val);
			if (val > fst.second){

				sec.first = fst.first;
				sec.second = fst.second;
				fst.first = i;
				fst.second = val;

			}
			else if (val > sec.second){

				sec.first = i;
				sec.second = val;

			}

		}

		printf("%d\n", sec.first);

		scanf("%d", &qnt);

	}

	return 0;
}
