#include "io.h"

/**
ED10 - AED1 T2 Manhã
Fabiana Kraft
677262
*/

/*
Metodo 0 - parar switch case
*/

void metodo0 ()
{
}

/**
 Definicao de tipo arranjo com inteiros
 baseado em estrutura
*/
typedef
struct s_int_Array
{
   int length;
   int* data ;
   int ix ;
}
int_Array;
/**

 Definicao de referencia para arranjo com inteiros
 baseado em estrutura

typedef int_Array* ref_int_Array;


 new_int_Array - Reservar espaco para arranjo com inteiros
 @return referencia para arranjo com inteiros
 @param n - quantidade de datos

ref_int_Array new_int_Array ( int n )
{
// reserva de espaco
   ref_int_Array tmpArray = (ref_int_Array) malloc (sizeof(int_Array));
// estabelecer valores padroes
   if ( tmpArray == NULL )
   {
      IO_printf ( "\nERRO: Falta espaco.\n" );
   }
   else
   {
      tmpArray->length = 0;
      tmpArray->data = NULL;
      tmpArray->ix = -1;
      if ( n>0 )
      {
      // guardar a quantidade de dados
         tmpArray->length = n;
      // reservar espaco para os dados
         tmpArray->data = (ints) malloc (n * sizeof(int));
      // definir indicador do primeiro elemento
         tmpArray->ix = 0;
      } // fim se
   } // fim se
// retornar referencia para espaco reservado
   return ( tmpArray );
} // fim


 free_int_Array - Dispensar espaco para arranjo com inteiros
 @param tmpArray - referencia para grupo de valores inteiros

void free_int_Array ( ref_int_Array tmpArray )
{
// testar se ha' dados
   if ( tmpArray != NULL )
   {
      free ( tmpArray->data );
      free ( tmpArray );
   } // fim se
} // fim free_int_Array ( )
*/
/**
 printIntArray - Mostrar arranjo com valores inteiros.
 @param array - grupo de valores inteiros
*/
void printIntArray ( int_Array array )
{
// mostrar valores no arranjo
   for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
   {
   // mostrar valor
      printf ( "%2d: %d\n", array.ix, array.data [ array.ix ] );
   } // fim repetir
} // printIntArray ( )


/*
Metodo 1 - Exemplo01
Objetivos
Testes: OK
*/
void metodo1 ()
{
//identificar
   IO_id("EXEMPLO1001 - Metodo01 - v0.0");
   
   // definir dado
   int_Array array;
// montar arranjo em estrutura
   array. length = 5;
   array. data = (ints) malloc (array.length * sizeof(int));
   array. data [ 0 ] = 1;
   array. data [ 1 ] = 2;
   array. data [ 2 ] = 3;
   array. data [ 3 ] = 4;
   array. data [ 4 ] = 5;

// executar o metodo auxiliar
   printIntArray ( array );


//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo1

/**
 IO_readintArray - Ler arranjo com valores inteiros.
 @return arranjo com valores lidos
*/
int_Array IO_readintArray ( )
{
// definir dados locais
   chars text = IO_new_chars ( STR_SIZE );
   static int_Array array;
// ler a quantidade de dados
   do
   {
      array.length = IO_readint ( "\nlength = " );
   }
   while ( array.length <= 0 );
// reservar espaco para armazenar
   array.data = (int*)malloc( array.length*sizeof(int) );
// testar se ha' espaco
   if ( array.data == NULL )
   {
      array.length = 0; // nao ha' espaco
   }
   else
   {
   // ler e guardar valores em arranjo
      for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
      {
      // ler valor
         //strcpy ( text, STR_EMPTY );
         //array.data [ array.ix ]
            //= IO_readint ( IO_concat (
            //IO_concat ( text, IO_toString_d ( array.ix ) ), " : " ) );
         printf("[%d]: ", array.ix);
         scanf("%d", &array.data[array.ix]);
      } // fim repetir
   } // fim se
// retornar arranjo
   return ( array );
} // IO_readintArray ( )
/*
Metodo 2 - Exemplo02
Objetivos
Testes: OK
*/
void metodo2 ()
{
//identificar
   IO_id("EXEMPLO1002 - Metodo02 - v0.0");
   // definir dados
   int_Array array;

// ler dados
   array = IO_readintArray ( );
// mostrar dados
   IO_printf ( "\n" );
   printIntArray ( array );


//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo2

/*
Metodo 3 - Exemplo03
Objetivos
Testes: OK
*/
/**
 fprintIntArray - Gravar arranjo com valores inteiros.
 @param fileName - nome do arquivo
 @param array - grupo de valores inteiros
*/
void fprintIntArray ( chars fileName, int_Array array )
{
// definir dados locais
   FILE* arquivo = fopen ( fileName, "wt" );
// gravar quantidade de dados
   fprintf ( arquivo, "%d\n", array.length );
// gravar valores no arquivo
   for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
   {
   // gravar valor
      fprintf ( arquivo, "%d\n", array.data [ array.ix ] );
   } // fim repetir

// fechar arquivo
   fclose ( arquivo );
} // fprintIntArray ( )
void metodo3 ()
{
//identificar
   IO_id("EXEMPLO1003 - Metodo03 - v0.0");;
// definir dados
   int_Array array;
 // ler dados
   array = IO_readintArray ( );
// mostrar dados
   IO_printf ( "\n" );
   fprintIntArray ( "ARRAY1.TXT", array );
//terminar
   IO_pause("Apertar enter para continuar");;
}// fim metodo3

/*
Metodo 4 - Exemplo04
Objetivos
Testes: OK
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
   fscanf ( arquivo, "%d", &n );
   if ( n <= 0 )
   {
      IO_printf ( "\nERRO: Valor invalido.\n" );
      n = 0;
   } // fim se
// retornar dados lidos
   return ( n );
} // freadArraySize ( )

int_Array fIO_readintArray ( chars fileName )
{
// definir dados locais
   int x = 0;
   int y = 0;
   FILE* arquivo = fopen ( fileName, "rt" );
   static int_Array array;
// ler a quantidade de dados
   fscanf ( arquivo, "%d", &array.length );
// testar se ha' dados
   if ( array.length <= 0 )
   {
      IO_printf ( "\nERRO: Valor invalido.\n" );
      array.length = 0; // nao ha' dados
   }
   else
   {
   // reservar espaco
      array.data = IO_new_ints ( array.length );
   // ler e guardar valores em arranjo
      array.ix = 0;
      while ( ! feof ( arquivo ) &&
      array.ix < array.length )
      {
      // ler valor
         fscanf ( arquivo, "%d", &(array.data [ array.ix ]) );
      // passar ao proximo
         array.ix = array.ix + 1;
      } // fim repetir
   } // fim se
// retornar dados lidos
   return ( array );
} // fIO_readintArray ( )


void metodo4 ()
{
//identificar
   IO_id("EXEMPLO1004 - Metodo04 - v0.0");
   
   // definir dados
   int_Array array; // arranjo sem tamanho definido

// ler dados
   array = fIO_readintArray ( "ARRAY1.TXT" );
// mostrar dados
   IO_printf ( "\n" );
   printIntArray ( array );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo4

/*
Metodo 5 - Exemplo05
Objetivos
Testes: OK
*/

/**
 copyIntArray - Copiar arranjo com valores inteiros.
 @return oopia do arranjo
 @param fileName - nome do arquivo
 @param array - grupo de valores inteiros
*/
int_Array copyIntArray ( int_Array array )
{
// definir dados locais
   int x = 0;
   int y = 0;
   static int_Array copy;
   if ( array.length <= 0 )
   {
      IO_printf ( "\nERRO: Valor invalido.\n" );
      array.length = 0;
   }
   else
   {
   // reservar area
      copy.length = array.length;
      copy.data = IO_new_ints ( copy.length );
   // testar se ha' espaco e dados
      if ( copy.data == NULL || array.data == NULL )
      {
         printf ( "\nERRO: Falta espaco ou dados." );
      }
      else
      {
      // ler e copiar valores
         for ( array.ix=0; array.ix<array.length; array.ix=array.ix+1 )
         {
         // copiar valor
            copy.data [ array.ix ] = array.data [ array.ix ];
         } // fim repetir
      } // fim se
   } // fim se
// retornar dados lidos
   return ( copy );
} // copyIntArray ( )


void metodo5 ()
{
//identificar
   IO_id("EXEMPLO1005 - Metodo05 - v0.0");
   
   // definir dados
   int_Array array; // arranjo sem tamanho definido
   int_Array other; // arranjo sem tamanho definido

// ler dados
   array = fIO_readintArray ( "ARRAY1.TXT" );
// copiar dados
   other = copyIntArray ( array );
// mostrar dados
   IO_printf ( "\nOriginal\n" );
   printIntArray ( array );
// mostrar dados
   IO_printf ( "\nCopia\n" );
   printIntArray ( other );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo5

/*
Metodo 6 - Exemplo06
Objetivos
Testes: OK
*/
/**
 Definicao de tipo arranjo bidimensional com inteiros baseado em estrutura
*/
typedef
struct s_int_Matrix
{
   int lines ;
   int columns;
   ints* data ;
   int ix, iy ;
}
int_Matrix;
/**
 Definicao de referencia para arranjo bidimensional com inteiros baseado em estrutura
*/
typedef int_Matrix* ref_int_Matrix;
/**
 new_int_Matrix - Reservar espaco para arranjo bidimensional com inteiros
 @return referencia para arranjo com inteiros
 @param lines - quantidade de dados
 @param columns - quantidade de dados
*/
ref_int_Matrix new_int_Matrix ( int lines, int columns )
{
// reserva de espaco
   ref_int_Matrix tmpMatrix = (ref_int_Matrix) malloc (sizeof(int_Matrix));
// estabelecer valores padroes
   if ( tmpMatrix != NULL )
   {
      tmpMatrix->lines = 0;
      tmpMatrix->columns = 0;
      tmpMatrix->data = NULL;
   // reservar espaco
      if ( lines>0 && columns>0 )
      {
         tmpMatrix->lines = lines;
         tmpMatrix->columns = columns;
         tmpMatrix->data = malloc (lines * sizeof(ints));
         for ( tmpMatrix->ix=0;
         tmpMatrix->ix<tmpMatrix->lines;
         tmpMatrix->ix=tmpMatrix->ix+1 )
         {
            tmpMatrix->data [ tmpMatrix->ix ] = (ints) malloc (columns * sizeof(int));
         } // fim repetir
      } // fim se
      tmpMatrix->ix = 0;
      tmpMatrix->iy = 0;
   } // fim se
   return ( tmpMatrix );
} // fim new_int_Matrix ( )
/**
 free_int_Matrix - Dispensar espaco para arranjo com inteiros
 @param tmpMatrix - referencia para grupo de valores inteiros
*/
void free_int_Matrix ( ref_int_Matrix tmpMatrix )
{
// testar se ha' dados
   if ( tmpMatrix != NULL )
   {
      for ( tmpMatrix->ix=0;
      tmpMatrix->ix<tmpMatrix->lines;
      tmpMatrix->ix=tmpMatrix->ix+1 )
      {
         free ( tmpMatrix->data [ tmpMatrix->ix ] );
      } // fim repetir
      free ( tmpMatrix->data );
      free ( tmpMatrix );
   } // fim se
} // fim free_int_Matrix ( )
/**
 printIntMatrix - Mostrar matrix com valores inteiros.
 @param array - grupo de valores inteiros
*/
void printIntMatrix ( ref_int_Matrix matrix )
{
// mostrar valores na matriz
   for ( matrix->ix=0; matrix->ix<matrix->lines; matrix->ix=matrix->ix+1 )
   {
      for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
      {
      // mostrar valor
         printf ( "%3d\t", matrix->data [ matrix->ix ][ matrix->iy ] );
      } // fim repetir
      printf ( "\n" );
   } // fim repetir
} // printIntArray ( )
void metodo6 ()
{
//identificar
   IO_id("EXEMPLO1006 - Metodo06 - v0.0");
   // definir dado
   ref_int_Matrix matrix = new_int_Matrix ( 3, 3 );
   matrix->data [0][0] = 1; matrix->data [0][1] = 2; matrix->data [0][2] = 3;
   matrix->data [1][0] = 3; matrix->data [1][1] = 4; matrix->data [1][2] = 5;
   matrix->data [2][0] = 6; matrix->data [2][1] = 7; matrix->data [2][2] = 8;

// executar o metodo auxiliar
   printIntMatrix ( matrix );
// reciclar espaco
   free_int_Matrix ( matrix );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo6

/*
Metodo 7 - Exemplo07
Objetivos
Testes: OK
*/

/**
 IO_readintMatrix - Ler arranjo bidimensional com valores inteiros.
 @return referencia para o grupo de valores inteiros
*/
ref_int_Matrix IO_readintMatrix ( )
{
// definir dados locais
   int lines = 0;
   int columns = 0;
   int z = 0;
   chars text = IO_new_chars ( STR_SIZE );
// ler a quantidade de dados
   do
   { lines = IO_readint ( "\nlines = " ); }
   while ( lines <= 0 );
   do
   { columns = IO_readint ( "\ncolumns = " ); }
   while ( columns <= 0 );
// reservar espaco para armazenar valores
   ref_int_Matrix matrix = new_int_Matrix ( lines, columns );
// testar se ha' espaco
   if ( matrix->data == NULL )
   {
   // nao ha' espaco
      matrix->lines = 0;
      matrix->columns = 0;
      matrix->ix = 0;
      matrix->iy = 0;
   }
   else
   {
   // ler e guardar valores na matriz
      for ( matrix->ix=0; matrix->ix<matrix->lines; matrix->ix=matrix->ix+1 )
      {
         for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
         {
         // ler e guardar valor
            strcpy ( text, STR_EMPTY );
            matrix->data [ matrix->ix ][ matrix->iy ]
               = IO_readint ( IO_concat (
               IO_concat ( IO_concat ( text, IO_toString_d ( matrix->ix ) ), ", " ),
               IO_concat ( IO_concat ( text, IO_toString_d ( matrix->iy ) ), " : " ) ) );
         } // fim repetir
         printf ( "\n" );
      } // fim repetir
   } // fim se
// retornar dados lidos
   return ( matrix );
} // IO_readintMatrix ( )
void metodo7 ()
{
//identificar
   IO_id("EXEMPLO1007 - Metodo07 - v0.0");
   // definir dados
   ref_int_Matrix matrix = NULL;

// ler dados
   matrix = IO_readintMatrix ( );
// mostrar dados
   IO_printf ( "\n" );
   printIntMatrix ( matrix );
// reciclar espaco
   free_int_Matrix ( matrix );


//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo7

/*
Metodo 8 - Exemplo08
Objetivos
Testes: OK
*/
/**
 fprintIntMatrix - Gravar arranjo bidimensional com valores inteiros.
 @param fileName - nome do arquivo
 @param matrix - grupo de valores inteiros
*/
void fprintIntMatrix ( chars fileName, ref_int_Matrix matrix )
{
// definir dados locais
   FILE* arquivo = fopen ( fileName, "wt" );
// testar se ha' dados
   if ( matrix == NULL )
   {
      printf ( "\nERRO: Nao ha' dados." );
   }
   else
   {
   // gravar quantidade de dados
      fprintf ( arquivo, "%d\n", matrix->lines );
      fprintf ( arquivo, "%d\n", matrix->columns );
   // gravar valores no arquivo
      for ( matrix->ix=0; matrix->ix<matrix->lines; matrix->ix=matrix->ix+1 )
      {
         for ( matrix->iy=0; matrix->iy<matrix->columns; matrix->iy=matrix->iy+1 )
         {
         // gravar valor
            fprintf ( arquivo, "%d\n", matrix->data [ matrix->ix ][ matrix->iy ] );
         } // fim repetir
      } // fim repetir
   // fechar arquivo
      fclose ( arquivo );
   } // fim se
} // fprintIntMatrix ( )
void metodo8 ()
{
//identificar
   IO_id("EXEMPLO1008 - Metodo08 - v0.0");
   // definir dados
   ref_int_Matrix matrix = NULL;

// ler dados
   matrix = IO_readintMatrix ( );
// gravar dados
   fprintIntMatrix( "MATRIX1.TXT", matrix );
// reciclar espaco
   free_int_Matrix ( matrix );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo8

/*
Metodo 9 - Exemplo09
Objetivos
Testes: OK
*/

/**
 freadintMatrix - Ler arranjo bidimensional com valores inteiros.
 @return referencia para o grupo de valores inteiros
 @param fileName - nome do arquivo
*/
ref_int_Matrix freadintMatrix ( chars fileName )
{
// definir dados locais
   ref_int_Matrix matrix = NULL;
   int lines = 0;
   int columns = 0;
   FILE* arquivo = fopen ( fileName, "rt" );
// ler a quantidade de dados
   fscanf ( arquivo, "%d", &lines );
   fscanf ( arquivo, "%d", &columns );
   if ( lines <= 0 || columns <= 0 )
   {
      IO_printf ( "\nERRO: Valor invalido.\n" );
   }
   else
   {
   // reservar espaco para armazenar
      matrix = new_int_Matrix ( lines, columns );
   // testar se ha' espaco
      if ( matrix->data == NULL )
      {
      // nao ha' espaco
         matrix->lines = 0;
         matrix->columns = 0;
         matrix->ix = 0;
         matrix->iy = 0;
      }
      else
      {
      // ler e guardar valores na matriz
         matrix->ix = 0;
         while ( ! feof ( arquivo ) && matrix->ix < matrix->lines )
         {
            matrix->iy = 0;
            while ( ! feof ( arquivo ) && matrix->iy < matrix->columns )
            {
            // guardar valor
               fscanf ( arquivo, "%d", &(matrix->data [ matrix->ix ][ matrix->iy ]) );
            // passar ao proximo
               matrix->iy = matrix->iy+1;
            } // fim repetir
         // passar ao proximo
            matrix->ix = matrix->ix+1;
         } // fim repetir
         matrix->ix = 0;
         matrix->iy = 0;
      } // fim se
   } // fim se
// retornar matriz lida
   return ( matrix );
} // fim freadintMatrix ( )
void metodo9 ()
{
//identificar
   IO_id("EXEMPLO1009 - Metodo09 - v0.0");
   // ler dados
   ref_int_Matrix matrix = freadintMatrix ( "MATRIX1.TXT" );
// mostrar dados
   IO_printf ( "\n" );
   printIntMatrix ( matrix );
// reciclar espaco
   free_int_Matrix ( matrix );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo9

/*
Metodo 10 - Exemplo10
Objetivos
Testes: OK
*/
/**
 copyIntMatrix - Copiar matriz com valores inteiros.
 @return referencia para o grupo de valores inteiros
*/
ref_int_Matrix copyIntMatrix ( ref_int_Matrix matrix )
{
// definir dados locais
   ref_int_Matrix copy = NULL;
   if ( matrix == NULL || matrix->data == NULL )
   {
      IO_printf ( "\nERRO: Faltam dados.\n" );
   }
   else
   {
      if ( matrix->lines <= 0 || matrix->columns <= 0 )
      {
         IO_printf ( "\nERRO: Valor invalido.\n" );
      }
      else
      {
      // reservar espaco
         copy = new_int_Matrix ( matrix->lines, matrix->columns );
      // testar se ha' espaco e dados
         if ( copy == NULL || copy->data == NULL )
         {
            printf ( "\nERRO: Falta espaco." );
         }
         else
         {
         // copiar valores
            for ( copy->ix = 0; copy->ix < copy->lines; copy->ix = copy->ix + 1 )
            {
               for ( copy->iy = 0; copy->iy < copy->columns; copy->iy = copy->iy + 1 )
               {
               // copiar valor
                  copy->data [ copy->ix ][ copy->iy ]
                     = matrix->data [ copy->ix ][ copy->iy ];
               } // fim repetir
            } // fim repetir
         } // fim se
      } // fim se
   } // fim se

// retornar copia
   return ( copy );
} // copyIntMatrix ( )
void metodo10 ()
{
//identificar
   IO_id("EXEMPLO1010 - Metodo10 - v0.0");
   // definir dados
   ref_int_Matrix matrix = NULL;
   ref_int_Matrix other = NULL;
// identificar
   IO_id ( "EXEMPLO1010 - Method10 - v0.0" );
// ler dados
   matrix = freadintMatrix ( "MATRIX1.TXT" );
// copiar dados
   other = copyIntMatrix ( matrix );
// mostrar dados
   IO_printf ( "\nOriginal\n" );
   printIntMatrix ( matrix );
// mostrar dados
   IO_printf ( "\nCopia\n" );
   printIntMatrix ( other );
// reciclar espaco
   free_int_Matrix ( matrix );
   free_int_Matrix ( other );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo10

/*
Metodo 11 - Exemplo11
Objetivos
Testes: OK
*/

//definir struct
typedef struct gerarint
{
   int size;
   int ix;
   int *dados;
   int inferior;
   int superior;
}Struct11;

  


void printar (Struct11 x)
{
   for(x.ix=0; x.ix<x.size; x.ix++)
   {
      printf("\n%d: %d", x.ix, x.dados[x.ix]);
   }
}



Struct11 Gerarint (int inferior, int superior )
{
// definir dados locais
   
   static Struct11 x;
// ler a quantidade de dados
   do
   {
      printf("Tamanho= ");
      scanf("%d", &x.size) ;
   }
   while ( x.size <= 0 );
// reservar espaco para armazenar
   x.dados = (int*)malloc(x.size*sizeof(int));
// testar se ha' espaco
   if ( x.dados == NULL )
   {
      x.size = 0; // nao ha' espaco
   }
   else
   {
   // ler e guardar valores em arranjo
      for ( x.ix=0; x.ix<x.size; x.ix=x.ix+1 )
      {
      // ler valor
         
         x.dados [ x.ix ]
            = inferior+(rand()%superior);
           // printf("%d\n", x.dados[x.ix]);
      } // fim repetir
   } // fim se
// retornar arranjo
   return ( x );
} // IO_readintArray ( )

void salvar (char* Filename, Struct11 x)
{
   FILE*arq=fopen(Filename, "wt");
   fprintf(arq,"%d\n",x.size);
 
   for (x.ix=0; x.ix<x.size; x.ix=x.ix+1)
   {
      fprintf(arq,"%d\n",x.dados[x.ix]);
      
   }
   fclose(arq);
}

void metodo11 ()
{
//identificar
   IO_id("EXEMPLO1011 - Metodo11 - v0.0");
   
    //determinar
   Struct11 x;
  
     
   //ler
   do
   {
      printf("\nInferior= ");
      scanf("%d", &x.inferior);
      printf("\nSuperior= ");
      scanf("%d", &x.superior);
   }
   while(x.inferior>=x.superior);  
        
   
   x= Gerarint(x.inferior, x.superior);
   printar(x);
   salvar("DADOS.TXT", x);
  
//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo11

/*
Metodo 12 - Exemplo12
Objetivos
Testes: OK
*/

typedef struct struct12{
   int size;
   int*dados;
   int ix;
   bool s;
}Struct12;

Struct12 lerarquivo (char* FileName)
{
//abrir para ler
   FILE*arq=fopen(FileName, "rt");
   if (arq==NULL)
   {
      printf(" \nERRO: ARQUIVO NAO ENCONTRADO\n");
   }
   else
   {
   //DELCARAR
      static Struct12 x;
   //ler size
      fscanf(arq, "%d",&x.size);
      //alocar para dados
      x.dados=(int*)malloc(x.size*sizeof(int));
   //ler primeiro
      x.ix=0;
      while(x.ix<x.size && !feof(arq))
      {
      
         fscanf(arq, "%d", &x.dados[x.ix]);
         //printf("%d\n",x.dados[x.ix]);
         x.ix=x.ix+1;
         
      }
      return(x);
   }
//fechar
   fclose(arq);
   
}

void printar12 (Struct12 x)
{

   for(x.ix=0; x.ix<x.size; x.ix++)
   {
      printf("\n%d: %d", x.ix, x.dados[x.ix]);
   }
   
}

bool search12 (Struct12 x, int n)
{
   x.s=false;
   for(x.ix=0; x.ix<x.size; x.ix++)
   {
      if ( x.dados[x.ix]==n)
      {
         x.s=true;
         x.ix=x.size;
      }
   }
   return(x.s);
   
}

void metodo12 ()
{
//identificar
   IO_id("EXEMPLO1012 - Metodo12 - v0.0");
   
  //declarar
   Struct12 x;
   //pegar array
   x=lerarquivo("DADOS.TXT");
   printar12(x);   
   
   int n=0;
   printf("\nNumero a ser procurado: ");
   scanf("%d", &n);
   
   printf("Encontrou o numero %d: %d", n, x.s=search12(x,n));

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo12

/*
Metodo 13 - Exemplo13
Objetivos
Testes: OK
*/
typedef struct Struct13
{
   int *dados;
   int ix;
   int size;
}Struct13;

Struct13 lerarquivo13 (char* FileName)
{
//abrir para ler
   FILE*arq=fopen(FileName, "rt");
   if (arq==NULL)
   {
      printf(" \nERRO: ARQUIVO NAO ENCONTRADO\n");
   }
   else
   {
   //DELCARAR
      static Struct13 x;
   //ler size
      fscanf(arq, "%d",&x.size);
      //alocar para dados
      x.dados=(int*)malloc(x.size*sizeof(int));
      
      if ( x.size<=0 && x.dados==NULL)
      {
         printf("\nVetor sem espaco");  // nao ha' espaco
      }
      else
      {
      
      //ler primeiro
         x.ix=0;
         while(x.ix<x.size && !feof(arq))
         {
         
            fscanf(arq, "%d", &x.dados[x.ix]);
         //printf("%d\n",x.dados[x.ix]);
            x.ix=x.ix+1;
         
         }
         return(x);
      }
   }
//fechar
   fclose(arq);
   
}

bool comparar( Struct13 x, Struct13 y)
{
   bool teste=true;
   if (x.size!=y.size)
   {
      teste=false;
   }
   else
   {
      for (x.ix=0; x.ix<x.size; x.ix=x.ix+1)
      {
         if (x.dados[x.ix]!=y.dados[x.ix])
         {
         
            teste=false;
            x.ix=x.size;
         }
      }
   }
   return(teste);
}

void metodo13 ()
{
//identificar
   IO_id("EXEMPLO1013 - Metodo13 - v0.0");
   Struct13 x;
   Struct13 y;
   x= lerarquivo13("DADOS1.TXT");
   //printf("\n next");
   y=lerarquivo13("DADOS2.TXT");
   printf("Os dois arrays sao iguais? R: %d", comparar(x,y));
   

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo13

/*
Metodo 14 - Exemplo14
Objetivos
Testes: OK
*/
Struct13 soma (Struct13 x, Struct13 y, int k)
{
   int soma=0;
   static Struct13 s;
   if (x.size!=y.size)
   {
      printf("\nERRO: tamanhos diferentes\n");
      s.size=0;
   }
   else
   {
   //alocar memo
      s.dados=(int*)malloc(x.size*sizeof(int));
      s.size=x.size;
   
      for (x.ix=0; x.ix<x.size; x.ix=x.ix+1)
      {
      
         s.dados[x.ix]=x.dados[x.ix]+k*(y.dados[x.ix]);
         //printf("%d= %d+%d*%d\n", s.dados[x.ix], x.dados[x.ix], k, y.dados[x.ix]);
         soma=soma+s.dados[x.ix];
      }
      printf("Soma= %d\n", soma);
      return(s);
   }
}

void print13 (Struct13 x)
{
   for(x.ix=0; x.ix<x.size; x.ix++)
   {
      printf("%d\t", x.dados[x.ix]);
   }
}

void metodo14 ()
{
//identificar
   IO_id("EXEMPLO1014 - Metodo14 - v0.0");
   Struct13 x;
   Struct13 y;
   Struct13 s;
   int k=0;
   x= lerarquivo13("DADOS1.TXT");
   //printf("\n next");
   y=lerarquivo13("DADOS2.TXT");
   printf("\nConstante= ");
   scanf("%d", &k);
   s=soma(x,y,k);
   print13(s);
      

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo14

/*
Metodo 15 - Exemplo15
Objetivos
Testes: OK
*/

bool testeordem (Struct13 x)
{
   bool teste = true;
   for(x.ix=1; x.ix<x.size; x.ix++)
   {
   
      if (x.dados[x.ix]>x.dados[x.ix+1])
      {
      
         teste=false;
         x.ix=x.size;
      }
   }
   
   return(teste);
}

Struct13 ordena (Struct13 x)
{
   int t=10;
   int temp=0;
   Struct13 xc;
   xc.size=x.size;
   xc.dados=(int*)malloc(xc.size*sizeof(int));

   for(x.ix=0; x.ix<x.size; x.ix++)
   {
      xc.dados[x.ix]=x.dados[x.ix];
     
     
   }
   
   for(x.ix=1; x.ix<x.size; x.ix++)
   {
      for(xc.ix=0; xc.ix<xc.size-1; xc.ix++)
      {  
         
         if (xc.dados[xc.ix]>xc.dados[xc.ix+1])
         {
               
            temp=xc.dados[xc.ix];
            xc.dados[xc.ix]=xc.dados[xc.ix+1];
            xc.dados[xc.ix+1]=temp;
         }
      }
       
   }
   return(xc);
   
}

void metodo15 ()
{
//identificar
   IO_id("EXEMPLO1015 - Metodo15 - v0.0");
   
   Struct13 x;
   Struct13 y;
   int teste=0;
   x= lerarquivo13("DADOS1.TXT");
   teste= testeordem(x);
   print13(x);
   
   if (teste==false)
   {
   
      y=ordena(x);
   }
   printf("\n");
   print13(y);

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo15

/*
Metodo 16 - Exemplo16
Objetivos
Testes: OK 
*/
typedef struct matriz14
{
   int C;
   int L;
   int**dado;
   int i;
   int j;
}mast;

mast teste1 ()
{
   int L=2;
   int C=3;
   
   int cont=0;
   static mast teste;
   teste.L=2;
   teste.C=3;
   teste.dado=(int**)malloc(L*sizeof(int*));
   
   for(teste.i=0; teste.i < C; teste.i++)
   {
      teste.dado[teste.i]=(int*)malloc(C*sizeof(int));
   }
   for(teste.i=0; teste.i<L; teste.i++)
   {
      for (teste.j=0;teste.j<C;teste.j++)
      {
         teste.dado[teste.i][teste.j]=cont;
         cont=cont+1;
      }
   }
   return(teste);
  
}

void printmatriz (mast m)
{
   for(m.i=0; m.i<m.L; m.i++)
   {
      for (m.j=0;m.j<m.C;m.j++)
      {
         printf("%3d\t", m.dado[m.i][m.j]);
      }
      printf("\n");
   }
}

mast lerarqm (char* FileName)
{

   FILE*arq=fopen(FileName, "rt");
   if(arq==NULL)
   {
      printf("\nERRO: arquivo nao encontrado\n");
      fclose(arq);
   }
   else
   {
   
      static mast M;
      fscanf(arq, "%d", &M.L);
      fscanf(arq, "%d", &M.C);
      
      M.dado=(int**)malloc(M.L*sizeof(int*));
      for(M.i=0;M.i<M.L;M.i++)
      {
         M.dado[M.i]=(int*)malloc(M.C*sizeof(int));
      }
      
      M.i=0;
      while(M.i<M.L && !feof(arq))
      {
      
         for(M.j=0;M.j<M.C;M.j++)
         {
            fscanf(arq, "%d", &M.dado[M.i][M.j]);
            
         }
         M.i=M.i+1;
         
      }
      fclose(arq);
      return(M);
   }

}

bool tamanhofile (char*Filename)
{

   FILE*arq=fopen(Filename, "rt");
   bool teste=true;
   if(arq==NULL)
   {
      teste=false;
      
   }
   else
   {
   
      int l=0;
      int c=0;
      
      fscanf(arq,"%d",&l);
     
      fscanf(arq,"%d",&c);
     
      int cont=-1;
      int x=0;
      
      while(!feof(arq))
      {
       
         cont=cont+1;
         fscanf(arq, "%d", &x);
         
      }
      if (cont!=l*c)
      {
      
         teste=false;
      }
   }
   fclose(arq);
   return(teste);
}

mast transp (mast m)
{
   mast t;
   t.C=m.L;
   t.L=m.C;
   t.dado=(int**)malloc(t.L*sizeof(int*));
   for(t.i=0;t.i<t.L;t.i++)
   {
      t.dado[t.i]=(int*)malloc(t.C*sizeof(int));
   }
   for(t.i=0;t.i<t.L;t.i++)
   {
      for(t.j=0;t.j<t.C;t.j++)
      {
         t.dado[t.i][t.j]=m.dado[t.j][t.i];
      }
   }
   return(t);
}

mast zeros()
{
   int L=2;
   int C=3;
   
   static mast teste;
   teste.L=2;
   teste.C=3;
   teste.dado=(int**)malloc(L*sizeof(int*));
   
   for(teste.i=0; teste.i < C; teste.i++)
   {
      teste.dado[teste.i]=(int*)malloc(C*sizeof(int));
   }
   for(teste.i=0; teste.i<L; teste.i++)
   {
      for (teste.j=0;teste.j<C;teste.j++)
      {
         teste.dado[teste.i][teste.j]=0;
      }
   }
   return(teste);
  
}

void metodo16 ()
{
//identificar
   IO_id("EXEMPLO1016 - Metodo16 - v0.0");
   if(tamanhofile("DADOSM1.TXT"))
   {
      mast M;
      mast T;
      M=lerarqm("DADOSM1.TXT");
      printmatriz(M);
      printf("\n");
      T=transp(M);
      printmatriz(T);   
   }
   else
   {
      printf("\nDimensoes nao condizentes no arquivo");
   }

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo16

/*
Metodo 17 - Exemplo17
Objetivos
Testes: OK
*/

bool iszeros (mast m)
{
   bool teste=true;
   for(m.i=0; m.i<m.L; m.i++)
   {
      for (m.j=0;m.j<m.C;m.j++)
      {
         if(m.dado[m.i][m.j]!=0)
         {
            teste=false;
            m.j=m.C;
            m.i=m.L;
         }
      }
      
   }
   return(teste);
}

void metodo17 ()
{
//identificar
   IO_id("EXEMPLO1017 - Metodo17 - v0.0");
   if(tamanhofile("DADOSM1.TXT"))
   {
      mast M;
      mast Z=zeros();
   
      M=lerarqm("DADOSM1.TXT");
      printmatriz(M);
      printf("\nContem so zeros?: %d", iszeros(M));
      printf("\nContem so zeros?teste positivo: %d", iszeros(Z));
     
   }
   else
   {
      printf("\nDimensoes nao condizentes no arquivo");
   }


//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo17

/*
Metodo 18 - Exemplo18
Objetivos
Testes: OK
*/

bool compare (mast m, mast n)
{
   bool teste=true;
   if(m.L!=n.L && m.C!=n.C)
   {
      teste=false;
   }
   else
   {
      for(m.i=0; m.i<m.L; m.i++)
      {
         for (m.j=0;m.j<m.C;m.j++)
         {
            if(m.dado[m.i][m.j]!=n.dado[m.i][m.j])
            {
               teste=false;
               m.j=m.C;
               m.i=m.L;
            }
         }
      
      }
   }
   return(teste);
}

void metodo18 ()
{
//identificar
   IO_id("EXEMPLO1018 - Metodo18 - v0.0");
   if(tamanhofile("DADOSM1.TXT") && tamanhofile("DADOSM2.TXT") )
   {
      mast M;
      mast N;
   
      N=lerarqm("DADOSM2.TXT");
      M=lerarqm("DADOSM1.TXT");
      printf("\nSao iguais?: %d", compare(M, N));
     
   }
   else
   {
      printf("\nDimensoes nao condizentes no arquivo");
   }


//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo18

/*
Metodo 19 - Exemplo19
Objetivos
Testes: OK
*/

mast somam (mast m, mast n)
{
   mast s;
   s.L=m.L;
   s.C=m.C;
   s.dado=(int**)malloc(s.L*sizeof(int*));
   for(s.i=0;s.i<s.L;s.i++)
   {
      s.dado[s.i]=(int*)malloc(s.C*sizeof(int));
   }
   for(s.i=0;s.i<s.L;s.i++)
   {
      for(s.j=0;s.j<s.C;s.j++)
      {
         s.dado[s.i][s.j]=m.dado[s.i][s.j]+n.dado[s.i][s.j];
      }
   }
   return(s);
}
void metodo19 ()
{
//identificar
   IO_id("EXEMPLO1019 - Metodo19 - v0.0");
   if(tamanhofile("DADOSM1.TXT") && tamanhofile("DADOSM2.TXT") )
   {
      mast M;
      mast N;
      mast S;
   
      N=lerarqm("DADOSM2.TXT");
      M=lerarqm("DADOSM1.TXT");
      if(M.C==N.C && M.L==N.L)
      {
         S=somam(M,N);
         printmatriz(S);
      }
      else
      {
         printf("\n dimensoes de matrizes incompativeis");
      }
     
   }
   else
   {
      printf("\nDimensoes nao condizentes no arquivo");
   }



//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo19

/*
Metodo 20 - Exemplo20
Objetivos
Testes: OK
*/
mast multim (mast m, mast n)
{
   static mast v;
   int soma=0;
   v.L=m.L;
   v.C=n.C;
   v.dado=(int**)malloc(v.L*sizeof(int*));
   for(v.i=0;v.i<v.L;v.i++)
   {
      v.dado[v.i]=(int*)malloc(v.C*sizeof(int));
   }
   for(v.i=0;v.i<v.L;v.i++)
   {
      for(v.j=0;v.j<v.C;v.j++)
      {
         soma=0;
         for(m.j = 0; m.j < m.C; m.j++)
         {
            soma=soma+(m.dado[v.i][m.j]*n.dado[m.j][v.j]);
            
         }
         v.dado[v.i][v.j]=soma;
         
      }
   }
   return(v);
}

void metodo20 ()
{
//identificar
   IO_id("EXEMPLO1020 - Metodo20 - v0.0");
   
   if(tamanhofile("DADOSM1.TXT") && tamanhofile("DADOSM3.TXT") )
   {
      mast M;
      mast N;
      mast v;
   
      N=lerarqm("DADOSM3.TXT");
      M=lerarqm("DADOSM1.TXT");
      if(M.C==N.L)
      {
         printmatriz(M);
         printf("\n");
         printmatriz(N);
         printf("\n");
         v=multim(M,N);
         printmatriz(v);
      }
      else
      {
         printf("\n dimensoes de matrizes incompativeis");
      }  
   }
   else
   {
      printf("\nDimensoes nao condizentes no arquivo");
   }


//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo20

/*
Metodo 21 - Exemplo21
Objetivos
Testes: OK
*/
void metodo21 ()
{
//identificar
   IO_id("EXEMPLO1021 - Metodo21 - v0.0");
   Struct13 x;
   x= lerarquivo13("DADOS1.TXT");
   print13(x);
   printf("\n");
   x=ordena(x);
   print13(x);

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo21

/*
Metodo 22 - Exemplo22
Objetivos
Testes: OK
*/
mast id (int n)
{
   static mast I;
   I.L=n;
   I.C=n;
   I.dado=(int**)malloc(I.L*sizeof(int*));
   for (I.i=0; I.i<I.L; I.i++)
   {
      I.dado[I.i]=(int*)malloc(I.C*sizeof(int));
   }
   for (I.i=0; I.i<I.L; I.i++)
   {
      for (I.j=0; I.j<I.C; I.j++)
      {
         if (I.i==I.j)
         {
            I.dado[I.i][I.j]=1;
         }
         else
         {
            I.dado[I.i][I.j]=0;
         }
      }
   }
   return (I);
}

bool isid (mast m)
{
   bool teste=true;
   if (m.L!=m.C)
   {
      teste=false;
   }
   else
   {
      for (m.i=0; m.i<m.L; m.i++)
      {
         for (m.j=0; m.j<m.C; m.j++)
         {
            if (m.i==m.j && m.dado[m.i][m.j]!=1)
            {
               teste=false; 
               m.i=m.L;
               m.j=m.L;   
            }
            else if (m.i!=m.j && m.dado[m.i][m.j]!=0)
            {
               teste=false; 
               m.i=m.L;
               m.j=m.L;
            }
         }
      }
   }
   return(teste);

}
void metodo22 ()
{
//identificar
   IO_id("EXEMPLO1022 - Metodo22 - v0.0");
   if(tamanhofile("DADOSM1.TXT") && tamanhofile("DADOSM3.TXT") )
   {
      mast M;
      mast N;
      mast v;
      mast I;
      I=id(3);
      printmatriz(I);
      printf("\n");
      N=lerarqm("DADOSM3.TXT");
      M=lerarqm("DADOSM1.TXT");
      if(M.C==N.L)
      {
         printmatriz(M);
         printf("\n");
         printmatriz(N);
         printf("\n");
         v=multim(M,N);
         printmatriz(v);
         printf("\nE matriz identidade? R: %d", isid(v));
         printf("\nE matriz identidade? Rpositiva: %d",isid(I));
      }
      else
      {
         printf("\n dimensoes de matrizes incompativeis");
      }  
   }
   else
   {
      printf("\nDimensoes nao condizentes no arquivo");
   }



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
                     "Lista ED10 - Fabiana Kraft - 677262", "0 - parar", "1 - Exemplo1001",
                     "2 - Exemplo1002","3 - Exemplo1003","4 - Exemplo1004","5 - Exemplo1005",
                     "6 - Exemplo1006","7 - Exemplo1007","8 - Exemplo1008","9 - Exemplo1009",
                     "10 - Exemplo1010","11 - Exemplo1011","12 - Exemplo1012","13 - Exemplo1013",
                     "14 - Exemplo1014","15 - Exemplo1015","16 - Exemplo1016","17 - Exemplo1017",
                     "18 - Exemplo1018","19 - Exemplo1019","20 - Exemplo1020","21 - Exemplo1021",
                     "22 - Exemplo1022");
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