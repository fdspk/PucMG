/**
  Program v0.1 - ED01_10
  @author: Fabiana Kraft
  @version: v0.1
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Exercício 10 Lista ED01

  -------------------Objetivos--------------------------------------------------------------------------------------------------
 - definir e ler um valor real do teclado;
 - supor que esse valor represente o raio de uma esfera (R),calcular e mostrar o volume do mesmo (V).
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

//função principal

int main()
 {
     //ID
     printf("%s\n", "Exercício 10 - ED01: v0.1" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     double R = 0.0;
     double V = 0.0;
      //Input valor
     printf("Insira o valor raio da esfera: ");
     scanf("%lf", &R);
     //verificar valor
      if (R<0)
      {
       printf("\n%s\n", "Valor negativo do raio. Sera considerado o modulo.");
       R=R*(-1);
      }//fim if
      //Operações
      V=(4.0/3.0)*M_PI*pow(R,3);
      //Output
     printf("\n%s%lf\n%s%lf","Raio da esfera=",R,"Volume da esfera= ",V);
     //Terminar
     printf ( "\n\nApertar ENTER para terminar." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)

 } // fim main

 /*
---------------Documentacao complementar----------------------------------------------------------------------------------------

---------------------------------------------- notas / observacoes / comentarios
- Obs1: expressão V=(4/3)*M_PI*pow(R,3) [divide 4 por 3 int] difere de V= (4.0/3.0)*M_PI*pow(R,3) [divide 4.0 por 3.0 double]
---------------------------------------------- previsao de testes
a.) 10 (OK)
b.) 9.8765432 (OK)
c.) -.1234567 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19
v0.1 - 25/08/19 (ver Obs1)


---------------------------------------------- testes
Versao Teste
v0.1 ( OK ) ED01_10

*/

