#include "train.h"

using namespace std;

// Конструктор по умолчанию
TRAIN::TRAIN() : trainNumber(0) {}

// Пользовательский конструктор с параметрами
TRAIN::TRAIN(string dest, int number, string time)
    : destination(dest), trainNumber(number), departureTime(time) {}

// Получаем значений полей
string TRAIN::getDestination() const {
    return destination;
}

int TRAIN::getTrainNumber() const {
    return trainNumber;
}

string TRAIN::getDepartureTime() const {
    return departureTime;
}

// Перегрузка оператора ввода для удобного ввода данных о поезде
istream& operator>>(istream& input, TRAIN& train) {
    cout << "Введите пункт назначения: ";
    input >> train.destination;

    cout << "Введите номер поезда: ";
    input >> train.trainNumber;

    cout << "Введите время отправления: ";
    input >> train.departureTime;

    return input;
}

// Перегрузка оператора вывода для удобного вывода данных о поезде
ostream& operator<<(ostream& output, const TRAIN& train) {
    output << "Номер поезда: " << train.trainNumber << "\nПункт назначения: " << train.destination
        << "\nВремя отправления: " << train.departureTime << "\n";
    return output;
}
