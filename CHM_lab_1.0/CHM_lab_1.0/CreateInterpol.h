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
	if (!fin.is_open())//���� ���� �� ������;
	{
		switch (errno)
		{
		case (ENOENT) : std::cout << "������� ��� ��� ����� �� �������. ����������, ��������� ������� ����� ��� �������� ��������� ������." << std::endl; break;
		case(EMFILE) : std::cout << "� ���������, ������� ����� �������� ������. ����� �������� �����������, ���������, ������ ����� ����� ��������." << std::endl; break;
		case(EACCES) : std::cout << "������ � ������� ����� ��������, ���������� ������� ������ ����." << std::endl; break;
		default: std::cout << "�������� �������������� ������, ���� �� ����� ���� ������, ���������� �����" << std::endl;
		}
		return false;
	}
	return true;
}
class CreateInterpol
{
	
	vector<double> X, Y; // X - ������ �������� ����������, Y - ������ �������� �������
	double XX; // ����� ����������������
	int m, N, // N - ���-�� ����� ������������, m - ������� ���������� ��������
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

