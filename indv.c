#include <stdio.h>
#define MAX 100
int main()
{
	char str[MAX];
	printf("aaaabbccccddddd"); // In printf it can be "Enter the text" so that the user can input text
	gets(str);
	char current = str[0];
       	int count = 1;
	for(int i=1; str[i]!='\0' ; i++)
	{
		if(str[i]== current)
			count++;
		else
		{
			printf("%c%d", current, count);
			current=str[i];
			count=1;
		}
	}
	printf("%c%d" , current, count);
	return 0;

}
