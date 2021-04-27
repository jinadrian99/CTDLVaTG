#include "stdafx.h"
#include "KhaiBao_Prim.h"
Prim::Prim(){
	tong = 0;
	soDinh = 1;
	for (int i=1 ; i<=n ; i++)
	{
		danhDau[i] = 0;
	}
}
bool Prim::kiemTraFile(int a[][MAX],int &n){
	cout<<"\nNhap duong dan tap tin: ";	cin.getline(f.filename,MAX);
	if (f.readFile(f.filename,a,n,1,1))
	{
		f.xuatFile(a,n,1,1);
		return true;
	}
	else	return false;
}
void Prim::start_prim(int a[][MAX],int n){

	chuaXet[soDinh] = danhDau[soDinh] = 1;
	while(soDinh < n){
		int min = MAXINT;
		for (int i=1 ; i<=soDinh ; i++)
		{
			for (int j=1 ; j<=n ; j++)
			{
				if (chuaXet[i]!=j && a[chuaXet[i]][j]!=0 && !danhDau[j] && a[chuaXet[i]][j]<min)
				{
					min=a[chuaXet[i]][j]; 
					dinhDau=chuaXet[i]; 
					dinhCuoi=j;
				}
			}
		}
		danhDau[dinhCuoi] = 1;
		chuaXet[++soDinh] = dinhCuoi;
		tong += a[dinhDau][dinhCuoi];
		cout<<"\nDinh dau "<<dinhDau<<" , "<<"Dinh cuoi "<<dinhCuoi<<endl;
		
	}
	cout<<"\nTong do dai cua cay khung nho nhat la: "<<tong<<endl;
}