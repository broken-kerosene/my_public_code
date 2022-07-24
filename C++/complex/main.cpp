#include <iostream>
#include "complex.h"


int main()
{
   Complex num1(2, 3);
   std::cout << "num1: Re="<< num1.Re() <<" Im="<< num1.Im() << std::endl;
   Complex num2(1, -4);
   std::cout << "num2= "<< num2.Re() <<' '<< num2.Im() << std::endl;
   Complex num3;
   num3 = -num1;
   std::cout << "num3 = -num1 "<< num3.Re() <<' '<< num3.Im() << std::endl;
   num3 = +num1;
   std::cout << "num3 = +num1 "<< num3.Re() <<' '<< num3.Im() << std::endl;

   if(num1 == num2){
       std::cout << "num1 == num2 "<< "yes" << std::endl;
   }

   int num = 5;
   num3 = num1 + num2;
   std::cout << "num1 + num2 "<< num3.Re() <<' '<< num3.Im() << std::endl;
   std::cout << "abs(num3)="<< abs(num3) << std::endl;

   if(num1 != num3){
       std::cout <<  "num1 != num3 "<< "yes" << std::endl;
   }

   num3 = num - num2;
   std::cout << "num - num2 "<< num3.Re() <<' '<< num3.Im() << std::endl;

   num3 = num2 - num;
   std::cout << "num2 - num "<< num3.Re() <<' '<< num3.Im() << std::endl;

   num3 = num1 / num2;
   std::cout << "num1 / num2 "<< num3.Re() <<' '<< num3.Im() << std::endl;

   num3 = num / num2;
   std::cout << "num / num2 "<< num3.Re() <<' '<< num3.Im() << std::endl;

   num3 = num2 / num;
   std::cout << "num2 / num "<< num3.Re() <<' '<< num3.Im() << std::endl;

   num3 = num1 * num2;
   std::cout << "num1 * num2 "<< num3.Re() <<' '<< num3.Im() << std::endl;

   num3 = num1 * num;
   std::cout << "num1 * num "<< num3.Re() <<' '<< num3.Im() << std::endl;

   num3 = num * num1;
   std::cout << "num * num1 "<< num3.Re() <<' '<< num3.Im() << std::endl;
   return 0;
}
