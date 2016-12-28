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

#include "fcssUmlNcursesFunctions.h"

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


