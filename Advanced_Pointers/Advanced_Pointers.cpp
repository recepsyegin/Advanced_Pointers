#include <stdio.h>
#include <stdlib.h>

int array1[] = { 10,20,30,40,50,60,70,80,90,100 };
int array2[] = { 38,27,87,63,59,223,132,1,19,7 };


int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }
int divv(int a, int b) { return a / b; }

// Array of pointers to functions
int (*fpArray[])(int, int) = { &add,&sub,&mult, &divv };

// Performs the given operation on elements of the arrays
int* performOp(int* a, int* b, int size, int(*f)(int, int));

// Displays the elements of an array
void display(int* x, int size);


int main()
{
	int choice = 0;
	unsigned int size = 0;
	int* result = NULL;

	size = sizeof(array1);
	size = sizeof(array1);
	if (sizeof(array2) < size) size = sizeof(array2);

	size = size / sizeof(int);

	while (choice != 5)
	{
		printf("\nWhich operation do you want to perform?\n");
		printf("1.ADD\n");
		printf("2.SUBTRACT\n");
		printf("3.MULTIPLY\n");
		printf("4.DIVIDE\n");
		printf("5.None...\n");
		printf("Enter choice: ");
		scanf_s("%d", &choice);

		if (choice == 5) break;
		if (choice < 1 || choice > 5) continue;
		int j = choice - 1;
		result = performOp(array1, array2, size,fpArray[j]);

		printf("\n\n The results are...\n");
		display(result, size);

		if (result != NULL)
			free(result);
	}
	return 0;
}

int* performOp(int* a, int* b, int size, int(*f)(int,int))
{
	int* c = (int*)malloc(sizeof(int)*size);
	for(int i = 0;i<size;i++)
	{
		c[i] = (f)(a[i], b[i]);

	}

	return c;
}

void display(int* x, int size)
{
	if (x == NULL) return;
	for (int i = 0; i < size; i++)
	{
		printf("%d ", x[i]);
	}
	printf("\n");
}