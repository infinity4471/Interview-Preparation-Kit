#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    int** lcs = new int*[ 2 ];
    for( int i = 0; i < 2; i++ ) {
        lcs[ i ] = new int[ n2 ];
    }
    //Base case
    lcs[ 0 ][ 0 ] = ( s1[ 0 ] == s2[ 0 ] );
    for( int j = 1; j < n2; j++ ) {
        lcs[ 0 ][ j ] = lcs[ 0 ][ j - 1 ] || ( s1[ 0 ] == s2[ j ] );
    }
    //dp calculation
    for( int i = 1; i < n1; i++ ) {
        for( int j = 0; j < n2; j++ ) {
            if( j == 0 ) {
                lcs[ i % 2 ][ j ] = ( s1[ i ] == s2[ j ] || lcs[ ( i - 1 ) % 2 ][ j ] );
            }
            else if( s1[ i ] == s2[ j ] ) {
                lcs[ i % 2 ][ j ] = 1 + lcs[ ( i - 1 ) % 2 ][ j - 1 ];
            } else {
                lcs[ i % 2 ][ j ] = max( lcs[ ( i - 1 ) % 2 ][ j ],
                                         lcs[ i % 2 ][ j - 1 ] );
            }
        }
    }
    return lcs[ ( n1 - 1 ) % 2 ][ n2 - 1 ];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}

