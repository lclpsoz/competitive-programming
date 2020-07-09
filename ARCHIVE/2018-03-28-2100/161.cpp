#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20000;

int i, j, k;
int n, x, hr, minu, sec;
bool t_b[100];
int t[3][MAXN];

int main ()
{
	while (1) {
		scanf ("%d", &n);
		if (n == 0) {
			for (i = 0; i < 100; i++)
				t_b[i] = 0;
			if (t[0][2]-1 > 18000)
				printf ("Signals fail to synchronise in 5 hours\n");
			else {
				sec = t[0][2]-1;
				hr = sec / 3600;
				sec -= hr * 3600;
				minu = sec / 60;
				sec -= minu * 60;
				printf ("%02d:%02d:%02d\n", hr, minu, sec);
			}
			scanf("%d", &n);
			if (n == 0) {
				scanf("%d", &n);
				break;
			}
			else {
				for (i = 0; i < 4; i++)
					for (j = 0; j < 2; j++)
						t[j][i] = 0;
			}
		}
		i = 0; j = 0; k = 0;
		if (t[0][0] == 0) {
			//Start fixed row
			x = 1; i = 0;
			while (x < MAXN) {
				t[0][i++] = x;
				x += n-6; //n-5-1, green
				t[0][i++] = x;
				x += n+6; //n+5+1, red and orange
			}
			t_b[n] = true;
		}
		else if (!t_b[n]){
			//Save new row
			x = 1; i = 0;
			while (x < MAXN) {
				t[1][i++] = x;
				x += n-6; //n-5-1, green
				t[1][i++] = x;
				x += n+6; //n+5+1, red and orange
			}
			//Compare new with fixed row if not present
			i = j = k = 0;
			while (t[0][i] && t[1][j]) {
				if (t[0][i] > t[1][j+1])
					j += 2;
				else if (t[0][i+1] < t[1][j])
					i += 2;
				else {
					if (t[0][i] > t[1][j])
						t[2][k] = t[0][i];
					else
						t[2][k] = t[1][j];

					if (t[0][i+1] > t[1][j+1]) {
						t[2][k+1] = t[1][j+1]; j += 2;
					}
					else {
						t[2][k+1] = t[0][i+1]; i += 2;
					}
					k += 2;
				}
			}
			t[2][k] = t[2][k+1] = 99999;
			t_b[n] = true;
			//Copy new row to the fixed
			i = 0;
			do {
				t[0][i] = t[2][i];
				t[0][i+1] = t[2][i+1];
				t[0][i+2] = t[2][i+2];
				t[0][i+3] = t[2][i+3];
				i += 4;
			} while (t[2][i-2]);
		}
	}
	return 0;
}
