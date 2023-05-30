#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//-------------Node setting-----------

struct SV
{
    char MaSV[11], Hoten[41];
    float dtb;
};

struct Node{
    SV info;
    struct Node* next;
};

void init(Node* &phead)
{
    phead = NULL;
}

int isEmpty(Node* &phead)
{
    return (phead == NULL);
}

Node* CreateNode(SV a)
{
    Node* ptr = new Node;
    ptr->info = a;
    ptr->next = NULL;
    return ptr;
}

//-------------------Assist--------------

void Nhap1SV(SV &a)
{
    printf("\nMa SV: ");    fflush(stdin);  gets(a.MaSV);
    printf("Ho ten: ");   fflush(stdin);  gets(a.Hoten);
    printf("Diem trung binh: ");  float temp; scanf("%f",&temp);  a.dtb = temp; 
}

void Xuat1SV(SV a)
{
    printf("\nMa SV: ");    puts(a.MaSV);
    printf("Ho ten: ");     puts(a.Hoten);
    printf("Diem trung binh: %.2f",a.dtb);
    printf("\n\n");
}

//-----------------Activity in List-------------

void InsertFirst(Node* &phead, SV a)
{
    Node* ptr = CreateNode(a);
    ptr->next = phead;
    phead = ptr;
}

void InsertLast(Node* &phead, SV a)
{
    Node* ptr = phead;
    if(ptr == NULL)
        InsertFirst(phead,a);
    else{
        while(ptr->next != NULL)
            ptr = ptr->next;
        Node* newNode = CreateNode(a);
        ptr->next = newNode;
    }
}

void InsertAfter(Node *ptr, SV a)
{
    Node* newNode;
    if(ptr != NULL){
        newNode = CreateNode(a);
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

Node* SearchX(Node* &phead, char x[])
{
    Node* ptr = phead;
    while(ptr != NULL && strcmp(x,ptr->info.MaSV) != 0)
        ptr = ptr->next;
    return ptr;
}

void SelectionSort(Node* &phead)
{
    Node* p,*q,*pmin;
    for(p = phead; p!= NULL; p = p->next){
        pmin = p;
        for(q = p->next; q != NULL; q = q->next){
            if(q->info.dtb < pmin->info.dtb)
                pmin = q;
        }
        SV t = p->info;
        p->info = pmin->info;
        pmin->info = t;
    }
}

void DeleteFirst(Node* &phead)
{
    Node* ptr;
    if(phead == NULL)
        printf("\nDanh sach rong, khong the xoa.");
    else{
        ptr = phead;
        phead = phead->next;
        delete ptr;
    }
}

void DeleteAfter(Node* ptr)
{
    Node* q;
    if(ptr == NULL || ptr->next == NULL)
        printf("\nKhong the xoa.");
    else{
        q = ptr->next;
        ptr->next = q->next;
        delete q;
    }
}

void ClearList(Node* phead)
{
    Node* ptr;
    while(phead != NULL){
        ptr = phead;
        phead = ptr->next;
        delete ptr;
    }
}

Node* SearchBeforeX(Node* &phead, char x[])
{
    Node* ptr = phead;
    if(strcmp(ptr->info.MaSV,x) == 0)
        return ptr;
    else{
        while(ptr != NULL && ptr->next != NULL && strcmp(x,ptr->next->info.MaSV) != 0)
            ptr = ptr->next;
        return ptr;
    }
}

void DeleteBeforeX(Node* ptr, Node* &phead)
{
    if(ptr == phead)
        DeleteFirst(phead);
    else{
       DeleteAfter(ptr);
    }
        
}

void InterchageSortStudentID(Node* &phead)
{
    for(Node* ptr = phead;ptr != NULL; ptr = ptr->next)
        for(Node* q = ptr->next;q != NULL; q = q->next)
            if(strcmp(ptr->info.MaSV,q->info.MaSV)  > 0 )
            {
                SV a = ptr->info;
                ptr->info = q->info;
                q->info = a;
            }
}

Node* Min(Node* &phead)
{
    if(phead == NULL)
        return NULL;
    else{
        Node* ptr = phead->next;
        float min = phead->info.dtb;
        while(ptr != NULL){
            if(min > ptr->info.dtb)
                min = ptr->info.dtb;
            ptr = ptr->next; 
        }
        return ptr;
    }
}

Node* Max(Node* &phead)
{
    if(phead = NULL)
        return NULL;
    else{
        Node* ptr = phead->next;
        float max = phead->info.dtb;
        while(ptr != NULL){
            if(max < ptr->info.dtb)
                max = ptr->info.dtb;
            ptr = ptr->next;
        }
        return ptr;
    }
}

//---------------------CODE--------------------
//a
void NhapSV(Node* &phead, SV a)
{
    char choice;    // t : true f: false
    do{
        printf("\nT: tiep tuc nhap; f: dung nhap\nNhap lua chon: ");    fflush(stdin);    scanf("%c",&choice);    
        if(choice == 't' ){
            Nhap1SV(a);
            InsertLast(phead,a);
        }
    } while (choice == 't');
}
//b
void XuatSV(Node* &phead)
{
    Node* ptr = phead;
    if(ptr == NULL)
        printf("\nDanh sach rong.");
    else{
        while(ptr != NULL){
            Xuat1SV(ptr->info);
            ptr = ptr->next;
        }
    }
}
//c
void XuatSVdtblon5(Node* phead)
{
    Node* ptr = phead;
    if(ptr == NULL)
        printf("\nDanh sach rong, vi vay khong co sv dtb > 5");
    else{
        while(ptr != NULL){
            if (ptr->info.dtb > 5){
                Xuat1SV(ptr->info);
            }
            ptr = ptr->next;
        }
    }
}
//d
void FindX(Node* &phead)
{
    char MSSV[11];
    printf("\nNhap MSSV can tim: ");    fflush(stdin);  gets(MSSV);
    Node* temp = SearchX(phead,MSSV);
    if(temp == NULL)
        printf("\nKhong tim thay");
    else{
        Xuat1SV(temp->info);
    }
}
//e: Trong phan activity in list
//f
void InsertAfterX(Node* &phead)
{
    char MSSV[11];
    printf("\nNhap MSSV can them vao sau: ");   fflush(stdin);  gets(MSSV);
    if(SearchX(phead,MSSV) == NULL)
        printf("\nKhong tim duoc sinh vien, vi the khong them duoc");
    else{
        SV y;
        printf("\nNhap thong tin sinh vien them vao: ");
        Nhap1SV(y);
        InsertAfter(SearchX(phead,MSSV),y);
    }
}
//g: Trong activity in List
//h
void DeleteLast(Node* &phead)
{
    if(phead == NULL)
        printf("\nDS rong");
    else{
        if(phead->next == NULL)
            DeleteFirst(phead);
        else{
            Node *ptr = phead;
            while(ptr != NULL && ptr->next != NULL && ptr->next->next != NULL)
                ptr = ptr->next;
            DeleteAfter(ptr);
        }
    }
}
//i trong activity in list
//j
void DeleteX(Node* &phead)
{
    char MSSV[11];
    printf("\nMSSV can xoa: "); fflush(stdin);  gets(MSSV);
    if(SearchBeforeX(phead,MSSV) == NULL)
        printf("\nKhong the xoa.");
    else{
        DeleteBeforeX(SearchBeforeX(phead,MSSV),phead);
    }
}
//k
void DeleteAfterX(Node* &phead)
{
    char MSSV[11];
    printf("\nMSSV can xoa: "); fflush(stdin);  gets(MSSV);
    if(SearchX(phead,MSSV) == NULL)
        printf("\nKhong the xoa.");
    else{
        DeleteAfter(SearchX(phead,MSSV));
    }

}
//l
void DeleteAllX(Node* &phead)
{
    Node* ptr = phead;
    char MSSV[11];
    printf("\nMSSV can xoa: "); fflush(stdin);  gets(MSSV);
    do
    {
        if(SearchBeforeX(ptr,MSSV) != NULL){
            DeleteBeforeX(SearchBeforeX(ptr,MSSV),phead);
        }
    } while (ptr != NULL);   
}
//m: Trong activity list
//n
void PrintEEL(Node* &phead)
{
    Node* ptr = phead;
    while(ptr != NULL){
        if(ptr->info.dtb > 6.5)
            Xuat1SV(ptr->info);
        ptr = ptr->next;
    }
}
//o
void PrintMinMax(Node* &phead)
{
    char m;
    printf("\nN: Xuat SV co dtb thap nhat\nL: Xuat SV co dtb cao nhat.\nNhap lua chon:");   fflush(stdin);  scanf("%c",&m);
    if(m == 'n'){
        if(Min(phead)!= NULL)
            Xuat1SV(Min(phead)->info);
    }
    if(m == 'l'){
        if(Max(phead) != NULL)
            Xuat1SV(Max(phead)->info);
    }
}
//p
float FindA(Node* &phead)
{
    Node* ptr = phead;
    while(ptr != NULL){
        if(ptr->info.dtb > 8)
            return ptr->info.dtb;
        ptr = ptr->next;
    }
}

void FindMinA(Node* &phead)
{
    float min = FindA(phead);
    Node* ptr = phead;
    while(ptr != NULL){
        if(ptr->info.dtb > 8 && min > ptr->info.dtb) 
            min = ptr->info.dtb;
        ptr= ptr->next;
    }
    printf("\nHoc sinh gioi co dtb thap nhat la: ");
    Xuat1SV(ptr->info);

}
int main()
{
    Node* phead;
    SV a;
    init(phead);
    char choice;
    do
    {
        system("cls");
        printf("\na: Nhap danh sach");
        printf("\nb: Xuat danh sach");
        printf("\nc: Xuat sinh vien co DTB>5");
        printf("\nd: Tim sinh vien co ma X");
        printf("\ne: Sap xep tang dan theo DTB");
        printf("\nf: Them 1 sinh vien sau sv x");
        printf("\ng: Xoa dau danh sach");
        printf("\nh: Xoa cuoi danh sach");
        printf("\ni: Xoa toan bo danh sach");
        printf("\nj: Xoa sinh vien co ma X");
        printf("\nk : Xoa mot sinh vien sau sinh vien");
        printf("\nl : Xoa tat ca sinh vien co MSSV X");
        printf("\nm: Sap xep theo MSSV");
        printf("\nn: In DS xep loai kha");
        printf("\no: Tim sinh vien co dtb cao nhat/thap nhat");
        printf("\np: Tim sinh vien co dtb thap nhat thuoc hoc sinh gioi");
        printf("\nz: Thoat chuong trinh");
        printf("\nChon cong viec: ");   fflush(stdin);   scanf("%c",&choice);    
        switch (choice)
        {
            case 'a':
                NhapSV(phead,a);
                break;
            case 'b':
                XuatSV(phead);
                system("pause");
                break;
            case 'c':
                XuatSVdtblon5(phead);
                system("pause");
                break;
            case 'd':
                FindX(phead);
                system("pause");
                break;
            case 'e':
                SelectionSort(phead);
                system("pause");
                break;
            case 'f':
                InsertAfterX(phead);
                system("pause");
                break;
            case 'g': 
                DeleteFirst(phead);
                system("pause");
                break;
            case 'h':
                DeleteLast(phead);
                system("pause");
                break;
            case 'i':
                ClearList(phead);
                system("pause");
                break;
            case 'j':
                DeleteX(phead);
                system("pause");
                break;
            case 'k':
                DeleteAfterX(phead);
                system("pause");
                break;
            case 'l':
                DeleteAllX(phead);
                system("pause");
                break;
            case 'm':
                InterchageSortStudentID(phead);
                system("pause");
                break;
            case 'n':
                PrintEEL(phead);
                system("pause");
                break;
            case 'o':
                PrintMinMax(phead);
                system("pause");
                break;
            case 'p':
                FindMinA(phead);
                system("pause");
                break;
        default:
            choice = 'z';
            break;
        }

    } while (choice != 'z');
    return 0;
}
