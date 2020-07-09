#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int i, j;
int n, b, val, pos;
int balls[MAXN];
bool first, last, test;
int seq[4];

void mark (int x)
{
	seq[x/32] |= 1<<(x%32);
}

bool check (int x)
{
	return seq[x/32] & 1<<(x%32);
}

int main (){

	while(scanf("%d %d", &n, &b), n || b){

		if (b > n){
			putchar ('Y');
			for (i = 0; i < b; i++)
				scanf("%d", &val);
		}
		else{

			first = last = false;
			for (i = 0; i < b; i++){

				scanf("%d", &val);
				balls[i] = val;
				if (!val) first = true;
				else if (val == n) last = true;

			}

			if (!first || !last)
				putchar ('N');
			else{

				mark(0);
				for (i = 0; i < b-1; i++)
					for (j = i+1; j < b; j++){

						pos = abs(balls[i] - balls[j]);
						mark(pos);

					}

				test = true;
				for (i = 0; i <= n; i++)
					if (!check(i)) {
						test = false;
						break;
					}

				test ? putchar ('Y') : putchar ('N');

			}
		}
		putchar ('\n');

		memset(seq, 0, sizeof(seq));
	}

	return 0;
}
