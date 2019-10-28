#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class DSU {
    public:
        DSU( int n ) {
            N = n;
            par = new int[ N ];
            forbidden = new bool[ N ];
            for( int i = 1; i <= N; i++ ) {
                forbidden[ i ] = 0;
                par[ i ] = i;
            }
        }
        int get( int u ) {
            u = find( u );
            return forbidden[ u ];
        }
        void set( int u ) {
            forbidden[ u ] = true;
        }
        int find( int u ) {
            if( par[ u ] == u ) return u;
            return par[ u ] = find( par[ u ] );
        }
        void Union( int u, int v ) {
            u = find( u );
            v = find( v );
            par[ v ] = u;
            forbidden[ u ] |= forbidden[ v ];
        }
    private:
        int* par, N;
        bool* forbidden;
};

int minTime(vector<vector<int>> roads, vector<int> machines) {
    int N = roads.size() + 1;
    vector< pair< int, pair< int, int > > > edges;
    DSU sets( N );
    int total = 0;
    for( vector< int > road : roads ) {
        edges.push_back( make_pair( road[ 2 ], make_pair( road[ 0 ], road[ 1 ] ) ) );
        total += road[ 2 ];
    }
    sort( edges.begin(), edges.end(), greater< pair< int, pair< int, int > > >() );
    for( int m : machines ) {
        sets.set( m );
    }
    for( auto edge : edges ) {
        int u = edge.second.first, v = edge.second.second, w = edge.first;
        if( sets.get( u ) && sets.get( v ) ) continue;
        else if( sets.find( u ) == sets.find( v ) ) continue;
        sets.Union( u, v );
        total -= w;
    }
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> roads(n - 1);
    for (int i = 0; i < n - 1; i++) {
        roads[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> roads[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> machines(k);

    for (int i = 0; i < k; i++) {
        int machines_item;
        cin >> machines_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        machines[i] = machines_item;
    }

    int result = minTime(roads, machines);

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

