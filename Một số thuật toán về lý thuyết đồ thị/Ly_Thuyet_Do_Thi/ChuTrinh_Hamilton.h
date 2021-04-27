#include "stdafx.h"
#include "TapTin.h"

class Hamilton{
private:
	File f;
	int a[MAX][MAX],n;
	int chuaXet[MAX],danhDau[MAX];
public:
	Hamilton();
	int soChuTrinh,x;
	bool kiemTraFile(int[][MAX],int&);
	void xuatChuTrinh_Hamilton(int[][MAX],int);
	void chuTrinh_Hamilton(int[][MAX],int,int);
};