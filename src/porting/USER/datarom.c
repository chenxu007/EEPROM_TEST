﻿
#include "datarom.h"
  /*
 unsigned short  data_word1[] = {
// 1
	0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF,
    0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF,
    0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF,	
    0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF,
// 2		
    0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF,
    0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF,
    0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF,	
    0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF
};
*/
 const unsigned short data_word1[] = {
// 1
	0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF,
    0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF,
    0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF,	
    0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF,
// 2		
    0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF,
    0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF,
    0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF,	
    0x5A5A,0xA5A5, 0x0000,0xFFFF,     0x5A5A,0xA5A5, 0x0000,0xFFFF,    0x5A5A,0xA5A5, 0x0000,0xFFFF,   0x5A5A,0xA5A5, 0x0000,0xFFFF
};
 /*  unsigned short  data_word2[] = {
// 1
	0x1111,0x1111, 0x1111,0x1111,     0x1111,0x1111, 0x1111,0x1111,    0x1111,0x1111, 0x1111,0x1111,   0x1111,0x1111, 0x1111,0x1111,
    0x1111,0x1111, 0x1111,0x1111,     0x1111,0x1111, 0x1111,0x1111,    0x1111,0x1111, 0x1111,0x1111,   0x1111,0x1111, 0x1111,0x1111,
	0x1111,0x1111, 0x1111,0x1111,     0x1111,0x1111, 0x1111,0x1111,    0x1111,0x1111, 0x1111,0x1111,   0x1111,0x1111, 0x1111,0x1111,
    0x1111,0x1111, 0x1111,0x1111,     0x1111,0x1111, 0x1111,0x1111,    0x1111,0x1111, 0x1111,0x1111,   0x1111,0x1111, 0x1111,0x1111,
// 2		
    0x1111,0x1111, 0x1111,0x1111,     0x1111,0x1111, 0x1111,0x1111,    0x1111,0x1111, 0x1111,0x1111,   0x1111,0x1111, 0x1111,0x1111,
    0x1111,0x1111, 0x1111,0x1111,     0x1111,0x1111, 0x1111,0x1111,    0x1111,0x1111, 0x1111,0x1111,   0x1111,0x1111, 0x1111,0x1111,
	0x1111,0x1111, 0x1111,0x1111,     0x1111,0x1111, 0x1111,0x1111,    0x1111,0x1111, 0x1111,0x1111,   0x1111,0x1111, 0x1111,0x1111,
    0x1111,0x1111, 0x1111,0x1111,     0x1111,0x1111, 0x1111,0x1111,    0x1111,0x1111, 0x1111,0x1111,   0x1111,0x1111, 0x1111,0x1111
}; */
 const unsigned short  data_word2[] = {
// 1
	0x0000,0x0000, 0x0000,0x0000,     0x0000,0x0000, 0x0000,0x0000,    0x0000,0x0000, 0x0000,0x0000,   0x0000,0x0000, 0x0000,0x0000,
    0x0000,0x0000, 0x0000,0x0000,     0x0000,0x0000, 0x0000,0x0000,    0x0000,0x0000, 0x0000,0x0000,   0x0000,0x0000, 0x0000,0x0000,
	0x0000,0x0000, 0x0000,0x0000,     0x0000,0x0000, 0x0000,0x0000,    0x0000,0x0000, 0x0000,0x0000,   0x0000,0x0000, 0x0000,0x0000,
    0x0000,0x0000, 0x0000,0x0000,     0x0000,0x0000, 0x0000,0x0000,    0x0000,0x0000, 0x0000,0x0000,   0x0000,0x0000, 0x0000,0x0000,
// 2		
    0x0000,0x0000, 0x0000,0x0000,     0x0000,0x0000, 0x0000,0x0000,    0x0000,0x0000, 0x0000,0x0000,   0x0000,0x0000, 0x0000,0x0000,
    0x0000,0x0000, 0x0000,0x0000,     0x0000,0x0000, 0x0000,0x0000,    0x0000,0x0000, 0x0000,0x0000,   0x0000,0x0000, 0x0000,0x0000,
	0x0000,0x0000, 0x0000,0x0000,     0x0000,0x0000, 0x0000,0x0000,    0x0000,0x0000, 0x0000,0x0000,   0x0000,0x0000, 0x0000,0x0000,
    0x0000,0x0000, 0x0000,0x0000,     0x0000,0x0000, 0x0000,0x0000,    0x0000,0x0000, 0x0000,0x0000,   0x0000,0x0000, 0x0000,0x0000
}; 
 const unsigned short data_word3[] = {
// 1
	0xFFFF,0xFFFF, 0xFFFF,0xFFFF,     0xFFFF,0xFFFF, 0xFFFF,0xFFFF,    0xFFFF,0xFFFF, 0xFFFF,0xFFFF,   0xFFFF,0xFFFF, 0xFFFF,0xFFFF,
    0xFFFF,0xFFFF, 0xFFFF,0xFFFF,     0xFFFF,0xFFFF, 0xFFFF,0xFFFF,    0xFFFF,0xFFFF, 0xFFFF,0xFFFF,   0xFFFF,0xFFFF, 0xFFFF,0xFFFF,
    0xFFFF,0xFFFF, 0xFFFF,0xFFFF,     0xFFFF,0xFFFF, 0xFFFF,0xFFFF,    0xFFFF,0xFFFF, 0xFFFF,0xFFFF,   0xFFFF,0xFFFF, 0xFFFF,0xFFFF,
    0xFFFF,0xFFFF, 0xFFFF,0xFFFF,     0xFFFF,0xFFFF, 0xFFFF,0xFFFF,    0xFFFF,0xFFFF, 0xFFFF,0xFFFF,   0xFFFF,0xFFFF, 0xFFFF,0xFFFF,    
// 2		
    0xFFFF,0xFFFF, 0xFFFF,0xFFFF,     0xFFFF,0xFFFF, 0xFFFF,0xFFFF,    0xFFFF,0xFFFF, 0xFFFF,0xFFFF,   0xFFFF,0xFFFF, 0xFFFF,0xFFFF,
    0xFFFF,0xFFFF, 0xFFFF,0xFFFF,     0xFFFF,0xFFFF, 0xFFFF,0xFFFF,    0xFFFF,0xFFFF, 0xFFFF,0xFFFF,   0xFFFF,0xFFFF, 0xFFFF,0xFFFF,
    0xFFFF,0xFFFF, 0xFFFF,0xFFFF,     0xFFFF,0xFFFF, 0xFFFF,0xFFFF,    0xFFFF,0xFFFF, 0xFFFF,0xFFFF,   0xFFFF,0xFFFF, 0xFFFF,0xFFFF,
    0xFFFF,0xFFFF, 0xFFFF,0xFFFF,     0xFFFF,0xFFFF, 0xFFFF,0xFFFF,    0xFFFF,0xFFFF, 0xFFFF,0xFFFF,   0xFFFF,0xFFFF, 0xFFFF,0xFFFF
};
	//--------chapter.7 data----------
const unsigned short data_word4[] = {
// 1
	0x5555,0x5555, 0x5555,0x5555,     0x5555,0x5555, 0x5555,0x5555,    0x5555,0x5555, 0x5555,0x5555,   0x5555,0x5555, 0x5555,0x5555,
    0x5555,0x5555, 0x5555,0x5555,     0x5555,0x5555, 0x5555,0x5555,    0x5555,0x5555, 0x5555,0x5555,   0x5555,0x5555, 0x5555,0x5555,
	0x5555,0x5555, 0x5555,0x5555,     0x5555,0x5555, 0x5555,0x5555,    0x5555,0x5555, 0x5555,0x5555,   0x5555,0x5555, 0x5555,0x5555,
    0x5555,0x5555, 0x5555,0x5555,     0x5555,0x5555, 0x5555,0x5555,    0x5555,0x5555, 0x5555,0x5555,   0x5555,0x5555, 0x5555,0x5555,
// 2		
    0x5555,0x5555, 0x5555,0x5555,     0x5555,0x5555, 0x5555,0x5555,    0x5555,0x5555, 0x5555,0x5555,   0x5555,0x5555, 0x5555,0x5555,
    0x5555,0x5555, 0x5555,0x5555,     0x5555,0x5555, 0x5555,0x5555,    0x5555,0x5555, 0x5555,0x5555,   0x5555,0x5555, 0x5555,0x5555,
	0x5555,0x5555, 0x5555,0x5555,     0x5555,0x5555, 0x5555,0x5555,    0x5555,0x5555, 0x5555,0x5555,   0x5555,0x5555, 0x5555,0x5555,
    0x5555,0x5555, 0x5555,0x5555,     0x5555,0x5555, 0x5555,0x5555,    0x5555,0x5555, 0x5555,0x5555,   0x5555,0x5555, 0x5555,0x5555
};

 const unsigned short  data_word5[] = {
// 1
	0xaaaa,0xaaaa, 0xaaaa,0xaaaa,     0xaaaa,0xaaaa, 0xaaaa,0xaaaa,    0xaaaa,0xaaaa, 0xaaaa,0xaaaa,   0xaaaa,0xaaaa, 0xaaaa,0xaaaa,
    0xaaaa,0xaaaa, 0xaaaa,0xaaaa,     0xaaaa,0xaaaa, 0xaaaa,0xaaaa,    0xaaaa,0xaaaa, 0xaaaa,0xaaaa,   0xaaaa,0xaaaa, 0xaaaa,0xaaaa,
    0xaaaa,0xaaaa, 0xaaaa,0xaaaa,     0xaaaa,0xaaaa, 0xaaaa,0xaaaa,    0xaaaa,0xaaaa, 0xaaaa,0xaaaa,   0xaaaa,0xaaaa, 0xaaaa,0xaaaa,
    0xaaaa,0xaaaa, 0xaaaa,0xaaaa,     0xaaaa,0xaaaa, 0xaaaa,0xaaaa,    0xaaaa,0xaaaa, 0xaaaa,0xaaaa,   0xaaaa,0xaaaa, 0xaaaa,0xaaaa,
// 2		
    0xaaaa,0xaaaa, 0xaaaa,0xaaaa,     0xaaaa,0xaaaa, 0xaaaa,0xaaaa,    0xaaaa,0xaaaa, 0xaaaa,0xaaaa,   0xaaaa,0xaaaa, 0xaaaa,0xaaaa,
    0xaaaa,0xaaaa, 0xaaaa,0xaaaa,     0xaaaa,0xaaaa, 0xaaaa,0xaaaa,    0xaaaa,0xaaaa, 0xaaaa,0xaaaa,   0xaaaa,0xaaaa, 0xaaaa,0xaaaa,
    0xaaaa,0xaaaa, 0xaaaa,0xaaaa,     0xaaaa,0xaaaa, 0xaaaa,0xaaaa,    0xaaaa,0xaaaa, 0xaaaa,0xaaaa,   0xaaaa,0xaaaa, 0xaaaa,0xaaaa,
    0xaaaa,0xaaaa, 0xaaaa,0xaaaa,     0xaaaa,0xaaaa, 0xaaaa,0xaaaa,    0xaaaa,0xaaaa, 0xaaaa,0xaaaa,   0xaaaa,0xaaaa, 0xaaaa,0xaaaa
}; 

 /*
   //--------chapter.4-1 data----------
   unsigned short data_word4[] = {
// 1
	0x5a5a,0x5a5a, 0xa5a5,0xa5a5,     0x5a5a,0x5a5a, 0xa5a5,0xa5a5,    0x5a5a,0x5a5a, 0xa5a5,0xa5a5,   0x5a5a,0x5a5a, 0xa5a5,0xa5a5,
    0x5a5a,0x5a5a, 0xa5a5,0xa5a5,     0x5a5a,0x5a5a, 0xa5a5,0xa5a5,    0x5a5a,0x5a5a, 0xa5a5,0xa5a5,   0x5a5a,0x5a5a, 0xa5a5,0xa5a5,
	0x5a5a,0x5a5a, 0xa5a5,0xa5a5,     0x5a5a,0x5a5a, 0xa5a5,0xa5a5,    0x5a5a,0x5a5a, 0xa5a5,0xa5a5,   0x5a5a,0x5a5a, 0xa5a5,0xa5a5,
    0x5a5a,0x5a5a, 0xa5a5,0xa5a5,     0x5a5a,0x5a5a, 0xa5a5,0xa5a5,    0x5a5a,0x5a5a, 0xa5a5,0xa5a5,   0x5a5a,0x5a5a, 0xa5a5,0xa5a5,
// 2		
    0x5a5a,0x5a5a, 0xa5a5,0xa5a5,     0x5a5a,0x5a5a, 0xa5a5,0xa5a5,    0x5a5a,0x5a5a, 0xa5a5,0xa5a5,   0x5a5a,0x5a5a, 0xa5a5,0xa5a5,
    0x5a5a,0x5a5a, 0xa5a5,0xa5a5,     0x5a5a,0x5a5a, 0xa5a5,0xa5a5,    0x5a5a,0x5a5a, 0xa5a5,0xa5a5,   0x5a5a,0x5a5a, 0xa5a5,0xa5a5,
	0x5a5a,0x5a5a, 0xa5a5,0xa5a5,     0x5a5a,0x5a5a, 0xa5a5,0xa5a5,    0x5a5a,0x5a5a, 0xa5a5,0xa5a5,   0x5a5a,0x5a5a, 0xa5a5,0xa5a5,
    0x5a5a,0x5a5a, 0xa5a5,0xa5a5,     0x5a5a,0x5a5a, 0xa5a5,0xa5a5,    0x5a5a,0x5a5a, 0xa5a5,0xa5a5,   0x5a5a,0x5a5a, 0xa5a5,0xa5a5
};
*/
/*unsigned short data_word5[] = {
// 1
	  0x0000,0x0000, 0xffff,0xffff,     0x0000,0x0000, 0xffff,0xffff,    0x0000,0x0000, 0xffff,0xffff,   0x0000,0x0000, 0xffff,0xffff,
    0x0000,0x0000, 0xffff,0xffff,     0x0000,0x0000, 0xffff,0xffff,    0x0000,0x0000, 0xffff,0xffff,   0x0000,0x0000, 0xffff,0xffff,
	  0x0000,0x0000, 0xffff,0xffff,     0x0000,0x0000, 0xffff,0xffff,    0x0000,0x0000, 0xffff,0xffff,   0x0000,0x0000, 0xffff,0xffff,
    0x0000,0x0000, 0xffff,0xffff,     0x0000,0x0000, 0xffff,0xffff,    0x0000,0x0000, 0xffff,0xffff,   0x0000,0x0000, 0xffff,0xffff,
// 2		
    0x0000,0x0000, 0xffff,0xffff,     0x0000,0x0000, 0xffff,0xffff,    0x0000,0x0000, 0xffff,0xffff,   0x0000,0x0000, 0xffff,0xffff,
    0x0000,0x0000, 0xffff,0xffff,     0x0000,0x0000, 0xffff,0xffff,    0x0000,0x0000, 0xffff,0xffff,   0x0000,0x0000, 0xffff,0xffff,
	  0x0000,0x0000, 0xffff,0xffff,     0x0000,0x0000, 0xffff,0xffff,    0x0000,0x0000, 0xffff,0xffff,   0x0000,0x0000, 0xffff,0xffff,
    0x0000,0x0000, 0xffff,0xffff,     0x0000,0x0000, 0xffff,0xffff,    0x0000,0x0000, 0xffff,0xffff,   0x0000,0x0000, 0xffff,0xffff
};
*/
const unsigned short data_word6[] = {
//1	
	0xaaaa, 0xaaaa,0x5555,0x5555,    0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,  
  0xaaaa, 0xaaaa,0x5555,0x5555,    0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,  
	0xaaaa, 0xaaaa,0x5555,0x5555,    0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,  
  0xaaaa, 0xaaaa,0x5555,0x5555,    0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,
	//2
	0xaaaa, 0xaaaa,0x5555,0x5555,    0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,  
  0xaaaa, 0xaaaa,0x5555,0x5555,    0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,  
	0xaaaa, 0xaaaa,0x5555,0x5555,    0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,  
  0xaaaa, 0xaaaa,0x5555,0x5555,    0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,  0xaaaa, 0xaaaa,0x5555,0x5555,
};


