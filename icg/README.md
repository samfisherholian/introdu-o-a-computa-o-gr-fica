# introducao a computacao grafica

## Ativade Pratica 1: Rastetrização de linhas com algoritmo de Bresenham.

Integrantes: Marcus Vinícius Maracajás. Matricula: 20180006975
             Tiago Silva da Costa.      Matricula: 20180157030
             
          
O objetivo deste trabalho implementar algoritmos para a rasterização de pontos, linhas e triangulos. As linhas são desenhadas através da rasterização das linhas que compõem suas arestas.

Para este trabalho foi disponiblizado o framework que simula uma tela de 512x512 pixels, pois os sitemas operacionais atualmente não permitem acesso direto a memoria do computador.

## "put pixel"
![fotopupixel](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/icg/foto1.jpeg)

FOTO2

Put pixel é o nome da função que demos para acender os pixels na tela do framwork. Cada pixel poussi 4 bytes cada bytes armazena as informações das 4 cores (RED, GREEN, BLUE, ALPHA), cada cor possui uma variação de 0 a 255 a cor alpha representa a transparencia da cor e na escolha de cada ponto obrigatoriamente escolhemos a cor que vai ser representada. Cada pixel possui 2 cordenadas e ela se move de 4 em 4 bytes.

FOTOS3

Determinando isso fizemos a função prinpixel onde nela escolhemos os pontos x e y de um ponto qualquer que chamamos de "p1"  e colocamos as coordenadas neste ponto e a cor deste ponto e logo abaixo chamamos a função putpixel(p1, cor1).

FOT0 PRINTPIXEL

A descoberta da funcionalidade desta função nos deu uma ideia de fazer um desenho em toda a tela. Descobrimos se ao ultilizarmos um (forLoop) poderiamos printar pixels como se fossem linhas em toda tela, mas ficava difícil determinar uma angulção destas retas utilizando apenas o putpixel, então, é ai que entra o algoritmo de Bresenham que vai suprir essa necessidade.

FOTOPIXEL

## DrawLine.
Como explicado durante as aulas o algoritmo de Bresenham supri a necessidade de escolher qual pixel correto deve ser acesa na tela ao ultilizar a média entre as distância dos pixels, todavia para passar tal algoritmo para linguagem c devemos criar um laço de repetição para a reptição do algoritmo. Nossa função de implementar tal algoritmo chama-se drawline(desenha linhas) e possui quatro parâmetros os dois pixels 'a' e 'b' cada um com duas coordenadas (X,Y) e duas cores uma para 'a' e outra para 'b'.

FOTO DRAwLINE

Calculamos o deltax e o deltay fazemos um teste para ver se os deltas são maiores ou menores do que zero, dependendo do resultado a reta cresce ou decresce nas suas coordenadas.
  
  Incrementamos o valor de 1 se ela crescer e de -1 se ela decrescer em seguida realizamos o teste entre e deltay e deltax se o deltax for maior que o deltay atribuimos o valor de 'M' a deltax e 'm' a deltay caso contrario isso será invertido se invertido fazemos um segundo teste se o deltay for maior do que 0 o y2 que é recebe o valor de 1 e se for menor que 0 -1 ao final de tudo x2 volta com o valor 0 acreditamos que ao atribuir valores de 0 ou 1 as coordenadas tornamos mais simples a atuação final. O pixel já pode ser colocado na tela, mas é preciso criar um laço de repetição para que seja aceso os pixels até atingir a condição final que é o ponto 2 ou seja ele vai acender os pixels de 'a' até 'b', por isso criamos o laço que ultiliza uma informação 'N' que foi consequida através dos testes onde 'N' é igual 'M' dividido por 2  ou seja 'N' recebe o eixo maior. 
  
  FOTOumado lado da outra

  Nosso "forloop" é: for(int i=0; i <= M ; i++), chamamos a função putpixel logo abaixo do laço, pois atender as condições colocadas abaixo ele sempre vai acender o pixel que vai estar nas coordenas do "Pixel a" até chegar ao "Pixel b" com a cor escolhida. O 'M' recebe o valor de 'N' + 'm' e realiza-se o teste se o 'N' > 'M' então o 'N' = 'N' - 'M' e as coordenadas x e y do ponto 'a' recebem seu proprio valor adicionado ao incremento ou decremento que chamamos de x1 e y1 respectivamente caso contrario <= recebem x2 e y2 respectivamente nas mesmas condições de incremento ou decremento, em seguida se não atender a condição de laço repete-se os passos e a cada passo vai mudar as coordenadas do "Pixel a" acendendo o pixel da nova coordenada 'a'.
  
## cores interboladas.  

   Para interpolar as cores criamos uma condição dentro de drawline chamada int inter'X' onde esse X recebe um número correspondente ao byte de cada cor, o inter recebe o valor da "cor2" menos o valor da "cor1" divido pelo deltax e no laço for a "cor1" que atribuiada ao 'Pixel a" por 1 recebe ela mesma mais o valor do inter mudando a cor do pixel seguinte e depois acendendo na tela com putpixel e como está dentro do laço for irar mudar até chegar ao pixel 'b' que recebeu a "cor2".
   
   FOTOinterpoldas

## Drawtriangles.

A função Drawtriangle recebe atribuição de três pontos e suas coordenadas (Pixel A, Pixel B, Pixel c) FOTO 

Nesta função chamamos a função de desenhar linhas "Drawline" três vezes e dentro de "Drawline" fazemos uma combinação dos pontos A,B,C onde o 'A' se liga ao 'B', 'B' ao 'C' e 'C' ao 'A'.

## printLines

   
   
   
