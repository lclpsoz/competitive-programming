#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;

void conquer (const int l_st, const int r_st, int *arr, int *ans){


	//printf("%d %d\n", l_st, r_st);
	int i;
	int l, r, mid;
	int aux[MAXN];

	mid = (l_st + r_st) / 2;
	l = l_st;
	r = mid + 1;

	i = l_st;
	while (l <= mid && r <= r_st){

		if (arr[l] < arr[r]){

			if (l - i > 0) *ans += l - i;
			//cout << "l: " <<*ans << ' ' << l << '-' << i << '\n';
			aux[i++] = arr[l++];

		}
		else{

			if (r - i > 0) *ans += r - i;
			//cout << "r: " <<*ans << ' ' << r << ' ' << i << '\n';
			aux[i++] = arr[r++];

		}
	}

	while (l <= mid)
		aux[i++] = arr[l++];

	while (r <= r_st)
		aux[i++] = arr[r++];

	for (i = l_st; i <= r_st; i++)
		arr[i] = aux[i];

	//for (i = 0; i < 5; i++)
	//	cout << arr[i];
	//puts("");
	//cout << "A> " << *ans << '\n';

}

void divide (int l, int r, int *arr, int *ans){

	int mid;
	if (l < r){

		//printf("D: %d %d\n", l, r);

		mid = (l + r) / 2;
		divide(l, mid, arr, ans);
		divide(mid+1, r, arr, ans);

		conquer(l, r, arr, ans);

	}
}

int main (){

	int i;
	int qnt, car, overtakes, ans;
	int dict[MAXN], seq[MAXN];

	while(scanf("%d", &qnt) != EOF){

		ans = 0;
		//Create the 'map' in array named dict
		for (i = 0; i < qnt; i++){

			scanf("%d", &car);
			dict[car] = i+1;

		}

		//Insert and 'translate' postiion to array seq
		for (i = 0; i < qnt; i++){

			scanf("%d", &car);
			seq[i] = dict[car];
			//printf("%d ", seq[i]);

		}
		//puts("");

		divide(0, qnt-1, seq, &ans);

		//for (i = 0; i < qnt; i++)
		//	cout << seq[i];
		//puts("");

		printf("%d\n", ans);

	}

	return 0;
}
