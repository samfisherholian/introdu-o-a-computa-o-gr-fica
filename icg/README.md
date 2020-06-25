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

A descoberta da funcionalidade desta função nos deu uma ideia de fazer um desenho em toda a tela. Descobrimos se ao ultilizarmos um (forLoop) poderiamos printar pixels como se fossem linhas em toda tela mais ficava difícil determina uma angulção destas retas utilizando apenas o putpixel e ai que entra o algoritmo de bresenham que vai suprir essa necessidade.

FOTOPIXEL

## DrawLine.
