/**
 * Autores: Tiago Silva da Costa.
 *          Marcus vinicius.
 * 
 * 
 * **/
#include "mygl.h"

// Um pixel é composto por 4 bytes
typedef struct
{
    int x;
    int y;
}Pixel;
Pixel p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12;
typedef struct
{
    int red;
    int green;
    int blue;
    int alpha;
 
}RGBA;
RGBA cor1,cor2, corpixel;
float inter1;
float inter2;
float inter3;
float inter4;
//
// >>> Defina aqui as funções que você implementar <<< 
//
// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {

printPixels();
printLines();
printTriagle();
}
void putPixel(Pixel p, RGBA cor){
    if((p.x>=0 && p.x<IMAGE_HEIGHT) && (p.y>=0 && p.y<IMAGE_WIDTH)){
    //cores para os pixels
    fb_ptr[p.x*4 +p.y*4*IMAGE_WIDTH+0] = cor.red;
    fb_ptr[p.x*4 +p.y*4*IMAGE_WIDTH+1] = cor.green;
    fb_ptr[p.x*4 +p.y*4*IMAGE_WIDTH+2] = cor.blue;
    fb_ptr[p.x*4 +p.y*4*IMAGE_WIDTH+3] = cor.alpha;
    }
}
//Abaixo esta a funcao de acender pixels na tela com uma determinada
// cor num lugar determinado
void printPixels()
  {
    // pixel da cor vermelha na posição coluna 1 e linha 100
    p1.x = 1;
    p1.y = 100;
    corpixel.red = 255;
    corpixel.green = 0;
    corpixel.blue = 0;
    corpixel.alpha = 255; 
    putPixel(p1,corpixel); //chamada da funcao void putpixel

    // pixel da cor verde na coluna 300 e linha 10
    p2.x = 300;
    p2.y = 10;
    corpixel.red = 0;
    corpixel.green = 255;
    corpixel.blue = 0;
    corpixel.alpha = 255; 
    putPixel(p2,corpixel);

    //píxel da cor azul na coluna 250 e na linha 150
    p3.x = 250;
    p3.y = 150;
    corpixel.red = 0;
    corpixel.green = 0;
    corpixel.blue = 255;
    corpixel.alpha = 255; 
    putPixel(p3,corpixel);

    //Afim de formar um desenho podemos colocar pixels onde quisermos
    for(int px = 0;px <= 512;px=px+8){
      for(int py = 452;py <= 512; py = py+4){
        if (px == 512){
        px == 0;
        }
    p4.x = px;
    p4.y = py;
    corpixel.red = 191;
    corpixel.green = 187;
    corpixel.blue = 63;
    corpixel.alpha = 255; 
    putPixel(p4,corpixel);
      }
    }
    for(int px = 5;px <= 512;px=px+8){
      for(int py = 455;py <= 512; py = py+4){
        if (px == 512){
        px == 5;
        }
    p5.x = px;
    p5.y = py;
    corpixel.red = 255;
    corpixel.green = 255;
    corpixel.blue = 255;
    corpixel.alpha = 255; 
    putPixel(p5,corpixel);
      }
    }
  }
   

//funcao de desenhar uma linha
void drawline(Pixel a, Pixel b, RGBA cor1, RGBA cor2){
    Pixel A = a, B = b;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0; //incrementos
    int dX = B.x - A.x;  //delta X = x2 - x(incicial);
    int dY = B.y - A.y;  //delta Y = y2 - y(inicial);
    int M, m;   
    int N;
    //testes para analisar se os eixos estão crescendo ou decrescendo de acordo com o delta
    if (dX > 0){            
        x1++;
        x2++;
    }
    if (dX < 0){     
        x1--;
        x2--;
    }
    if (dY > 0){              
        y1++;
    }
    if (dY < 0){     
        y1--;
    }

    if (abs(dX) >= abs(dY)){     
        M = abs(dX);
        m = abs(dY);
    }else {
        M = abs(dY);
        m = abs(dX);

         if(dY > 0){         
            y2 = 1;
        }

        if (dY < 0){    
            y2 = -1;
        } 
        x2 = 0;
    }
    N = M/2;
    inter1 = ((cor2.red) - (cor1.red)) / dX;
    inter2 = ((cor2.blue) - (cor1.blue)) / dX;
    inter3 = ((cor2.green) - (cor1.green)) / dX;
    inter4 = ((cor2.alpha) - (cor1.alpha)) / dX;

    for (int i = 0; i <= M; i++){
        putPixel(A,cor1);
        cor1.red += inter1;
        cor1.blue += inter2;
        cor1.green += inter3;
        cor1.alpha += inter4;
       
        N += m;

        if (N > M){
            N -= M;
            A.x += x1;
            A.y += y1;
           //aqui tem a primeira mudança de cor do primeiro ponto   
           //se o ponto p1 for menor que o p2
        }else {

            A.x += x2;
            A.y += y2;
           //aqui tem a primeira mudança de cor do primeiro ponto
           //se o ponto p2 for menor que o p1  
         }
    } 

}
void printLines(){
  
  
  //desenha uma linha vermelha
  p1.x = 0;
  p1.y = 0;
  p2.x = 250;
  p2.y = 250;
  
  cor1.red = 255;
  cor1.green = 0;
  cor1.blue = 0;
  cor1.alpha = 255;

  cor2.red = 0;
  cor2.green = 255;
  cor2.blue = 0;
  cor2.alpha = 255;
  drawline(p1,p2,cor1,cor2);
  //desenha uma linha verde
  p3.x = 425;
  p3.y = 375;
  cor1.red = 0;
  cor1.green = 255;
  cor1.blue = 0;
  cor1.alpha = 255;

  p4.x = 350;
  p4.y = 425;
  cor2.red = 0;
  cor2.green = 255;
  cor2.blue = 0;
  cor2.alpha = 255;
  drawline(p3,p4,cor1,cor2);

  //desenha uma linha azul
  p5.x = 200;
  p5.y = 315;
  p6.x = 275;
  p6.y = 375;
  
  cor1.red = 0;
  cor1.green = 0;
  cor1.blue = 255;
  cor1.alpha = 255;

  cor2.red = 0;
  cor2.green = 0;
  cor2.blue = 255;
  cor2.alpha = 255;
  drawline(p5,p6,cor1,cor2);
  
  
  //desenha uma linha rosa
  p7.x = 325;
  p7.y = 375;
  p8.x = 425;
  p8.y = 315;

  cor1.red = 242;
  cor1.green = 126;
  cor1.blue = 211;
  cor1.alpha = 255;

  cor2.red = 242;
  cor2.green = 126;
  cor2.blue = 211;
  cor2.alpha = 255;
  drawline(p7,p8,cor1,cor2);
//desenha uma linha colorida frenética :D
  
 /* p9.x = 300;
  p9.y = 190;
  p10.x = 300;
  p10.y = 330;
  
  cor1.red = rand() % 255;
  cor1.green = rand() % 255;
  cor1.blue = rand() % 255;
  cor1.alpha = 255;

  cor2.red = rand() % 255;
  cor2.green = rand() % 255;
  cor2.blue = rand() % 255;
  cor2.alpha = 255;
  drawline(p9,p10,cor1,cor2);*/

  
//desenhar uma linha representando o chão do egito
p1.x = 250;
  p1.y = 450;
  p2.x = 300;
  p2.y = 350;
  p3.x = 350;
  p3.y = 450;
  
  cor1.red = 255;
  cor1.green = 0;
  cor1.blue = 0;
  cor1.alpha = 255;
  
  cor2.red = 0;
  cor2.green = 0;
  cor2.blue = 255;
  cor2.alpha = 255;

  

  drawTriagle(p1,p2,p3);
}      
void drawTriagle(Pixel A, Pixel B, Pixel C)
{
  drawline(A,B,cor1,cor2);
  drawline(B,C,cor1,cor2);
  drawline(A,C,cor1,cor2);
} 

void printTriagle(){
  //desenha um triangulo piscante
  p1.x = 250;
  p1.y = 450;
  p2.x = 300;
  p2.y = 350;
  p3.x = 350;
  p3.y = 450;
  
  cor1.red = 255;
  cor1.green = 255;
  cor1.blue = 0;
  cor1.alpha = 255;
  
  cor1.red = 255;
  cor1.green = 255;
  cor1.blue = 0;
  cor1.alpha = 255;

  

  drawTriagle(p1,p2,p3);
  //desenha um triangulo com animação randomica de todos os pontos
  int p1x,p1y,p2x,p2y,p3x,p3y;
  p1x = 275 +(rand() % 10);
  p1y = 430 -(rand()% 10);
  p2x = 325;
  p2y = 420 + (rand() % 10);
  p3x = 305 -(rand() % 10);
  p3y = 410 -(rand() % 10);
    
  p4.x = p1x;
  p4.y = p1y;
  p5.x = p2x;
  p5.y = p2y;
  p6.x = p3x;
  p6.y = p3y;
  
  cor1.red = rand() % 255;
  cor1.green = rand() % 255;
  cor1.blue = rand() % 255;
  cor1.alpha = rand() % 255;
  
  cor2.red = 0;
  cor2.green = 5;
  cor2.blue = 255;
  cor2.alpha = 255;
  drawTriagle(p4,p5,p6);

}


