#include "io.h"

/**
ED09 - AED1 T2 Manhã
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
printIntMatrix - Mostrar arranjo bidimensional com valores inteiros.
@param lines - quantidade de linhas
@param columns - quantidade de colunas
@param matrix - grupo de valores inteiros
*/
void printIntMatrix ( int lines, int columns, int matrix[][columns] )
{
// definir dado local
   int x = 0;
   int y = 0;
// mostrar valores na matriz
   for ( x=0; x<lines; x=x+1 )
   {
      for ( y=0; y<columns; y=y+1 )
      {
      // mostrar valor
         IO_printf ( "%3d\t", matrix [ x ][ y ] );
      } // fim repetir
      IO_printf ( "\n" );
   } // fim repetir
} // printIntMatrix ( )

/*
Metodo 1 - Exemplo01
Objetivos: printar matriz dada
Testes:ok
*/

void metodo1 ()
{
//identificar
   IO_id("EXEMPLO0901 - Metodo01 - v0.0");
   // definir dado
   int matrix [ ][3] = { {1, 2, 3},
   {4, 5, 6},
   {7, 8, 9}
   };

// executar o metodo auxiliar
   printIntMatrix ( 3, 3, matrix );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );

}// fim metodo1

/**
readIntMatrix - Ler arranjo bidimensional com valores inteiros.
@param lines - quantidade de linhas
@param columns - quantidade de colunas
@param matrix - grupo de valores inteiros
*/
void readIntMatrix ( int lines, int columns, int matrix[][columns] )
{
// definir dados locais
   int x = 0;
   int y = 0;
   int z = 0;
   chars text = IO_new_chars ( STR_SIZE );
// ler e guardar valores em arranjo
   for ( x=0; x<lines; x=x+1 )
   {
      for ( y=0; y<columns; y=y+1 )
      {
      // ler valor
         strcpy ( text, STR_EMPTY );
         z = IO_readint ( IO_concat (
            IO_concat ( IO_concat ( text, IO_toString_d ( x ) ), ", " ),
            IO_concat ( IO_concat ( text, IO_toString_d ( y ) ), " : " ) ) );
      // guardar valor
         matrix [ x ][ y ] = z;
      } // fim repetir
   } // fim repetir
} // readIntMatrix ( )

/*
Metodo 2 - Exemplo02
Objetivos: scanf + printf de matriz de tamanho definido
Testes:ok
*/
void metodo2 ()
{
//identificar
   IO_id("EXEMPLO0902 - Metodo02 - v0.0");
   
   // definir dados
   int n = 2; // quantidade de valores
   int matrix [ n ][ n ];

// ler dados
   readIntMatrix ( n, n, matrix );
// mostrar dados
   IO_printf ( "\n" );
   printIntMatrix ( n, n, matrix );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo2

/**
fprintIntMatrix - Gravar arranjo bidimensional com valores inteiros.
@param fileName - nome do arquivo
@param lines - quantidade de linhas
@param columns - quantidade de colunas
@param matrix - grupo de valores inteiros
*/
void fprintIntMatrix ( chars fileName, int lines, int columns, int matrix[][columns] )
{
// definir dados locais
   FILE* arquivo = fopen ( fileName, "wt" );
   int x = 0;
   int y = 0;
// gravar quantidade de dados
   IO_fprintf ( arquivo, "%d\n", lines );
   IO_fprintf ( arquivo, "%d\n", columns );
// gravar valores no arquivo
   for ( x=0; x<lines; x=x+1 )
   {
      for ( y=0; y<columns; y=y+1 )
      {
      // gravar valor
         IO_fprintf ( arquivo, "%d\n", matrix [ x ][ y ] );
      } // fim repetir
   } // fim repetir
// fechar arquivo
   fclose ( arquivo );
} // fprintIntMatrix ( )

/*
Metodo 3 - Exemplo03
Objetivos: ler linhas e colunas, ler e printar matriz, salvar no arq
Testes:ok
*/
void metodo3 ()
{
//identificar
   IO_id("EXEMPLO0903 - Metodo03 - v0.0");
   // definir dados
   int lines = 0;
   int columns = 0;
   // ler dados
   lines = IO_readint ( "\nlines = " );
   columns = IO_readint ( "\ncolumns = " );
   IO_printf ( "\n" );
   if ( lines <= 0 || columns <= 0 )                                    //linhas e colunhas tem q ser >0
   {
      IO_println ( "\nERRO: Valor invalido." );
   }
   else
   {
   // reservar espaco
      int matrix [ lines ][ columns ];
   // ler dados
      readIntMatrix ( lines, columns, matrix );
   // mostrar dados
      IO_printf ( "\n" );
      printIntMatrix ( lines, columns, matrix );
   // gravar dados
      IO_printf ( "\n" );
      fprintIntMatrix( "MATRIX1.TXT", lines, columns, matrix );
   } // fim se

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo3

/**
freadMatrixRows - Ler tamanho (linhas) da matriz com valores inteiros.
@return quantidade de linhas da matriz
@param fileName - nome do arquivo
*/
int freadMatrixRows ( chars fileName )
{
// definir dados locais
   int n = 0;
   FILE* arquivo = fopen ( fileName, "rt" );
   ints array = NULL;
// ler a quantidade de dados
   IO_fscanf ( arquivo, "%d", &n );
   if ( n <= 0 )
   {
      IO_println ( "ERRO: Valor invalido." );
      n = 0;
   } // fim se
// retornar dado lido
   return ( n );
} // freadMatrixRows ( )

/**
freadMatrixColumns - Ler tamanho (colunas) da matriz com valores inteiros.
@return quantidade de colunas da matriz
@param fileName - nome do arquivo
*/
int freadMatrixColumns ( chars fileName )
{
// definir dados locais
   int n = 0;
   FILE* arquivo = fopen ( fileName, "rt" );
// ler a quantidade de dados
   IO_fscanf ( arquivo, "%d", &n );
   IO_fscanf ( arquivo, "%d", &n );
   if ( n <= 0 )
   {
      IO_println ( "ERRO: Valor invalido." );
      n = 0;
   } // fim se
// retornar dado lido
   return ( n );
} // freadMatrixColumns ( )

/**
freadIntMatrix - Ler arranjo bidimensional com valores inteiros.
@param fileName - nome do arquivo
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix - grupo de valores inteiros
*/
void freadIntMatrix ( chars fileName, int lines, int columns, int matrix[ ][columns] )
{
// definir dados locais
   int x = 0;
   int y = 0;
   int z = 0;
   FILE* arquivo = fopen ( fileName, "rt" );
// ler a quantidade de dados
   IO_fscanf ( arquivo, "%d", &x );
   IO_fscanf ( arquivo, "%d", &y );
   if ( lines <= 0 || lines > x ||
   columns <= 0 || columns > y )
   {
      IO_println ( "ERRO: Valor invalido." );
   }
   else
   {
   // ler e guardar valores em arranjo
      x = 0;
      while ( ! feof ( arquivo ) && x < lines )
      {
         y = 0;
         while ( ! feof ( arquivo ) && y < columns )
         {
         // ler valor
            IO_fscanf ( arquivo, "%d", &z );
         // guardar valor
            matrix [ x ][ y ] = z;
         // passar ao proximo
            y = y+1;
         } // fim repetir
      // passar ao proximo
         x = x+1;
      } // fim repetir
   } // fim se
} // freadIntMatrix ( )

/*
Metodo 4 - Exemplo04
Objetivos: pegar arquivo, ler a quantidade de linhas e colunas (2 primeiras linhas) e retornar, criar matriz pra receber os 
valores e recebe-los pelo arquivo.
Testes:ok
*/
void metodo4 ()
{
//identificar
   IO_id("EXEMPLO0904 - Metodo04 - v0.0");
   // definir dados
   int lines = 0;
   int columns = 0;
// ler dados
   lines = freadMatrixRows ( "MATRIX1.TXT" );
   columns = freadMatrixColumns ( "MATRIX1.TXT" );
   if ( lines <= 0 || columns <= 0 )
   {
      IO_println ( "\nERRO: Valor invalido." );
   }
   else
   {
   // definir armazenador
      int matrix [ lines ][ columns ];
   // ler dados
      freadIntMatrix ( "MATRIX1.TXT", lines, columns, matrix );
   // mostrar dados
      IO_printf ( "\n" );
      printIntMatrix ( lines, columns, matrix );
   } // fim se

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo4

/**
copyIntMatrix - Copiar matriz com valores inteiros.
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix - grupo de valores inteiros
*/
void copyIntMatrix ( int lines, int columns,
int matrix2[ ][columns], int matrix1[ ][columns] )
{
// definir dados locais
   int x = 0;
   int y = 0;
   if ( lines <= 0 || columns <= 0 )
   {
      IO_println ( "ERRO: Valor invalido." );
   }
   else
   {
   // copiar valores em matriz
      for ( x = 0; x < lines; x = x + 1 )
      {
         for ( y = 0; y < columns; y = y + 1 )
         {
         // copiar valor
            matrix2 [ x ][ y ] = matrix1 [ x ][ y ];
         } // fim repetir
      } // fim repetir
   } // fim se
} // copyIntMatrix ( )

/*
Metodo 5 - Exemplo05
Objetivos
Testes: OK
*/
void metodo5 ()
{
//identificar
   IO_id("EXEMPLO0905 - Metodo05 - v0.0");
   
   // definir dados
   int lines = 0;
   int columns = 0;
   
   // ler dados
   lines = freadMatrixRows ( "MATRIX1.TXT" );
   columns = freadMatrixColumns ( "MATRIX1.TXT" );
   if ( lines <= 0 || columns <= 0 )
   {
      IO_println ( "\nERRO: Valor invalido." );
   }
   else
   {
   // definir armazenadores
      int matrix [ lines ][ columns ];
      int other [ lines ][ columns ];
   // ler dados
      freadIntMatrix ( "MATRIX1.TXT", lines, columns, matrix );
   // copiar dados
      copyIntMatrix ( lines, columns, other, matrix );
   // mostrar dados
      IO_printf ( "\nOriginal\n" );
      printIntMatrix ( lines, columns, matrix );
   // mostrar dados
      IO_printf ( "\nCopia\n" );
      printIntMatrix ( lines, columns, other );
   } // fim se

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo5

/*
Metodo 6 - Exemplo06
Objetivos
Testes: OK
*/
/**
transposeIntMatrix - Transpor valores inteiros em matriz.
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix2 - grupo de valores inteiros (transposto)
@param matrix1 - grupo de valores inteiros
*/
void transposeIntMatrix ( int lines, int columns,
int matrix2[ ][lines] , int matrix1[ ][columns] )
{
// definir dados locais
   int x = 0;
   int y = 0;
// percorrer a matriz
   for ( x = 0; x<lines; x=x+1 )
   {
      for ( y = 0; y<columns; y=y+1 )
      {
         matrix2[ y ][ x ] = matrix1 [ x ][ y ];
      } // fim repetir
   } // fim repetir
} // transposeIntMatrix ( )
void metodo6 ()
{
//identificar
   IO_id("EXEMPLO0906 - Metodo06 - v0.0");
   
   // definir dados
   int matrix1 [ ][2] = { {1, 0} ,
   {0, 1} };
   int matrix2 [ ][2] = { {0, 0} ,
   {0, 0} };
   int matrix3 [ ][3] = { {1, 2, 3} ,
   {4, 5, 6} };
   int matrix4 [ ][3] = { {1, 2, 3} ,
   {4, 5, 6} };

// testar dados
   IO_println ( "\nMatrix1 " );
   printIntMatrix( 2, 2, matrix1 );
   transposeIntMatrix ( 2, 2, matrix2, matrix1 );
   IO_println ( "\nMatrix2" );
   printIntMatrix( 2, 2, matrix2 );
   IO_println ( "\nMatrix3" );
   printIntMatrix( 2, 3, matrix3 );
   transposeIntMatrix ( 2, 3, matrix4, matrix3 );
   IO_println ( "\nMatrix4" );
   printIntMatrix( 3, 2, matrix4 );
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
isIdentity - Testar se matriz identidade.
@return - true, se todos os dados forem iguais a zero;
false, caso contrario
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix - grupo de valores inteiros
*/
bool isIdentity ( int lines, int columns, int matrix[ ][columns] )
{
// definir dados locais
   bool result = true;
   int x = 0;
   int y = 0;
// testar condicao de existencia
   if ( lines <= 0 || columns <= 0 ||
   lines != columns )
   {
      IO_printf ( "\nERRO: Valor invalido.\n" );
   }
   else
   {
   // testar valores na matriz
      x = 0;
      while ( x<lines && result )
      {
         y = 0;
         while ( y<columns && result )
         {
         // testar valor
            if ( x == y )
            {
               result = result && ( matrix [ x ][ y ] == 1 );
            }
            else
            {
               result = result && ( matrix [ x ][ y ] == 0 );
            } // fim se
         // passar ao proximo
            y = y + 1;
         } // fim repetir
      // passar ao proximo
         x = x + 1;
      } // fim repetir
   } // fim se
// retornar resposta
   return ( result );
} // isIdentity ( )
void metodo7 ()
{
//identificar
   IO_id("EXEMPLO0907 - Metodo07 - v0.0");
   // definir dados
   int matrix1 [ ][2] = { {0, 0} ,
   {0, 0} };
   int matrix2 [ ][3] = { {1, 2, 3} ,
   {4, 5, 6}, {4, 5, 6} };
   int matrix3 [ ][2] = { {1, 0} ,
   {0, 1} };

// testar dados
   IO_println ( "\nMatrix1" );
   printIntMatrix( 2, 2, matrix1 );
   IO_printf ( "isIdentity (matrix1) = %d", isIdentity (2, 2, matrix1) );
   IO_println ( "\nMatrix2" );
   printIntMatrix( 3, 3, matrix2 );
   IO_printf ( "isIdentity (matrix2) = %d", isIdentity (3, 3, matrix2) );
   IO_println ( "\nMatrix3" );
   printIntMatrix( 2, 2, matrix3 );
   IO_printf ( "isIdentity (matrix3) = %d", isIdentity (2, 2, matrix3) );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo7

/*
Metodo 8 - Exemplo08
Objetivos
Testes: OK
*/


/**
isEqual - Testar se matrizes iguais.
@return - true, se todos os dados forem iguais;
false, caso contrario
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix1 - grupo de valores inteiros (1)
@param matrix2 - grupo de valores inteiros (2)
*/
bool isEqual ( int lines, int columns,
int matrix1[ ][columns], int matrix2[ ][columns] )
{
// definir dados locais
   bool result = true;
   int x = 0;
   int y = 0;
// mostrar valores na matriz
   x = 0;
   while ( x<lines && result )
   {
      y = 0;
      while ( y<columns && result )
      {
      // testar valor
         result = result &&
            ( matrix1 [ x ][ y ] == matrix2 [ x ][ y ] );
      // passar ao proximo
         y = y + 1;
      } // fim repetir
   // passar ao proximo
      x = x + 1;
   } // fim repetir
// retornar resposta
   return ( result );
} // isEqual ( )
void metodo8 ()
{
//identificar
   IO_id("EXEMPLO0908 - Metodo08 - v0.0");
   
   // definir dados
   int matrix1 [ ][2] = { {0, 0} ,
   {0, 0} };
   int matrix2 [ ][2] = { {1, 2} ,
   {3, 4} };
   int matrix3 [ ][2] = { {1, 0} ,
   {0, 1} };

// testar dados
   IO_println ( "\nMatrix1" );
   printIntMatrix( 2, 2, matrix1 );
   IO_println ( "\nMatrix2" );
   printIntMatrix( 2, 2, matrix2 );
   IO_printf ( "isEqual (matrix1, matrix2) = %d",
      isEqual (2, 2, matrix1, matrix2) );
   copyIntMatrix ( 2, 2, matrix1, matrix3 );
   copyIntMatrix ( 2, 2, matrix2, matrix3 );
   IO_println ( "\nMatrix1" );
   printIntMatrix( 2, 2, matrix1 );
   IO_println ( "\nMatrix3" );
   printIntMatrix( 2, 2, matrix2 );
   IO_printf ( "isEqual (matrix1, matrix2) = %d",
      isEqual (2, 2, matrix1, matrix2) );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo8

/*
Metodo 9 - Exemplo09
Objetivos
Testes: OK
*/

/**
addIntMatrix - Somar matrizes com inteiros.
@param lines - quantidade de valores
@param columns - quantidade de valores
@param matrix3 - grupo de valores inteiros resultante
@param matrix1 - grupo de valores inteiros (1)
@param k - constante para multiplicar o segundo termo
@param matrix2 - grupo de valores inteiros (2)
*/
void addIntMatrix ( int lines, int columns,
int matrix3[ ][columns],
int matrix1[ ][columns], int k, int matrix2[ ][columns] )
{
// definir dados locais
   int x = 0;
   int y = 0;
// mostrar valores na matriz
   for ( x=0; x<lines; x=x+1 )
   {
      for ( y = 0; y < columns; y = y + 1 )
      {
      // somar valores
         matrix3 [ x ][ y ] = matrix1 [ x ][ y ] + k * matrix2 [ x ][ y ];
      } // fim repetir
   } // fim repetir
} // addIntMatrix ( )
void metodo9 ()
{
//identificar
   IO_id("EXEMPLO0909 - Metodo09 - v0.0");
   // definir dados
   int matrix1 [ ][2] = { {1, 2},
   {3, 4} };
   int matrix2 [ ][2] = { {1, 0},
   {0, 1} };
   int matrix3 [ ][2] = { {0, 0},
   {0, 0} };
// identificar
   IO_id ( "EXEMPLO0910 - Method09 - v0.0" );
// testar dados
   IO_println ( "\nMatrix1" );
   printIntMatrix( 2, 2, matrix1 );
   IO_println ( "\nMatrix2" );
   printIntMatrix( 2, 2, matrix2 );
// soamr matrizes
   addIntMatrix ( 2, 2, matrix3, matrix1, (-2), matrix2 );
   IO_println ( "\nMatrix3" );
   printIntMatrix( 2, 2, matrix3 );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
   

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo9

/*
Metodo 10 - Exemplo10
Objetivos
Testes: OK
*/

/**
mulIntMatrix - Multiplicar matrizes com inteiros.
@param lines3 - quantidade de linhas da matriz (3)
@param columns3 - quantidade de colunas da matriz (3)
@param matrix3 - grupo de valores inteiros resultante
@param lines1 - quantidade de linhas da matriz (1)
@param columns1 - quantidade de colunas da matriz (1)
@param matrix1 - grupo de valores inteiros (1)
@param lines2 - quantidade de linhas da matriz (2)
@param columns2 - quantidade de colunas da matriz (2)
@param matrix2 - grupo de valores inteiros (2)
*/
void mulIntMatrix ( int lines3, int columns3,
int matrix3[ ][columns3],
int lines1, int columns1,
int matrix1[ ][columns1],
int lines2, int columns2,
int matrix2[ ][columns2] )
{
// definir dados locais
   int x = 0;
   int y = 0;
   int z = 0;
   int soma = 0;
   if ( lines1 <= 0 || columns1 == 0 ||
   lines2 <= 0 || columns2 == 0 ||
   lines3 <= 0 || columns3 == 0 ||
   columns1 != lines2 ||
   lines1 != lines3 ||
   columns2 != columns3 )
   {
      IO_printf ( "\nERRO: Valor invalido.\n" );
   }
   else
   {
   // percorrer valores na matriz resultante
      for ( x=0; x<lines3; x=x+1 )
      {
         for ( y = 0; y < columns3; y = y + 1 )
         {
         // somar valores
            soma = 0;
            for ( z = 0; z < columns1; z = z + 1 )
            {
               soma = soma + matrix1 [ x ][ z ] * matrix2 [ z ][ y ];
            } // fim repetir
         // guardar a soma
            matrix3 [ x ][ y ] = soma;
         } // fim repetir
      } // fim repetir
   } // fim se
} // mulIntMatrix ( )
void metodo10 ()
{
//identificar
   IO_id("EXEMPLO0910 - Metodo10 - v0.0");
   
   // definir dados
   int matrix1 [ ][2] = { {1, 2},
   {3, 4} };
   int matrix2 [ ][2] = { {1, 0},
   {0, 1} };
   int matrix3 [ ][2] = { {0, 0},
   {0, 0} };
// identificar
   IO_id ( "EXEMPLO0910 - Method09 - v0.0" );
// testar produto
   IO_println ( "\nMatrix1" );
   printIntMatrix( 2, 2, matrix1 );
   IO_println ( "\nMatrix2" );
   printIntMatrix( 2, 2, matrix2 );
// multiplicar matrizes
   mulIntMatrix ( 2, 2, matrix3, 2, 2, matrix1, 2, 2, matrix2 );
   IO_println ( "\nMatrix3 = Matrix1 * Matrix2" );
   printIntMatrix( 2, 2, matrix3 );
// outro teste
   IO_println ( "\nMatrix2" );
   printIntMatrix( 2, 2, matrix2 );
   IO_println ( "\nMatrix1" );
   printIntMatrix( 2, 2, matrix1 );
// multiplicar matrizes
   mulIntMatrix ( 2, 2, matrix3, 2, 2, matrix2, 2, 2, matrix1 );
   IO_println ( "\nMatrix3 = Matrix2 * Matrix1" );
   printIntMatrix( 2, 2, matrix3 );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo10

/*
Metodo 11 - Exemplo11
Objetivos: matriz double
Testes:ok
*/

void f_scandoublematrix(int L, int C, double matrix[][C])
{
   if (L<=0 || C<=0)
   {
      printf("\nERRO: dimensoes invalidas\n");
   }
   else
   {
   //declarar
      int i=0;
      int j=0;
      double z=0.0;
   
      for(i=0; i<L; i++)
      {
         for(j=0; j<C; j++)
         {
            printf("\n[%d][%d]: ", i, j);
            scanf("%lf", &z);
         
            matrix[i][j]=z;
            
         }//fim for j
      }//fim for i
   }
}//fim f_scandoublematrix

void f_printdoublematrix(int L, int C, double matrix[][C])
{
   int i=0;
   int j=0;
   if (L<=0 || C<=0)
   {
      printf("\nERRO: dimensoes invalidas\n");
   }//fi
   else
   {
      for (i=0; i<L; i++)
      {
         for (j=0; j<C; j++)
         {
            printf("%lf\t", matrix[i][j]);
         }//fim for j
         printf("\n");
      }//fim for i
   }//fim else

}//fim f_printdoublematrix

void metodo11 ()
{
//identificar
   IO_id("EXEMPLO0911 - Metodo11 - v0.0");
   //ler dimensoes
   int L=0;
   int C=0;
   //ler linhas
   while( L<=0)
   {
      printf("\nLINHAS: ");
      scanf("%d", &L);
   }
   //ler colunas
   while( C<=0)
   {
      printf("\nCOLUNAS: ");
      scanf("%d", &C);
   }
   //declarar matriz
   double matriz[L][C];
   //ler
   f_scandoublematrix(L, C, matriz);
   //printar
   f_printdoublematrix(L,C,matriz);

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo11

/*
Metodo 12 - Exemplo12
Objetivos: matriz double arquivo
Testes:
*/
void f_arqprintdoublematrix(char*Filename)
{
//abrir para ler
   FILE*arq=fopen(Filename, "rt");
//testar se existe
   if (arq==NULL)
   {
      printf("\n Arquivo nao encontrado\n");
   }
   else
   {
   //dados
      int L=0;
      int C=0;
      int i=0;
      int j=0;
      double z=0.0;
   //ler linhas
      fscanf(arq, "%d", &L);
      printf("\nLINHAS= %d", L);
   //ler colunas
      fscanf(arq, "%d", &C);
      printf("\nCOLUNAS= %d\n", C);
      i=0;
   //ler dados
      while (i<L && !feof(arq))
      {
         j=0;
         while (j<C && !feof(arq))
         {
            fscanf(arq, "%lf", &z);
            printf("%lf\t", z);
            j=j+1;
         }//fim while j
         printf("\n");
         i=i+1;
      }//fim while i
   
   
   }//fim else
   //fechar
   fclose(arq);

}//fim f_arqprintdoublematrix

void f_fprintfdoublematrix(char*Filename, int L, int C, double matrix[][C])
{
//abrir para gravar
   FILE*arq=fopen(Filename, "wt");
//dados locais
   int i=0;
   int j=0;

//teste
   if (L<=0 || C<=0)
   {
      printf("\nERRO: dimensoes invalidas\n");
   }
   else
   {
      fprintf(arq, "%d\n", L);
      fprintf(arq, "%d\n", C);
      for (i=0; i<L; i++)
      {
         for (j=0; j<C; j++)
         {
            fprintf(arq, "%lf\n", matrix[i][j]);
         }//fim for j
      }//fim for i
   }
   //fechar
   fclose(arq);
}//fim f_fprintfdoublematrix

void metodo12 ()
{
//identificar
   IO_id("EXEMPLO0912 - Metodo12 - v0.0");
    //ler dimensoes
   int L=0;
   int C=0;
   //ler linhas
   while( L<=0)
   {
      printf("\nLINHAS: ");
      scanf("%d", &L);
   }
   //ler colunas
   while( C<=0)
   {
      printf("\nCOLUNAS: ");
      scanf("%d", &C);
   }
   //declarar matriz
   double matriz[L][C];

   
   f_scandoublematrix(L,C,matriz);
   f_printdoublematrix(L,C,matriz);
   f_fprintfdoublematrix("ED0911.TXT", L, C, matriz);
   f_arqprintdoublematrix("ED0911.TXT");

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo12

/*
Metodo 13 - Exemplo13
Objetivos: diagonal matriz quadrada real
Testes:
*/
void f_diagonalquadrada(int L, int C, double matrix[][C])
{
   if (C!=L)
   {
      printf("\nERRO: matriz nao e quadrada\n");
   }//fi
   else
   {
   //variaveis
      int i=0;
      double z=0.0;
      for (i=0; i<L; i++)
      {
         z=matrix[i][i];
         printf("\n[%d][%d]: %lf", i, i, z);
        
      }
   }
   printf("\n");
}//fim f_diagonalquadrada
void metodo13 ()
{
//identificar
   IO_id("EXEMPLO0913 - Metodo13 - v0.0");
   double m1[][3]={{1.12,2.0,3.5},
                   {4.435,5.34,6.25},
                   {7.235,8.235,9.5}};
   double m2[][2]={{0.1,0.2},
                   {1.3,2.4}};
   double m3[][3]={{1.12,2.4,3.24},
                    {1.4,1.1,1.44}};
                    
   f_diagonalquadrada(3, 3, m1);
   f_diagonalquadrada(2, 2, m2);
   f_diagonalquadrada(2, 3, m3);
      
   

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo13

/*
Metodo 14 - Exemplo14
Objetivos: matriz quadrada diag secundaria
Testes:
*/
void f_diagonalsquadrada(int L, int C, double matrix[][C])
{
   if (C!=L)
   {
      printf("\nERRO: matriz nao e quadrada\n");
   }//fi
   else
   {
   //variaveis
      int i=0;
      int j=L-1;
      double z=0.0;
      while(i<C && j>=0)
      {
         z=matrix[i][j];
         printf("\n[%d][%d]: %lf", i, j, z);
         i=i+1;
         j=j-1;  
      }
   }
   printf("\n");
}//fim f_diagonalsquadrada
void metodo14 ()
{
//identificar
   IO_id("EXEMPLO0914 - Metodo14 - v0.0");
   
   //identificar
   IO_id("EXEMPLO0913 - Metodo13 - v0.0");
   double m1[][3]={{1.12,2.0,3.5},
                   {4.435,5.34,6.25},
                   {7.235,8.235,9.5}};
   double m2[][2]={{0.1,0.2},
                   {1.3,2.4}};
   double m3[][3]={{1.12,2.4,3.24},
                    {1.4,1.1,1.44}};
                    
   f_diagonalsquadrada(3, 3, m1);
   f_diagonalsquadrada(2, 2, m2);
   f_diagonalsquadrada(2, 3, m3);
      
   

//terminar
   IO_pause("Apertar enter para continuar");

}// fim metodo14

/*
Metodo 15 - Exemplo15
Objetivos: valores abaixo da diag princiapl matriz q
Testes:
*/
void f_abaixodiagprimdq(int L, int C, double matrix[][C])
{
   if (C!=L)
   {
      printf("\nERRO: matriz nao e quadrada\n");
   }//fi
   else
   {
   //variaveis
      int i=0;
      int j=L-1;
      double z=0.0;
      for (i=1; i<L; i++)
      {
         printf("\n");
         for (j=0; j<i; j++)
         {
            z=matrix[i][j];
            printf("\t%lf", z);
          
         }
      }
   }
   printf("\n");
}

void metodo15 ()
{
//identificar
   IO_id("EXEMPLO0915 - Metodo15 - v0.0");
   
   double m1[][3]={{1.12,2.0,3.5},
                   {4.435,5.34,6.25},
                   {7.235,8.235,9.5}};
   double m2[][2]={{0.1,0.2},
                   {1.3,2.4}};
   double m3[][3]={{1.12,2.4,3.24},
                    {1.4,1.1,1.44}};
   double m4[][5]={{0.0,0.1,0.2,0.3,0.4}, {1.0,1.1,1.2,1.3,1.4}, {2.0,2.1,2.2,2.3,2.4}, 
                   {3.0,3.1,3.2,3.3,3.4}, {4.0,4.1,4.2,4.3,4.4}};
                    
   f_abaixodiagprimdq(3, 3, m1);
   f_abaixodiagprimdq(2, 2, m2);
   f_abaixodiagprimdq(2, 3, m3);
   f_abaixodiagprimdq(5, 5, m4);

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo15

/*
Metodo 16 - Exemplo16
Objetivos
Testes:
*/

void f_acimadiagprimdq(int L, int C, double matrix[][C])
{
   if (C!=L)
   {
      printf("\nERRO: matriz nao e quadrada\n");
   }//fi
   else
   {
   //variaveis
      int i=0;
      int j=0;
      double z=0.0;
      for (i=0; i<L; i++)
      {
         printf("\n");
         for (j=i+1; j<L; j++)
         {
            z=matrix[i][j];
            printf("\t%lf", z);
          
         }
         
      }
   }
   printf("\n");
}

void metodo16 ()
{
//identificar
   IO_id("EXEMPLO0916 - Metodo16 - v0.0");
   
   
   double m1[][3]={{1.12,2.0,3.5},
                   {4.435,5.34,6.25},
                   {7.235,8.235,9.5}};
   double m2[][2]={{0.1,0.2},
                   {1.3,2.4}};
   double m3[][3]={{1.12,2.4,3.24},
                    {1.4,1.1,1.44}};
   double m4[][5]={{0.0,0.1,0.2,0.3,0.4}, {1.0,1.1,1.2,1.3,1.4}, {2.0,2.1,2.2,2.3,2.4}, 
                   {3.0,3.1,3.2,3.3,3.4}, {4.0,4.1,4.2,4.3,4.4}};
                    
   f_acimadiagprimdq(3, 3, m1);
   f_acimadiagprimdq(2, 2, m2);
   f_acimadiagprimdq(2, 3, m3);
   f_acimadiagprimdq(5, 5, m4);


//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo16

/*
Metodo 17 - Exemplo17
Objetivos
Testes:
*/

void f_abaixodiagsmdq(int L, int C, double matrix[][C])
{
   if (C!=L)
   {
      printf("\nERRO: matriz nao e quadrada\n");
   }//fi
   else
   {
   //variaveis
      int i=0;
      int j=0;
      int d=L-2;
      double z=0.0;
      for (i=1; i<L; i++)
      {
         printf("\n");
         for (j=d+1; j<L; j++)
         {
            z=matrix[i][j];
            printf("\t%lf", z);
          
         }
         d=d-1;
      }
   }
   printf("\n");
}

void metodo17 ()
{
//identificar
   IO_id("EXEMPLO0917 - Metodo17 - v0.0");
   
   double m1[][3]={{1.12,2.0,3.5},
                   {4.435,5.34,6.25},
                   {7.235,8.235,9.5}};
   double m2[][2]={{0.1,0.2},
                   {1.3,2.4}};
   double m3[][3]={{1.12,2.4,3.24},
                    {1.4,1.1,1.44}};
   double m4[][5]={{0.0,0.1,0.2,0.3,0.4}, {1.0,1.1,1.2,1.3,1.4}, {2.0,2.1,2.2,2.3,2.4}, 
                   {3.0,3.1,3.2,3.3,3.4}, {4.0,4.1,4.2,4.3,4.4}};
                    
   f_abaixodiagsmdq(3, 3, m1);
   f_abaixodiagsmdq(2, 2, m2);
   f_abaixodiagsmdq(2, 3, m3);
   f_abaixodiagsmdq(5, 5, m4);



//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo17

/*
Metodo 18 - Exemplo18
Objetivos
Testes:
*/

void f_acimadiagsmdq(int L, int C, double matrix[][C])
{
   if (C!=L)
   {
      printf("\nERRO: matriz nao e quadrada\n");
   }//fi
   else
   {
   //variaveis
      int i=0;
      int j=0;
      int d=L-1;
      double z=0.0;
      for (i=0; i<L; i++)
      {
         printf("\n");
         for (j=0; j<d; j++)
         {
            z=matrix[i][j];
            printf("\t%3lf", z);
          
         }
         d=d-1;
      }
   }
   printf("\n");
}

void metodo18 ()
{
//identificar
   IO_id("EXEMPLO0918 - Metodo18 - v0.0");
   
   double m1[][3]={{1.12,2.0,3.5},
                   {4.435,5.34,6.25},
                   {7.235,8.235,9.5}};
   double m2[][2]={{0.1,0.2},
                   {1.3,2.4}};
   double m3[][3]={{1.12,2.4,3.24},
                    {1.4,1.1,1.44}};
   double m4[][5]={{0.0,0.1,0.2,0.3,0.4}, {1.0,1.1,1.2,1.3,1.4}, {2.0,2.1,2.2,2.3,2.4}, 
                   {3.0,3.1,3.2,3.3,3.4}, {4.0,4.1,4.2,4.3,4.4}};
                    
   f_acimadiagsmdq(3, 3, m1);
   f_acimadiagsmdq(2, 2, m2);
   f_acimadiagsmdq(2, 3, m3);
   f_acimadiagsmdq(5, 5, m4);


//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo18

/*
Metodo 19 - Exemplo19
Objetivos
Testes:
*/

bool f_naonulosabaixodiagprimdq(int L, int C, double matrix[][C])
{
   if (C!=L)
   {
      printf("\nERRO: matriz nao e quadrada\n");
   }//fi
   else
   {
   //variaveis
      bool teste= true;
      int cont=0;
   // qtidade total de elementos =L^2; -qtidade de elementos da diagonal =L; divide por 2, pq tem a
    //mesma qtidade de elementos na matriz triangular de cima e na de baixo
      int total= ((L*L-L)/2);
      int i=0;
      int j=L-1;
      double z=0.0;
      for (i=1; i<L; i++)
      {
         printf("\n");
         for (j=0; j<i; j++)
         {
            z=matrix[i][j];
            printf("\t%lf", z);
            if (z==0)
            {
               cont=cont+1;
            }
          
         }
      }
      if (cont == total) 
      {
         teste=false;
      }
      printf("\n");
   
      return(teste);
   }
   
}

void metodo19 ()
{
//identificar
   IO_id("EXEMPLO0919 - Metodo19 - v0.0");
   
   double m1[][3]={{1.12,2.0,3.5},
                   {4.435,5.34,6.25},
                   {7.235,8.235,9.5}};
   double m2[][2]={{0.1,0.2},
                   {1.3,2.4}};
   double m3[][3]={{1.12,2.4,3.24},
                    {1.4,1.1,1.44}};
   double m4[][5]={{0.0,0.1,0.2,0.3,0.4}, {1.0,1.1,1.2,1.3,1.4}, {2.0,2.1,2.2,2.3,2.4}, 
                   {3.0,3.1,3.2,3.3,3.4}, {4.0,4.1,4.2,4.3,4.4}};
   double m5[][3]={{0.1,0.2, 0.3},
                   {0.0,2.4, 0.123},
                   {0.0, 0.0, 0.0}};
   printf("\nm1: %d",f_naonulosabaixodiagprimdq(3, 3, m1));
   printf("\nm2: %d",f_naonulosabaixodiagprimdq(2, 2, m2));
   printf("\nm3: %d", f_naonulosabaixodiagprimdq(2, 3, m3));
   printf("\nm4: %d", f_naonulosabaixodiagprimdq(5, 5, m4));
   printf("\nm5: %d", f_naonulosabaixodiagprimdq(3, 3, m5));
                    
  

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo19

/*
Metodo 20 - Exemplo20
Objetivos
Testes:
*/

bool f_naonulosacimadiagprimdq(int L, int C, double matrix[][C])
{
   if (C!=L)
   {
      printf("\nERRO: matriz nao e quadrada\n");
   }//fi
   else
   {
   //variaveis
      int i=0;
      bool teste = true;
      int j=0;
      int total= (L*L-L)/2;
      int cont=0;
      double z=0.0;
      for (i=0; i<L; i++)
      {
         printf("\n");
         for (j=i+1; j<L; j++)
         {
            z=matrix[i][j];
            printf("\t%lf", z);
            if (z==0)
            {
               cont=cont+1;
            }
          
         }
         
      }
      printf("\n");
      if (cont==total)
      {
         teste=false;
      }
      printf("\n");
      return(teste);
   }
   
}
void metodo20 ()
{
//identificar
   IO_id("EXEMPLO0920 - Metodo20 - v0.0");
   
   double m1[][3]={{1.12,2.0,3.5},
                   {4.435,5.34,6.25},
                   {7.235,8.235,9.5}};
   double m2[][2]={{0.1,0.2},
                   {1.3,2.4}};
   double m3[][3]={{1.12,2.4,3.24},
                    {1.4,1.1,1.44}};
   double m4[][5]={{0.0,0.1,0.2,0.3,0.4}, {1.0,1.1,1.2,1.3,1.4}, {2.0,2.1,2.2,2.3,2.4}, 
                   {3.0,3.1,3.2,3.3,3.4}, {4.0,4.1,4.2,4.3,4.4}};
   double m5[][3]={{0.1,0.0, 0.0},
                   {0.0,2.4, 0.0},
                   {0.0, 0.1, 0.0}};
   printf("\nm1: %d",f_naonulosacimadiagprimdq(3, 3, m1));
   printf("\nm2: %d",f_naonulosacimadiagprimdq(2, 2, m2));
   printf("\nm3: %d", f_naonulosacimadiagprimdq(2, 3, m3));
   printf("\nm4: %d", f_naonulosacimadiagprimdq(5, 5, m4));
   printf("\nm5: %d", f_naonulosacimadiagprimdq(3, 3, m5));

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo20

/*
Metodo 21 - Exemplo21
Objetivos
Testes:
*/
void f_21(int L, int C, int matrix[][C])
{
   if (C<=0 || L<=0)
   {
      printf("\nERRO: Dimensoes invalidas\n");
   }
   else
   {
      int i=0; 
      int j=0;
      int cont=L*C;
      for (i=0; i<L; i++)
      {
         for (j=0; j<C; j++)
         {
            matrix[i][j]=cont;
            cont=cont-1;
         }
      }
   }
}

void f_21arqg(char*FileName, int L, int C, int matrix[][C])
{
//abrir para gravar
   FILE*arq=fopen(FileName, "wt");
   int i=0;
   int j=0;
   fprintf(arq,"%d\n", L);
   fprintf(arq,"%d\n", C);
   for (i=0; i<L; i++)
   {
      for(j=0; j<C; j++)
      {
         fprintf(arq, "%d\n", matrix[i][j]);
      }
   }
//fechar
   fclose(arq);
}

void f_21arql(char*FileName)
{
//abrir para ler
   FILE*arq=fopen(FileName, "rt");
//testar se existe
   if (arq==NULL)
   {
      printf("\n  ERRO: arquivo nao encontrado\n");
   }
   else
   {
      int x=0;
      int i=0;
      int j=0;
      int L=0;
      int C=0;
      fscanf(arq, "%d", &x);
      L=x;
      printf("\n LINHAS= %d", L);
      fscanf(arq, "%d", &x);
      C=x;
      printf("\n COLUNAS= %d\n", C);
      while (i<L && !feof(arq))
      {
         j=0;
         while(j<C && !feof(arq))
         {
            fscanf(arq, "%d", &x);
            printf("%3d\t", x);
            j=j+1;
         }
         printf("\n");
         i=i+1;
      }
   }

//fechar
   fclose(arq);
}

void metodo21 ()
{
//identificar
   IO_id("EXEMPLO0921 - Metodo21 - v0.0");
   //ler linhas e colunas
   int L=0;
   int C=0;
   
   while (L<=0)
   {
      printf("\nLINHAS: ");
      scanf("%d", &L);
   }
   while (C<=0)
   {
      printf("\nCOLUNAS: ");
      scanf("%d", &C);
   }
   //declarar matriz
   int matrix[L][C];
   //preencher matriz
   f_21(L, C, matrix);
   printIntMatrix(L, C, matrix);
   f_21arqg("ED0921.TXT", L, C, matrix);
   f_21arql("ED0921.TXT");
   
   
   

//terminar
   IO_pause("Apertar enter para continuar");
}// fim metodo21

/*
Metodo 22 - Exemplo22
Objetivos
Testes:
*/

void f_22(int L, int C, int matrix[][C])
{
   if (C<=0 || L<=0)
   {
      printf("\nERRO: Dimensoes invalidas\n");
   }
   else
   {
      int i=0; 
      int j=0;
      int cont=L*C;
      for (i=0; i<C; i++)
      {
         for (j=0; j<L; j++)
         {
            matrix[j][i]=cont;
            cont=cont-1;
         }
      }
   }
}

void metodo22 ()
{
//identificar
   IO_id("EXEMPLO0922 - Metodo22 - v0.0");
   
   //ler linhas e colunas
   int L=0;
   int C=0;
   
   while (L<=0)
   {
      printf("\nLINHAS: ");
      scanf("%d", &L);
   }
   while (C<=0)
   {
      printf("\nCOLUNAS: ");
      scanf("%d", &C);
   }
   //declarar matriz
   int matrix[L][C];
   //preencher matriz
   f_22(L, C, matrix);
   printIntMatrix(L, C, matrix);
   f_21arqg("ED0922.TXT", L, C, matrix);
   f_21arql("ED0922.TXT");

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
                     "Lista ED09 - Fabiana Kraft - 677262", "0 - parar", "1 - Exemplo0901",
                     "2 - Exemplo0902","3 - Exemplo0903","4 - Exemplo0904","5 - Exemplo0905",
                     "6 - Exemplo0906","7 - Exemplo0907","8 - Exemplo0908","9 - Exemplo0909",
                     "10 - Exemplo0910","11 - Exemplo0911","12 - Exemplo0912","13 - Exemplo0913",
                     "14 - Exemplo0914","15 - Exemplo0915","16 - Exemplo0916","17 - Exemplo0917",
                     "18 - Exemplo0918","19 - Exemplo0919","20 - Exemplo0920","21 - Exemplo0921",
                     "22 - Exemplo0922");
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