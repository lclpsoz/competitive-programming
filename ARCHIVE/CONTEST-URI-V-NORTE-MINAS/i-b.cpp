#include <bits/stdc++.h>

int cost[1010];

int getInvCount(int arr[], int n)
{
  int inv_count = 0;
  for (int i = 0; i < n - 1; i++)
    for (int j = i+1; j < n; j++)
      if (arr[i] > arr[j])
        inv_count+=cost[arr[i]]+cost[arr[j]];

  return inv_count;
}

int main()
{
	int n;
	int a;
	int arr[1010];

	while (scanf ("%d", &n) != EOF) {
		for (int i = 0; i < n; i++)
			scanf ("%d", &arr[i]);
		for (int i = 0; i < n; i++)
			scanf ("%d", &cost[arr[i]]);
		printf ("%d\n", getInvCount (arr, n));
	}

	return 0;
}
