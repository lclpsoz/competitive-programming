#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int i, j;
int n, k, m, ans, val;
vector<pair<int, int> > vect;
int arr[MAXN];

int main (){

	scanf("%d %d %d", &n, &k, &m);
	for (i = 0; i < n; i++){

		scanf("%d", &val);
		vect.push_back(make_pair(val, val % m));
		arr[val%m]++;

	}

	ans = -1;
	for (i = 0; i < MAXN; i++)
		if (arr[i] >= k){

			ans = i;
			break;

		}

	if (ans == -1) printf("No\n");
	else{

		printf("Yes\n");
		for (i = 0, j = 0; i < n && j < k; i++)
			if (vect[i].second == ans){

				printf("%d ", vect[i].first);
				j++;

			}
		printf("\n");

	}

	return 0;
}
