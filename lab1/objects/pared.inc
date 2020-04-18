#version 3.7
#include "textures.inc"  
// Values of the wall. They are defined to fit the scene 
#declare ancho_pared = 80;  
#declare alto_pared = 130;
#declare profundidad_pared = 50;
// Wall
#declare wall =
    box { 
        <-ancho_pared, 0,profundidad_pared>, <ancho_pared, alto_pared, profundidad_pared + 0.01>  
        texture{ pigment {color rgb<0.85,0.85,0.85>}} 
                 finish{
                 diffuse 1.05}      
    }