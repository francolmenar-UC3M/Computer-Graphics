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

         
//This declare an object that will be used to obtain the box corners. Here we make the difference 
//between two cilinder so we obtain a U cilinder(being concave in the middle) tp make the rounded corners of the box
#declare corner_box_cilinder = difference{  
          object { //Round_Cylinder(point A, point B, Radius, EdgeRadius, UseMerge)
                 Round_Cylinder(<0,2,0>, <0,0,0>, 0.50 ,       0.20,   0)  
                 
                 texture{   pigment { rgbf<1.0, 1.0, 1.0, 0.7> }
                            finish  { Glass_Finish reflection 0.3}//We set the glass texture of the box
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
 
//We meake the difference to a rounded box of 4 corner_box_cilinder 
//to obbtain the 4 corners with the desired form.

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
                translate<0.5,0,0.5> //Each one will be in a specific postion
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

//The previous delcaration makes the corners but there is some space we hadn't taken away.
//Taht space is at the sides of the balls_box_corner (the shorter sides)
//For solving that, we make a difference with 2 boxes, each one situated a¡next to eah short side of balls_box_corners.
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


//This will declare the final box balls with the box obtained in balls_box_full and the necessaty balls
//We use union as want all the objects
#declare box_balls = union{
    object{
            balls_box_full
            translate <-1, 0, -1>
           }            
//We must call each sphere to simulate the balls and igve them the correct color pigment, the scale and the position 
//that they willhave inside the box using the translate characteristic           
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