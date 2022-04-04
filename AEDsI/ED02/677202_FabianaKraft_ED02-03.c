/**
  Program v0.0 - ED02_03
  @author: Fabiana Kraft
  @version: v0.0
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Exercicio 03 Lista ED03

  -------------------Objetivos--------------------------------------------------------------------------------------------------
- ler um valor inteiro do teclado (x) e
- dizer se pertence ao intervalo aberto entre (20:60).
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
     printf("%s\n", "Exercicio 03 - ED02: v0.0" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     int x = 0;
      //Input valor
     printf("Insira um numero inteiro: ");
     scanf("%i", &x);
     //verificar valor e output
      if (x<60 && x>20)
      {
       printf("\n%i%s\n", x," pertence ao intervalo aberto (20:60)");
      }//fim if
            else
      {
          printf("\n%s", "o numero nao se encaixa na categoria pre-definida (pertencer ao intervalo aberto (20:60))");
      } //fim else
      
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
a.) 30 (OK)
b.) -90 (OK)
c.) 60 (OK)
d.) 20 (OK)
e.) 50 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19

---------------------------------------------- testes
Versao Teste
v0.0 ( OK ) ED02_03

*/

