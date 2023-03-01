import java.util.*;
import java.io.*;

public class App {
   public static void main(String[] args) {
      BufferedReader br = null;
      String linha;
      String ler;
      int x = 0;
   
      LivroFisico LF[] = new LivroFisico[30];
      int i = 0;
      LivroDigital LD[] = new LivroDigital[30];
      int j = 0;
      Autor autores[] = new Autor[30];
      int k = 0;
      for (int a = 0; a < 30; a++) {
         autores[a] = new Autor(); // inicializar vetor de livros
      }
        
      Scanner sc = new Scanner(System.in);
      try {
         br = new BufferedReader(new FileReader("LIVROS_PM.TXT"));
      
         while ((linha = br.readLine()) != null) {
               
            String[] separado = linha.split(";");
            if (separado[3].equals("F")) {
               LF[i] = new LivroFisico(separado[1], separado[2], Integer.parseInt(separado[7]),
                            Double.parseDouble(separado[4]), Double.parseDouble(separado[5]));
               LF[i].copiasVendidas = Integer.parseInt(separado[6]);
               i++;
               autores[k]=new Autor(separado[2]);
               autores[k].adicionarLivro(LF[i]);
               
               k++;
            } else if (separado[3].equals("D")) {
                    
               LD[j] = new LivroDigital(separado[1], separado[2], Double.parseDouble(separado[4]));
                    
               LD[j].copiasVendidas = Integer.parseInt(separado[5]);
               j++;
               autores[k]=new Autor(separado[2]);
               autores[k].adicionarLivro(LD[j]);
               
               k++;
            }
         
         }
      } catch (IOException e) {
         e.printStackTrace();
      }
      
      
      BufferedReader in = null;
        
      try{
         in = new BufferedReader(new InputStreamReader(System.in));
         
         while (x!=3){
            System.out.println("Menu: 0- localizar livro; 1- localizar autor; 2- comprar; 3-sair");
            x=sc.nextInt();
         switch (x) {
            
            case 0:
               System.out.println("localizar livro:");
               ler=in.readLine();
               for (int n = 0; n < 30; n++) {
                if(LF[n]!=null){
                  if (LF[n].getTitulo().contains(ler)) {
                     LF[n].imprimir();;
                  } else if (LD[n]!=null && LD[n].getTitulo().contains(ler)) {
                     LD[n].imprimir();;
                  }
                }
               }
               break;
            case 1:
               System.out.println("localizar autor:");
               ler = in.readLine();
               for (int n = 0; n < 30; n++) {
                if(autores[n]!=null){
                  if (autores[n].nome.contains(ler)) {
                     System.out.println("Autor encontrado");
                     break;
                  }
                }
               }
               break;
            case 2:
               System.out.println("comprar:");
               ler = in.readLine();
               for (int n = 0; n < 30; n++) {
                  if (LF[n]!=null && LF[n].getTitulo().contains(ler)) {
                     LF[n].vender(1);
                     LF[n].imprimir();
                  }
                  else if (LD[n]!=null && LD[n].getTitulo().contains(ler)) {
                     LD[n].vender(1);
                     LD[n].imprimir();
                  }
               }
               break;
         }
        }
      }catch(IOException e){
      }
      sc.close();
   
   }
        
}

