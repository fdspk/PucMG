/**
  Program v0.0 - ED02_09
  @author: Fabiana Kraft
  @version: v0.0
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Exercicio 09 Lista ED03

  -------------------Objetivos--------------------------------------------------------------------------------------------------
- ler três valores reais do teclado (a, b, c) e
- dizer se o primeiro está entre os outros dois, se esses forem diferentes entre si.
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
     printf("%s\n", "Exercicio 09 - ED02: v0.0" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     double a = 0.0;
     double b = 0.0;
     double c = 0.0;
      //Input valor
     printf("Insira o primeiro numero real: ");
     scanf("%lf", &a);
     printf("%s", "Insira o segundo numero real: ");
     scanf("%lf", &b);
     printf("%s", "Insira o terceiro numero real: ");
     scanf("%lf", &c);
     //verificar valor e output
     
      if ((b>c && a<b && a>c) || (c>b && a<c && a>b))
      {
       printf("\n%lf%s%lf%s%lf%s", a," esta contido no intervalo entre ",b, " e ", c, " e todos sao diferentes entre si");
      } //fim if
      else 
      {
        printf("\n%s", "Os numeros inseridos nao correspondem aos objetivos do exercicio, favor reinserir dados");
      } // fim else if
     
     //Terminar
     printf ( "\n\nApertar ENTER para terminar." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)

 } // fim main

 /*
---------------Documentacao complementar----------------------------------------------------------------------------------------

---------------------------------------------- notas / observacoes / comentarios
N/A
---------------------------------------------- previsao de testes
a.) 1, 0.5 e 2 (OK)
b.) 1, 1 e 2 (OK)
c.) 0.673, 0.79 e 0.67 (OK)
d.) 1.2345, 1.3456 e 1.02348 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19

---------------------------------------------- testes
Versao Teste
v0.0 ( OK ) ED02_09

*/

