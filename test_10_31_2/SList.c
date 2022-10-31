#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

// 动态申请一个节点
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
// 单链表打印
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
// 单链表尾插
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
// 单链表的头插
void SListPushFront(SListNode** pplist, SListDataType x)
{
	assert(pplist);

	SListNode* newnode = BuySListNode(x);
	SListNode* front = *pplist;

	*pplist = newnode;
	newnode->next = front;
}
// 单链表的尾删
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
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);

	SListNode* front = *pplist;
	*pplist = front->next;
	free(front);
}
// 单链表查找
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
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
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
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
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
// 单链表的销毁
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

//之前插入
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
//删除当前位置
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