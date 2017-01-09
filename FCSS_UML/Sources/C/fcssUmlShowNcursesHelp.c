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
#include "fcssUmlShowNcursesHelp.h"

void
FcssUmlShowNcursesHelp (fcssUmlConfigurationOptionsType *option, fcssUmlLanguageType language, int numberOfRows, int numberOfColumns)
{
	WINDOW *help;
	int row, column;

	char *programText[fcssUmlLanguagesAmount][FCSS_UML_TEXT_AMOUNT] =
	{
		{"Generic help text",
		},
		{
			"Texto generico de ajuda",
		}
	};	


	row = 2;
	column = 3;
	help = newwin (numberOfRows, numberOfColumns, 0, 0);
	wbkgd(help, COLOR_PAIR(1));
	box(help, 0, 0);
	mvwprintw(help, row, column, "%s", programText[language][0]);
	wrefresh(help);
	getch();
	delwin(help);
	/*to complete*/
}

/* $RCSfile$ */
