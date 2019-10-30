#include <bits/stdc++.h>

using namespace std;

// Complete the maxMin function below.
int unfairness( multiset< int >& S ) {
    auto it_beg = S.begin(), it_end = S.end();
    it_end--;
    return *it_end - *it_beg;
}

int maxMin(int k, vector<int> arr) {
    int n = arr.size();
    sort( arr.begin(), arr.end() );
    multiset< int > S;
    for( int i = 0; i < k; i++ ) S.insert( arr[ i ] );
    int ans = unfairness( S );
    for( int i = k; i < n; i++ ) {
        S.insert( arr[ i ] );
        S.erase( S.find( arr[ i - k ] ) );
        ans = min( ans, unfairness( S ) );
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

