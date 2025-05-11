#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double get_max_profit(int N, double H, double C, vector<pair<double, double>> &houses) {
        vector<double> distances;
        for (auto &[x, y] : houses) {
            distances.push_back(sqrt(x * x + y * y));
        }
        sort(distances.begin(), distances.end());

        double max_profit = 0.0;
        for (int i = 0; i < N; ++i) {
            double dist = distances[i];
            int houses_covered = i + 1;
            double profit = C * houses_covered - dist * H;
            max_profit = max(max_profit, profit);
        }

        return max(max_profit, 0.0);
    }

    double get_max_profit_with_location(int N, double H, double C,
                                        vector<pair<double, double>> &houses,
                                        pair<double, double> tower_location) {
        double tower_x = tower_location.first;
        double tower_y = tower_location.second;

        vector<double> distances;
        for (auto &[x, y] : houses) {
            double dx = x - tower_x;                       // x2 - x1
            double dy = y - tower_y;                       // y2 - y1
            distances.push_back(sqrt(dx * dx + dy * dy));  // sqrt(|x2-x1| + |y2-y1|) <- distance formula
        }

        sort(distances.begin(), distances.end());

        double max_profit = 0.0;
        for (int i = 0; i < N; ++i) {
            double dist = distances[i];
            int houses_covered = i + 1;
            double profit = C * houses_covered - dist * H;
            max_profit = max(max_profit, profit);
        }

        return max(max_profit, 0.0);
    }
};

int main() {
    Solution sol;

    // Example 1
    int N1 = 3;
    vector<pair<double, double>> houses1 = {{1, 2}, {3, 4}, {5, 6}};
    double H1 = 2;
    double C1 = 10;
    double profit1 = sol.get_max_profit(N1, H1, C1, houses1);
    cout << "Example 1 - Maximum profit: " << profit1 << endl;

    // Example 2
    int N2 = 5;
    vector<pair<double, double>> houses2 = {{0.5, 1}, {1.5, 2}, {2.5, 3}, {10, 10}, {15, 15}};
    double H2 = 3;
    double C2 = 5;
    double profit2 = sol.get_max_profit(N2, H2, C2, houses2);
    cout << "Example 2 - Maximum profit: " << profit2 << endl;

    // Follow-up with location
    pair<double, double> tower_loc = {1, 1};
    double profit_with_loc = sol.get_max_profit_with_location(N1, H1, C1, houses1, tower_loc);
    cout << "Follow-up - Max profit with tower at (" << tower_loc.first << ", " << tower_loc.second << "): " << profit_with_loc << endl;

    return 0;
}



// Maximum Watchtower Profit
// You are tasked with building a watchtower in a town. A watchtower has a height h and provides surveillance to all houses within a horizontal distance less than or equal to h from the watchtower.
// Given:
// The watchtower is initially located at position (0, 0)
// Each unit of height of the watchtower costs H to build
// There are N houses in the town, each located at coordinates (x, y)
// Each house that comes under the surveillance of the watchtower will pay a cost C
// Your goal is to determine the optimal height of the watchtower to maximize profit.
// Profit is calculated as: (Number of houses under surveillance × C) - (Height of tower × H)

// Function Signature:
// def maximizeWatchtowerProfit(N: int, coordinates: List[List[float]], H: float, C: float) -> float:
//     """
//     Args:
//         N: Number of houses
//         coordinates: List of [x, y] coordinates of houses
//         H: Cost to build one unit height of the watchtower
//         C: Cost each house pays if under surveillance
    
//     Returns:
//         Maximum profit that can be achieved
//     """

// Example 1:
// Input: N = 3, coordinates = [[1, 2], [3, 4], [5, 6]], H = 2, C = 10
// Output: 10
// Explanation: 
// - If we build the watchtower with height 3, it covers houses at (1, 2) and (3, 4)
// - Cost of building: 3 × 2 = 6
// - Revenue from houses: 2 × 10 = 20
// - Profit: 20 - 6 = 14

// Example 2:
// Input: N = 5, coordinates = [[0.5, 1], [1.5, 2], [2.5, 3], [10, 10], [15, 15]], H = 3, C = 5
// Output: 4
// Explanation:
// - If we build the watchtower with height 2.5, it covers houses at (0.5, 1), (1.5, 2), and (2.5, 3)
// - Cost of building: 2.5 × 3 = 7.5
// - Revenue from houses: 3 × 5 = 15
// - Profit: 15 - 7.5 = 7.5


// Constraints:
// 1 ≤ N ≤ 10^5
// -10^9 ≤ x, y ≤ 10^9
// 0 < H, C ≤ 10^9
// All coordinates are unique
// Coordinates can be float values
// The output should be the maximum profit possible

// Follow Up:
// What if the watchtower's location is provided instead of being fixed at (0, 0)? How would you modify your solution?



// # Watchtower Problem Visualizations

// ## Example 1
// ```
// Input: N = 3, coordinates = [[1, 2], [3, 4], [5, 6]], H = 2, C = 10
// ```

// ASCII Plot:
// ```
//     |
//  6  |                    * (5,6)
//     |
//  5  |
//     |
//  4  |            * (3,4)
//     |
//  3  |
//     |
//  2  |    * (1,2)
//     |
//  1  |
//     |
//  0  +----+----+----+----+----+----
//     0    1    2    3    4    5
// ```

// With a watchtower at (0,0) of height 3:
// ```
//     |
//  6  |                    * (5,6) [Not covered]
//     |
//  5  |
//     |          [Coverage radius = 3]
//  4  |            * (3,4) [Covered]
//     |         /
//  3  |       /
//     |     /
//  2  |    * (1,2) [Covered]
//     |   /
//  1  | /
//     |/
//  0  W----+----+----+----+----+----
//     0    1    2    3    4    5
// ```

// The watchtower (W) with height 3 covers houses within horizontal distance 3. This includes houses at (1,2) and (3,4), but not (5,6).
// - Cost of building: 3 × 2 = 6
// - Revenue from houses: 2 × 10 = 20
// - Profit: 20 - 6 = 14

// ## Example 2
// ```
// Input: N = 5, coordinates = [[0.5, 1], [1.5, 2], [2.5, 3], [10, 10], [15, 15]], H = 3, C = 5
// ```

// ASCII Plot (scaled):
// ```
//     |
// 15  |                                            * (15,15)
//     |
//     |
// 10  |                                * (10,10)
//     |
//     |
//  5  |
//     |
//     |
//  3  |            * (2.5,3)
//     |
//  2  |        * (1.5,2)
//     |
//  1  |    * (0.5,1)
//     |
//  0  W----+----+----+----+----+----+----+----+----+----+----+
//     0    1    2    3    4    5    6    7    8    9   10   15
// ```

// With a watchtower at (0,0) of height 2.5:
// ```
//     |
// 15  |                                            * (15,15) [Not covered]
//     |
//     |
// 10  |                                * (10,10) [Not covered]
//     |
//     |
//  5  |
//     |           [Coverage radius = 2.5]
//     |                /
//  3  |            * (2.5,3) [Covered]
//     |           /
//  2  |        * (1.5,2) [Covered]
//     |       /
//  1  |    * (0.5,1) [Covered]
//     |   /
//  0  W----+----+----+----+----+----+----+----+----+----+----+
//     0    1    2    3    4    5    6    7    8    9   10   15
// ```

// The watchtower (W) with height 2.5 covers houses within horizontal distance 2.5. This includes houses at (0.5,1), (1.5,2), and (2.5,3), but not the distant houses.
// - Cost of building: 2.5 × 3 = 7.5
// - Revenue from houses: 3 × 5 = 15
// - Profit: 15 - 7.5 = 7.5

// ## Key Insights
// 1. The watchtower's coverage radius equals its height
// 2. Only the horizontal distance matters (√(x² + y²) when the tower is at origin)
// 3. The optimal height is likely to equal the distance to one of the houses
// 4. We need to try each possible height to find the maximum profit