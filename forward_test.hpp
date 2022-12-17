// Some examples
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct M1 {
	int * _a;

	M1(const int& a) noexcept
	{
		_a = new int;
		*_a = a;
		cout << "Constructor <const int & a> ["<<*_a<<"] ";
	};
	M1(M1&& m) noexcept
	{
		_a = m._a;
		m._a = nullptr;
		cout << "Constructor <M1&& m> [" << *_a << "] ";
	};
	M1(const M1& m) noexcept
	{
		_a = new int;
		_a = m._a;
		cout << "Constructor <const M1 & m> [" << *_a << "] ";
	};

};


void test_forward()
{
	cout << " M1 m(1) : ";
	M1 m(0);
	cout << "\n M1 n(M1(1)) : ";
	M1 n(M1(1));
	cout << "\n M1 o(m) : ";
	M1 o(m);
	cout << "\n M1 p(std::move(m)) : ";
	M1 p(std::move(m));
	cout << "\n M1 q(M1(M1(0))) : ";
	M1 q(M1(M1(1)));

	vector<M1> vm;
	vm.reserve(10);
;	cout << "\n vm.push_back(p) : ";
	vm.push_back(p);
	cout << "\n vm.emplace_back(q) : ";
	vm.emplace_back(q);
	cout << "\n vm.emplace_back(move(p)) : ";
	vm.emplace_back(move(p));
	cout << "\n vm.emplace_back(M1(5)) : ";
	vm.emplace_back((M1(5)));
	cout << "\n vm.push_back(M1(6)) : ";
	vm.push_back(M1(6));
}