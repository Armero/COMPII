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
	if ( !(configurationFile = fopen(fileName, "r")) )
 	{
 		return (CONFIGURATION_FILE_NOT_FOUND);
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
					strncpy(options->administratorEmail, temporaryDirectory, FCSS_UML_EMAIL_LENGTH + 1);
			break;
		}
		index++;
	}

	fclose(configurationFile);
	return (OK);
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

char *cgiText[fcssUmlLanguagesAmount][FCSS_UML_CGI_MAIN_TEXTS] =
{
  {
    "Change Language",
    "Sign In",
    "Reset Password",
    "Help",
    "License",
    "Username",
    "Password",
    "Designed by: Felipe Claudio da Silva Santos",
    "Email: felipesantos956ATpoli.ufrj.br",
    "Send"
    "Uml - Initial Page",
    "Full Name",
    "Full Name Confirmation",
    "Email"
    "Email Confirmation"
  },
  {
    "Mudar Linguagem",
    "Cadastrar",
    "Resetar Senha",
    "Ajuda",
    "Licen&ccedila",
    "Nome do Usuario",
    "Senha",
    "Enviar",
    "Pagina Inicial - BGU"
    "Feito por: Felipe Claudio da Silva Santos",
    "Email: felipesantos956ARROBApoli.ufrj.br",
    "P&aacutegina Inicial",
  }
};
/*FcssUmlGetFileOptions (char *fileName, fcssUmlConfigurationOptionsType *options)*/
/* $RCSfile$ */


