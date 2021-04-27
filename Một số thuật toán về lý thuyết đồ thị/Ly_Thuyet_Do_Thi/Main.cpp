#include "stdafx.h"
#include "TapTin.h"
#include "DoThi.h"
#include "DoThi_Euler.h"
#include "ChuTrinh_Hamilton.h"
#include "KhaiBao_Kruskal.h"
#include "KhaiBao_Prim.h"
int _tmain(int argc, _TCHAR* argv[]){
	int maTran[MAX][MAX],soDinh;
	int x;
	Graph G;
	Euler E;
	Hamilton H;
	Kruskal K;
	Prim P;
	/************************************************************************/
	/*			DFS - BFS                                                   */
	/************************************************************************/
	if (G.kiemTraFile(maTran,soDinh))
	{
		cout<<"\nDo thi vo huong"<<endl;
		cout<<"\nBac cua do thi: "<<G.tinhBac(maTran,soDinh);
		cout<<"\nCanh cua do thi: "<<G.tinhCanh(maTran,soDinh);
		cout<<"\nNhap vao dinh bat ky: ";	cin>>x;
		G.timDinhLienThong(maTran,soDinh,x);
		cout<<"\n====================================================";
		cout<<"\n\tDuyet do thi bang phuong phap DFS";
		cout<<endl<<endl;	G.DFS_QuayLui(maTran,soDinh);
		cout<<"\n\n===================================================";
		cout<<"\nDuyet do thi bang phuong phap BFS";
		cout<<endl<<endl;	G.find_BFS(maTran,soDinh);	cout<<endl;
	}
		/************************************************************************/
		/*				Hamilton                                                */
		/************************************************************************/
		cin.ignore();
		if (H.kiemTraFile(maTran,soDinh))
		{
			cout<<"\nChu trinh Hamilton"<<endl;
			H.chuTrinh_Hamilton(maTran,soDinh,1);
			cout<<"\nTong so chu trinh tim duoc: "<<H.soChuTrinh<<endl;
		}
		/************************************************************************/
		/*				Kruskal                                                 */
		/************************************************************************/
		cin.ignore();

		if (K.kiemTraFile(maTran,soDinh))
		{
			cout<<"\n==============================================="<<endl;
			K.start_Kruskal(maTran,soDinh);	cout<<endl;
		}
		/************************************************************************/
		/*				Prim                                                    */
		/************************************************************************/
		cin.ignore();
		if (P.kiemTraFile(maTran,soDinh))
		{
			P.start_prim(maTran,soDinh);
		}
		/************************************************************************/
		/*				Euler                                                   */
		/************************************************************************/
		if (E.kiemTraFile(maTran,soDinh))
		{
			if (E.kiemTraEuler(maTran,soDinh))
			{
				cout<<"\nDo thi co chu trinh Euler"<<endl;
				cout<<"\nNhap dinh xuat phat: ";	cin>>E.xuatPhat;
				E.chuTrinh_Euler(maTran,soDinh,E.xuatPhat,1);
			}
	}
	system("pause");
	return 0;
}