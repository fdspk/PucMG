#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

# define N 50
#define MAX_H 10
#define MIN_H 1
//variaveis globais
int i_cliente=0;
int i_funcionario=0;
int i_estadia=0;

/*Structs Cliente; Funcionario; Estadia; Quarto*/
typedef struct 
{
   int codigo;
   char nome[100];
   char endereco[1000];
   char telefone[20];
} Cliente;

typedef struct 
{
   int codigo;
   char nome[100];
   char telefone[20];
   char cargo[100];
   double salario;
} Funcionario;


typedef struct 
{
   int codigo;
   char data_entrada[11] ;
   char data_saida[11];
   int quantidade_diarias;
   int codigo_cliente;
   int numero_quarto;
} Estadia;

typedef struct 
{
   int numero;
   int quantidade_hospedes;
   double valor_diaria;
   bool status; //true= ocupado, false=desocupado
} Quarto;

/*Funcoes*/

//funcao1= cadastro de cliente
void cadastro_cliente (Cliente cliente[N], char* nome, char* endereco, char* telefone){
//geracao de codigo de 0 a N e teste se e chave unica
   cliente[i_cliente].codigo=rand()%N+1;
   for (int j=0; j<i_cliente; j++){
      if(cliente[i_cliente].codigo==cliente[j].codigo){
         j=0;
         cliente[i_cliente].codigo=rand()%N+1;
      }
   }
  
   strcpy (cliente[i_cliente].nome, nome);
   strcpy (cliente[i_cliente].endereco, endereco);
   strcpy (cliente[i_cliente].telefone, telefone);
   i_cliente++; 
   system("pause");  
}

//funcao2= cadastro funcionario
void cadastro_funcionario (Funcionario funcionario[N], char* nome, char* telefone, char* cargo, double salario){
    //geracao de codigo de 0 a N e teste se e chave unica
   funcionario[i_funcionario].codigo=rand()%N+1;
   for (int j=0; j<i_funcionario; j++){
      if(funcionario[i_funcionario].codigo==funcionario[j].codigo){
         j=0;
         funcionario[i_funcionario].codigo=rand()%N+1;
      }
   }
  
   strcpy (funcionario[i_funcionario].nome, nome);
   strcpy (funcionario[i_funcionario].telefone, telefone);   
   strcpy (funcionario[i_funcionario].cargo, cargo);
   funcionario[i_funcionario].salario= salario;
   i_funcionario++;
   system("pause");
}
//funcao3= inicializa quartos e estadia

void quarto_construtor(Quarto quarto[N]){
   for (int i=0; i<N; i++){
      quarto[i].numero=i;
      quarto[i].quantidade_hospedes=rand()%((MAX_H - MIN_H) + 1) + MIN_H;
      quarto[i].valor_diaria=quarto[i].quantidade_hospedes*125.50;
      quarto[i].status=false;
   
   }
}

//funcao4 = acha diferenca entre valores de data de entrada e saida
int diarias (int d_e, int d_s, int m_e, int m_s, int a_e, int a_s){
   int diaria;
   int i=0;
   int mes[] ={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   //mesmo ano
   if(a_e==a_s){
   //mesmo mes
      if(m_e==m_s){
         diaria=d_s-d_e;
      }
      //meses diferentes
      else{
         diaria= mes[m_e]-d_e+d_s;
         //mais de um mes de diferenca
         if(m_s-m_e>1){
            for(i=m_e+1; i<m_s; i++){
               diaria=diaria+mes[i];
            }
         }
      }
   }
   //anos diferentes
   else{
      diaria=mes[m_e]-d_e+d_s;
      for(i=m_e+1; i<mes[12]; i++){
         diaria=diaria+mes[i];
      }
      for(i=1; i<m_s; i++){
         diaria=diaria+mes[i];
      }
   }
   return diaria;
}

//funcao5 = cadastro de estadia
void cadastro_estadia(char*nome_cliente, int quantidade_hospedes, char* data_entrada, char* data_saida, int diaria,  Quarto quarto[N], Estadia estadia[N], Cliente cliente[N]){
   //achar um quarto
   int i=0;
   int j=0;
   bool achouquarto=false;//para saber se achou o quarto
   for (i=0; i<N; i++){
      if(quarto[i].quantidade_hospedes==quantidade_hospedes && quarto[i].status==false){
        
         quarto[i].status=true;
         estadia[i_estadia].numero_quarto=quarto[i].numero;
         achouquarto=true;
         j=i;
         i=N;
      }
   
   }
   //testar se achou quarto
   if(achouquarto==true){
   //achar codigo cliente
      for(i=0; i<N; i++){
         if(strcmp(cliente[i].nome, nome_cliente)==0){
            estadia[i_estadia].codigo_cliente=cliente[i].codigo;
            i=N;
         }
      }
      estadia[i_estadia].codigo=i_estadia;
      strcpy (estadia[i_estadia].data_entrada, data_entrada);
      strcpy (estadia[i_estadia].data_saida, data_saida);
      estadia[i_estadia].quantidade_diarias=diaria;
   
   
      i_estadia++;
   }
   else{
      printf("\nNao foi possivel cadastrar estadia, nao ha quartos disponiveis");
   }
   system("pause");
}

//funcao 6- dar baixa na estadia

void dar_baixa(int codigo_estadia, Quarto quarto[N], Estadia estadia[N]){
   int i=estadia[codigo_estadia].numero_quarto;
   double total=quarto[i].valor_diaria*estadia[codigo_estadia].quantidade_diarias;
   quarto[i].status=false;
   printf("\nValor total a ser pago=%.2lf", total);

   system("pause");
}

//funcao7- pesquisa cliente

void pesquisa_cliente (char *nome, Cliente cliente[N]){
   int i=0;
   bool achou_cliente=false;
   if(i_cliente==0){
      printf("\nERRO: Nao ha clientes cadastrados");
   }
   else{
      for (i=0; i<i_cliente; i++){
         if(strcmp(cliente[i].nome, nome)==0){
            printf("\nNome do cliente= %s \nCodigo= %d\n \nEndereco=%s \nTelefone=%s", cliente[i].nome, cliente[i].codigo, cliente[i].endereco, cliente[i].telefone);
            achou_cliente=true;
            i=i_cliente;
         }
      }
      if(achou_cliente==false){
         printf("\n Nao foi encontrado cliente com o nome %s", nome);
      }
   }
   system("pause");
}

//funcao8- pesquisa funcionario

void pesquisa_funcionario (char *nome, Funcionario funcionario[N]){
   int i=0;
   bool achou_funcionario=false;

   if(i_funcionario==0){
      printf("\nERRO: Nao ha funcionarios cadastrados");
   }
   else{
      for (i=0; i<i_funcionario; i++){
         if(strcmp(funcionario[i].nome, nome)==0){
            printf("\nNome do funcionario= %s \nCodigo= %d\n \nTelefone=%s \nCargo=%s \nSalario=%lf", funcionario[i].nome, funcionario[i].codigo,  funcionario[i].telefone, funcionario[i].cargo, funcionario[i].salario);
            achou_funcionario=true;
            i=i_funcionario;
         }
      }
      if(achou_funcionario==false){
         printf("\n Nao foi encontrado funcionario com o nome %s", nome);
      }
   }
   system("pause");
}

//funcao 9 - quantidade estadias do cliente

void estadias_cliente(char*nome, Cliente cliente[N], Estadia estadia[N]){
   int i=0;
   bool achou_cliente=false;
   int codigo_cliente;
   //achar codigo do cliente
   for(i=0; i<i_cliente; i++){
      if(strcmp(cliente[i].nome, nome)==0){
         codigo_cliente= cliente[i].codigo;
         achou_cliente=true;
         i=i_cliente;
      }
   }
   printf("\n Estadias do cliente %s ", nome);
   bool achou_estadia=false;
   if(achou_cliente==true){
      for(i=0; i<i_estadia; i++){
         if(codigo_cliente==estadia[i].codigo_cliente){
            achou_estadia=true;
            printf("\n\nCodigo da estadia:%d \nData de entrada:%s \nData de saida:%s \nQuatidade de diarias:%d \nNumero do quarto:%d", estadia[i].codigo, estadia[i].data_entrada, estadia[i].data_saida,estadia[i].quantidade_diarias,estadia[i].numero_quarto);
         }
      }
      if(achou_estadia==false){
         printf("\nNao ha estadias para o cliente %s", nome);
      }
   }
   else{
      printf("\nCliente nao cadastrado");
   }
   system("pause");
   
}


//funcao 10 - pontos de fidelidade do cliente

void fidelidade(char*nome, Cliente cliente[N], Estadia estadia[N]){
   int i=0;
   bool achou_cliente=false;
   int codigo_cliente;
   //achar codigo do cliente
   for(i=0; i<i_cliente; i++){
      if(strcmp(cliente[i].nome, nome)==0){
         codigo_cliente= cliente[i].codigo;
         achou_cliente=true;
         i=i_cliente;
      }
   }
   printf("\n Pontos de fidelidade do cliente %s ", nome);
   bool achou_estadia=false;
   int numero_diarias=0;
   if(achou_cliente==true){
      for(i=0; i<i_estadia; i++){
         if(codigo_cliente==estadia[i].codigo_cliente){
            achou_estadia=true;
            numero_diarias=numero_diarias+estadia[i].quantidade_diarias;
         }
      }
      if(achou_estadia==false){
         printf("\nNao ha estadias para o cliente %s", nome);
      }
   }
   else{
      printf("\nCliente nao cadastrado");
   }
   printf("\n Pontos de fidelidade do cliente= %d", numero_diarias*10);
   system("pause");
   
}

//funcao 11- escrever arquivo

void escrever_arquivo (Cliente cliente[N], Funcionario funcionario[N], Estadia estadia[N], Quarto quarto[N]){
   FILE*arquivo1=fopen("clientes.txt", "wt");
   int i=0;
   fprintf(arquivo1,"Clientes:\n");
   if(i_cliente!=0){
      for(i=0; i<i_cliente; i++){
         fprintf(arquivo1,"codigo= %d\n",cliente[i].codigo);
         fprintf(arquivo1,"nome= %s",cliente[i].nome);
         fprintf(arquivo1,"endereco= %s",cliente[i].endereco);
         fprintf(arquivo1,"telefone= %s",cliente[i].telefone);
         fprintf(arquivo1,"\n");
      }
   }
   fclose(arquivo1);
   
   FILE*arquivo2=fopen("funcionarios.txt", "wt");
   
   fprintf(arquivo2,"Funcionarios:\n");
   if(i_funcionario!=0){
      for(i=0; i<i_funcionario; i++){
         fprintf(arquivo2,"codigo= %d\n",funcionario[i].codigo);
         fprintf(arquivo2,"nome= %s",funcionario[i].nome);
         fprintf(arquivo2,"telefone= %s",funcionario[i].telefone);
         fprintf(arquivo2,"cargo= %s",funcionario[i].cargo);
         fprintf(arquivo2,"salario= R$%.2lf\n",funcionario[i].salario);
         fprintf(arquivo2,"\n");
      }
   }
   fclose(arquivo2);
   
   FILE*arquivo3=fopen("estadias.txt", "wt");
   
   fprintf(arquivo3,"Estadias:\n");
   if(i_estadia!=0){
      for(i=0; i<i_estadia; i++){
         fprintf(arquivo3,"codigo= %d\n",estadia[i].codigo);
         fprintf(arquivo3,"data entrada= %s\n",estadia[i].data_entrada);
         fprintf(arquivo3,"data saida= %s\n",estadia[i].data_saida);
         fprintf(arquivo3,"quantidade de diarias= %d\n",estadia[i].quantidade_diarias);
         fprintf(arquivo3,"codigo do cliente= %d\n",estadia[i].codigo_cliente);
         fprintf(arquivo3,"numero do quarto= %d\n",estadia[i].numero_quarto);
         fprintf(arquivo3,"\n");
      }
   }
   fclose(arquivo3);
   
   FILE*arquivo4=fopen("quartosocupados.txt", "wt");
   
   fprintf(arquivo4,"Quartos ocupados:\n");
   
   for(i=0; i<N; i++){
      if(quarto[i].status==true){
         fprintf(arquivo4,"numero= %d\n",quarto[i].numero);
         fprintf(arquivo4,"quantidade de hospedes= %d\n",quarto[i].quantidade_hospedes);
         fprintf(arquivo4,"valor da diaria= %.2lf\n",quarto[i].valor_diaria);
         fprintf(arquivo4,"\n");
      
      }
   }
   
   fclose(arquivo4);
   system("pause");
}

//funcao 12- ler arquivo

void ler_arquivo (char *arq){
   FILE*arquivo=fopen(arq,"rt");
   if(arquivo==NULL){
      printf("\nERRO de abertura de arquivo\n");
   }
   else{
      char linha[200];
      fgets(linha, 80, arquivo);
      while (!feof(arquivo)){ 
         printf("%s", linha);
         fgets(linha, 80, arquivo);
      }
   }
   fclose(arquivo);
  
}
/*MAIN*/

int main(){
//declaracao de variaveis

   Cliente cliente[N];
   //variaveis cliente
   char *nome = (char *)malloc(100*sizeof(char));
   char *endereco = (char *)malloc(1000*sizeof(char));
   char *telefone = (char *)malloc(20*sizeof(char));
  
   Funcionario funcionario[N];
   //variaveis funcionario
   char* nome_f = (char *)malloc(100*sizeof(char));
   char* telefone_f = (char *)malloc(20*sizeof(char));
   char* cargo_f = (char *)malloc(100*sizeof(char));
   double salario_f=0.0;

   
   Estadia estadia[N];
   //variaveis estadia
   int diaria;
   int d_e, d_s, m_e, m_s, a_e, a_s; //dia, mes e anos de entrada e saida
   int quantidade_hospedes;
   char *nome_cliente = (char *)malloc(100*sizeof(char));
   char* data_entrada= (char *)malloc(11*sizeof(char)) ;
   char* data_saida=(char *)malloc(11*sizeof(char)) ;
   int codigo_estadia;

   
   Quarto quarto[N];
   //construtor
   quarto_construtor(quarto);
   int x;

   do
   {
      printf("\n Menu\n 0-Sair\n 1-Cadastrar cliente\n 2-Cadastrar funcionario\n 3-Cadastrar estadia\n 4-Dar baixa\n 5-Pesquisa cliente\n 6-Pesquisa funcionario\n 7-Pesquisa estadia\n 8-Pontos de fidelidade\n 9-Salvar arquivo\n 10-Ler arquivo\n");
      printf("Digite a opcao: ");
      scanf("%i", &x);
      switch (x)
      {
         case 0:
            printf("Saida com sucesso");
            break;
         case 1:
           
            //input
            printf("\nCadastrar cliente\n");
            printf("\nInserir nome: ");
            fgets(nome, 100, stdin);// passa direto pelo primeiro
            fgets(nome, 100, stdin);
            printf("\nInserir endereco: ");
            fgets(endereco, 1000, stdin);
            printf("\nInserir telefone: ");
            fgets(telefone, 20, stdin);
            
            cadastro_cliente( cliente, nome, endereco, telefone);
            //printf("\nCliente %d:\n codigo: %d \tnome: %s \t endereco: %s \ttelefone: %s",i_cliente-1,cliente[i_cliente-1].codigo, cliente[i_cliente-1].nome, cliente[i_cliente-1].endereco, cliente[i_cliente-1].telefone);
            
            break;
         case 2:
         
             //input
            printf("\nCadastrar funcionario\n");
            printf("\nInserir nome: ");
            fgets(nome_f, 100, stdin);// passa direto pelo primeiro
            fgets(nome_f, 100, stdin);
            printf("\nInserir telefone: ");
            fgets(telefone_f, 20, stdin);
            printf("\nInserir cargo: ");
            fgets(cargo_f, 100, stdin);
            printf("\nInserir salario: ");
            scanf("%lf",&salario_f);
              
            cadastro_funcionario( funcionario, nome_f, telefone_f, cargo_f, salario_f);
            //printf("\nFuncionario %d:\n codigo: %d \tnome: %s \t telefone: %s \tcargo: %s \tsalario: %.2lf",i_funcionario-1,funcionario[i_funcionario-1].codigo, funcionario[i_funcionario-1].nome, funcionario[i_funcionario-1].telefone, funcionario[i_funcionario-1].cargo, funcionario[i_funcionario-1].salario);
            break;
         case 3:
            printf("\nCadastrar estadia\n");
            
            //testar se ha clientes cadastrados
            if(i_cliente==0){
               printf("ERRO: Nao ha clientes cadastrados\n");
            }
            else{
               printf("\nInserir nome do cliente: ");
               fgets(nome_cliente, 100, stdin);// passa direto pelo primeiro
               fgets(nome_cliente, 100, stdin);
               bool cadastrado= false;
               
               //testar se nome do cliente esta cadastrado
               while(cadastrado==false){
                  for(int j=0; j<i_cliente; j++){
                     if(strcmp(cliente[j].nome, nome_cliente)==0){
                        cadastrado=true;
                        j=i_cliente;
                     }
                    
                  }
                   if(cadastrado==false){
                        printf("\nERRO: Nome do cliente nao encontrado, favor repetir a pesquisa:");
                        printf("\nInserir nome do cliente: ");
                        fgets(nome_cliente, 100, stdin);
                     }
               }
               
               
               printf("\nInserir quantidade de hospedes: ");
               scanf("%d", &quantidade_hospedes);
               bool viavel=false;
               //testar se quantidade de hospedes e viavel
               while(viavel==false){
                  if(quantidade_hospedes<=MAX_H && quantidade_hospedes>=MIN_H){
                     viavel=true;
                  }
                  else{
                     printf("\n ERRO: quantidade de hospedes invalida");
                     printf("\nInserir quantidade de hospedes: ");
                     scanf("%d", &quantidade_hospedes);
                  }
               }
               
              
               
               int mes[] ={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
               viavel=false;
               printf("\n Inserir dia de entrada: ");
               scanf("%d", &d_e);
               printf("\n Inserir mes de entrada: ");
               scanf("%d", &m_e);
               printf("\n Inserir ano de entrada: ");
               scanf("%d", &a_e);
               //testar data entrada
               while(viavel==false){
                  if(m_e<=0 || m_e>=12){
                     printf("\nERRO: mes invalido");
                     printf("\n Inserir mes de entrada: ");
                     scanf("%d", &m_e);
                  }
                  else if(d_e<=0 || d_e>mes[m_e]){
                     printf("\nERRO: dia invalido");
                     printf("\n Inserir dia de entrada: ");
                     scanf("%d", &d_e);
                  }
                  else if(a_e<1900 || a_e>3000){
                     printf("\nERRO: ano invalido");
                     printf("\n Inserir ano de entrada: ");
                     scanf("%d", &a_e);
                  }
                  else{
                     viavel=true;
                  }
               }
               
               //testar data saida
               viavel=false;
               printf("\n Inserir dia de saida: ");
               scanf("%d", &d_s);
               printf("\n Inserir mes de saida: ");
               scanf("%d", &m_s);
               printf("\n Inserir ano de saida: ");
               scanf("%d", &a_s);
               while(viavel==false){
                  if(m_s<=0 || m_s>=12){
                     printf("\nERRO: mes invalido");
                     printf("\n Inserir mes de saida: ");
                     scanf("%d", &m_s);
                  }
                  else if(d_s<=0 || d_s>mes[m_s]){
                     printf("\nERRO: dia invalido");
                     printf("\n Inserir dia de saida: ");
                     scanf("%d", &d_s);
                  }
                  else if(a_s<1900 || a_s>3000){
                     printf("\nERRO: ano invalido");
                     printf("\n Inserir ano de saida: ");
                     scanf("%d", &a_s);
                  }
                  else{
                     viavel=true;
                  }
               }
               
                 
               //calcular diaria
               diaria= diarias (d_e, d_s, m_e, m_s, a_e, a_s);
               
               //passar data para string
               char strano1[40];
               char strdia1[40];
               char strmes1[40];
               char strano2[40];
               char strdia2[40];
               char strmes2[40];
               char strcat1[40];
               char strcat2[40];
               
               
               itoa(d_e,strdia1,10);
               itoa(m_e,strmes1,10);
               itoa(a_e,strano1,10);
               
               strcpy(strcat1, strdia1);
               strcat(strcat1, "/");
               strcat(strcat1, strmes1);
               strcat(strcat1, "/");
               strcat(strcat1, strano1);
               
               strcpy(data_entrada, strcat1);
               
               itoa(d_s,strdia2,10);
               itoa(m_s,strmes2,10);
               itoa(a_s,strano2,10);
               
               strcpy(strcat2, strdia2);
               strcat(strcat2, "/");
               strcat(strcat2, strmes2);
               strcat(strcat2, "/");
               strcat(strcat2, strano2);
               
               strcpy(data_saida, strcat2);
              
            
               cadastro_estadia(nome_cliente, quantidade_hospedes, data_entrada, data_saida, diaria,  quarto, estadia, cliente);
            
               
               
            }
            break;
         case 4:
            printf("\n Dar baixa na estadia\n");
            printf("\n inserir codigo da estadia");
            scanf("%d", &codigo_estadia);
            bool viavel=false;
            if(i_estadia==0){
               printf("\nERRO: nao ha estadias cadastradas");
            }
            else {
               while(viavel==false){
               
                  if(codigo_estadia>=i_estadia){
                     printf("ERRO: favor inserir codigo entre 0 e %d", i_estadia-1);
                     printf("\n inserir codigo da estadia");
                     scanf("%d", &codigo_estadia);
                  }
                  else{
                     dar_baixa(codigo_estadia, quarto, estadia);
                     viavel=true;
                  }
               }
            }
           
            
            break;
         case 5:
            printf("\nPesquisa Cliente\n");
            printf("\nInserir nome do cliente a ser pesquisado: ");
            fgets(nome, 100, stdin);// passa direto pelo primeiro
            fgets(nome, 100, stdin);
            pesquisa_cliente(nome, cliente);
         
            break;
         case 6:
            printf("\nPesquisa Funcionario\n");
            printf("\nInserir nome do funcionario a ser pesquisado: ");
            fgets(nome_f, 100, stdin);// passa direto pelo primeiro
            fgets(nome_f, 100, stdin);
            pesquisa_funcionario(nome_f, funcionario);
            break;
         case 7:
         
         //input
            printf("\nVerificar estadias do cliente\n");
            printf("\nInserir nome: ");
            fgets(nome, 100, stdin);// passa direto pelo primeiro
            fgets(nome, 100, stdin);
            
            if(i_cliente==0){
               printf("\nERRO: nao ha clientes cadastrados");
            }
            else if(i_estadia==0){
               printf("\nERRO: nao ha estadias cadastradas");
            }
            else{
               estadias_cliente(nome, cliente, estadia);
            }
         
            break;
         case 8:
            printf("\nVerificar pontos de fidelidade do cliente\n");
            printf("\nInserir nome: ");
            fgets(nome, 100, stdin);// passa direto pelo primeiro
            fgets(nome, 100, stdin);
         
            fidelidade(nome, cliente,estadia);
            break;
       
         case 9:
            escrever_arquivo (cliente, funcionario, estadia , quarto);
            break;
       
         case 10:
            ler_arquivo("clientes.txt");
            ler_arquivo("funcionarios.txt");
            ler_arquivo("estadias.txt");
            ler_arquivo("quartosocupados.txt");
            system("pause");
            break;
       
         default:
            break;
      }
   }
    while (x != 0);
   
   
}
