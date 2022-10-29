#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 79. Word Search

struct Position {
  Position(int row_, int col_) : row(row_), col(col_) {}
  int row;
  int col;
   bool operator < (const Position& other) const { return row < other.row && col < other.col; }
};

    static int pathRow[] = {0, 0, 1, -1,};
    static int pathCol[] = {1,-1, 0, 0};

class Solution {
    string word_to_search;
    set<Position> visited; 

    
public:
    bool foundUsingDFS(vector<vector<char>>& board, int position_x, int position_y, int index) {
      if (index >= word_to_search.size())
        return true;

      for (int i =0;i<4;i++) {
        int next_position_x = position_x + pathRow[i];
        int next_position_y = position_y + pathCol[i];

        if (next_position_x < 0 || next_position_x > board.size() || next_position_y < 0 || next_position_y > board[0].size())
          return false;

        auto position_to_find = Position(next_position_x, next_position_y);
        auto checked = visited.find(position_to_find);
        if (checked != visited.end())
          return false;

        visited.insert(Position(next_position_x, next_position_y));
        bool found = foundUsingDFS(board, next_position_x, next_position_y, word + board[next_position_x][next_position_y]);
        if (found)
          break;
        visited.erase(Position(next_position_x, next_position_y));

      }
      return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        word_to_search = word;
        for (int i = 0; i< board.size(); i++) {
          for (int j = 0; j< board[i].size(); j++) {
            if (foundUsingDFS(board, i, j, 0))
              return true;
          }
        }

      return false;
    }
};

int main() {
  Solution s;
   //[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
  vector<vector<char>> board{{'A','B','C','E'}, {'S','F','C','S'},{'A','D','E','E'}};
  string word = "ABCCED";
  std::cout << (s.exist(board, word) ? "ture": "false");
  return 0;
}
