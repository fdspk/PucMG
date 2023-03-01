public class CadastrarMaisDeUmException extends Exception {
    
    public CadastrarMaisDeUmException(){
        super("Ja existe cadastro de avaliacao para este livro por este cliente");
    }
}
