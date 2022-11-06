 #include <stdio.h>
#include <stdlib.h>
#include <string.h> // was missing in q3
#pragma warning(disable : 4996) // was missing in q1


void q1() {
	int a = 4, b = 7; // fix - , instead of ;
	float c;
	scanf("%f", &c);
	if (c == 5) {// replace c and 5 places and add extra = to the condition. 
		printf("%f", c);
	}// f was missing after print and curly braces after condition
}

void q2() {

	int x, y;
	int nums[6];
	int* arrPtr;

	// Section A - Print the variables
	printf("***** Section A *****\n"); // printf instead puts
	x = 5, y = 3;// x(base) & y(height) wasn't initialized before.
	printf(" Base = %d\n", x);
	printf(" Height = %d\n", y);
	printf(" Area = %d\n", (x * y) / 2); // 
	// Section B - Print the static array "nums".
	printf("***** Section B *****\n"); // printf instead puts
	int i = 0;

	while (i < 6) { // fill the array with numbers (wasn't initialized)
		nums[i] = i;
		i++; // i promotion
	}
	i = 0; // i initialization
	while (i < 6) {
		printf("nums[%d] = %d\n", i, nums[i]);
		i++; // i promotion
	}

	// Section C - Print allocated array.
	printf("***** Section C *****\n"); // printf instead puts
	arrPtr = malloc(sizeof(int) * 6); // 6 instead of 10
	int* arrPtrStart = arrPtr; // anchor var to the start of the dynamic array
	if (arrPtr) {

		// fills the dynamic array with values
		for (i = 0; i < 6; i++) { 
			*arrPtr = i; 
			arrPtr++;
		}
		// init arrPtr to the array start
		arrPtr = arrPtrStart;

		for (i = 0; i < 6; i++) {
			printf(" array[%d] = %d\n", i, *arrPtr); // add * to arrPtr to print his value
			arrPtr++; // addPtr promotion
		}
	}
	else {
		printf("Error Allocating Memory!\n");
		exit(1);
	}




}


////////////		Q3			 //////////////////////////

typedef struct letter{
	char small;
	char big;
	int counter;
	struct letter* next; // add pointers to the next/prev letter 
	struct letter* prev;
	
}letter;

void freelist(letter* head) {
	letter* releaseitem;
	letter* runitem = head;
	while (runitem != NULL) {
		releaseitem = runitem;
		runitem = runitem->next;
		free(releaseitem);
	}
}

void q3() {

	//Next two string represents all the english alphabets(small and capital)
	char* smallAlpha = "abcdefghijklmnopqrstuvwxyz";
	char* bigAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	// anchors for small and big alphas
	char* anchorA = smallAlpha;
	char* anchorB = bigAlpha;

	int loops = strlen(smallAlpha); // getting a constant size to run through

	int lettersCountArr[26] = {0}; // CHANGE THE ARRAY SIZE AS THE OPTIONAL LETTERS NUMBER
	char readChar, ch;
	FILE* f;

	f = fopen("myFile.txt", "r");

	// Dis[lay the content of myFile.txt and count letters
	printf("the content of myFile.txt :\n");
	while ((readChar = fgetc(f)) != EOF) { // EOF instead of 0
		printf("%c", readChar);
		
		smallAlpha = anchorA;
		bigAlpha = anchorB;

		

		for (int i = 0; i < loops; ++i) {
			if (readChar == smallAlpha[i] || readChar == // CHANGE THE POINTERS TO COMPARE WITH THEIR VALUE
				*bigAlpha) {

				lettersCountArr[i]++;
			}
			smallAlpha++;
			bigAlpha++;
		}
	}
	fclose(f);

	// Build Linked list from file content
	// Every node represent English letter (small and big).
	letter* HEAD = NULL;
	letter* TAIL = NULL;
	for (int j = 0; j < loops; ++j) {
			letter* letterItem = (letter*)malloc(sizeof(letter));
			if (!letterItem) {
				printf("Error Allocating Memory!"); // printf instead of puts
				exit(1);
			}
			letterItem->small = 'a' + j;
			letterItem->big = 'A' + j;
			letterItem->counter = lettersCountArr[j];
			// Creating the linked list

			if (HEAD == NULL) { // ADD THE HEAD SECTION TO THE LINKED LIST BUILD
				HEAD = letterItem;
				TAIL = letterItem;
				letterItem->prev = NULL;

			}
			else { // ADD THE TAIL SECTION TO THE LINKED LIST BUILD
				letterItem->prev = TAIL;
				TAIL->next = letterItem;
				TAIL = letterItem;
			}
			letterItem->next = NULL;
		}

	}


 int main() {
		  q1();
		 q2();
		 q3();
		  


		  return 0;
}