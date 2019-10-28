#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Graph {
    public:
        Graph(int n) {
            G = new vector< int >[ n ];
            N = n;
        }

        void add_edge(int u, int v) {
            G[ u ].push_back( v );
            G[ v ].push_back( u );
        }

        vector<int> shortest_reach(int start) {
            vector< int > dist( N, -1 );
            queue< int > Q;
            Q.push( start );
            dist[ start ] = 0;
            while( !Q.empty() ) {
                int u = Q.front();
                Q.pop();
                for( int v : G[ u ] ) {
                    if( dist[ v ] == -1 ) {
                        dist[ v ] = dist[ u ] + 1;
                        Q.push( v );
                    }
                }
            }
            vector< int > res;
            for( int i = 0; i < N; i++ ) {
                if( i == start ) continue;
                if( dist[ i ] != -1 ) dist[ i ] *= 6;
                res.push_back( dist[ i ] );
            }
            return dist;
        }
    private:
        int N;
        vector< int >* G;

};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}


