/*
 * My implementation of tee for exercise 3. Reflection and comparison
 * comments are located at the bottom of the file.
 * 
 * Available argument: -a = append to a file (default: overwrite file)
 * I didn't see any other arguments that I should implement, and I don't
 * think the real code implements any other arguments either. I could be
 * wrong though...
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/*
 * Prints to standard output.
 *
 * string 		Input to be printed
 */
void printToStandardOutput(char* string) {
	printf("Your input has been successfully written to the given file(s):\n");
	printf("%s\n", string);
}

/*
 * Writes given string to given file.
 * 
 * string 		String to be written
 * fileName 	Name of file to be edited
 * mode 		Mode in which string is to be written (w = write, a = append)
 */
void writeToFile(char* string, char* fileName, char* mode) {
	FILE *f = fopen(fileName, mode);
	if (f == NULL) {
		printf("An error occurred while opening the file: %s\n", fileName);
		exit(1);
	}	
	fprintf(f, "%s", string);
	fclose(f);
	printToStandardOutput(string);
}

/*
 * Retrieves user input.
 *
 * str 			Pointer to char where input will be stored
 */
void getInput(char* str) {
	printf("Enter the input that you would like written to the given files: ");
	fgets(str, sizeof(str), stdin);
}

int main(int argc, char *argv[]) {
	char ch;
	int i;
	int append = 0;

	while ((ch = getopt(argc, argv, "a")) != EOF) {
		switch (ch) {
			case 'a':
				append = 1;
				break;
			default:
				puts("Invalid option detected. Proceeding anyway...");
				break;
		}
	}

	argc -= optind;
	argv += optind;

	char str[100];
	getInput(str);

	for (i = 0; i < argc; i++) {
		append ? writeToFile(str, argv[i], "a") : writeToFile(str, argv[i], "w");
	}

	return 0;
}

/*
 * Reflection *******************************************************************
 * At first, I was really not sure how to do this exercise. I don't know anything
 * about tee, and I still don't think I implemented it the way I was supposed to.
 * This lack of understanding slowed me down, in addition to just not knowing how
 * to start. However, as soon as I started trying to think of this exercise as a
 * series of smaller problems (1. Reading standard input, 2. Allowing for args,
 * 3. Writing to files, etc.), it felt like it got a lot easier. When I realized
 * I could just look up most of these things, I was on a roll and finished my
 * implementation of tee in about an hour.
 * 
 * Next time I'm given some task in C that I don't even know how to begin, I think
 * I'll remember my experience with this exercise and just focus on breaking the
 * task into smaller tasks.
 * 
 * Comparison *******************************************************************
 * Well, looking at the real thing, I've realized that I wasn't too far off which
 * is really encouraging. The real thing and my code have some similarities, like
 * using a ternary operator to retrieve the file mode (file_mode = (append_mode ?
 *  "a" : "w");), but it splits up the smaller parts of tee differently. In fact,
 *  it doesn't really separate any parts except the parsing of the arguments.
 *  
 *  I think my code and the real code do mostly the same things though! I was so
 *  confused about how tee was supposed to work, but I'm relieved to see that I
 *  didn't completely miss the mark.
 */




