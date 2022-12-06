#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

#define NUMBER_OF_ROWS 5000

int main()
{
    for(int i = 0; i <= NUMBER_OF_ROWS; i++)
	{
		int a = (int)(2.0 * rand() / double(RAND_MAX));
		int b = (int)(2.0 * rand() / double(RAND_MAX));

		int t = !(a && b); // should not be 1 or 1

		cout << "in: " << a << ".0 " << b << ".0 " << endl;
		cout << "out: " << t << ".0" << endl; 
	}
}
