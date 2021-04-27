#include "stdafx.h"
#include "DoThi_Euler.h"
Euler::Euler(){
	danhDau[1] = 0;
	bac = 0;
	canh = 0;\
}
bool Euler::kiemTraFile(int a[][MAX],int &n){
	cout<<"\nNhap vao duong dan tap tin: ";	cin.getline(f.filename,MAX);

	if (f.readFile(f.filename,a,n,1,1))
	{
		f.xuatFile(a,n,1,1);
		return true;
	}
	else
		return false;
}
bool Euler::kiemTraEuler(int a[][MAX],int n){
	for (int i=1 ; i<=n ; i++)
	{
		for (int j=1 ; j<=n ; j++)
		{
			if (a[i][j] != 0)
			{
				bac++;
			}
		}
		if (bac %2 == 1)	//bac chan
		{
			return false;
		}
	}
	return true;
}
int Euler::tinhCanh(int a[][MAX],int n){
	canh = bac/2;
	return canh;
}
/************************************************************************/
/*						Chu Trinh Euler                                 */
/************************************************************************/
void Euler::xuatChuTrinh(int a[][MAX],int n){
	cout<<"\nChu Trinh Euler \n";
	cout<<xuatPhat;
	for (int i=1 ; i<=canh ; i++)
	{
		cout<<" -> "<<danhDau[i];
	}
	cout<<endl;
	system("pause");
	exit(1);
}
void Euler::chuTrinh_Euler(int a[][MAX],int n, int xuatPhat, int y){
		for (int i=1 ; i<=n ; i++)
		{
			if (a[xuatPhat][i] != 0)
			{
				danhDau[y] = i;
				a[xuatPhat][i] = a[i][xuatPhat] = 0;
				if (y == tinhCanh(a,n))
				{
					xuatChuTrinh(a,n);
				}
				else
				{
					chuTrinh_Euler(a,n,i,y+1);
				}
				a[xuatPhat][i] = a[i][xuatPhat] = 1;
			}
		}
}
/************************************************************************/
/*						Duong di Euler                                  */
/************************************************************************/
void Euler::xuatDuongDi_Euler(int a[][MAX],int n){

}