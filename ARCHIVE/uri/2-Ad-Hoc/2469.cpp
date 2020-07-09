#include <bits/stdc++.h>
using namespace std;

int i;
int qnt, val;
map<int, int> grades;
pair<int, int> maxi;

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%d", &val);
		grades[val]++;
		if (grades[val] > maxi.second || (grades[val] == maxi.second && val > maxi.first)){

			maxi.first = val;
			maxi.second = grades[val];

		}
	}

	printf("%d\n", maxi.first);


	return 0;
}
