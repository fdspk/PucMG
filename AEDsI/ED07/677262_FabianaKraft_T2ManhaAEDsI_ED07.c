#include "io.h"

/**
ED07 - AED1 T2 Manhã
Fabiana Kraft
677262
*/

/*
Metodo 0 - parar switch case
*/

void metodo0 ()
{
}


/*
writeInts + Metodo 1 - Exemplo01
Objetivos: writeInts - Gravar em arquivo texto certa quantidade de valores.
              @param fileName - nome do arquivo
              @param x - quantidade de valores
Testes:OK
*/

void writeInts ( chars fileName, int x )
{
// definir dados
   FILE* arquivo = fopen ( fileName, "wt" );
   int y = 0;
// repetir para a quantidade de dados
   for ( y = 1; y <= x; y = y + 1 )
   {
   // gravar valor
      fprintf ( arquivo, "%d\n", y );
   } // fim repetir
// fechar arquivo (INDISPENSAVEL para gravacao)
   fclose ( arquivo );
} // fim writeInts ( )


void metodo1 ()
{
//identificar
   IO_id("EXEMPLO0701 - Metodo1 - v0.0");
   
   // executar o metodo auxiliar
   writeInts ( "DADOS1.TXT", 10 );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo1

/*
readInts + Metodo 2 - Exemplo02
Objetivos: readInts - Ler de arquivo texto certa quantidade de valores.
              @param fileName - nome do arquivo
              @param x - quantidade de valores
Testes:ok
*/

void readInts ( chars fileName )
{
// definir dados
   FILE* arquivo = fopen ( fileName, "rt" );
   int x = 0;
// tentar ler o primeiro
   fscanf ( arquivo, "%d", &x );
// repetir enquanto houver dados
   while ( ! feof ( arquivo ) )
   {
   // mostrar valor
      printf ( "%d\n", x );
   // tentar ler o proximo
      fscanf ( arquivo, "%d", &x );
   } // fim repetir
// fechar arquivo (RECOMENDAVEL para leitura)
   fclose ( arquivo );
} // fim readInts ( )


void metodo2 ()
{
//identificar
   IO_id("EXEMPLO0702 - Metodo2 - v0.0");
   
   // executar o metodo auxiliar
   readInts ( "DADOS1.TXT" );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo2

/*
writeDoubles + Metodo 3 - Exemplo03
Objetivos: writeDoubles - Gravar em arquivo texto certa quantidade de valores.
              @param fileName - nome do arquivo
              @param x - quantidade de valores
Testes: OK
*/
void writeDoubles ( chars fileName, int x )
{
// definir dados
   FILE* arquivo = fopen ( fileName, "wt" );
   int y = 0;
// gravar quantidade de valores
   IO_fprintf ( arquivo, "%d\n", x );
// repetir para a quantidade de dados
   for ( y = 1; y <= x; y = y + 1 )
   {
   // gravar valor
      IO_fprintf ( arquivo, "%lf\n", (0.1*y) );
   } // fim repetir
// fechar arquivo (INDISPENSAVEL para gravacao)
   fclose ( arquivo );
} // fim writeDoubles ( )

void metodo3 ()
{
//identificar
   IO_id("EXEMPLO0703 - Metodo3 - v0.0");
   
   // executar o metodo auxiliar
   writeDoubles ( "DADOS2.TXT", 10 );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo3

/*
readDoubles + Metodo 4 - Exemplo04
Objetivos: readDoubles - Ler de arquivo texto certa quantidade de valores.
              @param fileName - nome do arquivo
              @param x - quantidade de valores
Testes: OK
*/

void readDoubles ( chars fileName )
{
// definir dados
   FILE* arquivo = fopen ( fileName, "rt" );
   int x = 0 ;
   int y = 1 ;
   double z = 0.0;
// tentar ler a quantidade de dados
   fscanf ( arquivo, "%d", &x );
// repetir enquanto houver dados e
// quantidade nao tiver sido alcancada
   while ( ! feof ( arquivo ) && y <= x )
   {
   // tentar ler
      fscanf ( arquivo, "%lf", &z );
   // mostrar valor
      printf ( "%2d: %lf\n", y, z );
   // passar ao proximo
      y = y + 1;
   } // fim repetir
// fechar arquivo (RECOMENDAVEL para leitura)
   fclose ( arquivo );
} // fim readDoubles ( )

void metodo4 ()
{
//identificar
   IO_id("EXEMPLO0704 - Metodo4 - v0.0");
   
   // executar o metodo auxiliar
   readDoubles ( "DADOS2.TXT" );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo4

/*
writeText + Metodo 5 - Exemplo05
Objetivos: writeText - Gravar em arquivo texto certa quantidade de valores.
              @param fileName - nome do arquivo
              @param x - quantidade de valores
Testes:ok
*/

void writeText ( chars fileName )
{
// definir dados
   FILE* arquivo = fopen ( fileName, "wt" );
   chars linha = IO_new_chars ( STR_SIZE );
// repetir ate' desejar parar
   printf("Gravar linhas (para terminar, entrar com \"PARAR\"): \n" );
   do
   {
   // ler do teclado
      strcpy ( linha, IO_readln ( "" ) );
                                      //scanf("%s", linha);
   // gravar valor
      fprintf (arquivo, "%s\n", linha);
                                      //IO_fprintf ( arquivo, "%s\n", linha );
   }
   while ( strcmp ( "PARAR", linha ) != 0 );
// fechar arquivo (INDISPENSAVEL para gravacao)
   fclose ( arquivo );
} // fim writeText ( )


void metodo5 ()
{
//identificar
   IO_id("EXEMPLO0705 - Metodo5 - v0.0");
   
   // executar o metodo auxiliar
   writeText ( "DADOS3.TXT" );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo5

/*
readText + Metodo 6 - Exemplo06
Objetivos: readText - Ler de arquivo texto certa quantidade de valores.
              @param fileName - nome do arquivo
Testes:ok
*/

void readText ( chars fileName )
{
// definir dados
   FILE* arquivo = fopen ( fileName, "rt" );
   chars linha = IO_new_chars ( STR_SIZE );
// tentar ler o primeiro
   strcpy ( linha, IO_freadln ( arquivo ) );
                                                //fscanf(arquivo, "%s", linha);
// repetir enquanto houver dados
   while ( ! feof (arquivo) &&
   strcmp ( "PARAR", linha ) != 0 )
   {
   // mostrar valor
      printf ( "%s\n", linha );
   // tentar ler o proximo
      strcpy ( linha, IO_freadln ( arquivo ) );
                                                   //fscanf(arquivo, "%s", linha);
   } // fim repetir
// fechar arquivo (RECOMENDAVEL para leitura)
   fclose ( arquivo );
} // fim readText ( )

void metodo6 ()
{
//identificar
   IO_id("EXEMPLO0706 - Metodo6 - v0.0");
   
   // executar o metodo auxiliar
   readText ( "DADOS3.TXT" );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo6

/*
copyText + Metodo 7 - Exemplo07
Objetivos: copyText - Copiar arquivo texto.
              @param fileOut - nome do arquivo de saida (destino)
              @param fileIn - nome do arquivo de entrada (origem )
Testes: alterar posicao do contador para dentro do if ou colocar contador-1 no printf - ok
*/

void copyText ( chars fileOut, chars fileIn )
{
// definir dados
   FILE* saida = fopen ( fileOut, "wt" );
   FILE* entrada = fopen ( fileIn , "rt" );
   chars linha = IO_new_chars ( STR_SIZE );
   int contador = 0;
// ler da origem
   strcpy ( linha, IO_freadln ( entrada ) );
// repetir enquanto houver dados
   while ( ! feof ( entrada ) )
   {
   
   // gravar no destino,
   // EXCEPCIONALMENTE sem a ultima linha, nesse caso
      if ( strcmp ( "PARAR", linha ) != 0 )
      {
         IO_fprintln ( saida, linha );
                                     // fprintf( saida, "%s\n", linha);
                                     // contar linha lida
         contador = contador + 1;
         
      
      } // fim se
      // ler da origem
      strcpy ( linha, IO_freadln ( entrada ) );
                                      // fscanf (entrada, "%s", linha);
   
   } // fim repetir
// informar total de linhas copiadas
   IO_printf ( "Lines read = %d\n", contador );
// fechar arquivos
   fclose ( saida );
   fclose ( entrada );
} // fim copyText ( )

void metodo7 ()
{
//identificar
   IO_id("EXEMPLO0707 - Metodo7 - v0.0");
   
   // executar o metodo auxiliar
   copyText ( "DADOS4.TXT", "DADOS3.TXT" );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo7

/*
appendText + Metodo 8 - Exemplo08
Objetivos: appendText - Gravar em arquivo texto certa quantidade de valores (adiciona "at").
              @param fileName - nome do arquivo
              @param x - quantidade de valores
Testes:ok
*/
void appendText ( chars fileName )
{
// definir dados
   FILE* arquivo = fopen ( fileName, "at" );
   chars linha = IO_new_chars ( STR_SIZE );
// repetir ate' desejar parar
   IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" );
   do
   {
   // ler do teclado
      strcpy ( linha, IO_readln ( "" ) );
   // gravar valor
      IO_fprintln ( arquivo, linha );
   }
   while ( strcmp ( "PARAR", linha ) != 0 );
// fechar arquivo (INDISPENSAVEL para gravacao)
   fclose ( arquivo );
} // fim appendText ( )

void metodo8 ()
{
//identificar
   IO_id("EXEMPLO0708 - Metodo8 - v0.0");
   
  // executar o metodo auxiliar
   appendText ( "DADOS4.TXT" ); 

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo8

/*
readWords + Metodo 9 - Exemplo09
Objetivos: readWords - Ler palavras de arquivo.
                @param fileName - nome do arquivo
Testes: adicionei o condicional pois o arquivo contem adicao no ultimo item, logo estava parando de mostrar no primeio "PARAR" - ok
*/

void readWords ( chars fileName )
{
// definir dados
   FILE* arquivo = fopen ( fileName, "rt" );
   chars linha = IO_new_chars ( STR_SIZE );
// tentar ler a primeira
   strcpy ( linha, IO_fread ( arquivo ) );
// repetir enquanto houver dados
   while ( ! feof (arquivo) ) 
   {
      if (strcmp ( "PARAR", linha ) != 0)
      {
      // mostrar valor
         printf ( "%s\n", linha );
      } // fim if
   // tentar ler o proximo
      strcpy ( linha, IO_fread ( arquivo ) );
   } // fim repetir
// fechar arquivo (RECOMENDAVEL para leitura)
   fclose ( arquivo );
} // fim readWords ( )

void metodo9 ()
{
//identificar
   IO_id("EXEMPLO0709 - Metodo9 - v0.0");
   
   // executar o metodo auxiliar
   readWords ( "DADOS4.TXT" );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo9

/*
Metodo 10 - Exemplo10
Objetivos: searchWord - Procurar palavra em arquivo.
                  @return true (!=0), se encontrar; false (0), caso contrario
                  @param fileName - nome do arquivo
                  @param word - palavra a procurar
Testes:
*/

bool searchWord ( chars fileName, chars word )
{
// definir dados
   FILE* arquivo = fopen ( fileName, "rt" );
   chars linha = IO_new_chars ( STR_SIZE );
// tentar ler a primeira
   strcpy ( linha, IO_fread ( arquivo ) );
// repetir enquanto houver dados
   while ( ! feof (arquivo) &&
   strcmp ( word, linha ) != 0 )
   {
   // tentar ler o proximo
      strcpy ( linha, IO_fread ( arquivo ) );
   } // fim repetir
// fechar arquivo (RECOMENDAVEL para leitura)
   fclose ( arquivo );
// retornar resultado
   return ( strcmp ( word, linha ) == 0 );
} // fim searchdWord ( )


void metodo10 ()
{
//identificar
   IO_id("EXEMPLO0710 - Metodo10 - v0.0");
   
   // procurar palavra
   IO_printf ( "Procurar (\"%s\") = %d\n", "pqr", searchWord ( "DADOS4.TXT", "pqr" ) );
   IO_printf ( "Procurar (\"%s\") = %d\n", "pqs", searchWord ( "DADOS4.TXT", "pqs" ) );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo10

/*
Metodo 11 - Exemplo11
Objetivos: método para ler um valor inteiro do teclado e
               gravar essa quantidade em múltiplos de 5, ímpares, em ordem crescente, começando em 5.
Testes: 5 ok, 10 ok, -1 ok, 0 ok
Obs: tive que por o fscanf pra ler o primeiro valor e dps printf+fscanf dentro do do/while -> se poe fscanf+printf ele printa o ultimo 2x
*/

void cincoimparesw (char* FileName, int q)
{

//definir dados
   int x=0;
   int y =1;
// abrir arquivo para gravação
   FILE* arquivo = fopen(FileName, "wt");

// gravar
   for (x=1; x<=q; x++)
   {
      fprintf( arquivo, "%d\n", 5*y);
      y=y+2;
   }// fim for

//fechar arquivo
   fclose (arquivo);
}// fim cincoimparesw

void lerarqint (char* FileName)
{
//declarar variaveis internas
   int x=0;
// abrir arquivo
   FILE* arquivo = fopen (FileName, "rt");
// ler o primeiro valor
   fscanf(arquivo, "%d", &x);
//ler do arquivo
   do
   {
      printf("%d\n", x);
      fscanf(arquivo, "%d", &x);
   }// fim do
   while (!feof(arquivo));

//fechar arquivo
   fclose (arquivo);
}
void metodo11 ()
{
//identificar
   IO_id("EXEMPLO0711 - Metodo11 - v0.1");
   // dados
   int x =0;
   //input  
   while (x<=0)
   {
      printf("\n Favor inserir uma quantidade: ");
      scanf("%d", &x);
      if ( x<=0)
      {
         printf ("\n ERRO: Numero menor ou igual a zero");
      }// fim if
   }// fim while
   cincoimparesw( "DADOS11.TXT", x);
   lerarqint( "DADOS11.TXT" ); 

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo11

/*
Metodo 12 - Exemplo12
Objetivos: método para ler um valor inteiro do teclado e
              gravar essa quantidade em múltiplos de 5, pares , em ordem decrescente encerrando em 5.
Testes: 10 ok, 7 ok, -1 ok, 0 ok.
*/

void cincopares (char* filename, int q)
{
//dados internos
   int y=0;

//abrir arquivo para gravação
   FILE* arq = fopen (filename, "wt");

//gravar
   for (y=q; y>=2; y--)
   {
      fprintf(arq, "%d\n", 10*(y-1));
   }// fim for
   y=5;
   fprintf(arq, "%d\n", y);  // se nao por /n ou /t ou espaço dps ele nao vai printar no lerarqint!

//fechar arquivo
   fclose(arq);
}//fim cincopares

void metodo12 ()
{
//identificar
   IO_id("EXEMPLO0712 - Metodo12 - v0.0");
 // variaveis
   int x =0;
   //input  
   while (x<=0)
   {
      printf("\n Favor inserir uma quantidade: ");
      scanf("%d", &x);
      if ( x<=0)
      {
         printf ("\n ERRO: Numero menor ou igual a zero");
      }// fim if
   }// fim while
   
   cincopares("DADOS12.txt", x);
   lerarqint ("DADOS12.txt");   

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo12

/*
Metodo 13 - Exemplo13
Objetivos: ler um valor inteiro do teclado e gravar essa quantidade em valores da sequência: 1 5 25 125 625 ...
Testes:ok
*/

void quadradocinco (char* nomearq, int x)
{
   int y=0;

//abrir para gravar
   FILE* arquivo = fopen (nomearq, "wt");

// gravar
   for (y=0; y<x; y++)
   {
      fprintf(arquivo, "%d\n", (int)round(pow(5,y)));  //round arredonda pro mais prox pq senao fica valor arredondado pra baixo
   
   }// fim for

//fechar arquivo
   fclose (arquivo);
}// fim quadradocinco

void metodo13 ()
{
//identificar
   IO_id("EXEMPLO0713 - Metodo13 - v0.1");
   // variaveis
   int x =0;
   //input  
   while (x<=0)
   {
      printf("\n Favor inserir uma quantidade: ");
      scanf("%d", &x);
      if ( x<=0)
      {
         printf ("\n ERRO: Numero menor ou igual a zero");
      }// fim if
   }// fim while
   
   //arquivo
   quadradocinco("DADOS13.TXT", x);
   lerarqint("DADOS13.TXT");

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo13

/*
Metodo 14 - Exemplo14
Objetivos: ler um valor inteiro do teclado e
              gravar essa quantidade em valores decrescentes da sequência: ... 1/625 1/125 1/25 1/5 1.
Testes:5 ok, 10 ok, -1 ok, 0 ok
*/

void qcdi (char* filename, int x)
{
//variaveis
   int y=0;
//abrir arq
   FILE*arq=fopen(filename, "wt");
//gravar
   for(y=x; y>1; y--)
   {
      fprintf(arq, "1/%d\n", (int)round(pow(5,y-1)));
   }//fim for
   fprintf(arq, "%d\n", 1);
//fechar arq
   fclose(arq);
}// fim qcdi

void lertexto (char*filename)
{
//variaveis
   char* texto = (char*)malloc(80*sizeof(char));
   texto[0]='\0';

//abrir arquivo
   FILE*arq = fopen(filename, "rt");

//ler primeiro
   fscanf(arq, "%s", texto);

//ler o resto
   while (!feof(arq))
   {
      printf("%s\n", texto);
      fscanf(arq, "%s", texto);
   }//fim while

//fechar arquivo
   fclose(arq);
}

void metodo14 ()
{
//identificar
   IO_id("EXEMPLO0714 - Metodo14 - v0.0");
   // variaveis
   int x =0;
   //input  
   while (x<=0)
   {
      printf("\n Favor inserir uma quantidade: ");
      scanf("%d", &x);
      if ( x<=0)
      {
         printf ("\n ERRO: Numero menor ou igual a zero");
      }// fim if
   }// fim while
   
   //arquivo
   qcdi ("DADOS14.TXT", x);
   lertexto("DADOS14.TXT");   

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo14

/*
Metodo 15 - Exemplo15
Objetivos: ler um valor inteiro do teclado (n) e outro valor real (x),
              gravar essa quantidade (n) em valores reais da sequência: 1 1/x 1/x3 1/x5 ...
Testes:ok
*/

void sip (char* filename, int q, double j)
{
//variaveis internas
   int x=0;
//abrir arquivo para gravar
   FILE*arquivo =fopen (filename, "wt");
//gravar primeiro valor
   fprintf(arquivo, "%lf\n", pow(j,0));
//gravar
   int e = 1;
   for (x=2; x<=q; x++)
   {
      fprintf(arquivo, "%lf\n", 1.0/pow(j, e));
      e=e+2;
   }//fim for
   
//fechar arquivo
   fclose(arquivo);
}// fim sip

void lerdoub (char* filename)
{
//variavel double
   double k =0;
//abrir arquivo para leitura
   FILE* arq = fopen (filename, "rt");
//ler primeiro
   fscanf(arq, "%lf", &k);
//ler
   while (!feof(arq))
   {
      printf("%lf\n", k);
      fscanf(arq, "%lf", &k);
   }//fim while
//fechar
   fclose(arq);
}// fim lerdoub

void metodo15 ()
{
//identificar
   IO_id("EXEMPLO0715 - Metodo15 - v0.0");
     // variaveis
   int x =0;
   double z =0;
   //input  
   while (x<=0)
   {
      printf("\n Favor inserir uma quantidade: ");
      scanf("%d", &x);
      if ( x<=0)
      {
         printf ("\n ERRO: Numero menor ou igual a zero");
      }// fim if
   }// fim while
   printf("\n Inserir valor real: ");
   scanf("%lf", &z);
   
   //arq
   sip("DADOS15.TXT",   x, z);
   lerdoub("DADOS15.TXT");

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo15

/*
Metodo 16 - Exemplo16
Objetivos: função para ler um valor inteiro do teclado e
           calcular a soma dessa quantidade dentre os primeiros valores gravados no exercício anterior.
            Testar essa função para quantidades diferentes.
           Gravar em outro arquivo ("RESULTADO06.TXT") cada quantidade e seu resultado.
   Testes:ok
*/
int fcont (char*filename)
{
//testar se existe
   if (filename == NULL)
   {
      printf("Arquivo nao existe");
      IO_pause("Apertar enter para continuar");
   }//fim if
   //abrir arquivo para leitura
   FILE* arq = fopen(filename, "rt");
  //variaveis
   int contador=-1;
   char* linha= (char*)malloc(80*sizeof(char));
   linha[0]='\0';
  //linhas arquivo
   while (!feof (arq))
   {
      fscanf(arq, "%s", linha);
      contador++;
   }//fim while
   //fechar arquivo
   fclose(arq);
   return(contador);
}

double func16 (char* filename, int x)
{
 //abrir arquivo para leitura
   FILE* arq = fopen(filename, "rt");
   if (arq == NULL)
   {
      printf("Arquivo nao existe");
      IO_pause("Apertar enter para continuar");
   }//fim if
   else
   {
   //linhas arquivo
      int contador=fcont(filename);
   // testar   
      if (x>contador)
      {
         printf("\nO numero inserido (%d) ultrapassa o numero de linhas do arquivo (%d)", x, contador);
         IO_pause("Aperte enter para retornar");
      }//fim if
      else
      {
      //variaveis
         int y=0;
         double k =0.0;
         double soma=0.0;
         for (y=1; y<=x; y++)
         {
            fscanf(arq, "%lf", &k);   
            soma= (soma + k);
            printf("%lf  %lf\n", k, soma);
         }//fim for
      //criar arquivo para gravar
         FILE*saida = fopen("RESULTADO06.TXT", "at");
      //gravar
         fprintf(saida, "%d\t%lf\n", x, soma);
      //fechar arquivos
         fclose(arq);
         fclose(saida);
      
         return(soma); 
      }//fim else      
   }//fim else
}

void metodo16 ()
{
//identificar
   IO_id("EXEMPLO0716 - Metodo16 - v0.0");
  // variaveis
   int x =0;
   
   //input  
   while (x<=0)
   {
      printf("\n Favor inserir uma quantidade: ");
      scanf("%d", &x);
      if ( x<=0)
      {
         printf ("\n ERRO: Numero menor ou igual a zero");
      }// fim if
      
   }// fim while
   
   
//funcao
   printf("A soma = %lf", func16("DADOS15.TXT", x));
//terminar
   IO_pause("Apertar enter para continuar");
   
}// fim metodo16

/*
Metodo 17 - Exemplo17
Objetivos: função para
ler um valor inteiro do teclado e
calcular a soma dessa quantidade dentre os inversos das potências de 5 do exercício 04 acima.
Gravar em outro arquivo ("RESULTADO07.TXT") cada quantidade e seu resultado.
Testes: adicao de condicional, pois quando string chega no =1, nao tem 1/1, pega direto
ok
*/

double divisaoesoma (char* filename, int x)
{
//abrir arquivo para leitura
   FILE*arq=fopen(filename,"rt");

//testar se existe
   if (arq==NULL)
   {
      printf("\n Arquivo nao encontrado!");
   }//fim if
   else
   {
   //contar linhas do arquivo
      int contador= fcont(filename);
      
   //controle da variavel
      if(x>contador)
      {
         printf("\n Valor de quantidade (%d) maior que numero de linhas do arquivo (%d)", x, contador);
      }
      else
      {
      //fazer operação da linha
         int i=0;
         int j=0;
         double soma = 0.0;
         double stod =0.0;
         char* get= (char*)malloc(80*sizeof(char));
         get[0]='\0';
         char* convert=(char*)malloc(80*sizeof(char));
         convert[0]='\0';
      //pegar linhas do arquivo
         for (i=1; i<=x; i++)
         {
            fscanf(arq, "%s", get);
         //controle1
            printf("\nstring: %s\t", get);
         
         // para valores diferentes do 1 (o resto e 1/alguma coisa)
            if (strcmp("1", get)!=0)
            {
            //copiar para dentro da string convert o valor posterior da divisão
               for (j=2; j<strlen(get); j++)
               {
                  convert[j-2]=get[j];
                  convert[j-1]='\0';
               }//fim for
            }//fim if
            else
            {
            //copia quando chega no 1
               strcpy(convert, get);
            }// fim else
         //controle2
            printf("convertida em %s\t", convert);
         
         //transformar valor a ser dividido em double-> funcao atof (string to float)
            stod= (double)atof(convert);
         
         //controle 3
            printf("\n em double %lf\t", stod);
            stod=1.0/stod;
         
         //controle 4
            printf("cujo inverso e %lf\t", stod);
         
            soma=soma+stod;   
         
         //controle5
            printf("e a soma = %lf\n", soma);
         }//fim for
      
      //gravar em arquivo
         FILE*saida = fopen("RESULTADO07.TXT", "at");
      
      //gravar
         fprintf(saida, "%d\t%lf\n", x, soma);
      
      //fechar todos arquivos
         fclose(arq);
         fclose(saida);
      }//fim else2
   }//fim else1
}//fim divisaoesoma

void metodo17 ()
{
//identificar
   IO_id("EXEMPLO0717 - Metodo17 - v0.1");
   
   // variaveis
   int x =0;
   
   //input  
   while (x<=0)
   {
      printf("\n Favor inserir uma quantidade: ");
      scanf("%d", &x);
      if ( x<=0)
      {
         printf ("\n ERRO: Numero menor ou igual a zero");
      }// fim if
      
   }// fim while
   
   //funcao
   divisaoesoma("DADOS14.TXT", x);

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo17

/*
Metodo 18 - Exemplo18
Objetivos: função para
ler um valor inteiro do teclado e
gravar o valor correspondente aos primeiros termos ímpares da série de Fibonacci.
Gravar em outro arquivo ("RESULTADO08.TXT") cada quantidade e seu resultado.
Testes:
*/

int fibonacci( int x)
{
   int termo=0;

   if (x==1 || x==2)
   {
      termo=1;
   }//fim if
   else
   {
      termo=fibonacci(x-1)+fibonacci(x-2);
   
   }//fim else
   return (termo);
}//fim fibonacci

void fibimp (int x)
{
   int i=0;
   int f=0;
   //abrir arquivo para gravar
   FILE*arq=fopen("RESULTADO08.TXT", "at");
   //gravar quantidade
   fprintf(arq, "\n%d)\t", x);
   //gravar
   for (i=1; i<=x; i++)
   {
   //pegar o termo da sequencia
      f=fibonacci(i);
      //testar se e impar
      if (f%2==1)
      {
         fprintf(arq, "%d\t", f);
      }//fim if
   }//fim for
//fechar
   fclose(arq);
}//fim fibimp

void metodo18 ()
{
//identificar
   IO_id("EXEMPLO0718 - Metodo18 - v0.0");
//declarar variavel
   int x=0;
//testar
   while (x<=0)
   {
      printf("\n Entrar com valor de quantidade: ");
      scanf("%d", &x);
      if (x<=0)
      {
         printf ("\n ERRO: valor invalido");
      }//fim if
   }//fim while
   
//funcao
   fibimp(x);

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo18

/*
Metodo 19 - Exemplo19
Objetivos: função para
para calcular a quantidade de minúsculas em cadeia de caracteres de um arquivo texto.
Gravar em outro arquivo ("RESULTADO09.TXT") cada cadeia de caracteres e seu resultado.
Testes:OK
*/

void lower (char* filename)
{
//abrir para gravar
   FILE*entrada= fopen(filename, "rt");
   FILE*saida= fopen("RESULTADO09.TXT", "wt");
//testar se entrada existe
   if(entrada==NULL)
   {
      printf("ERRO: arquivo nao encontrado");
   }//fim if
   else
   {
   //declara
      char* linha = (char*)malloc(80*sizeof(char));
      linha[0]='\0';
      int i=0;
   //le primeiro
      strcpy(linha, IO_freadln(entrada));
      
      //copiar minusculas
      while(!feof(entrada))
      {
         for (i=0; i<strlen(linha); i++)
         {
            if(linha[i]<='z' && linha[i]>='a')
            {
               fprintf(saida, "%c", linha[i]);
            }//fim if
         }//fim for
         fprintf(saida, "\n");
         //ler
         strcpy(linha, IO_freadln(entrada));
      
      }//fim while
   }//fim else
   
   //fechar
   fclose(entrada);
   fclose(saida);
}//fim lower


void metodo19 ()
{
//identificar
   IO_id("EXEMPLO0719 - Metodo19 - v0.0");
//declarar
   char*linha=(char*)malloc(80*sizeof(char));
   linha[0]='\0';   
//gravar texto
   FILE* arquivo=fopen("DADOS19.TXT", "at");
   printf("Escrevar PARAR para finalizar a gravação\n");
   while (strcmp(linha, "PARAR") !=0)
   {
      strcpy(linha, IO_readln(""));
      IO_fprintln(arquivo, linha);
   }//fim while
   //fechar
   fclose(arquivo);
   
   //minusculas
   lower("DADOS19.TXT");  
   

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo19

/*
Metodo 20 - Exemplo20
Objetivos: Incluir em um programa (Exemplo0720) com função para
para contar dígitos em uma cadeia de caracteres.
Gravar em outro arquivo ("RESULTADO10.TXT") cada cadeia de caracteres e seu resultado.
Testar essa função para quantidades diferentes.
Testes:ok
*/

void digitos(char* line)
{
//abrir arquivo para gravar
   FILE*arquivo =fopen("RESULTADO10.TXT", "at");
   //gravar
   IO_fprintln(arquivo, line);
   int i=0;
   int contador=0;
   for(i=0; i<strlen(line); i++)
   {
      if (line[i]>='0' && line[i]<='9')
      {
         contador=(contador+1);
      }//fim if
   }//fim for
   fprintf(arquivo, "Numero de digitos= %d\n", contador);   
   //fechar arq
   fclose(arquivo);
}//fim digitos

void metodo20 ()
{
//identificar
   IO_id("EXEMPLO0720 - Metodo20 - v0.0");
//declarar variavel
   int x=0;
//testar
   while (x<=0)
   {
      printf("\n Entrar com valor de quantidade: ");
      scanf("%d", &x);
      if (x<=0)
      {
         printf ("\n ERRO: valor invalido");
      }//fim if
   }//fim while
   
//variaveis
   int i=0;
   char*linha=(char*)malloc(80*sizeof(char));
   linha[0]='\0';

//funcao
   for (i=1; i<=x; i++)
   {
      strcpy(linha, IO_readln("Insira uma cadeia de caracteres: "));
      digitos(linha);
   }
   

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo20

/*
Metodo 21 - Exemplo21
Objetivos: Incluir em um programa (Exemplo07E1) um método para
programa ler um valor inteiro do teclado, e
gravar em arquivo os seus divisores em ordem crescente.
Testes:ok
*/
void metodo21 ()
{
//identificar
   IO_id("EXEMPLO0721 - Metodo21 - v0.0");
   //input
   int x=0;
   printf("Inserir valor inteiro: ");
   scanf("%d", &x);
   //criar arq
   FILE*arq=fopen("DADOS21.TXT", "wt");
   //operacoes e gravar
   fprintf(arq, "numero=%d\tdivisores=\t", x);
   int i=0;
   if (x<0)
   {
      x=-x;
   }//fim if
   if (x!=0)
   {
      for (i=1; i<=x; i++)
      {
         if (x%i==0)
         {
            fprintf(arq, "%d\t", i);
         }//fim if2
      }//fim for
   }//fim if1
   else
   {
      fprintf(arq,"Todos os numeros sao divisores de 0");
   }//fim else
   //fechar arq
   fclose(arq);

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo21

/*
Metodo 22 - Exemplo22
Objetivos: função para
ler palavras de um arquivo, uma por linha, e
contar quantas não começam com a letra 'a' (ou 'A').
Testes:OK
*/
int naoa (char* filename)
{
//declarar
   int total=0;
   char*palavra=(char*)malloc(80*sizeof(char));
   palavra[0]='\0';
//abrir para leitura
   FILE*arq=fopen(filename, "rt");
//teste
   if (arq==NULL)
   {
      printf("\nErro: Arquivo nao encontrado!\n");
   }//fim if
   else
   {
   //teste
      while(!feof(arq))
      {
         //ler 
         fscanf(arq, "%s", palavra);
         //controle
         printf("%s\n", palavra);
          if (palavra[0]!='a' && palavra[0]!='A')
         {
            total=total+1;
         }//fim if
      }//fim while
   
   }//fim else
   //return
   return(total);
}//fim naoa


void metodo22 ()
{
//identificar
   IO_id("EXEMPLO0722 - Metodo22 - v0.0");
   //variaveis
   char* nomearq=(char*)malloc(sizeof(char));
   nomearq[0]='\0';
//input
   strcpy(nomearq, IO_readln("Inserir nome do arquivo: "));
//funcao
   printf("O arquivo possui um total de %d palavras no inicio de linha que nao comecam com 'a'", naoa(nomearq));

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo22

/*
Main
Teste: OK
*/

int main ()
{
   int x =0;
   do
   {
   // menu exercicios
      printf("\n%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\n", 
                     "Lista ED07 - Fabiana Kraft - 677262", "0 - parar", "1 - Exemplo0701",
                     "2 - Exemplo0702","3 - Exemplo0703","4 - Exemplo0704","5 - Exemplo0705",
                     "6 - Exemplo0706","7 - Exemplo0707","8 - Exemplo0708","9 - Exemplo0709",
                     "10 - Exemplo0710","11 - Exemplo0711","12 - Exemplo0712","13 - Exemplo0713",
                     "14 - Exemplo0714","15 - Exemplo0715","16 - Exemplo0716","17 - Exemplo0717",
                     "18 - Exemplo0718","19 - Exemplo0719","20 - Exemplo0720","21 - Exemplo0721",
                     "22 - Exemplo0722");
   //input
      printf ("Inserir valor: ");
      scanf("%d", &x);
   
   // switch case
      switch (x)
      {
         case 0:
            {
               metodo0 ();
               break;
            }
         case 1:
            {
               metodo1 ();
               break;
            }
         case 2:
            {
               metodo2 ();
               break;
            }
         case 3:
            {
               metodo3 ();
               break;
            }
         case 4:
            {
               metodo4 ();
               break;
            }
         case 5:
            {
               metodo5 ();
               break;
            }
         case 6:
            {
               metodo6 ();
               break;
            }
         case 7:
            {
               metodo7 ();
               break;
            }
         case 8:
            {
               metodo8 ();
               break;
            }
         case 9:
            {
               metodo9 ();
               break;
            }
         case 10:
            {
               metodo10 ();
               break;
            }
         case 11:
            {
               metodo11 ();
               break;
            }
         case 12:
            {
               metodo12 ();
               break;
            }
         case 13:
            {
               metodo13 ();
               break;
            }
         case 14:
            {
               metodo14 ();
               break;
            }
         case 15:
            {
               metodo15 ();
               break;
            }
         case 16:
            {
               metodo16 ();
               break;
            }
         case 17:
            {
               metodo17 ();
               break;
            }
         case 18:
            {
               metodo18 ();
               break;
            }
         case 19:
            {
               metodo19 ();
               break;
            }
         case 20:
            {
               metodo20 ();
               break;
            }
         case 21:
            {
               metodo21 ();
               break;
            }
         case 22:
            {
               metodo22 ();
               break;
            }
         default:
            {
               IO_pause ( "Favor inserir numero ente 0 e 22. Aperte enter para continuar" );
            }
      
      }//fim switch
   
   
   }//fim do
   while (x!=0);
// terminar
   IO_pause ( "Apertar ENTER para terminar" );
}//fim main