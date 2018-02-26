#include <cstdint>
#include <iostream>


int main()
{

    uint64_t end_with_1 = 0;
    uint64_t end_with_0 = 0;
    uint64_t NUMBER;

    std::cin >> NUMBER;
    for (uint32_t i = 0; i < NUMBER; i++)
    {
        uint64_t tmp;
        if (i == 0)
        {
            end_with_1 = 1;
            end_with_0 = 0;
        }
        else
        {
            tmp = end_with_1;
            end_with_1 = end_with_0;
            end_with_0 = end_with_0 + tmp;
        }
    }
    std::cout << end_with_0 + end_with_1 << std::endl;
    return 0;
}
