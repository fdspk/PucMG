/**
  Program v0.1 - ED01_07
  @author: Fabiana Kraft
  @version: v0.1
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Exercício 07 Lista ED01

  -------------------Objetivos--------------------------------------------------------------------------------------------------
  - definir e ler um valor real do teclado;
  - supor que esse valor represente a medida de lados de um cubo (l),calcular e mostrar o volume do sólido (V).
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
     printf("%s\n", "Exercício 07 - ED01: v0.1" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     double l = 0.0;
     double V = 0.0;
      //Input valor
     printf("Insira o valor do lado do cubo:");
     scanf("%lf", &l);
     //verificar valor
      if (l<0)
      {
       printf("\n%s\n", "Valor negativo do lado. Sera considerado o modulo.");
       l=l*(-1);
      }//fim if
      //Operações
     V=pow(l,3);
      //Output
     printf("\n%s%lf\n%s%lf","Lado do cubo=",l,"Volume do cubo=",V);
     //Terminar
     printf ( "\n\nApertar ENTER para terminar." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)

 } // fim main

 /*
---------------Documentacao complementar----------------------------------------------------------------------------------------

---------------------------------------------- notas / observacoes / comentarios
- Obs1 Uso do "^" apenas para int
---------------------------------------------- previsao de testes
a.) 2 (OK)
b.) -1.23456 (OK)
c.) 123.4567 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19
v0.0 - 25/08/19 (ver Obs1)

---------------------------------------------- testes
Versao Teste
v0.1 ( OK ) ED01_07

*/

