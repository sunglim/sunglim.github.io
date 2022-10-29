package main

import (
	"fmt"
	"sort"
)

type MyBox struct {
	numberofboxes      int
	numberofunitperbox int
}

func maximumUnits(boxTypes [][]int, truckSize int) int {
	// number of boxes
	// number of units per box

	var boxlist []MyBox

	for _, single := range boxTypes {
		boxlist = append(boxlist, MyBox{numberofboxes: single[0], numberofunitperbox: single[1]})
	}
	return 0
}

/*
def sub_lists (l):
    lists = [[]]
    for i in range(len(l) + 1):
        for j in range(i):
            lists.append(l[j: i])
    return lists

# driver code
l1 = [1, 2, 3]
print(sub_lists(l1))
*/
/*
func getlistofsubarray(array []int) [][]int {
	var arrayofarray = [][]int{}
	for pos := 0; pos < len(array)+1; pos++ {
		for i := 0; i < pos; i++ {
			tmp := array[i:pos]
			buf := make([]int, len(tmp))
			buf = tmp
			if len(buf) == 1 {
				continue
			}
			arrayofarray = append(arrayofarray, buf)
		}
	}
	return arrayofarray
}

func subArrayRanges(nums []int) int64 {
	// get list of subarray
	subarr := getlistofsubarray(nums)
	fmt.Println(subarr)
	var sum int64 = 0
	for _, single := range subarr {
		sort.Ints(single)
		fmt.Println(single)
		// get first item. get latest item.
		// latest - first
		first := single[0]
		last := single[len(single)-1]
		//fmt.Println(last, first, last-first)
		sum = sum + int64(last-first)
	}

	return sum
}

func main() {
	var arrayint = []int{4, -2, -3, 4, 1} //assign
	fmt.Println(subArrayRanges(arrayint))
}
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // number, index
        map<int, int> num_map;
        for (int i = 0; i< nums.size(); i++) {
            num_map[nums[i]] = i;            
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int target_minus_num = target - nums[i];
            auto found = num_map.find(target_minus_num);
            if (found != num_map.end()) {
                //auto ret = vector<int>{i, found->second};
                //return ret;
                vector<int> return_val;
                return_val.push_back(i);
                return_val.push_back(found->first);
                return return_val;
               
            }
        }
        
        return vector<int>();
    }
};
