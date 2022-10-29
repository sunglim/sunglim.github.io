#include <iostream>
#include <utility>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <sstream>
#include <numeric>
#include <ctype.h>

using namespace std;

// 1268. Search Suggestion System
// searchWordㄹㄹ 기ㄴㅡ로 products에서 suggestion을 구현
/*
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
         sort(products.begin(), products.end());
        vector<vector<string>> result;
        int bsStart = 0, n=products.size();
        string prefix;
   //     for (char &c : searchWord) {
            prefix += "mon";

            // Get the starting index of word starting with `prefix`.
            auto start = lower_bound(products.begin() + bsStart, products.end(), prefix) - products.begin();
            //auto start = lower_bound(products.begin() + bsStart, products.end(), prefix);
            std::cout << "prefix:" << prefix << std::endl;
            std::cout << start << std::endl;

            // Add empty vector to result.
            result.push_back({});

            // Add the words with the same prefix to the result.
            // Loop runs until `i` reaches the end of input or 3 times or till the
            // prefix is same for `products[i]` Whichever comes first.
            //for (int i = start; i < min(start + 3, n) && !products[i].compare(0, prefix.length(), prefix); i++)
            //    result.back().push_back(products[i]);

            // Reduce the size of elements to binary search on since we know
            //bsStart = start;
        //}
        return result;
    
    }
};
*/
/*
class Trie
{
    // Node definition of a trie
    struct Node {
        bool isWord = false;
        vector<Node *> children{vector<Node *>(26, NULL)};
    } * Root, *curr;

    // Runs a DFS on trie starting with given prefix and adds all the words in the result, limiting result size to 3
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

public:
    Trie() {
        Root = new Node();
    }
    // Inserts the string in trie.
    void insert(string & s) {
        // Points curr to the root of trie.
        curr = Root;
        for (char &c : s) {
            if (!curr->children[c - 'a'])
                curr->children[c - 'a'] = new Node();
            curr = curr->children[c - 'a'];
        }
        // Mark this node as a completed word.
        curr->isWord = true;
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
};
*/

/*
int main() {
    vector<string> nike;
    nike.push_back("x");
    nike.push_back("mobile");
    nike.push_back("mouse");
    nike.push_back("moneypot");
    nike.push_back("monitor");
    nike.push_back("mousepad");

    Solution sol;
    auto result = sol.suggestedProducts(nike, "mouse");

    for (auto a: result) {
        for (auto b: a) {
            std::cout << " " << b;
        }
        std::cout << endl;
    }
    
    return 0;
}
*/

/*
//370. Range Addition
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result;
        for (int i=0;i<length;i++) {
            result.push_back(0);
        }

        for (auto& singlearray : updates) {
            int start = singlearray[0];
            int end = singlearray[1];
            for (int i = start;i<=end;i++) {
                result[i] += singlearray[2];
            }
        }
        return result;
    }
};

int main () {

    //length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
    Solution s;
    vector<vector<int>> a;
    a.push_back({});
    a.back().push_back(1);
    a.back().push_back(3);
    a.back().push_back(2);
    a.push_back({});
    a.back().push_back(2);
    a.back().push_back(4);
    a.back().push_back(3);
    a.push_back({});
    a.back().push_back(0);
    a.back().push_back(2);
    a.back().push_back(-2);
    auto modified = s.getModifiedArray(5, a);
    for (auto c: modified) {
        std::cout << " " << c;
    }

    return 0;
}
*/

/*
bool compareByLength(const vector<int> &a, const vector<int> &b)
{
    return a[1] > b[1];
}

// 1710. Maximum Units on a Truck
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        std::sort(boxTypes.begin(), boxTypes.end(), compareByLength);

        // boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
        // order with second.

        int currentstack = 0;
        int total = 0;
        for (auto& boxtype : boxTypes) {
            if (currentstack + boxtype[0] <= truckSize) {
                currentstack += boxtype[0];
                total += boxtype[0] * boxtype[1];
                continue;
            } else {
                int addnum = truckSize - currentstack;
                total += boxtype[1] * addnum;
                break;
            }
        }
        
        return total;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a;
    a.push_back({});
    a.back().push_back(5);
    a.back().push_back(10);
    a.push_back({});
    a.back().push_back(2);
    a.back().push_back(5);
    a.push_back({});
    a.back().push_back(4);
    a.back().push_back(7);
    a.push_back({});
    a.back().push_back(3);
    a.back().push_back(9);
    std::cout << s.maximumUnits(a, 10);
  return 0;
}
*/

/*
// 696. Count Binary Substrings
class Solution {
public:
    int countBinarySubstrings(string s) {
        // build group
        char initial = s[0];
        vector<int> group;
        group.push_back(1);
        int groupnum = 1;
        for (int i = 1;i<s.length(); i++) {
            if (s[i-1] != s[i])
                group.push_back(1);
            else {
                group.back() += 1;
            }
        }

        int sum = 0;
        // min currnet group, next group is substring.
        for (int i = 0; i< group.size()-1;i++) {
            int groupsize = std::min(group[i], group[i+1]);
            sum += groupsize;
        }

        return sum;
    }
};

int main() {
    Solution s;
    std::cout << s.countBinarySubstrings("00110011") << std::endl;
    return 0;
}
*/

// 1152. Analyze User Website Visit Pattern
/*
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        // build map
        // user, timestamp, webstie
        // use map instead.
        std::unordered_map<string, unordered_map<int,string>> source;
        for (int i = 0;i<username.size();i++) {
            source[username[i]][timestamp[i]] = website[i];
        }    

         unordered_map<string, int> freq;
        int maxFreq = 0;

        for (auto kv: source)
        {
            std::unordered_set<string> S;
            // time stamp → website

            // just insert three website.
            unordered_map<int, string> twm = kv.second;
             for (auto i = twm.begin(); i != twm.end(); i++)
                for (auto j = next(i); j != twm.end(); j++)
                    for (auto k = next(j); k != twm.end(); k++)
                        S.insert(i->second + " " + j->second + " " + k->second);
            
            // get max frequent
            for (auto s:S)
                maxFreq = max(maxFreq, ++freq[s]);
        }

            // If there is more than one pattern with the same largest score, return the lexicographically smallest such pattern.
        string res;
        for (auto kv:freq)
        if (kv.second == maxFreq)
            res = res.empty() ? kv.first : min(kv.first, res);

        vector<string> resVec(3);
        istringstream ss(res);
        ss >> resVec[2] >> resVec[1] >> resVec[0];
        return resVec;
    }
};

int main() {

    return 0;
}
*/

/*
class Solution {
public:
    int kthFactor(int n, int k) {
        int order = 0;
        for (int i = 1;i<=n;i++) {
            if (n%i == 0) {
                ++order;
                if (order == k)
                    return i;
            }
        }
        return -1;   
    }
};

int main() {
    Solution s;
    std::cout << s.kthFactor(12,3);
  return 0;
}
*/

// 1151. Minimum Swaps to Group All 1's Together
// dequeue is another method to solve.
/*
class Solution {
public:
    int minSwaps(vector<int>& data) {
        // get number of 1.
        int sum = 0;
        for (auto single : data) {
            if (single == 1)
                sum++;
        }

        int cnt_one = 0;

        int left = 0;
        int right = 0;
        int max_one = 0;
        while (right < data.size()) {
            // if data[right] is 1. cnt_one is increasing.
            cnt_one += data[right++];

            // maintaining the window size.
            if (right - left > sum) {
                // updating the number of 1's by removing the oldest element
                cnt_one -= data[left++];
            }

            max_one = max(max_one, cnt_one);
        }

        // maximum 1 
        return sum - max_one;
    }
};
*/

// 926. Flip String to Monotone Increasing
/*
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        // prefix sum을 이용해서 푼다.
        // idea

        // Make all 1.
        // first 1
        // 
        // number of zeros  = total - first - number of ones

        // make all zero
        // if number of one is less than number 1.

        // has two half. left half(zero), right half(ones)
        
    }
};
*/

//937. Reorder Data in Log Files
/*
class Solution {
public:
    static bool isDigitlog(std::string& logs) {
        auto found = logs.find(' ');
        if (isdigit(logs[found + 1])) {
            return true;
        }
        return false;
    }

    static bool comparator(const string& left, const string& right) {
        auto leftfound = left.find(' ') + 1;
        auto rightfound = right.find(' ') + 1;

        if (left.substr(leftfound) == right.substr(rightfound)) {
           return left < right; 
        }

        return left.substr(leftfound) < right.substr(rightfound);
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        std::vector<string> digitlogs;
        std::vector<string> letterlogs;
        // separate digit log, letter log.
        for (auto& single: logs) {
            if (isDigitlog(single)) {
                digitlogs.push_back(single);
            } else {
                letterlogs.push_back(single);
            }

        }

        // for letter logs,
        // order by content,
        std::sort(letterlogs.begin(), letterlogs.end(), comparator);

        std::vector<string> result;
        result.insert(result.end(), letterlogs.begin(), letterlogs.end());

        result.insert(result.end(), digitlogs.begin(), digitlogs.end());
        return result;
        // if contents are same, order by identifier.
    }
};

int main() {
    // logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
    vector<string> logs{"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    Solution s;
    auto myvec = s.reorderLogFiles(logs);
    for (auto a : myvec)
        std::cout << a << std::endl;
    return 0;
}
*/


// 56. Merge Intervals
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
/*
class Solution {
public:
    static bool compareByLength(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), compareByLength);

        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); i++) {
            if (merged.empty() || merged.back()[1] < intervals[i][0]) {
                merged.push_back(intervals[i]);
            } else {
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            }
        }

        return merged;
    }
};

int main() {
    return 0;
}
*/

// 370. Range Addition

// Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
// Output: [-2,0,3,5,3]
// partial sum?

/*
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        std::vector<int> result(length);

        for (vector<int>& single: updates) {
            for (int i = single[0]; i<=single[1];i++) {
                result[i] += single[2];
            }
        }

        return result;
    }
};
*/
/*
//370. Range Addition
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        std::vector<int> result(length);
        // set start value. = updates[2]
        // set end value  end +1 -= updates[2]
        for (auto single: updates) {
            // single = [1,3,2]
            result[single[0]] += single[2];

            // length 5;
            // length -1 = 4;
            if (single[1] < length-1)
                result[single[1] + 1] -= single[2];
        }

        partial_sum(result.begin(), result.end(), result.begin());

        return result;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> val;
    val.push_back({});
    val.back().push_back(1);
    val.back().push_back(3);
    val.back().push_back(2);
    val.push_back({});
    val.back().push_back(2);
    val.back().push_back(4);
    val.back().push_back(3);
    val.push_back({});
    val.back().push_back(0);
    val.back().push_back(2);
    val.back().push_back(-2);
    auto result = s.getModifiedArray(5, val);
    for (auto single: result) {
        std::cout << single << " ";
    }
    std::cout << endl;
    return 0;
}
*/

// dfs
/* 
class Solution {
public:
  void dfs(vector<vector<char>>& grid, int r, int c) {
      // number of row
      int nr = grid.size();
      // number of column
      int nc = grid[0].size();

      // visited;
      grid[r][c] = '0';
      if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r-1, c);
      if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r+1, c);
      if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c-1);
      if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c+1);
  }
    int numIslands(vector<vector<char>>& grid) {
        // dfs until no one.
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_island = 0;
        for (int i = 0; i< nr;i++) {
            for (int j = 0; j<nc;j++) {
               if (grid[i][j] == '1') {
                    num_island++;
                    dfs(grid, i,j);
               }
            }
        }
       return num_island; 
    }
};

int main() {
    return 0;
}
*/

// 828. Count Unique Characters of All Substrings of a Given String
/*
int countUniqueChars(string s) {
    string copy = s;
    std::sort(copy.begin(), copy.end());
    std::cout << copy << std::endl;
    int count=0;
    for (int i=0;i<copy.size();i++) {
        if (i+1 < copy.size() && copy[i] == copy[i+1]) {
            continue;
        } 
        if (i-1 >= 0 && copy[i-1] == copy[i]) {
            continue;
        }
       count++; 
    }
    return count;
}

std::vector<string> printAllSubstrings(string s, int n)
{
    std::vector<string> result;
    for (int i = 0; i < n; i++)
    {
        char temp[n - i + 1];
        int tempindex = 0;
        for (int j = i; j < n; j++)
        {
            temp[tempindex++] = s[j];
            temp[tempindex] = '\0';
            result.push_back(temp);
        }
    }
    return result;
}

int main() {
    std::cout << countUniqueChars("ABA");
    auto a = printAllSubstrings("ABA", 3);
    int allcount =0;
    for (auto c:a) {
        allcount += countUniqueChars(c);
    }
    std::cout << allcount << std::endl;
    return 0;
}
*/

/*
class Solution {
public:
    static bool comparator(std::vector<int>& left, std::vector<int>& right) {
        return left[0] < right[0];
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        // Sort the given meetings by their start time.
        std::sort(intervals.begin(), intervals.end(), comparator);
        for (auto interval: intervals) {
            std::cout << interval[0] << "," << interval[1] << std::endl;
        }

        std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
        // add the end time of first item.
        pq.push(intervals[0][1]);


        for (int i = 1; i< intervals.size(); i++) {
            //std::cout << intervals[i][0] << " -- " << pq.top() << std::endl;
            if (intervals[i][0] >= pq.top()) {
                pq.pop();
            }

            pq.push(intervals[i][1]);
        }

        return pq.size();
    }
};

int main() {
    Solution s;
    //[[0,30],[5,10],[15,20]]
    std::vector<std::vector<int>> sam;
    sam.push_back({});
    sam.back().push_back(0);
    sam.back().push_back(30);
    sam.push_back({});
    sam.back().push_back(5);
    sam.back().push_back(10);
    sam.push_back({});
    sam.back().push_back(15);
    sam.back().push_back(20);
    std::cout << s.minMeetingRooms(sam) << std::endl;
    return 0;
}
*/

// 146. LRU Cache

/*
class LRUCache {
public:
    int capacity_;
    // a map contains result;
    std::map<int, int> hash;
    // a hash to keep interator of list.
    // list::erase need iterator.
    std::map<int, std::list<int>::iterator> iterator_hash;
    // a list that keeps insert/get order.
    // front incicate recently touched key.
    std::list<int> lru_list;
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        lru_list.erase(iterator_hash[key]);
        lru_list.push_front(key);
        iterator_hash[key] = lru_list.begin();
       return hash[key]; 
    }
    
    void put(int key, int value) {
        auto found = hash.find(key);
        if (found == hash.end()) {
            hash[key] = value;
            lru_list.push_front(key);
            iterator_hash[key] = lru_list.begin();

            if (hash.size() > capacity_) {
                int key_to_delete = lru_list.back();
                hash.erase(key_to_delete);
                iterator_hash.erase(key);
                lru_list.pop_back();
            }
        } else {
            // if already exist.
            hash[key] = value;
            // erase come first.
            lru_list.erase(iterator_hash[key]);
            lru_list.push_front(key);
            iterator_hash[key] = lru_list.begin();
        }
        
    }
};
int main() {
    return 0;
}
*/

/*
public class HeaviestPackage {
    public static int getHeaviestPackage(int[] packages){
        int n = packages.length-1;
        int ans = packages[n];
        int curSum = 0;
        for(int i = n-1; i >= 0; i--){
            if(packages[i] < packages[i+1]){
                packages[i] += packages[i+1];
                curSum = packages[i];
            }
            else{
                curSum = packages[i];
            }
            ans = Math.max(ans, curSum);
        }
        return ans;
    }
    public static void main(String[] args) {
        int[] packages = {2,9,10,3, 7};
        int ans = getHeaviestPackage(packages);
        System.out.println("Heaviest package is : "+ans);
    }
}
*/

/*
       if(packageWeights == null || packageWeights.length == 0){return 0;}
        int n = packageWeights.length;
        int prev = packageWeights[n-1];
        int max = prev;
        for(int i = n-2; i >= 0 ; i--){
            int curr = packageWeights[i];
            if(curr < prev){
                prev += curr;
            }else{
                prev = curr;
            }
            max = Math.max(prev, max);
        }
        return max;
        */

/*
long getHeaviestPakcage(vector<int> packageWeights) {
    if (packageWeights.size() == 0)
        return 0;

    const int n = packageWeights.size();
    int prev = packageWeights[n-1];
    int max = prev;

    for (int i = n - 2; i >= 0; i--) {
        int curr = packageWeights[i];
        if (curr < prev) {
            prev += curr;
        } else {
            prev = curr;
        }
        max = std::max(prev, max);
    }
    return max;
}
*/

/*
long getHeaviestPakcage(vector<int> packageWeights) {
    if (packageWeights.size() == 0)
        return 0;

    const int total_package_count = packageWeights.size();
    
    long heaviest = (long)packageWeights[total_package_count - 1];
    long weight_to_add = heaviest;

    // The number is decreasing, so it's better to traverse from the end.
    for (int i = total_package_count - 2; i >= 0; i--) {
        int curr = packageWeights[i];
        if (curr < heaviest) {
            heaviest += curr;
        } else {
            heaviest = curr;
        }
        heaviest = std::max(heaviest, weight_to_add);
    }
    return heaviest;
}

int main() {
    std::vector<int> sam;
    sam.push_back(20);
    sam.push_back(13);
    sam.push_back(8);
    sam.push_back(9);
    std::cout << getHeaviestPakcage(sam) << std::endl;
   return 0;
}
*/

/*
long getTotalImblance(vector<int> weight) {
    long res = 0, n = weight.size(), j, k;
        // Get sum of minimums
        stack<int> s;
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && weight[s.top()] > (i == n ? -2e9 : weight[i])) {
                j = s.top(), s.pop();
                k = s.empty() ? -1 : s.top();
                res -= (long)weight[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        // get sum of maximums
        s = stack<int>();
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && weight[s.top()] < (i == n ? 2e9 : weight[i])) {
                j = s.top(), s.pop();
                k = s.empty() ? -1 : s.top();
                res += (long)weight[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        return res;
}

int main() {
    std::vector<int> sam;
    sam.push_back(3);
    sam.push_back(1);
    sam.push_back(2);
    sam.push_back(4);
    std::cout << getTotalImblance(sam) << std::endl;
    return 0;
}
*/

/*
struct Val {
  Val(int val, int min) {
    val_ = val;
    min_ = min;
  }
  int val_;
  int min_;
};

class MinStack {
public:
    std::stack<Val> stack_;
    int min_;

    MinStack() {
      min_ = 999999;
    }
    
    void push(int val) {
       stack_.push(Val(val, min_)); 
       if (min_ > val)
         min_ = val;
    }
    
    void pop() {
      auto top = stack_.top();
      stack_.pop();
      min_ = top.min_;
    }
    
    int top() {
      auto top = stack_.top();
      return top.val_;
    }
    
    int getMin() {
       return min_; 
    }
};

int main() {
  MinStack min_stack_;
  min_stack_.push(-2);
  min_stack_.push(0);
  min_stack_.push(-3);
  std::cout << min_stack_.getMin() << std::endl;
  min_stack_.pop();
  std::cout << min_stack_.top() << std::endl;
  std::cout << min_stack_.getMin() << std::endl;
  return 0;
}
*/

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // number, index
        map<int, int> num_map;
        
        for (int i = 0; i < nums.size(); i++) {
            int target_minus_num = target - nums[i];

            auto found = num_map.find(target_minus_num);
            if (i == found->second)
                continue;
            if (found != num_map.end()) {
                vector<int> return_val;
                return_val.push_back(found->second);
                return_val.push_back(i);
                return return_val;
            }
            num_map[nums[i]] = i;
        }
        
        return vector<int>();
    }
};

int main() {
Solution a;
std::vector<int> nums{2,7,11,15};
auto vec = a.twoSum(nums, 9);

for (auto a : vec) {
std::cout << a << " ";
}
return 0;
}
*/


// 907. Sum of Subarray Mimimums
// Use monostack.

/*
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
      // Get list of subarray. 
      // get sum
       // typical monotone stack.
       stack<int> monotone_stack;
       for (int i = 0; i < arr.size(); i++) {
         while(!monotone_stack.empty() && monotone_stack.top() > arr[i]) {
           monotone_stack.pop(); 
         }
         monotone_stack.push(arr[i]);
       }
       // 1,2,3,4(top)

       return 0;
    }
};
*/

/*
class Solution {
public:
    // This function finds the previous less number.
    vector<int> findleft(vector<int>& arr)
    {   
        vector<int> ans(arr.size(), 0);
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--)
        {   
            int x = arr[i];
            if(!st.empty())
            {
                if(x>arr[st.top()])
                    st.push(i);
                else
                {
                    while(!st.empty() && x <= arr[st.top()])
                    {
                        ans[st.top()] = max(0,abs(i-st.top())-1);
                        st.pop();
                    }
                    st.push(i);
                }
            } 
            else
                st.push(i);
        }
        
        while(!st.empty())
        {   
            ans[st.top()] = st.top();
            st.pop();
        }
        return ans;
    }

   // build next less vector.
    vector<int> findright(vector<int>& arr)
    {   
        vector<int> ans(arr.size(),0);
        stack<int> st;
        for(int i=0;i<arr.size();i++)
        {   
            int x = arr[i];
            if(!st.empty())
            {
                if(x>= arr[st.top()])
                    st.push(i);
                else
                {
                    while(!st.empty() && x < arr[st.top()])
                    {
                        ans[st.top()] =  abs(i-st.top()-1);
                        st.pop();
                    }
                    st.push(i);
                }
            }
            else
                st.push(i);
            
        }
      
        while(!st.empty())
        {   
            ans[st.top()] =  (arr.size()-1) - st.top() ;
            st.pop();
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> ll = findright(arr);
        for (auto aa : ll) {
            std::cout << aa << " ";
        }
        std::cout << std::endl;
        vector<int> rr = findleft(arr);
        for (auto aa : rr) {
            std::cout << aa << " ";
        }
        
        long long sum =0 ;
        int mod = 1000000007;
        for(int i=0;i<arr.size();i++)
        {   
          long long l = ll[i]+1;
          long long r = rr[i]+1;
          // left * right * element
          long long x = (arr[i] * (l*r)) ; 
          // sum + x % mod
          // sum % mod + x %mod
          sum = (sum%mod + x%mod) %mod ; 
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> sample{2, 9, 7, 8, 3, 4, 6, 1};
    // previous less vector
    // 1's previous less is 0 +1
    // 2's previous less is '1' = 0 + 1
    // 5's previous less is '2' = 0 + 1
    // 3's previous less is '2' = 1 + 1
    // 4's previous less is '3' = 0 + 1
    // next less vector
    // 1's next less = None
    // 2's next less = None
    // 5's next less is '4' = 1 + 1 = 2
    // 3's next less is = None
    // 4's next less is = None

    s.sumSubarrayMins(sample);
  return 0;
}
*/
/*
void bfs(int s) {
  map<int,int> level;
  map<int, int> parent;
  // -1 means start.
  level[s] = 0;
    parent[s] = -1;

    queue<int> frontier;
    frontier.push(s);
    int i = 1;

    // frontier is the nodes will visit.
    while(!frontier.empty()) {
        std::queue<int> next;
        for (auto u : frontier) {
            for (auto v : adj[u]) {
                // if not visited.
                if (level.find(v) == level.end()) {
                    level[v] = i;
                    parent[v] = u;
                    next.push(v);
                }
            }
        }
        i++;
        frontier = next;
    }


}
*/

/*
string isBalanced(string s) {
    stack<char> stack;
    for (int i = 0;i<s.size();i++) {
        char current = s[i];
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            stack.push(s[i]);
        }
        if (current == '}' || current == ']' || current == ')') {
            if (stack.size() == 0)
                return "NO";
            char top = stack.top();
            stack.pop();
            if (current == '}' && top != '{') {
                return "NO";
            }
            if (current == ']' && top != '[') {
                return "NO";
            }
            if (current == ')' && top != '(') {
                return "NO";
            }
        }
    }

    if (stack.size() != 0)
        return "NO";

    return "YES";
}

int main() {
    std::cout << isBalanced("}][}}(}][))]");
  return 0;
}
*/

/*
int main() {
    vector<string> nike;
    nike.push_back("ed");
    nike.push_back("eddie");
    nike.push_back("edward");
    nike.push_back("edwina");

    std::sort(nike.begin(), nike.end());

    int lower_bound = std::lower_bound(nike.begin(), nike.end(), "edw") - nike.begin();

    for (int i = lower_bound; i < nike.size(); i++) {
      if (nike[i].substr(0,3) != "edw")
        break;
      std::cout << nike[i] << std::endl;
    }

    return 0;
}
*/

// 1603. Design Parking System
// big. medium. small
//
// impl ParkingSystem class

/*
class ParkingSystem {
public:
    enum CarType {
      Big = 1,
      Medium = 2,
      Small = 3
    };

    // fixed size.
    int big_space_;
    int medium_space_;
    int small_space_;
    int big, medium, small;

    ParkingSystem(int big, int medium, int small) {
      big_space_= big;
      medium_space_ = medium;
      small_space_ = small;
    }

    bool addCar(int carType) {
       if (carType == 1)
          big_space_++;
    }
};
*/

// https://leetcode.com/problems/shortest-path-to-get-food/
// 1730. Shortest Path to Get Food

class Solution {
public:
        std::pair<int, int> getStart(vector<vector<char>>& grid) {
      int start_x = -1;
      int start_y = -1;
      for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[0].size(); col++) {
          if (grid[row][col] == '*') {
            start_x = row;
            start_y = col;
            return std::pair<int,int>(start_x, start_y);
          }
        }
      }

      return std::pair<int,int>(-1,-1);
    }

    int getFood(vector<vector<char>>& grid) {
      if (grid.size() == 0)
        return -1;
      if (grid[0].size() == 0)
        return -1;

      // BFS
      std::pair<int,int> start = getStart(grid);
      if (start.first == -1)
        return -1;

      std::vector<std::pair<int,int>> frontier;
      frontier.push_back(start);

      std::map<std::pair<int,int>, int> level;
      // 빼먹은거
      level[start] = 1;
      // 어려운거
      int direction_x[4] = {-1, 1,  0, 0};
      int direction_y[4] = { 0, 0, -1, 1};
      int k = 0;
      while (!frontier.empty()) {
        k++;
        std::vector<std::pair<int,int>> next;
        for (auto u : frontier) {
          for (int i = 0; i < 4; i++) {
            
            int new_position_x = u.first + direction_x[i];
            int new_position_y = u.second + direction_y[i];
            // X = row
            // y = column
            // grid[x] 니까 grid.size()랑 비교해야함
            if (new_position_x < 0 || new_position_x >= grid.size() || new_position_y < 0 || new_position_y >= grid[0].size()) {
              continue;
            }

            // if already visited.
            if (grid[new_position_x][new_position_y] == 'X') {
              continue;
            }

            if (grid[new_position_x][new_position_y] == '#') {
              return k;
            }

            if (grid[new_position_x][new_position_y] == 'O') {
              std::cout << "Add " << new_position_x << " : " << new_position_y << std::endl;
              // 3,4
              next.push_back(std::pair<int,int>(new_position_x, new_position_y));
            }
            grid[new_position_x][new_position_y] = 'X';
          }
        }

        std::cout << "----------------" << std::endl;
        frontier = next;
      }

      std::cout << "END HREER";

      return -1;
    }
};

int main() {
  Solution s;
  std::vector<std::vector<char>> input;
  // 5 row
  // 8 column
  input.push_back({'X','X','X','X','X','X','X','X'});
  input.push_back({'X','*','O','X','O','#','O','X'});
  input.push_back({'X','O','O','X','O','O','X','X'});
  input.push_back({'X','O','O','O','O','#','O','X'});
  input.push_back({'X','X','X','X','X','X','X','X'});

  std::cout << s.getFood(input);
return 0;
}
