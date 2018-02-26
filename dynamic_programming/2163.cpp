#include <cstdint>
#include <iostream>

int main()
{
    uint32_t n;
    uint32_t m;

    std::cin >> n;
    std::cin >> m;

    std::cout<< n-1 + (n)*(m-1) << std::endl;
    return 0;
}