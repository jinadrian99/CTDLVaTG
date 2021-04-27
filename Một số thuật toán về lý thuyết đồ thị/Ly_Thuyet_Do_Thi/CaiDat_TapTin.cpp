#include "stdafx.h"
#include "TapTin.h"
//void File::setFile(int x ,int y){
//	setReadFile(x,y);
//	getReadFile(x,y);
//}
bool File::readFile(char filename[],int a[][MAX],int &n,int x,int y){

	ifile.open(filename,ios::in);
	
	if (ifile.fail())
	{
		cout<<"\nDoc file '"<<filename<<"' that bai"<<endl;
		return false;
	}
	else{
		ifile>>n;
		if (x == 0 && y ==0)
		{
			for (int i=x ; i<n ; i++)
			{
				for(int j=y ; j<n ; j++){
					ifile>>a[i][j];
				}
			}
			ifile.close();
		}
		else if(x ==1 && y ==1){
			for (int i=x ; i<=n ; i++)
			{
				for(int j=y ; j<=n ; j++){
					ifile>>a[i][j];
				}
			}
			ifile.close();
		}
		return true;
	}

}
void File::xuatFile(int a[][MAX],int n,int x,int y){
	cout<<"\nSo dinh do thi: "<<n<<endl;;
	if (x == 0 && y ==0)
	{
		for (int i=x ; i<n ; i++)
		{
			cout<<endl;
			for(int j=y ; j<n ; j++){
				cout<<a[i][j];
			}
		}
		cout<<endl;
	}
	else if(x ==1 && y ==1){
		for (int i=x ; i<=n ; i++)
		{
			cout<<endl;
			for(int j=y ; j<=n ; j++){
				cout<<a[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}
