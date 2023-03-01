public class Avaliacao {
    public static final int MAX_AVAL =5;
    private Cliente cliente;
    private Livro livros;
    private int nota;
    private String comentario;

    public int getNota(){
        return this.nota;
    }

    public Avaliacao (Livro livro, int nota){
        this.livros=livro;
        this.nota=nota;
    }

   public String getLivros(){
    return (this.livros.getTituloLivro());
   }

   public void adicionarAvaliacao(Avaliacao aval){
    try{
        if(aval.getNota()>MAX_AVAL){
            throw new NotaMaiorQueMaximaException();
        }
        else{
            this.nota=aval.getNota();
        }
    }
    catch(NotaMaiorQueMaximaException e){
        System.out.println(e.getMessage());
    }
   }
    
}
