#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void TestSList()
{
	SListNode* plist = NULL;
	
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPushFront(&plist, 5);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 1);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);


	SListNode* pos = SListFind(plist, 4);
	if (pos == NULL)
	{
		printf("ц╩спур╣╫");
	}
	else
	{
		SListInsert(&plist, pos, 10);
		SListPrint(plist);
		SListInsertAfter(&plist, pos, 20);
		SListPrint(plist);
		SListEraseAfter(&plist, pos);
		SListPrint(plist);
		SListErase(&plist, pos);
		SListPrint(plist);

	}

}
int main()
{
	TestSList();
	return 0;
}