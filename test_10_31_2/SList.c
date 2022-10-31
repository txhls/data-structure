#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

// ��̬����һ���ڵ�
SListNode* BuySListNode(SListDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("BuySListNode::malloc:");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
// �������ӡ
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;

	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
// ������β��
void SListPushBack(SListNode** pplist, SListDataType x)
{
	assert(pplist);

	SListNode* newnode = BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* cur = *pplist;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}
// �������ͷ��
void SListPushFront(SListNode** pplist, SListDataType x)
{
	assert(pplist);

	SListNode* newnode = BuySListNode(x);
	SListNode* front = *pplist;

	*pplist = newnode;
	newnode->next = front;
}
// �������βɾ
void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);

	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* cur = *pplist;
		SListNode* prev = NULL;

		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = NULL;
		free(cur);
	}
}
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);

	SListNode* front = *pplist;
	*pplist = front->next;
	free(front);
}
// ���������
SListNode* SListFind(SListNode* plist, SListDataType x)
{
	assert(plist);

	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode** pplist,SListNode* pos, SListDataType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);

	SListNode* cur = *pplist;
	while (cur != pos)
	{
		cur = cur->next;
	}
	newnode->next = cur->next;
	cur->next = newnode;
}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode** pplist, SListNode* pos)
{
	assert(pplist);

	SListNode* cur = *pplist;

	while (cur != pos)
	{
		cur = cur->next;
	}
	SListNode* p = cur->next;
	cur->next = cur->next->next;
	free(p);
}
// �����������
void SListDestroy(SListNode** pplist)
{
	SListNode* cur = *pplist;
	while (cur)
	{
		SListNode* prev = cur;
		cur = cur->next;
		free(prev);
	}
	*pplist = NULL;
}

//֮ǰ����
void SListInsert(SListNode** pplist, SListNode* pos, SListDataType x)
{
	assert(pplist);

	SListNode* newnode = BuySListNode(x);
	if (*pplist == pos)
	{
		SListNode* front = *pplist;
		*pplist = newnode;
		newnode->next = front;
	}
	else
	{
		SListNode* cur = *pplist;
		SListNode* prev = NULL;

		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = newnode;
		newnode->next = cur;
	}
	
}
//ɾ����ǰλ��
void SListErase(SListNode** pplist, SListNode* pos)
{
	assert(pplist);
	
	if (*pplist == pos)
	{
		SListNode* front = *pplist;
		*pplist = front->next;
		free(front);
	}
	else
	{
		SListNode* cur = *pplist;
		SListNode* prev = NULL;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		free(cur);
	}
}