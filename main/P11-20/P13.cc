#include <bits/stdc++.h>
using namespace std;

#define FOR_INC(i, start, end) for (int i = start; i < end; ++i)
#define FOR_DEC(i, start, end) for (int i = start; i > end; --i)
#define FOR_INC_EQUAL(i, start, end) for (int i = start; i <= end; ++i)
#define FOR_DEC_EQUAL(i, start, end) for (int i = start; i >= end; --i)

class Solution {
 public:
  int duplicateInArray(vector<int>& nums) {
    for (int& n : nums) {
      if (n < 0 || n > nums.size() - 1) {
        return -1;
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      while (nums[i] != nums[nums[i]]) {
        swap(nums[i], nums[nums[i]]);
      }
      if (nums[i] != i) {
        return nums[i];
      }
    }
    return -1;
  }
};
int main() {
  
  return 0;
}
