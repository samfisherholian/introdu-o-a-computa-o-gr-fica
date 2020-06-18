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
    int alpha
    
};


struct RGBA rgba = {255, 0,0, 255};

struct Pixel
{
    int x;
    int y;
     
};
// -=--=-=pontos setados. acende um pixels no meio da tela =-=-=-/
struct Pixel pixel = {250,250};


//
// >>> Defina aqui as funções que você implementar <<< 
//
// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {

putPixel(pixel, rgba);


 }

int pos(int x, int y){
    int l = ((y*4)*IMAGE_WIDTH); //l é linha, 4 bytes por pixel
    int c = (x*4);               //c é coluna, 4 bytes por pixel
    int position = l + c;
    return position;          
  }
  void putPixel(struct Pixel pixel, struct RGBA rgba){

//teste para que não sejam pintados pixels indevidos na tela, limitando o desenho a apenas a area //disponível



 if((pixel.x>=0 && pixel.x<IMAGE_HEIGHT) && (pixel.y>=0 && pixel.y<IMAGE_WIDTH)){


    fb_ptr[pos(pixel.x, pixel.y)+0] = rgba.red;

    fb_ptr[pos(pixel.x, pixel.y)+1] = rgba.green;

    fb_ptr[pos(pixel.x, pixel.y)+2] = rgba.blue;

    fb_ptr[pos(pixel.x, pixel.y)+3] = rgba.alpha;

  } 

}