import java.util.OptionalDouble;
import java.util.Set;

public class Livro {
    private static final double PCT_DIREITOS=0.08;
    private String titulo;
    private Autor autor;
    private IProduto modalidade;
    private int paginas;
    private double precoBase;
    private int copiasVendidas;
    private Set<Avaliacao> avaliacoes;

    public double precoVenda(){
        return(this.modalidade.precoVenda(this.precoBase)*this.copiasVendidas);
    }

    public double direitosAutorais(){
        return(this.precoBase*PCT_DIREITOS);
    }

    public double avaliacaoMedia(){
        return(this.avaliacoes
        .stream()
        .mapToDouble(Avaliacao::getNota)
        .average()
        .getAsDouble());
    }

    public void cadastrarAvaliacao(Avaliacao avaliacao){
        avaliacoes.add(avaliacao);        
    }

    public int getPaginas(){
        return this.paginas;
    }
    
    public OptionalDouble AvaliacaoMedia(){
        return(avaliacoes
        .stream()
        .mapToDouble(Avaliacao::getNota)
        .average());
    }

    public String getTituloLivro(){
        return(this.titulo);
       }
    

}