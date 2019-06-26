#include <stdio.h>

int main(){

	int number, divide, exp = 0; //declare variables

	printf("Please enter a number to see its prime factorization\n");
	scanf("%d", &number);
	printf("Prime factorization starts...\n");
	
	int tempnumber = number;

	if(number == 1 || number == 0){ //return value directl for small numbers
		printf("%d\n", number);
		return 0;
	}

	while(number % 2 == 0){ //find the even part of the number
		number /= 2;
		exp++;
	}

	if(exp > 0){
		if(number > 1)
			printf("2^%d * ", exp);
		else
			printf("2^%d", exp);
		exp = 0;
	}

	for(divide = 3; divide <= tempnumber; divide = divide+2){ //now we can increment by two since the number is odd now

		if(number % divide == 0){
			while(number % divide == 0){
				number /= divide;
				exp++;
			}
			if(number>1)
				printf("%d^%d * ",divide, exp);	
			else
				printf("%d^%d",divide, exp);
		}
	}
	printf("\n");
	return 0;
}