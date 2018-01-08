#include <cstdio>
#include <string>
#include <utility>
using namespace std;

//compare the weight of ball "a" & "b"
bool compare(char a, char b)
{
	if (a == b)
		return false;
	printf("? %c %c\n", a, b);
	fflush(stdout);
	char ans;
	scanf(" %c", &ans);
	return ans == '>';
}

template <class T>
void quick_sort(T b, T e)
{
	if (b == e)
		return;
	auto l = b, r = e - 1;
	while (l < r)
	{
		while (compare(*r, *b))
			r--;
		while (!compare(*l, *b) && l < r)
			l++;
		std::swap(*l, *r);
	}
	std::swap(*b, *l);
	quick_sort(b, l);
	quick_sort(l + 1, e);
}

int main(void)
{
	int N, Q, i, j;

	scanf("%d%d", &N, &Q);

	string s;
	for (i = 0; i < N; i++)
		s += (char)('A' + i);
	quick_sort(s.begin(), s.end());
	printf("! %s\n", s.c_str());
	fflush(stdout);

	return 0;
}
