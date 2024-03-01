#include <iostream>
#include <vector>

// Функция сортировки подсчетом
void countingSort(std::vector<int>& arr, int maxValue) {
    std::vector<int> count(maxValue + 1, 0);

    // Распределение элементов по отсортированному массиву
    for (int i = arr.size() - 1; i >= 0; --i) {
        count[arr[i]]++;
    }

    // Индекс для записи отсортированных элементов в результирующий массив
    int index = 0;
    for (int i = 0; i <= maxValue; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

// Вывод массива
template<typename T>
void printArray(const std::vector<T>& arr) {
    for (const T& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr;
    int size, maxValue;

    std::cout << "Введите размер массива: ";
    std::cin >> size;
    std::cout << "Введите максимальное значение элементов: ";
    std::cin >> maxValue;
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i) {
        int num;
        std::cin >> num;
        arr.push_back(num);
    }

    std::cout << "Исходный массив:" << std::endl;
    printArray(arr);

    countingSort(arr, maxValue);

    std::cout << "Отсортированный массив:" << std::endl;
    printArray(arr);

    return 0;
}
