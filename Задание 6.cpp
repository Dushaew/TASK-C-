// запуск программ
// g++ task6.cpp
// ./a.out



// Вам дан массив prices, в котором prices[i]указана цена данной акции на текущий день.ith
// Найдите максимальную прибыль, которую вы можете получить. Вы можете совершить не более двух транзакций .
// Примечание. Вы не можете совершать несколько транзакций одновременно 
// (т. е. вы должны продать акции, прежде чем купить их снова).

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }

    // Инициализация массивов для отслеживания максимальной прибыли после каждой транзакции
    vector<int> firstBuy(n, 0);
    vector<int> firstSell(n, 0);
    vector<int> secondBuy(n, 0);
    vector<int> secondSell(n, 0);

    // Вычисление максимальной прибыли после первой транзакции
    firstBuy[0] = -prices[0];
    firstSell[0] = 0;
    for (int i = 1; i < n; ++i) {
        firstBuy[i] = max(firstBuy[i - 1], -prices[i]);
        firstSell[i] = max(firstSell[i - 1], firstBuy[i - 1] + prices[i]);
    }

    // Вычисление максимальной прибыли после второй транзакции
    secondBuy[0] = max(-prices[0], -prices[1]);
    secondSell[0] = 0;
    for (int i = 1; i < n; ++i) {
        secondBuy[i] = max(secondBuy[i - 1], firstSell[i] - prices[i]);
        secondSell[i] = max(secondSell[i - 1], secondBuy[i - 1] + prices[i]);
    }

    // Находим максимальную общую прибыль
    int maxProfit = 0;
    for (int i = 0; i < n; ++i) {
        maxProfit = max(maxProfit, secondSell[i]);
    }

    return maxProfit;
}

int main() {
    // Примеры использования
    vector<int> prices1 = { 3, 3, 5, 0, 0, 3, 1, 4 };
    vector<int> prices2 = { 1, 2, 3, 4, 5 };
    vector<int> prices3 = { 7, 6, 4, 3, 1 };

    cout << maxProfit(prices1) << endl;  // Ожидаемый вывод: 6
    cout << maxProfit(prices2) << endl;  // Ожидаемый вывод: 4
    cout << maxProfit(prices3) << endl;  // Ожидаемый вывод: 0

    return 0;
}
