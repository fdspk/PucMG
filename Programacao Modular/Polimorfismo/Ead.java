public class Ead extends TurmaNotas {
    private final static char LETRA='E';

    private int quantMateriais;

    Ead(){
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

  

}
