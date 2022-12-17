// Some examples
#include <iostream>
#include <vector>
#include <algorithm>


// test of lambda functions applied to vectors
void lambda_test()
{
    auto print = [](const int& n) { std::cout << " " << n; };
    auto print2 = [i = 0](int a) mutable {std::cout << "v[" << i << "] = " << a << "\n"; ++i; };
    const int vectorSize = 12;

    //Identity : v[i] = i
    std::vector<int> v(vectorSize, 0);
    std::generate(v.begin(), v.end(), [i = 0]() mutable { return i++; });
    std::cout << "v[i] = i: ";
    for_each(v.begin(), v.end(), print);
    std::cout << std::endl;

    // v[i] = v[i-1] + v[i-2]
    v[0] = 0;
    v[1] = 1;
    std::generate(v.begin() + 2, v.end(), [x = 0, y = 1]() mutable {int n = x + y; x = y; y = n; return n; });
    std::cout << "v[i] = v[i-1] + v[i-2]: \n";
    for_each(v.begin(), v.end(), print2);
    std::cout << std::endl;

    // using transform to create f = v / 2.0
    std::vector<float> f;
    std::transform(v.cbegin(), v.cend(), std::back_inserter(f), [](int c) { return  ((float)c / 2.0f); });
    std::cout << "(float) f[i] = v[i] / 2 :";
    auto printFloat = [](const float& n) { std::cout << " " << n; };
    for_each(f.begin(), f.end(), printFloat);
    std::cout << std::endl;

}

