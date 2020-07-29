# Atividade 03

Link do vídeo da atividade 03 -> https://www.youtube.com/watch?v=HBIT0VgORrw&feature=youtu.be

## Exercício 1

  Para a atividade 3 adotamos a estratégia de colocar variáveis nas matrizes e alterar essas variáveis através de um menu interativo 
  
  
  ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/photos/varivaveis.jpeg)

  
  ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/photos/matrizes.jpeg)
  
  Neste Trabalho foi estabelecido o universo de mão esquerda que é invertido em z para o exercício 1 (escala) basta a apenas modificar os valores em sx, sy e sz da matriz model 

FotoMatrizModel

![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/photos/matrizModel.jpeg)

  Neste exercício foi pedido para que alteramos os eixos x, y e z [1/3, 3/2, 1].
  
  1[](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/photos/Fotomeu1.jpeg)
  
  e obtemos o resultado
  
  ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/photos/ResultadoEscala.jpeg)

## Exercício 2

  Alterando a matriz view na coluna 1 linha 4 fazemos a translação no eixo X em 1.0 como foi pedido no exercício
  
  ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/photos/FotoCodigoex2.jpeg)
  
  ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/photos/FotoCodigoex2b.jpeg)
  
  e obtemos o resultado
  
  ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/photos/FotoResultadoex2.jpeg)
     
  ## Exercício 3
  
  Para o exercício 3 foi pedido que alterasse o valor da variavel 'd' em 1/2, como estamos lidando com a mão esquerda a matriz é transposta e o 'd' troca de lugar com o -1/d, no nosso código 'D' é igual 'd' 'E' é igual -1/D 
  

  ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/photos/
  
  e obtemos o resultado (D está setado como 0.5f).
  
  ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/photos/Ex3resultado.jpeg)
  
  ## Exercício 4
  
  Para este exercício foi pedido o movimento de câmera [-1/10,1/10,1/4] colocando esses valores diretamente na variaveis px, py e pz a variação da câmera é muito pouca e o que nós queremos é a proporção, para isso dividimos a tela em valores flutuantes de [-1, 1] largura(ou altura) + movimento / largura(ou altura) - movimento o que acontece quando é setado nas variáveis.
  

  ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/photos/codex4a.jpeg)
  
  Mantendo a perspectiva do exercício 3
  
  ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/photos/Resultadoex4.jpeg)

  
  ## Exercício 5
  
  Para este exercício criamos um menu interativa onde pergunta se queremos fazer alterações conjuntas ou individuais na escala, translação, perspectiva e na câmera e obtemos resultados variados
  

  ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/photos/exe5.jpeg)

  ![](https://github.com/samfisherholian/introducao-a-computacao-grafica/blob/master/photos/resultado05.jpeg)
 
