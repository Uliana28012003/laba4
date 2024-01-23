#include "train.h"

using namespace std;

// ����������� �� ���������
TRAIN::TRAIN() : trainNumber(0) {}

// ���������������� ����������� � �����������
TRAIN::TRAIN(string dest, int number, string time)
    : destination(dest), trainNumber(number), departureTime(time) {}

// �������� �������� �����
string TRAIN::getDestination() const {
    return destination;
}

int TRAIN::getTrainNumber() const {
    return trainNumber;
}

string TRAIN::getDepartureTime() const {
    return departureTime;
}

// ���������� ��������� ����� ��� �������� ����� ������ � ������
istream& operator>>(istream& input, TRAIN& train) {
    cout << "������� ����� ����������: ";
    input >> train.destination;

    cout << "������� ����� ������: ";
    input >> train.trainNumber;

    cout << "������� ����� �����������: ";
    input >> train.departureTime;

    return input;
}

// ���������� ��������� ������ ��� �������� ������ ������ � ������
ostream& operator<<(ostream& output, const TRAIN& train) {
    output << "����� ������: " << train.trainNumber << "\n����� ����������: " << train.destination
        << "\n����� �����������: " << train.departureTime << "\n";
    return output;
}
