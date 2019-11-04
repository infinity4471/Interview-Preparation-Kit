#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long largestRectangle(vector<int> h) {
    long ans = 0;
    int n = h.size();
    vector< int > left( n ), right( n );
    stack< int > monotone_idx;
    left[ 0 ] = -1;
    monotone_idx.push( 0 );
    for( int i = 1; i < n; i++ ) {
        while( !monotone_idx.empty() && h[ monotone_idx.top() ] >= h[ i ] ) {
            monotone_idx.pop();
        }
        if( !monotone_idx.empty() ) left[ i ] = monotone_idx.top();
        else left[ i ] = -1;
        monotone_idx.push( i );
    }
    while( !monotone_idx.empty() ) monotone_idx.pop();
    right[ n - 1 ] = n;
    monotone_idx.push( n - 1 );
    for( int i = n - 2; i >= 0; i-- ) {
        while( !monotone_idx.empty() && h[ monotone_idx.top() ] >= h[ i ] ) {
            monotone_idx.pop();
        }
        if( !monotone_idx.empty() ) right[ i ] = monotone_idx.top();
        else right[ i ] = n;
        monotone_idx.push( i );
    }
    for( int i = 0; i < n; i++ ) {
        long cur_ans = ( long )h[ i ] * ( long )( right[ i ] - left[ i ] - 1 );
        ans = max( ans, cur_ans );
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

