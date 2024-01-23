#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>

class TRAIN {
private:
    std::string destination;    
    int trainNumber;            
    std::string departureTime;  

public:
    // Конструкторы
    TRAIN();
    TRAIN(std::string dest, int number, std::string time);

    // Геттеры-методы, которые предназначены для получения значений приватных переменных объекта
    std::string getDestination() const;
    int getTrainNumber() const;
    std::string getDepartureTime() const;

    // Перегрузка операторов ввода и вывода
    friend std::istream& operator>>(std::istream& input, TRAIN& train);
    friend std::ostream& operator<<(std::ostream& output, const TRAIN& train);
};

#endif // TRAIN_H
