#include "stdafx.h"
#define trongSoMAX 999
#include "TapTin.h"

class Floyd{
private:
	int a[MAX][MAX],n;
	int W[MAX][MAX],P[MAX][MAX];
public:
	bool kiemTraFile(int[MAX][MAX],int&);
	int getTrongSo(int[][MAX],int);

};