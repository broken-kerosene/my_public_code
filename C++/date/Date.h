#include<iostream>
#include<map>
#include<stdexcept>

class Date{

private:
    int m_day;
    int m_month;
    int m_year;
    bool m_leap;
    std::map<int, int> m_cur_year;
    const std::map<int, int> m_com_year = {
        {1, 31}, {2, 28}, {3, 31}, {4, 30},
        {5, 31}, {6, 30}, {7, 31}, {8, 31},
        {9, 30}, {10,31}, {11,30}, {12,31}
        };
    const std::map<int, int> m_leap_year = {
        {1, 31}, {2, 29}, {3, 31}, {4, 30},
        {5, 31}, {6, 30}, {7, 31}, {8, 31},
        {9, 30}, {10,31}, {11,30}, {12,31}
        };

public:
    Date(int day, int month, int year){
        if(date_check(day, month, year)){
            m_day = day;
            m_month = month;
            m_year = year;
            m_leap = leap_check(year);
            if(m_leap)
                m_cur_year = m_leap_year;
            else
                m_cur_year = m_com_year;
        }
        else{
            throw std::invalid_argument("invalid year");
        }

    }

//блок геттеров
    int GetDay()   const {return m_day;}
    int GetMonth() const {return m_month;}
    int GetYear()  const {return m_year;}

//блок перегрузки оператора сравнения !=
    friend bool operator!=(const Date &date1, const Date &date2);

//блок перегрузки унарных операторов инкремента и декермента
    Date& operator++();
    Date& operator--();

//блок перегрузки бинарных операторов сложения и вычитания
    friend Date operator+(const Date &date, const int &num);
    friend Date operator-(const Date &date, const int &num);
    friend int operator-(const Date &date1, const Date &date2); //разность двух дат

private:
    bool date_check(int day, int month, int year);
    bool leap_check(int year);
};

//оператор сравнения !=
bool operator!=(const Date &date1, const Date &date2){
    if(date1.m_day == date2.m_day){
        if(date1.m_month == date2.m_month){
            if(date1.m_year == date2.m_year){
                return false;
            }
        }
    }
    return true;
}

//бинарный оператор сложения date + num
Date operator+(const Date &date, const int &num){
    Date new_date = date;
    for(int i=0; i<num; i++ ){
        ++new_date;
    }
    return new_date;
}
//бинарный оператор разности date - num
Date operator-(const Date &date, const int &num){
    Date new_date = date;
    for(int i=0; i<num; i++ ){
        --new_date;
    }
    return new_date;
}
//бинарный оператор разности date1 - date2
int operator-(const Date &date1, const Date &date2){
    Date new_date = date1;
    int count = 0;
        while(new_date != date2){
            --new_date;
            ++count;
        }
    return count;
}

//оператор инкремента
Date& Date::operator++(){
    //проверка перехода через 1 января
    if(m_day == 31 && m_month == 12){
        m_day = 1;
        m_month = 1;
        ++m_year;
        if(m_year > 2099){
            m_year = 1970;
            m_leap = leap_check(m_year);
            return *this;
        }
        else{
            m_leap = leap_check(m_year);
            return *this;
        }
    }

    if((m_day+1) > m_cur_year[m_month]){
        m_day = 1;
        ++m_month;
    }
    else{
        ++m_day;
    }
    return *this;
}

//оператор декремента
Date& Date::operator--(){
    //проверка перехода через 31 декабря
    if(m_day == 1 && m_month == 1){
        m_day = 31;
        m_month = 12;
        --m_year;
        if(m_year < 1970){
            m_year = 2099;
            m_leap = leap_check(m_year);
            return *this;
        }
        else{
            m_leap = leap_check(m_year);
            return *this;
        }
    }

    if((m_day-1) < 1){
        --m_month;
        m_day = m_cur_year[m_month];

    }
    else{
        --m_day;
    }
    return *this;
}

//функция проверки даты на корректность
bool Date::date_check(int day, int month, int year){
    std::map<int, int> cur_year;
    if(leap_check(year)){
        cur_year = Date::m_com_year;
    }
    else{
        cur_year = Date::m_leap_year;
    }

    if(year > 2099 || year < 1970){
        return false;
    }
    else if(cur_year.find(month) == cur_year.end()){
        return false;
    }
    else if(day > cur_year[month] || day < 1){
        return false;
    }
    else{
        return true;
    }

}

//функция проверки высокосный год или нет
bool Date::leap_check(int year){
    if(year % 400 == 0){
        return true;
    }
    else if(year % 100 == 0){
        return false;
    }
    else if(year % 4 == 0){
        return true;
    }
    else{
        return false;
    }
}
