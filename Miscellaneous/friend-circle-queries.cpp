#include <bits/stdc++.h>

using namespace std;

// Complete the maxCircle function below.

class DSU {
    public:
        void init( int u ) {
            if( visited[ u ] ) return;
            visited[ u ] = true;
            par[ u ] = u;
            size[ u ] = 1;
        }
        int get_max() {
            return max_size;
        }
        int find( int u ) {
            if( u == par[ u ] ) return u;
            return par[ u ] = find( par[ u ] );
        }
        void Union( int u, int v ) {
            u = find( u );
            v = find( v );
            if( u == v ) return;

            par[ u ] = v;
            size[ v ] += size[ u ];
            max_size = max( max_size, size[ v ] );
        }

    private:
        int max_size;
        unordered_map< int, int > par, size, visited;
};

vector<int> maxCircle(vector<vector<int>> queries) {
    vector< int > ans;
    int n = queries.size();
    DSU circles;
    for( auto q : queries ) {
        circles.init( q[ 0 ] );
        circles.init( q[ 1 ] );
        circles.Union( q[ 0 ], q[ 1 ] );
        ans.push_back( circles.get_max() );
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> ans = maxCircle(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

