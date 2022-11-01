#define _CRT_SECURE_NO_WARNINGS 1

//÷±Ω”≤Â»Î≈≈–Ú
#include<stdio.h>

void InsterSort(int* arr, int sz)
{
	
	int i = 0;
	while (i<sz-1)
	{
		int end = i;
		int tmp = *(arr + end + 1);
		while (end >= 0)
		{
			if (*(arr + end) > tmp)
			{
				*(arr + end + 1) = *(arr + end);
				end--;
			}
			else
			{
				break;
			}
		}
		*(arr + end + 1) = tmp;
		i++;
	}
}
void Print(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,10};
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsterSort(arr, sz);
	Print(arr, sz);
	return 0;
}