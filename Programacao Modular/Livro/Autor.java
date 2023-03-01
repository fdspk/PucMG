public class Autor{
    public String nome;
    private Livro[] livros= new Livro[100];
    private int cont=0;
    private double direitos;
    //construtor

    Autor(){
        this.livros=new Livro [100];
    }

    Autor(String nome){
        this.livros=new Livro [100];
        this.nome=nome;
    }

    public double direitoAutoral(Livro livro){
        double direitoAutoral=0.0;
        for (int i=0; i<livros.length; i++){
            if(livros[i].getTitulo().equals(livro.getTitulo()))
                return livro.direitosAutorais();
            
        }
        return direitoAutoral;
    }

    public void adicionarLivro(Livro livro){
        if (cont<livros.length){           
            this.livros[cont]=livro;
            cont++;
        }
    }

    public double direitosTotais(){
        for (int i=0; i<this.livros.length; i++){
            this.direitos+=direitoAutoral(this.livros[i]);

        }
        return this.direitos;
    }
    
    
}