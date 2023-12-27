// запуск программ
// g++ task4.cpp
// ./a.out

// Компании Загадка с n ферзями — это задача о том, как разместить nферзей на n x nшахматной доске так, 
// чтобы никакие два ферзя не атаковали друг друга.
// Учитывая целое число n, верните все различные решения головоломки с n ферзями . 
// Вы можете вернуть ответ в любом порядке .
// Каждое решение содержит отдельную конфигурацию доски для размещения n ферзей, 
// где 'Q'и '.'оба обозначают ферзя и пустое место соответственно.

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> solutions;
        std::vector<std::string> board(n, std::string(n, '.')); // Инициализация доски

        backtrack(solutions, board, 0, n);

        return solutions;
    }

private:
    void backtrack(std::vector<std::vector<std::string>>& solutions, std::vector<std::string>& board, int row, int n) {
        if (row == n) {
            solutions.push_back(board); // Добавляем текущую конфигурацию доски в решения
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q'; // Размещаем ферзя на текущей позиции
                backtrack(solutions, board, row + 1, n); // Рекурсивно размещаем ферзей на следующей строке
                board[row][col] = '.'; // Удаляем ферзя для проверки других позиций
            }
        }
    }

    bool isValid(const std::vector<std::string>& board, int row, int col, int n) {
        // Проверяем вертикали и горизонтали
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Проверяем диагонали
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    int n = 4;
    std::vector<std::vector<std::string>> solutions = solution.solveNQueens(n);

    // Вывод решений
    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            std::cout << row << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
