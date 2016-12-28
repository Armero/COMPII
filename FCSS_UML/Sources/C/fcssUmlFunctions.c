/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2016/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Felipe Claudio da Silva Santos

$Author$
$Date$
$Log$
*/ 
#include "fcssUmlFunctions.h"

fcssUmlLanguageType
FcssUmlGetLanguageIndex (char *language)
{
	if ( !(strcmp(language, "portuguese") ) ) 
		return (fcssUmlPortuguese);

	return (fcssUmlEnglish);
}

fcssUmlErrorType
FcssUmlGetConfigurationOptionsValues (char *fileName, fcssUmlConfigurationOptionsType *options)
{
	FILE *configurationFile;
	unsigned numberOfOptions, temporaryNumber;
	fcssUmlConfigurationsName index;

	char temporaryDirectory	[FCSS_UML_DIRECTORY_LENGTH + 1];
	char temporaryEmail			[FCSS_UML_EMAIL_LENGTH + 1];
	char temporaryFileName 	[FCSS_UML_FILENAME_LENGTH + 1];
	char *defaultOptions [] =
	{
		"FCSS_UML_ROOT_DIRECTORY",
		"FCSS_UML_DATA_DIRECTORY",
		"FCSS_UML_COOKIES_DIRECTORY",
		"FCSS_UML_ADMINISTRATOR_USER_IDENTIFIER",
		"FCSS_UML_ADMINISTRATOR_EMAIL",
		"FCSS_UML_PRIVATE_ROOT_DIRECTORY",
		"FCSS_UML_USERS_DATA_FILENAME",
		"FCSS_UML_INVITED_USERS_DATA_FILENAME",
		"FCSS_UML_REQUESTING_USERS_DATA_FILENAME",
		"FCSS_UML_LOCKED_USERS_DATA_FILENAME",
	};

	
	strncpy(options->rootDirectory, FCSS_UML_ROOT_DIRECTORY, FCSS_UML_DIRECTORY_LENGTH + 1);
	strncpy(options->dataDirectory, FCSS_UML_DATA_DIRECTORY, FCSS_UML_DIRECTORY_LENGTH + 1);
	strncpy(options->cookiesDirectory, FCSS_UML_COOKIES_DIRECTORY, FCSS_UML_DIRECTORY_LENGTH + 1);
	options->administratorIdentifier = (fcssUmlUserIdentifierType) FCSS_UML_ADMINISTRATOR_USER_IDENTIFIER;
	strncpy(options->administratorEmail, FCSS_UML_ADMINISTRATOR_EMAIL, FCSS_UML_EMAIL_LENGTH + 1);
	strncpy(options->privateRootDirectory, FCSS_UML_PRIVATE_ROOT_DIRECTORY, FCSS_UML_DIRECTORY_LENGTH + 1);
	strncpy(options->usersDataFileName, FCSS_UML_USERS_DATA_FILENAME, FCSS_UML_FILENAME_LENGTH + 1);
	strncpy(options->invitedUsersDataFileName, FCSS_UML_INVITED_USERS_DATA_FILENAME, FCSS_UML_FILENAME_LENGTH + 1);
	strncpy(options->requestingUsersDataFilename, FCSS_UML_REQUESTING_USERS_DATA_FILENAME, FCSS_UML_FILENAME_LENGTH + 1);
	strncpy(options->lockedUsersDataFileName, FCSS_UML_LOCKED_USERS_DATA_FILENAME, FCSS_UML_FILENAME_LENGTH + 1);

	/*verify length of the strings before copying*/
	numberOfOptions = (unsigned) sizeof(defaultOptions) / sizeof(char *);
	index = ROOT_DIRECTORY;
	if ( !(configurationFile = fopen(fileName, "r")) )
 	{
 		return (FCSS_UML_CONFIGURATION_FILE_NOT_FOUND);
 	}
	while (index < numberOfOptions)
	{
		switch (index)
		{
			case(ROOT_DIRECTORY):
				if (FcssUmlGetStringOptionFromFile(configurationFile, temporaryDirectory, index, defaultOptions, FCSS_UML_DIRECTORY_LENGTH))
					strncpy(options->rootDirectory, temporaryDirectory, FCSS_UML_DIRECTORY_LENGTH + 1);
			break;
			case(DATA_DIRECTORY):
				if (FcssUmlGetStringOptionFromFile(configurationFile, temporaryDirectory, index, defaultOptions, FCSS_UML_DIRECTORY_LENGTH))
					strncpy(options->dataDirectory, temporaryDirectory, FCSS_UML_DIRECTORY_LENGTH + 1);
			break;
			case(COOKIES_DIRECTORY):
				if (FcssUmlGetStringOptionFromFile(configurationFile, temporaryDirectory, index, defaultOptions, FCSS_UML_DIRECTORY_LENGTH))
					strncpy(options->cookiesDirectory, temporaryDirectory, FCSS_UML_DIRECTORY_LENGTH + 1);
			break;
			case(ADMINISTRATOR_USER):
				if (FcssUmlGetNumericOptionFromFile(configurationFile, &temporaryNumber, index, defaultOptions, FCSS_UML_DEFAULT_LINE_LENGTH))
					options->administratorIdentifier = temporaryNumber;
			break;
			case(ADMINISTRATOR_EMAIL):
				if (FcssUmlGetStringOptionFromFile(configurationFile, temporaryEmail, index, defaultOptions, FCSS_UML_EMAIL_LENGTH))
					strncpy(options->administratorEmail, temporaryEmail, FCSS_UML_EMAIL_LENGTH + 1);
			break;
			case(PRIVATE_ROOT_DIRECTRY):
				if (FcssUmlGetStringOptionFromFile(configurationFile, temporaryDirectory, index, defaultOptions, FCSS_UML_DIRECTORY_LENGTH))
					strncpy(options->privateRootDirectory, temporaryDirectory, FCSS_UML_DIRECTORY_LENGTH + 1);
			break;
			case(USERS_DATA_FILENAME):
				if (FcssUmlGetStringOptionFromFile(configurationFile, temporaryFileName, index, defaultOptions, FCSS_UML_FILENAME_LENGTH))
					strncpy(options->usersDataFileName, temporaryFileName, FCSS_UML_FILENAME_LENGTH + 1);
			break;
			case(INVITED_USERS_DATA_FLENAME):
				if (FcssUmlGetStringOptionFromFile(configurationFile, temporaryFileName, index, defaultOptions, FCSS_UML_FILENAME_LENGTH))
					strncpy(options->invitedUsersDataFileName, temporaryFileName, FCSS_UML_FILENAME_LENGTH + 1);
			break;
			case(REQUESTING_USERS_DATA_FILENAME):
				if (FcssUmlGetStringOptionFromFile(configurationFile, temporaryFileName, index, defaultOptions, FCSS_UML_FILENAME_LENGTH))
					strncpy(options->requestingUsersDataFilename, temporaryFileName, FCSS_UML_FILENAME_LENGTH + 1);
			break;
			case(LOCKED_USERS_DATA_FILENAME):
				if (FcssUmlGetStringOptionFromFile(configurationFile, temporaryFileName, index, defaultOptions, FCSS_UML_FILENAME_LENGTH))
					strncpy(options->lockedUsersDataFileName, temporaryFileName, FCSS_UML_FILENAME_LENGTH + 1);
			break;	
		}
		index++;
	}

	fclose(configurationFile);
	return (FCSS_UML_OK);
}

boolean
FcssUmlGetStringOptionFromFile (FILE *configurationFile, char *temporaryString, unsigned index, char *defaultOptions[], int lineLength)
{
	unsigned memberLength = strlen(defaultOptions[index]);
	unsigned stringIndex = memberLength;
	unsigned auxiliaryIndex = 0;
	char temporaryBuffer [lineLength + 1];

	while (fgets(temporaryBuffer, lineLength, configurationFile))
	{
		if (!strncmp(temporaryBuffer, defaultOptions[index], memberLength))
		{
			stringIndex ++; /*after the equal sign*/
			while (temporaryBuffer[stringIndex]) 
			{
				temporaryString[auxiliaryIndex] = temporaryBuffer[stringIndex];
				auxiliaryIndex++;
				stringIndex++;
			}
			temporaryString[auxiliaryIndex - 1] = EOS;
			return (true);
		}			
	}

	return(false);
}

boolean
FcssUmlGetNumericOptionFromFile (FILE *configurationFile, unsigned *temporaryNumber, unsigned index, char *defaultOptions[], int lineLength)
{
	unsigned memberLength = strlen(defaultOptions[index]);
	unsigned stringIndex = memberLength;
	unsigned auxiliaryIndex = 0;
	char temporaryBuffer [lineLength + 1];
	char temporaryString [lineLength + 1];
	char *validation;

	while (fgets(temporaryBuffer, lineLength, configurationFile))
	{
		if (!strncmp(temporaryBuffer, defaultOptions[index], memberLength))
		{
			stringIndex ++; /*after the equal sign*/
			while (temporaryBuffer[stringIndex])
			{
				temporaryString[auxiliaryIndex] = temporaryBuffer[stringIndex];
				auxiliaryIndex++;
				stringIndex++;
			}
			temporaryString[auxiliaryIndex] = EOS;
			*temporaryNumber = (unsigned) strtoul(temporaryString, &validation, 10);
			return (true);
		}			
	}
	
	return(false);
}

void
FcssUmlGetAbsolutFileName (char *string1, char *string2, char *outputString)
{
	snprintf(outputString, 50, "%s%s", string1, string2);
}

fcssUmlErrorType
FcssUmlCheckStringField (char *stringInput, char *validChars, size_t minimumLength, size_t maximumLegth)
{
	unsigned index, auxIndex;
	unsigned stringLength = strlen(stringInput);
	boolean isValidChar = false;
	boolean isValidString = true;

	if ((!stringInput) || (!validChars))
	{
		//return (2);
	}
	if ( (stringLength < minimumLength) || (stringLength > maximumLegth) )
	{
		//return (1);
	}

	index = 0;
	while (stringInput[index])
	{
		auxIndex = 0;
		isValidChar = false;
		while (validChars[auxIndex])
		{
			if (stringInput[index] == validChars[auxIndex])
			{
				isValidChar = true;
			}
			auxIndex++;
			if ( (!validChars[auxIndex]) && (!isValidChar))
				isValidString = false;
		}
		index++;
	}
	if (!isValidString)
		//return(3);

	return (0);
}

fcssUmlErrorType
FcssUmlCheckNickname (char *stringInput, char *validChars, size_t minimumLength, size_t maximumLegth)
{
	unsigned index, auxIndex;
	unsigned stringLength = strlen(stringInput);
	unsigned specialCharCounter = 0;
	boolean isValidChar = false;
	boolean isValidString = true;

	if ((!stringInput) || (!validChars))
	{
		//return (2);
	}
	if ( (stringLength < minimumLength) || (stringLength > maximumLegth) )
	{
		//return (1);
	}

	index = 0;
	while (stringInput[index])
	{
		auxIndex = 0;
		isValidChar = false;
		while (validChars[auxIndex])
		{
			if (stringInput[index] == validChars[auxIndex])
			{
				isValidChar = true;
			}
			auxIndex++;
			if ( (!validChars[auxIndex]) && (!isValidChar))
				isValidString = false;
		}
		if (stringInput[index] == '.')
		{
			isValidChar = true;
			isValidString = true;
			specialCharCounter++;
		}
		index++;
	}
	if (!isValidString)
		//return(3);

	printf("cont: %d\n", specialCharCounter );
	if (specialCharCounter != 1)
	{
		//return(4);
	}

	return (FCSS_UML_OK);
} 

fcssUmlErrorType
FcssumlCheckEmail (char *stringInput, char *validChars, size_t minimumLength, size_t maximumLegth)
{
	unsigned index, auxIndex;
	unsigned stringLength = strlen(stringInput);
	unsigned specialCharCounter = 0;
	boolean isValidChar = false;
	boolean isValidString = true;

	if ((!stringInput) || (!validChars))
	{
		//return (2);
	}
	if ( (stringLength < minimumLength) || (stringLength > maximumLegth) )
	{
		//return (1);
	}

	index = 0;
	while (stringInput[index])
	{
		auxIndex = 0;
		isValidChar = false;
		while (validChars[auxIndex])
		{
			if (stringInput[index] == validChars[auxIndex])
			{
				isValidChar = true;
			}
			auxIndex++;
			if ( (!validChars[auxIndex]) && (!isValidChar))
				isValidString = false;
		}
		if (stringInput[index] == '@')
		{
			isValidChar = true;
			isValidString = true;
			specialCharCounter++;
		}
		index++;
	}
	if (!isValidString)
		//return(3);

	printf("cont: %d\n", specialCharCounter );
	if (specialCharCounter != 1)
	{
		//return(4);
	}

	return (FCSS_UML_OK);
} 

fcssUmlErrorType
FcssUmlCreateRandomString (char *validChars, size_t length, char *outputString)
{	
	unsigned stringLength = strlen(validChars);
	unsigned index = 0;

	if (!validChars)
	{
		//return(1);
	}
	srand(time(NULL));
	while (index < length)
	{
		outputString[index] = validChars[(unsigned) rand() % stringLength];
		index++;
	}
	outputString[index] = EOS;

	return (0);
}

fcssUmlErrorType
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
	return (FCSS_UML_OK);
}

/* $RCSfile$ */


