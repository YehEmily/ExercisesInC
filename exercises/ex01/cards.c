#include <stdio.h>
#include <stdlib.h>

void getCardName(char *prompt, char *card_name) {
	puts(prompt);
	scanf("%2s", card_name);
}

int getIncrement(int val) {
	if ((val > 2) && (val < 7)) {
		return 1;
	} else if (val == 10) {
		return -1;
	} else {
		return 0;
	}
}

void printTotal(int total) {
	printf("Current count: %i\n", total);
}

int play() {
	char card_name[3];
	int count = 0;
	do {
		getCardName("Enter the card_name: ", card_name);
		int val = 0;
		switch(card_name[0]) {
			case 'K':
			case 'Q':
			case 'J':
				val = 10;
				break;
			case 'A':
				val = 11;
				break;
			case 'X':
				continue;
			default:
				val = atoi(card_name);
				if ((val < 1) || (val > 10)) {
					puts("I don't understand that value!");
					continue;
				}
		}
		printTotal(count + getIncrement(val));
	} while (card_name[0] != 'X');
	return 0;
}

int main() {
	return play();
}