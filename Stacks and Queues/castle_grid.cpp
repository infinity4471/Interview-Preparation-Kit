#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumMoves function below.

void check( queue< pair< int, int > >& Q, vector< vector< int > >& dist,
            pair< int, int > cur, int mydist ) {
    if( dist[ cur.first ][ cur.second ] != -1 ) return;
    dist[ cur.first ][ cur.second ] = mydist;
    Q.push( cur );
}

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int n = grid.size();
    vector< vector< int > > dist;
    dist.resize( n );
    for( int i = 0; i < n; i++ ) {
        dist[ i ].resize( n, -1 );
    }
    queue< pair< int, int > > Q;
    Q.push( make_pair( startX, startY ) );
    dist[ startX ][ startY ] = 0;
    while( !Q.empty() ) {
        pair< int, int > pos = Q.front();
        Q.pop();
        for( int i = pos.first; i < n; i++ ) {
            if( grid[ i ][ pos.second ] == 'X' ) break;
            check( Q, dist, make_pair( i, pos.second ),
            dist[ pos.first ][ pos.second ] + 1 );
        }
        for( int i = pos.first; i >= 0; i-- ) {
            if( grid[ i ][ pos.second ] == 'X' ) break;
            check( Q, dist, make_pair( i, pos.second ),
            dist[ pos.first ][ pos.second ] + 1 );
        }
        for( int i = pos.second; i < n; i++ ) {
            if( grid[ pos.first ][ i ] == 'X' ) break;
            check( Q, dist, make_pair( pos.first, i ),
            dist[ pos.first ][ pos.second ] + 1 );
        }
        for( int i = pos.second; i >= 0; i-- ) {
            if( grid[ pos.first ][ i ] == 'X' ) break;
            check( Q, dist, make_pair( pos.first, i ),
            dist[ pos.first ][ pos.second ] + 1 );
        }
    }
    return dist[ goalX ][ goalY ];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

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

