#include <stdio.h>
#define MAX_LIMIT 200

int str_len(char s[]) {
	int c = 0;

	while (s[c] != '\0')
	  	c++;

	return c;
}

int main() {
	/* code */

	char str[MAX_LIMIT];

	printf("Enter the string: ");
    fgets(str, MAX_LIMIT, stdin);

	int len = str_len(str)-1;

	int j = 0;
	char res[len];

	for(int i = len-1; i >=  0; i--){
		res[j] = str[i];
		j++;
	}

	res[len] = '\0';

	printf("The reversd string is: %s\n", res);

	return 0;
}
