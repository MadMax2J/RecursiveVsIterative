/*
The factorial of a non-negative integer n, written as n!, is a mathematical calculation that
is the product of all positive integers less than or equal to n. The calculation of
factorials is one of the example of the use of recursion.

The calculation can be written as
n! = n * (n-1) * (n-2) * ... 1
where 1! = 1, and 0! is defined to be 1 as well.

In this exercise, you will be using factorials to calculate a mathematical series.  Perform
the following steps for this exercise:
1.  One of the tenets of modern Software Engineering is code reuse.
    There are many instances of functions that implement the factorial schema on the Internet.
    Locate a recursive instance, code it and test it.

2.  Use the factorial function to calculate the series:
    e = 1/0! + 1/1! + 1/2! + 1/3! + ... for 20 terms.

3.  Write the same series calculation using an iterative loop of your choice.

4.  Instrument your code to measure time for the recursive and iterative loop methods to
    calculate the first 20 terms of the series.

5.  Present your timing results.

6.  Based on your timing results, comment on the quote:
    �Would any of you very experienced programmers, if asked to code an iterative
	loop (like a mathematical series), think of using recursion or would that be a
	�mistake� that a rookie programmer would leap to?�
*/

//Access C Standard Library
#include <stdio.h>
#include <time.h>

//Define my constants
#define TERMS 20				//The number of terms in the series to calculate.
#define TEST_REPEAT_COUNT 20000	//How many times should we repeat the factorial processes tests

//Declare my function prototypes
void displayWelcome();		//A Welcome Message
double recursiveTest();		//The Recursive Function test
double iterativeTest();		//The Iterative Function test
unsigned long long int recursiveFactorial(unsigned int number);	//Recursive Factorial function
unsigned long long int iterativeFactorial(unsigned int number);	//Iterative Factorial function
void displayVerdict(double recursiveTestDuration, double iterativeTestDuration);	//Outputs results to the user

//Simplified main() function
int main() {

    displayWelcome();			//Display the Welcome Message

    //Requirement #4 - Instrument your code to measure time for the recursive and iterative loop methods
    //Declare variables for my function return values.
    double recursiveTestDuration;
    double iterativeTestDuration;

    recursiveTestDuration = recursiveTest();	//Perform the Recursive Function Test
    iterativeTestDuration = iterativeTest();	//Perform the Iterative Function Test

    //Requirement #5 - Present your timing results
    displayVerdict(recursiveTestDuration, iterativeTestDuration);

    return(0);			//Assuming program completed successfully

} //End of main()

/*welcome
Displays an introduction to the user, describing what this program will do.
*/
void displayWelcome() {
    puts("Recursive vs. Iterative function performance comparison.\n");
    puts("This program calculates an approximate value for Euler's number, with the");
    printf("equation... e = 1/0! + 1/1! + 1/2! + 1/3! + ... for %d terms.\n\n", TERMS);

    puts("In order to determine if a Recursive function or Iterative function performs");
    puts("better, we'll use the C Standard Library 'clock()' function, to time the");
    puts("calculation of the factorial values, using both a Recursive function and");
    printf("an Iterative function. The test is repeated %d times, as the resolution\n", TEST_REPEAT_COUNT);
    puts("of the 'count()' function is system dependant and on some High Performance");
    puts("systems, calculating Euler's number by itself, doesn't even register.");
    puts("This timing data will then be presented to the user for evaluation.\n\n");


    puts("WARNING - In testing, I've found that this program has improved timing");
    puts("resolution on a system with a Linux host Operating System.\n\a");

    printf("%s", "Press ENTER key to Continue...");
    getchar();	//Causes program to pause until user hits the 'ENTER' key
    puts("\n\n");
}

/*Requirement #2 - Use the factorial function to calculate �e�
recursiveTest
This function returns the time it takes to calculate Euler's number
using 'TERMS' Factorial terms, calculated with a Recursive Factorial function call.

The test is repeated 'TEST_REPEAT_COUNT' times, as the Standard Library C count()
function's resolution is system dependant. On some High Performance systems,
calculating Euler's number only once, doesn't register with the count() function.

We then output the calculated number and the time taken to complete the task.

return duration � Time taken to complete test.
*/
double recursiveTest() {
    long double eRecursive;			//Result of Number Series to be calculated
    clock_t beforeTime, afterTime;	//Before process and After process time variables
    double duration;				//Calculated duration of test variable

    //Start test...
    puts("Starting Euler's Number calculation via Recursive function...");
    beforeTime = clock();	//Record the current number of clock ticks since program launched

    //Modern computers can do this so quickly, so I repeat the process TEST_REPEAT_COUNT times...
    for (int x = 1; x <= TEST_REPEAT_COUNT; x++) {
        eRecursive = 0.0;
        //Calculate Euler's number via the formula...
        //    e = 1/0! + 1/1! + 1/2! + 1/3! + ... for declared constant 'TERMS' terms
        for (int count = 0; count <= TERMS; count++) {
            eRecursive += 1.0 / recursiveFactorial(count);
        }//End of inner for
    }//End of TEST_REPEAT for

    afterTime = clock();	//Record the current number of clock ticks since program launched

    //Clock ticks 'After' minus Clock ticks 'Before' equals process ticks.
    //Display duration in seconds, by dividing by the system constant 'CLOCKS_PER_SEC' from <time.h>
    duration = (double)(afterTime - beforeTime) / CLOCKS_PER_SEC;

    //Output calculated figure and time taken...
    printf("\te = %.14f\n", (double)eRecursive);	//Found that we lose accuracy after 14dp
    printf("\tCalculation completed in a time of %f seconds\n\n", duration);

    //size_t bob = 1;
    return duration;
}//End of function recursiveTest()


/*Requirement #3 � Calculate �e� using an iterative loop
iterativeTest
This function returns the time it takes to calculate Euler's number
using 'TERMS' Factorial terms, calculated with an Iterative Factorial function call.

The test is repeated 'TEST_REPEAT_COUNT' times, as the Standard Library C count()
function's resolution is system dependant. On some High Performance systems,
calculating Euler's number only once, doesn't register with the count() function.

We then output the calculated number and the time taken to complete the task.

return duration � Time taken to complete test.
*/
double iterativeTest() {
    long double eIterative;			//Result of Number Series to be calculated
    clock_t beforeTime, afterTime;	//Before process and After process time variables
    double duration;				//Calculated duration of test variable

    //Start test...
    puts("Starting Euler's Number calculation via Iterative function...");
    beforeTime = clock();	//Record the current number of clock ticks since program launched

    //Modern computers can do this so quickly, so I repeat the process TEST_REPEAT_COUNT times...
    for (int x = 1; x <= TEST_REPEAT_COUNT; x++) {
        eIterative = 0.0;
        //Calculate Euler's number via the formula...
        //    e = 1/0! + 1/1! + 1/2! + 1/3! + ... for declared constant 'TERMS' terms
        for (int count = 0; count <= TERMS; count++) {
            eIterative += 1.0 / iterativeFactorial(count);
        }//End of inner for
    }//End of TEST_REPEAT for

    afterTime = clock();	//Record the current number of clock ticks since program launched

    //Clock ticks 'After' minus Clock ticks 'Before' equals process ticks.
    //Display duration in seconds, by dividing by the system constant 'CLOCKS_PER_SEC' from <time.h>
    duration = (double)(afterTime - beforeTime) / CLOCKS_PER_SEC;

    //Output calculated figure and time taken...
    printf("\te = %.14Lf\n", eIterative);	//Found that we lose accuracy after 14dp
    printf("\tCalculation completed in a time of %f seconds\n\n", duration);
    return duration;
}//End of function iterativeTest()


//Requirement #1 - "Code Reuse"
//Taken from (Deitel. P, Deital. H, 2013)
// ** NOTE ** - Internal function comments are unchanged from source. Only change made, was function name.
//
//recursive definition of function recursiveFactorial
unsigned long long int recursiveFactorial(unsigned int number)
{
    // base case
    if (number <= 1) {
        return 1;
    } // end if
    else { // recursive step
        return (number * recursiveFactorial(number - 1));
    } // end else
} // end function factorial

//Requirement #3 - "Iterative loop implementation"
/*iterativeFactorial
This function returns a factorial value using an Iterative loop

parameter n - The input value whose factorial is to be calculated. ie. 1!, 2! ... n!
return - a potentially very large integer value which is the factorial of the input parameter.
eg.		 5! = 120
		20! = 2432902008176640000
*/
unsigned long long int iterativeFactorial(unsigned int n)
{
    unsigned long long int factorial = 1;		//Initialise to 1 because 1 * x = x and 0 * x = 0
    for (int count = n; count >= 1; count--) {	//Start with 'count'; continue till count = 1
        // decrement 'count'
        factorial *= count;						//Increment factorial value with product of 'count'
    }
    return factorial;							//return the calculated factorial value.

}

/*displayVerdict
This function take in the two results from our Recursive and Iterative function tests and
determines how much faster one function was over the other. The result is then displayed
to the user.

parameter recursiveTestDuration - The Recursive function's Test Duration
parameter iterativeTestDuration - The Iterative function's Test Duration
*/
void displayVerdict(double recursiveTestDuration, double iterativeTestDuration) {

    //Confirm that the Recursive function took longer.
    // **NOTE** - This should nearly always be the case, so it's the first condition to check.
    if (recursiveTestDuration > iterativeTestDuration) {
        printf("\nThe Iterative process was %.1f times faster than the Recursive process.\n\n",
               recursiveTestDuration / iterativeTestDuration);
    }
        //This is unlikely, but we should allow for the possibility...
    else if (recursiveTestDuration < iterativeTestDuration) {

        printf("\nThe Recursive process was %.1f times faster than the Iterative process.\n\n",
               iterativeTestDuration / recursiveTestDuration);
    }
        //Again unlikely...
    else {
        puts("\nThere was no performance difference between the Recursive and Iterative functions.\n");
    }

}