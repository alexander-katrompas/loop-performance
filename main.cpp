
#include <stdio.h>
#include <string>
#include <time.h>
#include <ctype.h>

#define ITER 10000000

int main() {

    clock_t start_time, end_time;
    
    int count = 0, i=0, j=0;
    std::string str = "This is a string for testing purposes.";
    double time_taken = 0;


    /*****************************************************************
        determinant loop demonstrating the proper way to use for loops.
        count is known, therefore this loop can be optimized.
        when count is known, us a for loop.
    *****************************************************************/
    count = 0;
    int strn = str.size();
    start_time = clock();
    for(i=0; i<ITER; i++){
        for (j=0; j<strn; j++) {
            if (isalpha(str[j])) {
                count++;
            }
        }
    }
    end_time = clock();
    time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken to execute determinant for loop: %f seconds\n", time_taken);

    /*****************************************************************
        indeterminant loop demonstrating the proper way to use while loops.
        count is not known, therefore this loop cannot be optimized well.
        however, given it is indeterminant, the proper loop is a while loop
        because an indeterminant for loop will be just as bad performance,
        but less readable and less maintainable since it potentially
        confuses the reader. Use a while loop in cases like this.
    *****************************************************************/
    start_time = clock();
    for(i=0; i<ITER; i++){
        j = 0;
        count=0;
        while(str[j]!='\0'){
            if (isalpha(str[count])) {
                count++;
            }
            j++;
        }
    }
    end_time = clock();
    time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken to execute indeterminant while loop: %f seconds\n", time_taken);
    
    /*****************************************************************
        indeterminant loop demonstrating the INCORRECT way to use for loops
        count is not known, therefore this loop cannot be optimized.
        performance is just as bad a while loop, but code is less readable
        and maintainable, and is confusing to the reader
    *****************************************************************/
    count = 0;
    start_time = clock();
    for(i=0; i<ITER; i++){
        for (j=0; str[j]!='\0'; j++) {
            if (isalpha(str[j])) {
                count++;
            }
        }
    }
    end_time = clock();
    time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken to execute indeterminant for loop 1: %f seconds\n", time_taken);
    
    /*****************************************************************
        indeterminant loop demonstrating the INCORRECT way to use for loops
        count is not known, therefore this loop cannot be optimized.
        performance is just as bad a while loop. in this case, the for loop
        syntax is a relatively new C++ feature to make indeterminant for loops
        more readable and more Python-like. A classic example of making a
        bad idea worse. This loop compiles down to the same form (or worse)
        as the previous loop, it just looks better on the surface.
    *****************************************************************/
    count = 0;
    start_time = clock();
    for(i=0; i<ITER; i++){
        for (char c : str) {
            if (isalpha(c)) {
                count++;
            }
        }
    }
    end_time = clock();
    time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken to execute indeterminant for loop 2: %f seconds\n", time_taken);
    
    return 0;

}

