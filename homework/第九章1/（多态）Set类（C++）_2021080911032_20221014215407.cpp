#include<iostream>
#include"CSet.h"

bool Set::operator <=(const Set& s)const
{
	bool is_in = false;
	int i = 1, j;
	for (i = 1; i <= n; i++)
	{
		is_in = false;
		for (j = 1; j <= s.n; j++)
			if (s.pS[j] == pS[i])
			{
				is_in = true; break;
			}
		if (!is_in) return false;
	}
	return true;
}


bool Set::operator ==(const Set& s)const
{
	bool outcome = false;
	if (s.n != n) return outcome;
	outcome = ((*this) <= s);
	return outcome;

}

Set& Set::operator +=(int e)
{
	int i; bool is_in = false;
	for (i = 1; i <= n; i++)
	{
		if (e == pS[i])
		{
			is_in = true; break;
		}
	}
	if (!is_in)
	{
		int* temp = pS;
		n++;
		pS = new int[n + 1];
		for (i = 1; i < n; i++)
			pS[i] = temp[i];
		pS[n] = e;
	}
	return *this;

}

Set& Set::operator -=(int e)
{
	int i, pos = 0;
	for (i = 1; i <= n; i++)
	{
		if (pS[i] == e)
		{
			pos = i; break;
		}
	}
	if (pos == 0) return *this;

	for (i = pos; i < n; i++)
		pS[i] = pS[i + 1];
	n--;
	return *this;

}

Set Set::operator |(const Set& s)const
{
	int cnt = 0;
	int* temp = new int[this->n + s.n + 1];
	for (int i = 1; i <= n; i++)
		temp[++cnt] = pS[i];
	int i, j; bool is_in = false;
	for (i = 1; i <= s.n; i++)
	{
		is_in = false;
		for (j = 1; j <= n; j++)
			if (s.pS[i] == pS[j])
			{
				is_in = true; break;
			}
		if (!is_in) temp[++cnt] = s.pS[i];
	}
	Set uni;
	uni.n = cnt;
	uni.pS = temp;
	return uni;

}
Set Set::operator &(const Set& s)const
{
	int* temp = new int[min(n, s.n) + 1];
	int cnt = 0;
	int i, j; bool is_in = false;
	for (i = 1; i <= s.n; i++)
	{
		is_in = false;
		for (j = 1; j <= n; j++)
			if (s.pS[i] == pS[j]) { is_in = true; break; }
		if (is_in) temp[++cnt] = s.pS[i];
	}

	Set	con;
	con.n = cnt;
	con.pS = temp;
	return con;

}

Set Set::operator -(const Set& s)const
{
	int* temp = new int[n + 1];
	int i, j, cnt = 0;
	bool is_in = false;
	for (i = 1; i <= n; i++)
	{
		is_in = false;
		for (j = 1; j <= s.n; j++)
			if (s.pS[j] == pS[i]) { is_in = true; break; }
		if (!is_in) temp[++cnt] = pS[i];

	}
	Set dif;
	dif.n = cnt;
	dif.pS = temp;
	return dif;
}


