#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+10;

int i, j;
int qnt, size_arr, floors_qnt;
int arr[MAXN];
bool floor_type;

bool order (const int a, const int b)
{
	return abs(a) < abs(b);
}

int main ()
{
	scanf ("%d", &qnt);
	for (i = 0; i < qnt; i++) {
		scanf ("%d", &size_arr);
		floors_qnt = 0;
		if (size_arr) {
			for (j = 0; j < size_arr; j++)
				scanf ("%d", &arr[j]);
			sort (arr, arr+size_arr, order);
			arr[0] > 0 ? floor_type = true : floor_type = false;
			floors_qnt++;
			for (j = 1; j < size_arr; j++) {
				if ((floor_type && arr[j] < 0) || (floor_type == false && arr[j] > 0)) {
					floor_type = !floor_type;
					floors_qnt++;
				}
			}
		}
		printf ("%d\n", floors_qnt);
	}
	return 0;
}
