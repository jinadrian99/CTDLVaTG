#include "stdafx.h"
#include "ChuTrinh_Hamilton.h"
Hamilton::Hamilton(){
	for ( int i=0; i < n; i++) chuaXet[i] = 0;
	danhDau[0] = 0; chuaXet[0] = 1;
}
bool Hamilton::kiemTraFile(int a[][MAX],int &n){
	cout<<"\nNhap vao duong dan tap tin: ";	cin.getline(f.filename,MAX);
	if (f.readFile(f.filename,a,n,0,0))
	{
		f.xuatFile(a,n,0,0);
		return true;
	}
	else
		return false;
}
void Hamilton::xuatChuTrinh_Hamilton(int a[][MAX],int n){
	cout<<"\t\t";
	for (int i=0; i < n; i++)
	{
		cout<<danhDau[i]+1<<"->";//In ra số hiệu đỉnh+1
	}	
	cout<<danhDau[0]+1<<"\n";
}
void Hamilton::chuTrinh_Hamilton(int a[][MAX],int n,int x){
	for (int i = 0; i < n; i++)
		if (chuaXet[i]==0 && a[danhDau[x-1]][i]!=0)// Nếu đỉnh k chưa duyệt đến và có nối với đỉnh vừa được ghi nhận trước đó (thứ j-1, số hiệu là c[j-1]) 
		{
			{
				chuaXet[i] = 1; danhDau[x] = i;//Xem như duyệt đỉnh i và nó là đỉnh thứ x theo trình tự ghi nhận 
				if (x==n-1)
				{
					if(a[danhDau[x]][danhDau[0]]!=0){
						xuatChuTrinh_Hamilton(a,n); // Nếu đỉnh cuối có nối với đỉnh đầu tiên thì hiển thị chu trình
						soChuTrinh++;
					}
				}
				else
					chuTrinh_Hamilton(a,n,x+1);//Nếu chưa ghi nhận đủ n đỉnh thì đệ quy để tìm đỉnh thứ j+1
				chuaXet[i] = 0;//Quay lui
			}
		}
}