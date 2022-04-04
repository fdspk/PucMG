/**
ED04 - AEDsI - T2 manhã
Aluna: Fabiana Kraft - 677262
Data:02/09/2019
*/

//Biblioteca
#include "io.h"

//FunÃ§Ãµes

/**
01.) ~positive~
Funcao para determinar se valor inteiro e' positivo.
@return true, se positivo; false, caso contrario
@param x - valor a ser testado
*/

bool positive ( int x )
{
   // definir dado local
   bool result = false;
   // testar a condicao
   if ( x > 0 )
   {
      result = true;
   } // fim se
   return ( result );
} // fim positive ( )

/**
02.) ~belongsTo~
Funcao para determinar se valor inteiro pertence a intervalo aberto.
@return true, se pertencer; false, caso contrario
@param x - valor a ser testado
*/
bool belongsTo ( int x, int inferior, int superior )
{
// definir dado local
   bool result = false;
// testar a condicao
   if ( inferior < x && x < superior )
   {
      result = true;
   } // fim se
   return ( result );
} // fim belongsTo ( )

/**
03.) ~even~
Funcao para determinar se valor inteiro e' par.
@return true, se par; false, caso contrario
@param x - valor a ser testado
*/
bool even ( int x )
{
// definir dado local
   bool result = false;
// testar a condicao ( resto inteiro (%) da divisao por 2 igual a zero )
   if ( x % 2 == 0 )
   {
      result = true;
   } // fim se
   return ( result );
} // fim even ( )

/**
 04.) ~isLowerCase~
 Funcao para determinar se caractere e' letra minuscula.
 @return true, se par; false, caso contrario
 @param x - valor a ser testado
*/
bool isLowerCase ( char x )
{
// definir dado local
   bool result = false;
// testar a condicao
   if ( 'a' <= x && x <= 'z' )
   {
      result = true;
   } // fim se
   return ( result );
} // fim isLowerCase ( )

/**~isDigit~
 Funcao para determinar se caractere e' digito.
 @return true, se par; false, caso contrario
 @param x - valor a ser testado
*/
bool isDigit ( char x )
{
// definir dado local
   bool result = false;
// testar a condicao
   if ( '0' <= x && x <= '9' )
   {
      result = true;
   } // fim se
   return ( result );
} // fim isDigit ( )

/**~isADigit~
 Funcao para determinar se caractere e' digito.
 @return true, se par; false, caso contrario
 @param x - valor a ser testado
*/
bool isADigit ( char x )
{
   return ( '0' <= x && x <= '9' );
} // fim isADigit ( )


/**
Metodo0 - nÃ£o faz nada
Teste:ok
*/

void metodo0 ()
{
}//fim metodo0

/**
Method01 - Exemplo0401
Objetivo: Repeticao para ler certa quantidade de valores.
*/ 

void metodo1 ()
{
// definir dado
   int quantidade = 0;
   int valor
   = 0;
   int controle
   = 0;
// identificar
   printf( "\n%s","EXEMPLO0401 - metodo1 - v0.0" );
   printf( "\n%s","Objetivo: Repeticao para ler certa quantidade de valores." );
// ler do teclado
   quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
   controle = 1;
   while ( controle <= quantidade )
   {
   // ler valor do teclado
      valor = IO_readint ( IO_concat (
         IO_concat ( "", IO_toString_d ( controle ) ),
         ": " ) );
   // passar ao proximo valor
      controle = controle + 1;
   } // fim repetir
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo1


/**
Metodo02 - Exemplo0402
Objetivos: Ler valores e contar positivos.
Testes:
a.) 3, {0, 1, -1} (ok)
b.) -1 (pula, nao executa)
*/
void metodo2 ()
{
 // definir dado
   int quantidade = 0;
   int valor
   = 0;
   int controle
   = 0;
   int contador = 0;
// identificar
   IO_id ( "EXEMPLO0402 - metodo2 - v0.0" );
// ler do teclado
   quantidade = IO_readint ( "Entrar com uma quantidade: " );
   // repetir para a quantidade de vezes informada
   controle = 1;
   while ( controle <= quantidade )
   {
   // ler valor do teclado
      valor = IO_readint ( IO_concat (
         IO_concat ( "", IO_toString_d ( controle ) ),
         ": " ) );
   // testar e contar se valor for positivo
      if ( positive ( valor ) )
      {
         contador = contador + 1;
      } // fim se
   // passar ao proximo valor
      controle = controle + 1;
   } // fim repetir
// mostrar a quantidade de valores positivos
   IO_printf ( "%s%d\n", "Positivos = ", contador );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo2

 /**
Metodo03 - Exemplo0403
Objetivos: Ler valores e contar positivos menores que 100.
Testes:
a.) 
*/
void metodo3 ()
{
// definir dado
   int quantidade = 0;
   int valor
   = 0;
   int controle
   = 0;
   int contador = 0;
// identificar
   IO_id ( "EXEMPLO0403 - metodo3 - v0.0" );
// ler do teclado
   quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
   controle = 1;
   while ( controle <= quantidade )
   {
   // ler valor do teclado
      valor = IO_readint ( IO_concat (
         IO_concat ( "", IO_toString_d ( controle ) ),
         ": " ) );
   // testar e contar se valor for positivo
      if ( belongsTo ( valor, 0, 100 ) )
      {
         contador = contador + 1;
      } // fim se// passar ao proximo valor
      controle = controle + 1;
   } // fim repetir
// mostrar a quantidade de valores positivos
   IO_printf ( "%s%d\n", "Positivos menores que 100 = ", contador );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo3

/**
Metodo04 - Exemplo0404
Objetivos: Ler valores e contar positivos menores que 100 e pares.
Testes:
a.) 
*/

void metodo4 ()
{
// definir dado
   int quantidade = 0;
   int valor
   = 0;
   int controle
   = 0;
   int contador = 0;
// identificar
   IO_id ( "EXEMPLO0404 - metodo4 - v0.0" );
// ler do teclado
   quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
   controle = 1;
   while ( controle <= quantidade )
   {
   // ler valor do teclado
      valor = IO_readint ( IO_concat (
         IO_concat ( "", IO_toString_d ( controle ) ),
         ": " ) );
   // testar e contar se valor for positivo menor que 100 e par
      if ( belongsTo ( valor, 0, 100 ) && even ( valor ) )
      {
         contador = contador + 1;
      } // fim se
   // passar ao proximo valor
      controle = controle + 1;
   } // fim repetir
// mostrar a quantidade de valores positivos
   IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo4

/**
Metodo05 - Exemplo0405
Objetivos: Ler valores e contar positivos menores que 100 e pares (alternativo).
Testes:
a.) 
*/
void metodo5 ()
{
// definir dado
   int quantidade = 0;
   int valor
   = 0;
   int controle
   = 0;
   int contador
   = 0;
   bool ok
   = false;
// identificar
   IO_id ( "EXEMPLO0405 - Method05 - v0.0" );
// ler do teclado
   quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
   controle = 1;
   while ( controle <= quantidade )
   {
   // ler valor do teclado
      valor = IO_readint ( IO_concat (
         IO_concat ( "", IO_toString_d ( controle ) ),
         ": " ) );
   // testar e contar se valor for positivo menor que 100 e par
      ok = belongsTo ( valor, 0, 100 );
      ok = ok && even ( valor );
      if ( ok )
      {
         contador = contador + 1;
      } // fim se
   // passar ao proximo valor
      controle = controle + 1;
   } // fim repetir
// mostrar a quantidade de valores positivos
   IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo5

 /**
Metodo06 - Exemplo0406
Objetivos: Ler palavra e contar letras minusculas.
Testes:
a.) HShuasHUsuLAS (ok)
*/
void metodo6 ()
{// definir dado
   chars palavra = IO_new_chars ( STR_SIZE );
   int tamanho = 0;
   int posicao = 0;
   char simbolo = '_';
   int contador = 0;
// identificar
   IO_id ( "EXEMPLO0406 - Method06 - v0.0" );
// ler do teclado
   palavra = IO_readString ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
   tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
   for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
   {
   // isolar um simbolo por vez
      simbolo = palavra [ posicao ];
   // testar e contar se caractere e' letra minuscula
      if ( isLowerCase ( simbolo ) )
      {
         contador = contador + 1;
      } // fim se
   } // fim repetir
// mostrar a quantidade de minusculas
   IO_printf ( "%s%d\n", "Minusculas = ", contador );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );}//fim metodo6

 /**
Metodo07 - Exemplo0407
Objetivos: - Ler palavra, contar e mostrar letras minusculas
Testes:
a.) ASdfgHJklBNMk(ok)
*/
void metodo7 ()
{
// definir dado
   chars palavra = IO_new_chars ( STR_SIZE );
   int tamanho = 0;
   int posicao = 0;
   char simbolo = '_';
   int contador = 0;
// identificar
   IO_id ( "EXEMPLO0407 - Method07 - v0.0" );
// ler do teclado
   palavra = IO_readString ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
   tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
   for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
   {
   // isolar um simbolo por vez
      simbolo = palavra [ posicao ];
   // testar e contar se caractere e' letra minuscula
      if ( isLowerCase ( simbolo ) )
      {
      // mostrar
         IO_printf ( "%c ", simbolo );
      // contar
         contador = contador + 1;
      } // fim se
   } // fim repetir
// mostrar a quantidade de minusculas
   IO_printf ( "\n%s%d\n", "Minusculas = ", contador );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo7

/**
Metodo08 - Exemplo0408
Objetivos: Ler palavra, contar e mostrar letras minusculas (alternativo)
Testes:
a.) ASDdfghHJKl4 (ok)
*/
void metodo8 ()
{
// definir dado
   chars palavra = IO_new_chars ( STR_SIZE );
   int tamanho = 0;
   int posicao = 0;
   char simbolo = '_';
   int contador = 0;
   chars minusculas = IO_new_chars ( STR_SIZE );
   strcpy ( minusculas, STR_EMPTY ); // vazio
// identificar
   IO_id ( "EXEMPLO0408 - Method08 - v0.0" );
// ler do teclado
   palavra = IO_readString ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
   tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
   for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
   {
   // isolar um simbolo por vez
      simbolo = palavra [ posicao ];
   // testar e contar as letras minusculas de uma palavra
      if ( isLowerCase ( simbolo ) )
      {
      // concatenar simbolo encontrado
         minusculas = IO_concat ( minusculas, IO_toString_c ( simbolo ) );
      // contar
         contador = contador + 1;
      } // fim se
   } // fim repetir
// mostrar a quantidade de minusculas
   IO_printf ( "\n%s%d [%s]\n", "Minusculas = ", contador, minusculas );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo8

 /**
Metodo09 - Exemplo0409
Objetivos: Ler palavra e contar os algarismos.
Testes:aF&*(12-d76fthn99 (ok)
a.) 
*/
void metodo9 ()
{
// definir dado
   chars palavra = IO_new_chars ( STR_SIZE );
   int tamanho = 0;
   int posicao = 0;
   char simbolo = '_';
   int contador = 0;
// identificar
   IO_id ( "EXEMPLO0409 - Method09 - v0.0" );
// ler do teclado
   palavra = IO_readString ( "Entrar com caracteres: " );
// determinar a quantidade de simbolos
   tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
   for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
   {
   // isolar um simbolo por vez
      simbolo = palavra [ posicao ];
   // testar e contar os algarismos em uma cadeia de caracteres
      if ( isDigit ( simbolo ) )
      {
      // mostrar
         IO_printf ( "%c ", simbolo );
      // contar
         contador = contador + 1;
      } // fim se
   } // fim repetir
// mostrar a quantidade de digitos
   IO_printf ( "\n%s%d\n", "Algarismos = ", contador );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo9

 /**
Metodo10 - Exemplo0410
Objetivos: 
Testes:
a.) 745FfHUh89 (ok)
*/
void metodo10 ()
{
// definir dado
   chars palavra = IO_new_chars ( STR_SIZE );
   int tamanho = 0;
   int posicao = 0;
   char simbolo = '_';
   chars digitos = IO_new_chars ( STR_SIZE );
   strcpy ( digitos, STR_EMPTY ); // vazio
// identificar
   IO_id ( "EXEMPLO0410 - Method10 - v0.0" );
// ler do teclado
   palavra = IO_readString ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
   tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
   for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
   {
   // isolar um simbolo por vez
      simbolo = palavra [ posicao ];
   // testar e contar os algarismos em uma cadeia de caracteres
      if ( isADigit ( simbolo ) )
      {
      // concatenar simbolo encontrado
         digitos = IO_concat ( digitos, IO_toString_c ( simbolo ) );
      } // fim se
   } // fim repetir
// mostrar a quantidade de digitos
   IO_printf ( "\n%s%d [%s]\n", "Algarismos = ", strlen( digitos ), digitos );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo10

  /**
Metodo11 - Exemplo0411
Objetivos: - ler dois valores reais para definir um intervalo fechado;
           - ler certa quantidade de valores reais e
           - contar quantos desses valores estão dentro do intervalo, e quantos estão fora dele.
Testes:
a.) menu - 11 (Ok)
b.) 30, 10, 2 (pede para reler ok); 30, 10, -4 (pede para reler ok); -1.55, 3.65, 5 (ok) {-1.55, 3.65, -1, -1.6, 3.66} (ok)
*/
void metodo11 ()
{
// identificação
   printf("\n%s\n","E0411 - Fabiana Kraft - 677262");

//declarar variaveis
   double inferior = 0.0;
   double superior = 0.0;
   int quantidade = 0;
   double valor = 0.0;
   int contador= 1;
   int contadorin = 0;
   int contadorout =0;

//inputs

   while (inferior>=superior|| quantidade<=0)
   {
      printf("\n%s","Inserir valor real para limite inferior: ");
      scanf("%lf",& inferior);
   
      printf("\n%s","Inserir valor real para limite superior (>inferior): ");
      scanf("%lf",& superior);
      
      printf("\n%s","Inserir quantidade a ser lida (int>0): ");
      scanf("%d",& quantidade);
   
      if (inferior>=superior || quantidade<=0)
      {
         printf("\n%s\n", "Dados invalidos, favor reinserir");
      }//fim if
   
   }//fim while
   
   do
   {
      printf ("\n%s%d%s", "Inserir ", contador, "o valor: ");
      scanf("%lf",& valor);
   
      if (valor<=superior && valor>= inferior)
      {
         contadorin=contadorin+1;
      }//fim if
      else
      {
         contadorout=contadorout+1;
      }//fim else
      contador = contador+1;
   }// fim do
   while (contador<=quantidade);
   
   printf("\n%s%d", "Numero de valores dentro do intervalo = ", contadorin);
   printf("\n%s%d", "Numero de valores fora do intervalo = ", contadorout);
   
   //terminar
   IO_pause("\n Aperte enter para terminar"); 


}//fim metodo11

    /**
Metodo12 - Exemplo0412
Objetivos: - ler uma sequência de caracteres do teclado;
              - contar e mostrar a quantidade de letras maiúsculas. 
Testes:
a.) !@#34ASDFghjBN09*iI (ok)
*/

bool f_isupper (char c)
{
//dado local
   bool result = false;
//teste
   if (c<='Z' && c>= 'A')
   {
      result = true;
   }// fim if
   return (result);
}// fim f_isupper

void metodo12 ()
{
// identificação
   printf("\n%s\n","E0412 - Fabiana Kraft - 677262");
   
  // declarar variaveis
   char palavra[80] = "_";
   int contador = 0;
   int posicao =0;
   int tamanho = 0;
   char caractere= '_';
   
   // input
   printf ("\n%s", "Insira uma cadeia de caracteres: ");
   scanf("%s", palavra);
   //pegar tamanho
   tamanho = strlen (palavra);
   //testar se e maiuscula
   for (posicao=0; posicao<tamanho; posicao++)
   {
      caractere = palavra [posicao];
      if (f_isupper(caractere))
      {
         printf ("%c ", caractere);
         contador = contador+1;
      }// fim if
   }// fim for
    
   printf("\n%s%d","Numero de caracteres maiusculos: ", contador);
    
  //terminar
   IO_pause("\n Aperte enter para terminar"); 
   
}//fim metodo12

    /**
Metodo13 - Exemplo0413
Objetivos: - ler uma sequência de caracteres do teclado;
              - contar as letras maiúsculas mediante uso de uma função
                 definida para receber uma cadeia de caracteres como parâmetro.
Testes:
a.) AShhaUU8*9J (ok)
*/

int f_struppercount (char p[])
{
//declara
   int tamanho = 0;
   int posicao =0;   
   char ch = '_';
   int count = 0;
   tamanho = strlen(p);
//operacoes
   for (posicao=0; posicao<tamanho; posicao=posicao+1)
   {
      ch= p[posicao];
      if (f_isupper(ch))
      {
         count= count+1;
      }// fim if
   }//fim for
   return count;
} //fim f_stringupper

void metodo13 ()
{
// identificação
   printf("\n%s\n","E0413 - Fabiana Kraft - 677262");
   
   // variaveis
   char palavra[80] = "_";
   int contador= 0;
   // input
   printf ("\n%s", "Insira uma cadeia de caracteres: ");
   scanf("%s", palavra);
   //operacao
   contador =  f_struppercount(palavra);
   printf("\n%s%d","O numero de letras maiusculas e: ", contador);
   
   //terminar
   IO_pause("\n Aperte enter para terminar"); 
   
}//fim metodo13

    /**
Metodo14 - Exemplo0414
Objetivos: - ler uma sequência de caracteres do teclado;
              - separar as letras maiúsculas mediante uso de uma função
                definida para receber uma cadeia de caracteres como parâmetro.
Testes:
a.) AbkHOah897*(*haUJ (ok)
*/

char* f_strupper (char p[])
{
//declara
   int tamanho = 0;
   int posicao =0;   
   char ch = '_';
   tamanho = strlen(p);
//operacoes
   for (posicao=0; posicao<tamanho; posicao=posicao+1)
   {
      ch= p[posicao];
      if (f_isupper(ch))
      {  
         printf ("%c",ch);
      }// fim if
   }//fim for
   return (0);
} //fim f_strupper

void metodo14 ()
{
// identificação
   printf("\n%s\n","E0414 - Fabiana Kraft - 677262");
   
   // variaveis
   char palavra[80] = "_";
   // input
   printf ("\n%s", "Insira uma cadeia de caracteres: ");
   scanf("%s", palavra);
   //operacao   
   f_strupper(palavra); 
   
   //terminar
   IO_pause("\n Aperte enter para terminar"); 
}//fim metodo14

    /**
Metodo15 - Exemplo0415
Objetivos: - ler uma sequência de caracteres do teclado; 
              - contar as letras (tanto maiúsculas, quanto minúsculas) mediante uso de uma função
                definida para receber uma cadeia de caracteres como parâmetro.
Testes:
a.) aGSK99¨$%&AFSFgg (ok)
*/

int f_alphacount (char p[])
{
   int count=0;
   int tamanho=0;
   tamanho=strlen(p);
   int posicao=0;
   char c = '.';
   for(posicao=0; posicao<tamanho; posicao++)
   {
      c=p[posicao];
      if ( f_isupper(c) ||  isLowerCase(c))
      {
         count=count+1;
      }//fim if
   }// fim for
   return count;
}// fim f_alphacount

void metodo15 ()
{
// identificação
   printf("\n%s\n","E0415 - Fabiana Kraft - 677262");
    // variaveis
   char palavra[80] = "_";
   // input
   printf ("\n%s", "Insira uma cadeia de caracteres: ");
   scanf("%s", palavra);
   //output
   printf("\n%s%d", "Numero de letras e: ", f_alphacount(palavra));
   //terminar
   IO_pause("\n Aperte enter para terminar"); 
   
}//fim metodo15

    /**
Metodo16 - Exemplo0416
Objetivos: - ler uma sequência de caracteres do teclado;
             - separar as letras (tanto maiúsculas, quanto minúsculas) mediante uso de uma função
               definida para receber uma cadeia de caracteres como parâmetro.

Testes:
a.) ASdfgHJKL8986%¨&*(Yui (ok)
*/

char* f_lowupsep (char p[])
{
//declara
   int tamanho = 0;
   int posicao =0;   
   char ch = '_';
   tamanho = strlen(p);
//operacoes
   printf ("Letras maiusculas:\n");
   for (posicao=0; posicao<tamanho; posicao=posicao+1)
   {
      ch= p[posicao];
      
      if (f_isupper(ch))
      {  
         printf ("%c",ch);
      }// fim if
   }//fim for
   printf ("\nLetras minusculas: \n");
   for (posicao=0; posicao<tamanho; posicao=posicao+1)
   {
      ch= p[posicao];
      
      if (isLowerCase(ch))
      {  
         printf ("%c",ch);
      }// fim if
   }//fim for
   return (0);
} //fim f_lowupsep

void metodo16 ()
{
// identificação
   printf("\n%s\n","E0416 - Fabiana Kraft - 677262");
   
   // variaveis
   char palavra[80] = "_";
   // input
   printf ("\n%s", "Insira uma cadeia de caracteres: ");
   scanf("%s", palavra);
   //operacao   
   f_lowupsep(palavra); 
   
   //terminar
   IO_pause("\n Aperte enter para terminar"); 
}//fim metodo16

    /**
Metodo17 - Exemplo0417
Objetivos: - ler uma sequência de caracteres do teclado;
              - contar e mostrar apenas os dígitos pares em uma cadeia de caracteres,
                testados por meio de uma função.
Testes:
a.) QWErty1234567890l.(*& (ok)
*/
int f_evenshowcount (char p[])
{
   int count=0;
   int tamanho=0;
   tamanho=strlen(p);
   int posicao=0;
   char c = '.';
   printf("\nOs caracteres pares sao: ");
   for(posicao=0; posicao<tamanho; posicao++)
   {
      c=p[posicao];
      if (c=='0'|| c=='2' || c=='4'|| c=='6'||c=='8')
      {
         printf("%c", c);
         count=count+1;
      }//fim if
   }// fim for
   printf ("\nO numero de pares e: %d", count);
   return(0);
}// fim f_evenshowcount

void metodo17 ()
{
// identificação
   printf("\n%s\n","E0417 - Fabiana Kraft - 677262");
   
   // variaveis
   char palavra[80] = "_";
   // input
   printf ("\n%s", "Insira uma cadeia de caracteres: ");
   scanf("%s", palavra);
   //operacao   
   f_evenshowcount(palavra); 
   
   //terminar
   IO_pause("\n Aperte enter para terminar"); 

}//fim metodo17

    /**
Metodo18 - Exemplo0418
Objetivos: - ler uma sequência de caracteres do teclado;
              - contar todos os símbolos alfanuméricos (letras e dígitos) em uma cadeia de caracteres
                 por meio de uma função. 
Testes:
a.) ASDfghk123$%&890 (ok)
*/
int f_alphanumcount (char p[])
{
   int count=0;
   int tamanho=0;
   tamanho=strlen(p);
   int posicao=0;
   char c = '.';
   
   for(posicao=0; posicao<tamanho; posicao++)
   {
      c=p[posicao];
      if ( f_isupper(c) ||  isLowerCase(c) || (c>='0' && c<='9'))
      {
         count=count+1;
      }//fim if
   }// fim for
   printf("\nQuantidade de simbolos alfanumericos = %d", count);
   return (0);
}// fim f_alphanumcount

void metodo18 ()
{
// identificação
   printf("\n%s\n","E0418 - Fabiana Kraft - 677262");
   // variaveis
   char palavra[80] = "_";
   // input
   printf ("\n%s", "Insira uma cadeia de caracteres: ");
   scanf("%s", palavra);
   //operacao   
   f_alphanumcount(palavra); 
   
   //terminar
   IO_pause("\n Aperte enter para terminar"); 
}//fim metodo18

    /**
Metodo19 - Exemplo0419
Objetivos: - ler uma sequência de caracteres do teclado;
              - separar todos os símbolos alfanuméricos (letras e dígitos) em uma cadeia de caracteres
               por meio de uma função. 
Testes:
a.) SDfgj567@#$%ro0(
*/
int f_alphanumshow (char p[])
{
   int tamanho=0;
   tamanho=strlen(p);
   int posicao=0;
   char c = '.';
   printf("\nSimbolos alfanumericos sao: ");
   for(posicao=0; posicao<tamanho; posicao++)
   {
      c=p[posicao];
      if ( f_isupper(c) ||  isLowerCase(c) || (c>='0' && c<='9'))
      {
         printf("%c", c);
      }//fim if
   }// fim for
   return (0);
}// fim f_alphanumcs

void metodo19 ()
{
// identificação
   printf("\n%s\n","E0419 - Fabiana Kraft - 677262");
    // variaveis
   char palavra[80] = "_";
   // input
   printf ("\n%s", "Insira uma cadeia de caracteres: ");
   scanf("%s", palavra);
   //operacao   
   f_alphanumshow(palavra); 
   
   //terminar
   IO_pause("\n Aperte enter para terminar"); 
}//fim metodo19

    /**
Metodo20 - Exemplo0420
Objetivos: 
Testes:- ler certa quantidade de cadeias de caracteres do teclado;
          - contar a quantidade de símbolos alfanuméricos (letras e dígitos) em cada palavra,
           e calcular o total de todas as palavras, por meio de uma função. 

a.) 
*/


int f_plusalnumcs (int quant) 
{
//variaveis
   int counta=1; //controle quantidade
   chars p=IO_new_chars ( STR_SIZE );
   int tamanho = 0;
   int countb= 0;// controle tamanho
   char simb = '_';
   int countc = 0; //controle quantidade de simbolos alfanum na palavra
   int total =0;// controle total 
   //inputs
   for (counta=1; counta<=quant; counta++) //loop passa de palavra para outra
   {
      p = IO_readString(IO_concat("\nInserir palavra ", IO_concat(IO_toString_d ( counta ), ":") ));
      tamanho = strlen(p);
      for (countb=0; countb<tamanho; countb++) //loop dentro da palavra
      {
         simb = p[countb];
         if (f_isupper(simb) ||  isLowerCase(simb)|| ('0'<=simb && simb<='9'))
         {
            countc=countc+1;//dentro da palavra, quantos alfanum tem
         }// fim if
      }//fim for
      countb=0;//volta inicial para passar de novo pelo loop dentro da proxima palavra
      printf("\nQuantidade de simbolos alfanumericos para a palavra %d e = %d", counta, countc);
      total=total+countc; //controle total
      countc=0;
   }// fim for
   printf("\nTotal de simbolos alfanumericos nas palavras inseridas e: %d", total);
   return(0);
}// fim f_plusalnumcs
 //nao funciona pq a string ta afetando as variaveis int!? -> troquei por IO deu certo

/*
int f_testep1 (char p[])
{
   int count=0;
   int tamanho=0;
   tamanho=strlen(p);
   int posicao=0;
   char c = '.';
   
   for(posicao=0; posicao<tamanho; posicao++)
   {
      c=p[posicao];
      if ( f_isupper(c) ||  isLowerCase(c) || (c>='0' && c<='9'))
      {
         count=count+1;
      }//fim if
   }// fim for
   return (count);
}// fim f_testep1

int f_testep2 (char a[], char b[], char c[], char d[], char e[])
{
   int total=0;
   printf("\n respectivo numero de caracteres alfanum:");
   //printf("\n%d\t%d\t%d\t%d\t%d",f_testep1(a), f_testep1(b), f_testep1(c), f_testep1(d),f_testep1(e));
   total= f_testep1(a)+f_testep1(b)+f_testep1(c)+f_testep1(d)+f_testep1(e);
   printf ("%s%d"," Total= ", total);
   return (0);
}//fim f_testep2
*/


void metodo20 ()
{
// identificação
   printf("\n%s\n","E0420 - Fabiana Kraft - 677262");
     // variaveis
     int quantidade=0;
   // input
   printf ("\n%s", "Insira a quantidade: ");
   scanf("%d", &quantidade);
   //operacao   
   f_plusalnumcs(quantidade);    
   //terminar
   IO_pause("\n Aperte enter para terminar"); 
}//fim metodo20

    /**
Metodo21 - Exemplo0421
Objetivos: - ler certa quantidade de cadeias de caracteres do teclado;
              - contar a quantidade de símbolos alfanuméricos, incluindo espaços em branco, em cada palavra,
              e calcular o total de todas as palavras, por meio de uma função. 

Testes:
a.) 3; a s d g ;%¨&¨asas  as;a        7 (ok)
*/
 int f_plusalnumspc (int quant) 
{
//variaveis
   int counta=1; //controle quantidade
   chars p=IO_new_chars ( STR_SIZE );
   int tamanho = 0;
   int countb= 0;// controle tamanho
   char simb = '_';
   int countc = 0; //controle quantidade de simbolos alfanum na palavra
   int total =0;// controle total 
   //inputs
   for (counta=1; counta<=quant; counta++) //loop passa de palavra para outra
   {
      p = IO_readln(IO_concat("\nInserir palavra ", IO_concat(IO_toString_d ( counta ), ":") ));
      tamanho = strlen(p);
      for (countb=0; countb<tamanho; countb++) //loop dentro da palavra
      {
         simb = p[countb];
         if (f_isupper(simb) ||  isLowerCase(simb)|| ('0'<=simb && simb<='9'))
         {
            countc=countc+1;//dentro da palavra, quantos alfanum tem
         }// fim if
      }//fim for
      countb=0;//volta inicial para passar de novo pelo loop dentro da proxima palavra
      printf("\nQuantidade de simbolos alfanumericos para a palavra %d e = %d", counta, countc);
      total=total+countc; //controle total
      countc=0;
   }// fim for
   printf("\nTotal de simbolos alfanumericos nas palavras inseridas e: %d", total);
   return(0);
}// fim f_plusalnumspc
void metodo21 ()
{
// identificação
   printf("\n%s\n","E0421 - Fabiana Kraft - 677262");
      // variaveis
     int quantidade=0;
   // input
   printf ("\n%s", "Insira a quantidade: ");
   scanf("%d", &quantidade);
   //operacao   
   f_plusalnumspc(quantidade);    
   //terminar
   IO_pause("\n Aperte enter para terminar"); 
}//fim metodo21


    /**
Metodo22 - Exemplo0422
Objetivos: - ler duas cadeias de caracteres do teclado;
              - calcular qual das duas sequências possui a menor quantidade de dígitos,
              por meio de uma função. 
Testes:
a.) AZXCVBNMKMUYTRE; !@#$%¨&*()(OIUJHYGTREDCVBNMJK (ok)
b.)asdfghjklç; asdf)( (ok)
*/

bool f_stramenb (char a[], char b[])
{
int ta=0;
int tb=true;
bool resp=0;
ta= strlen(a);
tb= strlen (b);
if (ta<tb)
{
resp=true;
}// fim if
else
{
 resp=false;
}//fim else
return(resp);
}// fim f_stramenb
void metodo22 ()
{
// identificação
   printf("\n%s\n","E0422 - Fabiana Kraft - 677262");
     // variaveis
     chars n=IO_new_chars ( STR_SIZE );
     chars m=IO_new_chars ( STR_SIZE );

   // input
   n=IO_readString("Insira primeira cadeia de caracteres: ");
   m=IO_readString("Insira segunda cadeia de caracteres: ");
   //operacao e outputs   
   if (f_stramenb(n,m))
   {
   printf ("\n A primeira string e menor que a segunda.");
   }   // fim if
   else 
   {
   printf ("\n A segunda string e menor que a primeira.");
   }//fim else
   
   //terminar
   IO_pause("\n Aperte enter para terminar"); 

   
}//fim metodo22

int main ()
{
   int x=0;
   do
   {
   //identificacao
      printf("\n%s\n",
              "ED04 - v0.0 - Fabiana Kraft - 677262");
      printf("\n%s\n%s\t\t\%s\n%s\t\t%s\n%s\t\t%s\n%s\t\t%s\n%s\t\t%s\n%s\n",
             "Menu de exemplos ED04:", "0- Parar", "1- Exemplo0401",
             "2- Exemplo0402", "3- Exemplo0403", "4- Exemplo0404",
             "5- Exemplo0405","6- Exemplo0406","7- Exemplo0407",
             "8- Exemplo0408","9- Exemplo0409","10- Exemplo04010");
      printf("\n%s\n%s\t\t%s\n%s\t\t%s\n%s\t\t%s\n%s\t\t%s\n%s\t\t%s\n%s\t%s\n%s\n",
             "Menu dos exercicios ED04:", "0- Parar", "1- Exemplo0411",
             "12- Exemplo0412", "13- Exemplo0413", "14- Exemplo0414",
             "15- Exemplo0415","16- Exemplo0416","17- Exemplo0417",
             "18- Exemplo0418","19- Exemplo0419","20- Exemplo04020", "21- Exemplo04021",
             "22- Exemplo04022");
             
      printf("\n%s","Favor inserir numero correspondente: ");
      scanf("%d",&x);          
      switch (x)
      {
         case 0:
            metodo0();
            break;
      
         case 1:
            metodo1();
            break;
      
         case 2:
            metodo2();
            break;
      
         case 3:
            metodo3();
            break;
      
         case 4:
            metodo4();
            break;
      
         case 5:
            metodo5();
            break;
      
         case 6:
            metodo6();
            break;
      
         case 7:
            metodo7();
            break;
            
         case 8:
            metodo8();
            break;
            
         case 9:
            metodo9();
            break;
            
         case 10:
            metodo10();
            break;
      
         case 11:
            metodo11();
            break;
            
         case 12:
            metodo12();
            break;
            
         case 13:
            metodo13();
            break;
            
         case 14:
            metodo14();
            break;
            
         case 15:
            metodo15();
            break;
            
         case 16:
            metodo16();
            break;
      
      
         case 17:
            metodo17();
            break;
      
      
         case 18:
            metodo18();
            break;
      
      
         case 19:
            metodo19();
            break;
      
      
         case 20:
            metodo20();
            break;
      
      
         case 21:
            metodo21();
            break;
      
      
         case 22:
            metodo22();
            break;
      
      
         default:
            printf("\n%s(%d)\n", "Valor inserido diferente do intervalo [0,22] = ", x);
            printf("\n%s\n", "Favor reinserir valor.");
      
      }//fim switch
   }//fimdo
   while(x!=0);

   IO_pause("Apertar enter para terminar");
   return(0);
}// fim main