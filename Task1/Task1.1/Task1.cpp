#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <locale>
#include <io.h>
#include <fcntl.h>

// ����� ��� ��������� �������
class ArrayProcessor {
private:
    std::vector<double> arr; // ������ ��� �������� ��������� �������

public:
    // ����� ��� ����� ������� �������������
    void inputArray(int N) {
        arr.resize(N); // ��������� ������� ������� �� N ���������
        std::wcout << L"������� " << N << L" ��������� �������:\n";
        for (int i = 0; i < N; ++i) {
            std::wcin >> arr[i]; // ���� �������� �������
            // �������������� �������� �� ������������ ������
            if (arr[i] < 0) {
                std::wcerr << L"������: ������� ������������� �����.\n";
                exit(1); // ���������� ��������� � ������ ������������� �����
            }
        }
    }

    // ������ 1: ����� ������������� � ������������ ���������
    void findMinMax() {
        double min = arr[0], max = arr[0]; // ������������� ��������� ��������
        std::vector<int> minIndices, maxIndices; // ������� ��� �������� �������� ����������� � ������������ ��������
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] < min) {
                min = arr[i]; // ���������� ������������ ��������
                minIndices.clear(); // ������� ������ �������� ����������� ��������
                minIndices.push_back(static_cast<int>(i));// ���������� �������� �������
            }
            else if (arr[i] == min) {
                minIndices.push_back(static_cast<int>(i));// ���������� �������� ������� 
                //� ������ ��������� � ����������� ���������
            }
            if (arr[i] > max) {
                max = arr[i]; // ���������� ������������� ��������
                maxIndices.clear(); // ������� ������ �������� ������������ ��������
                maxIndices.push_back(static_cast<int>(i)); // ���������� �������� �������
            }
            else if (arr[i] == max) {
                maxIndices.push_back(static_cast<int>(i)); // ���������� �������� ������� � ������ ��������� � ������������ ���������
            }
        }
        std::wcout << L"����������� �������: " << min << L", �������: ";
        for (int index : minIndices) {
            std::wcout << index << L" "; // ����� �������� ����������� ��������
        }
        std::wcout << L"\n������������ �������: " << max << L", �������: ";
        for (int index : maxIndices) {
            std::wcout << index << L" "; // ����� �������� ������������ ��������
        }
        std::wcout << std::endl;
    }

    // ������ 2: ���������� ����� � ������������ ���������
    void sumAndProduct() {
        double sum = 0, product = 1; // ������������� ����� � ������������
        for (double num : arr) {
            sum += num; // ������������ ���������
            product *= num; // ��������� ���������
        }
        std::wcout << L"����� ���������: " << sum << std::endl;
        std::wcout << L"������������ ���������: " << product << std::endl;
    }

    // ������ 3: ���������� �������� ��������������� � �������� ���������������
    void mean() {
        double arithmeticMean = 0, geometricMean = 1; // ������������� ������� ��������
        for (double num : arr) {
            arithmeticMean += num; // ������������ ��� �������� ���������������
            geometricMean *= num; // ��������� ��� �������� ���������������
        }
        arithmeticMean /= arr.size(); // ���������� �������� ���������������
        geometricMean = pow(geometricMean, 1.0 / arr.size()); // ���������� �������� ���������������
        std::wcout << L"������� ��������������: " << arithmeticMean << std::endl;
        std::wcout << L"������� ��������������: " << geometricMean << std::endl;
    }

    // ������ 4: ������� ������ � �������� ���������
    void countEvenAndOdd() {
        int evenCount = 0, oddCount = 0; // ������������� ���������
        for (double num : arr) {
            int roundedNum = static_cast<int>(round(num)); // ���������� �����
            if (roundedNum % 2 == 0)
                evenCount++; // ���������� �������� ������ �����
            else
                oddCount++; // ���������� �������� �������� �����
        }
        std::wcout << L"���������� ������ ���������: " << evenCount << std::endl;
        std::wcout << L"���������� �������� ���������: " << oddCount << std::endl;
    }

    // ������ 5: ����� �������� � �������
    void search(double value) {
        int count = 0; // ������� ���������
        std::wcout << L"������� �������� " << value << L": ";
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] == value) {
                std::wcout << i << L" "; // ����� ������� ���������
                count++;
            }
        }
        std::wcout << L"\n���������� ���������: " << count << std::endl;
    }

    // ������ 6: ���������� ������� ������� Selection
    void selectionSort(bool ascending) {
        for (int i = 0; i < static_cast<int>(arr.size()) - 1; ++i) {
            // ������������� ������� ������������/������������� ��������
            int min_max_index = i;
            for (int j = static_cast<int>(i) + 1; j < static_cast<int>(arr.size()); ++j) {
                // ����� ������������ ��� ������������� �������� 
                //� ����������� �� ��������� ascending
                if (ascending ? (arr[j] < arr[min_max_index]) : (arr[j] > arr[min_max_index])) {
                    min_max_index = j;
                }
            }
            if (min_max_index != i) {
                std::swap(arr[i], arr[min_max_index]); // ����� ���������
            }
        }
    }

    // ����� ��� ������ �������
    void displayArray() {
        std::wcout << L"������: ";
        for (double num : arr) {
            std::wcout << num << L" "; // ����� ��������� �������
        }
        std::wcout << std::endl;
    }
};

int main() {
    // ��������� ����������� ��� ��������� ���������
    std::locale::global(std::locale("ru_RU.UTF-8"));

    // ��������� ������� ��� ������ � UTF-8
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    int N; // ������ �������
    std::wcout << L"������� ����������� �������: ";
    std::wcin >> N;

    ArrayProcessor ��; // �������� ������� ������ ArrayProcessor
    ��.inputArray(N); // ���� ������� �������������

    // ���������� �����
    ��.findMinMax(); // ����� ������������� � ������������ ���������
    ��.sumAndProduct(); // ���������� ����� � ������������ ���������
    ��.mean(); // ���������� �������� ��������������� � ���������������
    ��.countEvenAndOdd(); // ������� ������ � �������� ���������

    double searchValue; // �������� ��� ������
    std::wcout << L"������� �������� ��� ������: ";
    std::wcin >> searchValue;
    ��.search(searchValue); // ����� �������� � �������

    // ���������� � ����� �������
    ��.selectionSort(true); // ���������� �� �����������
    std::wcout << L"��������������� ������ �� �����������: ";
    ��.displayArray(); // ����� ���������������� �������

    ��.selectionSort(false); // ���������� �� ��������
    std::wcout << L"��������������� ������ �� ��������: ";
    ��.displayArray(); // ����� ���������������� �������

    return 0;
}
