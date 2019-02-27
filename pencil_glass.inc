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
#include "jarron.inc" 

#declare pencilGlass =  union{
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
    texture { Glass pigment{ color rgb<1,1,1>}}
  }

}