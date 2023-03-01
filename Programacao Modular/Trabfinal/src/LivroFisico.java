public class LivroFisico implements IProduto {
    private static final double ADIC_PAGINA=0.03;
    private double valorEncadernacao;


    public double precoVenda(double precoBase){
        return (precoBase+ livro.getPaginas()*ADIC_PAGINA+this.valorEncadernacao);
    }
}
