#include <stdio.h>
#include<iostream>
using namespace std;
 
 
typedef struct Node{
	int num;
	Node* next;
 
}Node;//设置节点
 
 
 
int *solve(int N, int M, int K) {
 
	Node* L, * p, * r, * q;
	int Left = N;
	static int s[1000];
	int j = 0;
	int temp;//数人头 
	L = new Node;
	L->next = NULL;//初始化
	r = L;//指向尾结点 
	q = L;
	*s = NULL;
	for (int i = 1; i <= N; i++) {
		p = new Node;
		p->num = i;
		p->next = L->next;
		r->next = p;
		r = p;
	}//上船 
	p = L;
		while (Left > K) {
			
			for (temp=1; temp <= M; temp++) {
				q = p;
				p = p->next;
				if (temp == M) {
					s[j] = p->num;
					j++;
					p = p->next;
					q->next = p;
					p = q;
				}
			}
			Left--;
		}
	
	return s;
}