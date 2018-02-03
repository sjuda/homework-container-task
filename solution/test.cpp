#include <iostream>

#include "array.hpp"

int main()
{
    array<int, 10> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    array<int, 10> a1;

    const array<int, 10> b = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    array<int, 1> c;

    std::cout << b.size() << std::endl;
    std::cout << a.at(0) << " " << b.at(1) << std::endl;
    std::cout << a[1] << " " << b[1] << std::endl;
    a[1] = 11;
    std::cout << a[1] << std::endl;

    std::cout << a.back() << " " << a.front() << std::endl;

    std::cout << a.empty() << std::endl;

    a1.fill(1234);

    a.swap(a1);

    for (int i : a)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << std::boolalpha << (a == b) << std::endl;
}
