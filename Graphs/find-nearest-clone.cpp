#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */

int bfs( vector< int > *G, vector< long > colors, int N, int color ) {
    int ans = N + 1;
    vector< int > visited( N + 1 ), dist( N + 1 ), par( N + 1 );
    queue< int > Q;
    for( int i = 1; i <= N; i++ ) {
        if( colors[ i - 1 ] == color ) {
            Q.push( i );
            visited[ i ] = true;
            par[ i ] = -1;
        }
    }
    if( Q.size() < 2 ) return -1;
    while( !Q.empty() ) {
        int u = Q.front();
        Q.pop();
        for( int neigh : G[ u ] ) {
            if( !visited[ neigh ] ) {
                visited[ neigh ] = true;
                dist[ neigh ] = dist[ u ] + 1;
                Q.push( neigh );
            }
        }
    }
    for( int i = 1; i <= N; i++ ) {
        for( int u : G[ i ] ) {
            if( colors[ u - 1 ] == color && colors[ i - 1 ] == color ) return 1;
            else if( colors[ u - 1 ] == color || colors[ i - 1 ] == color ) continue;
            ans = min( ans, dist[ i ] + dist[ u ] + 1 );
        }
    }
    return ans;
}
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    int N = graph_nodes;
    vector< int > G[ N + 1 ];
    for( int i = 0; i < graph_from.size(); i++ ) {
        G[ graph_from[ i ] ].push_back( graph_to[ i ] );
        G[ graph_to[ i ] ].push_back( graph_from[ i ] );
    }
    int ans = bfs( G, ids, N, val );
    if( ans == N + 1 ) return -1;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

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

