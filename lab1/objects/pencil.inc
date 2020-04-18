#include "colors.inc"
#include "textures.inc"
#include "woods.inc"
#include "metals.inc"
 
//This is the only object for which we look in internet, we found it at http://objects.povworld.org/cat/Tools/Writing/
//However we take waya some declaration that were unuseful for us.
 
 //texture of the pencil, this will make the pencil look as a wood pencil
#declare pencil_wood_texture = texture
{
    T_Wood35
    finish
    {
        specular 0.15
        roughness 0.025
        ambient 0.25
        reflection 0
    }

    rotate y*90
    rotate <10, 0, 15>
    scale <2,1,1>
    translate -3*x
}

//Box we will use later for the body of the pencil
#declare pencil_clipping_box = box
{
    <-100,0,0>, <100, 10, 10>
}
 //Here we make the difference between a box and some boxes set in diferent positions respect axe x so we can 
 //obtain the final form of the pencil body as it must be an hexagon
#declare pencil_hexagon = difference
{
    box
    {
        <-80, -(sqrt (12)), -4>, <80, sqrt (12), 4>
    }
    object
    {
        pencil_clipping_box
        translate <0,0,-10>
        rotate <30,0,0>
        translate <0,0,-4>
    }
    object
    {
        pencil_clipping_box
        rotate <-30,0,0>
        translate <0,0,4>
    }
    object
    {
        pencil_clipping_box
        translate <0,-10,-10>
        rotate <-30,0,0>
        translate <0,0,-4>
    }
    object
    {
        pencil_clipping_box
        translate <0,-10,0>
        rotate <30,0,0>
        translate <0,0,4>
    }
}

//this declaration corresponds to the end of the pencil mine that have a conical shape 
#declare pencil_sharpener = difference
{
    box
    {
        <50,-20,-20>, <100,20,20>
    }
    cone
    {
        <50,0,0>, 6, <79.9,0,0>, 0.01
    }
    sphere
    {
        <79.99,0,0>, 0.01
    }
}
//This cilinder corresponds to the pencil mine, that is thre part of the pencil that paint 
#declare pencil_lead_base = cylinder
{
    <-80,0,0>, <80,0,0>, 1.5
}
//This is for seting the text in the pencil, we leave the one cames with the code
#declare pencil_text = text
{
    ttf "arial.ttf"
    "OA98 graphite pencil   HB"
    1, 0
    pigment
    {
        BrightGold
    }
    finish
    {
        reflection .25
        specular 1
    }
}
//to the obtain the final form of the mine, we must take the difference between the mine body of the pencil
//and the sharpener
#declare pencil_lead = difference
{
    object
    {
        pencil_lead_base
    }
    object
    {
        pencil_sharpener
    }
    pigment
    {
        rgb <0.1, 0.1, 0.1>
    }
    finish
    {
        Dull
    }
}
 //to set the exture of the pencil
#declare pencil_wood = difference
{
    object
    {
        pencil_hexagon
        scale <1, 0.99, 0.99>
    }
    object
    {
        pencil_lead_base
        scale <1.1,1,1>
    }
    object
    {
        pencil_sharpener
    }
    texture
    {
        pencil_wood_texture
    }
}
//To set the color of the pencil
#declare pencil_paint = difference
{
    object
    {
        pencil_hexagon
    }
    object
    {
        pencil_hexagon
        scale <1.1,0.99,0.99>
    }
    object
    {
        pencil_sharpener
    }
    pigment
    {
        Black
    }
    finish
    {
        specular 0.15
        roughness 0.025
        ambient 0.25
        reflection 0.01
    }
}

//This si used to attach the already written text we want into the pencil

#declare pencil_sleeve = difference
{
    object
    {
        pencil_paint
    }
    object
    {
        pencil_text
        scale 3
        rotate <90,0,0>
        translate <-74, 2.99 + sqrt(12), -1.06>
    }
}


//We must make a union between the lead, the wood and the sleeve parts to obtain the final form of the pencil
#declare pencil = union
{
    object {pencil_lead}
    object {pencil_wood}
    object {pencil_sleeve}
}

