//--------------------------------------------------------------------------
#version 3.7
global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 conserve_energy}}
//--------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "transforms.inc" 
#include "../objects/jarronFinal.inc"  
#include "../objects/pencil_glass.inc" 
#include "../objects/box_balls.inc"  
#include "../objects/pared.inc"
#include "../objects/ground.inc"  

//--------------------------------------------------------------------------------------------------------<<<<
//--------------------------------------------------------------------------------------------------------<<<<
//------------------------------------------------------------- Camera_Position, Camera_look_at, Camera_Angle
#declare Camera_Number =  1;
//--------------------------------------------------------------------------------------------------------<<<<
//--------------------------------------------------------------------------------------------------------<<<<
#switch ( Camera_Number )
#case (0)
  #declare Camera_Position = < 1, 20,-50.00> ;  // front close view
  #declare Camera_Look_At  = < 1, 20,  1.00> ;
  #declare Camera_Angle    =  0 ;
#break   
#case (1)
  #declare Camera_Position = < 0, 15,-70.00> ;  // front view
  #declare Camera_Look_At  = < 0, 15,  1.00> ;
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
sky_sphere{ pigment{ gradient <0,1,0>
                     color_map{ [0   color rgb<1,1,1>*0.6         ]//White
                                [0.1 color rgb<0.24,0.34,0.56>*0.8]//~Navy
                                [0.9 color rgb<0.24,0.34,0.56>*0.8]//~Navy
                                [1.0 color rgb<1,1,1>*0.6         ]//White
                              }
                     scale 2 }
           } // end of sky_sphere
//-----------------------------------------------------------------------                
//---------------------------- objects in scene ----------------------------
//--------------------------------------------------------------------------                

#declare scaleConst = 110; // Constants for scaling the objects   
#declare scaleVector = <scaleConst,scaleConst,scaleConst> * 1;                                               
                                                 
object { ground } // Ground floor
object { wall }   // Wall        

object { // Bottle       
    jarron
    scale scaleVector 
    translate <15.00,0.00,0.00>
}

object { //Glass of pencils
    pencilGlass
    scale 4
    translate <-5, 5, 0> 
    rotate <0, 285, 0>
}

object { //Box of balls
    box_balls
    scale 5
    translate <1, 0, -15> 
    rotate <0, 60, 0>
}       