#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long long ans = 0;
    int L = s.length();
    for( char c : s ) {
        if( c == 'a' ) ans++;
    }
    long long total = n / L, left = n % L;
    ans *= total;
    for( int i = 0; left > 0; i++, left-- ) {
        if( s[ i ] == 'a' ) ans++;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

