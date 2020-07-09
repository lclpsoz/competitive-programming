#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;

int i, j, k[3], l[3], m;
int tests, qnt, mid, ans1, ans2;
int arr[MAXN], asc[MAXN], aux[MAXN];

bool sort_desc (const int &a, const int &b){

	return a > b;

}

int main (){

	scanf("%d", &tests);
	for (i = 0; i < tests; i++){

		ans1 = ans2 = 0;
		scanf("%d", &qnt);
		for (j = 0; j < qnt; j++){

			scanf("%d", &arr[j]);
			asc[j] = arr[j];

		}

		sort(asc, asc+qnt);
		sort(arr, arr+qnt, sort_desc);

		mid = ceil((float)qnt/2) - 1;

		//Small in the middle
		aux[mid] = asc[0];

		//Smallers
		k[0] = mid - 2;
		k[1] = mid + 2;
		//Largers
		l[0] = mid - 1;
		l[1] = mid + 1;
		//Positions in asc e arr
		k[2] = 1;
		l[2] = 0;
		for (m = 0; m < qnt/2; m++){

			if (m%2 == 1){

				aux[k[1]] = asc[k[2]++];
				if (k[0] > -1)
					aux[k[0]] = asc[k[2]++];

				k[1] += 2;
				k[0] -= 2;


			}
			else{

				aux[l[1]] = arr[l[2]++];
				if (l[0] > -1)
					aux[l[0]] = arr[l[2]++];

				l[1] += 2;
				l[0] -= 2;

			}
		}

		for (j = 0; j < qnt-1; j++)
			ans1 += abs(aux[j] - aux[j+1]);

		//Larger in the middle
		aux[mid] = arr[0];

		//Smallers
		k[0] = mid - 1;
		k[1] = mid + 1;
		//Largers
		l[0] = mid - 2;
		l[1] = mid + 2;
		//Positions in asc e arr
		k[2] = 0;
		l[2] = 1;
		for (m = 0; m < qnt/2; m++){

			if (m%2 == 0){

				aux[k[1]] = asc[k[2]++];
				if (k[0] > -1)
					aux[k[0]] = asc[k[2]++];

				k[1] += 2;
				k[0] -= 2;


			}
			else{

				aux[l[1]] = arr[l[2]++];
				if (l[0] > -1)
					aux[l[0]] = arr[l[2]++];

				l[1] += 2;
				l[0] -= 2;

			}
		}

		for (j = 0; j < qnt-1; j++)
			ans2 += abs(aux[j] - aux[j+1]);

		if (ans1 > ans2)
			printf("Case %d: %d\n", i+1, ans1);
		else
			printf("Case %d: %d\n", i+1, ans2);
		//printf("\n");

	}

	return 0;
}
