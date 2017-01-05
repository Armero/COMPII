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
	fcssUmlConfigurationsName index;
	unsigned numberOfOptions;
	fcssUmlUserIdentifierType temporaryNumber;

	char temporaryDirectory			[FCSS_UML_DIRECTORY_LENGTH + 1];
	char temporaryEmail					[FCSS_UML_EMAIL_LENGTH + 1];
	char temporaryFileName 			[FCSS_UML_FILENAME_LENGTH + 1];
	char temporaryNumberString 	[FCSS_UML_NUMBER_LENGTH + 1];
	char *validation;
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
 		return (FCSS_UML_CONFIGURATION_FILE_NOT_FOUND);

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
				if (FcssUmlGetStringOptionFromFile(configurationFile, temporaryNumberString, index, defaultOptions, FCSS_UML_EMAIL_LENGTH))
				{
					temporaryNumber = (fcssUmlUserIdentifierType) strtoul(temporaryNumberString, &validation, 10);
					if (!(*validation))
						options->administratorIdentifier = temporaryNumber;
				}
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
			stringIndex ++;
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
		return (FCSS_UML_EMPTY_STRING);

	if ( (stringLength < minimumLength) || (stringLength > maximumLegth) )
		return (FCSS_UML_STRING_WITH_INVALID_LENGTH);

	index = 0;
	while (stringInput[index])
	{
		auxIndex = 0;
		isValidChar = false;
		while (validChars[auxIndex])
		{
			if (stringInput[index] == validChars[auxIndex])
				isValidChar = true;

			auxIndex++;
			if ( (!validChars[auxIndex]) && (!isValidChar))
				isValidString = false;
		}
		index++;
	}

	if (!isValidString)
		return(FCSS_UML_STRING_WITH_INVALID_CONTENT);

	return (FCSS_UML_OK);
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
		return (FCSS_UML_EMPTY_STRING);

	if ( (stringLength < minimumLength) || (stringLength > maximumLegth) )
		return (FCSS_UML_STRING_WITH_INVALID_LENGTH);

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
		return(FCSS_UML_STRING_WITH_INVALID_CONTENT);

	printf("cont: %d\n", specialCharCounter );
	if (specialCharCounter != 1)
		return(FCSS_UML_INVALID_NICKNAME);

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
		return (FCSS_UML_EMPTY_STRING);

	if ( (stringLength < minimumLength) || (stringLength > maximumLegth) )
		return (FCSS_UML_STRING_WITH_INVALID_LENGTH);

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
		return(FCSS_UML_STRING_WITH_INVALID_CONTENT);

	printf("cont: %d\n", specialCharCounter );
	if (specialCharCounter != 1)
	{
		return(FCSS_UML_INVALID_EMAIL);
	}

	return (FCSS_UML_OK);
} 

fcssUmlErrorType
FcssUmlCreateRandomString (char *validChars, size_t length, char *outputString)
{	
	unsigned stringLength = strlen(validChars);
	unsigned index = 0;

	if (!validChars)
		return (FCSS_UML_EMPTY_STRING);

	srand(time(NULL));
	while (index <= length)
	{
		outputString[index] = validChars[(unsigned) rand() % stringLength];
		index++;
	}
	outputString[index] = EOS;

	return (FCSS_UML_OK);
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
		return (FCSS_UML_EMPTY_STRING);

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
		return (FCSS_UML_NOT_FULL_NAME);
	}

	if (!strlen(otherName))
		secondOption[0] = EOS;
	else
		FcssUmlGetAbsolutFileName(firstName, otherName, secondOption);
	
	FcssUmlGetAbsolutFileName(firstName, lastName, firstOption);	
	return (FCSS_UML_OK);
}

fcssUmlErrorType
FcssUmlGetCryptAlgorithm (char *passwordString, fcssUmlCryptAlgorithms *algorithmType)
{
	unsigned lengthPasswordString;
	

	if (!passwordString)
		return (FCSS_UML_EMPTY_STRING);

	lengthPasswordString = strlen(passwordString);

	if ((lengthPasswordString) >= FCSS_UML_SHA512_LENGTH_MINIMUM_LENGTH)
		*algorithmType = fcssUmlSha512; 

	else if ((lengthPasswordString) >= FCSS_UML_SHA256_LENGTH_MINIMUM_LENGTH)
		*algorithmType = fcssUmlSha256; 

	else if ((lengthPasswordString) >= FCSS_UML_MD5_LENGTH_MINIMUM_LENGTH)
		*algorithmType = fcssUmlMd5; 

	else
		*algorithmType = fcssUmlDes;

	return (FCSS_UML_OK);
}

fcssUmlErrorType
FcssUmlEncodePasswordWithSpecificAlgorithm (char *plainPassword, fcssUmlCryptAlgorithms algorithmType, char *encodedPassword)
{
	char saltPart[FCSS_UML_SALT_LENGTH + 1]; 
	char salt 	 [FCSS_UML_SALT_LENGTH + 5]; /* $id$ */
	char *stringBuffer;
	FcssUmlCreateRandomString (FCSS_UML_RANDOM_STRING_VALID_CHARACTERS, FCSS_UML_SALT_LENGTH, saltPart);

	if (!plainPassword)
		return (FCSS_UML_EMPTY_STRING);

	switch(algorithmType)
	{
		case (fcssUmlDes):
			salt[0] = EOS;
		break;
		case (fcssUmlMd5):
			strcpy(salt, "$1$");	
		break;
		case (fcssUmlSha256):
			strcpy(salt, "$5$");
		break;
		case (fcssUmlSha512):
			strcpy(salt, "$6$");
		break;
	}

	strcat(salt, saltPart);
	if (algorithmType != fcssUmlDes)
		strcat (salt, "$");

	stringBuffer = crypt(plainPassword, salt);
	strcpy(encodedPassword, stringBuffer);
	memset(stringBuffer, 0x00, strlen(stringBuffer));
	return (FCSS_UML_OK);
}

fcssUmlErrorType
FcssUmlEncodePasswordWithSpecificSalt (char *plainPassword, char *salt, char *encodedPassword)
{
	char *stringBuffer;
	if ( (!plainPassword)  || (!salt) ) 
		return (FCSS_UML_EMPTY_STRING);

	stringBuffer = crypt(plainPassword, salt);
	strcpy(encodedPassword, stringBuffer);
	memset(stringBuffer, 0x00, strlen(stringBuffer));

	return(FCSS_UML_OK);
}

fcssUmlErrorType
FcssUmlCheckPassword (char *plainPassword, char *encodedPassword)
{
	printf("encodedPassword1: \n\"%s\"\n", encodedPassword);
	unsigned counter = 1;
	unsigned index = 4;
	char temporaryPassword[FCSS_UML_PASSWORD_LENGTH + 1];

	if ((!plainPassword) || (!encodedPassword))
		return(FCSS_UML_EMPTY_STRING);

	char salt [FCSS_UML_SALT_LENGTH + 1];
	if (encodedPassword[0] != '$')
		strcpy (salt, encodedPassword);

	else
	{
		while (encodedPassword[index] != '$')
		{
			index++;
			counter++;
		}

		strncpy (salt, encodedPassword, counter + 4);
		salt[counter + 5] = EOS;
	}
	
	FcssUmlEncodePasswordWithSpecificSalt(plainPassword, salt, temporaryPassword);
	if (strcmp(temporaryPassword, encodedPassword))
		return (FCSS_UML_WRONG_PASSWORD);

	return (FCSS_UML_OK);
}

void 
FcssUmlInitializeNcursesWindows		(WINDOW **menu, WINDOW **topBar, WINDOW **footer, int heightBar, int widthBar, int numberOfColumns, int numberOfRows)
{
	*topBar = newwin (heightBar, widthBar - 5, 1, 1);
	*footer = newwin (heightBar + 4, widthBar - 5, numberOfRows - 6, 1);
	*menu =   newwin (numberOfRows, numberOfColumns, 0, 0);
}

void 
FcssUmlDrawNcursesMenu(WINDOW *menu, int highlight, int n_choices, fcssUmlLanguageType language, char *choices[fcssUmlLanguagesAmount][FCSS_UML_NCURSES_NUMBER_OF_OPTIONS])
{
	int row, column, index;	

	row = 2;
	column = 3;
	box(menu, 0, 0);
	for(index = 0; index < n_choices; ++index)
	{	
		if(highlight == index + 1) /* Highlight the present choice */
		{	wattron(menu, A_REVERSE); 
			mvwprintw(menu, column, row, "%s", choices[language][index]);
			wattroff(menu, A_REVERSE);
		}
		else
			mvwprintw(menu, column, row, "%s", choices[language][index]);
		column++;
	}
	wrefresh(menu);
}

void 
FcssUmlDrawNcursesTopBar (WINDOW *topBar, int numberOfColumns, fcssUmlLanguageType language, char *extraText[fcssUmlLanguagesAmount][FCSS_UML_NCURSES_NUMBER_OF_EXTRA_TEXT])
{
	int centerX = (numberOfColumns/2) - (strlen(extraText[language][0])/2);

	wclear(topBar);
	wbkgd(topBar, COLOR_PAIR(1));
	mvwprintw(topBar, 0, centerX, "%s", extraText[language][0]);
	wrefresh(topBar);
}

void 
FcssUmlDrawNcursesFooter (WINDOW *footer, int numberOfColumns, int numberOfRows, fcssUmlLanguageType language, char *extraText[fcssUmlLanguagesAmount][FCSS_UML_NCURSES_NUMBER_OF_EXTRA_TEXT])
{
	int centerX = (numberOfColumns/2) - (strlen(extraText[language][1])/2);

	wclear(footer);
	wbkgd(footer, COLOR_PAIR(1));
	mvwprintw(footer, 0, centerX, extraText[language][1]);
	mvwprintw(footer, 1, centerX, extraText[language][2]);
	mvwprintw(footer, 4, centerX, "%s", extraText[language][3]);
	curs_set(0);
	wrefresh(footer);
}

void 
FcssUmlCloseNcursesInterface  ()
{
	clrtoeol();
	refresh();
	endwin();
}


/* $RCSfile$ */


