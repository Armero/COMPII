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

#define _XOPEN_SOURCE 500
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "fcssUmlErrors.h"
#include "fcssUmlTypes.h"
#include "fcssUmlShowCliHelp.h"
#include "fcssUmlFunctions.h"


int
main (int argc, char *argv[])
{

	char optionsShortTypes[NUMBER_OF_SHORT_OPTIONS + 1];
	char filename [SIZE_FILENAME + 1];
  char *subopts;
  char *value;
  int option, command;
  fcssFunctionSelect selection = HELP;
  fcssUmlErrorType error;
  fcssUmlConfigurationOptionsType *configurationOptions;
  fcssUmlLanguageType languageChoice = fcssUmlEnglish;
  boolean endOptions = 0;

  /*Criar variaveis respectivas a cada campo opcional*/

  static struct option longOptions [FCSS_NUMBER_OF_LONG_OPTIONS + 1] =
  {
  	{"help", 0, NULL, 'h'},
  	{"Ncurse", 0, NULL, 'N'},
  	{"Configure", 0, NULL, 'c'},
  	{"add", 0, NULL, 'a'},
  	{"invite", 0, NULL, 'i'},
  	{NULL, 0, NULL, 0},
  };

  enum fcssSubOpts{
    LANGUAGE = 0,
    THE_END
  };
  char *const subOptions[] = {
    [LANGUAGE]   = "language",
    [THE_END]    = NULL
  };

  opterr = 0;

  strcpy(optionsShortTypes, FCSS_UML_SHORT_OPTIONS);

  strcpy(filename, FCSS_UML_CONFIGURATION_FILE);
	if ( (error = FcssUmlGetConfigurationOptionsValues (filename, configurationOptions)) )
	{
		/*should print something*/
		exit (error);
	}

 	while ((option = getopt_long(argc, argv, optionsShortTypes, longOptions, &command)) != -1 )
 	{
 		switch (option)
 		{
 			case 'a':
 				selection = ADD_USER;
 				/*parte que entra o add user*/
 			break;
 			case 'h':
 				selection = HELP;
        subopts = optarg;
        while ((*subopts != '\0') && (!endOptions))
 				{ 
          switch (getsubopt(&subopts, subOptions, &value))
          {
            case (LANGUAGE):
              languageChoice = FcssUmlGetLanguageIndex(value);
            break;
            default:
              endOptions = false;
          }
        }

 			break;
 			default:
 				printf("Erro!\n");
 		}
 	} 

 	switch (selection)
 	{
 		case (HELP):
 			FcssUmlShowCliHelp ( configurationOptions, languageChoice );
 		break;
    default:
    break;
 	}
	return (OK);
}


/* $RCSfile$ */