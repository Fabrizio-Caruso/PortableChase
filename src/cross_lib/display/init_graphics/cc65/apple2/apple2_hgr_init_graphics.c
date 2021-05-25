
/* Entry points
$F3D8 - HGR2
$F3E2 - HGR
$F605 - XDRAW
$F661 - DRAW
$F6E9 - HCOLOR
$F6FD - HPLOT
$F721 - ROT
$F727 - SCALE 
*/


#include "standard_libs.h"

#include "apple2_hgr_graphics.h"

#include <conio.h>
#include <peekpoke.h>

#include "7x8_chars.h"

uint16_t HB1[]={
0x2000, 0x2400, 0x2800, 0x2C00, 0x3000, 0x3400, 0x3800, 0x3C00,
0x2080, 0x2480, 0x2880, 0x2C80, 0x3080, 0x3480, 0x3880, 0x3C80,
0x2100, 0x2500, 0x2900, 0x2D00, 0x3100, 0x3500, 0x3900, 0x3D00,
0x2180, 0x2580, 0x2980, 0x2D80, 0x3180, 0x3580, 0x3980, 0x3D80,
0x2200, 0x2600, 0x2A00, 0x2E00, 0x3200, 0x3600, 0x3A00, 0x3E00,
0x2280, 0x2680, 0x2A80, 0x2E80, 0x3280, 0x3680, 0x3A80, 0x3E80,
0x2300, 0x2700, 0x2B00, 0x2F00, 0x3300, 0x3700, 0x3B00, 0x3F00,
0x2380, 0x2780, 0x2B80, 0x2F80, 0x3380, 0x3780, 0x3B80, 0x3F80,
0x2028, 0x2428, 0x2828, 0x2C28, 0x3028, 0x3428, 0x3828, 0x3C28,
0x20A8, 0x24A8, 0x28A8, 0x2CA8, 0x30A8, 0x34A8, 0x38A8, 0x3CA8,
0x2128, 0x2528, 0x2928, 0x2D28, 0x3128, 0x3528, 0x3928, 0x3D28,
0x21A8, 0x25A8, 0x29A8, 0x2DA8, 0x31A8, 0x35A8, 0x39A8, 0x3DA8,
0x2228, 0x2628, 0x2A28, 0x2E28, 0x3228, 0x3628, 0x3A28, 0x3E28,
0x22A8, 0x26A8, 0x2AA8, 0x2EA8, 0x32A8, 0x36A8, 0x3AA8, 0x3EA8,
0x2328, 0x2728, 0x2B28, 0x2F28, 0x3328, 0x3728, 0x3B28, 0x3F28,
0x23A8, 0x27A8, 0x2BA8, 0x2FA8, 0x33A8, 0x37A8, 0x3BA8, 0x3FA8,
0x2050, 0x2450, 0x2850, 0x2C50, 0x3050, 0x3450, 0x3850, 0x3C50,
0x20D0, 0x24D0, 0x28D0, 0x2CD0, 0x30D0, 0x34D0, 0x38D0, 0x3CD0,
0x2150, 0x2550, 0x2950, 0x2D50, 0x3150, 0x3550, 0x3950, 0x3D50,
0x21D0, 0x25D0, 0x29D0, 0x2DD0, 0x31D0, 0x35D0, 0x39D0, 0x3DD0,
0x2250, 0x2650, 0x2A50, 0x2E50, 0x3250, 0x3650, 0x3A50, 0x3E50,
0x22D0, 0x26D0, 0x2AD0, 0x2ED0, 0x32D0, 0x36D0, 0x3AD0, 0x3ED0,
0x2350, 0x2750, 0x2B50, 0x2F50, 0x3350, 0x3750, 0x3B50, 0x3F50,
0x23D0, 0x27D0, 0x2BD0, 0x2FD0, 0x33D0, 0x37D0, 0x3BD0, 0x3FD0};

// uint8_t hgr_enc[]={
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

const static uint8_t tiles[25][8] =
{
    _TILE_0_UDG,
    _TILE_1_UDG,
    _TILE_2_UDG,
    _TILE_3_UDG,
    _TILE_4_UDG,
    _TILE_5_UDG,
    _TILE_6_UDG,
    _TILE_7_UDG,    
    _TILE_8_UDG,
    _TILE_9_UDG,
    _TILE_10_UDG,
    _TILE_11_UDG,
    _TILE_12_UDG,
    _TILE_13_UDG,
    _TILE_14_UDG,
    _TILE_15_UDG,
    _TILE_16_UDG,
    _TILE_17_UDG,
    _TILE_18_UDG,
    _TILE_19_UDG,
    _TILE_20_UDG,
    _TILE_21_UDG,
    _TILE_22_UDG,
    _TILE_23_UDG,
    _TILE_24_UDG,
};



uint8_t hgr_enc[3*2*128] = 
{
0,0,0,64,0,16,0,80,0,4,0,68,0,20,0,84,0,1,0,65,0,17,0,81,0,5,0,69,0,21,0,85,32,0,32,64,32,16,32,80,32,4,32,68,32,20,32,84,32,1,32,65,32,17,32,81,32,5,32,69,32,21,32,85,8,0,8,64,8,16,8,80,8,4,8,68,8,20,8,84,8,1,8,65,8,17,8,81,8,5,8,69,8,21,8,85,40,0,40,64,40,16,40,80,40,4,40,68,40,20,40,84,40,1,40,65,40,17,40,81,40,5,40,69,40,21,40,85,2,0,2,64,2,16,2,80,2,4,2,68,2,20,2,84,2,1,2,65,2,17,2,81,2,5,2,69,2,21,2,85,34,0,34,64,34,16,34,80,34,4,34,68,34,20,34,84,34,1,34,65,34,17,34,81,34,5,34,69,34,21,34,85,10,0,10,64,10,16,10,80,10,4,10,68,10,20,10,84,10,1,10,65,10,17,10,81,10,5,10,69,10,21,10,85,42,0,42,64,42,16,42,80,42,4,42,68,42,20,42,84,42,1,42,65,42,17,42,81,42,5,42,69,42,21,42,85,

0,0,0,32,0,8,0,40,0,2,0,34,0,10,0,42,64,0,64,32,64,8,64,40,64,2,64,34,64,10,64,42,16,0,16,32,16,8,16,40,16,2,16,34,16,10,16,42,80,0,80,32,80,8,80,40,80,2,80,34,80,10,80,42,4,0,4,32,4,8,4,40,4,2,4,34,4,10,4,42,68,0,68,32,68,8,68,40,68,2,68,34,68,10,68,42,20,0,20,32,20,8,20,40,20,2,20,34,20,10,20,42,84,0,84,32,84,8,84,40,84,2,84,34,84,10,84,42,1,0,1,32,1,8,1,40,1,2,1,34,1,10,1,42,65,0,65,32,65,8,65,40,65,2,65,34,65,10,65,42,17,0,17,32,17,8,17,40,17,2,17,34,17,10,17,42,81,0,81,32,81,8,81,40,81,2,81,34,81,10,81,42,5,0,5,32,5,8,5,40,5,2,5,34,5,10,5,42,69,0,69,32,69,8,69,40,69,2,69,34,69,10,69,42,21,0,21,32,21,8,21,40,21,2,21,34,21,10,21,42,85,0,85,32,85,8,85,40,85,2,85,34,85,10,85,42,

0,0,0,96,0,24,0,120,0,6,0,102,0,30,0,126,64,1,64,97,64,25,64,121,64,7,64,103,64,31,64,127,48,0,48,96,48,24,48,120,48,6,48,102,48,30,48,126,112,1,112,97,112,25,112,121,112,7,112,103,112,31,112,127,12,0,12,96,12,24,12,120,12,6,12,102,12,30,12,126,76,1,76,97,76,25,76,121,76,7,76,103,76,31,76,127,60,0,60,96,60,24,60,120,60,6,60,102,60,30,60,126,124,1,124,97,124,25,124,121,124,7,124,103,124,31,124,127,3,0,3,96,3,24,3,120,3,6,3,102,3,30,3,126,67,1,67,97,67,25,67,121,67,7,67,103,67,31,67,127,51,0,51,96,51,24,51,120,51,6,51,102,51,30,51,126,115,1,115,97,115,25,115,121,115,7,115,103,115,31,115,127,15,0,15,96,15,24,15,120,15,6,15,102,15,30,15,126,79,1,79,97,79,25,79,121,79,7,79,103,79,31,79,127,63,0,63,96,63,24,63,120,63,6,63,102,63,30,63,126,127,1,127,97,127,25,127,121,127,7,127,103,127,31,127,127,
};

uint8_t mock_tile[8] = { 12,18,12,51,45,12,18,51 };

void hgr_draw(uint8_t x, uint8_t y, uint8_t tile, uint8_t color)
{
    uint8_t k;
    
    uint8_t extra_color = color>3;
    
    color = color-4*extra_color;
    
    extra_color<<=7;
    
    for(k=0;k<8;++k)
    {
        POKE(HB1[8*y+k]+2*x,hgr_enc[(uint16_t) (tiles[tile][k])*2u+((256U)*(color))]|extra_color);//(uint16_t) 256u*color]);
        POKE(HB1[8*y+k]+2*x+1,hgr_enc[(uint16_t)(tiles[tile][k])*2u+((256U)*(color))+1]|extra_color);//(uint16_t)256u*color+1]);
    }
}

void hgr_delete(uint8_t x, uint8_t y)
{
    uint8_t k;
    
    for(k=0;k<8;++k)
    {
        POKE(HB1[8*y+k]+2*x,0);
        POKE(HB1[8*y+k]+2*x+1,0);
    }
}

void _XL_INIT_GRAPHICS(void)
{
    // HIGH RES ON
    POKE(0xC057,0);

    // HGR PAGE 2
    // POKE(0xC055,0);

    // HGR PAGE 1
    POKE(0xC054,0);
 
    // TEXT OFF
    POKE(0xC050,0);
    
    // MIXED OFF
    POKE(0xC052,0);
    
    // foo(0,0,0,0);
    // cgetc();
    // foo(10,10,0,0);
    // cgetc();
    
    /*
    {
        uint8_t i;
        uint8_t j;
        uint8_t k;
        
        for(i=0;i<192;i+=8)
        {
            for(j=0;j<20;++j)
            {

                for(k=0;k<8;++k)
                {
                    POKE(HB1[i+k]+2*j,255);
                    POKE(HB1[i+k]+2*j+1,255);
                }
            }
            cgetc();
        }
    }    
    */
}
