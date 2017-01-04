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

#include "fcssUmlTypes.h"
#include "fcssUmlErrors.h"
#include "fcssUmlShowCliHelp.h"
#include "fcssUmlFunctions.h"
#include "fcssUmlRunNcursesInterface.h"
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <sys/types.h>



int
main (int argc, char *argv[])
{

	char optionsShortTypes[FCSS_UML_NUMBER_OF_SHORT_OPTIONS + 1];
  char *subopts = NULL;
  char *value = NULL;
  int option, command;
  fcssFunctionSelect selection = HELP;
  fcssUmlErrorType error;
  fcssUmlConfigurationOptionsType *configurationOptions;
  fcssUmlLanguageType languageChoice = fcssUmlEnglish;
  fcssUmlUserDataType user;
  boolean endOptions = 0;
  char fcssUmlConfigurationFileName[FCSS_UML_FILENAME_LENGTH + 1];
  char *bufferPassword;


  static struct option longOptions [] =
  {
    {"help", 0 , NULL, 'h'},
    {"Ncurses", 0 , NULL, 'N'},
  	{"Configure", 0, NULL, 'C'},
  	{"add", 0, NULL, 'a'},
  	{"invite", 0, NULL, 'i'},
  	{NULL, 0, NULL, 0}
  };

  enum fcssSubOpts{
    LANGUAGE = 0,
    USERNAME = 1,
    CONFIRM_USERNAME = 2,
    EMAIL = 3,
    CONFIRM_EMAIL = 4,
    THE_END
  };

  char *const subOptions[] = 
  {
    [LANGUAGE]  = "language",
    [USERNAME]  = "username",
    [CONFIRM_USERNAME]  = "confirm-username",
    [EMAIL]  = "email",
    [CONFIRM_EMAIL] = "confirm-email",
    NULL
  };

  opterr = 0;

  strcpy(optionsShortTypes, FCSS_UML_SHORT_OPTIONS);
  strcpy(fcssUmlConfigurationFileName, FCSS_UML_CONFIGURATION_FILE);

	// if ( (error = FcssUmlGetConfigurationOptionsValues (filename, configurationOptions)) )
	// {
	// 	/*should print something*/
	// 	exit (error);
	// }

  configurationOptions = malloc(sizeof(fcssUmlConfigurationOptionsType));
  if (FcssUmlGetConfigurationOptionsValues (fcssUmlConfigurationFileName, configurationOptions))
  {
    /*error*/
  }

  printf("root dir: %s\n",configurationOptions->rootDirectory);
  printf("data dir: %s\n",configurationOptions->dataDirectory);
  printf("cookies dir: %s\n",configurationOptions->cookiesDirectory);
  printf("admin id dir: %llu\n",configurationOptions->administratorIdentifier);
  printf("adminEmail dir: %s\n",configurationOptions->administratorEmail);
  printf("privateRootDirectory dir: %s\n",configurationOptions->privateRootDirectory);
  printf("usersDataFileName dir: %s\n",configurationOptions->usersDataFileName);
  printf("invitedUsersDataFileName dir: %s\n",configurationOptions->invitedUsersDataFileName);
  printf("requestingUsersDataFilename dir: %s\n",configurationOptions->requestingUsersDataFilename);
  printf("lockedUsersDataFileName dir: %s\n",configurationOptions->lockedUsersDataFileName);

  user.identifier = 0;
  user.nickName[0] = EOS;
  user.password[0] = EOS;
  user.passwordConfirmation[0] = EOS;
  user.profileType = 0;
  user.fullName[0] = EOS;
  user.fullNameConfirmation[0] = EOS;
  user.email[0] = EOS;
  user.emailConfirmation[0] = EOS;
  user.previous = NULL;
  user.next = NULL;

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
        {
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
            subopts++;
          }
        }
      /* transform this block above in an auxiliary function*/
      break;
      case 'N':
        selection = NCURSES;
        subopts = argv[optind];
        printf("subopts: %s\n", subopts);
        if (subopts)
        {
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
            subopts++;
          }
        }
 			break;

      case 'C':
        selection = CONFIGURE;
        subopts = argv[optind];
        printf("subopts: %s\n", subopts);
        if (subopts)
        {
          while ((*subopts != '\0') && (!endOptions))
          { 
            switch (getsubopt(&subopts, subOptions, &value))
            {
              case (LANGUAGE):
                languageChoice = FcssUmlGetLanguageIndex(value);
              break;
              case (USERNAME):
                strcpy(user.fullName, value);
              break;
              case (CONFIRM_USERNAME):
                strcpy(user.fullNameConfirmation, value);
              break;
              case (EMAIL):
                strcpy(user.email, value);
              break;
              case (CONFIRM_EMAIL):
                strcpy(user.emailConfirmation, value);
              break;                                                
              default:
                endOptions = true;
            }
            subopts++;
          }
        }
      break;
 			default:
 				endOptions = true;
 		}
 	} 

  printf("\n\n\n");
  printf("user.username: %s\n", user.fullName);
  printf("user.usernameConfirmation: %s\n", user.fullNameConfirmation);
  printf("user.email: %s\n", user.email);
  printf("user.emailConfirmation: %s\n", user.emailConfirmation);

  /*Must be inside fcssUmlAddUser*/
  if ( ((fcssUmlUserIdentifierType) getuid()) == configurationOptions->administratorIdentifier)
  {
      bufferPassword = getpass ("password: ");
      strcpy (user.password, bufferPassword);
      memset (bufferPassword, 0x00, strlen (bufferPassword));
      printf("user.password: %s\n", user.password);

      bufferPassword = getpass ("password confirmation: ");
      strcpy (user.passwordConfirmation, bufferPassword);
      memset (bufferPassword, 0x00, strlen (bufferPassword));
      printf("user.password: %s\n", user.passwordConfirmation);
  }
  /*Must be inside fcssUmlAddUser*/

 	switch (selection)
 	{
 		case (HELP):
 			FcssUmlShowCliHelp ( configurationOptions, languageChoice );
 		break; 
    case (NCURSES):
      FcssUmlRunNcursesInterface (configurationOptions, "Felipe", languageChoice);
    break;
    default:
    break;
 	}
	return (FCSS_UML_OK);
}


/* $RCSfile$ */