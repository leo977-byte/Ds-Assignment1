#include <bits/stdc++.h>
#define ll long long
#define leona ios_base::sync_with_stdio(false); cin.tie(NULL);          

using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size(); 
    vector<int> res(n, -1); 
    stack<int> s;  

    for (int i = 0; i < 2 * n; i++) {
        int currentIndex = i % n;

        while (!s.empty() && nums[currentIndex] > nums[s.top()]) {
            res[s.top()] = nums[currentIndex];
            s.pop();
        }
        if (i < n) {
            s.push(currentIndex);
        }
    }
    return res;
}

int main() {
    leona;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> result = nextGreaterElements(nums);

    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
