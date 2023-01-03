#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

#define NUMBER_OF_ROWS 4
#define NUMBER_OF_NANDS 4

int main()
{
    int input_c = 1;
	
	for(int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		int a = (int)(2.0 * rand() / double(RAND_MAX));
		int b = (int)(2.0 * rand() / double(RAND_MAX));

		int t = !(a && b); // should not be 1 or 1

		cout << "in_" << input_c << ": " << a << ".0 " << b << ".0 " << endl;
		cout << "out_" << input_c << ": " << t << ".0" << endl;

		input_c++;
		input_c = (input_c > NUMBER_OF_NANDS) ? 1 : input_c;
	}
}
