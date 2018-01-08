
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
template <class T>

void quick_sort(T b, T e)
{
	if (b == e)
		return;
	auto l = b, r = e - 1;
	cout << "!:" << *l << " " << *r << endl;
	while (l < r)
	{
		cout << *l << " " << *r << endl;
		while (*r > *b)
			r--;
		while (*l <= *b && l < r)
			l++;
		std::swap(*l, *r);
	}
	std::swap(*b, *l);
	quick_sort(b, l);
	quick_sort(l + 1, e);
}

int main()
{
	vector<int> v{10, 5, 8, 3, 1};
	quick_sort(v.begin(), v.end());
	for (auto x : v)
	{
		cout << x << endl;
	}
}
