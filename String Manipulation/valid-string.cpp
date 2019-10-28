#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    vector< int > freq( 256 );
    for( char c : s ) freq[ c ]++;
    for( char c = 'a'; c <= 'z'; c++ ) {
        if( !freq[ c ] ) continue;
        unordered_map< int, int > count_maps;
        freq[ c ]--;
        for( char c = 'a'; c <= 'z'; c++ ) {
            if( !freq[ c ] ) continue;
            count_maps[ freq[ c ] ]++;
        }
        if( count_maps.size() <= 1 ) return "YES";
        freq[ c ]++;
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

