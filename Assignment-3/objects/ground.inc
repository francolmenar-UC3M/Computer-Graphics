#version 3.7
#include "textures.inc"
#include "glass.inc"          

// Ground floor for the sceene
#declare ground = 
    plane { <0,1,0>, 0  
        texture { NBglass pigment { color rgb <0.9,0.9,0.9>}}
        finish{phong 1
         diffuse 0.35}
      }