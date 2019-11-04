#include <bits/stdc++.h>

using namespace std;

// Complete the stepPerms function below.

int stepPerms(int n) {
    const long MOD = 1e10+7;
    long dp[ n ];
    dp[ 0 ] = 1, dp[ 1 ] = 2, dp[ 2 ] = 4;
    for( int i = 3; i < n; i++ ) {
        dp[ i ] = ( dp[ i - 1 ] + dp[ i - 2 ] + dp[ i - 3 ] ) % MOD;
    }
    return dp[ n - 1 ];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
