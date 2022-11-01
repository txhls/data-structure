#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void ShellSort(int* arr, int sz)
{
	int gap = sz;
	while (gap>1)
	{
		gap = gap / 3 + 1;
		int i = 0;
		while(i<sz-gap)
		{
			int end = i;
			int tmp = *(arr + end + gap);
			while (end >= 0)
			{
				if (*(arr + end) > tmp)
				{
					*(arr + end + gap) = *(arr + end);
					end -= gap;
				}
				else
				{
					break;
				}
			}
			*(arr + end + gap) = tmp;
			i++;
		}
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
	int arr[] = { 9,8,7,6,5,4,3,2,1,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, sz);
	Print(arr, sz);

	return 0;
}