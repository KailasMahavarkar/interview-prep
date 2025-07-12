#include <algorithm>
#include <climits>
#include <iostream>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Name   : None
    Problem Link   : https://leetcode.com/problems/minimum-area-rectangle-ii/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
    Notes          : A very hard level problem, please ignore this question
*/

class Solution {
   public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        unordered_set<long long> point_set;
        for (auto& p : points)
            point_set.insert(((long long)p[0] << 32) | p[1]);

        double min_area = DBL_MAX;

        auto encode = [](int x, int y) {
            return ((long long)x << 32) | y;
        };

        for (int i = 0; i < n; ++i) {
            auto [x1, y1] = tie(points[i][0], points[i][1]);
            for (int j = i + 1; j < n; ++j) {
                auto [x2, y2] = tie(points[j][0], points[j][1]);
                for (int k = j + 1; k < n; ++k) {
                    auto [x3, y3] = tie(points[k][0], points[k][1]);
                    int dx1 = x2 - x1, dy1 = y2 - y1;
                    int dx2 = x3 - x1, dy2 = y3 - y1;

                    if (dx1 * dx2 + dy1 * dy2 != 0) continue;

                    int x4 = x2 + x3 - x1;
                    int y4 = y2 + y3 - y1;

                    if (!point_set.count(encode(x4, y4))) continue;

                    double side1 = hypot(dx1, dy1);
                    double side2 = hypot(dx2, dy2);
                    double area = side1 * side2;
                    min_area = min(min_area, area);
                }
            }
        }
        return (min_area == DBL_MAX) ? 0.0 : min_area;
    }
};

int main() {
    vector<int> p1 = {1, 1};
    vector<int> p2 = {4, 1};
    vector<int> p3 = {1, 4};

    int x1 = p1[0];
    int x2 = p2[0];
    int x3 = p3[0];
    int y1 = p1[1];
    int y2 = p2[1];
    int y3 = p3[1];

    int dot_product = (x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1);
    cout << "dot_product --> " << dot_product << endl;

    vector<vector<int>> points = {{1, 2}, {2, 1}, {1, 0}, {0, 1}};

    Solution sol;
    double ans = sol.minAreaFreeRect(points);
    cout << "ans --> " << ans << endl;
}