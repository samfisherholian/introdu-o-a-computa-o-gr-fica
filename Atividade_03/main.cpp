/*****************************************************************************
 * Este programa é baseado no exemplo "Hello-Triangle" disponível 
 * em 
 *     https://learnopengl.com/Getting-started/Hello-Triangle
 * 
 *     A principal diferença entre este programa e o exemplo acima é que neste
 * os vertex e fragment shaders são carregados a partir de arquivos externos, 
 * ao inves de estarem hard coded no código fonte. 
 *     Isso da mais flexibilidade para se fazerem experimentos com os shaders, 
 * pois nao e necessario se recompilar o programa a cada vez que os shaders forem
 * alterados.
 ****************************************************************************/
#include "main.h"

#define IMAGE_WIDTH 512 // Largura da janela OpenGL em pixels.
#define IMAGE_HEIGHT 512 // Altura da janela OpenGL em pixels.

    float d = 0.0f;// exercicio da translacao, 1 para os valores que o professor pediu, zero para o padrão 
    int g = 0;// exrecicio movimento da camera, 1 para os valores que o professor pediu, zero para o padrão
    int h = 0;// exercicio da perspectiva, 1 para os valores que o professor pediu, zero para o padrão
    int s = 0;
    float D = 0.5f;
    //varivaveis da escala
    float sx = 1.0f,sy = 1.0f,sz = 1.0f;
    //varivaveis da distorcao perspectiva
    float cx, cy, cz;

    //variaveis da posicao da camera
    float px, py, pz;

// Array contendo as coordenadas X,Y e Z de tres vertices (um trianglulo).
float vertices[] = {-0.25f, -0.5f, -0.1f, 0.75f, 0.0f, 0.0f, // red triangle (closer)
                     0.25f,  0.5f, -0.1f, 0.75f, 0.0f, 0.0f,
                     0.75f, -0.5f, -0.1f, 0.75f, 0.0f, 0.0f,
                    -0.75f, -0.5f, -0.4f, 0.0f, 0.0f, 0.75f, // blue triangle (farther)
                    -0.25f,  0.5f, -0.4f, 0.0f, 0.0f, 0.75f,
                     0.25f, -0.5f, -0.4f, 0.0f, 0.0f, 0.75f}; 

char* frag_shader_source = NULL;
char* vertex_shader_source = NULL;
unsigned int shader_program;
unsigned int vbo; // Vertex buffer object ID
unsigned int vao; // Vertex array object ID

//********************************************************************************************************************
// A função LoadShader() é baseada em https://stackoverflow.com/a/174552/6107321
void LoadShader(char* file_name, char** shader_source) {
    long length;
    FILE* f = fopen(file_name, "rb");

    if (f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);

        (*shader_source) = (char*)malloc(length + 1);
        if ((*shader_source)) {
            fread((*shader_source), 1, length, f);
            (*shader_source)[length] = '\0';
        }

        fclose(f);
    } else {
        printf("Could not load the shader file %s\nExiting...", file_name);
        exit(EXIT_FAILURE);
    }
}

//********************************************************************************************************************
void Display(void) {
    // Limpa a tela e o depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Define a posição da Viewport dentro da janela OpenGL
    glViewport(0, 0, IMAGE_WIDTH, IMAGE_HEIGHT);

    // Seleciona o Shader Program a ser utilizado.
    glUseProgram(shader_program);
    
     // h recebe 1  se o g estiver com 1, padrao do exercicio, a camera gira mostrando a perspectiva
     if(g == 1){
         h=1;
         } 

    // Matriz Model ///////////////////////////////////////////////////////////
    // You will have to change the contents of this matrix for the exercises
            float model_array[16] = {sx, 0.0f, 0.0f, 0.0f, 
                                     0.0f, sy, 0.0f, 0.0f, 
                                     0.0f, 0.0f, sz, 0.0f, 
                                     0.0f, 0.0f, 0.0f, 1.0f};
            glm::mat4 model_mat = glm::make_mat4(model_array);


    // Matriz View ////////////////////////////////////////////////////////////
    // You will have to change the contents of this matrix for the exercises
            float view_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                                    0.0f, 1.0f, 0.0f, 0.0f, 
                                    0.0f, 0.0f, 1.0f, 0.0f, 
                                    d, 0.0f, 0.0f, 1.0f}; 

            glm::mat4 view_mat = glm::make_mat4(view_array);
    
    // Matriz cam ////////////////////////////////////////////////////////////
    // You will have to change the contents of this matrix for the exercises
            px = -((1.0f + cx)/(1.0f-cx)),py = ((1.0f + cy)/(1.0f-cy)),pz = -((cz+1.0f)/(cz-1.0f)); 
    
                float cam_array[16] ={  1.0f, 0.0f, 0.0f,  -px*g, 
                                        0.0f, 1.0f, 0.0f,  -py*g, 
                                        0.0f, 0.0f, 1.0f,  -pz*g, 
                                        0.0f, 0.0f, 0.0f, 1.0f};
                glm::mat4 cam_mat = glm::make_mat4(cam_array);
    
                       
    // Matriz Projection //////////////////////////////////////////////////////
    // You will have to change the contents of this matrix for the exercises
            float E = -(1.0f/D);
            float proj_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                                    0.0f, 1.0f, 0.0f, 0.0f, 
                                    0.0f, 0.0f, 1.0f, E*h, 
                                    0.0f, 0.0f, D*h, 1.0f};
            glm::mat4 proj_mat = glm::make_mat4(proj_array);
    
    // Thr NDC is a left handed system, so we flip along the Z axis.
    // IMPORTANT: Do not change the contents of this matrix!!!!!!
    float flip_z_array[16] = {1.0f, 0.0f,  0.0f, 0.0f, 
                              0.0f, 1.0f,  0.0f, 0.0f, 
                              0.0f, 0.0f, -1.0f, 0.0f, 
                              0.0f, 0.0f,  0.0f, 1.0f};
    glm::mat4 flip_z_mat = glm::make_mat4(flip_z_array);

    // Matriz ModelViewProjection /////////////////////////////////////////////
    glm::mat4 model_view_proj_mat = flip_z_mat * proj_mat * view_mat * model_mat * cam_mat;
    
    unsigned int transformLoc;
    GL_CHECK(transformLoc = glGetUniformLocation(shader_program, "transform"));
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(model_view_proj_mat));

    // Ativa o Vertex Array Object selecionado.
    glBindVertexArray(vao);

    // Desenha as tres primeiras primitivias, comecando pela de indice 0.
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glFlush();            //
    glutSwapBuffers();    //
    glutPostRedisplay();  //
}

//********************************************************************************************************************
void ExitProg(void) {
    if (vertex_shader_source) {
        free(vertex_shader_source);
        vertex_shader_source = NULL;
    }

    if (frag_shader_source) {
        free(frag_shader_source);
        frag_shader_source = NULL;
    }

    printf("Exiting...\n");
}

void Exercicio1(){
    printf("=-=-=-=-=-==-=-=-=-=-=-==-=-=-=-=-=\n");
    printf("Exercicio 1: Da escala\n");
    printf("Modifica os valores em X, Y e Z  de acordo com o que foi pedido\n");
    printf("O X = 1/3, o Y = 3/2 e o Z = 1\n");
    printf("para ver os triangulos com a escala do exercicio digite 1, se não digite qualquer numero\n");
    scanf("%i",&s);
         
        if (s == 1){
            sx = 1.0f/3.0f;
            sy = 3.0f/2.0f;
            sz  = 1.0f;//valores pedidos no exercicio
            }
         
            else{
        sx = 1.0f;
        sy = 1.0f;
        sz = 1.0f;
        }
}
void Exercicio2(){
    printf("=-=-=-=-=-==-=-=-=-=-=-==-=-=-=-=-=\n");
    printf("Exercicio 2: Da translacao\n");
    printf("Modifica os valores em X de acordo com o que foi pedido\n");
    printf("O X vai transladar em 1.0f\n");
    printf("para ver os triangulos com a tranlacao do exercicio digite 1, se não digite 0\n");
    scanf("%i",&s);
    if (s == 1){
            d=1.0f;
            }

}
void Exercicio3(){
    printf("=-=-=-=-=-==-=-=-=-=-=-==-=-=-=-=-=\n");
    printf("Exercicio 3: Da perspectiva\n");
    printf("Modifica os valores em D de acordo com o que foi pedido\n");
    printf("O triangulo vai mudar a proporção de um para o outro em 0.5f da escala da da proporcao da tela\n");
    printf("para ver os triangulos com a perspectiva projetada na tela 2d digite 1, se não digite 0\n");
    scanf("%i",&h);

}
void Exercicio4(){
    printf("=-=-=-=-=-==-=-=-=-=-=-==-=-=-=-=-=\n");
    printf("Exercicio 4: Da camera\n");
    printf("Modifica os valores em de giro da camera com a perspectiva do exercicio 3 que foi pedido\n");
    printf("a camera ira se mexer mudando a visao dos triangulos na tela em [-1/10, 1/1O, 1/4]\n");
    printf("para ver a camera girar digite 1, se não digite 0\n");
    scanf("%i",&s);
        
       if (s == 1){ 
            g = 1;
            cx = 1/10;  // valor pedido pelo professor
            cy = -1/10; // valor pedido pelo professor
            cz = 1/4;
       }

}
void Exercicio5(){
    printf("=-=-=-=-=-==-=-=-=-=-=-==-=-=-=-=-=\n");
    printf("Exercicio 5: A mao livre\n");
    printf("Modifica os valores da escala, translacao, perspectiva e giro da camera\n");
    printf("Todos de uma vez ou apenas as escolhidas\n");
    printf("=-=-=-=-=-==-=-=-=-=-=-==-=-=-=-=-=\n\n\n");
    printf("Gostaria de mexer na escala?\n");
    printf("1 = 'sim' e 0 = 'nao");
    printf("[1/0]? \n");
    scanf("%i", &s);
    if(s == 1){

        printf("Digite o valor da escala em X (numero flutuante): \n");
        scanf("%f", &sx);
        printf("Digite o valor da escala em Y (numero flutuante): \n");
        scanf("%f", &sy);
        printf("Digite o valor da escala em Z (numero flutuante): \n");
        scanf("%f", &sz);
        }

    printf("Gostaria de mexer na translacao?\n");
    printf("1 = 'sim' e 0 = 'nao");
    printf("[1/0]? \n");
    scanf("%i", &s);
    if(s == 1){

        printf("Digite o valor da translacao em X (numero flutuante): \n");
        scanf("%f", &d);
        }
    printf("Gostaria de mexer na projecao?\n");
    printf("1 = 'sim' 0 = 'nao\n");
    printf("[1/0]?\n");
    scanf("%i", &s);

    if(s == 1){

        h = 1;
        
        printf("Digite o valor para 'D' (float)\n");
        scanf("%f", &D);

        

    }
    printf("Gostaria de mexer na camera?\n");
    printf("1 = 'sim' 0 = 'nao\n");
    printf("[1/0]?\n");
    scanf("%i", &s);
    if(s == 1){
       
        g = 1;
        D = 0.5f;
                
        printf("Digite o valor da escala em X (numero flutuante): \n");
        scanf("%f", &cx);
        printf("Digite o valor da escala em Y (numero flutuante): \n");
        scanf("%f", &cy);
        printf("Digite o valor da escala em Z (numero flutuante): \n");
        scanf("%f", &cz);
        }

 

}

//********************************************************************************************************************
int main(int argc, char** argv) {

    printf("=-=-=-=-=-==-=-=-=-=-=-==-=-=-=-=-=\n");
    printf("BEM VINDO AO PIPELINE GRAFICO\n");
    printf("digite os valore para os exercicios\n");
    printf("EXERCICIO 01 = 1\n");
    printf("EXERCICIO 02 = 2\n");
    printf("EXERCICIO 03 = 3\n");
    printf("EXERCICIO 04 = 4\n");
    printf("EXERCICIO 05 = 5\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    int _leitura;

    scanf("%i", &_leitura);
    switch (_leitura)
    {
    case 1:
        Exercicio1();
        break;
    case 2:
        Exercicio2();
        break;
    case 3:
        Exercicio3();
        break; 
    case 4:
        Exercicio4();
        break;
    case 5:
        Exercicio5();
    default:
        printf("opcao invalida, tente uma das opcoes disponiveis");
        break;
    }

    // Inicializa a GLUT
    glutInit(&argc, argv);

    // Cria um color buffer onde cada pixel é representado por 4 bytes (RGBA)
    // Cria um depth buffer (para resolver a oclusão)
    // Cria dois color buffers para reduzir o flickering
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

    // Define as dimensões do color buffer (ou a área útil do OpenGL na janela)
    glutInitWindowSize(IMAGE_WIDTH, IMAGE_HEIGHT);

    // Posição do canto superior esquerdo da janela OpenGL em relação a tela do computador.
    glutInitWindowPosition(100, 100);

    // Título da janela
    glutCreateWindow("Modern OpenGL: Assignment 3");

    // Load the OpenGL extensions
    GLenum err = glewInit();
    if (GLEW_OK != err) {
      /* Problem: glewInit failed, something is seriously wrong. */
      fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
      return EXIT_FAILURE; 
    }

    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

    // Carrega o codigo fonte do Vertex shader
    LoadShader("vertex_shader.glsl", &vertex_shader_source);

    printf("%s\n", vertex_shader_source);

    unsigned int vertex_shader;

    // Cria um identificador para o Vertex Shader
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);

    // Vincula o código fonte do Vertex Shader ao seu identificador
    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);

    // Compila dinamicamente (em tempo de execucao) o Vertex Shader
    glCompileShader(vertex_shader);

    // Imprime eventuais mensagens de erro de compilacao do Vertex Shader
    int success;
    char info_log[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", info_log);
    }

    // Carrega o codigo fonte do Fragment shader
    LoadShader("fragment_shader.glsl", &frag_shader_source);

    printf("%s\n", frag_shader_source);

    unsigned int fragment_shader;

    // Cria um identificador para o Fragment Shader
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

    // Vincula o código fonte do Fragment Shader ao seu identificador
    glShaderSource(fragment_shader, 1, &frag_shader_source, NULL);

    // Compila dinamicamente (em tempo de execucao) o Fragment Shader
    glCompileShader(fragment_shader);

    // Imprime eventuais mensagens de erro de compilacao do Fragment Shader
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", info_log);
    }

    // Cria um identificador para um Shader program (vertex + fragment shader)
    shader_program = glCreateProgram();

    // Vincula os Fragment e Vertex Shaders ao Program Shader
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);

    // Linka o Fragment e Vertex Shader para formarem o Program Shader 
    glLinkProgram(shader_program);

    // Imprime eventuais mensagens de erro de linkagem do Program Shader
    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program, 512, NULL, info_log);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n", info_log);
    }

    // Deleta os Fragment e Vertex Shaders, já que eles já foram incorporados 
    // ao Program Shader e não são mais necessários.
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    // Ativa o Vertex Array Object (VAO)
    glBindVertexArray(vao);

    // Cria um novo identificador de buffer 
    glGenBuffers(1, &vbo);

    // Vincula o buffer criado a um Vertex Buffer Object (VBO)
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // Carrega as propriedades (coordenadas + cores) dos vértices no VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Atributo 'posição' do vértice
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Atributo 'cor' do vértice
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Define a cor a ser utilizada para limpar o color buffer a cada novo frame
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);            

    // Habilita o teste de profundidade (oclusão).
    GL_CHECK(glEnable(GL_DEPTH_TEST));

    atexit(ExitProg);          // deifne o callback de saída do programa
    glutDisplayFunc(Display);  // define o callback que renderizará cada frame

    // Framebuffer scan loop.
    glutMainLoop();

    return EXIT_SUCCESS;
}
