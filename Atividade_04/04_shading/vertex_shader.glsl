#version 330 core

layout (location = 0) in vec3 obj_spc_vertex_pos; 
layout (location = 1) in vec3 obj_spc_N;            
layout (location = 2) in vec3 k_d;                

// matrizes do pipeline
uniform mat4 model_mat; 
uniform mat4 view_mat;  
uniform mat4 proj_mat;  

out vec3 I;  //Variável I: atributo de intensidade (ou cor) a ser calculado para o vértice
 
void main() {
    vec3 cam_pos = vec3(0.0f, 0.0f, 1.5f); //posição da câmera (hard coded) no espaço do Universo
   
    vec3 I_a = vec3(0.2f, 0.2f, 0.2f);      //intensidade da luz ambiente.
    vec3 k_a = vec3(0.0f, 0.0f, 1.0f);	    //coeficiente de reflectância ambiente (κa)
    vec3 k_s = vec3(1.0f, 1.0f, 1.0f);      //coeficiente de reflectância especular (κs)	
    vec3 I_p_pos = vec3(-2.0f, 2.0f, 1.5f); //posição da fonte de luz pontual (hard coded) no espaço do Universo.
    vec3 I_p = vec3(0.8f, 0.8f, 0.8f);      //intensidade da luz pontual
    vec3 k_d = vec3(0.0f, 0.0f, 0.8f);      //coeficiente de reflectância difusa
    

    vec3 L = normalize(I_p_pos - (model_mat * vec4(obj_spc_vertex_pos, 1.0)).xyz);

    vec3 N = normalize(mat3(transpose(inverse(model_mat))) * obj_spc_N);

    vec3 R = -reflect(L, N);

    vec3 V = normalize(cam_pos - (model_mat * vec4(obj_spc_vertex_pos, 1.0)).xyz);
    
    float s = dot(N, L); // produto escalar
    
    float l = dot(R, V);

    float r = l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l*l;

    // a funcao "pow(l,64.0f)" nao funciona!

    //I = I_a * k_a + I_p * k_d * s; // EXERCICIO 1
    
    I = I_a * k_a + I_p * (k_d * s + k_s *  r); // EXERCICIO 2
   
    

    gl_Position = proj_mat * view_mat * model_mat * vec4(obj_spc_vertex_pos, 1.0);  //Atualização da posição do vértice, originalmente no espaço do Objeto, para o espaço de Recorte
}