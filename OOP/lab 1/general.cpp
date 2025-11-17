#include <iostream>
#include "data.h"
#include "data.cpp"
int main()
{
    setlocale(LC_ALL, "Russian");
    Data a1(12,12,2012), a2, a3; //1)конструктор
    a1.output();
    
    a1.input(); //2) ввод\вывод
    std::cout<<"Data a1 = "; a1.output();
    

    //3) определить время года
    std::cout<<"Время года - ";
    a1.season();

    //4) аксессоры
    std::cout << "Аксессоры" << std::endl;
    int n1, b1;
    std::cout<<"Введите месяц для Data a2"<<std::endl;
    std::cin>>n1;
    a2.setMonth(n1);
    std::cout << "Data a2 после установки аксессором месяца: ";
    a2.output();
    b1 = a2.getMonth();
    std::cout<<"Месяц - "<<b1<<std::endl;
    
    //5) определить, является ли год високосным
    std::cout<<"Определить, является ли год високосным"<<std::endl;
    int n2;
    std::cout<<"Введите год для Data a2"<<std::endl;
    std::cin>>n2;
    a2.setYear(n2);
    a2.output();
    if(a2.isLeapYear()) std::cout<<a2.getYear()<<" - висаксоный год"<<std::endl;
    else std::cout<<a2.getYear()<<"- не висакосный год"<<std::endl;
    

    //6)определить, сколько дней прошло от начала года
    std::cout<<"определить, сколько дней прошло от начала года"<<std::endl;
    a3.input();
    a3.output();
    int b2 = a3.daySinceStartYear();
    std::cout<<"Дней от начала года - "<<b2<<std::endl;
    

    //7) определить, является ли текущая дата праздничным днем
    std::cout<<"определить, является ли текущая дата праздничным днем"<<std::endl;
    Data x4;
    x4.input(); x4.output();
    if(x4.isHoliday()) std::cout<<"праздничная дата"<<std::endl;
    else std::cout<<"обычная дата"<<std::endl;



    //8) проверить, совпадают ли две даты
    Data x5, x6;
    std::cout<<"Введите даты для сравнения"<<std::endl;
    x5.input(); x5.output();
    x6.input(); x6.output();
    if(x5==x6) std::cout<<"Даты равны"<<std::endl;
    else std::cout<<"Даты не равны"<<std::endl;
}