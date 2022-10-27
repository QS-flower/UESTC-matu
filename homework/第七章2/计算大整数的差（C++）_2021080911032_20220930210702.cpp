#include <iostream>
#include<cstdio>
#include <cstdlib>
#include<cstring>

using namespace std;
void CharReverselInt(char* source1, char* source2, int* num1, int* num2);
int compare(char* A, char* B);
void My_Poor(int* , int*,int);

int main()
{
	char A[100], B[100];
	scanf("%s %s", A, B);
	int len1 = strlen(A), len2 = strlen(B);
	int len = len1 > len2 ? len1 : len2;
	int *num1 = new int[len],*num2 = new int[len];
	CharReverselInt(A, B, num1, num2);


    int sign_tf = compare(A, B);
	if (sign_tf == 0)
		cout << 0;
	else if (sign_tf > 0)
	{
		cout << "+";
		My_Poor(num1, num2,len);
	}
	else if (sign_tf < 0)
	{
		cout << "-";
		My_Poor(num2, num1,len);
	}

	
}

void CharReverselInt(char* source1,char *source2, int* num1,int *num2)
{
	int len1 = strlen(source1), len2 = strlen(source2);
	int len = len1 > len2 ? len1 : len2;

	for (int i = 0; i < len; i++)
	{
		num1[i] = i < len1 ? source1[len1 - i - 1] - '0' : 0;
	}
	for (int j = 0; j < len; j++)
	{
		num2[j] = j < len2 ? source2[len2 - j - 1] - '0' : 0;
	}

}

int compare(char* A, char* B)
{
	int len1 = strlen(A), len2 = strlen(B);
	
	if (len1 > len2)
		return 1;
	if (len1 < len2)
		return -1;
	if (strcmp(A, B) == 0)
		return 0;
	else
	{
		for (int i = 0; i < len1; i++)
		{
			if (A[i] == B[i])
				continue;
			if (A[i] > B[i])
				return 1;
			if (A[i] < B[i])
				return -1;
		}
	}
}


void My_Poor(int* num1, int* num2,int len)
{	
	int* result = new int[len];
	int flag = 0;//½èÎ»
	for (int i = 0; i < len; i++)
	{
		result[len - 1 - i] = (num1[i] - num2[i] - flag + 10 ) % 10;
		flag = (num1[i] - num2[i] - flag>=0)?0:1;
	}
	for (int i = 0; i < len; i++)
		cout << result[i];
}


