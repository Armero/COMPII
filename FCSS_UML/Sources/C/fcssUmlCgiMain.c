/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 *
 * EEL270 - Computacao II - Turma 2016/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * $Author$
 * $Date$
 * $Log$
 *
 */

#include "fcssUmlConst.h"
#include "fcssUmlTypes.h"
#include "fcssUmlErrors.h"
#include "Libraries/mlcgi.h"
#include <stdlib.h>
#include <stdio.h>

int
main (int argc, char *argv[])
{
  char stringConfigurationFileName [FCSS_UML_FILENAME_LENGTH + 1];
  char stringlanguage [FCSS_UML_LANGUAGE_NAME_MAX_LENGTH + 1];
  unsigned returnCode;
  environmentType environment;

  /*error in initialization*/
  if ((mlCgiInitialize(&environment)))
  {
    exit (ML_CGI_OK);
  }

  if (environment == commandLine)
  {
    /*Shoulf print some error message*/
    return (FCSS_UML_INVALID_CGI_ENVIRONMENT_TYPE);
  }

  if ( (returnCode = mlCgiGetFormStringNoNewLines ("configurationFile", stringConfigurationFileName, FCSS_UML_FILENAME_LENGTH + 1)) )
  {
    /*Should print some error*/
    return (ML_CGI_OK);
  }

  if ( (returnCode = mlCgiGetFormStringNoNewLines ("language", stringlanguage, FCSS_UML_FILENAME_LENGTH + 1)) )
  {
    /*Should print some error*/
    return (ML_CGI_OK);
  }
  mlCgiBeginHttpHeader ("text/html");
  mlCgiEndHttpHeader ();

  printf ("<HTML>\n");
  printf ("  <HEAD>\n");
  printf ("    <TITLE>\n");
  printf ("      Computa&ccedil;&atilde;o II - Primeiro Exemplo\n");
  printf ("    </TITLE>\n");
  printf ("  </HEAD>\n");
  printf ("  <BODY BGCOLOR=\"white\">\n");
  printf ("    <DIV ALIGN=\"center\">\n");
  printf ("      <FONT SIZE=\"+3\">\n");
  printf ("        Configuration File: %s<br>\n", stringConfigurationFileName);
  printf ("        Language: %s<br>\n", stringlanguage);
  printf ("Funciona!");
  printf ("      </FONT><BR>\n");
  printf ("      05/12/2016\n");
  printf ("    </DIV><BR>\n");
  printf ("    Fatorial de ");
  printf ("  </BODY>\n");
  printf ("</HTML>\n");


  mlCgiFreeResources ();
  exit (ML_CGI_OK);
}

/* $RCSfile$ */
