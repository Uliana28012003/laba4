#include <iostream>
#include <algorithm>
#include <chrono>
#include "train.h"

using namespace std;
using namespace chrono;

class LogDuration {
public:
    LogDuration()
        : start(steady_clock::now())
    {
    }

    ~LogDuration() {
        auto finish = steady_clock::now();
        auto dur = finish - start;
        cerr << duration_cast<milliseconds>(dur).count()
            << " ms" << endl;
    }
private:
    steady_clock::time_point start;
};

int main() {
    {

        LogDuration input;
        setlocale(LC_ALL, "Russian");

        const int arraySize = 3;
        TRAIN trainArray[arraySize];

        // Ввод данных о поездах
        for (int i = 0; i < arraySize; ++i) {
            cout << "Введите данные для поезда " << i + 1 << ":\n";
            cin >> trainArray[i];
        }

        // Сортировка поездов по номеру
        sort(trainArray, trainArray + arraySize, [](const TRAIN& a, const TRAIN& b) {
            return a.getTrainNumber() < b.getTrainNumber();
            });

        // Вывод отсортированных данных
        cout << "\nОтсортированная информация о поездах:\n";
        for (const auto& train : trainArray) {
            cout << train;
        }

        // Поиск по номеру поезда
        int searchNumber;
        cout << "\nВведите номер поезда для поиска: ";
        cin >> searchNumber;

        // Использование алгоритма find_if для поиска по номеру поезда
        auto it = find_if(trainArray, trainArray + arraySize, [searchNumber](const TRAIN& train) {
            return train.getTrainNumber() == searchNumber;
            });

        // Вывод результата поиска
        if (it != trainArray + arraySize) {
            cout << "\nПоезд найден:\n" << *it;
        }
        else {
            cout << "\nПоезд с номером " << searchNumber << " не найден.\n";
        }

        return 0;
    }
}
