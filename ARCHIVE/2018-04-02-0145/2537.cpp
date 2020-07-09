#include<bits/stdc++.h>
using namespace std;

int N; // N-->max_x and max_y
const int MAXN = 1e6+10;

struct Query
{
    int x1, y1; // x and y co-ordinates of bottom left
    int x2, y2; // x and y co-ordinates of top right
};

// A function to update the 2D BIT
void updateBIT(int BIT[][MAXN], int x, int y, int val)
{
    for (; x <= N; x += (x & -x))
    {
        // This loop update all the 1D BIT inside the
        // array of 1D BIT = BIT[x]
        for (; y <= N; y += (y & -y))
            BIT[x][y] += val;
    }
    return;
}

// A function to get sum from (0, 0) to (x, y)
int getSum(int BIT[][MAXN], int x, int y)
{
    int sum = 0;

    for(; x > 0; x -= x&-x)
    {
        // This loop sum through all the 1D BIT
        // inside the array of 1D BIT = BIT[x]
        for(; y > 0; y -= y&-y)
        {
            sum += BIT[x][y];
        }
    }
    return sum;
}

// A function to create an auxiliary matrix
// from the given input matrix
void constructAux(int mat[][MAXN], int aux[][N+1])
{
    // Initialise Auxiliary array to 0
    for (int i=0; i<=N; i++)
        for (int j=0; j<=N; j++)
            aux[i][j] = 0;

    // Construct the Auxiliary Matrix
    for (int j=1; j<=N; j++)
        for (int i=1; i<=N; i++)
            aux[i][j] = mat[N-j][i-1];

    return;
}

// A function to construct a 2D BIT
void construct2DBIT(int mat[][MAXN], int BIT[][N+1])
{
    // Create an auxiliary matrix
    int aux[N+1][N+1];
    constructAux(mat, aux);

    // Initialise the BIT to 0
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            BIT[i][j] = 0;

    for (int j=1; j<=N; j++)
    {
        for (int i=1; i<=N; i++)
        {
            // Creating a 2D-BIT using update function
            // everytime we/ encounter a value in the
            // input 2D-array
            int v1 = getSum(BIT, i, j);
            int v2 = getSum(BIT, i, j-1);
            int v3 = getSum(BIT, i-1, j-1);
            int v4 = getSum(BIT, i-1, j);

            // Assigning a value to a particular element
            // of 2D BIT
            updateBIT(BIT, i, j, aux[i][j]-(v1-v2-v4+v3));
        }
    }

    return;
}

// A function to answer the queries
void answerQueries(Query q[], int m, int BIT[][MAXN])
{
    for (int i=0; i<m; i++)
    {
        int x1 = q[i].x1 + 1;
        int y1 = q[i].y1 + 1;
        int x2 = q[i].x2 + 1;
        int y2 = q[i].y2 + 1;

        int ans = getSum(BIT, x2, y2)-getSum(BIT, x2, y1-1)-
                  getSum(BIT, x1-1, y2)+getSum(BIT, x1-1, y1-1);

        printf ("Query(%d, %d, %d, %d) = %d\n",
                q[i].x1, q[i].y1, q[i].x2, q[i].y2, ans);
    }
    return;
}

bool verif[MAXN][MAXN];

// Driver program
int main()
{
    int mat[N][N] = {{1, 2, 3, 4},
                    {5, 3, 8, 1},
                    {4, 6, 7, 5},
                    {2, 4, 8, 9}};

    // Create a 2D Binary Indexed Tree
    int BIT[N+1][N+1];
    construct2DBIT(mat, BIT);

    Query q[] = {{1, 1, 3, 2}, {2, 3, 3, 3}, {1, 1, 1, 1}};
    int m = sizeof(q)/sizeof(q[0]);

    answerQueries(q, m, BIT);

    return(0);
}
