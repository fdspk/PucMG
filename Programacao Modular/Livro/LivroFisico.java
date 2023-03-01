public class LivroFisico extends Livro{
    private static final double ADIC_PAGINA=0.03;
    private double valorEncadernacao;
    private int paginas;

     //construtor
    LivroFisico(String titulo, String nomeAutor, int paginas, double precoBase, double valorEncadernacao){
        super(titulo, nomeAutor);
        this.valorEncadernacao=valorEncadernacao;
        this.paginas=paginas;
        this.setPrecoBase(precoBase);
    }


    //METODOS
    @Override
    public void setPrecoBase(double precoBase) {
        this.precoBase = precoBase+this.precoImpressao()+this.valorEncadernacao;
    }    


    private double precoImpressao(){
        return this.paginas*ADIC_PAGINA;
    }

    public void imprimir(){
        System.out.println(this.titulo+" "+this.autor.nome+" "+this.paginas+" "+this.precoBase+" "+this.valorEncadernacao+" "+this.precoVenda()+ " "+this.copiasVendidas);
    }
    
    
    
}
