#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int get_sum( vector< vector< int > >& arr, int c_i, int c_j ) {
    int val = arr[ c_i ][ c_j ];
    for( int i = c_j - 1; i <= c_j + 1; i++ ) {
        val += arr[ c_i - 1 ][ i ] + arr[ c_i + 1 ][ i ];
    }
    return val;
}

int hourglassSum(vector<vector<int>> arr) {
    int max_hourglass = INT_MIN;
    for( int i = 1; i < arr.size() - 1; i++ ) {
        for( int j = 1; j < arr[ i ].size() - 1; j++ ) {
            max_hourglass = max( max_hourglass, get_sum( arr, i, j ) );
        }
    }
    return max_hourglass;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

