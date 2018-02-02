/* rbwordcount-test.c -- simple test for rbwordcount.c
 *
 * This is NOT a complete test, and this is NOT the program used
 * to grade this task. Nevertheless, it is CRITICAL that you pass
 * this test.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../cutest-1.5/CuTest.h"

#define min(x, y) ((x) < (y) ? (x) : (y))

/* Tests:
   test with three words on one line
 */

/* =========== Utility Functions for Testing ============ */
static FILE *save_stdout = NULL;

char *run_solution_main(CuTest *tc, char *content, int output_len)
{
    int r = link("words.txt", "words-save-for-testing.txt");
    if (r < 0) {
        perror("WARNING - link() failed trying to create "
               "words-save-for-testing.txt linked to words.txt");
    }
    unlink("words.txt"); /* delete so fopen will make a new file, ... */
    /* (ignore any error since we don't require words.txt to exist) */
    FILE *words = fopen("words.txt", "w");
    if (!words) {
        perror("ERROR - fopen() failed to open words.txt, cannot continue");
        CuFail(tc, "Cannot initialize words.txt");
        return NULL;
    }
    fprintf(words, "%s", content); /* without 2nd arg, we get a warning */
    if (fclose(words) != 0)
        perror("WARNING - fclose() reported an error");
    /* redirect stdout to a file to capture user's output */
    char *output_name = tempnam(".", "rbwordcount-output");
    FILE *output = fopen(output_name, "w");
    if (!output) {
        fprintf(stdout, "tempnam() gives %s as output_name\n", output_name);
        perror("ERROR - fopen() failed to open temp file");
        CuFail(tc, "Cannot open temp file to capture stdout");
        free(output_name);
        return NULL;
    }
    FILE *save_stdout = stdout;
    stdout = output;
    /* now we can run the user's program */
    solution_main();
    /* examine the output: should be "and 1\ndays 2\n" */
    fclose(stdout); /* closes output */
    /* restore stdout */
    stdout = save_stdout;
    /* reopen output file to see what was written */
    output = fopen(output_name, "r");
    char *output_text = (char *) malloc(output_len);
    int len = fread(output_text, 1, output_len, output);
    output_text[min(len, output_len - 1)] = 0; /* EOS */
    /* delete the output file */
    r = unlink(output_name);
    if (r < 0) {
        perror("WARNING - unlink() failed trying to remove output file");
    }        
    /* intentionally leave output_name on heap because it was allocated
     * with real malloc whereas free() is defined in ../malloc/malloc.c
     * and is not compatible
     * free(output_name);
     */
    if (len >= output_len) {
        printf("GOT: %s\nEXPECTED less than %d chars.\n", output_text, output_len);
        CuFail(tc, "Too much output");
        free(output_text);
        return NULL;
    }
    /* move original file back to words.txt */
    r = unlink("words.txt");
    if (r < 0) {
        perror("WARNING - unlink() failed trying to remove words.txt");
    }

    r = link("words-save-for-testing.txt", "words.txt");
    if (r < 0) {
        perror("WARNING - link() failed to create words.txt link");
    }
    
    r = unlink("words-save-for-testing.txt");
    if (r < 0) {
        perror("WARNING - unlink() failed removing (deleting) words-save-for-testing.txt");
    }

    return output_text;
}


/* remove all space except newlines from output */
void strip_blanks(char *s)
{
    int j = 0;
    int i = 0;
    for (i = 0; s[i] != 0; i++) {
        if (!isspace(s[i]) || s[i] == '\n') {
            s[j++] = s[i];
        }
    }
    s[j] = 0;
}


/* ========== test compare ============= */
void test_compare(CuTest *tc)
{
    printf("    test_compare\n");
    CuAssertIntEquals_Msg(tc, "a < b failed", -1, compare("a", "b"));
    CuAssertIntEquals_Msg(tc, "b > a failed",  1, compare("b", "a"));
    CuAssertIntEquals_Msg(tc, "a == a failed", 0, compare("a", "a"));
    CuAssertIntEquals_Msg(tc, "test > smaller failed", 1, compare("test", "smaller"));
    CuAssertIntEquals_Msg(tc, "aardvark < ant failed", -1, compare("aardvark", "and"));
    CuAssertIntEquals_Msg(tc, "Pittsburgh == Pittsburgh failed", 0, 
                          compare("Pittsburgh", "Pittsburgh"));
}


/* ========== test with three words on one line ========== */
void test_three_words_one_line(CuTest *tc)
{
    char *input_text = "days and days\n";
    char *expected = "and 1\ndays 2\n";
    char *expected2 = "and1\ndays2\n";
    char *output_text = run_solution_main(tc, input_text, 100);

    printf("    test_three_words_one_line\n");

    if (!output_text) return;
    strip_blanks(output_text);
    CuAssertStrEquals_Msg(tc, "Expected output not found",
                          expected2, output_text);
    free(output_text);
    return;
}


CuSuite *rbwordcount_get_suite()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_compare);
    SUITE_ADD_TEST(suite, test_three_words_one_line);
    return suite;
}

int main(int argc, char *argv[])
{
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();
    CuSuiteAddSuite(suite, rbwordcount_get_suite());
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
    return 0;
}


