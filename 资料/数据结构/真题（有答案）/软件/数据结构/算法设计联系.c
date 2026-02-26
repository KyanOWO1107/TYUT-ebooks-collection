#define MAXSIZE 100

//顺序表逆序
typedef struct SqList {
    int *elem;
    int length;
}SqList;

void ListReverse(SqList &L){
    int left=0;
    int right=L.length-1;

    while(left<right){
        int temp = L.elem[left];
        L.elem[left] = L.elem[right];
        L.elem[right] = temp;
        left++;
        right--;
    }
}

//单链表逆序
typedef struct LNode {
    int elem;
    struct LNode* next;
}LNode, *LinkList;

void LNodeReverse(LinkList &L) {
    //链表为空的条件->头结点为空或者首元结点为空
    if (L == NULL || L->next == NULL) {
        return;
    }
    //当链表不为0时，进行逆序操作

    //指定头指针指向首元结点
    LNode* begin = L->next;
    //指定尾结点指向首元结点的下一个结点;
    LNode* next = L->next->next;

    //当尾指针不为NULL时
    while (end != MNULL) {
        begin->next = end->next;
        end->next = L->next;
        L->next = end;
        end = begin->next;
    }
}

//设计一个算法，返回单链表中倒数第k个结点的指针,若不存在，则返回空指针
typedef struct LNode {
    int data;
    struct LNode* next;
}LNode, *LinkList;

LNode* last_kth_node(LinkList& L,int k) {
    //判断链表是否为空
    if (L == NULL || L->next == NULL) {
        return NULL; //若不存在返回空指针;
    }

    LNode* fast = L;
    LNode* slow = L;

    while (k-- > 0) {
        if (fast == NULL) {
            return NULL;
        }
        fast = fast->next;
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow->next;
}


//顺序表删除指定范围值的元素
typedef struct SqList {
    int* elem;
    int length;
}SqList;

void Delete(SqList& L, int i, int j) {
    int a = 0;
    int b = 0;

    //找前索引
    while (L.elem[a] < i) {
        a++;
    }
    //前索引不能越界
    if (a > L.length) {
        return;
    }
    //找后索引
    //后索引也不能越界
    while (L.elem[b] <= j && b<=L.length) {
        b++;
    }

    while (b < L.length) {
        L.elem[i++] = L.elem[j++];
    }

    //更新长度
    L.length = i;
}


//先序创建二叉树
typedef struct BiTNode {
    char data;
    struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

void createBiTree(BiTree& T) {
    char c = getchar();

    //判断是否为空结点，若为空结点，设置为NULL
    if (c == "#") {
        //如果根结点是#，说明这棵树是空树
        T = NULL;
        return;
    }
    else {
        T = new BiTNode;
        T->data = c;
        create(T->lchild);
        create(T->rchild);
    }
}

void middle(BiTree& T) {
    if (T == NULL) {
        return;
    }
    else {
        middle(T->lchild);
        cout >> T->Data;
        middle(T->rchild);
    }
}

//判断两棵树是否相同
typedef struct BiTNode {
    char data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

int CompareTree(BiTree& T1,BiTree&T2) {
    //当树为空树时两树相等
    if (T1 == NULL && T2 == NULL) {
        return 1;
    }
    //空树和任何非空树都不相同
    if (T1 == NULL || T2 == NULL) {
        return 0;
    }
    //根节点不同的两棵树一定不相同
    if (T->data != T2->data) {
        return 0;
    }

    return CompareTree(T1->lchil, T2->lchild) && CompareTree(T1->rchild, T2->rchild);

}

//合并两颗树
typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

BiTree hebing(BiTree& T1, BiTree& T2) {
    //有一个是空树，直接返回另一颗树
    if (T1 == NULL) {
        return T2;
    }

    if (T2 == NULL) {
        return T1;
    }

    //比较对应结点
    if (T1->data != "#" && T2->data != "#"{
        T1->data+=T2->data;
    })else if(T1->data=="#") {
            T1->data = T2->data;
        }
    else {
        T1->data = T2->data;
        }
    T1->lchild = hebing(T1->lchild, T2->lchild);
    T1->rchild = hebing(T1->rchild, T2->rchild);
}


//交换二叉树左右孩子
typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

void swapBiTree(BiTree& T) {
    if (T == NULL) {
        return;
    }

    BiTree = temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;

    swapTree(T->lchild);
    swapTree(T->rchild);
}

//完全二叉树判断(需要用到队列)
typedef struct BiTNode {
    int data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

int ifCompleteTree(BiTree& T) {
    //空树满足完全二叉树的条件
    if (T == NULL) {
        return 1;
    }
    //c++的queue队列结构
    queue<BiTree> q;
    q.push(T);

    bool biaoji = false;//标记是否遇到了空结点

    while (!q.empty()) {
        BiTree node = q.front();
        q.pop();

        if (node == NULL) {
            biaoji = true;
        }
        else {
            if (biaoji) {
                return 0;
            }

            q.push(node->lchild);
            q.push(node->rchild);
        }
    }
}

//折半查找(递归法)
typedef struct SSTable {
    int* R;
    int length;
}SSTable;

int BinSearch_recur(SSTable ST, int key, int low, int high) {
    int mid = (low + high) / 2;

    if (ST.R[mid] == key) {
        return mid;
    }
    else if (ST.R[mid] < key) {
        return BinSearch_recur(ST, key, mid+ 1, high);
    }
    else BinSearch_recur(ST, key, low, mid - 1);
}

//折半查找(非递归法)
int BinSearch_norecur(SSTable ST, int key, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (ST.R[mid] == key) {
            return mid;
        }
        else if (ST.R[mid] < key) {
            low = low + 1;
        }
        else {
            high = high - 1;
        }
    }
}

//二叉排序树(递归查找)
typedef struct BSTNode {
    int data;
    struct BSTNode* lchild, * rchild;
}BSTNode, * BSTree;

BSTNode* SearchBST_cur(BSTree& T, int key) {
    if (T == NULL || T->data == key) {
        return T;
    }
    if (key < T->data) {
        return SearchBST_cur(T->lchild);
    }
    else {
        return SearchBST_cur(T->rchild);
    }
}

//二叉排序树(非递归查找)
BSTNode* SearchBST_cur(BSTree& L, int key) {
    while (T != NULL && T->data != key) {
        if (T->data < key) {
            T = T->lchild;
        }
        else {
            T = T->lchild;
        }
    }

    return T;
}

//插入排序
typedef struct SqList {
    int* elem;
    int length;
}SqList;

void InsertSort(SqList& L) {
    //索引为0处为暂存哨
    for (int i = 2; i < L.length; i++) {
        //如果小的话才需要替换
        if (L.R[i] < L.R[i - 1]) {
            L.R[0] = L.R[i];
            L.R[i] = L.R[i - 1];
            int j;
            for (int j = i - 2; L.R[0] < L.R[j]; j--) {
                L.R[j + 1] = L.R[j];
            }
            L.R[j + 1] = L.R[0];
        }
    }
}

//选择排序
void SelectSort(SqList& L) {
    for (int i = 1; i < L.length; i++) {
        int k = i; //每次都把待比较位次k设为i，每次加1
        for (int j = i + 1; j < L.length; j++) {
            if (L.R[j] < L.R[k]) {
                k = j;
            }
        }

        if (k != i) {
            int temp = L.R[i];
            L.R[i] = L.R[k];
            L.R[k] = temp;
        }
    }
}

//快速排序
typedef struct SqList {
    int* R;
    int length;
}SqList;

int Partition(SqList& L, int low, int high) {
    //实现快速排序的划分算法
    // 第一趟排序
    //0索引处防止第一个元素，也就是快速排序枢轴
    L.R[0] = L.R[low];
    while (low < highh) {
        while (low < high && L.R[high] >= L.R[0]) {
            high--;
        }
        L.R[low] = L.R[high];

        while (low < high && L.R[low] <= L.R[0]) {
            low++;
        }
        L.R[high] = L.R[low];
    }
    L.R[low] = L.R[0];
    return low;
}

//第一趟之后的排序
void QSort(SqList& L, int low, int high) {
    if (low < high) {
        int pivotloc = Partition(L, low, high);
        QSort(L, low, pivotloc - 1);
        QSort(L, pivotloc + 1, high);
    }
}

//第k小的数
//在无序顺序表中查找第k小的元素，返回第k小元素的值，参考快速排序过程
int kth_elem(SqList& L, int k) {
    if (k<1 || k>L.length) {
        return -1;
    }

    int left = 1;
    int right = L.length;
    while (left < right) {
        int pivot = L.R[left];
        int i = left;
        int j = right;
        while (i < j) {
            while (i < j && L.R[j] >= pivot) {
                j--;
            }
            L.R[i] == L.R[j];

            while (i < j && L.R[i] <= pivot) {
                i++;
            }
            L.R[j] = L.R[i];
        }
        L.R[i] = pivot;
        if (i == k) {
            return L.R[i];
        }
        else if (i < k) {
            left = i + 1;
        }
        else {
            right = i - 1;
        }
    }

    return -1;

}

//用一位数组模拟栈
typedef struct {
    int* stack;
    int top[2];
}DualStack;

void push(DualStack& S, int i, int x) {
    //i表示要入的栈，两个入口，取值为0和1
    if (i == 0) {
        //判断是否栈满
        if (S.top[0] + 1 = S.top[1]) {
            return;
        }
        S.satck[S.top[0]++] = x;
    }
    else if (i == 1) {
        if (S.top[1] - 1 = S.top[0]) {
            return;
        }
        S.stack[--S.top[1]]] = x;
    }
    else {
        return;
    }
}

void pop(DualStack& S, int i, int x) {
    if
}