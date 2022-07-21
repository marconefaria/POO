#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  FILE *arq;
  char *result;
  int cont=0;
  char c;
  // Abre um arquivo TEXTO para LEITURA
  arq = fopen("file.txt", "a+");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return 1;
  }

  while (!feof(arq))
  {
	// Lê uma linha (inclusive com o '\n')
	if((c = fgetc(arq)) !=EOF)
        if(c == ' ')
            cont++;
  }
  fclose(arq);
  cout << cont;
  return 0;
}
