#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int processInput(char input[]) {
	int val = atoi(input);

	if (val == 0) {
		puts("Your input is not valid! Please try again.");
	} else if (strlen(input) > 5) {
		puts("Your input is too large! Please try again.");
	} else {
		printf("Your input of %i has been added.\n", val);
		return val;
	}
	return 0;
}

void addIntegers(int integers[]) {
	int sum = 0;
	for (int i = 0; i < 10; ++i) {
		sum += integers[i];
	}
	printf("The final sum of all the integers is %i\n.", sum);
}

void run() {
	char input[5];
	int integers[10];
	int count = 0;

	while (input[0] != EOF) {
		if (count < 10) {
			puts("Enter up to 10 integers to add (up to 5 digits each): ");
			scanf("%10s", input);

			int result = processInput(input);

			if (result != 0) {
				integers[count] = result;
				count++;
			}
		} else {
			puts("Looks like you've entered 10 integers already. Let's add them up!");
			break;
		}
	}
	addIntegers(integers);
}

int main() {
	run();
	return 0;
}