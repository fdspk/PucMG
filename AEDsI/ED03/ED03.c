/**
Lista ED03
Autora:Fabiana Dinelli Salvatico de Paula Kraft
Matricula: 677262
Data:30/08/2019
v0.0
*/

//incluir bibliotecas
#include "io.h"

/**
Metodo0- parar
Teste (OK)
*/
void metodo0 ()
{
//nada
} //fim metodo0

 /**
Metodo01- Exemplo01
Objetivos:Repeticao com teste no inicio. 
          Ler um inteiro positivo e mostrar ele e os inteiros abaixo dele, até o numero 1.
Testes:
a.) 0 (ok)
b.) 1 (ok)
c.) 2 (ok)
d.) 3 (ok)
e.) 4 (ok)
f.) -1 (ok)

*/
void metodo01 ()
{
   // identificar
   printf ( "\n%s\n%s\n","EXEMPLO0301 - metodo01 - v0.0", "Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Repeticao com teste no inicio. Ordem decrescente");
   // definir dado
   int x = 0;
// ler do teclado o valor inicial
   x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
   while ( x > 0 )
   {
   // mostrar valor atual
      IO_println ( IO_toString_d ( x ) );
   // passar ao proximo valor
      x = x - 1;
   } // fim repetir
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} //fim metodo01


  /**
Metodo02- Exemplo02
Objetivos: Repeticao com teste no inicio.
          Ler um inteiro positivo e mostrar ele e os inteiros abaixo dele, até o numero 1.
Testes:  
a.) 0 (ok)
b.) 1 (ok)
c.) 2 (ok)
d.) 3 (ok)
e.) 4 (ok)
f.) -1 (ok)

Comentarios: v0.1 - Necessario trocar x por y no IO_println no meio do loop

*/
void metodo02 ()
{  
   // definir dado
   int x = 0;
   int y = 0;
// identificar
   printf ( "\n%s\n%s\n","EXEMPLO0302 - metodo02 - v0.1", "Fabiana Kraft - 677262");
   printf("%s\n", "Objetivos: Repeticao com teste no inicio. Ordem decrescente");
// ler do teclado
   x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
   y = x; // copiar o valor lido (e' melhor)
   while ( y > 0 )
   {
   // mostrar valor atual
      IO_println ( IO_toString_d ( y ) );
   // passar ao proximo valor
      y=y-1;
   } // fim repetir
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} //fim metodo02

  /**
Metodo03- Exemplo03
Objetivos: Repeticao com teste no inicio.
           Mostrar um valor a partir do 1, aumentando de 1 em 1, até um valor inteiro inserido pelo usuario
Testes: 
a.) 0 (ok)
b.) 1 (ok)
c.) 2 (ok)
d.) 10 (ok)
e.) -5 (ok)
*/
void metodo03 ()
{
   // definir dado
   int x = 0;
   int y = 0;
// identificar
   printf( "\n%s\n%s\n","EXEMPLO0303 - metodo03 - v0.0","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Repeticao com teste no inicio. Ordem crescente.");
// ler do teclado
   x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
   y = 1; // copiar o valor lido (e' melhor)
   while ( y <= x )
   {
   // mostrar valor atual
      IO_printf ( "%d\n", y );
   // passar ao proximo valor
      y = y + 1;
   } // fim repetir
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} //fim metodo03

  /**
Metodo04- Exemplo04
Objetivos: Repeticao com teste no inicio e variacao.
            Mostrar um valor a partir do 1, aumentando de 1 em 1, até um valor inteiro inserido pelo usuario.
Testes: 
a.) 0 (ok)
b.) 1 (ok)
c.) 2 (ok)
d.) 10 (ok)
e.) -5 (ok)
*/
void metodo04 ()
{
   // definir dado
   int x = 0;
   int y = 0;
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0304 - metodo04 - v0.0","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Repeticao com teste no inicio e variacao. Ordem crescente.");
// ler do teclado
   x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
// inicio teste variacao
   for ( y = 1; y <= x; y = y + 1 )
   {
   // mostrar valor atual
      IO_printf ( "%d\n", y );
   } // fim repetir
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} //fim metodo04

  /**
Metodo05- Exemplo05
Objetivos:Repeticao com teste no inicio e variacao.
          Ler um inteiro positivo e mostrar ele e os inteiros abaixo dele, até o numero 1.
Testes:
a.) 0 (ok)
b.) 1 (ok)
c.) 5 (ok)
d.) 10 (ok)
e.) -1 (ok)

*/
void metodo05 ()
{
   // definir dado
   int x = 0;
   int y = 0;
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0305 - metodo05 - v0.0","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Repeticao com teste no inicio e variacao. Ordem decrescente.");
// ler do teclado
   x = IO_readint ( "Entrar com uma quantidade: " );
// repetir (x) vezes
// inicio teste variacao
   for ( y = x; y >= 1; y = y - 1 )
   {
   // mostrar valor atual
      IO_printf ( "%d\n", y );
   } // fim repetir
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} //fim metodo05

  /**
Metodo06- Exemplo06
Objetivos: Repeticao sobre cadeia de caracateres.
           Mostra caracteres de tras para frente.
Testes:
a.) pqwereerere (ok)
b.) pj5 (ok)
c.) abc (ok)
d.) inconstitucionalicinalmente (ok)
e.) Grundstücksverkehrsgenehmigungszuständigkeitsübertragungsverordnung  (ok)

*/
void metodo06 ()
{
   // definir dado
   int x = 0;
   int y = 0;
   chars palavra = IO_new_chars ( STR_SIZE );
   int tamanho = 0;
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0306 - metodo06 - v0.0","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Repeticao sobre cadeia de caracateres. Ordem decrescente ");
// ler do teclado
   palavra = IO_readstring ( "Entrar com uma palavra: " );
// repetir para cada letra
   tamanho = strlen ( palavra )-1;
// inicio teste variacao
   for ( y = tamanho; y >= 0; y = y - 1 )
   {
   // mostrar valor atual
      IO_printf ( "%d: [%c]\n", y, palavra [y] );
   } // fim repetir
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} //fim metodo06

  /**
Metodo07- Exemplo07
Objetivos: Repeticao sobre cadeia de caracateres.
           Mostra caracteres na ordem.
a.) mitfahrgelegenheit (ok)
b.) abcdefgh (ok)
c.) qwertyuiop (ok)
d.) ![]=+-?;/ (ok)
e.) 123/0 (ok)
Comentários: troquei y=0 por y=1;  fiz palavra [y-1]; y de <tamanho para <=tamanho -> resultado: aparece [1] em vez de [0] e assim por diante
*/
void metodo07 ()
{
   // definir dado
   int x = 0;
   int y = 0;
   char palavra [STR_SIZE];
   int tamanho = 0;
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0307 - metodo07 - v0.1","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Repeticao sobre cadeia de caracateres. Ordem crescente ");
// ler do teclado
   IO_printf ( "Entrar com uma palavra: " );
   scanf ( "%s", palavra );
// repetir para cada letra
   tamanho = strlen ( palavra );
// inicio teste variacao
   for ( y = 1; y <= tamanho; y = y + 1 )
   {
   // mostrar valor atual
      IO_printf ( "%d: [%c]\n", y, palavra [y-1] );
   } // fim repetir
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} //fim metodo07

  /**
Metodo08- Exemplo08
Objetivos: Repeticao com intervalos. Mostra variação de 1 em 1 crescente entre um numero inferior e um superior dados pelo usuario
Testes:
a.) 1 e 1 (ok)
b.) 1 e 10 (ok)
c.) -5 e 5 (ok)
d.) 5 e -5 (ok)
*/
void metodo08 ()
{
   // definir dado
   int inferior = 0;
   int superior = 0;
   int x = 0;
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0308 - metodo08 - v0.0","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Repeticao com intervalos. Ordem crescente ");
// ler do teclado
   inferior = IO_readint ( "Limite inferior do intervalo: " );
   superior = IO_readint ( "Limite superior do intervalo : " );
// inicio teste variacao
   for ( x = inferior; x <= superior; x = x + 1 )
   {
   // mostrar valor atual
      IO_printf ( "%d\n", x );
   } // fim repetir
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} //fim metodo08

  /**
Metodo09- Exemplo09
Objetivos: Repeticao com intervalos. Mostra variação de passo em passo (dado pelo usuario) decrescente entre um numero superior e inferior dados pelo usuario.
Testes:
 Testes: 
a.)1  2    0.1 (ok)
b.)1  10     1 (ok)
c.).000001   .000010   .000001 (ok)
Comentario: IO_readdouble: ex: do intervalo superior 2 e inferior 1 epara valores de passo 0.1, nao mostra o intervalo inferior (mostra até 1.1) 
            Solução: ? x>inferior-0.0000000001 (=dx) (gambiarra, porem funcionou)


*/
void metodo09 ()
{
   // definir dado
   double inferior = 0.0;
   double superior = 0.0;
   double passo = 0.0;
   double x = 0.0;
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0309 - metodo09 - v0.1","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Repeticao com intervalos. Ordem derescente ");
// ler do teclado
   inferior = IO_readdouble ( "Limite inferior do intervalo : " );
   superior = IO_readdouble ( "Limite superior do intervalo : " );
   passo = IO_readdouble ( "Variacao no intervalo (passo): " );
// inicio teste variacao
   for ( x = superior; x> inferior-0.00000000001; x = x - passo )
   {
   // mostrar valor atual
      IO_printf ( "%lf\n", x );
   } // fim repetir
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} //fim metodo09

  /**
Metodo10- Exemplo10
Objetivos: Repeticao com confirmacao. Ordem crescente
Comentario: mesmo prolema do exemplo 09, nao aceita valores muito pequenos
Teste:
a.) 0  1  0.5  (ok)
b.)1  2  0.2 (Ok)
c.) 1 e 1.1 -> nao aceita, só aceitou a partir de dx=+1
d.) dx muito pequeno nao mostra o ultimo numero (x=inferior)
*/
void metodo10 ()
{
   // definir dado
   double inferior = 0;
   double superior = 0;
   double passo = 0;
   double x = 0;
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0310 - metodo10 - v0.0","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Repetir com confirmacao. Ordem derescente ");
// ler do teclado
   inferior = IO_readdouble ( "Limite inferior do intervalo : " );
// repetir ate' qua haja confirmacao de validade
   do
   {
      superior = IO_readint ( "Limite superior do intervalo: " );
   }
   while ( inferior >= superior );
// repetir ate' qua haja confirmacao de validade
   do
   {
      passo = IO_readdouble ( "Variacao no intervalo (passo): " );
   }
   while ( passo <= 0.0 );
// inicio teste variacao
   for ( x = inferior; x <= superior; x = x + passo )
   {
   // mostrar valor atual
      IO_printf ( "%lf\n", x );
   } // fim repetir
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} //fim metodo10

/**
Metodo11 -exemplo011 ou exercicio1
Objetivo: Ler uma palavra do teclado. Mostrar as letras maiusculas 
Testes:
a.)AsdFgHJkL (ok)
b.)asCghHaiOtyRhjEahdI (ok)
c.) acHqoudEauLuoasdhP!(ok)
 
Comentarios: coloquei 80 deentro do [], senao pegava so 3
*/
void metodo11 ()
{
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0312 - metodo12 - v0.1","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Ler uma palavra do teclado. Mostrar as letras maiusculas ");
//inputs
   char palavra [80]= "abc";
   int posicao = 0;
   int tamanho = 0;
   printf("\n%s","Escreva uma palavra ");
   scanf("%s", palavra);
   tamanho= strlen (palavra);
   printf("\n%s","As letras maiusculas sao: ");
//operações e outputs
   for  (posicao=0; posicao<=tamanho; posicao=posicao+1)
   {
      if (isupper(palavra[posicao]))
      {
         printf("\t%c", palavra[posicao]);
      }//fim if 
   }//fim for
   
   IO_pause ( "Apertar ENTER para continuar" );

} //fim metodo11


/**
Metodo12 -exemplo012 ou exercicio2
Objetivo: Ler uma palavra do teclado. Mostrar as letras maiusculas e a quantidade
Testes:
a.)StaFILoCocuS (ok)
b.))_!LcUJsª (ok)
c.) 12Gs0O (ok)
*/
void metodo12 ()
{
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0312 - metodo12 - v0.1","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Ler uma palavra do teclado. Mostrar as letras maiusculas ");
//inputs
   char palavra [80]= "abc";
   int posicao = 0;
   int tamanho = 0;
   int quantidade = 0;
   printf("\n%s","Escreva uma palavra ");
   scanf("%s", palavra);
   tamanho= strlen (palavra);
//operações e outputs
   for  (posicao=0; posicao<=tamanho; posicao=posicao+1)
   {
      if (isupper(palavra[posicao]))
      {
         quantidade=quantidade+1;
         printf("\n%s%c%s%d", " letra ", palavra[posicao], " na posicao ", posicao+1);
      }//fim if 
   }//fim for
   printf("\n%s%d", "Numero de letras maiusculas: ", quantidade);
   /* Obs: com while 
   while  (posicao<tamanho)
   {
      if (isupper(palavra[posicao]))
      {
         quantidade = quantidade+1;
         printf("\n%s%c%s%d", " letra ", palavra[posicao], " na posicao ", posicao+1);
      }//fim if 
      posicao=posicao+1;
   }//fim while
   */
          
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

} //fim metodo12

  /**
Metodo13 -exemplo013 ou exercicio3
Objetivo: Ler uma palavra do teclado. Mostrar as letras maiusculas e posicao de tras para frente
Testes:
a.)ABCdefGHIjklMNOP (ok)
b.)ASxccUHUOAshOas (ok)
c.) HGsjK (ok)
*/

void metodo13 ()
{
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0313 - metodo13 - v0.0","Fabiana Kraft - 677262" );
   printf("%s\n%s\n", "Objetivos: Ler uma palavra do teclado.",
                       "Mostrar as letras maiusculas e a posicao de tras para frente ");
//inputs
   char palavra [80]= "abc";
   int posicao = 0;
   int tamanho = 0;
   int quantidade=0;
   printf("\n%s","Escreva uma palavra ");
   scanf("%s", palavra);
   tamanho= strlen (palavra);
   posicao=tamanho-1;
//operações e outputs
   while  (posicao>=0)
   {
      if (isupper(palavra[posicao]))
      {
         quantidade = quantidade+1;
         printf("\n%s%c%s%d", " letra ", palavra[posicao], " na posicao ", posicao+1);
      }//fim if 
      posicao=posicao-1;
   }//fim while 
   printf("\n%s%d", "Numero de letras maiusculas: ", quantidade);            
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

} //fim metodo13

  /**
Metodo14 -exemplo014 ou exercicio4
Objetivo: Ler uma cadeia de caracteres do teclado. Mostrar as letras 
Testes:
a.)!|;aHs=KL][}sK (ok)
b.)+=-!CCDdEZz (ok)
c.) _____aaaaa____OMG!4564645O (ok)

*/

void metodo14 ()
{
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0314 - metodo14 - v0.0","Fabiana Kraft - 677262" );
   printf("%s\n%s\n", "Objetivos: Ler uma cadeia de caracteres do teclado.",
                       "Mostrar as letras");
//inputs
   char palavra [80]= "abc";
   int posicao = 0;
   int tamanho = 0;
   int quantidade=0;
   printf("\n%s","Escreva uma cadeia de caracteres: ");
   scanf("%s", palavra);
   tamanho= strlen (palavra);
//operações e outputs
   while  (posicao<=tamanho)
   {
      if (isalpha(palavra[posicao]))
      {
         quantidade = quantidade+1;
         printf("\n%s%c%s%d", " letra ", palavra[posicao], " na posicao ", posicao+1);
      }//fim if 
      posicao=posicao+1;
   }//fim while 
   printf("\n%s%d", "Numero de letras: ", quantidade);            
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

} //fim metodo14

 /**
Metodo15 -exemplo015 ou exercicio5
Objetivo: ler uma cadeia de caracteres do teclado;
             contar e mostrar todos os dígitos, começando do fim para o início da cadeia de caracteres.
Testes:
a.)ans123o+-45 (ok)
b.)aso129-3]]a]á[p' (ok)
*/

void metodo15 ()
{
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0315 - metodo15 - v0.0","Fabiana Kraft - 677262" );
   printf("%s\n%s\n", "Objetivos: Ler uma cadeia de caracteres do teclado.",
                       "Mostrar digitos de tras para frente");
//inputs
   char palavra [80]= "abc";
   int posicao = 0;
   int tamanho = 0;
   int quantidade=0;
   printf("\n%s","Escreva uma cadeia de caracteres: ");
   scanf("%s", palavra);
   tamanho= strlen (palavra);
//operações e outputs
   for  (posicao=tamanho-1; posicao>=0; posicao=posicao-1)
   {
      if (isdigit(palavra[posicao]))
      {
         quantidade = quantidade+1;
         printf("\n%s%c%s%d", " numero ", palavra[posicao], " na posicao ", posicao+1);
      }//fim if 
   }//fim for 
   printf("\n%s%d", "Numero de digitos: ", quantidade);            
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

} //fim metodo15

 /**
Metodo16 -exemplo016 ou exercicio6
Objetivo: Ler uma cadeia de caracteres do teclado. Mostrar tudo que nao for digito nem letra
Testes:
a.)ay978+=+~´ (ok)
b.)***aa)({13a (ok)
Comentarios: <=tamanho para <tamanho dentro do for, pois senao pega o enter ao confirmar a cadeia de caracteres
 
*/
void metodo16 ()
{
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0316 - metodo16 - v0.1","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Ler uma cadeia de caracteres do teclado. Mostrar tudo que nao for digito nem letra ");
//inputs
   char palavra [80]= "abc";
   int posicao = 0;
   int tamanho = 0;
   int quantidade = 0;
   printf("\n%s","Escreva uma cadeia de caracteres ");
   scanf("%s", palavra);
   tamanho= strlen (palavra);
//operações e outputs
   for  (posicao=0; posicao<tamanho; posicao=posicao+1)
   {
      if (!(isalnum(palavra[posicao])))
      {
         quantidade=quantidade+1;
         printf("\n%s%c%s%d", " caractere ", palavra[posicao], " na posicao ", posicao+1);
      }//fim if 
   }//fim for
   printf("\n%s%d", "Numero de caracteres nao alfanumericos: ", quantidade);
       
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

} //fim metodo16


    /**
Metodo17 -exemplo017 ou exercicio7
Objetivo: - ler dois valores inteiros para definir um intervalo;
             - ler uma quantidade de valores inteiros a serem testados, e
              ler outros tantos valores quanto os indicados pela quantidade;
             - contar e mostrar todos os múltiplos de 5.
   Testes:
a.)5, {200, 70, 66, -1, 54, 12, 10} (ok)
Comentarios: <=tamanho para <tamanho dentro do for, pois senao pega o enter ao confirmar a cadeia de caracteres
*/

void metodo17 ()
{
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0317 - metodo17 - v0.0","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Verificar se os numeros inseridos dentro do intervalo sao multiplos de 5");
//declaracoes e inputs
   int superior = 0;
   int inferior =0;
   int quantidade=0;
   int controle=0;
   int contador=0;
   int x =0;
   printf("\n%s","Inserir valor inferior do intervalo: ");
   scanf("%d",& inferior);
   printf("\n%s","Inserir valor superior do intervalo: ");
   scanf("%d",& superior);
   printf("\n%s","Inserir a quantidade de valores a serem lidos: ");
   scanf("%d",& quantidade);
   int valor [quantidade];
   controle=quantidade;
   // operacoes e outputs
   while (controle>0)
   {
      printf("\n%s[%d] ", "Inserir valor ", controle);
      scanf("%d", &x);
      if (x<=superior && x>=inferior)
      {
         valor[controle]=x;
         controle=controle-1;
      }//fim if
      else
      {
         printf("\n%s%d%s%d","favor inserir um valor entre ", inferior, " e ", superior);
      }//fim else
   }//fim while
   for (controle=0; controle<=quantidade; controle=controle+1)
   {
      if (valor[controle]%5==0)
      {
         contador=contador+1;
         printf("\n%s(%d)%s" ,"O valor ", valor[controle], " e divisivel por 5.");
      }//fim if
   }//fim for
   printf("\n%s%d","O numero de valores inseridos divisiveis por 5 sao: ", contador);
   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" ); 

}// fim metodo17

  /**
Metodo18 -exemplo018 ou exercicio8
Objetivo: - ler dois valores inteiros para definir um intervalo;
             - ler uma quantidade de valores inteiros a serem testados, e
                ler outros tantos valores quanto os indicados pela quantidade;
             - contar e mostrar todos os múltiplos de 3 que não forem também múltiplos de 5.
   Testes:
a.)[5,100],5, {200 (pede outro), 70, 66, -1 (pede outro), 54, 12, 10} (ok)
b.)[300, 30](pede outro)(ok)
c.)[30, 300], 0 (pede outro) -1(pede outro), 2, {6,5} (ok)
*/

void metodo18 ()
{
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0318 - metodo18 - v0.0","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Verificar se os numeros inseridos dentro do intervalo sao multiplos de 3 e nao de 5");
//declaracoes e inputs
   int superior = 0;
   int inferior =0;
   int quantidade=0;
   int controle=0;
   int contador=0;
   int x =0;
   while(inferior>=superior)
   {
      printf("\n%s","Inserir valor inferior do intervalo: ");
      scanf("%d",& inferior);
      printf("\n%s","Inserir valor superior do intervalo: ");
      scanf("%d",& superior);
      if (inferior>=superior)
      {
         printf("\n%s\n","Favor inserir valor superior acima do inferior");
      }//fim if
   }//fim while
   do
   {
      printf("\n%s","Inserir a quantidade de valores a serem lidos: ");
      scanf("%d",& quantidade);
      if (quantidade<=0)
      {
         printf("\n%s\n","Favor inserir quantidade acima de zero");
      }//fim if
   }//fim do
   while (quantidade<=0);
 
   int valor [quantidade];
   controle=quantidade;
   // operacoes e outputs
   while (controle>0)
   {
      printf("\n%s[%d] ", "Inserir valor ", controle);
      scanf("%d", &x);
      if (x<=superior && x>=inferior)
      {
         valor[controle]=x;
         controle=controle-1;
      }//fim if
      else
      {
         printf("\n%s%d%s%d","favor inserir um valor entre ", inferior, " e ", superior);
      }//fim else
   }//fim while
   for (controle=0; controle<=quantidade; controle=controle+1)
   {
      if (valor[controle]%3==0 && valor[controle]%5!=0)
      {
         contador=contador+1;
         printf("\n%s(%d)%s" ,"O valor ", valor[controle], " e divisivel por 3, mas nao por 5.");
      }//fim if
   }//fim for
   printf("\n%s%d","O numero de valores inseridos divisiveis por 3, mas nao por 5, sao: ", contador);
   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" ); 

}// fim metodo18


  /**
Metodo19 -exemplo019 ou exercicio9
Objetivo: ler dois valores reais, o primeiro menor que o segundo, confirmadamente,para definir um intervalo;
             - ler uma quantidade de valores REAIS a serem testados, e
              ler outros tantos valores quanto os indicados pela quantidade;
             - contar e mostrar todos os valores lidos, pertencentes ao do intervalo,
              cujas partes inteiras forem ímpares.
   Testes:
a.) [10.99 1.5] pede reinsercao dos dados (ok)
b.) [1.5 10.99], 0 (pede outro) 5, {31.55, 9.87, 2.54, 6.99, 4.99} (ok, nao arredonda, pega so a parte inteira)
c.) [-10.546, -1.29], 5, {1, -1, -9.55, -10.5, -11} (ok)
*/

void metodo19 ()
{
//identificacao
   printf ( "\n%s\n%s\n", "EXEMPLO0319 - metodo19 - v0.0","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Ler valores reais. Mostrar se pertencem ao intervalo e possuem partes inteiras impares ");
   
//definir variaveis (1)

   double superior= 0.0;
   double inferior= 0.0;
   int quantidade = 0.0;
   
 //inputs (1)
   while (inferior>=superior)
   {
      printf("\n%s","Inserir valor inferior do intervalo: ");
      scanf("%lf",& inferior);
      printf("\n%s","Inserir valor superior do intervalo: ");
      scanf("%lf",& superior);
      if (inferior>=superior)
      {
         printf("\n%s\n","Favor inserir valor superior acima do inferior");
      }//fim if
   }//fim while
   do
   {
      printf("\n%s","Inserir a quantidade de valores a serem lidos: ");
      scanf("%d",& quantidade);
      if (quantidade<=0)
      {
         printf("\n%s\n","Favor inserir quantidade acima de zero");
      }//fim if
   }//fim do
   while (quantidade<=0);
   
   //variaveis (2)
   double valor[quantidade];
   int valorint [quantidade];
   int controle=0;
   controle=quantidade;
   
   // operacoes, inputs e outputs (2)
   while (controle>0)
   {
      printf("\n%s[%d] ", "Inserir valor ", controle);
      scanf("%lf", &valor[controle]);
      
      valorint[controle]=valor[controle];
      controle=controle-1;
   }//fim while
   
   // variaveis (3)
   int contador=0;
   
   //operacoes e outputs (3)
   for (controle=0; controle<=quantidade; controle=controle+1)
   {
      if (valor[controle]<=superior && valor[controle]>=inferior && valorint[controle]%2!=0)
      {
         contador=contador+1;
         printf("\n%s(%lf)%s[%lf,%lf]\n%s(%d)%s" ,"O valor ", valor[controle], " pertence ao intervalo", 
                                                 inferior, superior, "E possui parte inteira ", 
                                                 valorint[controle], " impar." );
      }//fim if
   }//fim for
   printf("\n%s%d","O numero de valores pertencentes ao intervalo, com parte inteira impar sao: ", contador);
   
   //encerrar
   IO_pause ( "Apertar ENTER para continuar" ); 
}//fim metodo19


    /**
Metodo20 -exemplo020 ou exercicio20
Objetivo: - ler dois valores reais, menores que 1 e diferentes de 0, confirmadamente,
                para definir um intervalo;
            - ler uma quantidade de valores reais a serem testados, e
               ler outros tantos valores quanto os indicados pela quantidade;
            - contar e mostrar todos os valores lidos
               que tenham suas partes fracionárias dentro do intervalo.
   Testes:
a.) [0 e 10] (pede outro) [0.9 e 0.3] (pede outro) [0.3 e 0.99], 5, {6.54, 9.02, .66, 84566.55, 156.2} (ok)
b.)
*/

void metodo20 ()
{
//identificacao
   printf ( "\n%s\n%s\n", "EXEMPLO0320 - metodo20 - v0.0","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Ler valores reais. Mostrar se suas partes fracionarias pertencem ao intervalo ");
   
//definir variaveis (1)

   double superior= 0.0;
   double inferior= 0.0;
   int quantidade = 0.0;
   
 //inputs (1)
   do 
   {
      printf("\n%s","Inserir valor inferior do intervalo: ");
      scanf("%lf",& inferior);
      printf("\n%s","Inserir valor superior do intervalo: ");
      scanf("%lf",& superior);
      if (inferior>=superior)
      {
         printf("\n%s\n","Favor inserir valor superior acima do inferior");
      }//fim if
      if (inferior>=1 || inferior<=0)
      {
         printf("\n%s\n","Favor inserir valor inferior no intervalo aberto (0,1)");
      }//fim if
      if (superior>=1 || superior<=0)
      {
         printf("\n%s\n","Favor inserir valor superior no intervalo aberto (0,1)");
      }//fim if
   }//fim do
   while(inferior>=superior || !(inferior<1 && inferior>0) || !(superior<1 && superior>0) );
   
   do
   {
      printf("\n%s","Inserir a quantidade de valores a serem lidos: ");
      scanf("%d",& quantidade);
      if (quantidade<=0)
      {
         printf("\n%s\n","Favor inserir quantidade acima de zero");
      }//fim if
   }//fim do
   while (quantidade<=0);
   
   //variaveis (2)
   double valor[quantidade];
   int valorint [quantidade];
   double valorfrac [quantidade];
   int controle=0;
   controle=quantidade;
   
   // operacoes, inputs e outputs (2)
   while (controle>0)
   {
      printf("\n%s[%d] ", "Inserir valor ", controle);
      scanf("%lf", &valor[controle]);
      
      valorint[controle]=valor[controle];
      valorfrac [controle] = valor[controle]-valorint[controle];
      controle=controle-1;
   }//fim while
   
   // variaveis (3)
   int contador=0;
   
   //operacoes e outputs (3)
   for (controle=0; controle<=quantidade; controle=controle+1)
   {
      if (valorfrac[controle]<=superior && valorfrac[controle]>=inferior)
      {
         contador=contador+1;
         printf("\n%s(%lf)%s(%lf)%s[%lf,%lf]\n" ,"O valor ", valor[controle], " possui parte fracionaria",
                                                 valorfrac[controle], " pertencente ao intervalo ", 
                                                 inferior, superior);
      }//fim if
   }//fim for
   printf("\n%s%d","O numero de valores pertencentes ao intervalo sao: ", contador);
   
   //encerrar
   IO_pause ( "Apertar ENTER para continuar" ); 
}//fim metodo20


 /**
Metodo21 -exemplo021 ou tarefa extra 01
Objetivo: - ler uma linha do teclado;
             - separar e mostrar todos os símbolos não alfanuméricos (letras ou dígitos) na cadeia de caracteres.
Testes:
a.)ay978+=+~´ (ok)
b.)***aa)({13a (ok)
c.) !@#$%¨&*()_+/?°`{´]}[^~;:.,\|"' (ok)
d.) ç (le como nao alfanumerico- ok?)
 */
void metodo21 ()
{
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0321 - metodo21 - v0.0","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Ler uma cadeia de caracteres do teclado. Mostrar os simbolos nao alfanumericos ");
//inputs
   char palavra [80]= "abc";
   int posicao = 0;
   int tamanho = 0;
   printf("\n%s","Escreva uma cadeia de caracteres ");
   scanf("%s", palavra);
   tamanho= strlen (palavra);
   printf("\n");
//operações e outputs
   for  (posicao=0; posicao<tamanho; posicao=posicao+1)
   {
      if (!(isalnum(palavra[posicao])))
      {
         printf("\t%c", palavra[posicao]);
      }//fim if 
   }//fim for
       
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

} //fim metodo21

 /**
Metodo22 -exemplo022 ou tarefa extra 02
Objetivo: - ler uma cadeia de caracteres do teclado;
             - dizer se a sequência contém apenas símbolos que não são letras.
Testes:
a.)#$%¨&*7$%¨&*((ok)
b.)@#$%&*(ok)
c.)$%¨&t%¨&* (ok)
*/
void metodo22 ()
{
// identificar
   printf ( "\n%s\n%s\n", "EXEMPLO0321 - metodo21 - v0.0","Fabiana Kraft - 677262" );
   printf("%s\n", "Objetivos: Ler uma cadeia de caracteres do teclado. Mostrar os simbolos nao alfanumericos ");
//inputs
   char palavra [80]= "abc";
   int posicao = 0;
   int tamanho = 0;
   int flag=0;
   printf("\n%s","Escreva uma cadeia de caracteres ");
   scanf("%s", palavra);
   tamanho= strlen (palavra);
   printf("\n");
//operações e outputs
   for  (posicao=0; posicao<tamanho; posicao=posicao+1)
   {
      if (isalnum(palavra[posicao]))
      {
         flag=1;
      }//fim if 
   }//fim for
   if (flag==0)
   {
      printf("\n%s","Todos caracteres inseridos sao nao alfanumericos.");
   }//fim if
   else 
   {
      printf("\n%s", "Existem caracteres alfanumericos nos dados inseridos.");
   }//fim else
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

} //fim metodo22


int main ()
{
   int x = 0;
   do
   {
   // input switch
   //id
      printf("\n%s\n", "ED03 - Autora: Fabiana Kraft - 677262 - v0.0");
      printf("%s\n%s\t\t\t%s\n%s\t\t%s\n%s\t\t%s\n%s\t\t%s\n%s\t\t%s\n%s",
            "Menu da lista E3 - Exemplos", 
            "0 - parar", "1 - Exemplo01", "2 - Exemplo02","3- Exemplo03",
            "4- Exemplo04", "5 - Exemplo05","6- Exemplo06","7- Exemplo07",
            "8- Exemplo08","9- Exemplo09","10- Exemplo10");
      printf("\n\n%s\n%s\t\t\t\t%s\n%s\t\t%s\n%s\t\t%s\n%s\t\t%s\n%s\t\t%s\n%s\t\t%s\n%s",
            "Menu da lista E3 - Exercicios", 
            "0 - parar", "11 - Exercicio01", "12 - Exercicio2","13- Exercicio03",
            "14- Exercicio04", "15 - Exercicio05","16- Exercicio06","17- Exercicio07",
            "18- Exercicio08","19- Exercicio09","20- Exercicio10","21-Tarefaextra01",
            "22-Tarefaextra02");
      printf("%s", "\n\nInsira um valor de 0 a 22: ");
      scanf("%d",&x);
      switch (x)
      {
         case 0:
            metodo0();
            break;
         case 1:
            metodo01();
            break;
         case 2:
            metodo02();
            break;
         case 3:
            metodo03();
            break;
         case 4:
            metodo04();
            break;
         case 5:
            metodo05();
            break;
         case 6:
            metodo06();
            break;
         case 7:
            metodo07();
            break;
         case 8:
            metodo08();
            break;
         case 9:
            metodo09();
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
            printf("\n%s(%d)", "Valor inserido diferente do intervalo: ", x);
            printf("\n%s", "Favor reinserir dado");
      } //fim switch
   }//fim do
   while(x!=0);
   IO_pause ( "Apertar ENTER para terminar" );
   return ( 0 );
} // fim main