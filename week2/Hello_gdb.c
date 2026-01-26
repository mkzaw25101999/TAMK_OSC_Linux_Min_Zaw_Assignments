#include <stdio.h>

int main(int argc, char* argv[]){
	int age = 26;
	int year = 2026;
	int future_age;

	printf("Hello %s!\n", argv[1]);

	future_age = age + 5;
	
	if(age > 20){
		printf("Age %d is an adult age.\n", age);
	} else {
		printf("Age %d is a teenage age.\n", age);
	}

	printf("Counting: ");
	for(int i = 1; i <= 3; i++){
		printf("%d ", i);
	}
	printf("\n");

	printf("In 5 years, Your age will be %d years old.\n", future_age);
	
	return 0;
}
