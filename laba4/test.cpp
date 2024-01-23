#include "test.h"
#include "train.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

int test() {
    // Создаем объект TRAIN с заданными параметрами
    TRAIN Train("Москва", 123, "12:11");

    // Тест 1: Вывод на экран
    cout << "Тест 1: Вывод на экран\n";
    cout << Train << endl;

    // Создаем объект TRAIN без параметров для теста ввода с клавиатуры
    TRAIN TrainInput;

    // Тест 2: Ввод с клавиатуры
    cout << "Тест 2: Ввод с клавиатуры\n";

    // Создаем поток ввода, имитирующий ввод с клавиатуры
    istringstream input("Москва\n12\n11\n");

    // Считываем данные с клавиатуры в объект TrainInput
    input >> TrainInput;

    // Выводим ожидаемые значения для сравнения
    cout << "\nМосква\n12\n11\n";

    // Проверяем, что введенные данные соответствуют ожидаемым
    assert(TrainInput.getDestination() == "Москва");
    assert(TrainInput.getTrainNumber() == 12);
    assert(TrainInput.getDepartureTime() == "12:11");

    return 1;
}
