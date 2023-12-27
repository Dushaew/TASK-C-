// запуск программ
// g++ task3.cpp
// ./a.out

// Компании

// Медиана — это среднее значение в упорядоченном целочисленном списке . 
// Если размер списка четный, среднего значения нет, а медиана — это среднее значение двух средних значений.
// Например, для arr = [2,3,4]медиана равна 3.
// Например, для arr = [2,3]медиана равна (2 + 3) / 2 = 2.5.
// Реализуйте класс MedianFinder:
// MedianFinder() инициализирует MedianFinderобъект.
// void addNum(int num)добавляет целое число numиз потока данных в структуру данных.
// double findMedian()возвращает медиану всех элементов на данный момент. Принимаются ответы в пределах фактического ответа.10-5

#include <iostream>
#include <vector>
#include <algorithm>

class MedianFinder {
private:
    std::vector<int> nums;

public:
    MedianFinder() {
    }

    void addNum(int num) {
        nums.push_back(num);
    }

    double findMedian() {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n % 2 == 0) {
            int mid1 = n / 2;
            int mid2 = mid1 - 1;
            return (nums[mid1] + nums[mid2]) / 2.0;
        }
        else {
            int mid = n / 2;
            return nums[mid];
        }
    }
};

int main() {
    MedianFinder medianFinder;
    std::vector<double> output;

    medianFinder.addNum(1);
    output.push_back(0.0);
    medianFinder.addNum(2);
    output.push_back(0.0);
    output.push_back(0.0);
    output.push_back(medianFinder.findMedian());
    medianFinder.addNum(3);
    output.push_back(0.0);
    output.push_back(medianFinder.findMedian());

    // Вывод результата
    for (double val : output) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
