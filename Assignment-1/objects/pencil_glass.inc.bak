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
#include "../objects/pencil.inc" 

#declare Glass =  union{
    sor {
     7,
    <0.0,   0.0>,
    <2.0,   0.0>,
    <2.0,   3.5>,
    <1.7,   5.0>,
    <1.9,   5.1>,
    <2.0    5.2>, 
    <1.7,   5.0>
    open
    texture { Glass }
  } 
  

} 

#declare pencilGlass = union{
object
{
        Glass
        scale 0.6
} 
        
object
{
        pencil
        scale 0.04 // to get in cms
        rotate <0, -5, 55>  
        translate<0.75,3,-0.4>
}  
object
{
        pencil
        scale 0.04 // to get in cms
        rotate <0, 35, 90>  
        translate<-0.2,2.8,-0.65>
} 
object
{
        pencil
        scale 0.04 // to get in cms
        rotate <0, 30, 90>  
        translate<-0.5,2.8,-0.65>
} 
object
{
        pencil
        scale 0.04 // to get in cms
        rotate <0, 207, -95>  
        translate<0.6, 2.8, 0.5>
} 
object
{
        pencil
        scale 0.04 // to get in cms
        rotate <0, 212, -95>  
        translate<0.4, 2.8, 0.6>
}     
object
{
        pencil
        scale 0.04  
        rotate <0, 200, -60>
        translate<-0.5, 2.8, 0.5>
} 
object
{
        pencil
        scale 0.04  
        rotate <0, 200, -60>
        translate<-0.3, 2.8, 0.7>
}   
object
{
        pencil
        scale 0.04 
        rotate <0, 170, -60>
        translate <-0.5, 2.8, 0>
}
} 