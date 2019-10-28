#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.

int check_median( multiset< int >& half_expenses, int cur, int d ) {
    if( d & 1 ) {
        int median = *half_expenses.begin();
        return cur >= 2*median;
    } else {
        auto it = half_expenses.begin();
        int twice_median = *it;
        it++;
        twice_median += *it;
        return cur >= twice_median;
    }
}

int activityNotifications(vector<int> expenditure, int d) {
    int ans = 0, n = expenditure.size();
    multiset< int > half_expenses;
    for( int i = 0; i < d; i++ ) half_expenses.insert( expenditure[ i ] );
    for( int i = 0; i < ( d + 1 ) / 2 - 1; i++ ) half_expenses.erase( half_expenses.begin() );
    for( int i = d; i < n; i++ ) {
        ans += check_median( half_expenses, expenditure[ i ], d );
        half_expenses.insert( expenditure[ i ] );
        half_expenses.erase( half_expenses.begin() );
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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

