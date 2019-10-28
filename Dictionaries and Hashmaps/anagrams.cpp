#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int res = 0;
    map< vector< int >, int > same_count;
    for( int i = 0; i < s.length(); i++ ) {
        vector< int > freq( 256 );
        for( int j = i; j < s.length(); j++ ) {
            freq[ s[ j ] ]++;
            res += same_count[ freq ];
            same_count[ freq ]++;
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

