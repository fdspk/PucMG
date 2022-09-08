
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

/*
 * Plano de testes:
a) Registrar a data de aquisição do veículo; - data deve ser válida - classe data OK
b) Registrar o consumo do veículo em quilômetros por litro;- dado informado - OK
        valor positivo -ok
        valor negativo - ok
c) Saber a quilometragem total do veículo; - dado informado - oK
        valor positivo -ok
        valor negativo -ok
d) Calcular a quilometragem média por rota realizada do veículo; 
    d.1)Inserir quantidade de rotas
        valor positivo -ok
        valor negativo -ok
        valor superior a 3 -ok
    d.2)Inserir valores de quilometragem 
        valor positivo -ok
        valor negativo -ok
        valor a mais -ok
    d.3)Tirar media
        primeira rota -ok
        segunda rota -ok
        terceira rota -ok
        rota invalida -ok
e) A partir de um preço de combustível definido, calcular o gasto total do veículo com abastecimento.
    e.1)Somar media das rotas em d.3
    e.2)Calcular com base em e.1 e b
 */

 public class VeiculoTest{

    public static Veiculo veiculo1;
    @BeforeEach
    public void init(){
        veiculo1= new Veiculo();
    }

    @Test
    public void TesteDataConstrutor(){
        assertEquals("01/01/2000", veiculo1.getData());
    }
    @Test
    public void dataCorreta(){
        veiculo1.setData(4,9,2022);
        assertEquals("04/09/2022", veiculo1.getData());
    }
    @Test
    public void dataIncorreta(){
        veiculo1.setData(34,9,2022);
        assertEquals("01/01/1900", veiculo1.getData());
    }
    @Test
    public void TesteQuilometroPorLitroInvalido(){
            veiculo1.setQuilometrosPorLitro(-10.7);
            assertEquals(0.0, veiculo1.getQuilometrosPorLitro());
    }
    @Test
    public void TesteQuilometroPorLitroValido(){
            veiculo1.setQuilometrosPorLitro(3.4);
            assertEquals(3.4, veiculo1.getQuilometrosPorLitro());
    }

    @Test
    public void TesteQuilometragemTotalInvalido(){
            veiculo1.setKmTotal(-10.7);
            assertEquals(0.0, veiculo1.getKmTotal());
    }
    @Test
    public void TesteQuilometragemTotalValido(){
            veiculo1.setKmTotal(3.4);
            assertEquals(3.4, veiculo1.getKmTotal());
    }
    @Test
    public void TesteQuantidadeRotasValida(){
            veiculo1.setQuantidadeRotas(3);
            assertEquals(3, veiculo1.getQuantidadeRotas());
    }

    @Test
    public void TesteQuantidadeRotasInValida1(){
            veiculo1.setQuantidadeRotas(4);
            assertEquals(0, veiculo1.getQuantidadeRotas());
    }
    @Test
    public void TesteQuantidadeRotasInValida2(){
            veiculo1.setQuantidadeRotas(-1);
            assertEquals(0, veiculo1.getQuantidadeRotas());
    }
    @Test
    public void TesteInsereValorInvalido(){
            veiculo1.setValores(-1);
            assertEquals("0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 ", veiculo1.getValores());
    }

    @Test
    public void TesteInsereValorValido(){
            veiculo1.setQuantidadeRotas(1);// setar quantidade de rotas
            veiculo1.setValores(8.1);
            veiculo1.setValores(9.0);
            veiculo1.setValores(10.3);
            veiculo1.setValores(10);// valor a mais nao vai entrar
            assertEquals("8.1 9.0 10.3 0.0 0.0 0.0 0.0 0.0 0.0 ", veiculo1.getValores());
    }

    @Test
    public void TesteMediaValida1(){
            veiculo1.setQuantidadeRotas(1);// setar quantidade de rotas
            veiculo1.setValores(9.1);
            veiculo1.setValores(9.0);
            veiculo1.setValores(9.2);
            assertEquals(9.1, veiculo1.media(1));
    }

    @Test
    public void TesteMediaValida2(){
            veiculo1.setQuantidadeRotas(2);// setar quantidade de rotas
            veiculo1.setValores(1);
            veiculo1.setValores(1);
            veiculo1.setValores(1);//primeira rota
            veiculo1.setValores(9.1);//segunda rota
            veiculo1.setValores(9.0);
            veiculo1.setValores(9.2);
            assertEquals(9.1, veiculo1.media(2));
    }

    @Test
    public void TesteMediaValida3(){
            veiculo1.setQuantidadeRotas(3);// setar quantidade de rotas
            veiculo1.setValores(1);//primeira
            veiculo1.setValores(1);
            veiculo1.setValores(1);
            veiculo1.setValores(9.1);//segunda rota
            veiculo1.setValores(9.0);
            veiculo1.setValores(9.2);
            veiculo1.setValores(3.1);//terceira rota
            veiculo1.setValores(3.0);
            veiculo1.setValores(3.2);
            assertEquals(3.1, veiculo1.media(3));
    }

    @Test
    public void TesteMediaInvalida(){
            veiculo1.setQuantidadeRotas(3);// setar quantidade de rotas
            veiculo1.setValores(1);//primeira
            veiculo1.setValores(1);
            veiculo1.setValores(1);
            veiculo1.setValores(9.1);//segunda rota
            veiculo1.setValores(9.0);
            veiculo1.setValores(9.2);
            veiculo1.setValores(3.1);//terceira rota
            veiculo1.setValores(3.0);
            veiculo1.setValores(3.2);
            assertEquals(0.0, veiculo1.media(7));
    }

    @Test
    public void TesteGastoAbastecimento(){
            veiculo1.setQuilometrosPorLitro(3.0);
            veiculo1.setQuantidadeRotas(3);// setar quantidade de rotas
            veiculo1.setValores(1);//primeira
            veiculo1.setValores(1);
            veiculo1.setValores(1);
            veiculo1.setValores(9.1);//segunda rota
            veiculo1.setValores(9.0);
            veiculo1.setValores(9.2);
            veiculo1.setValores(3.1);//terceira rota
            veiculo1.setValores(3.0);
            veiculo1.setValores(3.2);
            assertEquals(19.2632, veiculo1.gastoAbastecimento());
    }
    
 }