class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& arr) {
        unordered_map<int, int> mp;

        for (auto x : arr) {
            mp[x[0]] |= (1 << x[1]);
        }

        int ans = 2 * n;

        for (auto &[row, mask] : mp) {
            bool left = !(mask & ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)));
            bool right = !(mask & ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9)));

            if (left && right) {
                // 2 groups, nothing to subtract
            }
            else if (left || right) {
                ans--;
            }
            else if (!(mask & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7)))) {
                ans--;
            }
            else {
                ans -= 2;
            }
        }

        return ans;
    }
};