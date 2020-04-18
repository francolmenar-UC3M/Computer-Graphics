#version 3.7
global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 conserve_energy}}
//--------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "transforms.inc"     
#include "../objects/jarron.inc" 
// Variables for transforming the original bottle into the desired one                          
#declare D = 0.000001;
#declare Glass_D = 0.004 * 1;
#declare Neck_Fillet =  0.240 * 1; // It must be larger than 0
#declare Bowl_Radius = 0.070 * 1;
#declare Neck_Radius = 0.016 * 1;  
#declare Neck_Length = 0.050 * 1;     
// Red textre of the bottle
#declare texturaRojaJarron =  
    texture {
        pigment{ color rgbt<0.7,0,0,0.3> } // Red color with transparency
        finish { specular 0.3
                 phong_size 50
                 phong 0.05
                 reflection 0.01
                 diffuse 0.78
                 ambient 0.09
                 }
     } 
// Glass texture of the base of the bottle 
#declare texturaBaseJarron = 
    texture {
        Glass3 // Glass3 texture is used as the base texture 
        pigment{ color rgbt<1,1,1,1> } // White color with transparency
        finish { specular 0.1
                 diffuse 0.9 
                 }  
        }
// Interior parameters for the base f the bottle
#declare intertiorBase = 
    interior {  ior 1
                caustics 1
                dispersion 0.8
                dispersion_samples 3
                fade_distance 1
                fade_power 1
                fade_color <0.8,0.8,0.8> 
                }
// Creation of the bottle object    
#declare jarron  = 
   union {  // Upper part of the bottle, the red one
        
            object{ Round_Bottom_Mace_1 (// A round-bottom flask shape 
                    Neck_Fillet, // > 0  neck base fillet
                    Bowl_Radius, // base bowl radius
                    Neck_Radius, // neck radius
                    Neck_Length, // 0=non; neck linear length 
                    1,           //   1 for transparent materials, else: 0 
                  )  
                texture { texturaRojaJarron } // Red texture for the bottle           
                translate<0.00,0.08, 0.00>
                } // end of jarron               
            
            // Bottle'ds base
            difference { // Get the base with the flat botton by the difference of
                         // the base and a plane
                                 
                difference{ // Get the base by the difference of two bottles      
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
                 } // end of difference which is the base    
                 
               plane { y, 0.03 }            // Plane that makes flat the base 
               texture{ texturaBaseJarron  } // Base Texture    
               interior {intertiorBase}      // Base's interior values
              } // end of difference which is the base with the flat bottom 
                 
      translate<0.00, -0.03, 0.00>
    }  // end of jarron     

