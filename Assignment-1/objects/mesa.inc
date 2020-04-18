/* A squarish wood inlaid tea or coffee table with bonus silver
  serving tray. PovRay version 3.0 or later.
  Created by: Ken Tyler tylereng@pacbell.net 12-21-98
  Object siaze 4 x 6 x 1.5. The finish for this was optimized for
  this scene and may need to be adjusted for different lighting
  conditions. Feel free to try changing the wood textures for a
  different look on the inlay sections. I tried many combinations
  and several looked great before I settled on this one. Becase of
  the many directions the wood grain takes it is *important* to use
  anti aliasing with this object or it will look very jagged */

  #include "woods.inc"
  #include "metals.inc"

  #declare FW = 
  finish{
  ambient    .4000
  diffuse    .6500
  specular   .5000
  roughness  .0005 
  reflection .0500}

  #declare TW = texture{T_Wood16 scale 4.75 rotate 90*x}

  #declare Ta  = texture{T_Wood15 scale< 9.75,4.75,4.75>rotate<2,90,0>finish{FW}}
  #declare Tb  = texture{T_Wood36 scale< 9.75,1.00,1.00>rotate<2,90,0>finish{FW}}
  #declare Tc  = texture{T_Wood15 scale< 9.75,4.75,4.75>rotate<2,90,0>finish{FW}}
  #declare Td  = texture{T_Wood36 scale< 9.75,1.00,1.00>rotate<2,90,0>finish{FW}}
  #declare Te  = texture{T_Wood15 scale< 9.75,4.75,4.75>rotate<2,90,0>finish{FW}}
  #declare Tf  = texture{T_Wood36 scale< 9.75,1.00,1.00>rotate<2,90,0>finish{FW}}
  #declare Tg  = texture{T_Wood28 scale< 8.75,8.75,8.75>rotate<2, 0,0>finish{FW}}
  #declare Th  = texture{T_Wood16 scale< 8.75,2.75,2.75>rotate<2, 0,0>finish{FW}}
  #declare Ti  = texture{T_Wood17 scale< 8.75,2.75,2.75>rotate<2, 0,0>finish{FW}}
 
  #declare Bx1 = box{-1,1 scale<23,0.3,1>                            }
  #declare Bx2 = box{-1,1 scale<23,0.3,1>texture{Tg                 }}
  #declare Bx3 = box{-1,1 scale<23,0.3,1>pigment{rgbf 1             }}
  #declare Bx4 = box{-1,1 scale<23,0.3,1.5>rotate 0*x pigment{rgbf 1}}
  #declare Bx5 = box{-1,1 scale<23,0.3,1.5>rotate 0*x                }

  #declare Set1 = union {
  object{Bx2 translate<0,0.3, 7.5>}
  object{Bx2 translate<0,0.3, 6.0>}
  object{Bx2 translate<0,0.3, 4.5>}
  object{Bx2 translate<0,0.3, 3.0>}
  object{Bx2 translate<0,0.3, 1.5>}
  object{Bx2 translate<0,0.3, 0.0>}
  object{Bx2 translate<0,0.3,-1.5>}
  object{Bx2 translate<0,0.3,-3.0>}
  object{Bx2 translate<0,0.3,-4.5>}
  object{Bx2 translate<0,0.3,-6.0>}
  object{Bx2 translate<0,0.3,-7.5>}}

  #declare Set2 = union {
  object{Bx1 translate<0,0.3, 15>texture{Ta}}
  object{Bx1 translate<0,0.3, 12>texture{Tb}}
  object{Bx1 translate<0,0.3,  9>texture{Tc}}
  object{Bx1 translate<0,0.3,  6>texture{Td}}
  object{Bx1 translate<0,0.3,  3>texture{Te}}
  object{Bx1 translate<0,0.3,  0>texture{Tf}}
  object{Bx1 translate<0,0.3, -3>texture{Te}}
  object{Bx1 translate<0,0.3, -6>texture{Td}}
  object{Bx1 translate<0,0.3, -9>texture{Tc}}
  object{Bx1 translate<0,0.3,-12>texture{Tb}}
  object{Bx1 translate<0,0.3,-15>texture{Ta}}}

  #declare Set3 = union {
  object{Bx3 translate<0,0.3, 15>}
  object{Bx3 translate<0,0.3, 12>}
  object{Bx3 translate<0,0.3,  9>}
  object{Bx3 translate<0,0.3,  6>}
  object{Bx3 translate<0,0.3,  3>}
  object{Bx3 translate<0,0.3,  0>}
  object{Bx3 translate<0,0.3, -3>}
  object{Bx3 translate<0,0.3, -6>}
  object{Bx3 translate<0,0.3, -9>}
  object{Bx3 translate<0,0.3,-12>}
  object{Bx3 translate<0,0.3,-15>}}

  // Start Construction

  #declare Set5a = intersection { union {
  object { Set2 rotate 45* y }
  object { Set2 rotate 45*-y}}
  plane  { x,-20 inverse     }
  plane  { x, 20             }
  plane  { z,-20 inverse     }
  plane  { z, 20             }
  pigment{rgbf 1}}

  #declare Set1a = merge  {
  object { Set1 rotate<0,90,0>                 }
  object { Set1 rotate<0,90,0> translate x*-17 }
  object { Set1 rotate<0,90,0> translate x* 17}}

  #declare Set3a = intersection {
  object { Set1a               }
  object { Set3 scale 1.000001}}

  #declare Set1b1 = union {
  object { Set3a}
  object { Set1  rotate<0,90,0>scale 1                }
  object { Set1  rotate<0,90,0>translate x*-17 scale 1}
  object { Set1  rotate<0,90,0>translate x* 17 scale 1}
  object { Set5a scale 1.00001}}

  #declare PlaneSet1 = intersection {
  object { Set1b1}
  plane  { x,-20 inverse pigment{rgbft 1}} 
  plane  { x, 20         pigment{rgbft 1}}
  plane  { z,-20 inverse pigment{rgbft 1}} 
  plane  { z, 20         pigment{rgbft 1}}
  scale .5}

  #declare Frame1 = intersection {
  box{-1,1 scale<12.0,0.3,12.0>translate<0,.3,0>       }
  box{-1,1 scale<9.99,0.4,9.99>translate<0,.3,0>inverse}
  texture{Tg}}

  #declare Frame2 = intersection {
  box{-1,1 scale<16.0,0.3,16.0>translate<0,.3,0>       }
  box{-1,1 scale<11.9,0.4,11.9>translate<0,.3,0>inverse}
  texture{Th}}

  #declare Inlay1 = intersection { union {
  object { Frame1   rotate 90*-y  }
  object { Frame2   rotate 90*-y  }
  object { PlaneSet1 scale<1,2,1>}}
  plane  { y,.1 inverse pigment{rgbf 1}}
  scale .125}

  #declare Set2A = union {
  object{Bx5 translate<0,.3, 18>texture{Ti}}
  object{Bx5 translate<0,.3, 12>texture{Ti}}
  object{Bx5 translate<0,.3,  6>texture{Ti}}
  object{Bx5 translate<0,.3,  0>texture{Ti}}
  object{Bx5 translate<0,.3, -6>texture{Ti}}
  object{Bx5 translate<0,.3,-12>texture{Ti}}
  object{Bx5 translate<0,.3,-18>texture{Ti}}}

  #declare Set3A = union {
  object{Bx4 translate<0,.3, 18>}
  object{Bx4 translate<0,.3, 12>}
  object{Bx4 translate<0,.3,  6>}
  object{Bx4 translate<0,.3,  0>}
  object{Bx4 translate<0,.3, -6>}
  object{Bx4 translate<0,.3,-12>}
  object{Bx4 translate<0,.3,-18>}}

  #declare Set5b = intersection { union {
  object{Set2A rotate 45* y}
  object{Set2A rotate -45*y}
  rotate 45*y              }
  plane{ x,-20 inverse     }
  plane{ x, 20             }
  plane{ z,-20 inverse     }
  plane{ z, 20             }
  pigment{rgbf 1}}

  #declare SetA1 = merge {
  object{Set1 rotate<0,90,0>                }
  object{Set1 rotate<0,90,0>translate x*-17 }
  object{Set1 rotate<0,90,0>translate x* 17}}

  #declare SetA3 = intersection {
  object{SetA1                }
  object{Set3A scale 1.000001}}

  #declare Set1b2 = union {
  object{SetA3}
  object{Set1  rotate<0,90,0>scale 1                }
  object{Set1  rotate<0,90,0>translate x*-17 scale 1}
  object{Set1  rotate<0,90,0>translate x* 17 scale 1}
  object{Set5b scale 1.00001}}

  #declare PlaneSet2 = intersection {
  object{Set1b2}
  plane{ x,-20 inverse pigment{rgbft 1}}plane{ x, 20 pigment{rgbft 1}}
  plane{ z,-20 inverse pigment{rgbft 1}}plane{ z, 20 pigment{rgbft 1}}
  scale .5}

  #declare Inlay2 = intersection { union {
  object {Frame1   rotate 90*-y  }
  object {Frame2   rotate 90*-y  }
  object {PlaneSet2 scale<1,2,1> }}
  plane  {y,.1 inverse pigment{rgbf 1}}scale .13 }

  #declare Parkay1 =
  union{
  object{Inlay1 rotate   0*y translate<-2,0, 2>}
  object{Inlay1 rotate  90*y translate<-2,0,-2>}
  object{Inlay1 rotate   0*y translate< 2,0,-2>}
  object{Inlay1 rotate  90*y translate< 2,0, 2>}
  object{Inlay2 rotate -90*y translate<-6,0,-6>}
  object{Inlay2 rotate  90*y translate<-6,0,-2>}
  object{Inlay2 rotate -90*y translate<-6,0, 2>}
  object{Inlay2 rotate  90*y translate<-6,0, 6>}
  object{Inlay2 rotate -90*y translate<-2,0, 6>}
  object{Inlay2 rotate  90*y translate< 2,0, 6>}
  object{Inlay2 rotate -90*y translate< 6,0, 6>}
  object{Inlay2 rotate  90*y translate< 6,0, 2>}
  object{Inlay2 rotate -90*y translate< 6,0,-2>}
  object{Inlay2 rotate  90*y translate< 6,0,-6>}
  object{Inlay2 rotate -90*y translate< 2,0,-6>}
  object{Inlay2 rotate  90*y translate<-2,0,-6>}}

  #declare Parkay2 =
  union{
  object{Inlay1 rotate   0*y translate< 0,0, 2>}
  object{Inlay1 rotate  90*y translate< 0,0,-2>}
  object{Inlay2 rotate -90*y translate<-4,0,-2>}
  object{Inlay2 rotate  90*y translate<-4,0, 2>}
  object{Inlay2 rotate -90*y translate<-4,0, 6>}
  object{Inlay2 rotate  90*y translate< 0,0, 6>}
  object{Inlay2 rotate -90*y translate< 4,0, 6>}
  object{Inlay2 rotate  90*y translate< 4,0, 2>}
  object{Inlay2 rotate -90*y translate< 4,0,-2>}
  object{Inlay2 rotate  90*y translate< 4,0,-6>}
  object{Inlay2 rotate -90*y translate< 0,0,-6>}
  object{Inlay2 rotate  90*y translate<-4,0,-6>}}
  
  #declare Top =
  box{-1,1 scale<4.050,0.150,6.075>translate<0,3.000,0>texture{Th}}

  #declare TopTrim =
  box{-1,1 scale<4.125,0.025,6.125>translate<0,3.125,0>texture{Th}}

  #declare EndPanel = union{
  box{-1,1 scale<4.135,0.32,0.1>translate<0,2.8,-6.05>}
  box{-1,1 scale<4.135,0.32,0.1>translate<0,2.8, 6.05>}
  texture{Th rotate 90*y}}

  #declare SidePanel = union{
  box{-1,1 scale<0.1,0.32,6.135>translate<-4.05,2.8,0>}
  box{-1,1 scale<0.1,0.32,6.135>translate< 4.05,2.8,0>}
  texture{Th}} 

  #declare Legs = union{
  box{-1,1 scale<0.35,1.255,0.35>translate<-3.8,1.255,-5.8>}
  box{-1,1 scale<0.35,1.255,0.35>translate<-3.8,1.255, 5.8>}
  box{-1,1 scale<0.35,1.255,0.35>translate< 3.8,1.255,-5.8>}
  box{-1,1 scale<0.35,1.255,0.35>translate< 3.8,1.255, 5.8>}
  texture{Th rotate 90*x}}

  #declare Coffee_Table = union { union {
  object{Top         }
  object{TopTrim     }
  object{SidePanel   }
  object{EndPanel    }
  object{Legs        }
  scale<1.035,1,.929>}
  object{Parkay2 scale .7 rotate 0*x translate 3.125*y}}

  #declare TeaTray =
  lathe{
  //linear_spline  // Fastest   render - decent  smoothness
  quadratic_spline // Smoother  finish - decent  render time
  //cubic_spline   // Smoothest finish - longest render time
  44
  <0.00000,.00000>,<0.00123,.00000>,<0.01234,.00000>,<0.09800,.00000>,
  <0.33333,.00000>,<0.75359,.00503>,<1.25094,.00402>,<1.68026,.01360>,
  <1.93296,.03097>,<2.04658,.05288>,<2.09520,.07480>,<2.13946,.09343>, 
  <2.18638,.11056>,<2.22953,.12920>,<2.26401,.15148>,<2.29094,.17604>,
  <2.31293,.20060>,<2.33325,.22301>,<2.35772,.24165>,<2.39280,.25500>,
  <2.44058,.26255>,<2.48574,.26784>,<2.50860,.27540>,<2.49531,.28799>,
  <2.45554,.30134>,<2.40480,.30940>,<2.35606,.30725>,<2.31224,.29454>,
  <2.27373,.27200>,<2.23977,.24114>,<2.20507,.20651>,<2.16320,.17340>,
  <2.10943,.14620>,<2.04583,.12580>,<1.97620,.11220>,<1.89434,.10502>,
  <1.75427,.10237>,<1.50006,.10200>,<1.10537,.10200>,<0.66229,.10200>,
  <0.29253,.10200>,<0.08667,.10200>,<0.01083,.10200>,<0.00000,.10200>}

  object  { Coffee_Table rotate 0*y }

  object  { TeaTray scale<1,1,0.75>texture { T_Silver_5E }
  translate<0,3.2,2>}

  camera{location<-7,10,-13>look_at<0,0,0> }

  light_source{<10,10,  19>rgb 1 }
  light_source{< 0,90,-400>rgb 1 }  

  // Floor 
  plane { y, 0.0 pigment{bozo 
  color_map{[.15 rgb<0.47,0.43,0.40>][1 rgb<0.70,0.66,0.62>]}
  scale .003} finish{ambient .6 diffuse .3}}

  // Walls and Ceiling
  plane { -y,-120 pigment{rgb<0.75,0.75,0.75>}finish{ambient .6 diffuse .3}}
  plane { -z,-20  pigment{rgb<0.29,0.24,0.20>}finish{ambient .4 diffuse .1}}
  plane {  x, 20  pigment{rgb<0.99,0.94,0.92>}finish{ambient .4 diffuse .2}}


  // Bonus
  // An example of method to tile a floor with the individual squares 
  // Tile scale =>  X = 2, Y = 0.1, Z = 2
  /*
  #declare AA =  0;
  #while  (AA <  4)
  #declare BB =  0;
  #while  (BB <  4)
  union{
  object{Inlay1 rotate  0*y translate<-2,0, 2>}
  object{Inlay1 rotate 90*y translate<-2,0,-2>}
  object{Inlay1 rotate  0*y translate< 2,0,-2>}
  object{Inlay1 rotate 90*y translate< 2,0, 2>}
  translate<-12,0,-12>translate<16*AA,0,16*BB> }
  #declare BB=BB+1; #end
  #declare AA=AA+1; #end
  */