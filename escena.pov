//--------------------------------------------------------------------------
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
#include "jarronFinal.inc" 

//--------------------------------------------------------------------------------------------------------<<<<
//--------------------------------------------------------------------------------------------------------<<<<
//------------------------------------------------------------- Camera_Position, Camera_look_at, Camera_Angle
#declare Camera_Number = 5 ;
//--------------------------------------------------------------------------------------------------------<<<<
//--------------------------------------------------------------------------------------------------------<<<<
#switch ( Camera_Number )
#case (0)
  #declare Camera_Position = < 0.00, 0.0,-1.00> ;  // front view
  #declare Camera_Look_At  = < 0.00, 0.20,  0.00> ;
  #declare Camera_Angle    =  35 ;
#break
#case (1)
  #declare Camera_Position = < 0.50, 0.30, -0.30>  ;  // diagonal view
  #declare Camera_Look_At  = < 0.00, 0.18,  0.00>  ;
  #declare Camera_Angle    =  55 ;
#break
#case (2)
  #declare Camera_Position = < 2.00, 0.20, -0.001> ;  // right side view
  #declare Camera_Look_At  = < 0.00, 0.20,  0.00> ;
  #declare Camera_Angle    =  25 ;
#break
#case (3)
  #declare Camera_Position = < 1, 3,-145> ;  // front upper view
  #declare Camera_Look_At  = < 0, 3,  1.15> ;
  #declare Camera_Angle    =  00 ;
#case (4)
  #declare Camera_Position = < 1.5, 50,-75> ;  // front upper view
  #declare Camera_Look_At  = < 1.5, 7,  1.15> ;
  #declare Camera_Angle    =  00 ;
#break 
#case (5)
  #declare Camera_Position = < 1.5, 3,-145> ;  // front upper view
  #declare Camera_Look_At  = < 1.5, 3,  1.15> ;
  #declare Camera_Angle    =  00 ;
#break
#else
  #declare Camera_Position = < 0.00, 0.20,-2.00> ;  // front view
  #declare Camera_Look_At  = < 0.00, 0.20,  0.00> ;
  #declare Camera_Angle    =  35 ;
#break
#end // of "#switch ( Camera_Number )" -----------------------------
//-------------------------------------------------------------------------------------------------------<<<<
camera{ location Camera_Position
        right    x*image_width/image_height
        angle    Camera_Angle
        look_at  Camera_Look_At
      }
//------------------------------------------------------------------------------------------------------<<<<<
//------------------------------------------------------------------------
// sun -------------------------------------------------------------------
light_source{< 500,3500,-2500> color White*0.9}
light_source{ Camera_Position  color rgb<0.9,0.9,1>*0.1} 
// sky -------------------------------------------------------------------
sky_sphere{ pigment{ gradient <0,1,0>
                     color_map{ [0   color rgb<1,1,1>*0.6         ]//White
                                [0.1 color rgb<0.24,0.34,0.56>*0.8]//~Navy
                                [0.9 color rgb<0.24,0.34,0.56>*0.8]//~Navy
                                [1.0 color rgb<1,1,1>*0.6         ]//White
                              }
                     scale 2 }
           } // end of sky_sphere
//------------------------------------------------------------------------
 
fog { fog_type   2
      distance   2
      color     White*0.6 // rgb<1,0.89,0.7>*0.9  
      fog_offset 0.0
      fog_alt    0.1
      turbulence 1.8
    }
 

//------------------------------------------------------------------------

#declare Texture_A_Dark  = texture {
                               pigment{ color rgb<1,0.45,0>}
                               finish { phong 1}
                             }
#declare Texture_A_Light = texture {
                               pigment{ color rgb<1,1,1>}
                               finish { phong 1}
                             }


//-------------------------------------------------- end of coordinate axes


// ground -----------------------------------------------------------------
//---------------------------------<<< settings of squared plane dimensions
#declare RasterScale = 0.05;
#declare RasterHalfLine  = 0.025;
#declare RasterHalfLineZ = 0.025;
//-------------------------------------------------------------------------
#macro Raster(RScale, HLine)
       pigment{ gradient x scale RScale
                color_map{[0.000   color rgbt<1,1,1,0>*0.6]
                          [0+HLine color rgbt<1,1,1,0>*0.6]
                          [0+HLine color rgbt<1,1,1,1>]
                          [1-HLine color rgbt<1,1,1,1>]
                          [1-HLine color rgbt<1,1,1,0>*0.6]
                          [1.000   color rgbt<1,1,1,0>*0.6]} }
 #end// of Raster(RScale, HLine)-macro
//-------------------------------------------------------------------------


plane { <0,1,0>, 0    // plane with layered textures
        texture { NBglass pigment { color rgb <1,1,1>}}
        
        finish{phong 1}
      }                
      
plane {<0,0,1> 70
        texture{NBglass pigment {color rgb<1,1,1>}}
        }
//------------------------------------------------ end of squared plane XZ

//--------------------------------------------------------------------------
//---------------------------- objects in scene ----------------------------
//--------------------------------------------------------------------------                

#declare scaleConst = 110; // Constants for scaling the objects   
#declare scaleVector = <scaleConst,scaleConst,scaleConst> *1;
#declare zeroVector = <0.00,0.00,0.00>;   

object {        
    jarron
    scale scaleVector 
    rotate zeroVector
    translate <10.00,0.00,0.00>
}
