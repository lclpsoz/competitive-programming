#include <bits/stdc++.h>

using namespace std;

const int MAXP = 32000;

bool not_prime[MAXP];
vector<int> primes;

void eratosthenes_sieve () {
    int i;
    for (i = 2; i*i < MAXP; i++)
        if (!not_prime[i]) {
            primes.push_back (i);
            for (int j = i*i; j < MAXP; j+=i)
                not_prime[j] = true;
        }
    for (; i < MAXP; i++)
        if (!not_prime[i])
            primes.push_back (i);
}

// Return empty if not divisible by 2,
// if it is the vector<int> will have
// it first position has the maximum
// expoent for 2 and the others
// positions for the others factors
vector<int> exp_divisors (int n) {
    vector<int> vec;
    if (n&1) return vec;
    int i = -1;
    for (int x : primes) {
		if (n%x == 0) i++;
        while (n%x == 0) {
            if (vec.size() == i)
                vec.push_back(1);
            else
                vec[i]++;
			n/=x;
        }
        if (n == 1) break;
    }
    if (n > 1)
        vec.push_back(1);
    
    return vec;
}

/*
 * Complete the divisors function below.
 */
int divisors(int n) {
    vector<int> exp = exp_divisors (n);
    if (exp.empty())
        return 0;
    else {
        int ans = exp[0];
		for (int i = 1; i < exp.size(); i++) {
			// printf ("  %d: %d\n", n, ans);
            ans *= exp[i]+1;
		}
		// printf ("%d: %d\n", n, ans);
        return ans;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    eratosthenes_sieve ();
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = divisors(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
