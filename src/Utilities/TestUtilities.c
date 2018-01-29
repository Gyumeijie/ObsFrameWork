//
//
// TestUtilities.cpp
//

#include <stdio.h>
#include <time.h>
#include "../GeneralInclude/TestCompilerSwitches.h"
#include "../GeneralInclude/TestConstants.h"
#include "../Utilities/TestUtilities.h"

#undef MS_HOST

void printRegressionTestHeader(FILE* outFile) {

#ifdef MS_HOST
     time_t ltime;
     time( &ltime );
     fprintf(outFile, "<html><head>\n");
     fprintf(outFile, "<title>OBS Framework - Regression Test Report</title>\n");
     fprintf(outFile, "</head><body  bgcolor=\"#FFFF99\" link=\"#3333FF\">\n");
     fprintf(outFile, "<center><h1>Regression Test Report</h1></center>\n");
     fprintf(outFile, "<center><h4><i>Test Run Performed on %s</i></h4></center>\n",ctime( &ltime ));
     fprintf(outFile, "This report was automatically generated by the regression test program of\n");
     fprintf(outFile, "the OBS Framework. The regression test program executes all the test cases\n");
     fprintf(outFile, "defined for the OBS Framework. The test cases are executed in sequence.\n");
     fprintf(outFile, "Each test cases tests some or all the functionalities of one \n");
     fprintf(outFile, "framework component. The tests are performed at component-level only.\n");
     fprintf(outFile, "A test case can have two possible outcomes: 'test succeeded' or 'test failed'.\n");
     fprintf(outFile, "The test case outcome can be accompanied by an explanatory message.\n");
     fprintf(outFile, "The table below reports the outcome of the test case performed in a \n");
     fprintf(outFile, "regression test run. The links in the table point to the files documenting the individual test cases. \n");
     fprintf(outFile, "The links are active only if this file\n");
     fprintf(outFile, "is placed in the directory containing the HTML architectural documentation of \n");
     fprintf(outFile, "the OBS Framework.\n");
     fprintf(outFile, "There should be one documentation file for each test case. The links assume its \n");
     fprintf(outFile, "name to be: 'TEST_FILE_NAME_1'+'test name'+'TEST_FILE_NAME_2'+'.html' where \n");
     fprintf(outFile, "'TEST_FILE_NAME_1' and 'TEST_FILE_NAME_2' are string constants defined in\n");
     fprintf(outFile, "the 'TestConstants.h' include file.\n");
     fprintf(outFile, "<p>\n");
     fprintf(outFile, "<p>\n");
     fprintf(outFile, "<table BORDER=1 ALIGN=\"center\" CELLPADDING=5%%>\n");
     fprintf(outFile, "<tr><th>Test Name</th>\n");
     fprintf(outFile, "<th>Test Outcome</th></tr>\n");
#else
	printf("Regression Test Report\n");
#endif
}

void printRegressionTestTail(FILE* outFile) {
#ifdef MS_HOST
     fprintf(outFile, "</table></body></html>\n");
#endif
}

void printTestSuccess(FILE* outFile, char* testName, char* testMsg) {
#ifdef MS_HOST
	fprintf(outFile, 
            "<tr><td><a href=\"%s%s%s.html\">%s</a></td>\n",
            TEST_FILE_NAME_1,
            doubleUnderscore(outFile, testName),
            TEST_FILE_NAME_2,testName);
	fprintf(outFile,"<td>%s</td></tr>\n", testMsg);
#else
	printf("Test %s executed successfully. %s\n", testName, testMsg);
#endif
}

void printTestFailed(FILE* outFile, char* testName, char* testMsg) {
#ifdef MS_HOST
	fprintf(outFile,
            "<tr><td><a href=\"%s%s%s.html\">%s</a></td>\n",
            TEST_FILE_NAME_1,
            doubleUnderscore(outFile,testName),
            TEST_FILE_NAME_2,
            testName);
	fprintf(outFile, "<td><b>%s</b></td></tr>\n", testMsg);
#else
	printf("Test %s failed. %s\n", testName, testMsg);
#endif
}

void printErrorMsg(FILE* outFile, char* testName, char* testMsg) {
#ifdef MS_HOST
	fprintf(outFile, "<tr><td>%s</td>\n", testName);
	fprintf(outFile, "<td><b>%s</b></td></tr>\n", testMsg);
#else
	printf("Test %s failed. %s\n",testName,testMsg);
#endif
}

char* doubleUnderscore(FILE* outFile, char* testName) {
    int i = 0;
    int j = 0;
    while ( (testName[j]!='\0') && (i<(MAX_TEST_FILE_NAME_LENGTH-1)) ) {
        charBuffer[i] = testName[j];
        if (testName[j]=='_') {
            i++;
            charBuffer[i] = '_';
        }
        i++;
        j++;
    }
    if (testName[j]!='\0') {
       printErrorMsg(outFile, testName, "Test case name is too long");
    }
    charBuffer[i]='\0';
    return charBuffer;
}

