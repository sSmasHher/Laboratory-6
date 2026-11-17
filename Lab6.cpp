/*****************************
* Автор: Полудинцев Никита   *
* Вариант: 23                *
* Название: Лабораторная 6   *
*****************************/

#include <iostream>
#include <iomanip>
#include <cmath>

#include <iostream>

using namespace std;

int countInInterval(const double* arr, int size, double a, double b) {
    if (arr == nullptr || size <= 0 || a >= b) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > a && arr[i] < b) {
            count++;
        }
    }
    return count;
}
void inputArray(double* arr, int size, char name) {
    if (size <= 0) return;
    cout << "Введите " << size << " элементов массива " << name << ": ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    double a, b;
    cout << "Введите границы интервала a и b (через пробел): ";
    cin >> a >> b;

    int n, m, k;
    cout << "Введите размеры массивов n, m, k (через пробел): ";
    cin >> n >> m >> k;

    double* A = (n > 0) ? new double[n] : nullptr;
    double* L = (m > 0) ? new double[m] : nullptr;
    double* T = (k > 0) ? new double[k] : nullptr;

    inputArray(A, n, 'A');
    inputArray(L, m, 'L');
    inputArray(T, k, 'T');

    int countA = countInInterval(A, n, a, b);
    int countL = countInInterval(L, m, a, b);
    int countT = countInInterval(T, k, a, b);

    cout << "\nРезультаты для интервала (" << a << ", " << b << "):\n";
    cout << "В массиве A элементов в интервале: " << countA << endl;
    cout << "В массиве L элементов в интервале: " << countL << endl;
    cout << "В массиве T элементов в интервале: " << countT << endl;

    delete[] A;
    delete[] L;
    delete[] T;

    return 0;
}

