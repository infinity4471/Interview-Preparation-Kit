#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class node {
    public:
        node() {
            children.resize( 2, nullptr );
        }
        ~node() {
            delete children[ 0 ];
            delete children[ 1 ];
        }
        friend class binary_trie;
    private:
        vector< node* > children;
};
class binary_trie {
    public:
        binary_trie() {
            root = new node;
        }
        void insert( int val ) {
            node* current = root;
            for( int b = 30; b >= 0; b-- ) {
                int valbit = val & ( 1 << b );
                if( valbit ) valbit = 1;
                if( current->children[ valbit ] == nullptr ) {
                    current->children[ valbit ] = new node;
                }
                current = current->children[ valbit ];
            }
        }
        int getmax( int query ) {
            int maxans = 0;
            node* current = root;
            for( int b = 30; b >= 0; b-- ) {
                int querybit = query & ( 1 << b );
                if( querybit ) querybit = 1;
                if( current->children[ 1 ^ querybit ] != nullptr ) {
                    current = current->children[ 1 ^ querybit ];
                    maxans |= ( 1 << b );
                } else {
                    current = current->children[ querybit ];
                }
            }
            return maxans;
        }
    private:
        node* root;
};
vector<int> maxXor(vector<int> arr, vector<int> queries) {
    binary_trie T;
    vector< int > res;
    for( int val : arr ) {
        T.insert( val );
    }
    for( int q : queries ) {
        int ans = T.getmax( q );
        res.push_back( ans );
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

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(m);

    for (int i = 0; i < m; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<int> result = maxXor(arr, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
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

