#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <queue>

using namespace std;

// 79. Word Search

/*
struct Position {
  Position(int row_, int col_) : row(row_), col(col_) {}
  int row;
  int col;
   bool operator < (const Position& other) const { return row < other.row && col < other.col; }
};

    static int pathRow[] = {0, 0, 1, -1,};
    static int pathCol[] = {1,-1, 0, 0};
  vector<vector<bool>> cache{{false,false,false}, {false,false,false}, {false,false,false}};

class Solution {
    string word_to_search;
    set<Position> visited; 

    
public:
    bool foundUsingDFS(vector<vector<char>>& board, int position_x, int position_y, string word) {
      if (word == word_to_search)
        return true;

      for (int i =0;i<4;i++) {
        int next_position_x = position_x + pathRow[i];
        int next_position_y = position_y + pathCol[i];

        if (next_position_x < 0 || next_position_x >= board.size() || next_position_y < 0 || next_position_y >= board[0].size())
          return false;

        //std::cout << "X " << next_position_x << std::endl;
        //std::cout << "Y " << next_position_y << std::endl;
        //
        if (cache[next_position_x][next_position_y])
          return false;

        cache[next_position_x][next_position_y] = true;
        string search_word = word + board[next_position_x][next_position_y];
        std::cout << "X " << next_position_x << std::endl;
        std::cout << "Y " << next_position_y << std::endl;
        std::cout << "WOOR TO SEACRH : " << search_word<< std::endl;
        bool found = foundUsingDFS(board, next_position_x, next_position_y, search_word);
        if (found)
          return true;
        cache[next_position_x][next_position_y] = false;

      }
      return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        word_to_search = word;
        for (int i = 0; i< board.size(); i++) {
          for (int j = 0; j< board[i].size(); j++) {
            if (board[i][j] == word[0]) {
            if (foundUsingDFS(board, i, j, "A"))
              return true;
            }
          }
        }

      return false;
    }
};

int main() {
  Solution s;
   //[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
  vector<vector<char>> board{{'A','B','C'}, {'S','F','C'},{'A','D','E'}};
  string word = "AS";
  std::cout << (s.exist(board, word) ? "ture": "false");
  return 0;
}
*/


/*
struct {
bool operator()(string& left, string& right) const {
      // sort by contents.
      // sort by their identifier.
      //
      size_t index = left.find(' ');
      string content_left = left.substr(index+1);

      size_t right_index = right.find(' ');
      string content_right = right.substr(right_index+1);

      if (content_left == content_right) {
        string identifier_left = left.substr(0, index); 
        string identifier_right = right.substr(0, right_index); 
        return identifier_left < identifier_right;
      }
      return content_left < content_right;
};

} mycomparator;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
      std::vector<string> digit_logs;
      std::vector<string> letter_logs;
      for (string log : logs) {
        size_t index = log.find(' ');
        if (log[index+1] >= '0' && log.at(index+1) <= '9') {
          digit_logs.push_back(log);
        } else {
          letter_logs.push_back(log);
        }
      }


      std::sort(letter_logs.begin(), letter_logs.end(), mycomparator);


      for (auto single: digit_logs) {
        letter_logs.push_back(single);
      }
      return letter_logs;
    }
};

int main() {
  Solution s;

  std::vector<string> input{"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
  auto out = s.reorderLogFiles(input);
  for (auto a : out) {
    std::cout << a << std::endl;
  }
  return 0;
}
*/

// 1268. Search Suggestions System

/*
class Trie {
public:
  struct Node {
    bool isWord = false;
    vector<Node*> children{vector<Node*>(26,nullptr)};
  };

  Node* Root;
  Node* curr;

  Trie() {
    Root = new Node();
  }

    void insert(string & s) {
        // Points curr to the root of trie.
        curr = Root;

        for (char &c : s) {
            // if not exist.
            if (!curr->children[c - 'a'])
                curr->children[c - 'a'] = new Node();
            curr = curr->children[c - 'a'];
        }

        // Mark this node as a completed word.
        curr->isWord = true;
    }

    void dfsWithPrefix(Node * curr, string & word, vector<string> & result) {
        if (result.size() == 3)
            return;
        if (curr->isWord)
            result.push_back(word);

        // Run DFS on all possible paths.
        for (char c = 'a'; c <= 'z'; c++)
            if (curr->children[c - 'a']) {
                word += c;
                dfsWithPrefix(curr->children[c - 'a'], word, result);
                word.pop_back();
            }
    }

    vector<string> getWordsStartingWith(string & prefix) {
        curr = Root;
        vector<string> result;

        // Move curr to the end of prefix in its trie representation.
        for (char &c : prefix) {
            if (!curr->children[c - 'a'])
                return result;
            curr = curr->children[c - 'a'];
        }
        dfsWithPrefix(curr, prefix, result);
        return result;
    }

private:
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
    }
};
*/

// 146. LRU Cache.
// Point is we need to clear cache in both get/put.

/*
class LRUCache {
private:
    int capacity_;

    map<int, int> cache_;

    // this queue maitain the last used keys.
    // first(oldest one), last(newest one)
    deque<int> lru_list_;

public:
    LRUCache(int capacity) {
      capacity_ = capacity;
    }
    
    int get(int key) {
      auto found = cache_.find(key);
      if (found == cache_.end()) {
        return -1;
      }
      if (lru_list_.size() == capacity_) {
        lru_list_.push_back(key);
        int front = lru_list_.front();
        lru_list_.pop_front();
        if (front != key) {
          cache_.erase(key);
        }
      }
      return found->second;
    }
    
    // Update if exist.
    // Add key-value
    // if keys exceeds the capacity. evict the LRU
    void put(int key, int value) {
      cache_[key] = value;
      if (lru_list_.size() != 0 && lru_list_.back() == key) {
        return;
      }

      if (lru_list_.size() == capacity_) {
        int oldest_one = lru_list_.front();
        lru_list_.pop_front();
        // this is the point.
        if (oldest_one != key) {
          cache_.erase(oldest_one);
        }
      }
      lru_list_.push_back(key);
    }

    void printCache() {
      std::cout << "---------" << std::endl;
        std::cout << "Size: " << cache_.size() << " : capa : " << capacity_ << std::endl;
        for (auto a : cache_) {
          std::cout << "Key: " << a.first << " value: " << a.second << std::endl;
        }
        std::cout << "Queue : ";
        for (auto a : lru_list_) {
          std::cout << a << " - ";
        }
        std::cout << std::endl;
    }
};


// ["LRUCache","get","put","get","put","put","get","get"]
// [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
int main() {
LRUCache lRUCache = LRUCache(2);
std::cout << lRUCache.get(2) << std::endl;
lRUCache.printCache();
lRUCache.put(2, 6); // cache is {1=1, 2=2}
lRUCache.printCache();
std::cout << lRUCache.get(1) << std::endl;
lRUCache.printCache();
lRUCache.put(1, 5); // cache is {1=1, 2=2}
lRUCache.printCache();
lRUCache.put(1, 2); // cache is {1=1, 2=2}
lRUCache.printCache();
lRUCache.put(4, 1); // cache is {1=1, 2=2}
lRUCache.printCache();

lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.printCache();
std::cout << "not found " << std::endl;
std::cout << lRUCache.get(2);    // returns -1 (not found)
lRUCache.printCache();
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
std::cout << lRUCache.get(1);    // return -1 (not found)
std::cout << lRUCache.get(3);    // return 3
std::cout << lRUCache.get(4);    // return 4
  return 0;
}
*/

// 200. Number of Islands
/*
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int start_x, int start_y) {
      grid[start_x][start_y] = '0';
      // check boundary
      if (start_x - 1 > 0 && grid[start_x-1][start_y] != 0) {
        dfs(grid, start_x-1, start_y);
      }
      if (start_x + 1 < grid.size() && grid[start_x-1][start_y] != 0) {
        dfs(grid, start_x+1, start_y);
      }
      if (start_y -1 > 0 && grid[start_x][start_y-1] != 0) {
        dfs(grid, start_x, start_y-1);
      }
    }

    int numIslands(vector<vector<char>>& grid) {
      int num = 0;
      for (int i = 0; i < grid.size(); i++) { // size 
        for(int j=0;j<grid[0].size();j++) {
            if (grid[i][j] ==  '1') {
               num++; 
// x, y
              dfs(grid, i, j);
            }
        }
      }
    }
};

int main() {
  std::vector<vector<char>> grid;
  std::vector<char> a{'1','1','0','0','0'};
  grid.push_back(a);
  std::vector<char> b{'1','1','0','0','0'};
  grid.push_back(b);
  std::vector<char> c{'1','1','0','0','0'};
  grid.push_back(c);
  std::vector<char> d{'1','1','0','0','0'};
  grid.push_back(d);
Solution s;
std::cout << s.numIslands(grid) << std::endl;
  return 0;
}
*/

// inorder traversal
//

struct Node {
    int data;
    struct Node *left, *right;
};
 
//Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

std::vector<int> BFS(Node* root) {
  std::vector<int> ret;

  std::vector<Node*> frontiner;
  frontiner.push_back(root);
  std::map<Node*, int> level;
  std::map<Node*, Node*> parent;

  level[root] = 0;
  int ia  = 0;
  while (!frontiner.empty()) {
    std::vector<Node*> next;
    for (Node* single : frontiner) {
      if (single->left) {
         next.push_back(single->left);
      }
      if (single->right) {
         next.push_back(single->right);
      }
    }
    frontiner = next;
    ia++;
  }

  return ret;
}

int main() {
return 0;
}
