#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char s[100];
	int i=0,j=0;
	while ((s[i]=getchar())!='\n') i++;
	s[i]='\0';
	for (i=0,j=0;s[i]!='\0';i++)
		if (s[i]>='0' && s[i]<='9'){
			s[j]=s[i];
			j++;
		}
	s[j]='\0';
		printf("%s", s);
	return 0;
}
