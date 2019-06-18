#include <stdio.h>
struct node
{
	int data;
	struct node* pLeft;
	struct node* pRight;
};
typedef node NODE;
typedef NODE* TREE;

//khoi tao cay
void KhoiTao(TREE &t)
{
	t == NULL;
}

//them node vao cay
void InsertNode(TREE &t, int x)
{
	if(t==NULL)
	{
		node *p = new node;
		x = p;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else 
	{
		if(x < t->data)     InsertNode(t->pLeft, x);
		else if(x > t->data)   InsertNode(t->pRight, x);
	}
}

//duyet cay
void DisplayTree(TREE t)
{
	if(t != NULL)
	{
		printf("%5d", t->data);
		DisplayTree(t->pLeft);
		DisplayTree(t->pRight);
	}
}

//tim kiem node
void NODE* SearchNode(TREE &t, int x)
{
	if(t==NULL)
	return  NULL ;
	else
	{
	    if(x < t->data)     SearchNode(t->pLeft, x);
	    if(x > t->data)     SearchNode(t->pRight, x);
	    else                return t;
    }
}

//tim node the mang
void NODE *TimNodeTheMang(TREE &X, TREE &Y)
{
	if(Y->pLeft != NULL)
	TimNodeTheMang(X,Y->pLeft);
	else
	{
		X->data = Y->data;
		X = Y;
		Y = Y->pRight;
	}
}

//xoa phan tu bat ki trong cay
void DeleteNode(TREE &t, int x)
{
	if(t == NULL)
	return 
	else
	{
		if(x < t->data)       DeleteNode(t->pLeft, x);
		else if(x > t->data)  DeleteNode(t->pRight, x);
		else  //dd tim ra phan tu de xoa
		{   
		    NODE *X = t;
			if(t->pLeft == NULL)
			t = t->pRight;
			else if(t->pRight == NULL)
			t = t->pLeft;
			else
			{
				NODE *Y = t->pRight;
				TimNodTheMang(X, Y);
			}   
			delete X;  
		}
	}
}

//dem co bao nhieu so nguyen to trong cay
int  KiemTra(int x)
{
	if(x < 2)   return 0;
	else
	{
		for(int i =2; i<x;i++)
		{
			if(x%i = 0)    return 0
			else return 1;  
		}
	}   
}

//dem co bao nhieu so nguyen to
int DemSoNguyenTo(TREE &t, int &dem)
{
	int dem = 0;
	if(t != NULL)
	{
		if(KiemTra(t->data) = 1)     
		dem = dem +1;
		DemSoNguyenTo(t->pLeft, dem);
		DemSoNguyenTo(t->pRight, dem);
	}
	return dem;
}

void main()
{
	TREE t;
	int x,y;
	KhoiTao(t)
	while(true)
	{
		int luachon;
		printf("\n1. nhap cay moi");
		printf("\n2. xuat cay");
		printf("\n3. xoa node");
		printf("\n4. Tim kiem");
		printf("\n0. Thoat");
		printf("\nnhap lua chon");
		scanf("%d", &luachon);
		if((luachon <0)||(luachon>4))   printf("\nnhap lai lua chon");
		else if(luachon = 1)
		{
			printf("\nnhap du lieu: ");
			scanf("d", &x);
			InsearchNode(t,x);
		}
		else if(luachon = 2)
		{
			printf("\nCay ban vua nhap theo NLR: ");
			DisplayNode(t);
		}
		else if(luachon = 3)
		{
			printf("\nCan xoa phan tu: ");
			scanf("%d", &y);
			
		}
	}
}
