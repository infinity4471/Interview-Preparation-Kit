#include <bits/stdc++.h>

using namespace std;

// Complete the maxRegion function below.

void dfs( int i, int j, int N, int M, vector< vector< int > >& grid,
            vector< vector< int > >& visited, int& ans ) {
    if( i < 0 || j < 0 || i >= N || j >= M ||
        visited[ i ][ j ] || !grid[ i ][ j ] ) return;
    visited[ i ][ j ] = true;
    ans++;
    for( int b1 = -1; b1 <= 1; b1++ ) {
        for( int b2 = -1; b2 <= 1; b2++ ) {
            dfs( i + b1, j + b2, N, M, grid, visited, ans );
        }
    }
}

int maxRegion(vector<vector<int>> grid) {
    int N = grid.size(), M = grid[ 0 ].size(), ans = 0;
    vector< vector< int > > visited( N );
    for( int i = 0; i < N; i++ ) {
        visited[ i ].resize( M, 0 );
    }
    for( int i = 0; i < N; i++ ) {
        for( int j = 0; j < M; j++ ) {
            int val = 0;
            dfs( i, j, N, M, grid, visited, val );
            ans = max( ans, val );

        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    fout.close();

    return 0;
}

