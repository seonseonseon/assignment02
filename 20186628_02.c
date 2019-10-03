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
//command line argument�� 0��°�� exe�̸� ... �ε�
//command line�� argument Ȧ���� symbol ¦���� integer �׷��� ���� ��� �޼��� �������
//The maximum number of (symbol, number) pairs is 100 �̹Ƿ� argc <= 201


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
		for (int i = 1; i <= (argc - 1) / 2; i++) { //pair �� ��ŭ �ݺ�
			if (strcmp(argv[2 * i - 1], "+") == 0) {
				if (isint(argv[2 * i]) == false) { //���ڿ��� �����θ� �̷�������� �ƴ��� üũ
					printf("input is out of range.\n");
					calculated = false;
				}
				else {
					result = result + atoi(argv[2 * i]);
				}
			}
			else if (strcmp(argv[2 * i - 1], "-") == 0) {
				if (isint(argv[2 * i]) == false) {  //���ڿ��� �����θ� �̷�������� �ƴ��� üũ
					printf("input is out of range.\n");
					calculated = false;
				}
				else {
					result = result - atoi(argv[2 * i]);
				}
			}
			else {
				printf("Please use only + or - symbol and also Please pay attention to spacing.\n");	//Ȧ�� argument�� +�� -�� �ƴҶ� ���
				
				calculated = false;
			}

		}
		if (calculated == true) {
			printf("result is %d.\n", result);
			printf("/(*��*)/ Hello. This is written by Seon-ho Im.  /(@��@)? \n\n");
		}
		else {
			printf("Sorry, You put wrong argument. \n");
			printf("Arguments should be like, assignment02.exe + 11 - 3 + 5\n");
		}
	}

	
	return 0;
}