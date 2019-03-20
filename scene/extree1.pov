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
// Classic tree example
//-----------------------------------------
// This file calls the MakeTree and MakeLeaf macros
// and defines the textures and parameters
// Set the [dofile] parameter to "true"
// when you want to create the final file
//-----------------------------------------
#include "colors.inc"
#include "../objects/txttree.inc"
#include "maketree.pov" // tree & leaf macro
//=========================================
// Camera & light
//-----------------------------------------
#declare PdV=<0, 4 , -110>;
#declare PdA=<0,25,0>;
camera {location  PdV direction <0.0 , 0.0 , 1.7 > up y  right 4*x/3 look_at   PdA}
//-----------------------------------------
light_source{PdV color White*0.5  shadowless}
light_source{<130,40,-200> color White*1.8}
//=========================================
// Tree macro Parameters
//-----------------------------------------
// These parameters must be declared before calling the tree macro
//-----------------------------------------
#declare dofile=false;    // true creates a tree file ; false otherwise
#declare dotexture=true;  // true creates a textured tree (with the texture following the branch); false otherwise
#declare ftname="gttree1.inc" // file name for tree
#declare fvname="gtfoliage1.inc" // file name for foliage
#declare ffname="gtleaf1.inc" // file name for leaf
#declare txtTree=texture{txtTree_3} // Bark texture

//-----------------------------------------
// Random streams
// one stream for branches and another one for leaves
// so that the leafed tree has the same structure as the leafless one
//-----------------------------------------
#declare rsd=1431;      // random seed
#declare rsd=1432;      // random seed
#declare rsd=1433;      // random seed
#declare rd=seed(rsd);  // random stream for branches
#declare rdl=seed(rsd); // separate random stream for leaves

//-----------------------------------------
// Tree structure parameters        
// test with low level0 and nseg0 (3 or 4)
// High (>=6) recursion levels [level0] gives more complex trees
// High (>=6) segment numbers [nseg0] gives smoother trees
//-----------------------------------------
#declare level0=7;      // recursion level
//#declare level0=3;      // recursion level
#declare nseg0=12;       // initial number of branch segments (decreases of one at each level)
#declare nb=3;          // max number of branches per level
#declare dotop=true;   // if true, generates an extra branch on top of trunk (sometimes necessary to give more verticality)

#declare lb0=25;        // initial branch length
#declare rb0=1.4;         // initial branch radius
#declare ab0=35;        // initial branch angle (x angle between the trunk and the first branch)
#declare qlb=0.67;       // branch length decrease ratio (1=constant length)
#declare qrb=0.59;       // branch radius decrease ratio (1=constant radius)
#declare qab=0.88;       // branch angle decrease ratio (1=constant angle)
#declare stdax=10;      // stdev of x angle (angle x = ax+(0.5-rand)*stdax)
#declare stday=10;      // stdev of y angle (angle y = ay+(0.5-rand)*stday)

#declare branchproba=1; // probability of branch apparition 
#declare jb=0.7;        // secondary branches start after this ratio of branch length

#declare fgnarl=0.25;    // gnarledness factor - keep it low <0.8
#declare stdlseg=0.5;     // stddev of branch segment length (0...1) (adds more randomness to branch length)

#declare twigproba=0.59; // probability to have a twig on a trunk segment

#declare v0=<0,1,0>;    // initial direction - change to give an initial orientation
#declare pos0=<0,0,0>;  // initial trunk position (no need to change this one)

//-----------------------------------------
// constraints parameters
//-----------------------------------------
#declare vpush=<0,-1,0>;// direction of push (wind, gravity...) <0,-1,0> = gravity ; <0,1,0> = antigravity
#declare fpush=0.2;       // force of push
#declare aboveground=0; // constrains the branches above this level 
#declare belowsky=140;  // constrains the branches below this level 

//-----------------------------------------
// root parameters
//-----------------------------------------
#declare rootproba=1;   // probability of root 0=no root ; 1=all [nb] roots
#declare nroot=5;      // number of roots;
#declare vroot=<1,0,0>; // initial direction of root 
#declare yroot=<0,0.5,0>;   // initial position of root above ground

//-----------------------------------------
// leaf position parameters
//-----------------------------------------
#declare leafproba=0.8;   // probability of leaf 0=no leaf ; 1=leaf on each segment
#declare leaflevel=4;   // level where the leaves start to appear
#declare alz0=100;       // max z angle for leaf
#declare alx0=-10;      // start x angle for leaf
#declare stdalx=40;     // std x angle for leaf
#declare stdlsize=0.1;     // stddev of leaf size 0=constant size; size = leafsize*(1+stdlsize*rand)

//-----------------------------------------
// leaf structure parameters
//-----------------------------------------
#declare txtLeaf=texture{txtLeaf_0} // Leaf texture
#declare lsize=0.3;     // leaf size
#declare seg=10;        // nb of leaf segments and stalk segments : increase to smooth
#declare ll=5;          // leaf length
#declare wl=1.2;          // leaf width 
#declare fl=0.5;        // depth of leaf fold
#declare lpow=1;        // modifies the leaf shape : lpow=3 makes heart-shaped leaf
#declare al=100;        // leaf bending angle : the leaf bends backward until this angle
#declare apow=1;        // curve power, how slow the leaf bends
#declare ndents=0;      // dents in the leaf (8 = "oak" leaf). May require a high seg >20
#declare nlobes=3;      // number of lobes (individual leaves)
#declare alobes=110;    // angle made by all the lobes
#declare qlobes=0.7;    // size of the farest lobe (0.9 = size will be 0.9*leaf length)                               
#declare ls=3;          // stalk length (0=no stalk)
#declare ws=0.12;        // width of stalk
#declare as=10;         // stalk bending angle : the stalk bends forward
//-----------------------------------------
// end of parameters
//=========================================

//=========================================
// Make the tree now !
//-----------------------------------------

object{
        #if (leafproba>0)
        #declare Leaf=object{MakeLeaf(lsize,seg,ll,wl,fl,lpow,al,apow,
                 ndents,nlobes,alobes,qlobes,ls,ws,as,dofile,ffname)
                 #if (dotexture=false)  // no texture applied to tree segments, so the leaf texture must be used for the individual leaf
                        texture{txtLeaf}
                 #end
        } 
        
        #end              
        MakeTree()
        
        #if (dotexture = true) // texture is already applied to tree so that we can safely apply the leaf texture to the leaves
                texture {txtLeaf}
        #else

                texture {txtTree} // apply tree texture  regardless of the tree structure
        #end    
        
        translate <-100, 0, 200>
}             
               
               
object{
        #if (leafproba>0)
        #declare Leaf=object{MakeLeaf(lsize,seg,ll,wl,fl,lpow,al,apow,
                 ndents,nlobes,alobes,qlobes,ls,ws,as,dofile,ffname)
                 #if (dotexture=false)  // no texture applied to tree segments, so the leaf texture must be used for the individual leaf
                        texture{txtLeaf}
                 #end
        } 
        
        #end              
        MakeTree()
        
        #if (dotexture = true) // texture is already applied to tree so that we can safely apply the leaf texture to the leaves
                texture {txtLeaf}
        #else

                texture {txtTree} // apply tree texture  regardless of the tree structure
        #end    
        
        translate <-25, 0, 200>
}       

object{
        #if (leafproba>0)
        #declare Leaf=object{MakeLeaf(lsize,seg,ll,wl,fl,lpow,al,apow,
                 ndents,nlobes,alobes,qlobes,ls,ws,as,dofile,ffname)
                 #if (dotexture=false)  // no texture applied to tree segments, so the leaf texture must be used for the individual leaf
                        texture{txtLeaf}
                 #end
        } 
        
        #end              
        MakeTree()
        
        #if (dotexture = true) // texture is already applied to tree so that we can safely apply the leaf texture to the leaves
                texture {txtLeaf}
        #else

                texture {txtTree} // apply tree texture  regardless of the tree structure
        #end    
        
        translate <50, 0, 200>
}             

object{
        #if (leafproba>0)
        #declare Leaf=object{MakeLeaf(lsize,seg,ll,wl,fl,lpow,al,apow,
                 ndents,nlobes,alobes,qlobes,ls,ws,as,dofile,ffname)
                 #if (dotexture=false)  // no texture applied to tree segments, so the leaf texture must be used for the individual leaf
                        texture{txtLeaf}
                 #end
        } 
        
        #end              
        MakeTree()
        
        #if (dotexture = true) // texture is already applied to tree so that we can safely apply the leaf texture to the leaves
                texture {txtLeaf}
        #else

                texture {txtTree} // apply tree texture  regardless of the tree structure
        #end    
        
        translate <125, 0, 200>
}

plane{y,0 pigment{rgb<1,0.7,0.3>}}


background{color rgb <0.8,0.9,1>}

//tests for tree texture, leaf and leaf textures
//cylinder{0,y*4,1 texture{txtTree} scale 10}
//#declare Leaf=object{MakeLeaf(lsize,seg,ll,wl,fl,lpow,al,apow,ndents,nlobes,alobes,qlobes,ls,ws,as,dofile,ffname)  texture{txtLeaf}} 
//object{Leaf scale 15 rotate y*1 translate y*30 texture{txtLeaf} }
