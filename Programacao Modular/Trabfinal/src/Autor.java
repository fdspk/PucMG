import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class Autor {
    public String nome;
    private List<Livro> livros;

    public double direitoAutoral (Livro livro){
        return (livro.direitosAutorais());
    }

    /* 
    public double totalEmDireitos(){
        double soma=0.0;
        for(int i=0; i<livros.size(); i++){
            soma+=livros.get(i).direitosAutorais();
        }
        return soma;
    }
    */

    public double totalEmDireitos(){
        return (livros.stream()
                    .mapToDouble(this::direitoAutoral)
                    .sum());
    }

    public void ordenacaoDecrescente(){
        List<Integer> livrosDesc = 
				livros.stream()
					.sorted(Comparator.reverseOrder())
					.collect(Collectors.toList());
        System.out.println("Ordem descrescente"+ livrosDesc);
    }

    public void adicionarLivro(Livro livro){
        try{
            if(livro.getTituloLivro().equals(livros.stream().filter(l -> l.getTituloLivro().equals(livro.getTituloLivro())))){
                throw new MaisDeUmLivroDuasVezesException();
                
            } 
            else{
                livros.add(livro);
            } 

        }
        catch (MaisDeUmLivroDuasVezesException e){
            System.out.println(e.getMessage());
        }
    }
}
