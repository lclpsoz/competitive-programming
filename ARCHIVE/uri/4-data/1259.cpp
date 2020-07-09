#include <bits/stdc++.h>
using namespace std;

int i;
int qnt, val;
vector<int> odd, even;

bool desc (int a, int b){

	return a > b;

}

int main (){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d", &val);

		if (val % 2) odd.push_back(val);
		else even.push_back(val);

	}

	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end(), desc);

	for (i = 0; i < even.size(); i++) printf("%d\n", even[i]);
	for (i = 0; i < odd.size(); i++) printf("%d\n", odd[i]);

	return 0;
}
