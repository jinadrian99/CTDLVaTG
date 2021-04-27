#include "stdafx.h"
#include "TapTin.h"
#define MAX 100
class Graph{
private: 
	int canh;
	File f;
	int a[MAX][MAX],n;
	int danhDau[MAX],truoc[MAX],chuaXet[MAX];
	int tongBac,TPLienThong;
public:
	Graph();
	
	/************************************************************************/
	/*			Kiem tra do thi co huong hay vo huong                       */
	bool kiemTraFile(int [][MAX],int&);
	/************************************************************************/

	/************************************************************************/
	/*			Tinh bac va tim dinh lien thong cua do thi                  */
	/************************************************************************/
	int tinhBac(int[][MAX],int);
	int tinhCanh(int[][MAX],int);
	void timDinhLienThong(int[][MAX],int,int);
	/************************************************************************/
	/*						DFS		                                        */
	/************************************************************************/
	void DFSDeQuy(int [][MAX],int,int);
	void DFS_QuayLui(int [][MAX],int);
	/************************************************************************/
	/*						BFS                                             */
	/************************************************************************/
	void BFS(int[][MAX],int,int);
	void find_BFS(int[][MAX],int);
};