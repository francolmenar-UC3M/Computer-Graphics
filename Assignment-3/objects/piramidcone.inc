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

// basis object
#declare cone1 = union{
        cone { <0,0,0>,0.75,<0,1.50,0>,0 

       texture { pigment{ magnet 1
                     mandel 20 interior 1, 1
                     scale 0.25 rotate<0,30,0>
                     color_map{[0.0 color rgb <0,0,0>]
                     [0.2 color rgb <1,0,0>]
                     [0.4 color rgb <1,1,0>]
                     [1.0 color rgb <1,1,1>]
                     [1.0 color rgb <0,0,0>]} }
                 finish { phong 1 reflection{ 0.00 metallic 0.00} } 
               } // end of texture

       scale <1,1,1> rotate<0,0,0> translate<0,0,0>         
     } // end of cone -------------------------------------
    }

#macro conefractal(s, base_center, recursion_depth)
    #if (recursion_depth > 0) 
        union{
             conefractal(s / 2, base_center + s/2*x,  recursion_depth - 1)
             conefractal(s / 2, base_center - s/2*-x, recursion_depth - 1)
             conefractal(s / 2, base_center - s/2*y,  recursion_depth - 1)
             conefractal(s / 2, base_center - s/2*-y, recursion_depth - 1)
             conefractal(s / 2, base_center - s/2*z,  recursion_depth - 1)
             conefractal(s / 2, base_center - s/2*-z, recursion_depth - 1)
         }
     #else union{
            object {cone1
                    scale  s translate base_center
                    rotate <180,0,0>
                    texture { pigment{ magnet 1
                                 mandel 20 interior 1, 1
                                 scale 0.25 rotate<0,30,0>
                                 color_map{[0.0 color rgb <0,0,0>]
                                 [0.2 color rgb <1,0,0>]
                                 [0.4 color rgb <1,1,0>]
                                 [1.0 color rgb <1,1,1>]
                                 [1.0 color rgb <0,0,0>]} }
                             finish { phong 1 reflection{ 0.00 metallic 0.00} }
                     }
    
            }   
            
            object {cone1
                    scale  s translate base_center
                    rotate <0,0,0>
                    texture { pigment{ magnet 1
                                 mandel 20 interior 1, 1
                                 scale 0.25 rotate<0,30,0>
                                 color_map{[0.0 color rgb <0,0,0>]
                                 [0.2 color rgb <1,0,0>]
                                 [0.4 color rgb <1,1,0>]
                                 [1.0 color rgb <1,1,1>]
                                 [1.0 color rgb <0,0,0>]} }
                             finish { phong 1 reflection{ 0.00 metallic 0.00} }
                     }
    
            } 
            
         
      }    
    #end
#end

