#include <bits/stdc++.h>
#define ll long long
#define leona ios_base::sync_with_stdio(false); cin.tie(NULL);          

using namespace std;
vector<int> solveNextGreater(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;
    for (int i = 0; i < 2 * n; i++) {
        int currentNum = nums[i % n];

        while (!s.empty() && nums[s.top()] < currentNum) {
            result[s.top()] = currentNum;
            s.pop();
        }

        if (i < n) {
            s.push(i);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 1};
    vector<int> result = solveNextGreater(nums);

    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}
