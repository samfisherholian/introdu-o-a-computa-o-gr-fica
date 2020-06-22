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
Pixel pixel,P1,P2;


// -=--=-=pontos setados. acende um pixels no meio da tela =-=-=-/
//struct Pixel pixel;//= {250,250};
//struct P1 pixel;
//struct P2 pixel;
//
// >>> Defina aqui as funções que você implementar <<< 
//
// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {

printPixels();
printLines();

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

    fb_ptr[pos(pixel.x, pixel.y)+0] = rgba.red;
    fb_ptr[pos(pixel.x, pixel.y)+1] = rgba.green;
    fb_ptr[pos(pixel.x, pixel.y)+2] = rgba.blue;
    fb_ptr[pos(pixel.x, pixel.y)+3] = rgba.alpha;
 }
}


void printPixels(){

/* pixel da cor vermelha */
pixel.x = 0;
pixel.y = 0;
rgba.red = 255;
rgba.green = 0;
rgba.blue = 0;
rgba.alpha = 255; 
putPixel(pixel, rgba);

/* pixel da cor verde*/
pixel.x = 1;
pixel.y = 1;
rgba.red = 0;
rgba.green = 255;
rgba.blue = 0;
rgba.alpha = 255; 
putPixel(pixel, rgba);

/*píxel da cor azul*/
pixel.x = 2;
pixel.y = 2;
rgba.red = 0;
rgba.green = 0;
rgba.blue = 255;
rgba.alpha = 255; 
putPixel(pixel, rgba);

}

void drawline(Pixel P1,Pixel P2, struct RGBA rgba){
    int a,b,xf;
    int DELTAX = P2.x - P1.x;
    int DELTAY = P2.y - P1.y;
    int d = 2 * DELTAY - DELTAX;
    int d2 = 2 * DELTAY;
    int inc = 2*(DELTAY - DELTAX);

    if(P1.x > P2.x){
      
      a = P2.x;
      b = P2.y;
      xf = P1.x;
      }else
      {
        a = P1.x;
        b = P1.y;
        xf = P2.x;
      }
    putPixel(pixel,rgba);

    while(a < xf)
    {
      a++;
      if(d<0){
      putPixel(pixel,rgba);
      d += d2;
      }else{
        putPixel(pixel,rgba);
        b++;
        d += inc;
      }
      putPixel(pixel,rgba);

    }
}
      
void printLines()

  {
  P1.x = 50;
  P1.y = 450;
  rgba.red = 255;
  rgba.green = 0;
  rgba.blue = 0;
  rgba.alpha = 255;
  P2.x = 400;
  P2.y = 250;
  rgba.red = 255;
  rgba.green = 0;
  rgba.blue = 0;
  rgba.alpha = 255;
  drawline(P1,P2,rgba);
}    
