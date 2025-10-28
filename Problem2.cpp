// Problem Name: Next greater element 2
// Time Complexity : O(3n) = O(n)
// Space Complexity : O(n) stack space
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// Your code here along with comments explaining your approach
// 1. We use a monotonic decreasing stack here to get the next greater element
// 2. We run our loop for 2n since it's circular and check if current element is
// greater than stack's top
// 3. If yes, then we replace the res[top] with nums[i % n]
// 4. We only push to stack when i < n, so that we should not keep pushing the
// elements

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    int n = (int)nums.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < 2 * n; i++) {
      while (!st.empty() && nums[i % n] > nums[st.top()]) {
        int top = st.top();
        res[top] = nums[i % n];
        st.pop();
      }
      if (i < n) {
        st.push(i);
      }
    }
    return res;
  }
};
