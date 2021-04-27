#include "stdafx.h"
#include "DoThi.h"
Graph::Graph(){
	tongBac = 0;
	canh = 0;
	TPLienThong = 0;
	danhDau[1] = 0;
	truoc[1] = 0;
	chuaXet[1] = 0;
}

bool Graph::kiemTraFile(int a[][MAX],int &n){
	cout<<"\nNhap vao duong dan tap tin: ";	cin.getline(f.filename,MAX);
	if (f.readFile(f.filename,a,n,1,1))
	{
		f.xuatFile(a,n,1,1);
		for (int i=1 ; i<=n ; i++)
		{
			for (int j=1 ; j<=n ; j++)
			{
				if (a[i][j] != a[j][i])
				{
					return false;
				}
			}
		}
		return true;
	}
	else
		return false;
}
int Graph::tinhBac(int a[][MAX],int n){
	for (int i=1 ; i<=n ; i++)
	{
		for (int j=1 ; j<=n ; j++)
		{
			if(a[i][j] != 0)
				tongBac++;
		}
	}
	return tongBac;
}
int Graph::tinhCanh(int a[][MAX],int n){
	//Tong bac = 2 * canh;
	canh = tongBac / 2;
	return canh;
}
void Graph::timDinhLienThong(int a[][MAX],int n,int x){
	cout<<"\nCac dinh lien thong voi dinh "<<x<<" la";
	for (int i=1 ; i<=n ; i++)
	{
		if (a[x][i] != 0)
		{
			cout<<"\t"<<i;
		}
	}
	cout<<endl;
}
/************************************************************************/
/*				Duyet do thi bang DFS                                   */
/************************************************************************/
void Graph::DFSDeQuy(int a[][MAX],int n,int x){
	//duyet 1 thanh phan lien thong.
	cout<<"\t"<<x;
	danhDau[x] = TPLienThong;
	for (int i=1 ; i<=n ; i++)
	{
		if (a[x][i] != 0 && !danhDau[i])
		{
			truoc[i] = x;
			DFSDeQuy(a,n,i);
		}
	}
}
void Graph::DFS_QuayLui(int a[][MAX],int n){
	//duyet toan bo thanh phan lien thong.
	for (int i=1 ; i<=n ; i++)
	{
		danhDau[i] = 0;
		for (int i=1 ; i<=n ; i++)
		{
			if (!danhDau[i])
			{
				TPLienThong++;
				DFSDeQuy(a,n,i);
			}
		}
	}
}
/************************************************************************/
/*				Duyet do thi bang BFS                                   */
/************************************************************************/
void Graph::BFS(int a[][MAX],int n,int x){
	int truoc = 0, sau = 0;
	chuaXet[sau++] = x;
	danhDau[x] = TPLienThong;
	while (truoc != sau)
	{
		int i = chuaXet[truoc++];
		cout<<"\t"<<i;
		for (int j=1 ; j<=n ; j++)
		{
			if (a[i][j] !=0 && danhDau[j] ==0)
			{
				danhDau[j] = TPLienThong;
				chuaXet[sau++] = j;
			}
		}
	}
}
void Graph::find_BFS(int a[][MAX],int n){
	for (int i=1 ; i<=n ; i++)
	{
		if (chuaXet[i] == 0)
		{
			TPLienThong++;
			BFS(a,n,i);
		}
	}
}