#include <iostream>
#include <numeric>
#include <functional>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
int main()
{
	int a[] = {1, 2, 3, 4, 5};
	const int N = sizeof(a) / sizeof(int);
	cout << "The result by multipling all elements in A is"
		 << accumulate(a, a + N, 1, multiplies<int>())//调用标准函数对象 
		 << endl;
	int intArr[]= {30, 90, 10, 40, 70, 50, 20, 80};
	const int M = sizeof(intArr) / sizeof(int);
	vector<int> b(intArr, intArr + M);
	cout << "before sorting:" << endl;
	copy(b.begin(), b.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	sort(b.begin(), b.end(), greater<int>());
	cout << "after sorting:" << endl;
	copy(b.begin(), b.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl; 
}
