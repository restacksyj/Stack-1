// Problem Name: Daily Temperature
// Time Complexity : O(2n) = O(n)
// Space Complexity : O(n) stack space
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No

// Your code here along with comments explaining your approach
// 1. We use a monotonic decreasing stack here to get the first temperature that
// is greater
// 2. If current temperature is greater than stack's top, we pop it and replace
// the value of res[popped] with i - popped
// 3. In the end, we return the result

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<int> res(temperatures.size(), 0);
    stack<int> st;
    for (int i = 0; i < temperatures.size(); i++) {
      while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        int popped = st.top();
        res[popped] = i - popped;
        st.pop();
      }
      st.push(i);
    }
    return res;
  }
};
