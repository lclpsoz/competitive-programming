#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int> > piii;

// If value is negative, not AC yet, if positivo, already AC
int mat [155][14];
char arr[50], t;
int part, probs, temp;
vector <piii> ans;
bool test[152];

bool ord (const piii &f, const piii &s)
{
	if (f.second.first > s.second.first)
		return true;
	else if (f.second.first < s.second.first)
		return false;
	else if (f.second.second < s.second.second)
		return true;
	else if (f.second.second > s.second.second)
		return false;
	else if (f.first > s.first)
		return false;
	else
		return true;
}

int main ()
{
	int n;
	scanf ("%d", &n);
	getchar (); // '\n'
	for (int l = 0; l < n; l++) {
		if (l > 0)
			putchar ('\n');
		getchar ();
		while (scanf ("%[^\n]", arr), strlen (arr)) {
			getchar ();
			// probs+1, pois posicao 0 eh o total de problemas e 1 eh o total de tempo acumulado
			sscanf (arr, "%d %d %d %c", &part, &probs, &temp, &t);
			test[part] = true;
			//printf ("::%d %d %d\n", part, probs, temp);
			if (t == 'C' && mat[part][probs+1] <= 0) {
				mat[part][probs+1] = abs(mat[part][probs+1]*20) + temp;
				mat[part][0]++;
				mat[part][1] += mat[part][probs+1];
				if (mat[part][probs+1] == 0)
					mat[part][probs+1]++;
			}
			else if (t == 'I' && mat[part][probs+1] <= 0)
				mat[part][probs+1]--;

			arr[0] = '\0';
		}
		//printf ("%d %d %d\n", 1, mat[1][0], mat[1][1]);
		//printf ("%d %d %d\n", 3, mat[3][0], mat[3][1]);
		for (int i = 0; i < 103; i++)
			if (test[i])
				ans.push_back ({i, {mat[i][0], mat[i][1]}});
		sort (ans.begin (), ans.end (), ord);
		for (int i = 0; i < ans.size (); i++)
			printf ("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
		ans.clear ();
		for (int j = 0; j < 105; j++) {
			for (int k = 0; k < 13; k++)
				mat[j][k] = 0;
			test[j] = false;
		}
	}

	return 0;
}
