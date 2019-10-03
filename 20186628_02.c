/*
wirtten at 2019 09 27 ~
discrete mathematics assignment02 
written by Seon-ho Im
id number : 20186628
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//symbol(+ or -) and integer(0, 1, 2, ...) pair
//command line argument는 0번째가 exe이름 ... 인듯
//command line의 argument 홀수는 symbol 짝수는 integer 그렇지 않은 경우 메세지 출력하자
//The maximum number of (symbol, number) pairs is 100 이므로 argc <= 201


enum bool{
	false, true
}calculated;

enum bool isint(char * input) {
	for (int i = 0; input[i]; i++) {
		if (input[i] < '0' || input[i] > '9')
			return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	int result = 0;
	calculated = true;

	//printf("argc is %d.\n", argc);
	
	if (argc > 201) {
		printf("You put too many arguments.\n");
		printf("Please put no more than 100 pairs of symbol and number.\n");
		
	}
	else {
		for (int i = 1; i <= (argc - 1) / 2; i++) { //pair 수 만큼 반복
			if (strcmp(argv[2 * i - 1], "+") == 0) {
				if (isint(argv[2 * i]) == false) { //문자열이 정수로만 이루어졌는지 아닌지 체크
					printf("input is out of range.\n");
					calculated = false;
				}
				else {
					result = result + atoi(argv[2 * i]);
				}
			}
			else if (strcmp(argv[2 * i - 1], "-") == 0) {
				if (isint(argv[2 * i]) == false) {  //문자열이 정수로만 이루어졌는지 아닌지 체크
					printf("input is out of range.\n");
					calculated = false;
				}
				else {
					result = result - atoi(argv[2 * i]);
				}
			}
			else {
				printf("Please use only + or - symbol and also Please pay attention to spacing.\n");	//홀수 argument가 +도 -도 아닐때 출력
				
				calculated = false;
			}

		}
		if (calculated == true) {
			printf("result is %d.\n", result);
			printf("/(*ㅁ*)/ Hello. This is written by Seon-ho Im.  /(@ㅁ@)? \n\n");
		}
		else {
			printf("Sorry, You put wrong argument. \n");
			printf("Arguments should be like, assignment02.exe + 11 - 3 + 5\n");
		}
	}

	
	return 0;
}