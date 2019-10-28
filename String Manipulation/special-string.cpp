#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    vector< int > prev( n ), next( n );
    long long ans = 1;
    prev[ 0 ] = 1;
    for( int i = 1; i < n; i++ ) {
        if( s[ i ] == s[ i - 1 ] ) prev[ i ] = prev[ i - 1 ] + 1;
        else prev[ i ] = 1;
        ans += prev[ i ];
    }
    next[ n - 1 ] = 1;
    for( int i = n - 2; i >= 0; i-- ) {
        if( s[ i ] == s[ i + 1 ] ) next[ i ] = next[ i + 1 ] + 1;
        else next[ i ] = 1;
    }
    for( int i = 1; i < n - 1; i++ ) {
        if( s[ i - 1 ] == s[ i + 1 ] && s[ i ] != s[ i - 1 ] ) {
            long long val = min( prev[ i - 1 ], next[ i + 1 ] );
            ans += val * val;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

