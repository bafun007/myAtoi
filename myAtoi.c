#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int myAtoi(char* str) {
    int myInt=0;
	int i=0;
	int sign = 1;
	printf("Input is %s\n", str);
	// eliminate white space
	while (str[i]==' ') i++;
	// handle sign
	if(str[i] == '-' || str[i] == '+') {
		if (str[i++] == '-') sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9') {
//		if ((myInt >= INT_MAX/10) && str[i]-'0' > 7) {
		if (myInt >  INT_MAX / 10 || (myInt == INT_MAX / 10 && str[i]-'0' > INT_MAX%10)) {
			if(sign > 0)
				return INT_MAX;
			else
				return INT_MIN;
		}
		myInt = myInt*10 + str[i++]-'0';
	}
//	printf ("myAtoi is %d\n", myInt * sign);
	return myInt * sign;
}

void main (void)
{
	printf("INT_MAX is %d\nINT_MIN is %d\n", INT_MAX, INT_MIN);
	printf("myResule is %d\n", myAtoi("2147483648"));

}