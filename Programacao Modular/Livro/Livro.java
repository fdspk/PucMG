public abstract class Livro {
    private static final double PCT_DIREITOS = 0.08;
    protected String titulo;
    protected Autor autor;
    protected int paginas;
    protected double precoBase;
    protected int copiasVendidas;   

    // construtores
    Livro(String titulo, String nomeAutor) {
        this.titulo = titulo;
        this.autor=new Autor();
        this.autor.nome = nomeAutor;
    }

    public double direitosAutorais() {
        return this.getPrecoBase() * Livro.PCT_DIREITOS*this.copiasVendidas;
    }

    public double precoVenda() {
        return this.getPrecoBase()+this.direitosAutorais()/this.copiasVendidas;
    }

    public void vender(int numCopias) {
        this.copiasVendidas+=numCopias;
    }
    // getters e setters
    public String getTitulo() {
        return this.titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo=titulo;
    }
    public double getPrecoBase(){
        return this.precoBase;
    }
    
    public int getVendas(){
        return this.copiasVendidas;
    }

    //metodo abstrato    
    public abstract void setPrecoBase(double precoBase);
}
