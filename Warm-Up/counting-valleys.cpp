#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int sum = 0, prev = 0, valeys = 0;
    for( char c : s ) {
        if( c == 'U' ) sum++;
        else sum--;
        if( prev >= 0 && sum < 0 ) valeys++;
        prev = sum;
    }
    return valeys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

