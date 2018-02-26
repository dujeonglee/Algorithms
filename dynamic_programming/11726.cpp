#include <cstdint>
#include <iostream>

int main()
{
    uint32_t LENGTH = 0;
    uint32_t result[1001] = {0};
    std::cin >> LENGTH;
    result[1] = 1;
    result[2] = 2;
    for (uint32_t i = 3; i <= LENGTH; i++)
    {
        result[i] = (result[i - 1] + result[i - 2])%10007;
    }
    std::cout << result[LENGTH] << std::endl;
    return 0;
}
