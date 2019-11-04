#include <bits/stdc++.h>

using namespace std;

// Complete the crosswordPuzzle function below.

vector< string > parse( string words ) {
    string item;
    vector< string > res;
    for( char c : words ) {
        if( c == ';' ) {
            res.push_back( item );
            item.clear();
        } else {
            item += c;
        }
    }
    res.push_back( item );
    return res;
}

bool solve_cross( vector< string >& crossword, vector< string > words, int n = 10 ) {
    if( words.empty() ) return true;
    int sz = words.size();
    string cur_word = words[ sz - 1 ];
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            //fit horizontal
            bool valid = true;
            for( int k = 0; k < cur_word.size(); k++ ) {
                if( j + k >= n ) {
                    valid = false;
                    break;
                }
                if( crossword[ i ][ j + k ] == '-' ||
                    crossword[ i ][ j + k ] == cur_word[ k ] ) continue;
                valid = false;
                break;
            }
            if( valid ) {
                string prev_state;
                for( int k = 0; k < cur_word.size(); k++ ) {
                    prev_state += crossword[ i ][ j + k ];
                    crossword[ i ][ j + k ] = cur_word[ k ];
                }
                words.erase( words.begin() + sz - 1 );
                if( solve_cross( crossword, words ) ) return true;
                words.push_back( cur_word );
                for( int k = 0; k < cur_word.size(); k++ ) {
                    crossword[ i ][ j + k ] = prev_state[ k ];
                }
            }
            //fit vertical
            valid = true;
            for( int k = 0; k < cur_word.size(); k++ ) {
                if( i + k >= n ) {
                    valid = false;
                    break;
                }
                if( crossword[ i + k ][ j ] == '-' ||
                    crossword[ i + k ][ j ] == cur_word[ k ] ) continue;
                valid = false;
                break;
            }
            if( valid ) {
                string prev_state;
                for( int k = 0; k < cur_word.size(); k++ ) {
                    prev_state += crossword[ i + k ][ j ];
                    crossword[ i + k ][ j ] = cur_word[ k ];
                }
                words.erase( words.begin() + sz - 1 );
                if( solve_cross( crossword, words ) ) return true;
                words.push_back( cur_word );
                for( int k = 0; k < cur_word.size(); k++ ) {
                    crossword[ i + k ][ j ] = prev_state[ k ];
                }
            }
        }
    }
    return false;
}

vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    vector< string > all_words = parse( words );
    random_shuffle( all_words.begin(), all_words.end() );
    solve_cross( crossword, all_words );
    return crossword;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

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
