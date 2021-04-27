#include"Header.h"
bool docfileMTK(char* filename, MTK &x)
{
	FILE* f = fopen(filename, "rt");
	if (f == NULL)	return false;
	fscanf(f, "%d", &x.n);
	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.n; j++)
		{
			fscanf(f, "%d", &x.mtk[i][j]);
		}
	}
	fclose(f);
	return true;
}

void xuatMaTranKe(MTK x)
{
	cout << "\nGia tri trong file: \n";
	cout << x.n << endl;
	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.n; j++)
		{
			cout << x.mtk[i][j] << "  ";
		}
		cout << endl;
	}
}

int tinhBacVaoDinhU(MTK x, int u)
{
	int kq = 0;
	for (int i = 0; i < x.n; i++)
	{
		if (i == u)continue;
		if (x.mtk[i][u] != 0)
			kq++;
	}
	return kq;
}

int tinhBacRaDinhU(MTK x, int u)
{
	int kq = 0;
	for (int i = 0; i < x.n; i++)
	{
		if (i == u)continue;
		if (x.mtk[u][i] != 0)
			kq++;
	}
	return kq;
}
int tinhBac(MTK x, int u)
{
	return tinhBacVaoDinhU(x, u) + tinhBacRaDinhU(x, u);
}

int tinhBacVaoDinhU(DSK x, int u)
{
	int kq=0;
	for (int i = 0; i < x.n; i++)
	{
		if (i == u) continue;
		NODE* p = x.dsk[i];
		while (p != NULL)
		{
			if (p->des == u)	kq++;
			p = p->link;
		}
	}
	return kq;
}
int tinhBacRaDinhU(DSK x, int u)
{
	int kq = 0;
	NODE* p = x.dsk[u];
	while (p != NULL)
	{
		kq++;
		p = p->link;
	}
	return kq;
}
int tinhBac(DSK x, int u)
{
	return tinhBacVaoDinhU(x, u) + tinhBacRaDinhU(x, u);
}

int tinhBacVoHuong(MTK x, int u)
{
	int count = 0;
	for (int i = 0; i < x.n; i++)
	{
		if (x.mtk[u][i] != 0)
			count++;
	}
	return count;
}
int tinhBacVoHuong(DSK x, int u)
{
	int count = 0;
	NODE* p = x.dsk[u];
	while (p != NULL)
	{
		count++;
		p = p->link;
	}
	return count;
}

EDGE canhMax(MTK x)
{
	EDGE kq;
	int flag = 1;
	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.n; j++)
		{
			if (x.mtk[i][j] != 0)
			{
				if (flag)
				{
					flag = 0;
					kq.org = i;
					kq.des = j;
					kq.wei = x.mtk[i][j];
				}
				else
				{
					if (kq.wei < x.mtk[i][j])
					{
						kq.org = i;
						kq.des = j;
						kq.wei = x.mtk[i][j];
					}
				}
			}
		}
	}
	return kq;
}

void xuatCanh(EDGE e)
{
	cout << "(" << e.org << "-" << e.des << "," << e.wei << ")  ";
}

EDGE canhMin(MTK x)
{
	EDGE kq;
	int flag = 1;
	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.n; j++)
		{
			if (x.mtk[i][j] != 0)
			{
				if (flag)
				{
					flag = 0;
					kq.org = i;
					kq.des = j;
					kq.wei = x.mtk[i][j];
				}
				else
				{
					if (kq.wei > x.mtk[i][j])
					{
						kq.org = i;
						kq.des = j;
						kq.wei = x.mtk[i][j];
					}
				}
			}
		}
	}
	return kq;
}

EDGE canhMax(DSK x)
{
	EDGE kq;
	int flag = 1;
	for (int i = 0; i < x.n; i++)
	{
		NODE* p = x.dsk[i];
		while (p != NULL)
		{
			if (flag)
			{
				flag = 0;
				kq.wei = p->wei;
				kq.org = i;
				kq.des = p->des;
			}
			else
			{
				if (kq.wei < p->wei)
				{
					kq.wei = p->wei;
					kq.org = i;
					kq.des = p->des;
				}
			}
			p = p->link;
		}
	}
	return kq;
}

EDGE canhMin(DSK x)
{
	EDGE kq;
	int flag = 1;
	for (int i = 0; i < x.n; i++)
	{
		NODE* p = x.dsk[i];
		while (p != NULL)
		{
			if (p->wei != 0)
			{
				if (flag)
				{
					flag = 0;
					kq.wei = p->wei;
					kq.org = i;
					kq.des = p->des;
				}
				else
				{
					if (kq.wei > p->wei)
					{
						kq.wei = p->wei;
						kq.org = i;
						kq.des = p->des;
					}
				}
			}
			p = p->link;
		}
	}
	return kq;
}

int dinhKeUBacMax(MTK x, int u)
{
	int kq, sodinhke;
	int flag=1;
	for (int j = 0; j < x.n; j++)
	{
		if (x.mtk[u][j] != 0)
		{
			if (flag)
			{
				flag = 0;
				kq = j;
				sodinhke = tinhBac(x,j);
			}
			else
			{
				if (sodinhke < tinhBac(x, j))
				{
					kq = j;
					sodinhke = tinhBac(x, j);
				}
			}
		}
	}
	return kq;
}

void xuatCanhKeUCoTrongSoMax(MTK x, int u)
{
	EDGE kq;
	int flag = 1;
	for (int i = 0; i < x.n; i++)
	{
		if (x.mtk[u][i] != 0)
		{
			if (flag)
			{
				flag = 0;
				kq.org = u;
				kq.des = i;
				kq.wei = x.mtk[u][i];
			}
			else
			{
				if (kq.wei < x.mtk[u][i])
				{
					kq.des = i;
					kq.wei = x.mtk[u][i];
				}
			}
		}
	}
	cout << "\nCanh ke " << u << " co trong so MAX: ";
	xuatCanh(kq);
}

bool docfileDSK(char* filename, DSK &x)
{
	FILE* f = fopen(filename, "rt");
	if (f == NULL)	return false;
	fscanf(f, "%d", &x.n);
	for (int i = 0; i < x.n; i++)
	{
		x.dsk[i] = NULL;
	}
	for (int i = 0; i < x.n; i++)
	{
		int m;
		fscanf(f, "%d", &m);
		for (int j = 0; j < m; j++)
		{
			NODE* p = new NODE;
			fscanf(f, "%d%d", &p->des, &p->wei);
			p->link = NULL;
			if (x.dsk[i] == NULL)
			{
				x.dsk[i] = p;
			}
			else
			{
				NODE* q = x.dsk[i];
				while (q->link != NULL)	q = q->link;
				q->link = p;
			}
		}
	}
	fclose(f);
	return true;
}

void xuatDanhSachKe(DSK x)
{
	for (int i = 0; i < x.n; i++)
	{
		cout << i << ": ";
		NODE* p = x.dsk[i];
		while (p != NULL)
		{
			cout << "(" << p->des << "," << p->wei << ")  ";
			p = p->link;
		}
		cout << endl;
	}
}

ArrayEdge TapCanhDoThiCoHuong(MTK x)
{
	ArrayEdge ae;
	ae.count = 0;
	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.n; j++)
		{
			if (x.mtk[i][j] != 0)
			{
				ae.ds[ae.count].org = i;
				ae.ds[ae.count].des = j;
				ae.ds[ae.count++].wei = x.mtk[i][j];
			}
		}
	}
	return ae;
}
ArrayEdge TapCanhDoThiCoHuong(DSK x)
{
	ArrayEdge ae;
	ae.count = 0;
	for (int i = 0; i < x.n; i++)
	{
		NODE* p = x.dsk[i];
		while (p != NULL)
		{
			ae.ds[ae.count].org = i;
			ae.ds[ae.count].des = p->des;
			ae.ds[ae.count++].wei = p->wei;
			p = p->link;
		}
	}
	return ae;
}
DSK ChuyenKieuDoThi(MTK x)
{
	DSK kq;
	kq.n = x.n;
	for (int i = 0; i < x.n; i++)
	{
		kq.dsk[i] = NULL;
		for (int j = 0; j < x.n; j++)
		{
			if (x.mtk[i][j] != 0)
			{
				NODE* p = new NODE;
				p->des= j;
				p->wei = x.mtk[i][j];
				p->link = NULL;

				if (kq.dsk[i] == NULL)
				{
					kq.dsk[i] = p;
				}
				else
				{
					NODE* q = kq.dsk[i];
					while (q->link != NULL)	q = q->link;
					q->link = p;
				}
			}
		}
	}
	return kq;
}

MTK ChuyenKieuDoThi(DSK x)
{
	MTK kq;
	kq.n = x.n;
	for (int i = 0; i < kq.n; i++)
		for (int j = 0; j < kq.n; j++)
			kq.mtk[i][j] = 0;

	for (int i = 0; i < x.n; i++)
	{
		NODE* p = x.dsk[i];
		while (p != NULL)
		{
			kq.mtk[i][p->des] = p->wei;
			p = p->link;
		}
	}
	return kq;
}

MTK TaoDoThiMTK(ArrayEdge ae, int numv)
{
	MTK kq;
	kq.n = numv;
	for (int i = 0; i < kq.n; i++)
		for (int j = 0; j < kq.n; j++)
			kq.mtk[i][j] = 0;
	
	for (int i = 0; i < ae.count; i++)
	{
		kq.mtk[ae.ds[i].org][ae.ds[i].des] = ae.ds[i].wei;
	}
	return kq;
}


DSK TaoDoThiDSK(ArrayEdge ae, int numv)
{
	DSK kq;
	kq.n = numv;
	for (int i = 0;i< kq.n; i++)
		kq.dsk[i] = NULL;
	
	for (int i = 0; i < ae.count; i++)
	{
		NODE* p = new NODE;
		p->des = ae.ds[i].des;
		p->wei = ae.ds[i].wei;
		p->link = NULL;
		if (kq.dsk[ae.ds[i].org] == NULL)
		{
			kq.dsk[ae.ds[i].org] = p;
		}
		else
		{
			NODE* q = kq.dsk[ae.ds[i].org];
			while (q->link != NULL)	q = q->link;
			q->link = p;
		}
	}
	return kq;
}

bool docfileTapCanh(char* filename, ArrayEdge &ae)
{
	char kytuao;
	FILE* f = fopen(filename, "rt");
	if (f == NULL) return false;
	fscanf(f, "%d\n", &ae.count);
	for (int i = 0; i < ae.count; i++)
	{
		fscanf(f, "%c", &kytuao);
		fscanf(f, "%d%c%d%c", &ae.ds[i].org, &kytuao, &ae.ds[i].des, &kytuao);
		fscanf(f, "%d", &ae.ds[i].wei);
		fscanf(f, "%c\t", &kytuao);
	}
	fclose(f);
	return true;
}
void xuatTapCanh(ArrayEdge ae)
{
	for (int i = 0; i < ae.count; i++)
	{
		xuatCanh(ae.ds[i]);
	}
}

ArrayEdge TapCanhDoThiVoHuong(MTK x)
{
	ArrayEdge kq;
	kq.count = 0;
	for (int i = 0; i <= x.n; i++)
	{
		for (int j = 0; j < x.n; j++)
		{
			if (x.mtk[i][j]!= 0 && i < j)
			{
				kq.ds[kq.count].org = i;
				kq.ds[kq.count].des = j;
				kq.ds[kq.count++].wei = x.mtk[i][j];
			}
		}
	}
	return kq;
}

ArrayEdge TapCanhDoThiVoHuong(DSK x)
{
	ArrayEdge kq;
	kq.count = 0;
	int check;
	for (int i = 0; i < x.n; i++)
	{
		NODE*p = x.dsk[i];
		while (p != NULL)
		{
			check = 0;
			for (int j = 0; j < kq.count; j++)
			{
				if (i == kq.ds[j].des&&p->des == kq.ds[j].org&&p->wei == kq.ds[j].wei)
					check = 1;
			}
			if (!check)
			{
				kq.ds[kq.count].org = i;
				kq.ds[kq.count].des = p->des;
				kq.ds[kq.count++].wei = p->wei;
			}
			p = p->link;
		}
	}
	return kq;
}