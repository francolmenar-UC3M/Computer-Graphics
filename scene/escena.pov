//--------------------------------------------------------------------------
#version 3.7
global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 conserve_energy}}
//--------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "transforms.inc"   
#include "extree1.pov" 
#include "../objects/ground.inc"       
#include "../objects/sierpinski.inc" 
#include "../objects/piramidcone.inc"

//--------------------------------------------------------------------------------------------------------<<<<
//--------------------------------------------------------------------------------------------------------<<<<
//------------------------------------------------------------- Camera_Position, Camera_look_at, Camera_Angle
#declare Camera_Number =  1;
//--------------------------------------------------------------------------------------------------------<<<<
//--------------------------------------------------------------------------------------------------------<<<<
#switch ( Camera_Number )
#case (0)
  #declare Camera_Position = < 1, 20,-75.00> ;  // front close view
  #declare Camera_Look_At  = < 1, 20,  1.00> ;
  #declare Camera_Angle    =  0 ;
#break   
#case (1)
  #declare Camera_Position = < 0, 10,-40.00> ;  // front view
  #declare Camera_Look_At  = < 0, 10,  1.00> ;
  #declare Camera_Angle    =  0 ;
#break 
#case (2)
  #declare Camera_Position = < 1.5, 3,-145> ;  // front far view
  #declare Camera_Look_At  = < 1.5, 3,  1.15> ;
  #declare Camera_Angle    =  0 ;
#break 
#case (3)
  #declare Camera_Position = < 1.5, 6,-170> ;  // front far far view
  #declare Camera_Look_At  = < 1.5, 60,  1.15> ;
  #declare Camera_Angle    =  0 ;
#break     
#case (4)
  #declare Camera_Position = < 10, 0,-30.00> ;  //Camera for the base of the bottle
  #declare Camera_Look_At  = < 10, 0,  1.00> ;
  #declare Camera_Angle    =  0 ;
#break     
#case (5)
  #declare Camera_Position = < 80, 10,20.00> ;  // Vista desde el lado
  #declare Camera_Look_At  = < 0, 10,  0.00> ;
  #declare Camera_Angle    =  0 ;
#break
#else
  #declare Camera_Position = < 0.00, 100.20,-2.00> ;  // front view
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
light_source{< 2000,3500,-2500> color White*0.9}

// sky -------------------------------------------------------------------
plane{<0,1,0>,1 hollow  // 
      
        texture{ pigment {color rgb<0.1,0.3,0.75>*0.7}
                 #if (version = 3.7 )  finish {emission 1 diffuse 0}
                 #else                 finish { ambient 1 diffuse 0}
                 #end 
               } // end texture 1

        texture{ pigment{ bozo turbulence 0.75
                          octaves 6  omega 0.7 lambda 2 
                          color_map {
                          [0.0  color rgb <0.95, 0.95, 0.95> ]
                          [0.05  color rgb <1, 1, 1>*1.25 ]
                          [0.15 color rgb <0.85, 0.85, 0.85> ]
                          [0.55 color rgbt <1, 1, 1, 1>*1 ]
                          [1.0 color rgbt <1, 1, 1, 1>*1 ]
                          } // end color_map 
                         translate< 3, 0,-1>
                         scale <0.3, 0.4, 0.2>*3
                        } // end pigment
                 #if (version = 3.7 )  finish {emission 1 diffuse 0}
                 #else                 finish { ambient 1 diffuse 0}
                 #end 
               } // end texture 2
       scale 10000
     } //-------------------------------------------------------------
           

// ground fog at the horizon -----------------------------------------
fog{ fog_type   2
     distance   1000
     color      rgb<1,1,1>*0.9
     fog_offset 0.1
     fog_alt    20
     turbulence 1.8
   } //--------------------------------------------------------------
//-----------------------------------------------------------------------                
//---------------------------- objects in scene ----------------------------
//--------------------------------------------------------------------------                

#declare scaleConst = 110; // Constants for scaling the objects   
#declare scaleVector = <scaleConst,scaleConst,scaleConst> * 1;                                               
                                                 

  
object { sierpinski(2,0, 2)
          translate <-2, 0, 4> 
          scale <5, 5, 5>   
          rotate <0, -15, 0>  
          pigment {Blue_Agate}
          } 
          
object{conefractal(2, 0, 3) 
        translate<-2,2,2>
        rotate<0, 90,0>
        scale 4
        }