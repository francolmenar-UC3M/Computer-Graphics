#version 3.7
global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 conserve_energy}}
//--------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"
#include "stones.inc"
#include "woods.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"     
#include "../objects/jarron.inc" 
                          
#declare D = 0.000001;
#declare Glass_D = 0.004*1;
#declare Neck_Fillet =  0.240*1; // > 0 !!!  Curva de la boca
#declare Bowl_Radius = 0.070*1;
#declare Neck_Radius = 0.016*1;  
#declare Neck_Length = 0.050*1; //  Longitud de la boca    

#declare texturaRojaJarron =  
    texture {
        pigment {color rgbt<0.7,0,0,0.2>}
        finish { specular 0.13
                 phong_size 50
                 phong 0.05
                 reflection 0.01
                 diffuse 0.78
                 ambient 0.09
                 }
     } 

#declare texturaBaseJarron = 
texture {
        Glass3  
        pigment {color rgbt<1,1,1,1>}
        finish { 
            specular 0.1
            diffuse 0.9}  
        }

#declare intertiorBase = 
    interior {ior 1
                caustics 1
                dispersion 0.8
                dispersion_samples 3
                fade_distance 1
                fade_power 1
                fade_color <0.8,0.8,0.8> }
    


#declare jarron  = 
   union {  // Jarron de arriba     
            object{ Round_Bottom_Mace_1 (     //  A round-bottom flask shape 
                    Neck_Fillet, // > 0 // neck base fillet
                    Bowl_Radius, // base bowl radius
                    Neck_Radius, // neck radius
                    Neck_Length, // 0=non; neck linear length 
                    1, //   1 for transparent materials, else: 0 
                  )  
                texture { texturaRojaJarron } // Textura del jarrón de arriba           
            translate<0.00,0.08, 0.00>
    } // end of jarron               
            // Base del Jarron
            difference {       
                difference{     
                    object{ Round_Bottom_Mace_1 (
                                    Neck_Fillet, 
                                    Bowl_Radius, 
                                    Neck_Radius, 
                                    0, 
                                    1,
                                  ) 
                            translate<0.00,0.06, 0.00>
                    } // end of object            
                    object{ Round_Bottom_Mace_1 (   
                                    Neck_Fillet,
                                    Bowl_Radius, 
                                    Neck_Radius, 
                                    Neck_Length, 
                                    1, 
                                  ) 
                            translate<0.00,0.08, 0.00>
                    } // end of object
                    scale <0.8,0.6,0.8>  
                 } // end of difference 
                 plane { y, 0.03 }// Plano que corta la base por abajo
               texture{ texturaBaseJarron  } // Textura de la base    
               interior {intertiorBase}
              } // end of difference    
      translate<0.00, -0.03, 0.00>
    }  // end of union     

