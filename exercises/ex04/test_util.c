#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "./trout/util.c"
#include "minunit.h"

int tests_run = 0;

static char * test1() {
	char *result = icmpcode_v4(0);
	char *message = "test failed: code 0";
	mu_assert(message, strcmp(result, "network unreachable") == 0);
	return NULL;
}

static char * test2() {
	char *result = icmpcode_v4(1);
	char *message = "test failed: code 1";
	mu_assert(message, strcmp(result, "host unreachable") == 0);
	return NULL;
}

static char * test3() {
	char *result = icmpcode_v4(2);
	char *message = "test failed: code 2";
	mu_assert(message, strcmp(result, "protocol unreachable") == 0);
	return NULL;
}

static char * test4() {
	char *result = icmpcode_v4(20);
	char *message = "test failed: code default";
	mu_assert(message, strcmp(result, "[unknown code]") == 0);
	return NULL;
}

static char * all_tests() {
    mu_run_test(test1);
    mu_run_test(test2);
    mu_run_test(test3);
    mu_run_test(test4);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
