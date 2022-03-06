#include <iostream>
using namespace std;
int main()
{

	int x[5][4], i, j;
	for (i = 0; i <= 4; i++)
	{

		for (j = 0; j <= 1; j++)
		{

			x[i][j] = rand() % 100;
			cout << x[i][j] << "\t";
		}
		/*		for (j = 2; j < 3; j++)
		{
			int op;
			int result;
			
			switch (op)
			{
			case '1':
			{
						result = x[i][0] + x[i][1];
						//cout << "Sum is " << result << endl;
						break;
			}
			case '2':
			{
						result = x[i][0] - x[i][1];
						//cout << "Subtraction is " << result << endl;
						break;
			}

			case '3':
			{
						result = x[i][0] * x[i][1];
						//cout << "Product is " << result << endl;
						break;
			}
			case '4':
			{
						result = x[i][0] / x[i][1];
						//cout << "Division is " << result << endl;
						break;
			}
			case '5':
			{
						result = x[i][0] % x[i][1];
						//cout << "Remainder is " << result << endl;
						break;
			}
				case '6':
				{cout << result << endl;
				break;
				}
			
			}
			op = rand() % 5 + 1;
			cout << op << endl;


		}*/
	}
	system("pause");
}