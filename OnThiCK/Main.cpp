#include"Header.h"
int main()
{
	MTK x;
	DSK y;
	ArrayEdge z;
	int choice;
	bool kqdocfile = false, kqdocfileTC = false;
	do{
		system("cls");
		cout << "\n0.THOAT.";
		cout << "\n\n1.Doc file 1/3.";
		cout << "\n2.Tinh bac vao.";
		cout << "\n3.Tinh bac ra.";
		cout << "\n4.Tinh bac vao va ra.";
		cout << "\n5.Tim canh max.";
		cout << "\n6.Tim canh min.";
		cout << "\n7.Tim dinh ke vs U co bac max.";
		cout << "\n8.Tinh canh ke U co trong so max.";
		cout << "\n\n9.Doc file 2/4.";
		cout << "\n10.Tap canh DoThi.";
		cout << "\n11.Chuyen kieu DoThi.";
		cout << "\n\n12.Doc file TapCanh.";
		cout << "\n13.Tao DoThi.";
		cout << "\nChon muc: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			kqdocfile = docfileMTK("OnThi3.txt", x);
			if (kqdocfile)
				xuatMaTranKe(x);
			else
				cout << "\nDoc that bai.";
			system("pause");
			break;

		case 2:
			system("cls");
			if (kqdocfile)
			{
				int dinh;
				int kq;
				int chon;
				cout << "\n0.MTK.";
				cout << "\n1.DSK.";
				cout << "\nBan chon: ";
				cin >> chon;
				if (!chon)
				{
					cout << "\nNhap dinh can tinh Bac Vao: ";
					cin >> dinh;
					kq = tinhBacVaoDinhU(x, dinh);
					cout << "\nKQ = " << kq;
				}
				else
				{
					cout << "\nNhap dinh can tinh Bac Vao: ";
					cin >> dinh;
					kq = tinhBacVaoDinhU(y, dinh);
					cout << "\nKQ = " << kq;
				}
			}
			else
				cout << "\nKo co data.";
			system("pause");
			break;

		case 3:
			system("cls");
			if (kqdocfile)
			{
				int dinh;
				int kq;
				int chon;
				cout << "\n0.MTK.";
				cout << "\n1.DSK.";
				cout << "\nBan chon: ";
				cin >> chon;
				if (!chon)
				{
					cout << "\nNhap dinh can tinh Bac Ra: ";
					cin >> dinh;
					kq = tinhBacRaDinhU(x, dinh);
					cout << "\nKQ = " << kq;
				}
				else
				{
					cout << "\nNhap dinh can tinh Bac Ra: ";
					cin >> dinh;
					kq = tinhBacRaDinhU(y, dinh);
					cout << "\nKQ = " << kq;
				}
			}
			else
				cout << "\nKo co data.";
			system("pause");
			break;

		case 4:
			system("cls");
			if (kqdocfile)
			{
				int dinh;
				int kq;
				int chon;
				cout << "\n0.MTK.";
				cout << "\n1.DSK.";
				cout << "\nBan chon: ";
				cin >> chon;
				if (!chon)
				{
					cout << "\nNhap dinh can tinh Bac: ";
					cin >> dinh;
					kq = tinhBac(x, dinh);
					cout << "\nKQ = " << kq;
				}
				else
				{
					cout << "\nNhap dinh can tinh Bac: ";
					cin >> dinh;
					kq = tinhBac(y, dinh);
					cout << "\nKQ = " << kq;
				}
			}
			else
				cout << "\nKo co data.";
			system("pause");
			break;

		case 5:
			system("cls");
			if (kqdocfile)
			{
				int dinh;
				int kq;
				int chon;
				cout << "\n0.MTK.";
				cout << "\n1.DSK.";
				cout << "\nBan chon: ";
				cin >> chon;
				if (!chon)
				{
					EDGE kq;
					kq = canhMax(x);
					cout << "\nCanh Max: ";
					xuatCanh(kq);
				}
				else
				{
					EDGE kq;
					kq = canhMax(y);
					cout << "\nCanh Max: ";
					xuatCanh(kq);
				}
			}
			system("pause");
			break;

		case 6:
			system("cls");
			if (kqdocfile)
			{
				int dinh;
				int kq;
				int chon;
				cout << "\n0.MTK.";
				cout << "\n1.DSK.";
				cout << "\nBan chon: ";
				cin >> chon;
				if (!chon)
				{
					EDGE kq;
					kq = canhMin(x);
					cout << "\nCanh Min: ";
					xuatCanh(kq);
				}
				else
				{
					EDGE kq;
					kq = canhMin(y);
					cout << "\nCanh Min: ";
					xuatCanh(kq);
				}
			}
			system("pause");
			break;

		case 7:
			system("pause");
			system("cls");
			if (kqdocfile)
			{
				int kq;
				int u;
				cout << "\nNhap U de tim dinh ke co bac MAX: ";
				cin >> u;
				kq = dinhKeUBacMax(x, u);
				cout << "\nDinh ke bac MAX: " << kq;
			}
			system("pause");
			break;

		case 8: 
			system("pause");
			system("cls");
			if (kqdocfile)
			{
				int u;
				cout << "\nNhap U dem tim canh ke co trong so MAX: ";
				cin >> u;
				xuatCanhKeUCoTrongSoMax(x, u);
			}
			system("pause");
			break;

		case 9:
			system("cls");
			kqdocfile = docfileDSK("OnThi4.txt", y);
			if (kqdocfile)
				xuatDanhSachKe(y);
			else
				cout << "\nDoc that bai.";
			system("pause");
			break;

		case 10:
			system("cls");
			if (kqdocfile)
			{
				ArrayEdge ae;
				int chon;
				cout << "\n0.CoHuong.";
				cout << "\n1.VoHuong.";
				cin >> chon;
				if (!chon)
				{
					cout << "\n0.MTK.";
					cout << "\n1.DSK.";
					cout << "\nBan chon: ";
					cin >> chon;
					if (!chon)
					{
						ae = TapCanhDoThiCoHuong(x);
						for (int i = 0; i < ae.count; i++)
						{
							if (i == 0 || ae.ds[i].org == ae.ds[i - 1].org)
							{
								xuatCanh(ae.ds[i]);
							}
							else if (ae.ds[i].org != ae.ds[i - 1].org)
							{
								cout << endl;
								xuatCanh(ae.ds[i]);
							}
						}
					}
					else
					{
						ae = TapCanhDoThiCoHuong(y);
						for (int i = 0; i < ae.count; i++)
						{
							if (i == 0 || ae.ds[i].org == ae.ds[i - 1].org)
							{
								xuatCanh(ae.ds[i]);
							}
							else if (ae.ds[i].org != ae.ds[i - 1].org)
							{
								cout << endl;
								xuatCanh(ae.ds[i]);
							}
						}
					}
				}
				else
				{
					cout << "\n0.MTK.";
					cout << "\n1.DSK.";
					cout << "\nBan chon: ";
					cin >> chon;
					if (!chon)
					{
						ae = TapCanhDoThiVoHuong(x);
						for (int i = 0; i < ae.count; i++)
						{
							if (i == 0 || ae.ds[i].org == ae.ds[i - 1].org)
							{
								xuatCanh(ae.ds[i]);
							}
							else if (ae.ds[i].org != ae.ds[i - 1].org)
							{
								cout << endl;
								xuatCanh(ae.ds[i]);
							}
						}
					}
					else
					{
						ae = TapCanhDoThiVoHuong(y);
						for (int i = 0; i < ae.count; i++)
						{
							if (i == 0 || ae.ds[i].org == ae.ds[i - 1].org)
							{
								xuatCanh(ae.ds[i]);
							}
							else if (ae.ds[i].org != ae.ds[i - 1].org)
							{
								cout << endl;
								xuatCanh(ae.ds[i]);
							}
						}
					}
				}
			}
			system("pause");
			break;

		case 11:
			system("cls");
			if (kqdocfile)
			{
				int chon;
				cout << "\n0.Tu MTK.";
				cout << "\n1.Tu DSK.";
				cout << "\nBan chon: ";
				cin >> chon;
				system("pause");
				if (!chon)
				{
					cout << "\nDSK co tu MTK:\n";
					DSK xy = ChuyenKieuDoThi(x);
					xuatDanhSachKe(xy);
				}
				else
				{
					cout << "\nMTK co tu DSK:\n";
					MTK yx = ChuyenKieuDoThi(y);
					xuatMaTranKe(yx);
				}
			}
			system("pause");
			break;

		case 12:
			system("cls");
			kqdocfileTC = docfileTapCanh("TapCanh.txt", z);
			if (kqdocfileTC)
			{
				xuatTapCanh(z);
			}
			else
				cout << "\nDoc file TapCanh that bai.";
			system("pause");
			break;

		case 13:
			system("cls");
			if (kqdocfileTC)
			{
				int chon;
				cout << "\n0.Tu MTK.";
				cout << "\n1.Tu DSK.";
				cout << "\nBan chon: ";
				cin >> chon;
				system("pause");
				if (!chon)
				{
					cout << "\nMTK vua tao: \n";
					MTK xtc = TaoDoThiMTK(z, 5);
					xuatMaTranKe(xtc);
				}
				else
				{
					cout << "\nDSK vua tao: \n";
					DSK ytc = TaoDoThiDSK(z, 5);
					xuatDanhSachKe(ytc);
				}
			}
			system("pause");
			break;
		default:
			break;
		}
	} while (choice != 0);
	return 1;
}