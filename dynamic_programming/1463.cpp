#include <cstdint>
#include <iostream>

int main()
{
    uint32_t minimum_operations[1000000] = {0xffffffff,};
    uint32_t target;
    std::cin >> target;

    minimum_operations[1] = 0;
    minimum_operations[2] = 1;
    minimum_operations[3] = 1;

    if (target == 1)
    {
        std::cout << "0" << std::endl;
    }
    else if (target == 2)
    {
        std::cout << "1" << std::endl;
    }
    else if (target == 3)
    {
        std::cout << "1" << std::endl;
    }
    else
    {
        for (uint32_t i = 4; i <= target; i++)
        {
            minimum_operations[i] = 0xffffffff;
            if ((i % 3) == 0)
            {
                if (minimum_operations[i] > minimum_operations[i / 3] + 1)
                {
                    minimum_operations[i] = minimum_operations[i / 3] + 1;
                }
            }
            if ((i % 2) == 0)
            {
                if (minimum_operations[i] > minimum_operations[i / 2] + 1)
                {
                    minimum_operations[i] = minimum_operations[i / 2] + 1;
                }
            }
            if (minimum_operations[i] > minimum_operations[i - 1] + 1)
            {
                minimum_operations[i] = minimum_operations[i - 1] + 1;
            }
        }
        std::cout << minimum_operations[target] << std::endl;
    }
    return 0;
}
