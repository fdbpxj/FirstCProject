#pragma once
#include <stdio.h>
#include <string.h>
//˳������󳤶�
#define MaxSize 100

//�Զ���˳����Ԫ��Ϊint
typedef int ElemType;

//�Զ���ṹ��
typedef struct {
	//���鴢��
	ElemType data[MaxSize];
	//˳�����Ԫ�ظ���
	unsigned int length;
}SeqList,*PSeqList;

// ˳���LL�ĳ�ʼ��������
void InitList(PSeqList LL);

// ���˳���
void ClearList(PSeqList LL);

//����˳�����
int LengthList(PSeqList LL);

// ˳���LL�ĳ�ʼ��������
void InitList(PSeqList LL) {
	ClearList(LL);
};
// ��ȡ˳����е�ii��Ԫ�ص�ֵ�������ee�У�����ֵ��0-ʧ�ܣ�1-�ɹ���
int  GetElem(PSeqList LL, unsigned int ii, ElemType* ee);

// ��˳���LL�ĵ�ii��λ�ò���Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertList(PSeqList LL, unsigned int ii, ElemType* ee);

// ��˳���LL��ͷ������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  PushFront(PSeqList LL, ElemType* ee);

// ��˳���LL��β������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int PushBack(PSeqList LL, ElemType* ee);

// ɾ��˳���LL�еĵ�ii��Ԫ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int DeleteElem(PSeqList LL, unsigned int ii);

// ����ee��˳���LL�е�λ�ã�����ֵ��0-Ԫ��ee�ڱ�LL�в����ڣ�>0Ԫ��ee�ڱ�LL�е�λ�á�
int LocateElem(PSeqList LL, ElemType* ee);


// ɾ��˳���LL��ͷԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int PopFront(PSeqList LL);

// ɾ��˳���LL��βԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int PopBack(PSeqList LL);

// �ж�˳����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int IsEmpty(PSeqList LL);

// ��ӡ˳�����ȫ����Ԫ�ء�
void PrintList(PSeqList LL);


// ��ӡ˳�����ȫ����Ԫ�ء�
void PrintList(PSeqList LL) {
	if (LL == NULL) return;   // ����ָ�롣

	if (LL->length == 0) { printf("��Ϊ�ա�\n"); return; }

	int kk;
	for (kk = 0; kk < LL->length; kk++)
	{
		printf("%-3d", LL->data[kk]);  // ���������ʽҲ���ԡ�
	}

	printf("\n");
};


// �ж�˳����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int IsEmpty(PSeqList LL) {
	if (LL == NULL) return 0;   // ����ָ�롣

	if (LL->length == 0) return 1;

	return 0;
};

// ɾ��˳���LL��βԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int PopBack(PSeqList LL) {
	return DeleteElem(LL, LL->length);
};

// ɾ��˳���LL��ͷԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int PopFront(PSeqList LL) {
	return DeleteElem(LL, 1);
}

// ɾ��˳���LL�еĵ�ii��Ԫ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int DeleteElem(PSeqList LL, unsigned int ii) {
	// ����ָ��
	if ((LL == NULL)) return 0;  
	// �ж�ɾ��λ��ii�Ƿ�Ϸ�
	if ((ii < 1) || (ii > LL->length))
	{
		printf("ɾ��λ�ã�%d�����Ϸ���Ӧ���ڣ�%d-%d��֮��\n", ii, 1, LL->length);
		return 0;
	}
	// ��ii֮���Ԫ��ǰ�ơ�
	int k;
	for (k = ii; k<=LL->length; k++) {
		memcpy(&LL->data[k-1], &LL->data[k], sizeof(ElemType));
	}
	LL->length--;
	return 1;
};
// ����ee��˳���LL�е�λ�ã�����ֵ��0-Ԫ��ee�ڱ�LL�в����ڣ�>0Ԫ��ee�ڱ�LL�е�λ�á�
int LocateElem(PSeqList LL, ElemType* ee) {
	// ����ָ�롣
	if ((LL == NULL) || (ee == NULL)) return 0;   

	int kk;
	for (kk = 0; kk < LL->length;kk++) {
		if (LL->data[kk] == *ee) {
			return kk + 1;
		}
	}
	return 0;
}


// ��˳���LL��β������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int PushBack(PSeqList LL, ElemType* ee) {
	return InsertList(LL, LL->length + 1, ee);
};

// ��˳���LL��ͷ������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  PushFront(PSeqList LL, ElemType* ee) {
	return InsertList(LL, 1, ee);
};

// ��˳���LL�ĵ�ii��λ�ò���Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertList(PSeqList LL, unsigned int ii, ElemType* ee) {
	// ����ָ��
	if ((LL == NULL) || (ee == NULL)) return 0;  
	if (LL->length >= MaxSize)
	{
		printf("˳������������ܲ��롣\n"); 
		return 0;
	}
	// �жϲ���λ���Ƿ�Ϸ�
	if ((ii < 1) || (ii > LL->length + 1))
	{
		printf("����λ�ã�%d�����Ϸ���Ӧ���ڣ�%d-%d��֮�䡣\n", ii, 1, LL->length + 1); 
		return 0;
	}
	// ��ii��ii֮���Ԫ�غ��ơ�
	int kk;
	for (kk = LL->length; kk >= ii; kk--) {
		memcpy(&LL->data[kk], &LL->data[kk - 1], sizeof(ElemType));
	};
	memcpy(&LL->data[ii-1],ee,sizeof(ElemType));
	//����+1
	LL->length++;
	return 1;
};



// ��ȡ˳����е�ii��Ԫ�ص�ֵ�������ee�У�����ֵ��0-ʧ�ܣ�1-�ɹ���
int  GetElem(PSeqList LL, unsigned int ii, ElemType* ee) {
	if ((LL == NULL) || (ee == NULL)) {
		return 0;
	};
	// �ж�λ��ii�Ƿ�Ϸ�
	if ((ii < 0) || ii > LL->length) {
		return 0;
	};
	memcpy(ee, &LL->data[ii - 1], sizeof(ElemType));
	return 1;
};

// ���˳���
void ClearList(PSeqList LL) {

	//����ָ��
	if (LL == NULL) {
		return;
	}
	//����һ��ʼ�ĳ���Ϊ0
	LL->length = 0;
	//memset���� �����������е�Ԫ�ػ���0��
	memset(LL->data, 0, sizeof(ElemType) * MaxSize);

};

//����˳�����
int LengthList(PSeqList LL) {
	// ����ָ�롣
	if (LL == NULL) {
		return 0;
	}
	return LL->length;
};
