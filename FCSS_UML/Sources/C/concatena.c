#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define EOS '\0'

void
FcssUmlGetAbsolutFileName (char *string1, char *string2, char *outputString);

int
//fcssUmlErrorType
FcssUmlCreateNickname (char *fullName, char *firstOption, char *secondOption);

typedef enum
{
	false,
	true,
} boolean;

int
main (int argc, char *argv[])
{
	char *string1;
	char *string2;
	char *string3;
	string1 = (char *) malloc (200 * sizeof(char));
	string2 = (char *) malloc (200 * sizeof(char));
	string3 = (char *) malloc (200 * sizeof(char));

  strcpy(string1, "Felipe ");
  string2[0] = EOS;
  string3[0] = EOS;

  //strcpy(string2, "abcdefgijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  FcssUmlCreateNickname (string1, string2,  string3);

	//printf("saida: %d\n", FcssUmlCreateNickname (string1, string2,  string3));
	printf("String2: %s\n", string2);
	printf("String3: %s\n", string3);
	return (0);
}


void
FcssUmlGetAbsolutFileName (char *string1, char *string2, char *outputString)
{
	snprintf(outputString, 50, "%s%s", string1, string2);
}

int
//fcssUmlErrorType
FcssUmlCreateNickname (char *fullName, char *firstOption, char *secondOption)
{	
	char firstName [20];
	char lastName  [20];
	char otherName [20];
	unsigned wordEnd = 0;
	unsigned fullNameLength = strlen(fullName);


	if (!fullName)
	{
		//return(1);
	}

	lastName[0] = EOS;
	otherName[0] = EOS;

	while ((fullName[wordEnd] != ' ') && (fullName[wordEnd]))
		wordEnd++;

	strncpy (firstName, fullName, wordEnd);

	firstName[wordEnd] = '.';
	firstName[wordEnd + 1] = EOS;
	fullName += wordEnd + 1;
	wordEnd = 0;


	if ( strlen(firstName) < fullNameLength )
	{
		while (fullName[wordEnd])
		{
			while ( (fullName[wordEnd] != ' ') && (fullName[wordEnd]) )
				wordEnd++;

			strcpy(otherName,lastName);
			strncpy(lastName, fullName, wordEnd);

			lastName[wordEnd] = EOS;
			fullName += wordEnd + 1;
			wordEnd = 0;
		}
	}

	if (!strlen(lastName))
	{
		firstOption[0] = EOS;
		secondOption[0] = EOS;
		return (2);
	}

	if (!strlen(otherName))
		secondOption[0] = EOS;
	else
		FcssUmlGetAbsolutFileName(firstName, otherName, secondOption);
	
	FcssUmlGetAbsolutFileName(firstName, lastName, firstOption);	
	return (0);
}