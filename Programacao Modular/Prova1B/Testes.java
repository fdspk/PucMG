import static org.junit.Assert.assertEquals;
import org.junit.Test;
import org.junit.jupiter.api.BeforeAll;

public class Testes {
    JogoFisico jf=new JogoFisico("Snake", 2022, 100.0, 0, false);
    Cliente cliente = new Cliente();
    
    @BeforeAll
    public void inicializar() {
        cliente.setNome("Fulano");
        cliente.incluirJogo(jf);
    }    

    @Test
    public void testePrecoVendaDefault(){
        assertEquals(0.0, jf.precoVenda(), 0.1);
    }

    @Test
    public void testePrecoVendaVariandoQuantidadeDiscos(){
        jf.setQuantDiscos(-1);
        assertEquals(0.0, jf.precoVenda(), 0.1);
        jf.setQuantDiscos(0);
        assertEquals(0.0, jf.precoVenda(), 0.1);
        jf.setQuantDiscos(1);
        assertEquals(155.25, jf.precoVenda(), 0.1);
        jf.setQuantDiscos(5);
        assertEquals(236.25, jf.precoVenda(), 0.1);
    }
   
    @Test
    public void testePrecoVendaVariandoIsEspecial(){

        jf.setQuantDiscos(1);
        jf.setIsEspecial(false);
        assertEquals(155.25, jf.precoVenda(), 0.1);
        jf.setIsEspecial(true);
        assertEquals(170.775, jf.precoVenda(), 0.1);

        jf.setQuantDiscos(5);
        jf.setIsEspecial(false);
        assertEquals(236.25, jf.precoVenda(), 0.1);
        jf.setIsEspecial(true);
        assertEquals(259.875, jf.precoVenda(), 0.1);
    }

    @Test
    public void testePrecoVendaVariandoPrecoBase(){

        jf.setQuantDiscos(1);
        jf.setIsEspecial(false);
        jf.setPrecoBase(-100.0);
        assertEquals(155.25, jf.precoVenda(), 0.1);
        jf.setPrecoBase(150.0);
        assertEquals(222.75, jf.precoVenda(), 0.1);
        
    }

    @Test
    public void testePrecoVendaVariandoAnoLancamento(){
        jf.setAnoLancamento(2020);
        jf.setQuantDiscos(1);
        jf.setIsEspecial(false);
        assertEquals(124.2, jf.precoVenda(), 0.1);
       /*Classe jogo, linha 26, favor ler comentario -> formula errada, faltou parentesis - em vez de tirar 20%, tirou 0.2*/
       //correcao:this.getPrecoBase()*((1+MARGEM_LUCRO) - this.descontoTempo())
    }

    @Test
    public void testeCompraDescontoCliente(){
        jf.setQuantDiscos(1);
        jf.setIsEspecial(false);
        jf.setAnoLancamento(2020);
        assertEquals(0.0, cliente.getProxDesconto(), 0.1);
        cliente.incluirJogo(jf);
        assertEquals(0.0, cliente.getProxDesconto(), 0.1);
        cliente.incluirJogo(jf);
        assertEquals(0.0, cliente.getProxDesconto(), 0.1);
        cliente.incluirJogo(jf);
        assertEquals(0.0, cliente.getProxDesconto(), 0.1);
        cliente.incluirJogo(jf);
        assertEquals(0.0, cliente.getProxDesconto(), 0.1);
        cliente.incluirJogo(jf);
        assertEquals(31.05, cliente.getProxDesconto(), 0.1);
        cliente.incluirJogo(jf);
        assertEquals(0.0, cliente.getProxDesconto(), 0.1);
    }
}
