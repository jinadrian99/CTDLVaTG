#include <iostream>
using namespace std;

//MAXV: số đỉnh tối đa
const int MAXV = 20;

//MAXE: số cạnh tối đa
const int MAXE = MAXV*MAXV;

//VERTEX: Kiểu của một đỉnh
typedef int VERTEX;

//EDGE: Kiểu của một cạnh
struct EDGE
{
	VERTEX org; //Origin
	VERTEX des; //Destination
	int wei; //weight
};

//ArrayVertex: danh sách đỉnh
struct ArrayVertex
{
	VERTEX ds[MAXV];
	int count;
};

//ArrayEdge: danh sách cạnh
struct ArrayEdge
{
	EDGE ds[MAXE];
	int count;
};

//Ma trận kề của đồ thị (Adjacency-matrix)
struct AdjacencyMatrix
{
	int mt[MAXV][MAXV];
	int n;
};
typedef AdjacencyMatrix MTK;

// cau truc node dinh
struct NODEVERTEX {
	int dinhke;
	int trongso = 0;
	NODEVERTEX* link;
};
typedef NODEVERTEX NODE;

struct DANHSACHKE{
	NODEVERTEX* dsk[MAXV];
	int n = 0;//so dinh cua do thi
};
typedef DANHSACHKE DSK;

//Xuất đỉnh v ra màn hình
void printVertex(VERTEX v);

//Xuất cạnh e ra màn hình
void printEdge(EDGE e);

//Xuất danh sách đỉnh ra màn hình
void printArrayVertex(ArrayVertex av);

//Xuất danh sách cạnh ra màn hình
void printArrayEdge(ArrayEdge ae);

//Đọc một ma trận kề từ file văn bản.
int Read(char* filename, AdjacencyMatrix& g);

//Ghi một ma trận kề lên file văn bản.
int Write(char* filename, AdjacencyMatrix g);

//Hàm xuất ma trận kề ra màn hình
void Xuat(AdjacencyMatrix g);

//Hàm tính bậc vào đồ thị có hướng
int TinhBacVaoDTCoHuong(AdjacencyMatrix g, int dinh);

//Hàm trả về tập cạnh của đồ thị có hướng
ArrayEdge TapCanhDTCH(AdjacencyMatrix g);
// ham doc file danh sach ke
int docFile(const char* tenfile, DANHSACHKE& x);
// ham xuat danh sach ke
void xuatDSK(DANHSACHKE x);

int bacVao1Dinh(MTK x, VERTEX u);
int bacRa1Dinh(MTK x, VERTEX u);
int bac1DinhCuaDoThiCoHuong(MTK x, VERTEX u);

int bacVao1Dinh(DSK x, VERTEX u);
int bacRa1Dinh(DSK x, VERTEX u);
int bac1DinhCuaDoThiCoHuong(DSK x, VERTEX u);

EDGE canhMax(MTK x);
EDGE canhMin(MTK x);
EDGE canhMax(DSK x);
EDGE canhMin(DSK x);

ArrayEdge TapCanhDoThiCoHuong(MTK x);
ArrayEdge TapCanhDoThiCoHuong(DSK x);

DSK ChuyenKieuDoThi(MTK x);
MTK ChuyenKieuDoThi(DSK x);