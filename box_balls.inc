#include "glass.inc"
#include "colors.inc"
#include "shapes.inc"


#declare balls_box_texture = texture {
              Polished_Chrome
                   // pigment{ color rgb<1,0,0> } 
                   finish { phong 1 }
                 } // end of texture 

 

#declare corner_box_cilinder = difference{  
          object { //Round_Cylinder(point A, point B, Radius, EdgeRadius, UseMerge)
                 Round_Cylinder(<0,2,0>, <0,0,0>, 0.50 ,       0.20,   0)  
                 
                 texture{   Glass
                        }
                 scale<2,2,2>  rotate<0, 0,0> translate<0,0.00,0>
               } // ---------------------------------------------------------
               
         object { //Round_Cylinder(point A, point B, Radius, EdgeRadius, UseMerge)
                 Round_Cylinder(<0.75,3,0>, <0.75,0,0>, 0.75 ,       0.20,   0)  
                 
                 texture{   Glass
                        }
                 scale<2,2,2>  rotate<0, 0,0> translate<0,0.00,0>
               } // ---------------------------------------------------------
        
      
}       

#declare balls_box_corners = difference {
      object{ // Round_Box(A, B, WireRadius, UseMerge)
        Round_Box(<0,0,0>,<3,1,5>, 0.25   , 0)  
         
        texture{  Glass
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
      }
      
      box { <1, 0, -1>,< 2.00, 2.00, 00.15>   

      texture {   Glass
              } // end of texture

      scale <1,1,1> rotate<0,0,0> translate<0,0,0> 
        } // end of box --------------------------------------
     
      box { <1, 0, 6>,< 2.00, 2.00, 05.85>   

      texture {  Glass
              } // end of texture

      scale <1,1,1> rotate<0,0,0> translate<0,0,0> 
        } // end of box --------------------------------------
}