#include <cstdio>
using namespace std;

int arr[2][4];

int main ()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			scanf ("%d", &arr[i][j]);
	//x-axis
	if (arr[0][0] > arr[1][2] || arr[1][0] > arr[0][2])
		printf ("0\n");
	//y-axis
	else if (arr[0][1] > arr[1][3] || arr[1][1] > arr[0][3])
		printf ("0\n");
	else
		printf ("1\n");
	return 0;
}
