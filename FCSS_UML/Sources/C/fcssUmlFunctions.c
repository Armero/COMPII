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
	char *defaultOptions [] =
	{
		"FCSS_UML_ROOT_DIRECTORY",
		"FCSS_UML_DATA_DIRECTORY",
		"FCSS_UML_COOKIES_DIRECTORY",
		"FCSS_UML_ADMINISTRATOR_USER_IDENTIFIER",
		"FCSS_UML_ADMINISTRATOR_EMAIL",
	};

	
	strncpy(options->rootDirectory, FCSS_UML_ROOT_DIRECTORY, FCSS_UML_DIRECTORY_LENGTH + 1);
	strncpy(options->dataDirectory, FCSS_UML_DATA_DIRECTORY, FCSS_UML_DIRECTORY_LENGTH + 1);
	strncpy(options->cookiesDirectory, FCSS_UML_COOKIES_DIRECTORY, FCSS_UML_DIRECTORY_LENGTH + 1);
	options->administratorIdentifier = (fcssUmlUserIdentifierType) FCSS_UML_ADMINISTRATOR_USER_IDENTIFIER;
	strncpy(options->administratorEmail, FCSS_UML_ADMINISTRATOR_EMAIL, FCSS_UML_EMAIL_LENGTH + 1);

	/*verify length of the strings before copying*/
	numberOfOptions = (unsigned) sizeof(defaultOptions) / sizeof(char *);
	index = ROOT_DIRECTORY;
	printf("%s fileName: %s\n", "aqui-1", fileName);
	if ( !(configurationFile = fopen(fileName, "r")) )
 	{
 		return (CONFIGURATION_FILE_NOT_FOUND);
 	}
	printf("%s\n", "aqui0");
	while (index < numberOfOptions)
	{
		switch (index)
		{
			case(ROOT_DIRECTORY):
				if (fcssUmlGetStringOptionFromFile(configurationFile, temporaryDirectory, index, defaultOptions, FCSS_UML_DIRECTORY_LENGTH))
					strncpy(options->rootDirectory, temporaryDirectory, FCSS_UML_DIRECTORY_LENGTH + 1);
			break;
			case(DATA_DIRECTORY):
				if (fcssUmlGetStringOptionFromFile(configurationFile, temporaryDirectory, index, defaultOptions, FCSS_UML_DIRECTORY_LENGTH))
					strncpy(options->dataDirectory, temporaryDirectory, FCSS_UML_DIRECTORY_LENGTH + 1);
			break;
			case(COOKIES_DIRECTORY):
				if (fcssUmlGetStringOptionFromFile(configurationFile, temporaryDirectory, index, defaultOptions, FCSS_UML_DIRECTORY_LENGTH))
					strncpy(options->cookiesDirectory, temporaryDirectory, FCSS_UML_DIRECTORY_LENGTH + 1);
			break;
			case(ADMINISTRATOR_USER):
				if (fcssUmlGetNumericOptionFromFile(configurationFile, &temporaryNumber, index, defaultOptions, FCSS_UML_DEFAULT_LINE_LENGTH))
					options->administratorIdentifier = temporaryNumber;
			break;
			case(ADMINISTRATOR_EMAIL):
				if (fcssUmlGetStringOptionFromFile(configurationFile, temporaryEmail, index, defaultOptions, FCSS_UML_EMAIL_LENGTH))
					strncpy(options->administratorEmail, temporaryDirectory, FCSS_UML_EMAIL_LENGTH + 1);
			break;
		}
		index++;
	}

	fclose(configurationFile);
	return (OK);
}

boolean
fcssUmlGetStringOptionFromFile (FILE *configurationFile, char *temporaryString, unsigned index, char *defaultOptions[], int lineLength)
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
fcssUmlGetNumericOptionFromFile (FILE *configurationFile, unsigned *temporaryNumber, unsigned index, char *defaultOptions[], int lineLength)
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

/*FcssUmlGetFileOptions (char *fileName, fcssUmlConfigurationOptionsType *options)*/
/* $RCSfile$ */

