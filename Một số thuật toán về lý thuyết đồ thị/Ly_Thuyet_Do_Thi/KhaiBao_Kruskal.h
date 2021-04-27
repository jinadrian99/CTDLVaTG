#include "stdafx.h"
#include "TapTin.h"
typedef struct TREE{
	int dau,cuoi;
	int trongLuong;
}Tree;
class Kruskal{
private:
	File f;
	int a[MAX][MAX],n;
	int danhDau[MAX];
	Tree root[MAX];
public:
	Kruskal();
	bool kiemTraFile(int[][MAX],int&);
	void sapXep(Tree [],int);
	void start_Kruskal(int[][MAX],int);
};