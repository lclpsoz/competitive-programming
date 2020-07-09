#include <bits/stdc++.h>
using namespace std;

int n, k;
int x;
int arr[110];

double brute ()
{
	vector<double> vec;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			for (int k = j+1; k < n; k++)
				vec.push_back ((arr[i]+arr[j]+arr[k])/3.0);

	sort (vec.begin(), vec.end());
	return vec[vec.size()-k];
}

int main ()
{
	while (scanf ("%d %d", &n, &k) != EOF) {
		for (int i = 0; i < n; i++)
			scanf ("%d", &arr[i]);

		printf ("%.1lf\n", brute());
	}

	return 0;
}
