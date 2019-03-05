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


#declare balls_box_texture = texture {
              Polished_Chrome
                   // pigment{ color rgb<1,0,0> } 
                   finish { phong 1 }
                 } // end of texture 

 

#declare corner_box_cilinder = difference{  
          object { //Round_Cylinder(point A, point B, Radius, EdgeRadius, UseMerge)
                 Round_Cylinder(<0,2,0>, <0,0,0>, 0.50 ,       0.20,   0)  
                 
                 texture{   pigment { rgbf<1.0, 1.0, 1.0, 0.7> }
                            finish  { Glass_Finish reflection 0.3}
                            }
                 scale<2,2,2>  rotate<0, 0,0> translate<0,0.00,0>
               } // ---------------------------------------------------------
               
         object { //Round_Cylinder(point A, point B, Radius, EdgeRadius, UseMerge)
                 Round_Cylinder(<0.75,3,0>, <0.75,0,0>, 0.75 ,       0.20,   0)  
                 
                 texture{ pigment { rgbf<1.0, 1.0, 1.0, 0.7> }
                          finish  { Glass_Finish reflection 0.3}
                        }
                 scale<2,2,2>  rotate<0, 0,0> translate<0,0.00,0>
               } // ---------------------------------------------------------
        
      
}       

#declare balls_box_corners = difference {
      object{ // Round_Box(A, B, WireRadius, UseMerge)
        Round_Box(<0,0,0>,<3,1,5>, 0.25   , 0)  
         
        texture{  pigment { rgbf<1.0, 1.0, 1.0, 0.7> }
                  finish  { Glass_Finish reflection 0.3}
                }
        scale<1,1,1>  rotate<0, 0,0> translate<0,0.1,0>
      } // ---------------------------------------------------------  
      
      object {
                corner_box_cilinder 
                rotate<0,315,0> 
                translate<0.5,0,0.5>
      }    
      object {
                corner_box_cilinder 
                rotate<0,225,0> 
                translate<2.5,0,0.5>
      }   
               
      object {
                corner_box_cilinder 
                rotate<0,135,0> 
                translate<2.5,0,4.5>
      }  
      object {
                corner_box_cilinder 
                rotate<0,45,0> 
                translate<0.5,0,4.5>
      }  
}

#declare balls_box_full = difference{
      object{
                balls_box_corners 
        
      }box { <1, 0, -1>,< 2.00, 2.00, 00.15>   

      texture {   pigment { rgbf<1.0, 1.0, 1.0, 0.7> }
                  finish  { Glass_Finish reflection 0.3}
              } // end of texture

      scale <1,1,1> rotate<0,0,0> translate<0,0,0> 
        } // end of box --------------------------------------
     
      box { <1, 0, 6>,< 2.00, 2.00, 05.85>   

      texture {  pigment { rgbf<1.0, 1.0, 1.0, 0.7> }
                 finish  { Glass_Finish reflection 0.3}
              } // end of texture

      scale <1,1,1> rotate<0,0,0> translate<0,0,0> 
        } // end of box --------------------------------------
}

#declare box_balls = union{
    object{
            balls_box_full
            translate <-1, 0, -1>
           }
    //-----GREEN BALLS------
sphere { <0,0,0>, 0.5 

        texture { pigment{ color rgb<00, 0.3, 0.00>}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

          scale<0.5,0.5,0.5>  rotate<0,0,0>  translate<0,0.5,0>  
       }  // end of sphere -----------------------------------       

sphere { <1,0,1.75>, 0.5 

        texture { pigment{ color rgb<00, 0.3, 0.00>}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

          scale<0.5,0.5,0.5>  rotate<0,0,0>  translate<0,0.5,0>  
       }  // end of sphere -----------------------------------  
       
sphere { <0.5,0,0.75>, 0.5 

        texture { pigment{ color rgb<00, 0.3, 0.00>}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

          scale<0.5,0.5,0.5>  rotate<0,0,0>  translate<0,0.5,0>  
       }  // end of sphere -----------------------------------       
       
//-----RED BALLS------
sphere { <0,0,2>, 0.5 

        texture { pigment{ color rgb<0.3, 0, 0.00>}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

          scale<0.5,0.5,0.5>  rotate<0,0,0>  translate<0,0.5,0>  
       }  // end of sphere ----------------------------------- 
 
 
//-----ORANGE BALLS------     
sphere { <0.75,0,-0.5>, 0.5 

        texture { pigment{ OrangeRed}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

          scale<0.5,0.5,0.5>  rotate<0,0,0>  translate<0,0.5,0>  
       }  // end of sphere -----------------------------------    
       
sphere { <3,0,1.75>, 0.5 

        texture { pigment{ OrangeRed}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

          scale<0.5,0.5,0.5>  rotate<0,0,0>  translate<0,0.5,0>  
       }  // end of sphere ----------------------------------- 
       

//-----BLUE BALLS------

sphere { <1.5,0,0.5>, 0.5 

        texture { pigment{ color rgb<00, 0, 0.3>}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

          scale<0.5,0.5,0.5>  rotate<0,0,0>  translate<0,0.5,0>  
       }  // end of sphere ----------------------------------- 

sphere { <1.75,0,-0.5>, 0.5 

        texture { pigment{ color rgb<00, 0, 0.3>}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

          scale<0.5,0.5,0.5>  rotate<0,0,0>  translate<0,0.5,0>  
       }  // end of sphere ----------------------------------- 
       
sphere { <2,0,1.5>, 0.5 

        texture { pigment{ color rgb<00, 0,0.3>}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

          scale<0.5,0.5,0.5>  rotate<0,0,0>  translate<0,0.5,0>  
       }  // end of sphere ----------------------------------- 

sphere { <2.75,0,-0.25>, 0.5 

        texture { pigment{ color rgb<00, 0, 0.3>}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

          scale<0.5,0.5,0.5>  rotate<0,0,0>  translate<0,0.5,0>  
       }  // end of sphere -----------------------------------  
       
sphere { <2.75,0,0.75>, 0.5 

        texture { pigment{ color rgb<00, 0, 0.3>}
                  finish { phong 1.0 reflection 0.00}
                } // end of texture

          scale<0.5,0.5,0.5>  rotate<0,0,0>  translate<0,0.5,0>  
       }  // end of sphere ----------------------------------- 
}