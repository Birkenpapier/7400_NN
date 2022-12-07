#include "IC_main.hpp"

using namespace std;

void printVector(string label, vector<double> &v)
{
	cout << label << " ";
	for(uint8_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
