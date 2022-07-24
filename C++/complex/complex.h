#include<cmath>

class Complex
{
private:
    double m_Re;
    double m_Im;

public:
    Complex(double Re=0, double Im=0){
        m_Re = Re;
        m_Im = Im;
    }
    double Re() const { return m_Re; }
    double Im() const{ return m_Im; }
    friend double abs(const Complex &num);

    friend Complex operator+(const Complex &num1, const Complex &num2);
    friend Complex operator-(const Complex &num1, const Complex &num2);
    friend Complex operator*(const Complex &num1, const Complex &num2);
    friend Complex operator/(const Complex &num1, const Complex &num2);

    friend Complex operator+(const Complex &num1, const double &num);
    friend Complex operator-(const Complex &num1, const double &num);
    friend Complex operator-(const double &num, const Complex &num1);
    friend Complex operator*(const Complex &num1, const double &num);
    friend Complex operator/(const Complex &num1, const double &num);
    friend Complex operator/(const double &num, const Complex &num1);

    Complex operator-() const {
        return {-m_Re, -m_Im};
    }
    Complex operator+() const {
        return *this;
    }
    friend bool operator==(const Complex &num1, const Complex &num2);
    friend bool operator!=(const Complex &num1, const Complex &num2);
};

double abs(const Complex &num){
    double a = num.m_Re;
    double b = num.m_Im;
    return sqrt((a*a) + (b*b));
}


Complex operator+(const Complex &num1, const Complex &num2){
    double a = num1.m_Re;
    double b = num1.m_Im;
    double c = num2.m_Re;
    double d = num2.m_Im;
    return {a+c, b+d};
}

Complex operator+(const Complex &num1, const double &num){
    return {num1.m_Re + num, num1.m_Im};
}

Complex operator-(const Complex &num1, const Complex &num2){
    double a = num1.m_Re;
    double b = num1.m_Im;
    double c = num2.m_Re;
    double d = num2.m_Im;
    return {a-c, b-d};
}
Complex operator-(const Complex &num1, const double &num){
    return {num1.m_Re - num, num1.m_Im};
}

Complex operator-(const double &num, const Complex &num1){
    return {num - num1.m_Re, -num1.m_Im};
}

Complex operator*(const Complex &num1, const Complex &num2){
        double a = num1.m_Re;
        double b = num1.m_Im;
        double c = num2.m_Re;
        double d = num2.m_Im;
    return { (a*c - b*d), (b*c + a*d)};
}
Complex operator*(const Complex &num1, const double &num){
    return { num1.m_Re*num, num1.m_Im*num};
}

Complex operator/(const Complex &num1, const Complex &num2){
        double a = num1.m_Re;
        double b = num1.m_Im;
        double c = num2.m_Re;
        double d = num2.m_Im;
        double Re = (a*c+b*d) / (c*c + d*d);
        double Im = (b*c-a*d) / (c*c + d*d);
    return {Re, Im};
}

Complex operator/(const Complex &num1, const double &num){
    return { num1.m_Re/num, num1.m_Im/num};
}

Complex operator/( const double &num, const Complex &num1){
    double a = num1.m_Re;
    double b = num1.m_Im;
    double Re = a*num/(a*a + b*b);
    double Im = -b*num/(a*a + b*b);
    return {Re, Im};
}

bool operator==(const Complex &num1, const Complex &num2){
    double a = num1.m_Re;
    double b = num1.m_Im;
    double c = num2.m_Re;
    double d = num2.m_Im;
    if((a == c) && (b == d)){
        return true;
    }
    else{
        return false;
    }
}

bool operator!=(const Complex &num1, const Complex &num2){
    double a = num1.m_Re;
    double b = num1.m_Im;
    double c = num2.m_Re;
    double d = num2.m_Im;
    if((a != c) || (b != d)){
        return true;
    }
    else{
        return false;
    }
}
