#include "thuvien_ontap.h"

void main()
{
	int ok, dinh;
	AdjacencyMatrix g;
	DANHSACHKE DSK,kq;
	ArrayEdge tapcanh;
	do{
		cout << "\n===================================";
		cout << "\n0.Ket thuc";
		cout << "\n1.Doc file ma tran ke do thi ";
		cout << "\n2.Doc file danh sach ke do thi ";
		cout << "\n3.Ghi file ma tran ke dothi3.txt";
		cout << "\nMoi ban chon: ";
		cin >> ok;
		cin.ignore();
		switch (ok)
		{
		case 1:
			Read("MTK.txt", g);
			Xuat(g);
			break;
		case 2:
			docFile("DSK.txt", DSK);
			xuatDSK(DSK);
			break;
		case 3:
			cout << "\n Ghi file ma tran ke";
			Write("dothi3.txt", g);
			Xuat(g);
			break;
		case 4:
			kq = ChuyenKieuDoThi(g);
			xuatDSK(kq);
			break;
		}
	} while (ok != 0);
}
