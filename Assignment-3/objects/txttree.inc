//=========================================
// Leaf & Tree examples for the MakeTree macro
//==========================================  
// Copyright 1999-2004 Gilles Tran http://www.oyonale.com
// -----------------------------------------
// This work is licensed under the Creative Commons Attribution License. 
// To view a copy of this license, visit http://creativecommons.org/licenses/by/2.0/ 
// or send a letter to Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.
// You are free:
// - to copy, distribute, display, and perform the work
// - to make derivative works
// - to make commercial use of the work
// Under the following conditions:
// - Attribution. You must give the original author credit.
// - For any reuse or distribution, you must make clear to others the license terms of this work.
// - Any of these conditions can be waived if you get permission from the copyright holder.
// Your fair use and other rights are in no way affected by the above. 
//==========================================  
// Curved tree with long branches
// The curvature is obtained through the vpush vector <1,-0.8,0>
#include "colors.inc"
//=========================================
// Some tree textures
//=========================================
// simple tree texture for tests
//-----------------------------------------
#declare txtTree_0=texture{pigment{Tan}}
//-----------------------------------------
// tree texture with a image_map
//-----------------------------------------
//#declare txtTree_1=texture{pigment{image_map{png "treepig.png"  map_type 2  interpolate 2 }}}
//-----------------------------------------
// crackle tree textures
//-----------------------------------------
#declare colBark=rgb <1,0.6,0.31>; // nice brown
#declare txtTree_2=texture{pigment{crackle turbulence 0.4 lambda 3.2 color_map{[0 color colBark*.3][0.1 color colBark*.4][0.6 color colBark*.8] [1 color colBark*1.2]}}       
finish{ambient 0.1} scale <0.2,0.7,0.2>*1}                 
//-----------------------------------------
#declare colBark=rgb <1,0.8,0.51>*0.8; // dirty brown
#declare txtTree_3=texture{pigment{crackle turbulence 0.4 lambda 3.2 color_map{[0 color colBark*.3][0.1 color colBark*.4][0.6 color colBark*.8] [1 color colBark*1.2]}}       
finish{ambient 0.1} scale <0.2,0.7,0.2>*1}                 
//-----------------------------------------
#declare colBark=rgb <1,0.8,0.51>*2; // light brown
#declare txtTree_4=texture{pigment{crackle turbulence 0.4 lambda 3.2 color_map{[0 color colBark*.3][0.1 color colBark*.4][0.6 color colBark*.8] [1 color colBark*1.2]}}       
finish{ambient 0.1} scale <0.2,0.7,0.2>*1}                 

//-----------------------------------------
// birch-like tree texture
//-----------------------------------------
#declare colBark=rgb <1,0.8,0.64>; // light brown, white
#declare txtTree_5=texture{pigment{gradient y turbulence 0.7 lambda 4 color_map{[0 color colBark*.3] [0.1 color colBark][0.9 color colBark][1 color colBark*.4]}} finish{ambient 0.1}}
texture{pigment{bozo turbulence 0.7 lambda 4 color_map{[0 color colBark*.2][0.1 color colBark*.3] [0.3 color colBark*.4][0.4 color Clear][0.9 color Clear][1 color colBark*.4] }}finish{ambient 0.1}}                 

//-----------------------------------------
// spiral tree texture
//-----------------------------------------
#declare colBark=rgb <1,0.6,0.2>;
#declare txtTree_6=texture{pigment{spiral1 8 turbulence 0.5 lambda 4 color_map{[0 color colBark*.3] [0.3 color colBark*0.5][0.9 color colBark][1 color colBark*.4] }} finish{ambient 0.1} scale <1,3,1>}                
texture{pigment{bozo turbulence 0.7 lambda 3 color_map{[0 color Clear][0.1 color colBark*.1] [0.4 color Clear][0.9 color Clear][1 color colBark*.4] }} finish{ambient 0.1}}                 

//=========================================
// Leaf color and textures
//-----------------------------------------
// Simple leaf textures
//-----------------------------------------
#declare colLeaf=rgb <0.4,1,0.3>*0.4; // nice green
#declare txtLeaf_0=texture{pigment{colLeaf} finish{ambient 0.1 specular 0.3 roughness 0.01}}
//-----------------------------------------
#declare colLeaf=rgb <0.6,1,0.3>*0.8; // yellow clear green
#declare txtLeaf_1=texture{pigment{colLeaf} finish{ambient 0.1 specular 0.3 roughness 0.01}}
//-----------------------------------------
#declare colLeaf=rgb <0.65,1,0.3>*0.3; // olive green
#declare txtLeaf_3=texture{pigment{colLeaf} finish{ambient 0.1 specular 0.3 roughness 0.01}}
//-----------------------------------------
// Automn leaf (bad...)
//-----------------------------------------
#declare colLeaf_1=rgb <0.4,1,0.3>*0.4; // green
#declare colLeaf_2=rgb <1,0.8,0.3>*0.8; // yellow
#declare colLeaf_3=rgb <1,0.2,0.1>*0.8; // red
#declare txtLeaf_4=texture{
pigment{bozo turbulence 0.5        
        color_map{[0.0 color colLeaf_1][0.3 color colLeaf_2] [0.5 color colLeaf_3][0.7 color colLeaf_2][1.0 color colLeaf_1] }}       
        finish{ambient 0.1 specular 0.3 roughness 0.01}}                 
//-----------------------------------------
// Yellow and greenish (need scaling)
//-----------------------------------------
#declare colLeaf_1=rgb <0.7,1,0.2>*0.8; // greenish 
#declare colLeaf_2=rgb <1,0.7,0.2>*0.8; // yellow
#declare txtLeaf_5=texture{pigment{agate color_map{[0.0 color colLeaf_1][0.3 color colLeaf_2] [0.7 color colLeaf_2][1.0 color colLeaf_1] }}       
        finish{ambient 0.1 specular 0.3 roughness 0.01} scale 10}                 
