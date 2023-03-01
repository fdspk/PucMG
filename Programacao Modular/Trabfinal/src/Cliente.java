import java.util.List;

public class Cliente {
    public String nome;
    private List<Avaliacao> avaliacoes;

    public Avaliacao avaliarLivro (Livro livro, int nota){
        Avaliacao aval= new Avaliacao(livro, nota);
        try{
            if(livro.getTituloLivro().equals(avaliacoes.stream().filter(l -> l.getLivros().equals(livro.getTituloLivro())))){
                throw new CadastrarMaisDeUmException();
                
            } 
            else{
                avaliacoes.add(aval);
            }  
        }
        catch(CadastrarMaisDeUmException e){
            System.out.println(e.getMessage());
        }
        return aval;
    }
}
