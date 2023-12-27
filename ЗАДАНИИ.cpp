// запуск программ
// g++ task2.cpp
// ./a.out



// Вам дан целочисленный массив numsи два целых числа indexDiffи valueDiff.
// Найдите пару индексов (i, j)такую, что:
// i != j, abs(i - j) <= indexDiff. abs(nums[i] - nums[j]) <= valueDiff, и 
// Возврат, trueесли такая пара существует или falseнет .

#include <iostream>
#include <vector>
#include <cmath>

bool findPair(std::vector<int>& nums, int indexDiff, int valueDiff) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(i - j) <= indexDiff && abs(nums[i] - nums[j]) <= valueDiff) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Пример 1
    std::vector<int> nums = { 1, 2, 3, 1 };
    int indexDiff = 3;
    int valueDiff = 0;

    bool result = findPair(nums, indexDiff, valueDiff);

    std::cout << std::boolalpha << result << std::endl;


    // Пример 2
    // std::vector<int> nums = {1, 5, 9, 1, 5, 9};
    // int indexDiff = 2;
    // int valueDiff = 3;

    // bool result = findPair(nums, indexDiff, valueDiff);

    // std::cout << std::boolalpha << result << std::endl;

    return 0;
}
