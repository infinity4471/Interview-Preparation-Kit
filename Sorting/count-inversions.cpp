#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the countInversions function below.
long count_merge( vector< int >& arr ) {
    int n = arr.size();
    if( n == 1 ) return 0;
    vector< int > first_half, second_half;
    for( int i = 0; i < n / 2; i++ ) first_half.push_back( arr[ i ] );
    for( int i = n / 2; i < n; i++ ) second_half.push_back( arr[ i ] );
    long val = count_merge( first_half ) + count_merge( second_half );
    int i1, i2;
    arr.clear();
    for( i1 = 0, i2 = 0; i1 < first_half.size() && i2 < second_half.size(); ) {
        if( first_half[ i1 ] <= second_half[ i2 ] ) {
            arr.push_back( first_half[ i1++ ] );
        } else {
            arr.push_back( second_half[ i2++ ] );
            val += ( long )( first_half.size() - i1 );
        }
    }
    while( i1 < first_half.size() ) arr.push_back( first_half[ i1++ ] );
    while( i2 < second_half.size() ) arr.push_back( second_half[ i2++ ] );
    return val;
}

bool is_sorted( vector< int > arr ) {
    for( int i = 1; i < arr.size(); i++ ) {
        if( arr[ i ] < arr[ i - 1 ] ) return false;
    }
    return true;
}

long countInversions(vector<int> arr) {
    return count_merge( arr );
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

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

