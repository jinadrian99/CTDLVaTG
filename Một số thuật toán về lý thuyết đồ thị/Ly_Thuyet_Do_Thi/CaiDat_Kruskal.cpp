#include "stdafx.h"
#include "KhaiBao_Kruskal.h"
Kruskal::Kruskal(){
	for (int i=1 ; i<=n ; i++)
	{
		danhDau[i] = 0;
	}
}
bool Kruskal::kiemTraFile(int a[][MAX],int &n){
	cout<<"\nNhap duong dan tap tin: ";	cin.getline(f.filename,MAX);
	if (f.readFile(f.filename,a,n,1,1))
	{
		f.xuatFile(a,n,1,1);
		return true;
	}
	else	return false;
}
void Kruskal::sapXep(Tree root[MAX],int n){
	Tree temp;
	for (int i=1 ; i<=n ; i++)
	{
		for (int j=1 ; j<=n ; j++)
		{
			if (root[i].trongLuong > root[j].trongLuong)
			{
				temp    = root[i];
				root[i] = root[j];
				root[j] = temp;
			}
		}
	}
}
void Kruskal::start_Kruskal(int a[][MAX],int n){
	Tree canh[MAX];
	int x = 1;
	for (int i=1 ; i<=n ; i++)
	{
		danhDau[i] = 1;
		for (int j=1 ; j<=n ; j++)
		{
			if (a[i][j] != vocuc && a[i][j] != 0 && danhDau[j] ==0)
			{
				canh[x].dau = i;
				canh[x].cuoi = j;
				canh[x].trongLuong = a[i][j];
				x++;
			}
		}
	}
	sapXep(canh,n);
	root[1] = canh[1];
	int k=2,t;
	int w = root[1].trongLuong;
	for (int i=2 ; i<n ; i++)
	{lap:
		t=0;
		for (int j=1 ; j<i ; j++)
		{
			if (root[j].dau == canh[k].dau || root[j].cuoi == canh[k].dau)
			{
				t++;
				break;
			}
		}
		for (int j=1 ; j<i ; j++)
		{
			if (root[j].dau == canh[k].cuoi || root[j].cuoi == canh[k].cuoi)
			{
				t++;
				break;
			}
		}
		if (t == 2 || t == 0)
		{
			k+=1;
			goto lap;
		}
		if (t == 1)
		{
			root[i] = canh[k];
			k++;
			w += root[i].trongLuong;
		}
	}
	cout<<"\nTrong luong cay: "<<w;
	cout<<"\nCac nhanh cua cay"<<endl;
	for (int i=1 ; i<n ; i++)
	{
		cout<<root[i].dau<<" -> "<<root[i].cuoi;
	}
}