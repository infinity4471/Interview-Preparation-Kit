#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the riddle function below.
vector<long> riddle(vector<long> arr) {
    int n = arr.size();
    long right[ n ], left[ n ], cur_max = 0;
    vector< long > max_range( n + 1 ), res( n );
    stack< pair< long, int > > S;
    for( int i = 0; i < n; i++ ) {
        left[ i ] = 0;
        while( !S.empty() && S.top().first >= arr[ i ] ) S.pop();
        if( !S.empty() ) left[ i ] = S.top().second + 1;
        S.push( { arr[ i ], i } );
    }
    while( !S.empty() ) S.pop();
    for( int i = n - 1; i >= 0; i-- ) {
        right[ i ] = n - 1;
        while( !S.empty() && S.top().first >= arr[ i ] ) S.pop();
        if( !S.empty() ) right[ i ] = S.top().second - 1;
        S.push( { arr[ i ], i } );
    }
    for( int i = 0; i < n; i++ ) {
        int sz = right[ i ] - left[ i ] + 1;
        max_range[ sz ] = max( max_range[ sz ], arr[ i ] );
    }
    for( int i = n; i > 0; i-- ) {
        cur_max = max( cur_max, max_range[ i ] );
        res[ i - 1 ] = cur_max;
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
