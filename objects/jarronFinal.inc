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


#declare jarron  = 
   union {  // Jarron de arriba     
            object{ Round_Bottom_Mace_1 (     //  A round-bottom flask shape 
                    Neck_Fillet, // > 0 // neck base fillet
                    Bowl_Radius, // base bowl radius
                    Neck_Radius, // neck radius
                    Neck_Length, // 0=non; neck linear length 
                    1, //   1 for transparent materials, else: 0 
                  )
            texture
                {
                pigment
                {
                 color rgbt<0.7,0,0,0.6>
                }
               finish
                {
                specular 0.3
                phong_size 100
                phong 0.3
                reflection 0.1
                }
            }
 // Textura del jarrón de arriba 
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
                            translate<0.00,0.05, 0.00>
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
                 } // end of difference 
                 plane { y, 0.01 }// Plano que corta la base por abajo
               texture{ Glass  } // Textura de la base   
              } // end of difference    
      translate<0.00, -0.008, 0.00>
    }  // end of union     

