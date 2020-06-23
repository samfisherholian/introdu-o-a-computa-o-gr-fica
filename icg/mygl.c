/**
 * Autores: Tiago Silva da Costa.
 *          Marcus vinicius.
 * 
 * 
 * **/
#include "mygl.h"

// Um pixel é composto por 4 bytes
struct RGBA
{
    int red;
    int green;
    int blue;
    int alpha;
 
}RGBA;
struct RGBA rgba;// = {255, 0,0, 255};

typedef struct
{
    int x;
    int y;
}Pixel;
Pixel pixel,p1,p2,p3;
//
// >>> Defina aqui as funções que você implementar <<< 
//
// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {

printPixels();
printLines();
printTriagle();
}

int pos(int x, int y){
    int l = ((y*4)*IMAGE_WIDTH); //l é linha, 4 bytes por pixel
    int c = (x*4);               //c é coluna, 4 bytes por pixel
    int position = l + c;
    return position;          
  }

  void putPixel(Pixel pixel, struct RGBA rgba){
//teste para que não sejam pintados pixels indevidos na tela, limitando o desenho a apenas a area //disponível
 if((pixel.x>=0 && pixel.x<IMAGE_HEIGHT) && (pixel.y>=0 && pixel.y<IMAGE_WIDTH)){
    //cores para os pixels
    fb_ptr[pos(pixel.x, pixel.y)+0] = rgba.red;
    fb_ptr[pos(pixel.x, pixel.y)+1] = rgba.green;
    fb_ptr[pos(pixel.x, pixel.y)+2] = rgba.blue;
    fb_ptr[pos(pixel.x, pixel.y)+3] = rgba.alpha;
    //cores para os pixels do ponto 1 de uma reta
    fb_ptr[pos(p1.x, p1.y)+0] = rgba.red;
    fb_ptr[pos(p1.x, p1.y)+1] = rgba.green;
    fb_ptr[pos(p1.x, p1.y)+2] = rgba.blue;
    fb_ptr[pos(p1.x, p1.y)+3] = rgba.alpha;
    //cores para os pixels do ponto 2 de uma reta
    fb_ptr[pos(p2.x, p2.y)+0] = rgba.red;
    fb_ptr[pos(p2.x, p2.y)+1] = rgba.green;
    fb_ptr[pos(p2.x, p2.y)+2] = rgba.blue;
    fb_ptr[pos(p2.x, p2.y)+3] = rgba.alpha;
    //cores para os pixels do ponto 3 de uma reta
    fb_ptr[pos(p3.x, p3.y)+0] = rgba.red;
    fb_ptr[pos(p3.x, p3.y)+1] = rgba.green;
    fb_ptr[pos(p3.x, p3.y)+2] = rgba.blue;
    fb_ptr[pos(p3.x, p3.y)+3] = rgba.alpha;
 }
}

//Abaixo esta a funcao de acender pixels na tela com uma determinada
// cor num lugar determinado
void printPixels()
  {
    /* pixel da cor vermelha na posição coluna 1 e linha 100*/
    pixel.x = 1;
    pixel.y = 100;
    rgba.red = 255;
    rgba.green = 0;
    rgba.blue = 0;
    rgba.alpha = 255; 
    putPixel(pixel, rgba); //chamada da funcao void putpixel

    /* pixel da cor verde na coluna 300 e linha 10*/
    pixel.x = 300;
    pixel.y = 10;
    rgba.red = 0;
    rgba.green = 255;
    rgba.blue = 0;
    rgba.alpha = 255; 
    putPixel(pixel, rgba);

    /*píxel da cor azul na coluna 250 e na linha 150*/
    pixel.x = 250;
    pixel.y = 150;
    rgba.red = 0;
    rgba.green = 0;
    rgba.blue = 255;
    rgba.alpha = 255; 
    putPixel(pixel, rgba);

    //Afim de formar um desenho podemos colocar pixels onde quisermos
    for(int px = 0;px <= 512;px+=+8){
      for(int py = 452;py <= 512; py +=4){
        if (px == 512){
        px == 0;
        }
    pixel.x = px;
    pixel.y = py;
    rgba.red = 191;
    rgba.green = 187;
    rgba.blue = 63;
    rgba.alpha = 255; 
    putPixel(pixel, rgba);
      }
    }
    for(int px = 5;px <= 512;px=px+8){
      for(int py = 455;py <= 512; py = py+4){
        if (px == 512){
        px == 5;
        }
    pixel.x = px;
    pixel.y = py;
    rgba.red = 255;
    rgba.green = 255;
    rgba.blue = 255;
    rgba.alpha = 255; 
    putPixel(pixel, rgba);
      }
    }
  }
   

//funcao de desenhar uma linha
void drawline(Pixel p1, Pixel p2, struct RGBA rgba){
    Pixel A = p1, B = p2;
    int dX = B.x - A.x;  //delta X = x2 - x(incicial);
    int dY = B.y - A.y;  //delta Y = y2 - y(inicial);
    //armazenamento dos eixos
    int eixoMaior, eixoMenor;   
    int incrementoX0 = 0, incrementoY0 = 0, incrementoX1 = 0, incrementoY1 = 0, numerador;

    //testes para analisar se os eixos estão crescendo ou decrescendo de acordo com o delta
    if (dX > 0){            
        incrementoX0 = incrementoX1 = 1;
    }

    if (dX < 0){     
        incrementoX0 = incrementoX1 = -1;
    }

    if (dY > 0){              
        incrementoY0 = 1;
    }
    if (dY < 0){     
        incrementoY0 = -1 ;
    }

    if (abs(dX) >= abs(dY)){     
        eixoMaior = abs(dX);
        eixoMenor = abs(dY);
    }else {
        eixoMaior = abs(dY);
        eixoMenor = abs(dX);

         if(dY > 0){         
            incrementoY1 = 1;
        }

        if (dY < 0){    
            incrementoY1 = -1;
        } 
        incrementoX1 = 0;
    }
    numerador = eixoMaior/2;
    for (int i = 0; i <= eixoMaior; i++){
        putPixel(A, rgba);
        numerador += eixoMenor;

        if (numerador > eixoMaior){
            numerador -= eixoMaior;
            A.x += incrementoX0;
            A.y += incrementoY0;

        }else {

            A.x += incrementoX1;
            A.y += incrementoY1;
         }
    } 

}

void printLines(){

  //desenha uma linha vermelha
  p1.x = 175;
  p1.y = 375;
  rgba.red = 255;
  rgba.green = 0;
  rgba.blue = 0;
  rgba.alpha = 255;

  p2.x = 250;
  p2.y = 425;
  rgba.red = 255;
  rgba.green = 0;
  rgba.blue = 0;
  rgba.alpha = 255;
  drawline(p1,p2,rgba);
  //desenha uma linha verde
  p1.x = 425;
  p1.y = 375;
  rgba.red = 0;
  rgba.green = 255;
  rgba.blue = 0;
  rgba.alpha = 255;

  p2.x = 350;
  p2.y = 425;
  rgba.red = 0;
  rgba.green = 255;
  rgba.blue = 0;
  rgba.alpha = 255;
  drawline(p1,p2,rgba);

  //desenha uma linha azul
  p1.x = 200;
  p1.y = 315;
  rgba.red = 0;
  rgba.green = 0;
  rgba.blue = 255;
  rgba.alpha = 255;

  p2.x = 275;
  p2.y = 375;
  rgba.red = 0;
  rgba.green = 0;
  rgba.blue = 255;
  rgba.alpha = 255;
  drawline(p1,p2,rgba);
  
  
  //desenha uma linha rosa
  p1.x = 325;
  p1.y = 375;
  rgba.red = 242;
  rgba.green = 126;
  rgba.blue = 211;
  rgba.alpha = 255;

  p2.x = 425;
  p2.y = 315;
  rgba.red = 242;
  rgba.green = 126;
  rgba.blue = 211;
  rgba.alpha = 255;
  drawline(p1,p2,rgba);
//desenha uma linha colorida frenética :D
  
  p1.x = 300;
  p1.y = 190;
  rgba.red = rand() % 255;
  rgba.green = rand() % 255;
  rgba.blue = rand() % 255;
  rgba.alpha = 255;

  p2.x = 300;
  p2.y = 330;
  rgba.red = rand() % 255;
  rgba.green = rand() % 255;
  rgba.blue = rand() % 255;
  rgba.alpha = 255;
  drawline(p1,p2,rgba);

  
//desenhar uma linha representando o chão do egito
  p1.x = 0;
  p1.y = 452;
  rgba.red = 204;
  rgba.green = 108;
  rgba.blue = 40;
  rgba.alpha = 255;

  p2.x = 512;
  p2.y = 452;
  rgba.red = 204;
  rgba.green = 108;
  rgba.blue = 40;
  rgba.alpha = 255;
  drawline(p1,p2,rgba);
  
  
}      
void drawTriagle(Pixel p1, Pixel p2, Pixel p3)
{
  drawline(p1,p2,rgba);
  drawline(p2,p3,rgba);
  drawline(p1,p3,rgba);
} 

void printTriagle(){
  //desenha um triangulo piscante
  p1.x = 250;
  p1.y = 450;
  rgba.red = rand() % 255;
  rgba.green = rand() % 255;
  rgba.blue = rand() % 255;
  rgba.alpha = 255;

  p2.x = 300;
  p2.y = 350;
  rgba.red = rand() % 255;
  rgba.green = rand() % 255;
  rgba.blue = rand() % 255;
  rgba.alpha = 255;

  p3.x = 350;
  p3.y = 450;
  rgba.red = rand() % 255;
  rgba.green = rand() % 255;
  rgba.blue = rand() % 255;
  rgba.alpha = 255;

  drawTriagle(p1,p2,p3);
  //desenha um triangulo com animação randomica de todos os pontos
  int p1x,p1y,p2x,p2y,p3x,p3y;
  p1x = 275 +(rand() % 10);
  p1y = 430 -(rand()% 10);
  p2x = 325;
  p2y = 420 + (rand() % 10);
  p3x = 305 -(rand() % 10);
  p3y = 410 -(rand() % 10);
    
  p1.x = p1x;
  p1.y = p1y;
  rgba.red = rand() % 255;
  rgba.green = rand() % 255;
  rgba.blue = rand() % 255;
  rgba.alpha = rand() % 255;
  
  p2.x = p2x;
  p2.y = p2y;
  rgba.red = rand() % 255;
  rgba.green = rand() % 255;
  rgba.blue = rand() % 255;
  rgba.alpha = rand() % 255;
 
  p3.x = p3x;
  p3.y = p3y;
  rgba.red = rand() % 255;
  rgba.green = rand() % 255;
  rgba.blue = rand() % 255;
  rgba.alpha = rand() % 255;

  drawTriagle(p1,p2,p3);
  
}    
