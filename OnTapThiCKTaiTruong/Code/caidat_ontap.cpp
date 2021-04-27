
#include "thuvien_ontap.h"

//Xuất đỉnh v ra màn hình
void printVertex(VERTEX v)
{
	cout << v;
}

//Xuất cạnh e ra màn hình
void printEdge(EDGE e)
{
	cout << "(" << e.org << "," << e.des << ")";
}

//Xuất danh sách đỉnh ra màn hình
void printArrayVertex(ArrayVertex av)
{
	for (int i = 0; i<av.count; i++)
	{
		cout << "\t";
		printVertex(av.ds[i]);
	}
}

//Xuất danh sách cạnh ra màn hình
void printArrayEdge(ArrayEdge ae)
{
	for (int i = 0; i<ae.count; i++)
	{
		cout << "\t";
		printEdge(ae.ds[i]);
	}
}

//Đọc một ma trận kề từ file văn bản.
int Read(char* filename, AdjacencyMatrix& g)
{
	FILE *f;
	fopen_s(&f, filename, "rt");
	if (f == NULL) return 0;
	fscanf_s(f, "%d", &g.n);
	for (int i = 0; i<g.n; i++)
		for (int j = 0; j<g.n; j++)
			fscanf_s(f, "%d", &g.mt[i][j]);
	fclose(f);
	return 1;
}
// doc danh sach ke
int docFile(const char* tenfile, DANHSACHKE& x) 
{
	FILE* f;
	fopen_s(&f,tenfile, "rt");
	if (f == NULL) return 0;
	fscanf_s(f, "%d", &x.n);
	for (int i = 0; i < x.n; i++)
		x.dsk[i] = NULL;
	for (int i = 0; i < x.n; i++)
	{
		int m;
		fscanf_s(f, "%d", &m);
		for (int j = 0; j < m; j++)
		{
			NODEVERTEX* p = new NODEVERTEX;
			fscanf_s(f, "%d%d", &p->dinhke, &p->trongso);
			p->link = x.dsk[i];
			x.dsk[i] = p;
		}
	}
	fclose(f);
	return 1;
}

//Ghi một ma trận kề lên file văn bản.
int Write(char* filename, AdjacencyMatrix g)
{
	FILE *f;
	fopen_s(&f, filename, "wt");
	if (f == NULL) return 0;
	fprintf(f, "%d", g.n);
	for (int i = 0; i<g.n; i++)
	{
		fprintf(f, "\n");
		for (int j = 0; j<g.n; j++)
			fprintf(f, "%d\t", g.mt[i][j]);
	}
	fclose(f);
	return 1;
}

//Hàm xuất ma trận kề ra màn hình
void Xuat(AdjacencyMatrix g)
{
	cout << "\n Gia tri trong file la: ";
	cout << "\n" << g.n << "\n";
	for (int i = 0; i<g.n; i++)
	{
		for (int j = 0; j<g.n; j++)
			cout << g.mt[i][j] << " ";
		cout << "\n";
	}
}

//Hàm tính bậc vào đồ thị có hướng
int TinhBacVaoDTCoHuong(AdjacencyMatrix g, int dinh)
{
	int dem = 0;
	for (int i = 0; i<g.n; i++)
	{
		if (g.mt[i][dinh] != 0)
			dem++;
	}
	return dem;
}

//Hàm trả về tập cạnh của đồ thị có hướng
ArrayEdge TapCanhDTCH(AdjacencyMatrix g)
{
	ArrayEdge tapcanh;
	tapcanh.count = 0;
	for (int i = 0; i<g.n; i++)
		for (int j = 0; j<g.n; j++)
			if (g.mt[i][j] != 0)
			{
		EDGE e;
		e.org = i;
		e.des = j;
		e.wei = g.mt[i][j];
		tapcanh.ds[tapcanh.count] = e;
		tapcanh.count++;
			}
	return tapcanh;
}
// ham xuat danh sach ke
void xuatDSK(DANHSACHKE x) 
{
	cout << endl;
	for (int i = 0; i < x.n; i++)	{
		cout << endl;
		NODEVERTEX* p = x.dsk[i];
		cout << i << ": ";
		while (p != NULL)		{
			cout << " (" << p->dinhke << "," << p->trongso << ")";
			p = p->link;
		}
	}
}


int bacVao1Dinh(MTK x, VERTEX u)
{
	int count = 0;
	for (int i = 0; i < x.n; i++)
	{
		if (x.mt[i][u] != 0)	count++;
	}
	return count;
}
int bacRa1Dinh(MTK x, VERTEX u)
{
	int count = 0;
	for (int i = 0; i < x.n; i++)
	{
		if (x.mt[u][i] != 0)	count++;
	}
	return count;
}
int bac1DinhCuaDoThiCoHuong(MTK x, VERTEX u)
{
	return bacRa1Dinh(x, u) + bacVao1Dinh(x, u);
}
int bacVao1Dinh(DSK x, VERTEX u)
{
	int count = 0;
	for (int i = 0; i < x.n; i++)
	{
		if (i == u)	continue;
		NODE* p = x.dsk[i];
		while (p != 0)
		{
			if (p->dinhke == u)	count++;
			p = p->link;
		}
	}
	return count;
}
int bacRa1Dinh(DSK x, VERTEX u)
{
	int count = 0;
	NODE* p = x.dsk[u];
	while (p != 0)
	{
		if (p->dinhke == u)	count++;
		p = p->link;
	}
	return count;
}
int bac1DinhCuaDoThiCoHuong(DSK x, VERTEX u)
{	
	return bacRa1Dinh(x, u) + bacVao1Dinh(x, u);
}

EDGE canhMax(MTK x)
{
	EDGE e;
	int flag = 1;
	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.n; j++)
		{
			if (x.mt[i][j] != 0)
			{
				if (flag)
				{
					flag = 0;
					e.org = i;
					e.des = j;
					e.wei = x.mt[i][j];
				}
				else
				{
					if (e.wei <= x.mt[i][j])
					{
						e.org = i;
						e.des = j;
						e.wei = x.mt[i][j];
					}
				}
			}
		}
	}
	return e;
}
EDGE canhMin(MTK x)
{
	EDGE e;
	int flag = 1;
	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.n; j++)
		{
			if (x.mt[i][j] != 0)
			{
				if (flag)
				{
					flag = 0;
					e.org = i;
					e.des = j;
					e.wei = x.mt[i][j];
				}
				else
				{
					if (e.wei >= x.mt[i][j])
					{
						e.org = i;
						e.des = j;
						e.wei = x.mt[i][j];
					}
				}
			}
		}
	}
	return e;
}
EDGE canhMax(DSK x)
{
	EDGE e;
	int flag = 1;
	for (int i = 0; i < x.n; i++)
	{
		NODE* p = x.dsk[i];
		while (p != NULL)
		{
			if (p->trongso != NULL)
			{
				if (flag)
				{
					flag = 0;
				}
				else
				{
					if (e.wei <= p->trongso)
					{
						e.org = i;
						e.des = p->dinhke;
						e.wei = p->trongso;
					}
				}
			}
			p = p->link;
		}
	}
	return e;
}
EDGE canhMin(DSK x)
{
	EDGE e;
	int flag = 1;
	for (int i = 0; i < x.n; i++)
	{
		NODE* p = x.dsk[i];
		while (p != NULL)
		{
			if (p->trongso != NULL)
			{
				if (flag)
				{
					flag = 0;
					e.org = i;
					e.des = p->dinhke;
					e.wei = p->trongso;
				}
				else
				{
					if (e.wei >= p->trongso)
					{
						e.org = i;
						e.des = p->dinhke;
						e.wei = p->trongso;
					}
				}
			}
			p = p->link;
		}
	}
	return e;
}
ArrayEdge TapCanhDoThiCoHuong(MTK x)
{
	ArrayEdge ae;
	ae.count = 0;
	for (int i = 0; i < x.n; i++)
	{
		for (int j = 0; j < x.n; j++)
		{
			if (x.mt[i][j] != 0)
			{
				ae.ds[ae.count].org = i;
				ae.ds[ae.count].des = j;
				ae.ds[ae.count++].wei = x.mt[i][j];
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
			if (p->trongso != 0)
			{
				ae.ds[ae.count].org = i;
				ae.ds[ae.count].des = p->dinhke;
				ae.ds[ae.count++].wei = p->trongso;
			}
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
			if (x.mt[i][j] != 0)
			{
				NODE* p = new NODE;
				p->dinhke = j;
				p->trongso = x.mt[i][j];
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
//MTK ChuyenKieuDoThi(DSK x)
//{
//
//}