// запуск программ
// g++ task1.cpp
// ./a.out


// Путь в бинарном дереве — это последовательность узлов, в которой каждая пара соседних узлов 
// в последовательности имеет соединяющее их ребро . Узел может появиться в последовательности 
//не более одного раза . Обратите внимание, что путь не обязательно должен проходить через корень.
// Сумма путей пути — это сумма значений узлов в пути.
// Учитывая rootдвоичное дерево, верните максимальную сумму путей любого непустого пути 

#include <iostream>
#include <algorithm>
#include <climits>

// Определение структуры узла бинарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Рекурсивная функция для вычисления максимальной суммы пути в бинарном дереве
int maxPathSum(TreeNode* root, int& result) {
    if (root == nullptr) {
        return 0;
    }

    // Вычисляем суммы путей в левом и правом поддеревьях
    int leftSum = std::max(maxPathSum(root->left, result), 0);
    int rightSum = std::max(maxPathSum(root->right, result), 0);

    // Обновляем результат, если текущий путь дает большую сумму
    result = std::max(result, root->val + leftSum + rightSum);

    // Возвращаем максимальную сумму пути, начинающегося с текущего узла
    return root->val + std::max(leftSum, rightSum);
}

// Функция для вызова рекурсивной функции и получения результата
int maxPathSum(TreeNode* root) {
    int result = INT_MIN;
    maxPathSum(root, result);
    return result;
}

int main() {
    // Пример 1

    // Создаем узлы бинарного дерева
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Вычисляем максимальную сумму пути
    int maxSum = maxPathSum(root);

    // Выводим результат
    std::cout << "Максимальная сумма пути: " << maxSum << std::endl;

    // Освобождаем память
    delete root->left;
    delete root->right;
    delete root;


    // Пример 2
    // Создаем узлы бинарного дерева
    // TreeNode* root = new TreeNode(-10);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);

    // Вычисляем максимальную сумму пути
    // int maxSum = maxPathSum(root);

    // Выводим результат
    // std::cout << "Максимальная сумма пути: " << maxSum << std::endl;

    // Освобождаем память
    // delete root->left;
    // delete root->right->left;
    // delete root->right->right;
    // delete root->right;
    // delete root;


    return 0;
}
