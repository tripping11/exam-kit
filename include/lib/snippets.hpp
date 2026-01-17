#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

namespace lib {

// --- 1. Binary Search (The "Lower Bound" Pattern) ---
// Returns the first index `i` in [l, r) where check(i) is true.
// Assumption: check(x) is false for all x < ans, and true for all x >= ans.
// If no such i exists, returns r.
template<typename F>
long long binary_search(long long l, long long r, F check) {
    while (l < r) {
        long long mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

// --- 2. Sliding Window (Generic Skeleton) ---
// Finds max length of subarray satisfying a condition
// NOTE: You usually copy-paste the *logic* inside the loop, not the template itself.
/*
int sliding_window(const std::vector<int>& nums) {
    int n = nums.size();
    int left = 0, ans = 0;
    // State variables (e.g., current_sum, count_map)
    for (int right = 0; right < n; ++right) {
        // 1. Add nums[right] to state

        // 2. Shrink window while condition is broken
        while (/* condition broken * /) {
            // Remove nums[left] from state
            left++;
        }
        // 3. Update answer
        ans = std::max(ans, right - left + 1);
    }
    return ans;
}
*/

// --- 3. 2D Grid BFS (The "Layer" Pattern) ---
// Useful for "shortest path in unweighted graph/grid"
/*
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
void bfs_grid(int rows, int cols, std::pair<int,int> start) {
    std::vector<std::vector<bool>> vis(rows, std::vector<bool>(cols, false));
    std::deque<std::pair<int,int>> q;
    
    q.push_back(start);
    vis[start.first][start.second] = true;
    int dist = 0;

    while (!q.empty()) {
        int sz = q.size(); // Process level by level
        while (sz--) {
            auto [r, c] = q.front(); q.pop_front();
            
            // Check termination: if (r == target_r && c == target_c) return dist;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !vis[nr][nc]) {
                    // Check validity (e.g. not a wall)
                    vis[nr][nc] = true;
                    q.push_back({nr, nc});
                }
            }
        }
        dist++;
    }
}
*/

} // namespace lib
