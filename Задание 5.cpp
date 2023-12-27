// запуск программ
// g++ task5.cpp
// ./a.out

// Учитывая rows x cols двоичный файл matrix, заполненный символами 0's и 1's, 
// найдите самый большой прямоугольник, содержащий только 1's, и верните его площадь .

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                }
                else {
                    heights[j] = 0;
                }
            }
            maxArea = std::max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        std::stack<int> stk;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            while (!stk.empty() && (i == n || heights[i] < heights[stk.top()])) {
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                maxArea = std::max(maxArea, h * w);
            }
            stk.push(i);
        }

        return maxArea;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    int maxArea = solution.maximalRectangle(matrix);
    std::cout << "Максимальная площадь прямоугольника: " << maxArea << std::endl;

    return 0;
}

