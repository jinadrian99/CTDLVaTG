#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

const int MAXV = 10;
const int MAXE = MAXV*MAXV;

struct MTK{
	int mtk[MAXV][MAXV];
	int n;
};
struct EDGE{
	int org;
	int des;
	int wei=0;
};
struct ArrayEdge
{
	EDGE ds[MAXE];
	int count;
};

struct NODE
{
	int des;
	int wei=0;
	NODE* link;
};
struct DSK
{
	NODE* dsk[MAXV];
	int n;
};

bool docfileMTK(char* filename, MTK &x);
void xuatMaTranKe(MTK x);
bool docfileDSK(char* filename, DSK &x);
void xuatDanhSachKe(DSK x);
bool docfileTapCanh(char* filename, ArrayEdge &ae);
void xuatTapCanh(ArrayEdge ae);

int dinhKeUBacMax(MTK x, int u);
void xuatCanhKeUCoTrongSoMax(MTK x, int u);

int tinhBacVaoDinhU(MTK x, int u);
int tinhBacRaDinhU(MTK x, int u);
int tinhBac(MTK x, int u);
int tinhBacVaoDinhU(DSK x, int u);
int tinhBacRaDinhU(DSK x, int u);
int tinhBac(DSK x, int u);
int tinhBacVoHuong(MTK x,int u);
int tinhBacVoHuong(DSK x, int u);


void xuatCanh(EDGE e);
EDGE canhMax(MTK x);
EDGE canhMin(MTK x);
EDGE canhMax(DSK x);
EDGE canhMin(DSK x);

ArrayEdge TapCanhDoThiCoHuong(MTK x);
ArrayEdge TapCanhDoThiCoHuong(DSK x);
ArrayEdge TapCanhDoThiVoHuong(MTK x);
ArrayEdge TapCanhDoThiVoHuong(DSK x);

DSK ChuyenKieuDoThi(MTK x);
MTK ChuyenKieuDoThi(DSK x);

MTK TaoDoThiMTK(ArrayEdge ae, int numv);
DSK TaoDoThiDSK(ArrayEdge ae, int numv);




