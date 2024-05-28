#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <locale>
#include <io.h>
#include <fcntl.h>

// Класс для обработки массива
class ArrayProcessor {
private:
    std::vector<double> arr; // Вектор для хранения элементов массива

public:
    // Метод для ввода массива пользователем
    void inputArray(int N) {
        arr.resize(N); // Изменение размера вектора на N элементов
        std::wcout << L"Введите " << N << L" элементов массива:\n";
        for (int i = 0; i < N; ++i) {
            std::wcin >> arr[i]; // Ввод элемента массива
            // Дополнительная проверка на корректность данных
            if (arr[i] < 0) {
                std::wcerr << L"Ошибка: Введено отрицательное число.\n";
                exit(1); // Завершение программы в случае некорректного ввода
            }
        }
    }

    // Задача 1: Поиск максимального и минимального элементов
    void findMinMax() {
        double min = arr[0], max = arr[0]; // Инициализация начальных значений
        std::vector<int> minIndices, maxIndices; // Векторы для хранения индексов минимальных и максимальных значений
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] < min) {
                min = arr[i]; // Обновление минимального значения
                minIndices.clear(); // Очистка списка индексов минимальных значений
                minIndices.push_back(static_cast<int>(i));// Добавление текущего индекса
            }
            else if (arr[i] == min) {
                minIndices.push_back(static_cast<int>(i));// Добавление текущего индекса 
                //в случае равенства с минимальным значением
            }
            if (arr[i] > max) {
                max = arr[i]; // Обновление максимального значения
                maxIndices.clear(); // Очистка списка индексов максимальных значений
                maxIndices.push_back(static_cast<int>(i)); // Добавление текущего индекса
            }
            else if (arr[i] == max) {
                maxIndices.push_back(static_cast<int>(i)); // Добавление текущего индекса в случае равенства с максимальным значением
            }
        }
        std::wcout << L"Минимальный элемент: " << min << L", Индексы: ";
        for (int index : minIndices) {
            std::wcout << index << L" "; // Вывод индексов минимальных значений
        }
        std::wcout << L"\nМаксимальный элемент: " << max << L", Индексы: ";
        for (int index : maxIndices) {
            std::wcout << index << L" "; // Вывод индексов максимальных значений
        }
        std::wcout << std::endl;
    }

    // Задача 2: Вычисление суммы и произведения элементов
    void sumAndProduct() {
        double sum = 0, product = 1; // Инициализация суммы и произведения
        for (double num : arr) {
            sum += num; // Суммирование элементов
            product *= num; // Умножение элементов
        }
        std::wcout << L"Сумма элементов: " << sum << std::endl;
        std::wcout << L"Произведение элементов: " << product << std::endl;
    }

    // Задача 3: Нахождение среднего арифметического и среднего геометрического
    void mean() {
        double arithmeticMean = 0, geometricMean = 1; // Инициализация средних значений
        for (double num : arr) {
            arithmeticMean += num; // Суммирование для среднего арифметического
            geometricMean *= num; // Умножение для среднего геометрического
        }
        arithmeticMean /= arr.size(); // Вычисление среднего арифметического
        geometricMean = pow(geometricMean, 1.0 / arr.size()); // Вычисление среднего геометрического
        std::wcout << L"Среднее арифметическое: " << arithmeticMean << std::endl;
        std::wcout << L"Среднее геометрическое: " << geometricMean << std::endl;
    }

    // Задача 4: Подсчет четных и нечетных элементов
    void countEvenAndOdd() {
        int evenCount = 0, oddCount = 0; // Инициализация счетчиков
        for (double num : arr) {
            int roundedNum = static_cast<int>(round(num)); // Округление числа
            if (roundedNum % 2 == 0)
                evenCount++; // Увеличение счетчика четных чисел
            else
                oddCount++; // Увеличение счетчика нечетных чисел
        }
        std::wcout << L"Количество четных элементов: " << evenCount << std::endl;
        std::wcout << L"Количество нечетных элементов: " << oddCount << std::endl;
    }

    // Задача 5: Поиск значения в массиве
    void search(double value) {
        int count = 0; // Счетчик вхождений
        std::wcout << L"Индексы элемента " << value << L": ";
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] == value) {
                std::wcout << i << L" "; // Вывод индекса вхождения
                count++;
            }
        }
        std::wcout << L"\nКоличество вхождений: " << count << std::endl;
    }

    // Задача 6: Сортировка массива методом Selection
    void selectionSort(bool ascending) {
        for (int i = 0; i < static_cast<int>(arr.size()) - 1; ++i) {
            // Инициализация индекса минимального/максимального значения
            int min_max_index = i;
            for (int j = static_cast<int>(i) + 1; j < static_cast<int>(arr.size()); ++j) {
                // Выбор минимального или максимального значения 
                //в зависимости от параметра ascending
                if (ascending ? (arr[j] < arr[min_max_index]) : (arr[j] > arr[min_max_index])) {
                    min_max_index = j;
                }
            }
            if (min_max_index != i) {
                std::swap(arr[i], arr[min_max_index]); // Обмен элементов
            }
        }
    }

    // Метод для вывода массива
    void displayArray() {
        std::wcout << L"Массив: ";
        for (double num : arr) {
            std::wcout << num << L" "; // Вывод элементов массива
        }
        std::wcout << std::endl;
    }
};

int main() {
    // Установка локализации для поддержки кириллицы
    std::locale::global(std::locale("ru_RU.UTF-8"));

    // Настройка консоли для работы с UTF-8
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    int N; // Размер массива
    std::wcout << L"Введите размерность массива: ";
    std::wcin >> N;

    ArrayProcessor ап; // Создание объекта класса ArrayProcessor
    ап.inputArray(N); // Ввод массива пользователем

    // Выполнение задач
    ап.findMinMax(); // Поиск максимального и минимального элементов
    ап.sumAndProduct(); // Вычисление суммы и произведения элементов
    ап.mean(); // Нахождение среднего арифметического и геометрического
    ап.countEvenAndOdd(); // Подсчет четных и нечетных элементов

    double searchValue; // Значение для поиска
    std::wcout << L"Введите значение для поиска: ";
    std::wcin >> searchValue;
    ап.search(searchValue); // Поиск значения в массиве

    // Сортировка и вывод массива
    ап.selectionSort(true); // Сортировка по возрастанию
    std::wcout << L"Отсортированный массив по возрастанию: ";
    ап.displayArray(); // Вывод отсортированного массива

    ап.selectionSort(false); // Сортировка по убыванию
    std::wcout << L"Отсортированный массив по убыванию: ";
    ап.displayArray(); // Вывод отсортированного массива

    return 0;
}
