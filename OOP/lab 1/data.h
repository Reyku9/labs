#pragma once 

#include <iostream>

class Data 
{
    int day_, month_, year_;
public:
    Data(); //конструктор по умолчанию
    Data(int, int, int); // конструктор с аргументами Предусмотреть корректность ввода
    // ввод/вывод 
    void input();
    void output() const;
    //определить время года
    void season() const; //вывод значения череде cout без return
    //аксессоры
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    //определить, является ли год високосным
    bool isLeapYear() const;
    // определить, сколько дней прошло от начала года;
    int daySinceStartYear() const;
    // определить, является ли текущая дата праздничным днем
    bool isHoliday() const;
    // проверить, совпадают ли две даты
    bool operator==(const Data& other) const;
    //нахождение количества дней, оставшихся до нового года
    int numsDayUntilNewYear() const;
    //вычислить, сколько дней между двумя датами
    int operator-(const Data& other) const;
    // проверить попадание в заданный временной промежуток.
    bool inInterval(const Data& a, const Data& b) const;
};