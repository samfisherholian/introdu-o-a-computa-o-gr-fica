#include "mygl.h"

//
// >>> Defina aqui as funções que você implementar <<< 
//
void PutPixel();
// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {

    //
    // >>> Chame aqui as funções que você implementou <<<
    //
    PutPixel();
    DrawLine();
}

void PutPixel(){
    
    // Escreve um pixel vermelho na posicao (0,0) da tela:
 // Escreve um pixel vermelho na posicao (0,0) da tela:
 for(int i = 5120;i<7168;++i){
 fb_ptr[16*i+128*i] = 222; // componente R
 fb_ptr[16*i+128*i] = 152; // componente G
 fb_ptr[16*i+128*i] = 031; // componente B
 fb_ptr[16*i+128*i] = 255; // componente A
    }
}

void DrawLine(){

    for(int i = 0; i <= 262144; i++){
            if(i <= 200000 && i >= 190000){
                fb_ptr[i*4+0] = 227; // componente R
                fb_ptr[i*4+1] = 224; // componente G
                fb_ptr[i*4+2] = 27; // componente B
                fb_ptr[i*4+3] = 255;
            }
        }
}


    /*
    for(int i = 0; i <= 262144; i++){
        if(i >= 200000){
            fb_ptr[i*4+0*] = 227; // componente R
            fb_ptr[i*4+1] = 224; // componente G
            fb_ptr[i*4+2] = 27; // componente B
            fb_ptr[i*4+3] = 255;
        }
    }
    */   

  
