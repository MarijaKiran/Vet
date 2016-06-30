#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef struct{
//structure that contains information on an animal
//his name
char name[20];
//year of birth
int year;
//type
char type[20];
//number in the "database"
int number;
}Animal;

//a function that compares 2 strings, returns 1 if the strings are equal, 0 if not
int compareStrings (char string1[],char string2[])
{
	int i;
	//condition that compares the lengths of the strings
	if(strlen(string1) == strlen(string2))
	{
		//itaration of one by one character of the strings
		for(i=0;string1[i]!='\0';i++)
		{
			//if there's at least one character that doesn't match, return 0
			if(string1[i]!=string2[i])
			{
				return 0;
			}
		}
		//if not return 1
		return 1;
	}
	//return 0 if the first if condition is not true: different lengths of strings
	return 0;
}

//function that prints all the information on each animal in an Animal type array
void printAll (Animal BDDVet[], int n)
{
    int i;
    printf("Number, Name, Type, Year\n");
    for(i=0;i<n;i++)
    {
        printf("%d,%s,%s,%d\n", BDDVet[i].number, BDDVet[i].name,BDDVet[i].type, BDDVet[i].year);
    }
}

//function that matches animal's type with a searched type entered by the user and place the animal's index in an dynamic array
//*typeMatch is a refference to a char array passed as an argument
//later prints out the names of matched animals
void match(Animal BDDVet[],int n,char *typeMatch)
{
	/*Unsigned integral type.
	 Alias of one of the fundamental unsigned integer types.
	 It is a type able to represent the size of
	 any object in bytes:
	 size_t is the type returned by the sizeof operator
	 and is widely used in the standard library
	 to represent sizes and counts.*/

	//initial size and coefficient of expand=1
	size_t arraySizeExpand=1;

	//declaring a int pointer
	int *matchedAnimalsIndex;

	//allocating the array with initial size of 1 using malloc

	matchedAnimalsIndex=(int*)malloc(arraySizeExpand*sizeof(int));
	//declaring an int variable count that counts the string matches in the for loop
	int i,count=0;

	//in a for loop do
	for(i=0;i<n;i++)
	  {
		 //check if an animal's type matches a searched type enter by the user
		 if(compareStrings(BDDVet[i].type,typeMatch))
	     {	 //increase the counter
			 count ++;

			 //incrementing the variable arraySizeExpand each time there is a match
			 arraySizeExpand++;

			 //expanding the array by 1, matchedAnimalsIndex is now +1
	    	 matchedAnimalsIndex =(int*)realloc(matchedAnimalsIndex,arraySizeExpand * sizeof(int));

			 //fill in the index of the element matched into the dynamic array
	    	 //instead of filling it directly with the name
	    	 //in order to save memory and avoid working with structures
	    	 matchedAnimalsIndex[count-1]=i;

	     }
	  }
	//prints out only the names of the matched animals
	for(i=0;i<count;i++)
	{
		//the values in the matchedAnimalsIndex array are already the ones matched
		printf("%s\n",BDDVet[matchedAnimalsIndex[i]].name);
	}

}


int main()
{
	//declare a pointer that will later point to the adrese of the Animal's type entered by the user
	char *type=(char*)malloc(sizeof(char)+256);
	//declare a counter for the for loop
	int i;
	//declare a variable reserved for Animal number
	int Animalnb;
	//declare an array of type Animal
    Animal BDDVet[N];
    printf("Enter a number of animals to fill in:");
    //typing number of animals to be filled in the "database"
    scanf("%d",&Animalnb);
    printf("\n");
    //fill in array BDDVet with info on the animals
    for(i=0;i<Animalnb;i++)
    {
        printf("Enter a name:");
        scanf("%s",BDDVet[i].name);
        printf("Enter a year of birth:");
        scanf("%d",&BDDVet[i].year);
        printf("Enter the type of the animal:");
        scanf("%s",BDDVet[i].type);
        BDDVet[i].number=i+1;
        printf("\n----------------------------------\n");
    }

    //call of the printAll function
    printAll(BDDVet,Animalnb);

    printf("\nEnter a type of an animal:");
    scanf("%s",type);

    //call of the printMatch function
    match(BDDVet,Animalnb,type);
    return 0;
}
