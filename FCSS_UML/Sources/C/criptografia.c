#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fcssUmlConst.h"
#include "fcssUmlErrors.h"
#include "fcssUmlTypes.h"
#include "fcssUmlFunctions.h"

fcssUmlErrorType
FcssUmlCheckPassword (char *plainPassword, char *encodedPassword);

int
main (int argc, char *argv[])
{
	char *senhaCodificada; 
	senhaCodificada = (char *) malloc( 301 * sizeof(char));
	char salt[301];
	unsigned contador = 1;
	fcssUmlCryptAlgorithms *algorithmType;

	char senha1[301];
	char senha2[301];
	// while (contador < argc)
	// {
		*algorithmType = fcssUmlDes;
		FcssUmlEncodePasswordWithSpecificAlgorithm(argv[1], *algorithmType, senhaCodificada);
		//printf("%s\n", "Depois 1");
		FcssUmlGetCryptAlgorithm (senhaCodificada, algorithmType);
		//printf("Valor: %d\n", (int)(*algorithmType));
		printf("SenhaCodificada DES: \"%s\"\n", senhaCodificada);

	// 	// sleep(2);
		*algorithmType = fcssUmlMd5;
		FcssUmlEncodePasswordWithSpecificAlgorithm(argv[1], *algorithmType, senhaCodificada);
	// 	// FcssUmlGetCryptAlgorithm (senhaCodificada, algorithmType);
		printf("Valor: %d\n", (int)(*algorithmType));
		printf("SenhaCOdificada MD5: \"%s\"\n", senhaCodificada);
	
	// 	// *algorithmType = fcssUmlSha256;
	// 	// FcssUmlEncodePasswordWithSpecificAlgorithm(argv[1], *algorithmType, &senhaCodificada);
	// 	// FcssUmlGetCryptAlgorithm (senhaCodificada, algorithmType);
	// 	// printf("Valor: %d\n", (int)(*algorithmType));
	// 	// //printf("SenhaCOdificada SHA256: \"%s\"\n", senhaCodificada);	


	// 	// *algorithmType = fcssUmlSha512;
	// 	// FcssUmlEncodePasswordWithSpecificAlgorithm(argv[1], *algorithmType, &senhaCodificada);
	// 	// FcssUmlGetCryptAlgorithm (senhaCodificada, algorithmType);
	// 	// printf("Valor: %d\n", (int)(*algorithmType));
	// 	// printf("SenhaCodificada SHA512: \"%s\"\n", senhaCodificada);



	// 	contador++;
	// }

	system("clear");

	strcpy(salt, "$5$4uEANABBI5.GQa/mo$");
	strcpy(salt, "GR");
	strcpy(salt, "$5$4uEANABBI5.GQa/mo$");
	FcssUmlEncodePasswordWithSpecificSalt(argv[1], salt, senhaCodificada);
	printf("Verdadeiro?: %d\n\n", (int) FcssUmlCheckPassword("argv[1]", senhaCodificada));
	return (0);
}



