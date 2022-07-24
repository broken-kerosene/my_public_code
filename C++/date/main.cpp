#include "Date.h"

int main()
{

    Date ne(1, 02, 2020);
    Date ne2(1, 03, 2020);
    Date new_ne(28, 02, 2020);
    ++ne;
    std::cout << ne.GetDay() << ' ' << ne.GetMonth() << ' ' << ne.GetYear() << std::endl;
    --ne;
    std::cout << ne.GetDay() << ' ' << ne.GetMonth() << ' ' << ne.GetYear() << std::endl;
    int num = 30;
    std::cout << (ne + num).GetDay() << ' ' << (ne + num).GetMonth() << ' ' << (ne + num).GetYear() << std::endl;

    std::cout << (ne - num).GetDay() << ' ' << (ne - num).GetMonth() << ' ' << (ne - num).GetYear() << std::endl;


    std::cout << "days= " << (ne2 - ne) << std::endl;
    return 0;
}
