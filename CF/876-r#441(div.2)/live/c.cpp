#include <bits/stdc++.h>
using namespace std;

int i, j;
int n;
//int mat[9][9]; //Each line is a power of 10, not including 10^9 because it results in 10^9 + 1, that's larger than the maximum possible result
//In columns, it goest from 1 in position 0 to 9 in position 8 (9 columns)
vector <int> vect;

int digits (int a){

	int ans = 0;

	while (a > 0){

		ans += a % 10;
		a /= 10;

	}

	return ans;

}

int main (){

	int ans = 0;

	/*for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++){

			mat[i][j] = ((j + 1) * pow(10, i)) + (j + 1);
			//printf("%d*10^%d + %d: %d\n", j+1, i, j+1, mat[i][j]);

		}
	*/
	scanf("%d", &n);
	for (i = 1; i < 82 && n - i > 0; i++){

		if (digits(n - i) == i){

			vect.push_back(n-i);
			ans++;

		}

	}

	printf("%d\n", ans);
	for (i = 0; i < ans; i++)
		printf("%d\n", vect[i]);

	return 0;
}
