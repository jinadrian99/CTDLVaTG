//#include "HeaderL4.h"
//
//Xuất đỉnh v ra màn hình
//void printVertex(VERTEX v)
//{
//	cout << v;
//}
//
//Xuất cạnh e ra màn hình
//void printEdge(EDGE e)
//{
//	cout << "(" << e.org << "," << e.des;
//	if (e.wei != 0)
//		cout << "," << e.wei << ")";
//	else
//		cout << ")";
//}
//
//Xuất danh sách đỉnh ra màn hình
//void printArrayVertex(ArrayVertex av)
//{
//	for (int i = 0; i<av.count; i++)
//	{
//		cout << "\t";
//		printVertex(av.ds[i]);
//	}
//}
//
//Xuất danh sách cạnh ra màn hình
//void printArrayEdge(ArrayEdge ae)
//{
//	for (int i = 0; i<ae.count; i++)
//	{
//		cout << "\t";
//		printEdge(ae.ds[i]);
//	}
//}
//
//Đọc một ma trận kề từ file văn bản.
//int Read(char* filename, AdjacencyMatrix& g)
//{
//	FILE *f;
//	fopen_s(&f, filename, "rt");
//	if (f == NULL) return 0;
//	fscanf_s(f, "%d", &g.n);
//	for (int i = 0; i<g.n; i++)
//		for (int j = 0; j<g.n; j++)
//			fscanf_s(f, "%d", &g.mt[i][j]);
//	fclose(f);
//	return 1;
//}
//
//Ghi một ma trận kề lên file văn bản.
//int Write(char* filename, AdjacencyMatrix g)
//{
//	FILE *f;
//	fopen_s(&f, filename, "wt");
//	if (f == NULL) return 0;
//	fprintf(f, "%d", g.n);
//	for (int i = 0; i<g.n; i++)
//	{
//		fprintf(f, "\n");
//		for (int j = 0; j<g.n; j++)
//			fprintf(f, "%d\t", g.mt[i][j]);
//	}
//	fclose(f);
//	return 1;
//}
//
//Hàm xuất ma trận kề ra màn hình
//void Xuat(AdjacencyMatrix g)
//{
//	cout << "\n Gia tri trong file la: ";
//	cout << "\n" << g.n << "\n";
//	for (int i = 0; i<g.n; i++)
//	{
//		for (int j = 0; j<g.n; j++)
//			cout << g.mt[i][j] << " ";
//		cout << "\n";
//	}
//}
//
//Hàm tính bậc vào đồ thị có hướng
//int TinhBacVaoDTCoHuong(AdjacencyMatrix g, int dinh)
//{
//	int dem = 0;
//	for (int i = 0; i<g.n; i++)
//	{
//		if (g.mt[i][dinh] != 0)
//			dem++;
//	}
//	return dem;
//}
//
//Hàm trả về tập cạnh của đồ thị có hướng
//ArrayEdge TapCanhDTCH(AdjacencyMatrix g)
//{
//	ArrayEdge tapcanh;
//	tapcanh.count = 0;
//	for (int i = 0; i<g.n; i++)
//		for (int j = 0; j<g.n; j++)
//			if (g.mt[i][j] != 0)
//			{
//		EDGE e;
//		e.org = i;
//		e.des = j;
//		e.wei = g.mt[i][j];
//		tapcanh.ds[tapcanh.count] = e;
//		tapcanh.count++;
//			}
//	return tapcanh;
//}
//void Init(Queue &Q)
//{
//	Q.count = 0;
//}
//int Isempty(Queue Q)
//{
//	return (Q.count == 0);
//}
//int Isfull(Queue Q)
//{
//	return (Q.count == MAXV);
//}
//void Push(Queue &Q, item x)
//{
//	Q.Data[Q.count++] = x;
//}
//int Pop(Queue &Q)
//{
//	int tam = Q.Data[0];
//	for (int i = 0; i < Q.count - 1; i++)
//		Q.Data[i] = Q.Data[i + 1];
//	Q.count--;
//	return tam;
//}
//int Qfront(Queue Q)
//{
//	return Q.Data[0];
//}
//
//void Duyet_BFS(AdjacencyMatrix MTK, VERTEX start)
//{
//	int VISIT[MAXV];
//	int layptdinhvt[MAXV];
//	int n = 0;
//	VERTEX u;
//	Queue Q;
//
//	for (int i = 0; i < MTK.n; i++)
//	{
//		VISIT[i] = -1;
//	}
//	VISIT[start] = start;
//	cout << start << "  ";
//	layptdinhvt[n++] = start;
//
//	Init(Q);
//	Push(Q, start);
//
//	while (Isempty(Q) == 0)
//	{
//		u = Pop(Q);
//		for (int v = 0; v < MTK.n; v++)
//		{
//			if (MTK.mt[u][v] != 0 && VISIT[v] == -1)
//			{
//				VISIT[v] = u;
//				cout << u << '-' << v << "  ";
//				layptdinhvt[n++] = v;
//				Push(Q, v);
//			}
//		}
//	}
//
//	FILE* f = fopen("av.txt", "wt");
//	if (f != NULL)
//	{
//		for (int i = 0; i < n; i++)
//			fprintf(f, "%d  ", layptdinhvt[i]);
//		fclose(f);
//	}
//
//	no cai canh ti ve tim hieu r lam no
//}
//
//
//void Init(Stack &st)
//{
//	st.top = 0;
//}
//int Isempty(Stack st)
//{
//	return (st.top == 0);
//}
//int Isfull(Stack st)
//{
//	return (st.top == MAXV);
//}
//void Push(Stack &st, item x)
//{
//	if (!Isfull(st))
//	{
//		st.Data[st.top] = x;
//		st.top++;
//	}
//}
//int Pop(Stack &st)
//{
//	if (!Isempty(st))
//	{
//		st.top--;
//		return st.Data[st.top];
//	}
//}
//int Peak(Stack st)
//{
//	return st.Data[st.top - 1];
//}
//void Duyet_DFS(AdjacencyMatrix MTK, VERTEX start)
//{
//	int VISIT[MAXV];
//	VERTEX u;
//	Stack S;
//	for (int i = 0; i < MTK.n; i++)
//	{
//		VISIT[i] = -1;
//	}
//
//	Init(S);
//	Push(S, start);
//	VISIT[start] = start;
//	cout << start << "  ";
//
//	while (Isempty(S) == 0)
//	{
//		u = Pop(S);
//		for (int v = 0; v < MTK.n; v++)
//		{
//			if (MTK.mt[u][v] != 0 && VISIT[v] == -1)
//			{
//				VISIT[v] = u;
//				cout << v << "  ";
//				Push(S, u);
//				Push(S, v);
//				break;
//			}
//		}
//	}
//}