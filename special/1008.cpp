#include <cstdint>
#include <iostream>

int main()
{
    int32_t A;
    int32_t B;
    std::cin >> A;
    std::cin >> B;

    int32_t INT;

    if (A / B > 0)
    {
        std::cout << A / B << ".";
        A -= (A / B) * B;
    }
    else
    {
        std::cout << "0.";
    }
    int32_t cnt = 0;
    do
    {
        A *= 10;
        if (A / B > 0)
        {
            std::cout << A / B;
            A -= (A / B) * B;
            if(A == 0)
            {
                break;
            }
        }
        else
        {
            std::cout << "0";
        }
        cnt++;
    } while (cnt < 20);
    std::cout << std::endl;
    return 0;
}