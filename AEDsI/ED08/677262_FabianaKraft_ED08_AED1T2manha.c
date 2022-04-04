#include "io.h"

/**
ED08 - AED1 T2 Manhã
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
printIntArray + Metodo 1 - Exemplo01
Objetivos: printIntArray - Mostrar arranjo com valores inteiros.
@param n - quantidade de valores
@param array - grupo de valores inteiros
Testes:ok
*/

void printIntArray ( int n, int array [ ] )
{
// definir dado local
   int x = 0;
// mostrar valores no arranjo
   for ( x=0; x<n; x=x+1 )
   {
   // mostrar valor
      IO_printf ( "%2d: %d\n", x, array [ x ] );
   } // fim repetir
} // printIntArray ( )


void metodo1 ()
{
//identificar
   IO_id("EXEMPLO0801 - Metodo01 - v0.0");

// definir dado
   int array [ ] = { 1, 2, 3, 4, 5 };
   
   // executar o metodo auxiliar
   printIntArray ( 5, array );
//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo1

/*
Metodo 2 - Exemplo02
Objetivos: readIntArray - Ler arranjo com valores inteiros.
@param n - quantidade de valores
@param array - grupo de valores inteiros
Testes:ok
*/

void readIntArray ( int n, int array [ ] )
{
// definir dados locais
   int x = 0;
   int y = 0;
   chars text = IO_new_chars ( STR_SIZE );
// ler e guardar valores em arranjo
   for ( x=0; x<n; x=x+1 )
   {
   // ler valor
      //strcpy ( text, STR_EMPTY );
      //y = IO_readint ( IO_concat (
         //IO_concat ( text, IO_toString_d ( x ) ), " : " ) );
      printf("\n%d: ", x);
      scanf("%d", &y);
   // guardar valor
      array [ x ] = y;
   } // fim repetir
} // readIntArray ( )

void metodo2 ()
{
//identificar
   IO_id("EXEMPLO0802 - Metodo02 - v0.0");;
// definir dados
   int n = 5; // quantidade de valores
   int array [ n ];
   // ler dados
   readIntArray ( n, array );
// mostrar dados
   IO_printf ( "\n" );
   printIntArray ( n, array );
//terminar
   IO_pause("Apertar enter para continuar");;
}// fim metodo2

/*
Metodo 3 - Exemplo03
Objetivos: fprintIntArray - Gravar arranjo com valores inteiros.
@param fileName - nome do arquivo
@param n - quantidade de valores
@param array - grupo de valores inteiros
Testes: ok
*/

void fprintIntArray ( chars fileName, int n, int array [ ] )
{
// definir dados locais
   FILE* arquivo = fopen ( fileName, "wt" );
   int x = 0;
// gravar quantidade de dados
   IO_fprintf ( arquivo, "%d\n", n );
// gravar valores no arranjo
   for ( x=0; x<n; x=x+1 )
   {
   // gravar valor
      IO_fprintf ( arquivo, "%d\n", array [ x ] );
   } // fim repetir
// fechar arquivo
   fclose ( arquivo );
} // fprintIntArray ( )

void metodo3 ()
{
//identificar
   IO_id("EXEMPLO0803 - Metodo03 - v0.0");;
// definir dados
   int n = 5; // quantidade de valores
   int array [ n ];
   // ler dados
   readIntArray ( n, array );
// mostrar dados
   IO_printf ( "\n" );
   fprintIntArray ( "ARRAY1.TXT", n, array );

//terminar
   IO_pause("Apertar enter para continuar");;
}// fim metodo3

/*
Metodo 4 - Exemplo04
Objetivos
Testes: ok
*/

/**
freadArraySize - Ler tamanho do arranjo com valores inteiros.
@return quantidade de valores lidos
@param fileName - nome do arquivo
*/

int freadArraySize ( chars fileName )
{
// definir dados locais
   int n = 0;
   FILE* arquivo = fopen ( fileName, "rt" );
// ler a quantidade de dados
   IO_fscanf ( arquivo, "%d", &n );
   if ( n <= 0 )
   {
      IO_println ( "ERRO: Valor invalido." );
      n = 0;
   } // fim se
// retornar dado lido
   return ( n );
} // freadArraySize ( )

/**
freadIntArray - Ler arranjo com valores inteiros.
@param fileName - nome do arquivo
@param n - quantidade de valores
@param array - grupo de valores inteiros
*/
void freadIntArray ( chars fileName, int n, int array [ ] )
{
// definir dados locais
   int x = 0;
   int y = 0;
   FILE* arquivo = fopen ( fileName, "rt" );
// ler a quantidade de dados
   IO_fscanf ( arquivo, "%d", &x );
   if ( n <= 0 || n > x )
   {
      IO_println ( "ERRO: Valor invalido." );
   }
   else
   {
   // ler e guardar valores em arranjo
      x = 0;
      while ( ! feof ( arquivo ) && x < n )
      {
      // ler valor
         IO_fscanf ( arquivo, "%d", &y );
      // guardar valor
         array [ x ] = y;
      // passar ao proximo
         x = x+1;
      } // fim repetir
   } // fim se
} // freadIntArray ( )   

void metodo4 ()
{
//identificar
   IO_id("EXEMPLO0804 - Metodo04 - v0.0");
   // definir dados
   int n = 0; // quantidade de valores
   // ler dados
   n = freadArraySize ( "ARRAY1.TXT" );
   if ( n <= 0 )
   {
      IO_printf ( "\nERRO: Valor invalido.\n" );
   }
   else
   {
   // definir armazenador
      int array [ n ];
   // ler dados
      freadIntArray ( "ARRAY1.TXT", n, array );
   // mostrar dados
      IO_printf ( "\n" );
      printIntArray ( n, array );
   } // fim se

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo4

/*
Metodo 5 - Exemplo05
Objetivos
Testes: ok
*/

/**
copyIntArray - Copiar arranjo com valores inteiros.
@param n - quantidade de valores
@param copy - copia do grupo de valores inteiros
@param array - grupo de valores inteiros
*/
void copyIntArray ( int n, int copy [ ], int array [ ] )
{
// definir dados locais
   int x = 0;
   int y = 0;
   if ( n <= 0 )
   {
      IO_println ( "ERRO: Valor invalido." );
      n = 0;
   }
   else
   {
   // copiar valores em arranjo
      for ( x = 0; x < n; x = x + 1 )
      {
      // copiar valor
         copy [ x ] = array [ x ];
      } // fim repetir
   } // fim se
} // copyIntArray ( )

void metodo5 ()
{
//identificar
   IO_id("EXEMPLO0805 - Metodo05 - v0.0");
   // definir dados
   int n = 0; // quantidade de valores
// ler a quantidade de dados
   n = freadArraySize ( "ARRAY1.TXT" );
   if ( n <= 0 )
   {
      IO_printf ( "\nERRO: Valor invalido.\n" );
   }
   else
   {
   // definir armazenador
      int array [ n ];
      int other [ n ];
   // ler dados
      freadIntArray ( "ARRAY1.TXT", n, array );
   // copiar dados
      copyIntArray ( n, other, array );
   // mostrar dados
      IO_printf ( "\nOriginal\n" );
      printIntArray ( n, array );
   // mostrar dados
      IO_printf ( "\nCopia\n" );
      printIntArray ( n, other );
   } // fim se

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo5

/*
Metodo 6 - Exemplo06
Objetivos
Testes: ok
*/

/**
sumIntArray - Somar valores em arranjo com inteiros.
@return - soma dos valores
@param n - quantidade de valores
@param array - grupo de valores inteiros
*/
int sumIntArray ( int n, int array [ ] )
{
// definir dados locais
   int soma = 0;
   int x = 0;
// mostrar valores no arranjo
   for ( x=0; x<n; x=x+1 )
   {
   // somar valor
      soma = soma + array [ x ];
   } // fim repetir
// retornar resposta
   return ( soma );
} // sumIntArray ( )

void metodo6 ()
{
//identificar
   IO_id("EXEMPLO0806 - Metodo06 - v0.0");
   // definir dados
   int n = 0; // quantidade de valores
// ler a quantidade de dados
   n = freadArraySize ( "ARRAY1.TXT" );
   if ( n <= 0 )
   {
      IO_printf ( "\nERRO: Valor invalido.\n" );
   }
   else
   {
   // definir armazenador
      int array [ n ];
   // ler dados
      freadIntArray ( "ARRAY1.TXT", n, array );
   // mostrar a soma dos valores no arranjo
      IO_printf ( "\nSoma = %d\n", sumIntArray ( n, array ) );
   } // fim se

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo6

/*
Metodo 7 - Exemplo07
Objetivos
Testes: ok
*/

/**
isAllZeros - Testar valores inteiros em arranjo.
@return - true, se todos os dados forem iguais a zero;
false, caso contrario
@param n - quantidade de valores
@param array - grupo de valores inteiros
*/
bool isAllZeros ( int n, int array [ ] )
{
// definir dados locais
   bool result = true;
   int x = 0;
// mostrar valores no arranjo
   x=0;
   while ( x<n && result )
   {
   // testar valor
      result = result && ( array [ x ] == 0 );
   // passar ao proximo
      x = x + 1;
   } // fim repetir
// retornar resposta
   return ( result );
} // isAllZeros ( )

void metodo7 ()
{
//identificar
   IO_id("EXEMPLO0807 - Metodo07 - v0.0");
   // definir dados
   int n = 5; // quantidade de valores
   int array1 [ ] = { 0,0,0,0,0 };
   int array2 [ ] = { 1,2,3,4,5 };
   int array3 [ ] = { 1,2,0,4,5 };

// testar dados
   IO_println ( "\nArray1" );
   printIntArray ( n, array1 );
   IO_printf ( "isAllZeros (array1) = %d", isAllZeros (n, array1) );
   IO_println ( "\nArray2" );
   printIntArray ( n, array2 );
   IO_printf ( "isAllZeros (array2) = %d", isAllZeros (n, array2) );
   IO_println ( "\nArray3" );
   printIntArray ( n, array3 );
   IO_printf ( "isAllZeros (array3) = %d", isAllZeros (n, array3) );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo7

/*
Metodo 8 - Exemplo08
Objetivos
Testes: ok
*/

/**
addIntArray - Somar arranjos com inteiros.
@return - arranjo ocm a soma resultante
@param n - quantidade de valores
@param array3 - soma de grupo de valores inteiros
@param array1 - grupo de valores inteiros (1)
@param k - constante para multiplicar o segundo arranjo
@param array2 - grupo de valores inteiros (2)
*/
void addIntArray ( int n, int array3 [ ], int array1 [ ], int k, int array2 [ ] )
{
// definir dados locais
   int x = 0;
// mostrar valores no arranjo
   for ( x=0; x<n; x=x+1 )
   {
   // somar valor
      array3 [ x ]= array1 [ x ] + k * array2 [ x ];
   } // fim repetir
} // addIntArray ( )


void metodo8 ()
{
//identificar
   IO_id("EXEMPLO0808 - Metodo08 - v0.0");
// definir dados
   int n = 0; // quantidade de valores

// ler a quantidade de dados
   n = freadArraySize ( "ARRAY1.TXT" );
   if ( n <= 0 )
   {
      IO_printf ( "\nERRO: Valor invalido.\n" );
   }
   else
   {
   // definir armazenador
      int array [ n ];
      int other [ n ];
      int sum [ n ];
   // ler dados
      freadIntArray ( "ARRAY1.TXT", n, array );
   // copiar dados
      copyIntArray ( n, other, array );
   // mostrar dados
      IO_printf ( "\nOriginal\n" );
      printIntArray ( n, array );
   // mostrar dados
      IO_printf ( "\nCopia\n" );
      printIntArray ( n, other );
   // operar soma de arranjos
      addIntArray ( n, sum, array, (-2), other );
   // mostrar resultados
      IO_printf ( "\nSoma\n" );
      printIntArray ( n, sum );
   } // fim se
//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo8

/*
Metodo 9 - Exemplo09
Objetivos
Testes: ok
*/

/**
isEqual - Testar arranjos com inteiros sao iguais.
@return - true, se todos os dados forem iguais;
false, caso contrario
@param n - quantidade de valores
@param array1 - grupo de valores inteiros (1)
@param array2 - grupo de valores inteiros (2)
*/
bool isEqual ( int n, int array1 [ ], int array2 [ ] )
{
// definir dados locais
   bool result = true;
   int x = 0;
// mostrar valores no arranjo
   x = 0;
   while ( x<n && result )
   {
   // testar valor
      result = result && ( array1 [ x ] == array2 [ x ] );
   // passar ao proximo
      x = x + 1;
   } // fim repetir
// retornar resposta
   return ( result );
} // isEqual ( )


void metodo9 ()
{
//identificar
   IO_id("EXEMPLO0809 - Metodo09 - v0.0");
// definir dados
   int n = 0; // quantidade de valores
// ler a quantidade de dados
   n = freadArraySize ( "ARRAY1.TXT" );
   if ( n <= 0 )
   {
      IO_printf ( "\nERRO: Valor invalido.\n" );
   }
   else
   {
   // definir armazenador
      int array [ n ];
      int other [ n ];
   // ler dados
      freadIntArray ( "ARRAY1.TXT", n, array );
   // copiar dados
      copyIntArray ( n, other, array );
   // mostrar dados
      IO_printf ( "\nOriginal\n" );
      printIntArray ( n, array );
   // mostrar dados
      IO_printf ( "\nCopia\n" );
      printIntArray ( n, other );
   // mostrar resultado da comparacao
      IO_printf ( "\nIguais = %d\n", isEqual ( n, array, other ) );
   // modificar um valor
      other [ 0 ] = (-1) * other [ 0 ];
   // mostrar dados
      IO_printf ( "\nCopia alterada\n" );
      printIntArray ( n, other );
   // mostrar resultado da comparacao
      IO_printf ( "\nIguais = %d\n", isEqual ( n, array, other ) );
   } // fim se
//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo9

/*
Metodo 10 - Exemplo10
Objetivos
Testes: ok
*/
/**
searchArray - Procurar valor em arranjo com inteiros.
@return - true, se encontrar;
false, caso contrario
@param n - quantidade de valores
@param array - grupo de valores inteiros
@param value - valor a ser procurado
*/
bool searchArray ( int n, int array [ ], int value )
{
// definir dados locais
   bool result = false;
   int x = 0;
// mostrar valores no arranjo
   x = 0;
   while ( x<n && ! result )
   {
   // testar valor
      result = ( value == array [ x ] );
   // passar ao proximo
      x = x + 1;
   } // fim repetir
// retornar resposta
   return ( result );
} // searchArray ( )

void metodo10 ()
{
//identificar
   IO_id("EXEMPLO0810 - Metodo10 - v0.0");
   int n = 0; // quantidade de valores
   int value = 0; // valor a ser procurado

// ler a quantidade de dados
   n = freadArraySize ( "ARRAY1.TXT" );
   if ( n <= 0 )
   {
      IO_printf ( "\nERRO: Valor invalido.\n" );
   }
   else
   {
   // definir armazenador
      int array [ n ];
   // ler dados
      freadIntArray ( "ARRAY1.TXT", n, array );
   // mostrar dados
      IO_printf ( "\nOriginal\n" );
      printIntArray ( n, array );
   // mostrar resultados de procuras
      value = array [ 0 ];
      IO_printf ( "\nProcurar por (%d) = %d\n",
         value, searchArray ( n, array, value ) );
      value = array [ n / 2 ];
      IO_printf ( "\nProcurar por (%d) = %d\n",
         value, searchArray ( n, array, value ) );
      value = array [ n - 1 ];
      IO_printf ( "\nProcurar por (%d) = %d\n",
         value, searchArray ( n, array, value ) );
      value = (-1);
      IO_printf ( "\nProcurar por (%d) = %d\n",
         value, searchArray ( n, array, value ) );
   } // fim se

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo10

/*
Metodo 11 - Exemplo11
Objetivos: Incluir em um programa (Exemplo0811) um método para
ler o tamanho de um arranjo para inteiros do teclado,
bem como todos os seus elementos, garantindo que só tenha valores positivos e pares.
Verificar se as dimensões não são nulas ou negativas.
Para testar, ler diferentes quantidades de dados.
Testes:ok
*/
   

void metodo11 ()
{
//identificar
   IO_id("EXEMPLO0811 - Metodo11 - v0.0");
   int n1=0;
   int i=0;
   //input
   while (n1<=0)
   {
      printf("\nInserir tamanho do vetor: ");
      scanf("%d", &n1);
      if (n1<=0)
      {
         printf("\nERRO: VALOR INVALIDO");
      }//fim if
   }//fim while   
   int v1[n1];
   int valor=0;
   //inserir valores

   while (i<n1)
   {
      printf ("Inserir valor %d: ",i);
      scanf("%d", &valor);
      v1[i]=valor;
         
      while (v1[i]<=0 || v1[i]%2==1)
      {
         printf ("Inserir valor %d: ", i);
         scanf("%d", &valor);
         v1[i]=valor;
      }//while
      
      i=i+1;
      
   }//fim while
   //output
   for (i=0; i<n1; i++)
   {
      printf("\n%d: %d", i, v1[i]);
   }//fim for
    //obs
   int n=sizeof(v1)/sizeof(v1[0]); //nao funciona dentro de funcao (v1 como parametro)
   printf("\ntamanho=%d", n);
//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo11

/*
Metodo 12 - Exemplo12
Objetivos: Incluir em um programa (Exemplo0812) um método para
ler um arranjo com inteiros positivos de arquivo.
Valores negativos e também os ímpares deverão ser descartados.
O arranjo e o nome do arquivo serão dados como parâmetros.
Guardar primeiro o tamanho, depois os elementos, um dado por linha.
Para testar, ler diferentes quantidade de dados.
Testes: ok
*/


void f_12 (char* filename, int vetor[], int tamanho)
{
//abrir arquivo
   FILE*arq=fopen(filename, "rt");
//ler primeiro (=tamanho array)
   int n=0;
   int i=1;
   vetor[0]=tamanho;
   fscanf(arq, "%d", &n);
//ler resto
   while (!feof(arq))
   {
      fscanf(arq, "%d", &n);
      if (n>0 && n%2==0)
      {
         vetor[i]=n;
         i=i+1;
      }//fim if
   }
   //fechar
   fclose(arq);
   //print
   for (i=0; i<tamanho+1; i++)
   {
      printf("\n%d: %d", i, vetor[i]);
   }//fim for
}//fim f_12

void metodo12 ()
{
//identificar
   IO_id("EXEMPLO0812 - Metodo12 - v0.0");
   //abrir arquivo para gravar
   FILE*arq= fopen("ENTRADA12.TXT", "wt");
   //gravar tamanho
   int tamanho=0;
   int valor=0;
   int cont=0;
   int i=0;
   while (tamanho<=0)
   {
      printf("Inserir quantidade: ");
      scanf("%d", &tamanho);
   }//fim while
   fprintf(arq, "%d\n", tamanho);
   //gravar valores
   for (i=0; i<tamanho; i++)
   {
      printf("%d: ", i);
      scanf("%d", &valor);
      if (valor>0 && valor%2==0)
      {
         cont= cont+1;
      }
      fprintf(arq, "%d\n", valor);
   }//fim for
//fechar
   fclose(arq);
//vetorizar
   int v[cont];
   //controle
   printf("\ntamanho= %d", cont);
   f_12("ENTRADA12.TXT", v, cont);
//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo12

/*
Metodo 13 - Exemplo13
Objetivos: Incluir em um programa (Exemplo0813) uma função para
gerar um valor inteiro aleatoriamente dentro de um intervalo,
cujos limites de início e de fim serão recebidos como parâmetros;
Para para testar, ler os limites do intervalo do teclado;
ler a quantidade de elementos ( N ) a serem gerados;
gerar essa quantidade ( N ) de valores aleatórios
dentro do intervalo e armazená-los em arranjo;
gravá-los, um por linha, em um arquivo ("DADOS.TXT").
A primeira linha do arquivo deverá informar a quantidade
de números aleatórios ( N ) que serão gravados em seguida.
DICA: Usar a função rand( ), mas tentar limitar valores muito grandes (usar mod=%).
Exemplo: valor = gerarInt ( inferior, superior );
Testes: ok
*/
int gerarint (int sup, int inf)
{
   int valor=rand() % (sup-inf+1);
   return (valor);
}

void metodo13 ()
{
//identificar
   IO_id("EXEMPLO0813 - Metodo13 - v0.0");
//declarar
   int q=0;
   int max=0;
   int min=0;
   int i=0;
//inputs
   while (q<=0)
   {
      printf("Inserir quantidade a ser lida: ");
      scanf("%d",&q);
   }//fim while
//vetor
   int v[q];
   while(max<=min)
   {
      printf("Inserir intervalo superior: ");
      scanf("%d",&max);
      printf("Inserir intervalo inferior: ");
      scanf("%d",&min);
   }//fim while 
   
   for (i=0; i<q; i++)
   {
      v[i]=gerarint(max, min);
      //controle
      printf("\n%d: %d", i, v[i]);
   }
   //abrir para gravar
   FILE* arq= fopen("DADOS.TXT", "wt");
  //gravar
   fprintf(arq, "%d\n", q);
   for (i=0; i<q; i++)
   {
      fprintf(arq, "%d\n", v[i]);
   }
  
  //fechar arquivo
   fclose(arq);
//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo13

/*
Metodo 14 - Exemplo14
Objetivos: Incluir em um programa (Exemplo0814) uma função para
procurar o maior valor em um arranjo.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;
DICA: Usar o primeiro valor da tabela como referência inicial
para o maior valor.
Testes:OK
*/

int ftamanho (char* filename)
{
//abrir para ler
   FILE*arq=fopen(filename, "rt");
//testar se existe
   if (arq==NULL)
   {
      printf("\nERRO: nao foi possivel abrir");
   }
   else
   {
      int x=0;
      int cont=1;
   //ler primeiro
      fscanf(arq, "%d", &x);
      while(!feof(arq))
      {
         fscanf(arq, "%d", &x);
         cont=cont+1;
      }
      return(cont);
   }
  //fclose
   fclose(arq);
}//fim ftamanho

void farranjo (char* filename, int size, int v[])
{
//abrir para ler
   FILE*arq=fopen(filename, "rt");
//testar se existe
   if (arq==NULL || size<=0)
   {
      printf("\nERRO: arquivo nao existe ou esta em branco");
   }
   else
   {
      int x=0;
   //ler primeiro
      fscanf(arq, "%d", &x);
      //controle 
      printf("\n%d",x);
      v[0]=x;
      int i=1;
      while(!feof(arq) && i<size)
      {
         fscanf(arq, "%d", &x);
         //controle 
         //printf("\n%d",x);
         v[i]=x;
         i=i+1;
      }
   }
   //fechar
   fclose(arq);
}//fim farranjo

int fmaior (int v[], int size)
{
   int i=0;
   int maior= v[0];
   for (i=1; i<size; i++)
   {
      if (maior< v[i])
      {
         maior=v[i];
      }//fim if
   }//fim for
   return(maior);
}//fim fmaior

void metodo14 ()
{
//identificar
   IO_id("EXEMPLO0814 - Metodo14 - v0.0");
   //inputs
   char* filename=(char*)malloc(80*sizeof(char));
   filename[0]='\0';
   printf("Inserir nome do arquivo: ");
   scanf("%s", filename);
   //tamanho
   int n= ftamanho(filename);
   //arranjo
   int v[n];
   farranjo(filename, n, v);
   //maior
   printf("\nO maior e= %d", fmaior (v, n));
//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo14

/*
Metodo 15 - Exemplo15
Objetivos: ncluir em um programa (Exemplo0815) uma função para
procurar o menor valor em um arranjo.
Para testar, receber um nome de arquivo como parâmetro e
aplicar a função sobre o arranjo com os valores lidos;
DICA: Usar o primeiro valor da tabela como referência inicial.
Testes: ok
*/
int fmenor (int v[], int size)
{
   int i=0;
   int menor= v[0];
   for (i=1; i<size; i++)
   {
      if (menor> v[i])
      {
         menor=v[i];
      }//fim if
   }//fim for
   return(menor);
}//fim fmaior

void metodo15 ()
{
//identificar
   IO_id("EXEMPLO0815 - Metodo15 - v0.0");
//inputs
   char* filename=(char*)malloc(80*sizeof(char));
   filename[0]='\0';
   printf("Inserir nome do arquivo: ");
   scanf("%s", filename);
   //tamanho
   int n= ftamanho(filename);
   //arranjo
   int v[n];
   farranjo(filename, n, v);
   //menor
   printf("\nO menor e= %d", fmenor (v, n));
//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo15

/*
Metodo 16 - Exemplo16
Objetivos: Incluir em um programa (Exemplo0816) uma função para
para determinar a média valores em um arranjo.
Para testar, ler o arquivo ("DADOS.TXT")
armazenar os dados em um arranjo;
separar em dois outros arquivos,
os valores maiores ou iguais à média, e os menores que ela.
Testes: ok
*/
double fmedia (int v[], int n)
{
   double media=0.0;
   int i=0;
   for (i=0; i<n; i++)
   {
      media=media+v[i];
      //controle
      //printf("\n%d", v[i]);
   }
   media=(media/(double)n);
   return(media);
}// fim fmedia
void metodo16 ()
{
//identificar
   IO_id("EXEMPLO0816 - Metodo16 - v0.0");
   //tamanho
   int n= ftamanho("DADOS.TXT");
   //arranjo
   int v[n];
   farranjo("DADOS.TXT", n, v);
   //media
   double media = fmedia (v, n);
   printf("\nA media e= %lf", media);
   // arquivos
   FILE*arqmaior=fopen("MAIORES.TXT", "wt");
   FILE*arqmenor=fopen("MENORES.TXT", "wt");
   //GRAVAR
   int i=0;
   for (i=0; i<n; i++)
   {
      if (v[i]>=media)
      {
         fprintf(arqmaior, "%d\n", v[i]);
      }//fim if
      else
      {
         fprintf(arqmenor, "%d\n", v[i]);
      }//fim else
   }//fim for
//fechar arq
   fclose(arqmaior);
   fclose(arqmenor);
//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo16

/*
Metodo 17 - Exemplo17
Objetivos: Incluir em um programa (Exemplo0817) uma função para
receber como parâmetro um arranjo
e dizer se está ordenado, ou não, em ordem crescente.
Testes: ok
*/
bool fordemv (int v[], int n)
{
   bool ordem =true;
   int i=1;
   while (i<n && ordem==true)
   {
      if (v[i]<v[i-1])
      {
         ordem=false;
      }
      i=i+1;
   }
   return(ordem);
}// fim fordemv

bool fordemvd (double v[], int n)
{
   bool ordem =true;
   int i=1;
   while (i<n && ordem==true)
   {
      if (v[i]<v[i-1])
      {
         ordem=false;
      }
      i=i+1;
   }
   return(ordem);
}// fim fordemvd

void metodo17 ()
{
//identificar
   IO_id("EXEMPLO0817 - Metodo17 - v0.0");
//declarar
   int v1[]={0,1,2,3,4};
   int v2[]={1,6,0};
   int v3[]={11,12,13,14,17,16,18,19,20};
   double v4[]={1.0, 2.5, 4.7, 9.9999};
   int n=0;
//teste
   printf("1) %d\n", fordemv(v1, (n+5)));
   printf("2) %d\n", fordemv(v2, (n+3)));
   printf("3) %d\n", fordemv(v3, (n+9)));
   printf("4) %d\n", fordemvd(v4, (n+4)));
//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo17

/*
Metodo 18 - Exemplo18
Objetivos: Incluir em um programa (Exemplo0818) uma função para
procurar por determinado valor em arranjo e
dizer se esse valor pode ser nele encontrado,
indicada a posição inicial para se começar a procura.
Para testar, ler o arquivo ("DADOS.TXT"),
e armazenar os dados em arranjo;
ler do teclado um valor inteiro para ser procurado;
determinar se o valor procurado existe no arranjo,
a partir da posição indicada.
Testes: ok
*/
bool fexiste ( int v[], int n, int dado, int posicao, int direcao)
{
   int i=posicao;
   bool existe=false;
   while (i<n && i>=0 && existe==false)
   {
      if (dado == v[i])
      { 
         existe=true;
      }//fim if
      if (direcao == 0)
      {
         i=i-1;
      }
      else
      {
         i=i+1;
      }
   }//fim while
   return (existe);
}

void metodo18 ()
{
//identificar
   IO_id("EXEMPLO0818 - Metodo18 - v0.0");
   //tamanho
   int n= ftamanho("DADOS.TXT");
   //arranjo
   int v[n];
   farranjo("DADOS.TXT", n, v);
   //inputs
   int posicao=-1;
   int dado=0;
   while (posicao<0 || posicao>n)
   {
      printf("\n Posicao desejada = ");
      scanf("%d", &posicao);
   }//fim while
   printf("\n valor desejado a ser procurado= ");
   scanf("%d", &dado);
   int direcao= 2;
   while (direcao!=1 && direcao!=0)
   {
      printf("\n Digite 1 para procurar para frente ou 0 para tras: ");
      scanf("%d", &direcao);
   }//fim while
   //controle
   printf("\n%d\t%d\t%d\t%d\t%d", n, dado, posicao, direcao,fexiste( v, n, dado, posicao, direcao));
   
   if ( fexiste( v, n, dado, posicao, direcao)==true)
   {
      printf("\nO valor foi encontrado");
   }
   else
   {
      printf("\nO valor nao foi encontrado");
   }
   
//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo18

/*
Metodo 19 - Exemplo19
Objetivos: Incluir em um programa (Exemplo0819) uma função para
procurar por determinado valor em arranjo e
dizer onde se encontra esse valor,
indicada a posição inicial para começar a procura.
Para testar, ler o arquivo ("DADOS.TXT"),
e armazenar os dados em arranjo;
ler do teclado um valor inteiro para ser procurado;
determinar onde o valor procurado está no arranjo,
se houver.
Testes: ok
*/
int fexistepos ( int v[], int n, int dado, int posicao, int direcao)
{
   int i=posicao;
   int existe=-1;
   while (i<n && i>=0 && existe==-1)
   {
      if (dado == v[i])
      { 
         existe=i;
      }//fim if
      if (direcao == 0)
      {
         i=i-1;
      }
      else
      {
         i=i+1;
      }
   }//fim while
   return (existe);
}

void metodo19 ()
{
//identificar
   IO_id("EXEMPLO0819 - Metodo19 - v0.0");

   //tamanho
   int n= ftamanho("DADOS.TXT");
   //arranjo
   int v[n];
   farranjo("DADOS.TXT", n, v);
   //inputs
   int posicao=-1;
   int dado=0;
   while (posicao<0 || posicao>n)
   {
      printf("\n Posicao desejada = ");
      scanf("%d", &posicao);
   }//fim while
   printf("\n valor desejado a ser procurado= ");
   scanf("%d", &dado);
   int direcao= 2;
   while (direcao!=1 && direcao!=0)
   {
      printf("\n Digite 1 para procurar para frente ou 0 para tras: ");
      scanf("%d", &direcao);
   }//fim while
   if ( fexistepos( v, n, dado, posicao, direcao)==-1)
   {
      printf("\nO valor nao foi encontrado");
   }
   else
   {
      printf("\nO valor foi encontrado na posicao %d", fexistepos( v, n, dado, posicao, direcao));
   }

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo19

/*
Metodo 20 - Exemplo20
Objetivos: Incluir em um programa (Exemplo0820) uma função para
procurar por determinado valor em arranjo e
dizer quantas vezes esse valor pode ser encontrado,
indicada a posição inicial para começar a procura.
Para testar, ler o arquivo ("DADOS.TXT"),
e armazenar os dados em arranjo;
ler do teclado um valor inteiro para ser procurado;
determinar quantas vezes o valor procurado aparece no arranjo,
se houver.
Testes: ok
*/
int fquantos ( int v[], int n, int dado, int posicao, int direcao)
{
   int i=posicao;
   int contador=0;
   int flag1 =0;
   int flag2=0;
   int dir= direcao;
   if (posicao==0 && direcao==0)
   {
      dir=1;
   }
   if (posicao==n && direcao==1)
   {
      dir=0;
   }

   
   
   while (i<n && i>=0)
   {
      
      if (dado == v[i])
      { 
         contador=contador+1;
      }//fim if
      printf("\n%d   %d",v[i], i);
      if (dir == 0)
      {
         i=i-1;
      }
      else         
      {
         i=i+1;
      } 
     
   }//fim while
   if (posicao!=0 && posicao!=n)
   {
      if (direcao ==0)
      {
         dir=1;
         i= posicao+1;
      }
      else 
      {
         dir=0;
         i= posicao-1;
      }
   
      while (i<n && i>=0)
      {
      
         if (dado == v[i])
         { 
            contador=contador+1;
         }//fim if
         printf("\n%d   %d",v[i], i);
         if (dir == 0)
         {
            i=i-1;
         }
         else         
         {
            i=i+1;
         } 
       
      }//fim while
   }//fim if

   
   
  
   return (contador);
}
void metodo20 ()
{
//identificar
   IO_id("EXEMPLO0820 - Metodo20 - v0.0");
    //tamanho
   int n= ftamanho("DADOS.TXT");
   //arranjo
   int v[n];
   farranjo("DADOS.TXT", n, v);
   //inputs
   int posicao=-1;
   int dado=0;
   while (posicao<0 || posicao>n)
   {
      printf("\n Posicao desejada = ");
      scanf("%d", &posicao);
   }//fim while
   printf("\n valor desejado a ser procurado= ");
   scanf("%d", &dado);
   int direcao= 2;
   while (direcao!=1 && direcao!=0)
   {
      printf("\n Digite 1 para procurar para frente ou 0 para tras: ");
      scanf("%d", &direcao);
   }//fim while
   //controle
   printf("\n%d\t%d\t%d", posicao, dado, direcao);
   int q= fquantos( v, n, dado, posicao, direcao);
   printf("\nO valor foi encontrado %d vezes", q);



//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo20

/*
Metodo 21 - Exemplo21
Objetivos: Incluir em um programa (Exemplo08E1) uma função para
ler um valor inteiro do teclado,
e mediante funções para calcular e retornar a quantidade
e seus divisores guardados em arranjo,
o qual deverá ser mostrado na tela após o retorno,
bem como gravado em arquivo ( "DIVISORES.TXT" ).
DICA: Supor que a quantidade de divisores
será menor ou igual ao próprio número.
Testes: ok
*/
int divisores (int v[], int y)
{
   int i=0;
   int valor=0;
   int cont=0;
   for(valor=1; valor<=y; valor++)
   {
      if(y%valor==0)
      {
         v[i]=valor;
         printf("\n%d", v[i]);
         i=i+1; 
         cont=cont+1;  
      }
   }
   int j=0;
   for(j=i+1; j<y; j++)
   {
      v[j]=0;
   }
   return (cont);
}//fim divisores

void frecordv (char* filename, int x, int v[])
{
//abrir
   FILE*arq=fopen(filename, "wt");
//gravar
   int i=0;
   for (i=0; i<x; i++)
   {
      fprintf(arq,"%d\n", v[i]);
   }//fim for
   //fechar
   fclose(arq);
}//fim frecordv
void metodo21 ()
{
//identificar
   IO_id("EXEMPLO0821 - Metodo21 - v0.0");
   int x=0;
   int y=0;
   printf("\nInserir valor inteiro= ");
   scanf ("%d", &x);
   if (x<0)
   {
      y=-x;
   }
   else
   {
      y=x;
   }
   int v[y];
   int tamanho= divisores(v, y);
   int a[tamanho];
   int i=0;
   for (i=0; i<tamanho; i++)
   {
      a[i]=v[i];
   }
   frecordv("DIVISORES.TXT", tamanho, a);   
//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo21

/*
Metodo 22 - Exemplo22
Objetivos: Incluir em um programa (Exemplo08E1) uma função para
ler um arquivo ( "PALAVRAS.TXT" ),
e mediante uma função retornar as dez primeiras palavras
que não comecem pela letra 'a' (ou 'A'), se houver.
As palavras encontradas deverão ser exibidas na tela,
após retorno.
Testes: ok
*/

void fnaoa (char* filename)
{
   FILE*arq=fopen(filename, "rt");
   if (arq==NULL)
   {
   printf("\nERRO: ARQUIVO NAO ENCONTRADO");
   }
   else
   {
   char*palavra=(char*)malloc(80*sizeof(char));
   palavra[0]='\0';
   int cont=0;
   fscanf(arq, "%s", palavra);
   while(!feof(arq) && cont<10)
   {
      if (palavra[0]!='a' && palavra[0]!='A')
      {
         printf("%s\n", palavra);
         cont=cont+1;
      }
      fscanf(arq, "%s", palavra);
   }
   fclose(arq);
}
}

void metodo22 ()
{
//identificar
   IO_id("EXEMPLO0822 - Metodo22 - v0.0");
 
   fnaoa("PALAVRAS.TXT"); 

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
                     "Lista ED08 - Fabiana Kraft - 677262", "0 - parar", "1 - Exemplo0801",
                     "2 - Exemplo0802","3 - Exemplo0803","4 - Exemplo0804","5 - Exemplo0805",
                     "6 - Exemplo0806","7 - Exemplo0807","8 - Exemplo0808","9 - Exemplo0809",
                     "10 - Exemplo0810","11 - Exemplo0811","12 - Exemplo0812","13 - Exemplo0813",
                     "14 - Exemplo0814","15 - Exemplo0815","16 - Exemplo0816","17 - Exemplo0817",
                     "18 - Exemplo0818","19 - Exemplo0819","20 - Exemplo0820","21 - Exemplo0821",
                     "22 - Exemplo0822");
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