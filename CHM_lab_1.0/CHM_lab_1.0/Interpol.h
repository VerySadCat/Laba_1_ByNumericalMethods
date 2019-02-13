#pragma once
#include "CreateInterpol.h"

class Interpol
{
	CreateInterpol value;
	double YY = 0;
	vector<double> pointInterpolX, pointInterpolY;
public:
	Interpol(){};
	void getValue(CreateInterpol val){
		value = val;
	}

	void creatPointInterpol(){
		int countPoint = 0; // ���������� ����� ��� ������������
		double tempprev, tempnext; // �������� �� ����� �����, ��� ����� ������� �� ��
		double p = -1, k = value.setX().size() + 1; // ����� ��������
		vector<double> X = value.setX(), Y = value.setY(); // ����� ���� ��� ����������� ���� �������
		int i = 0; // ����� ��� ����: ���� X[i] == XX, ����� ����� i
		// ���� ����� ������� ����� � i
		for (; i < X.size(); i++){
			tempnext = i ;
			tempprev = i - 1;
			if (X[i] >= (value.setPointXX()))
				break;
		}
		if (i == X.size())
		{
			k--;
			i--;
			tempnext ++;
			tempprev ++;
		}
		// ��������, ������ �� ���� ������������ ��������
		if (X[i] == value.setPointXX()){
			pointInterpolX.push_back(X[i]);
			pointInterpolY.push_back(value.setY()[i]);
			tempnext++;
			countPoint++;
		}
		// ���� ��� ��������� �����
		while (countPoint != value.setN())	{
			if (tempprev >= 0) p = abs(X[tempprev] - value.setPointXX());
				else p = -1;
			if (tempnext < X.size()) k = abs(X[tempnext] - value.setPointXX());
			else k = value.setX().size() + 1;
			if (p != -1){
				if (k != X.size() + 1){
					if (k < p){
						pointInterpolX.push_back(X[tempnext]);
						pointInterpolY.push_back(value.setY()[tempnext]);
						tempnext++;
					}
					else {
						pointInterpolX.push_back(X[tempprev]);
						pointInterpolY.push_back(value.setY()[tempprev]);
						tempprev--;
					}
				}
				else {
					pointInterpolX.push_back(X[tempprev]);
					pointInterpolY.push_back(value.setY()[tempprev]);
					tempprev--;
				}
			}
			else {
				pointInterpolX.push_back(X[tempnext]);
				pointInterpolY.push_back(value.setY()[tempnext]);
				tempnext++;
			}
			countPoint++;
		}
	}

	void Lagrang(){
		double K;
		for (int i = 0; i < pointInterpolX.size(); i++){
			K = 1;
			for (int j = 0; j < pointInterpolX.size(); j++){
				if (pointInterpolX[i] != pointInterpolX[j])	{
					K *= (value.setPointXX()-pointInterpolX[j]);
					K /= (pointInterpolX[i] - pointInterpolX[j]);
				}
			}
			YY += pointInterpolY[i] * K;
		}
	}
	double setYY(){
		return YY;
	}

	~Interpol(){};
};

