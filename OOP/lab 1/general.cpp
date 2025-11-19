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

    //9) нахождение количества дней, оставшихся до нового года
    std::cout<<"Нахождение количества дней, оставшихся до нового года"<<std::endl;
    Data x7;
    x7.input(); x7.output();
    int b3 = x7.numsDayUntilNewYear();
    std::cout<<"Дней до нового года - "<<b3;



    //10) вычислить, сколько дней между двумя датами
    Data x8, x9;
    std::cout<<"Введите даты для вычисления дней мемжду ними"<<std::endl;
    x8.input(); x8.output();
    x9.input(); x9.output();
    int b4 = x8 - x9;
    std::cout<<"дней между датами - "<<b4<<std::endl;


    //11)проверить попадание в заданный временной промежуток
    std::cout<<"Проверить попадание в заданный временной промежуток"<<std::endl;
    Data x10, int1, int2;
    x10.input(); x10.output();
    std::cout<<"Введите две даты интервала"<<std::endl;
    int1.input(); int1.output();
    int2.input(); int2.output();
    if(x10.inInterval(int1, int2)) std::cout<<"Входит в промежуток"<<std::endl;
    else std::cout<<"Не входит в промежуток"<<std::endl;

    //12) сравнить дату с текущей датой (прошлое или будущее);
    Data x11, x12;
    x11.input(); x11.output();
    x12.input(); x12.output();
    x11.compare(x12);
    return 0;
}