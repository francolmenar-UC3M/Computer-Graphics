#macro sierpinski(s, base_center, recursion_depth)
    #if (recursion_depth > 0)
        union {        
            sierpinski(s / 2, base_center + s/2*y,      recursion_depth - 1)
            sierpinski(s / 2, base_center - s/2*(x+z),  recursion_depth - 1)
            sierpinski(s / 2, base_center - s/2*(x-z),  recursion_depth - 1)
            sierpinski(s / 2, base_center - s/2*(-x+z), recursion_depth - 1)
            sierpinski(s / 2, base_center - s/2*(-x-z), recursion_depth - 1)
        }
    #else
        difference{
            box { <1,1,1>, <-1,0,-1> }
            plane{ x-y,  -sqrt(2)/2}
            plane{ -x-y, -sqrt(2)/2}
            plane{ z-y,  -sqrt(2)/2}
            plane{ -z-y, -sqrt(2)/2}
            scale s*1.0
            translate base_center             
        }     
    #end
#end