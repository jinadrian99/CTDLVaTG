#include "stdafx.h"
#include "TapTin.h"

#define MAX 100
using namespace std;
class Euler {
private:
	File f;
	int a[MAX][MAX],n;
	int danhDau[MAX];
	int bac,canh;
public:
	int xuatPhat;
	Euler();
	bool kiemTraFile(int[][MAX],int&);
	int tinhCanh(int[][MAX],int);
	bool kiemTraEuler(int[][MAX],int);
	void xuatChuTrinh(int[][MAX],int);
	void chuTrinh_Euler(int[][MAX],int,int,int);
	void xuatDuongDi_Euler(int[][MAX],int);
	void duongDi_Euler(int[][MAX],int,int);
};