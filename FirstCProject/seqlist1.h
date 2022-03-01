#pragma once
#include <stdio.h>
#include <string.h>
//顺序表的最大长度
#define MaxSize 100

//自定义顺序表的元素为int
typedef int ElemType;

//自定义结构体
typedef struct {
	//数组储存
	ElemType data[MaxSize];
	//顺序表里元素个数
	unsigned int length;
}SeqList,*PSeqList;

// 顺序表LL的初始化操作。
void InitList(PSeqList LL);

// 清空顺序表。
void ClearList(PSeqList LL);

//返回顺序表长度
int LengthList(PSeqList LL);

// 顺序表LL的初始化操作。
void InitList(PSeqList LL) {
	ClearList(LL);
};
// 获取顺序表中第ii个元素的值，存放在ee中，返回值：0-失败；1-成功。
int  GetElem(PSeqList LL, unsigned int ii, ElemType* ee);

// 在顺序表LL的第ii个位置插入元素ee，返回值：0-失败；1-成功。
int InsertList(PSeqList LL, unsigned int ii, ElemType* ee);

// 在顺序表LL的头结点插入元素ee，返回值：0-失败；1-成功。
int  PushFront(PSeqList LL, ElemType* ee);

// 在顺序表LL的尾结点插入元素ee，返回值：0-失败；1-成功。
int PushBack(PSeqList LL, ElemType* ee);

// 删除顺序表LL中的第ii个元素，返回值：0-位置ii不合法；1-成功。
int DeleteElem(PSeqList LL, unsigned int ii);

// 查找ee在顺序表LL中的位置，返回值：0-元素ee在表LL中不存在，>0元素ee在表LL中的位置。
int LocateElem(PSeqList LL, ElemType* ee);


// 删除顺序表LL中头元素，返回值：0-位置ii不合法；1-成功。
int PopFront(PSeqList LL);

// 删除顺序表LL中尾元素，返回值：0-位置ii不合法；1-成功。
int PopBack(PSeqList LL);

// 判断顺序表是否为空，返回值：1-空，0-非空或失败。
int IsEmpty(PSeqList LL);

// 打印顺序表中全部的元素。
void PrintList(PSeqList LL);


// 打印顺序表中全部的元素。
void PrintList(PSeqList LL) {
	if (LL == NULL) return;   // 检查空指针。

	if (LL->length == 0) { printf("表为空。\n"); return; }

	int kk;
	for (kk = 0; kk < LL->length; kk++)
	{
		printf("%-3d", LL->data[kk]);  // 用数组的形式也可以。
	}

	printf("\n");
};


// 判断顺序表是否为空，返回值：1-空，0-非空或失败。
int IsEmpty(PSeqList LL) {
	if (LL == NULL) return 0;   // 检查空指针。

	if (LL->length == 0) return 1;

	return 0;
};

// 删除顺序表LL中尾元素，返回值：0-位置ii不合法；1-成功。
int PopBack(PSeqList LL) {
	return DeleteElem(LL, LL->length);
};

// 删除顺序表LL中头元素，返回值：0-位置ii不合法；1-成功。
int PopFront(PSeqList LL) {
	return DeleteElem(LL, 1);
}

// 删除顺序表LL中的第ii个元素，返回值：0-位置ii不合法；1-成功。
int DeleteElem(PSeqList LL, unsigned int ii) {
	// 检查空指针
	if ((LL == NULL)) return 0;  
	// 判断删除位置ii是否合法
	if ((ii < 1) || (ii > LL->length))
	{
		printf("删除位置（%d）不合法，应该在（%d-%d）之间\n", ii, 1, LL->length);
		return 0;
	}
	// 把ii之后的元素前移。
	int k;
	for (k = ii; k<=LL->length; k++) {
		memcpy(&LL->data[k-1], &LL->data[k], sizeof(ElemType));
	}
	LL->length--;
	return 1;
};
// 查找ee在顺序表LL中的位置，返回值：0-元素ee在表LL中不存在，>0元素ee在表LL中的位置。
int LocateElem(PSeqList LL, ElemType* ee) {
	// 检查空指针。
	if ((LL == NULL) || (ee == NULL)) return 0;   

	int kk;
	for (kk = 0; kk < LL->length;kk++) {
		if (LL->data[kk] == *ee) {
			return kk + 1;
		}
	}
	return 0;
}


// 在顺序表LL的尾结点插入元素ee，返回值：0-失败；1-成功。
int PushBack(PSeqList LL, ElemType* ee) {
	return InsertList(LL, LL->length + 1, ee);
};

// 在顺序表LL的头结点插入元素ee，返回值：0-失败；1-成功。
int  PushFront(PSeqList LL, ElemType* ee) {
	return InsertList(LL, 1, ee);
};

// 在顺序表LL的第ii个位置插入元素ee，返回值：0-失败；1-成功。
int InsertList(PSeqList LL, unsigned int ii, ElemType* ee) {
	// 检查空指针
	if ((LL == NULL) || (ee == NULL)) return 0;  
	if (LL->length >= MaxSize)
	{
		printf("顺序表已满，不能插入。\n"); 
		return 0;
	}
	// 判断插入位置是否合法
	if ((ii < 1) || (ii > LL->length + 1))
	{
		printf("插入位置（%d）不合法，应该在（%d-%d）之间。\n", ii, 1, LL->length + 1); 
		return 0;
	}
	// 把ii和ii之后的元素后移。
	int kk;
	for (kk = LL->length; kk >= ii; kk--) {
		memcpy(&LL->data[kk], &LL->data[kk - 1], sizeof(ElemType));
	};
	memcpy(&LL->data[ii-1],ee,sizeof(ElemType));
	//长度+1
	LL->length++;
	return 1;
};



// 获取顺序表中第ii个元素的值，存放在ee中，返回值：0-失败；1-成功。
int  GetElem(PSeqList LL, unsigned int ii, ElemType* ee) {
	if ((LL == NULL) || (ee == NULL)) {
		return 0;
	};
	// 判断位置ii是否合法
	if ((ii < 0) || ii > LL->length) {
		return 0;
	};
	memcpy(ee, &LL->data[ii - 1], sizeof(ElemType));
	return 1;
};

// 清空顺序表。
void ClearList(PSeqList LL) {

	//检查空指针
	if (LL == NULL) {
		return;
	}
	//设置一开始的长度为0
	LL->length = 0;
	//memset方法 将数组里所有的元素换成0；
	memset(LL->data, 0, sizeof(ElemType) * MaxSize);

};

//返回顺序表长度
int LengthList(PSeqList LL) {
	// 检查空指针。
	if (LL == NULL) {
		return 0;
	}
	return LL->length;
};
