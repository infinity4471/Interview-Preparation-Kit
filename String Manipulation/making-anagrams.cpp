#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int count_chars[ 256 ] = { 0 };
    for( char c : a ) count_chars[ c ]++;
    for( char c : b ) count_chars[ c ]--;
    int ans = 0;
    for( int c = 'a'; c <= 'z'; c++ ) {
        ans += abs( count_chars[ c ] );
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

