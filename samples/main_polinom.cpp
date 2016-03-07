#include "polinom.h"
#include <stdlib.h>
#include <iostream>

using namespace std;
void main()
{
	bool end_work = false;
	int answer;
	int size_polinom;
	while (end_work==false)
	{
		Polinom polinom_1,polinom_2;
		Polinom polinom_res;
		monom input_monom;
		double input;
		cout << "Enter size of the first polinom: ";
		cin >> size_polinom;
		for (int i = 0; i < size_polinom;i++)
		{
			cout << "Element "<<i<<":  " << endl;
			cout << "	 Coefficient = ";
			cin >> input;
			input_monom.SetCoefficient(input);
			cout << "	 Degree = ";
			cin >> input;
			input_monom.SetDegree(input);
			polinom_1.AddElement(input_monom);
		}
		cout << "Enter size of the second polinom: ";
		cin >> size_polinom;
		for (int i = 0; i < size_polinom; i++) {
			cout << "Element " << i << ":  " << endl;;
			cout << "	Coefficient = ";
			cin >> input;
			input_monom.SetCoefficient(input);
			cout << "	Degree = ";
			cin >> input;
			input_monom.SetDegree(input);
			polinom_2.AddElement(input_monom);
		}

		polinom_res = polinom_1 + polinom_2;
		cout << endl;
		cout << "The sum: "<<endl;
		for (int i = 0; i < polinom_res.GetLength(); i++) {
			cout << "Element " << i << " = " << polinom_res[i].GetCoefficient() << "|" << polinom_res[i].GetDegree()<<endl;
		}

		cout << endl;
		polinom_res = polinom_1 * polinom_2;
		cout << "The multiply: " << endl;
		for (int i = 0; i < polinom_res.GetLength(); i++) {
			cout << "Element " << i << " = " << polinom_res[i].GetCoefficient() << "|" << polinom_res[i].GetDegree() << endl;
		}

		cout << endl;
		cout << "Continue work? (1-yes|0-no): ";
		cin >> answer;
		if (answer == 0)
		{
			end_work = true;
		}
		else
		{
			end_work = false;
		}
	}
	
}