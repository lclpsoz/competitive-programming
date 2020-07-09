#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int i, j;
int n, b, val, pos;
int balls[MAXN];
bool seq[MAXN], first, last, test;

int main (){

	while(scanf("%d %d", &n, &b), n || b){

		if (b > n){
			printf("Y\n");
			for (i = 0; i < b; i++) scanf("%d", &val);
		}
		else{

			first = last = false;
			for (i = 0; i < b; i++){

				scanf("%d", &val);
				balls[i] = val;
				if (!val) first = true;
				else if (val == n) last = true;

			}

			if (!first || !last) printf("N\n");
			else{

				seq[0] = true;
				for (i = 0; i < b-1; i++)
					for (j = i+1; j < b; j++){

						pos = abs(balls[i] - balls[j]);
						seq[pos] = true;

					}

				test = true;
				for (i = 0; i <= n; i++)
					if (!seq[i]) test = false;

				if (test) printf("Y\n");
				else printf("N\n");

			}
		}

		memset(seq, 0, sizeof(seq));
	}

	return 0;
}
