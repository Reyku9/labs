#include <iostream>
#include "data.h"

//конструкторы 
Data::Data() : day_(1), month_(1), year_(2000) {}
Data::Data(int day, int month, int year) : day_(day), month_(month), year_(year) 
{
    if(day_>31 || day_<1) day_ = 28;
    if(month_>12 || month_ < 1) month_ = 12;
    if(year_ > 9999 || year_ < 1000) year_ = 2000;
    if(day_>29 && month_ == 2) day = 28;
    if(day_>30 && (month == 4 || month == 6 || month == 9 || month == 11)) day_ = 28;
}
//Ввод/вывод
void Data::input()
{
    std::cout<<"Введите день(x), месяц(x), год(xxxx)"<<std::endl;
    std::cin>>day_>>month_>>year_;
    if(day_>31 || (day_>29 && month_ == 2) || day_ < 1)
    {
        std::cout<<"Ошибка ввода дня, значение изменено на стандартное - 28"<<std::endl;
        day_ = 28;
    }
    if(month_ > 12 || month_ < 1)
    {
        std::cout<<"Ошибка ввода месяца, значение изменено на стандартное - 12"<<std::endl;
        month_ = 12;
    }
    if(year_ > 9999 || year_ < 1000)
    {
        std::cout<<"Ошибка ввода года, значение изменено на стандартное - 2000"<<std::endl;
        year_ = 2000;
    }
}
void Data::output() const
{
    std::cout<<day_<<'.'<<month_<<'.'<<year_<<std::endl;
}
//определить время года
void Data::season() const
{
    switch (month_)
    {
    case 12:
    case 1:
    case 2:
        std::cout<<"Зима"<<std::endl;
        break;
    case 3:
    case 4:
    case 5:
        std::cout<<"Весна"<<std::endl;
        break;
    case 6:
    case 7:
    case 8:
        std::cout<<"Лето"<<std::endl;
        break;
    case 9:
    case 10:
    case 11:
        std::cout<<"Осень"<<std::endl;
        break;
    }
}
//Аксессоры
int Data::getDay() const {return day_;}
int Data::getMonth() const {return month_;}
int Data::getYear() const {return year_;}

void Data::setDay(int day)
{
    day_ = day;
    if(day_>31 || (day_>29 && month_ == 2) || day_<1)
    {
        std::cout<<"Ошибка ввода дня, значение изменено на стандартное - 28"<<std::endl;
        day_ = 28;
    }
}
void Data::setMonth(int month)
{
    month_ = month;
    if(month_ > 12 || month_ < 1)
    {
        std::cout<<"Ошибка ввода месяца, значение изменено на стандартное - 12"<<std::endl;
        month_ = 12;
    }
}
void Data::setYear(int year) 
{
    year_ = year;
    if(year_ > 9999 || year_<1000)
    {
        std::cout<<"Ошибка ввода года, значение изменено на стандартное - 2000"<<std::endl;
        year_ = 2000;
    }
    
}
//определить, является ли год високосным
bool Data::isLeapYear() const
{
    if(year_ % 4 == 0 && (year_ % 100 != 0 || (year_ % 100 == 0 && year_%400 == 0))) return true;
    return false;
}
// определить, сколько дней прошло от начала года;
int Data::daySinceStartYear() const
{   
    int month = month_ - 1;
    int cnt = 0;
    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i = 0;i<month;i++)
    {
        cnt += arr[i];
    }
    cnt += day_;
    if(isLeapYear()) cnt++;
    return cnt;
}
// определить, является ли текущая дата праздничным днем
bool Data::isHoliday() const
{
    if (month_ == 1 && (day_>=1 || day_<= 10)) return true;
    // 7 января - Рождество
    if (month_ == 1 && day_ == 7) return true;
    // 23 февраля
    if (month_ == 2 && day_ == 23) return true;
    // 8 марта
    if (month_ == 3 && day_ == 8) return true;
    // 1 мая
    if (month_ == 4 && day_ == 1) return true;
    // 9 мая
    if (month_ == 4 && day_ == 9) return true;
    // 12 июня
    if (month_ == 6 && day_ == 12) return true;
    // 4 ноября
    if (month_ == 11 && day_ == 4) return true;
    
    return false;
}
// проверить, совпадают ли две даты
bool Data::operator==(const Data& other) const
{
    return (day_ == other.day_) && (month_ == other.month_) && (year_ == other.year_);
}