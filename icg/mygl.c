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
Pixel pixel,p1,p2;
//
// >>> Defina aqui as funções que você implementar <<< 
//
// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {

printPixels();
printLines();
//printTriagle();
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
    //cores para os pixels do ponto 1 da reta
    fb_ptr[pos(p1.x, p1.y)+0] = rgba.red;
    fb_ptr[pos(p1.x, p1.y)+1] = rgba.green;
    fb_ptr[pos(p1.x, p1.y)+2] = rgba.blue;
    fb_ptr[pos(p1.x, p1.y)+3] = rgba.alpha;
    //cores para os pixels do ponto 2 da reta
    fb_ptr[pos(p2.x, p2.y)+0] = rgba.red;
    fb_ptr[pos(p2.x, p2.y)+1] = rgba.green;
    fb_ptr[pos(p2.x, p2.y)+2] = rgba.blue;
    fb_ptr[pos(p2.x, p2.y)+3] = rgba.alpha;
 }
}
//Funcao de acender pixels na tela com uma determinada cor
void printPixels(){

/* pixel da cor vermelha */
pixel.x = 10;
pixel.y = 100;
rgba.red = 255;
rgba.green = 0;
rgba.blue = 0;
rgba.alpha = 255; 
putPixel(pixel, rgba);

/* pixel da cor verde*/
pixel.x = 30;
pixel.y = 30;
rgba.red = 0;
rgba.green = 255;
rgba.blue = 0;
rgba.alpha = 255; 
putPixel(pixel, rgba);

/*píxel da cor azul*/
pixel.x = 250;
pixel.y = 150;
rgba.red = 0;
rgba.green = 0;
rgba.blue = 255;
rgba.alpha = 255; 
putPixel(pixel, rgba);
}

//funcao de desenhar uma linha
void drawline(Pixel p1, Pixel p2){
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
  p1.x = 50;
  p1.y = 450;
  rgba.red = 255;
  rgba.green = 0;
  rgba.blue = 0;
  rgba.alpha = 255;

  p2.x = 400;
  p2.y = 250;
  rgba.red = 255;
  rgba.green = 0;
  rgba.blue = 0;
  rgba.alpha = 255;
  drawline(p1,p2);

  //desenha uma linha azul
  p1.x = 500;
  p1.y = 45;
  rgba.red = 0;
  rgba.green = 0;
  rgba.blue = 255;
  rgba.alpha = 255;

  p2.x = 100;
  p2.y = 350;
  rgba.red = 0;
  rgba.green = 0;
  rgba.blue = 255;
  rgba.alpha = 255;
  drawline(p1,p2);
  
  
  //desenha uma linha rosa
  p1.x = 510;
  p1.y = 510;
  rgba.red = 242;
  rgba.green = 126;
  rgba.blue = 211;
  rgba.alpha = 255;

  p2.x = 210;
  p2.y = 104;
  rgba.red = 242;
  rgba.green = 126;
  rgba.blue = 211;
  rgba.alpha = 255;
  drawline(p1,p2);
//desenha uma linha colorida frenética :D
  
  p1.x = 0;
  p1.y = 0;
  rgba.red = rand() % 255;
  rgba.green = rand() % 255;
  rgba.blue = rand() % 255;
  rgba.alpha = 255;

  p2.x = 200;
  p2.y = 512;
  rgba.red = rand() % 255;
  rgba.green = rand() % 255;
  rgba.blue = rand() % 255;
  rgba.alpha = 255;
  drawline(p1,p2);
  
  
}