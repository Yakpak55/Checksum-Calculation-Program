/*=============================================================================
| Assignment: pa02 - Calculating an 8, 16, or 32 bit
| checksum on an ASCII input file
|
| Author: Christopher Deluigi
| Language: c, c++, Java, GO, Python
|
| To Compile: javac pa02.java
| gcc -o pa02 pa02.c
| g++ -o pa02 pa02.cpp
| go build pa02.go
| python pa02.py //Caution - expecting input parameters
|
| To Execute: java -> java pa02 inputFile.txt 8
| or c++ -> ./pa02 inputFile.txt 8
| or c -> ./pa02 inputFile.txt 8
| or go -> ./pa02 inputFile.txt 8
| or python-> python3 pa02.py inputFile.txt 8
| where inputFile.txt is an ASCII input file
| and the number 8 could also be 16 or 32
| which are the valid checksum sizes, all
| other values are rejected with an error message
| and program termination
|
| Note: All input files are simple 8 bit ASCII input
|
| Class: CIS3360 - Security in Computing - Fall 2023
| Instructor: McAlpin
| Due Date:  Sunday by 11:59pm | Nov 12 at 11:59pm
|
+=============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void output(char array[], int size, unsigned int answer, int checksum); //creates function that prints the input array and also the cheeck sum


int main(int argc, char **argv)
{
    char array[10000];
    int size = 0;
    char *file_one = argv[1]; 
    char *bit = argv[2];


    FILE *file = fopen(file_one, "r");

    if (file == NULL)  //opens the first file
    {
        printf("Could not open File\n");
        return 1;
    }
    else
    {
        char c;
        int i = 0;

        while ((c = fgetc(file)) != EOF) //while loop reads in charcyers from the file and stores them in the array below
        {
            array[i] = c;
            size++;
            i++;
        } 
        fclose(file); //closes file
    }


    int checksum = atoi(bit); //if statement checks to makse surew the right checksum is inputted

    if (checksum == 8 || checksum == 16 || checksum == 32)
    {
    }
    else
    {
        fprintf(stderr, "Valid checksum sizes are 8, 16, or 32\n");
        return 1;
    }
  
    int num = checksum / 8;

    unsigned int answer = 0;
    int remainder = size % num;

    while((size % num) != 0)
    {
        array[size++] = 'X';
    }

    for (int x = 0; x < size; x += num) //for loop continues to check the checksum of the input array in bytes: 8, 16, or 32
    {
        int current = 0;
        for (int i = 0; i < num; i++)
        {
            current = current << 8;
            current += array[x+i];
        }
        answer += current;
    }

    int x = 1;
    for (int j = 0; j < 64; j++) // appls a mask to checksum to make sure that it fits within the specified checksum size
    {
        if(j >= checksum)
        {
            if((answer & x) != 0)
            {
                answer = answer ^ x;
            }
        }
        x *= 2;
    }

    output(array, size, answer, checksum); //prints the output
}


void output(char array[], int size, unsigned int answer, int checksum)//function printsd the iunput array and checksum
{
    for (int j = 0; j < size; j++)
    {
        if (j % 80 == 0)
        {
            printf("\n");
        }
        printf("%c", array[j]);
    }

    printf("\n%2d bit checksum is %8x for all %4d chars\n",checksum, answer, size);//end
}


/*=============================================================================
| I Christopher Deluigi ch554452 affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+============================================================================*/