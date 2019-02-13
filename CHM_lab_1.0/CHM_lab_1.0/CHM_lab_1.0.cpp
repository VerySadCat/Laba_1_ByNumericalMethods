// CHM_lab_1.0.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "CreateInterpol.h"
#include "Interpol.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	CreateInterpol value;
	Interpol val;
	int rezult = value.createXY();
	switch (rezult)
	{
	case 0: 
		val.getValue(value);
		val.creatPointInterpol();
		val.Lagrang();
		cout << val.setYY() << endl;
		break;
	case 1: 
		cout << "Интерполяционный многочлен степени m не может быть построен"<< endl; break;
	case 2:
		cout << "Нарушен порядок возрастания аргумента в входном векторе X" << endl; break;
	case 3:
		cout << "Не хватает точек, чтобы построить многочлен." << endl; break;
	default:
		break;
	}

	system("pause");
	return 0;
}

