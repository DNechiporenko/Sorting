#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Выбор рандомного pivot элемента
int randomPivot(int low, int high) {
    srand(time(0)); // Инициализация генератора случайных чисел
    return low + rand() % (high - low + 1);
}

// Меняем местами элементы массива
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Разделение массива относительно pivot элемента
int partition(std::vector<int>& arr, int low, int high) {
    int pivIndex = randomPivot(low, high); 
    int pivValue = arr[pivIndex]; 
    swap(arr[pivIndex], arr[high]); // Помещаем pivot элемент в конец массива
    int i = low;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivValue) {
            swap(arr[i], arr[j]);
            ++i;
        }
    }
    swap(arr[i], arr[high]); // Помещаем pivot элемент на его правильное место
    return i;
}

// Основная функция быстрой сортировки
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivIndex = partition(arr, low, high);
        quickSort(arr, low, pivIndex - 1); // Сортируем левую часть массива
        quickSort(arr, pivIndex + 1, high); // Сортируем правую часть массива
    }
}

// Вывод массива
void showArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian"); 
    std::vector<int> arr;
    int size; //Переменная для размера массива

    std::cout << "Введите размер массива: ";
    std::cin >> size;
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i) {
        int n;
        std::cin >> n;
        arr.push_back(n);
    }

    std::cout << "Исходный массив:" << std::endl;
    showArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Отсортированный массив:" << std::endl;
    showArray(arr);

    return 0;
}
