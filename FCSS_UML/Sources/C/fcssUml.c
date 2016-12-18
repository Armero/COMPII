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
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include "fcssUmlErrors.h"
#include "fcssUmlTypes.h"
#include "fcssUmlShowCliHelp.h"
#include "fcssUmlFunctions.h"
#include "fcssUmlRunNcursesInterface.h"


int
main (int argc, char *argv[])
{

	char optionsShortTypes[FCSS_UML_NUMBER_OF_SHORT_OPTIONS + 1];
	char filename [FCSS_UML_SIZE_FILENAME + 1];
  char *subopts = NULL;
  char *value = NULL;
  int option, command;
  fcssFunctionSelect selection = HELP;
  fcssUmlErrorType error;
  fcssUmlConfigurationOptionsType *configurationOptions;
  fcssUmlLanguageType languageChoice = fcssUmlEnglish;
  boolean endOptions = 0;


  static struct option longOptions [] =
  {
    {"help", 0 , NULL, 'h'},
    {"Ncurses", 0 , NULL, 'N'},
  	{"Configure", 0, NULL, 'c'},
  	{"add", 0, NULL, 'a'},
  	{"invite", 0, NULL, 'i'},
  	{NULL, 0, NULL, 0}
  };

  enum fcssSubOpts{
    LANGUAGE = 0,
    NCURSES  = 1,
    THE_END
  };

  char *const subOptions[] = 
  {
    [LANGUAGE]   = "language",
    NULL
  };

  opterr = 0;

  strcpy(optionsShortTypes, FCSS_UML_SHORT_OPTIONS);
  strcpy(filename, FCSS_UML_CONFIGURATION_FILE);

	// if ( (error = FcssUmlGetConfigurationOptionsValues (filename, configurationOptions)) )
	// {
	// 	/*should print something*/
	// 	exit (error);
	// }

 	while ((option = getopt_long(argc, argv, optionsShortTypes, longOptions, &command)) != -1 )
 	{
    printf("option: %c\n", option);
 		switch (option)
 		{
 			case 'a':
 				selection = ADD_USER;
 			break;
 			case 'h':
 				selection = HELP;
        subopts = argv[optind];
        /* transform this block below in an auxiliary function*/
        printf("subopts: %s\n", subopts);

        if (subopts)
        while ((*subopts != '\0') && (!endOptions))
 				{ 
          switch (getsubopt(&subopts, subOptions, &value))
          {
            case (LANGUAGE):
              languageChoice = FcssUmlGetLanguageIndex(value);
            break;
            default:
              endOptions = true;
          }
        }

      /* transform this block above in an auxiliary function*/
      break;
      case 'N':
        selection = NCURSES;
        subopts = optarg;
        printf("subopts: %s\n", subopts);
        if (subopts)
        while ((*subopts != '\0') && (!endOptions))
        { 
          switch (getsubopt(&subopts, subOptions, &value))
          {
            case (LANGUAGE):
              languageChoice = FcssUmlGetLanguageIndex(value);
            break;
            default:
              endOptions = true;
          }
        }
 			break;

 			default:
 				endOptions = true;
 		}
 	} 

 	switch (selection)
 	{
 		case (HELP):
 			FcssUmlShowCliHelp ( configurationOptions, languageChoice );
 		break;
    case (NCURSES):
      fcssUmlRunNcursesInterface (configurationOptions, "Felipe", languageChoice);
    break;
    default:
    break;
 	}
	return (OK);
}


/* $RCSfile$ */