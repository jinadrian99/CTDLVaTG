#include "stdafx.h"
#include "TapTin.h"
#define MAXINT 32767
class Prim{
private:
	File f;
	int a[MAX][MAX],n;
	int danhDau[MAX],chuaXet[MAX];
	int tong,dinhDau,dinhCuoi,soDinh;
public:
	Prim();
	bool kiemTraFile(int[][MAX],int &);
	void start_prim(int[][MAX],int);
};