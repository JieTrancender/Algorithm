#pragma once

#include <cstdio>

void Permutation(char *pStr, char *pBegin);

void Permutation(char* pStr)
{
	if (pStr == nullptr)
	{
		return;
	}

	Permutation(pStr, pStr);
}

void Permutation(char *pStr, char *pBegin)
{
	if (*pBegin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		for (char *ptr = pBegin; *ptr != '\0'; ++ptr)
		{
			char temp = *ptr;
			*ptr = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin + 1);

 		temp = *ptr;
			*ptr = *pBegin;
			*pBegin = temp;
		}
	}
}