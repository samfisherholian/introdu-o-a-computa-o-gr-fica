
Autores: Marcus Vinicius Maracaja Pires M: 20180006975 && Tiago Silva da Costa M: 20180157030
# Atividade 04

Na atividade 4 aplicamos o que foi sugerido pelo professor e criamos variáveis para que ficasse mais fácil de compreender o código.
Explicaremos brevemente:

Na linha 21 adicionamos:

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/coeficiente_refletancian_difusa.png)

 que não era presente no código e é essencial para os cálculos.

## Exercício 1

Implementação do Modelo de Reflexão Difuso

Utilizando-se das fórmulas concedidas no trabalho pelo professor

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/vetor_L_N.png)

Onde L é: o vetor que vai da superfície até o ponto de luz, ponto de luz (menos) superfície.

O N é: O vetor normal do plano da superfície.

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/formula.png)

E o “normalize” é a função retorna um vetor com comprimento 1.0  que é paralelo a x, ou seja, x dividido por seu comprimento. O parâmetro de entrada pode ser escalar flutuante ou um vetor flutuante. No caso de um escalar flutuante, a função de normalização é trivial e retorna 1.0.

Adotamos para o exercício as variáveis:

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/produto_escalar.png)

“dot” é a função que faz o cálculo do escalar entre os vetores N e L.

A fórmula da reflexão difusa é: 

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/FormulaDnovo.png)

com:

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/valores.png)

E os valores que foram pedidos pelo professor.

E o cosseno de teta é o vetor L x vetor N, ou seja o produto escalar entre esses dois vetores.

Lembrando que S é a variável que representa o Cosseno de teta:

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/produto_escalar.png)

E a  fórmula ficou:

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/exercicio01.png)

E ao rodar o código obtemos o resultado:

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/chalerinhaDifusa.png)
  
## Exercício 2

Implementação do Modelo de Reflexão Especular.

Modificar o vertex Shader de forma que ele passe a incluir, além do modelo de iluminação ambiente e difuso, também o modelo especular, ou de Phong. Para isto, será necessário calcular o vetor R, de reflexão da luz L, e o vetor da câmera V, que aponta do vértice em questão para a câmera. Abaixo seguem as sugestões de cálculo destes dois vetores:

Utilizando-se das fórmulas concedidas no trabalho pelo professor

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/vetor_R_S.png)
 
Onde R é: Um vetor oposto ao vetor do ponto de luz no espaço, se transformando no reflexo dele, ambos tocando a superfície do objeto.

Onde V é: O vetor que vai da superfície do objeto até o ponto de visão e que forma um angulo alfa com o R (posição da câmera - superfície).

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/outraFormula.png)


O “reflect” presente em R é a função retorna um vetor que aponta na direção de reflexão. A função tem dois parâmetros de entrada do tipo escalar flutuante ou vetor flutuante: L, o vetor incidente, e N, o vetor normal da superfície refletora.

Ele faz exatamente:

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/umaOutraFormula.png)

Adotamos para esse exercício as variáveis:

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/maisumaformula.png)


A variável r, deveria ser “pow(l, n)” que é o cosseno alfa elevado a n, n controla o tamanho do brilho especular e no exercicio n = 64.0f, mas ao fazer isto, a figura não funciona, então como alternativa, multiplicamos o “l” 64 vezes, e assim deu certo. Além da falta de familiaridade com as funções da linguagem glsl , esta foi a principal dificuldade do trabalho, o pow não funcionar.

A fórmula da Reflexão Especular com o modelo Phong é:
  
![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/Otaformula.png)

Com:

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/valores.png)

Que foram os valores pedidos pelo professor;

a posição da câmera esta saindo da tela no sistema de mão direita:

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/posicaodacamera.png)

E a formula final na linguagem glsl e no nosso código ficou:

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/Formulaglsl.png)

Obtendo como resultado:

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/Atividade_04/04_shading/fotos_04/chalerinhaFinal.png)



