public class CursoLivre extends Turma{

    public static final char LETRA='L';
    public static final boolean CERTIFICADO =true;

    private int quantMateriais;

    CursoLivre(){
        super();
    }
    
    @Override
    public void geraCodigo(){
        this.codigo=(Integer.toString(this.getNivel()*100+this.getDiaSemana()*10+this.getNivel())+LETRA);
    }


    public int getQuantMateriais() {
        return this.quantMateriais;
    }

    public void setQuantMateriais(int quantMateriais) {
        this.quantMateriais = quantMateriais;
    }

    @Override
    public void geraRelatorio(){
        Aluno [] relatorio= this.getOrdemAlfabetica();
        for(int i=0; i<this.getCont(); i++){
            System.out.println(relatorio[i].getNome());
            System.out.println(relatorio[i].isAprovado());
        }
    }

}
