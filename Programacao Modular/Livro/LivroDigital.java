public class LivroDigital extends Livro{
//construtor

    public LivroDigital(String titulo, String nomeAutor, double precoBase) {
        super(titulo, nomeAutor);
        this.setPrecoBase(precoBase);
    }

//metodos
    @Override
    public void setPrecoBase(double precoBase) {
        this.precoBase = precoBase;
    }

    public void imprimir(){
        System.out.println(this.titulo+" "+this.autor.nome+" "+this.precoBase+" "+this.precoVenda()+ " "+this.copiasVendidas);
    }
}
