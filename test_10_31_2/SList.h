#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//����ѭ������ͷ����
typedef int SListDataType;
typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SListDataType x);
// �������ӡ
void SListPrint(SListNode* plist);
// ������β��
void SListPushBack(SListNode** pplist, SListDataType x);
// �������ͷ��
void SListPushFront(SListNode** pplist, SListDataType x);
// �������βɾ
void SListPopBack(SListNode** pplist);
// ������ͷɾ
void SListPopFront(SListNode** pplist);
// ���������
SListNode* SListFind(SListNode* plist, SListDataType x);
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode** pplist, SListNode* pos, SListDataType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode** pphead,SListNode* pos);
// �����������
void SListDestroy(SListNode** pplist);
//ɾ����ǰλ��
void SListErase(SListNode** pplist, SListNode* pos);
//֮ǰ����
void SListInsert(SListNode** pplist, SListNode* pos, SListDataType x);
