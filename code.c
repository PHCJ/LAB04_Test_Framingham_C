#include <stdio.h>
#include <locale.h>
#include <stdlib.h> //system()
#include <conio.h>  // getch()

void objetivoLab();
void resultado(int escore, char sexo);
char computarSexo();
int calculo(char sexo);
int computarIdade(char sexo);
int computarDiabetes(char sexo);
int computarFumo(char sexo);
int computarColesterol(char sexo);
int computarColesterolDHL(char sexo);
int computarPressao(char sexo);

int main()
{
  setlocale(LC_ALL, "Portuguese");
  //Variáveis globais
  int score;
  char sexo;
  //funções
  objetivoLab();
  sexo = computarSexo();
  score = calculo(sexo);
  resultado(score, sexo);
  getch(); // pausa no programa antes de sair
  return 0;
}

int calculo(char sexo)
{
  int result;
  result = (computarIdade(sexo));
  result += (computarDiabetes(sexo));
  result += (computarFumo(sexo));
  result += (computarColesterol(sexo));
  result += (computarColesterolDHL(sexo));
  result += (computarPressao(sexo));
  return result;
}

void objetivoLab()
{
  puts(" Calcule seu risco de infarto.");
  puts(" Obs: Use o programa apenas se você possui entre 30 e 74 anos.");
  return;
}

char computarSexo()
{
  char inf;

  do
  {
    printf(" Qual seu sexo (F/M)? ");
    scanf(" %c", &inf);
    if ((inf != 'f') && (inf != 'F') && (inf != 'm') && (inf != 'M'))
    {
      system("clear||cls");
      puts("*** Erro - Insira 'F' ou 'M' ***\n\n");
    }
  } while ((inf != 'f') && (inf != 'F') && (inf != 'm') && (inf != 'M'));

  if ((inf == 'f') || (inf == 'F'))
    inf = 'f';
  else
    inf = 'm';
  return inf;
}

void resultado(int score, char sexo)
{
  //Tabela de pontuação linhas 0 - score homem, 1 - risco DAC homem, 2 - score mulher, 3 - risco DAC mulher. Coluna relaciona score com risco.
  int i, j, tabela[4][20] = {{-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, {2, 3, 3, 4, 5, 7, 8, 10, 13, 16, 20, 25, 31, 37, 45, 53}, {-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17}, {1, 2, 2, 2, 3, 3, 4, 4, 5, 6, 7, 8, 10, 11, 13, 15, 18, 20, 24, 27}};
  if ((score < tabela[0][0]) && (sexo == 'm'))
  {
    printf(" Risco de infarto: %d%c", tabela[1][0], 37);
    puts("\n Excelente!");
  }
  else if ((score >= tabela[0][15]) && sexo == 'm')
  {
    printf(" Risco de infarto: %d%c", tabela[1][15], 37);
    puts("\n Nível crítico - peça alguem para cavar sua cova pois é capaz que seu coração pare antes de acabar");
  }
  else if ((score < tabela[2][0]) && sexo == 'f')
  {
    printf(" Risco de infarto: %d%c", tabela[3][0], 37);
    puts("\n Excelente!");
  }
  else if ((score >= tabela[2][19]) && sexo == 'f')
  {
    printf(" Risco de infarto: %d%c", tabela[3][19], 37);
    puts("\n Nível crítico - peça alguem para cavar sua cova pois é capaz que seu coração pare antes de acabar");
  }
  else if (sexo == 'f')
  {
    for (i = 2; i < 3; i++)
      for (j = 1; j < 18; j++)
        if (tabela[i][j] == score)
          printf(" Risco de infarto: %d%c", tabela[i + 1][j], 37);
  }

  else
  {
    for (i = 0; i < 1; i++)
      for (j = 1; j < 14; j++)
        if (tabela[i][j] == score)
          printf(" Risco de infarto: %d%c", tabela[i + 1][j], 37);
  }

  return;
}

int computarIdade(char sexo)
{
  int inf;
  printf(" Qual sua idade?");
  scanf("%d", &inf);
  if ((inf < 30) || (inf > 74))
  {
    system("clear||cls");
    puts("*** Idade invalida ***\n\n");
    getch(); // pausa no programa antes de sair
    exit(1);
  }
  switch (inf)
  {
  case 30 ... 34:
    if (sexo == 'm')
      inf = -1;
    else
      inf = -9;
    break;
  case 35 ... 39:
    if (sexo == 'm')
      inf = 0;
    else
      inf = -4;
    break;
  case 40 ... 44:
    if (sexo == 'm')
      inf = 1;
    else
      inf = 0;
    break;
  case 45 ... 49:
    if (sexo == 'm')
      inf = 2;
    else
      inf = 3;
    break;
  case 50 ... 54:
    if (sexo == 'm')
      inf = 3;
    else
      inf = 6;
    break;
  case 55 ... 59:
    if (sexo == 'm')
      inf = 4;
    else
      inf = 7;
    break;
  case 60 ... 64:
    if (sexo == 'm')
      inf = 5;
    else
      inf = 8;
    break;
  case 65 ... 69:
    if (sexo == 'm')
      inf = 6;
    else
      inf = 8;
    break;
  case 70 ... 74:
    if (sexo == 'm')
      inf = 7;
    else
      inf = 8;
    break;
  default:
    //O default não sera acionado podendo ser dispensado nessa ocasião
    printf("Validação de idade falhou na etapa anterior");
    break;
  }
  return inf;
}

int computarDiabetes(char sexo)
{
  char inf;

  do
  {
    printf(" Você é diabético (S/N)?");
    scanf(" %c", &inf);

    if (inf != 's' && inf != 'S' && inf != 'n' && inf != 'N')
    {
      //system("clear||cls");
      puts("*** Erro - Insira 'S' ou 'N' ***\n\n");
    }
  } while (inf != 's' && inf != 'S' && inf != 'n' && inf != 'N');

  if (sexo == 'm')
    if (inf == 's' || inf == 'S')
      inf = 2;
    else
      inf = 0;
  else if (inf == 's' || inf == 'S')
    inf = 4;
  else
    inf = 0;
  return inf;
}

int computarFumo(char sexo)
{
  char inf;

  do
  {
    printf(" Voce é fumante (S/N)?");
    scanf(" %c", &inf);
    if ((inf != 's') && (inf != 'S') && (inf != 'n') && (inf != 'N'))
    {
      system("clear||cls");
      puts("*** Erro - Insira 'S' ou 'N' ***\n\n");
    }
  } while ((inf != 's') && (inf != 'S') && (inf != 'n') && (inf != 'N'));

  if (sexo == 'm')
    if (inf == 's' || inf == 'S')
      inf = 2;
    else
      inf = 0;
  else if (inf == 's' || inf == 'S')
    inf = 2;
  else
    inf = 0;
  return inf;
}

int computarColesterol(char sexo)
{
  char inf;
  do
  {
    printf(" Indique o seu colesterol total, usando a legenda:\n a) <160\n b) 160-199\n c) 200-239\n d) 240-279\n e) >=280\n ");
    scanf(" %c", &inf);
    if (inf != 'a' && inf != 'A' && inf != 'b' && inf != 'B' && inf != 'c' && inf != 'C' && inf != 'd' && inf != 'D' && inf != 'e' && inf != 'E')
    {
      system("clear||cls");
      puts("*** Erro - Insira uma letra de 'A' a 'E' para informar o colesterol ***\n\n");
    }
  } while (inf != 'a' && inf != 'A' && inf != 'b' && inf != 'B' && inf != 'c' && inf != 'C' && inf != 'd' && inf != 'D' && inf != 'e' && inf != 'E');

  if (inf == 'a' || inf == 'A')
    inf = 'a';
  else if (inf == 'b' || inf == 'B')
    inf = 'b';
  else if (inf == 'c' || inf == 'C')
    inf = 'c';
  else if (inf == 'd' || inf == 'D')
    inf = 'd';
  else
    inf = 'e';

  switch (inf)
  {
  case 'a':
    if (sexo == 'm')
      inf = -3;
    else
      inf = -2;
    break;
  case 'b':
    if (sexo == 'm')
      inf = 0;
    else
      inf = 0;
    break;
  case 'c':
    if (sexo == 'm')
      inf = 1;
    else
      inf = 1;
    break;
  case 'd':
    if (sexo == 'm')
      inf = 2;
    else
      inf = 1;
    break;
  default:
    if (sexo == 'm')
      inf = 3;
    else
      inf = 3;
    break;
  }
  return inf;
}

int computarColesterolDHL(char sexo)
{
  char inf;
  do
  {
    printf(" Indique o seu HDL colesterol, usando a legenda:\n a) <35\n b) 35-44\n c) 45-49\n d) 50-59\n e) >=60\n ");
    scanf(" %c", &inf);
    if (inf != 'a' && inf != 'A' && inf != 'b' && inf != 'B' && inf != 'c' && inf != 'C' && inf != 'd' && inf != 'D' && inf != 'e' && inf != 'E')
    {
      system("clear||cls");
      puts("*** Erro - Insira uma letra de 'A' a 'E' para informar o colesterol ***\n\n");
    }
  } while (inf != 'a' && inf != 'A' && inf != 'b' && inf != 'B' && inf != 'c' && inf != 'C' && inf != 'd' && inf != 'D' && inf != 'e' && inf != 'E');

  if (inf == 'a' || inf == 'A')
    inf = 'a';
  else if (inf == 'b' || inf == 'B')
    inf = 'b';
  else if (inf == 'c' || inf == 'C')
    inf = 'c';
  else if (inf == 'd' || inf == 'D')
    inf = 'd';
  else
    inf = 'e';

  switch (inf)
  {
  case 'a': //HDL-C < 35
    if (sexo == 'm')
      inf = 2;
    else
      inf = 5;
    break;
  case 'b': //HDL-C 35 - 44
    if (sexo == 'm')
      inf = 1;
    else
      inf = 2;
    break;
  case 'c': //HDL-C 45 - 49
    if (sexo == 'm')
      inf = 0;
    else
      inf = 1;
    break;
  case 'd': //HDL-C 50 - 59
    if (sexo == 'm')
      inf = 0;
    else
      inf = 0;
    break;
  default: //HDL-C >=60
    if (sexo == 'm')
      inf = -1;
    else
      inf = -3;
    break;
  }
  return inf;
}

int computarPressao(char sexo)
{
  char inf;
  do
  {
    printf(" Indique o seu PAS e PAD, usando a legenda:\n     PAS    |PAD\n a) <120    |<80\n b) 120-129 |80-84\n c) 130-139 |85-89\n d) 140-159 |90-99\n e) >=160   |>=100\n ");
    scanf(" %c", &inf);
    if (inf != 'a' && inf != 'A' && inf != 'b' && inf != 'B' && inf != 'c' && inf != 'C' && inf != 'd' && inf != 'D' && inf != 'e' && inf != 'E')
    {
      system("clear||cls");
      puts("*** Erro - Insira uma letra de 'A' a 'E' para informar o colesterol ***\n\n");
    }
  } while (inf != 'a' && inf != 'A' && inf != 'b' && inf != 'B' && inf != 'c' && inf != 'C' && inf != 'd' && inf != 'D' && inf != 'e' && inf != 'E');

  if (inf == 'a' || inf == 'A')
    inf = 'a';
  else if (inf == 'b' || inf == 'B')
    inf = 'b';
  else if (inf == 'c' || inf == 'C')
    inf = 'c';
  else if (inf == 'd' || inf == 'D')
    inf = 'd';
  else
    inf = 'e';
  //Valores da pontução da pressão sistólica (PAS) e diastólica (PAD)
  switch (inf)
  {
  case 'a':
    if (sexo == 'm')
      inf = 0;
    else
      inf = -3;
    break;
  case 'b':
    if (sexo == 'm')
      inf = 0;
    else
      inf = 0;
    break;
  case 'c':
    if (sexo == 'm')
      inf = 1;
    else
      inf = 0;
    break;
  case 'd':
    if (sexo == 'm')
      inf = 2;
    else
      inf = 2;
    break;
  default:
    if (sexo == 'm')
      inf = 3;
    else
      inf = 3;
    break;
  }
  return inf;
}
