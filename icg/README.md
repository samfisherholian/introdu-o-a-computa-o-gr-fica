# introducao a computacao grafica

## Ativade Pratica 1: Rastetrização de linhas com algoritmo de Bresenham.

Integrantes: Marcus Vinícius Maracajás.   Matricula: 20180006975
             Tiago Silva da Costa.        Matricula: 20180157030
             
          
O objetivo deste trabalho implementar algoritmos para a rasterização de pontos, linhas e triângulos . As linhas são desenhadas através da rasterização das linhas que compõem suas arestas.

Para este trabalho foi disponibilizado o framework que simula uma tela de 512x512  pixels, pois os sistemas operacionais atualmente não permitem acesso direto a memoria do computador.

## "Put pixel"
![fotopupixel](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/foto1.jpeg)

![fotorgba](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/foto2.jpeg)

Put pixel é o nome da função que demos para acender os pixels na tela do framwork. Cada pixel possui 4 bytes cada bytes armazena as informações das 4 cores (RED, GREEN, BLUE, ALPHA), cada cor possui uma variação de 0 a 255 a cor alpha representa a transparência da cor e na escolha de cada ponto obrigatoriamente escolhemos a cor que vai ser representada. Cada pixel possui 2 coordenadas e ela se move de 4 em 4 bytes.

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/foto3.jpeg)

Determinando isso fizemos a função printpixel onde nela escolhemos os pontos x e y de um ponto qualquer que chamamos de "p1"  e colocamos as coordenadas neste ponto e a cor deste ponto e logo abaixo chamamos a função putpixel(p1, cor1).

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/printpixel.jpeg)

A descoberta da funcionalidade desta função nos deu uma ideia de fazer um desenho em toda a tela. Descobrimos se ao utilizarmos um (forLoop) poderíamos printar pixels como se fossem linhas em toda tela, mas ficava difícil determinar uma angulação destas retas utilizando apenas o putpixel, então, é ai que entra o algoritmo de Bresenham que vai suprir essa necessidade.

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/pixel1.jpeg)

## DrawLine.
Como explicado durante as aulas o algoritmo de Bresenham supri a necessidade de escolher qual pixel correto deve ser acesa na tela ao utilizar a média entre as distância dos pixels, todavia para passar tal algoritmo para linguagem c devemos criar um laço de repetição. Nossa função de implementar tal algoritmo chama-se drawline(desenha linhas) e possui quatro parâmetros os dois pixels 'a' e 'b' cada um com duas coordenadas (X,Y) e duas cores uma para 'a' e outra para 'b'.

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/drawline.jpeg)

Calculamos o delta x (dX) e o delta y (dY) fazemos um teste para ver se os deltas são maiores ou menores do que zero, dependendo do resultado a reta cresce ou decresce nas suas coordenadas.
  
  Incrementamos o valor de 1 se ela crescer e de -1 se ela decrescer em seguida realizamos o teste entre e delta y e delta x se o delta x for maior que o delta y atribuímos o valor de 'M' a delta x e 'm' a delta y caso contrario isso será invertido se invertido fazemos um segundo teste se o delta y for maior do que 0 o y2 que é recebe o valor de 1 e se for menor que 0 -1 ao final de tudo x2 volta com o valor 0 acreditamos que ao atribuir valores de 0 ou 1 as coordenadas tornamos mais simples a atuação final. O pixel já pode ser colocado na tela, mas é preciso criar um laço de repetição para que seja aceso os pixels até atingir a condição final que é o ponto 2 ou seja ele vai acender os pixels de 'a' até 'b', por isso criamos o laço que utiliza uma informação 'N' que foi conseguida através dos testes onde 'N' é igual 'M' dividido por 2  ou seja 'N' recebe o eixo maior. 
  
  ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/deltax.jpeg) ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/deltay.jpeg)

  Nosso "forloop" é: for(int i=0; i <= M ; i++), chamamos a função putpixel logo abaixo do laço, pois atender as condições colocadas abaixo ele sempre vai acender o pixel que vai estar nas coordenas do "Pixel a" até chegar ao "Pixel b" com a cor escolhida. O 'M' recebe o valor de 'N' + 'm' e realiza-se o teste se o 'N' > 'M' então o 'N' = 'N' - 'M' e as coordenadas x e y do ponto 'a' recebem seu próprio valor adicionado ao incremento ou decremento que chamamos de x1 e y1 respectivamente caso contrario <= recebem x2 e y2 respectivamente nas mesmas condições de incremento ou decremento, em seguida se não atender a condição de laço repete-se os passos e a cada passo vai mudar as coordenadas do "Pixel a" acendendo o pixel da nova coordenada 'a'.
  
  ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/Mdeatribui%C3%A7%C3%A3o.jpeg)
  
## Cores Interpoladas.  

   Para interpolar as cores criamos uma condição dentro de drawline chamada int inter'X' onde esse X recebe um número correspondente ao byte de cada cor, o inter recebe o valor da "cor2" menos o valor da "cor1" divido pelo delta x e no laço for a "cor1" que atribuída ao 'Pixel a" por 1 recebe ela mesma mais o valor do inter mudando a cor do pixel seguinte e depois acendendo na tela com putpixel e como está dentro do laço for irá mudar até chegar ao pixel 'b' que recebeu a "cor2".
   
   ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/interpola%C3%A7oes.jpeg)  ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/incrementos.jpeg)

## Drawtriangles.

A função Drawtriangle recebe atribuições de três pontos e suas coordenadas (Pixel A, Pixel B, Pixel c) 

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/DrawTriangles.jpeg)

Nesta função chamamos a função de desenhar linhas "Drawline" três vezes e dentro de "Drawline" fazemos uma combinação dos pontos A,B,C onde o 'A' se liga ao 'B', 'B' ao 'C' e 'C' ao 'A'.

## PrintLines.

  Nesta função chamamos o ponto inicial e o ponto final da linha setamos suas coordenadas e para cada ponto atribuímos as suas cores.
  
![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/PrintLines.jpeg) ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/linhainterpolada.jpeg)
  
   Caso queiramos não interpolar a cor basta apenas ou repetir a "cor1" igual a "cor2" ou na chamada de drawline chamarmos uma das cores. Podemos até brincar com as cores e a linguagem c como na foto abaixo.
   
   ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/linhacorRAndomica.jpeg) ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/linhaFRenetica.jpeg)

Nesta chamada apenas atribuímos a função "rand() % " ilimitado de 0 a 255 irá mudar a cor freneticamente nos 4 bytes de cada ponto.

 
## PrintTriangles.

A ultima função serve para chamar “drawtrinagle” com os três pontos e suas respectivas coordenadas tomando-se cuidado para entender a lógica da ligação dos vértices de um triangulo comum abc como observado na figura, há coincidências nas coordenadas dos pixels p1,p2,p3.

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/PrintTriangles.jpeg) ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/printtriangles.jpeg)

E da mesma forma que utilizamos a linguagem c para mudar freneticamente as cores fizemos isso para criar uma animação de um triangulo que muda freneticamente suas coordenadas.

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/Triangulofrenetico.jpeg)

## Considerações finais.

O algoritmo de Bresenham reduz consideravelmente o custo computacional e nos inspira a criar funções que podem chamar além de triângulos, quaisquer outros desenhos que utilizam linhas retas em sua formação, como hexágonos, octógonos, trapézios etc. Nosso desenho final tem a inspiração na capa do Álbum The Dark Side Of The Moon da banda Pink Floyd.

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/rasteriza%C3%A7%C3%A3o%20de%20linhas.gif)
