#include <bits/stdc++.h>

using namespace std;

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    bool** is_same;
    int n1 = a.length(), n2 = b.length();
    is_same = new bool*[ n1 ];
    for( int i = 0; i < n1; i++ ) {
        is_same[ i ] = new bool[ n2 ];
    }
    bool flag = false;
    is_same[ 0 ][ 0 ] = ( toupper( a[ 0 ] ) == b[ 0 ] );
    flag = ( a[ 0 ] == b[ 0 ] );
    for( int i = 1; i < n2; i++ ) is_same[ 0 ][ i ] = false;
    for( int i = 1; i < n1; i++ ) {
        if( isupper( a[ i ] ) ) {
            if( flag ) is_same[ i ][ 0 ] = false;
            else if( a[ i ] == b[ 0 ] ) {
                is_same[ i ][ 0 ] = true;
                flag = true;
            }
        } else {
            if( toupper( a[ i ] ) == b[ 0 ] && !flag ) {
                is_same[ i ][ 0 ] = true;
            } else {
                is_same[ i ][ 0 ] = is_same[ i - 1 ][ 0 ];
            }
        }
    }
    for( int i = 1; i < n1; i++ ) {
        for( int j = 1; j < n2; j++ ) {
            is_same[ i ][ j ] = false;
            if( toupper( a[ i ] ) == b[ j ] ) {
                is_same[ i ][ j ] = is_same[ i - 1 ][ j - 1 ];
            }
            if( islower( b[ j ] ) ) is_same[ i ][ j ] |= is_same[ i ][ j - 1 ];
            if( islower( a[ i ] ) ) is_same[ i ][ j ] |= is_same[ i - 1 ][ j ];
        }
    }
    return is_same[ n1 - 1 ][ n2 - 1 ] ? "YES": "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

