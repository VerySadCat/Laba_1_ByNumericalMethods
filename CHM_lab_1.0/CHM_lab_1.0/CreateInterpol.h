#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
bool Open_file_ifstream(std::ifstream&fin)
{
	std::string line;
	std::cout << "Input the way file input: ";
	std::cin >> line;
	fin.open(line);
	if (!fin.is_open())//если файл не открыт;
	{
		switch (errno)
		{
		case (ENOENT) : std::cout << "Маршрут или имя файла не найдены. Пожалуйста, проверьте наличие файла или верность введенных данных." << std::endl; break;
		case(EMFILE) : std::cout << "К сожалению, слишком много открытых файлов. После закрытия большинства, программа, скорее всего будет работать." << std::endl; break;
		case(EACCES) : std::cout << "Доступ к данному файлу запрещен, попробуйте открыть другой файл." << std::endl; break;
		default: std::cout << "Возникла непредвиденная ошибка, файл не может быть открыт, попробуйте позже" << std::endl;
		}
		return false;
	}
	return true;
}
class CreateInterpol
{
	
	vector<double> X, Y; // X - вектор значений аргументов, Y - вектор значений функции
	double XX; // точка интерполирования
	int m, N, // N - кол-во узлов инторполяции, m - степень многочлена Логранжа
		omountOfPoints;
public:
	CreateInterpol(){};
	
	int setN(){ return N; }
	vector<double> setX(){ return X; }
	vector<double> setY(){ return Y; }
	int setM(){ return m; }
	double setPointXX(){return XX;}
	int createXY(){
		ifstream fout;
		int k;
		if (Open_file_ifstream(fout)){
			fout >> m; 
			fout >> N;
			if (N < m+1)	return 1;
			fout >> omountOfPoints;
			if (N > omountOfPoints) return 4;
			fout >> k;
			X.push_back(k);
			for (int i = 1; i < omountOfPoints; i++){
				fout >> k;
				if (X[i - 1] > k) return 2;
				X.push_back(k);
			}
			for (int j = 0; j < omountOfPoints; j++){
				fout >> k;
				Y.push_back(k);
			}
			fout >> XX;
		}
		fout.close();
		return 0;
	}
	~CreateInterpol(){};
};

