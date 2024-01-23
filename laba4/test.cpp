#include "test.h"
#include "train.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

int test() {
    // ������� ������ TRAIN � ��������� �����������
    TRAIN Train("������", 123, "12:11");

    // ���� 1: ����� �� �����
    cout << "���� 1: ����� �� �����\n";
    cout << Train << endl;

    // ������� ������ TRAIN ��� ���������� ��� ����� ����� � ����������
    TRAIN TrainInput;

    // ���� 2: ���� � ����������
    cout << "���� 2: ���� � ����������\n";

    // ������� ����� �����, ����������� ���� � ����������
    istringstream input("������\n12\n11\n");

    // ��������� ������ � ���������� � ������ TrainInput
    input >> TrainInput;

    // ������� ��������� �������� ��� ���������
    cout << "\n������\n12\n11\n";

    // ���������, ��� ��������� ������ ������������� ���������
    assert(TrainInput.getDestination() == "������");
    assert(TrainInput.getTrainNumber() == 12);
    assert(TrainInput.getDepartureTime() == "12:11");

    return 1;
}
