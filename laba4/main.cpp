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

        // ���� ������ � �������
        for (int i = 0; i < arraySize; ++i) {
            cout << "������� ������ ��� ������ " << i + 1 << ":\n";
            cin >> trainArray[i];
        }

        // ���������� ������� �� ������
        sort(trainArray, trainArray + arraySize, [](const TRAIN& a, const TRAIN& b) {
            return a.getTrainNumber() < b.getTrainNumber();
            });

        // ����� ��������������� ������
        cout << "\n��������������� ���������� � �������:\n";
        for (const auto& train : trainArray) {
            cout << train;
        }

        // ����� �� ������ ������
        int searchNumber;
        cout << "\n������� ����� ������ ��� ������: ";
        cin >> searchNumber;

        // ������������� ��������� find_if ��� ������ �� ������ ������
        auto it = find_if(trainArray, trainArray + arraySize, [searchNumber](const TRAIN& train) {
            return train.getTrainNumber() == searchNumber;
            });

        // ����� ���������� ������
        if (it != trainArray + arraySize) {
            cout << "\n����� ������:\n" << *it;
        }
        else {
            cout << "\n����� � ������� " << searchNumber << " �� ������.\n";
        }

        return 0;
    }
}
