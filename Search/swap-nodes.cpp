#include <bits/stdc++.h>

using namespace std;

struct node {
    node( int v ) {
        idx = v;
        left = right = nullptr;
    }
    int idx;
    node* left, *right;
};

void perform_query( node* root, int curdepth, int k ) {
    if( root == nullptr ) return;
    else if( curdepth % k == 0 ) swap( root->left, root->right );
    perform_query( root->left, curdepth + 1, k );
    perform_query( root->right, curdepth + 1, k );
}

void inorder_traversal( node* root, vector< int >& acc ) {
    if( root == nullptr ) return;
    inorder_traversal( root->left, acc );
    acc.push_back( root->idx );
    inorder_traversal( root->right, acc );
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    int n = indexes.size();
    node* root;
    root = new node( 1 );
    node* mapping[ n + 1 ];
    for( int i = 1; i <= n; i++ ) mapping[ i ] = new node( i );
    for( int i = 1; i <= n; i++ ) {
        vector< int > idx = indexes[ i - 1 ];
        int l = idx[ 0 ], r = idx[ 1 ];
        if( l != -1 ) {
            mapping[ i ]->left = mapping[ l ];
        }
        if( r != -1 ) {
            mapping[ i ]->right = mapping[ r ];
        }
    }
    vector< vector< int > > ans;
    root = mapping[ 1 ];
    for( int q : queries ) {
        perform_query( root, 1, q );
        vector< int > res;
        inorder_traversal( root, res );
        ans.push_back( res );
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
