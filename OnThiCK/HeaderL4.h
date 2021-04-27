//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
////MAXV: số đỉnh tối đa
//const int MAXV = 20;
//// hang doi bieu dien bang danh sach dac
//
//typedef int item;
//struct Queue
//{
//	int count;
//	item Data[MAXV];
//};
//
//void Init(Queue &Q);
//int Isempty(Queue Q);
//int Isfull(Queue Q);
//void Push(Queue &Q, item x);
//int Pop(Queue &Q);
//int Qfront(Queue Q);
//
//struct Stack
//{
//	int top;
//	item Data[MAXV];
//};
//void Init(Stack &st);
//int Isempty(Stack st);
//int Isfull(Stack st);
//void Push(Stack &st, item x);
//int Pop(Stack &st);
//int Peak(Stack st);
//
//
////MAXE: số cạnh tối đa
//const int MAXE = MAXV*MAXV;
//
////VERTEX: Kiểu của một đỉnh
//typedef int VERTEX;
//
////EDGE: Kiểu của một cạnh
//struct EDGE
//{
//	VERTEX org; //Origin
//	VERTEX des; //Destination
//	int wei=0; //weight
//};
//
////ArrayVertex: danh sách đỉnh
//struct ArrayVertex
//{
//	VERTEX ds[MAXV];
//	int count;
//};
//
////ArrayEdge: danh sách cạnh
//struct ArrayEdge
//{
//	EDGE ds[MAXE];
//	int count;
//};
//
////Ma trận kề của đồ thị (Adjacency-matrix)
//struct AdjacencyMatrix
//{
//	int mt[MAXV][MAXV];
//	int n;
//};
//
////Xuất đỉnh v ra màn hình
//void printVertex(VERTEX v);
//
////Xuất cạnh e ra màn hình
//void printEdge(EDGE e);
//
////Xuất danh sách đỉnh ra màn hình
//void printArrayVertex(ArrayVertex av);
//
////Xuất danh sách cạnh ra màn hình
//void printArrayEdge(ArrayEdge ae);
//
////Đọc một ma trận kề từ file văn bản.
//int Read(char* filename, AdjacencyMatrix& g);
//
////Ghi một ma trận kề lên file văn bản.
//int Write(char* filename, AdjacencyMatrix g);
//
////Hàm xuất ma trận kề ra màn hình
//void Xuat(AdjacencyMatrix g);
//
////Hàm tính bậc vào đồ thị có hướng
//int TinhBacVaoDTCoHuong(AdjacencyMatrix g, int dinh);
//
////Hàm trả về tập cạnh của đồ thị có hướng
//ArrayEdge TapCanhDTCH(AdjacencyMatrix g);
//
//// ham duyet theo chieu rong
//void Duyet_BFS(AdjacencyMatrix MTK, VERTEX start);
//void Duyet_DFS(AdjacencyMatrix MTK, VERTEX start);