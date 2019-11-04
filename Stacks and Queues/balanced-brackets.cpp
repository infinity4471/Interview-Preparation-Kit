#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    vector< int > trans;
    stack< int > S;
    for( char c : s ) {
        int v;
        switch( c ) {
            case '(': v = 1; break;
            case ')': v = -1; break;
            case '{': v = 2; break;
            case '}': v = -2; break;
            case '[': v = 3; break;
            case ']': v = -3; break;
        }
        trans.push_back( v );
    }
    for( int v : trans ) {
        if( v > 0 ) S.push( v );
        else if( S.empty() || S.top() != -v ) return "NO";
        else S.pop();
    }
    if( S.empty() ) return "YES";
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
