//#include "HeaderL4.h"
//
//void main()
//{
//	int ok, dinh;
//	AdjacencyMatrix g;
//	ArrayEdge tapcanh;
//	do{
//		cout << "\n===================================";
//		cout << "\n0.Ket thuc";
//		cout << "\n1.Doc file do thi vo huong";
//		cout << "\n2.Doc file do thi co huong";
//		cout << "\n3.Ghi file";
//		cout << "\n4.Tinh so bac vao cua dinh";
//		cout << "\n5.Lay tap canh cua do thi co huong";
//		cout << "\n6.Duyet do thi theo chieu rong";
//		cout << "\n7.Duyet do thi theo chieu sau";
//		cout << "\nMoi ban chon: ";
//		cin >> ok;
//		cin.ignore();
//		switch (ok)
//		{
//		case 1:
//			Read("dothi.txt", g);
//			Xuat(g);
//			break;
//		case 2:
//			Read("dothi2.txt", g);
//			Xuat(g);
//			break;
//		case 3:
//			cout << "\n Ghi file";
//			Write("dothi3.txt", g);
//			Xuat(g);
//			break;
//		case 4:
//			cout << "\n Nhap dinh can tinh bac vao:";
//			cin >> dinh;
//			cout << "\n So bac vao cua dinh " << dinh << " la: " << TinhBacVaoDTCoHuong(g, dinh);
//			break;
//		case 5:
//			tapcanh = TapCanhDTCH(g);
//			if (tapcanh.count == 0) cout << "Do thi ko co canh nao.";
//			else
//			{
//				cout << "\nTap canh cua do thi: ";
//				for (int i = 0; i<tapcanh.count; i++)
//					cout << "\n(" << tapcanh.ds[i].org << " - " << tapcanh.ds[i].des << ", " << tapcanh.ds[i].wei << ")";
//			}
//			cout << "\n";
//			break;
//		case 6:
//			Duyet_BFS(g, 0);
//			break;
//		case 7:
//			Duyet_DFS(g, 0);
//			break;
//		}
//	} while (ok != 0);
//}
