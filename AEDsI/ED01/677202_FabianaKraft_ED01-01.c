/**
  Program v0.3 - ED01_01
  @author: Fabiana Kraft
  @version: v0.3
  @date: 21/08/2019
*/
//Identifica��o do programa
/*
  Exerc�cio 01 Lista ED01

  -------------------Objetivos--------------------------------------------------------------------------------------------------
  - definir e ler um valor inteiro do teclado;
  - supor que esse valor represente o lado de um quadrado (a), calcular e mostrar a �rea do mesmo (A).
  ------------------------------------------------------------------------------------------------------------------------------
*/

// lista de dependencias
#include <stdio.h>     // para entradas e saida
#include <stddef.h>    // para definicoes basicas
#include <stdlib.h>    // para a biblioteca padrao
#include <string.h>    // para cadeias de caracteres
#include <stdarg.h>    // para tratar argumentos
#include <stdbool.h>   // para definicoes logicas
#include <ctype.h>     // para tipos padroes
#include <math.h>      // para definicoes matematicas
#include <time.h>      // para medir tempo

//fun��o principal

int main()
 {
     //ID
     printf("%s\n", "Exerc�cio 01 - ED01: v0.3" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     int a = 0;
     int A = 0;
      //Input valor
     printf("Insira o valor inteiro do lado do quadrado:");
     scanf("%d", &a);
      //verificar valor
      if (a<0)
      {
       printf("\n%s\n", "Valor negativo. Sera considerado o modulo.");
       a=a*(-1);
      }
      //Opera��es
     A=a*a;
      //Output
     printf("%s%d\n%s%d","Lado do quadrado=",a, "Area do quadrado=",A);
     //Terminar
     printf ( "\n\nApertar ENTER para terminar." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)

 } // fim main

 /*
---------------Documentacao complementar----------------------------------------------------------------------------------------

---------------------------------------------- notas / observacoes / comentarios
*obs1:
Tentativa de usar A=pow(a,2); Por�m para resultados a=5 e a=10, obteve-se respectivamente A=24 e A=99.
A partir de informa��es averiguadas por outros usu�rios com o mesmo tipo de problema, chegou-se � conclus�o que pow deve ser
modificada (criar uma fun��o) para n�meros inteiros, devido � forma que a linguagem opera os dados da fun��o, tornando-se
imprecisa para caso de inteiros.

*obs2:
Adi��o de condicional, devido � possibilidade de input de valor negativo

---------------------------------------------- previsao de testes
a.) 5 (OK)
b.) 3 (OK)
c.) 10 (OK)
d.)897 (OK)
e.)-3 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 21/08/19
v0.1 - 21/08/19 (ver obs1)
v0.3 - 21/08/19 (ver obs2)

---------------------------------------------- testes
Versao Teste
v0.3 ( OK ) ED01_01

*/

