#include <iostream>
#include <vector>

// Меняем местами элементы массива
template<typename T>
void swap(T& a, T& b) {
    T c = a;
    a = b;
    b = c;
}

// Сортировка пузырьком
template<typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) { //Перебор всех элементов массива
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Вывод массива
template<typename T>
void showArray(const std::vector<T>& arr) {
    for (const T& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr;
    int size;

    std::cout << "Введите размер массива: ";
    std::cin >> size;
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i) {
        int num;
        std::cin >> num;
        arr.push_back(num);
    }

    std::cout << "Исходный массив:" << std::endl;
    showArray(arr);

    bubbleSort(arr);

    std::cout << "Отсортированный массив:" << std::endl;
    showArray(arr);

    return 0;
}
