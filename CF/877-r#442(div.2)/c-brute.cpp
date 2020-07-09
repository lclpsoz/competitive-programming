#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
typedef pair<int, int> pii;

int n, sum, steps, best;
pii arr[MAXN];
vector<int> path;
vector<int> best_path;

bool brute (int pos)
{
	/*for (int i = 0; i < steps; i++)
		printf ("  |");
	printf ("%d: %d\n", steps+1, pos);*/
	if (arr[pos].first || arr[pos].second) {
		pii aux;
		/*for (int i = 0; i < steps; i++)
			printf ("  |");
		for (int i = 0; i < n; i++)
			printf ("(%d, %d) ", arr[i].first, arr[i].second);
		putchar ('\n');*/
		if (pos == 0) {
			aux = arr[pos];
			arr[pos] = {0, 0};
			arr[pos+1].second += aux.first;
			sum -= aux.second;
			steps++;
			path.push_back (pos);
			for (int i = 0; i < n; i++)
				if (!brute (i))
					break;
			path.pop_back ();
			steps--;
			sum += aux.second;
			arr[pos+1].second -= aux.first;
			arr[pos] = aux;
		}
		else if (pos == n-1) {
			aux = arr[pos];
			arr[pos] = {0, 0};
			arr[pos-1].second += aux.first;
			sum -= aux.second;
			steps++;
			path.push_back (pos);
			for (int i = 0; i < n; i++)
				if (!brute (i))
					break;
			path.pop_back ();
			steps--;
			sum += aux.second;
			arr[pos-1].second -= aux.first;
			arr[pos] = aux;
		}
		else {
			aux = arr[pos];
			arr[pos] = {0, 0};
			arr[pos-1].second += aux.first>>1;
			arr[pos+1].second += aux.first>>1;
			sum -= aux.second;
			steps++;
			path.push_back (pos);
			for (int i = 0; i < n; i++)
				if (!brute (i))
					break;
			path.pop_back ();
			steps--;
			sum += aux.second;
			arr[pos-1].second -= aux.first>>1;
			arr[pos+1].second -= aux.first>>1;
			arr[pos] = aux;
		}
		return true;
	}
	else if (sum == 0 && steps < best) {
		best = steps;
		best_path = path;
		return false;
	}
	return true;
}

int main ()
{
	for (n = 2; n < 9; n++) {
		sum = n<<1;
		best = 1e9;
		steps = 0;
		printf ("----------|%d|----------\n", n);
		for (int j = 0; j < n; j++)
			arr[j] = {2, 0};
		for (int j = 0; j < n; j++) {
			brute (j);
		}
		printf ("%d\n", best);
		for (int x : best_path)
			printf ("%d ", x+1);
		putchar ('\n');
	}

	return 0;
}
