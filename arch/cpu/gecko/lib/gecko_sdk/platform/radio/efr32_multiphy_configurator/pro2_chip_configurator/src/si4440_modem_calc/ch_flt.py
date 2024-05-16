'''
Created on Jan 22, 2013

@author: sesuskic
'''

__all__ = ["ch_flt"]

def ch_flt(filter_k):
    chflt_coe_list = {
          1 : [-3,   -4,    1,   15,    30,    27,    -4,    -55,    -87,    -49,    81,    271,    442,    511], # 305k BW (decim-8*3) original PRO2
          # 1: [13    17 -8 -15 14 20    -27    -23    48 27 -94 -29 303 511 ]';   # 464k BW (decim-8*3, fil-1) for EZR2 tracking 
          # 1: [9 -6 -26 -35 -13 29 50 13 -64  -101 -15 192 415 511]'; # 378k BW (decim-8*3, fil-3) for EZR2 tracking 
          # 1: [-16 -9  8 34 51 38 -9 -69 -96 -44 95 284 447 511 ]';   # 302k BW (decim-8*3, fil-5) for EZR2 tracking 
          2 : [ 0,    3,   12,   22,    23,     5,   -34,    -72,    -75,    -11,   127,    304,    452,    511],
          3 : [ 4,   10,   17,   18,     5,   -22,   -55,    -71,    -47,     33,   160,    304,    417,    460],
          4 : [ 3,    7,    8,    2,   -14,   -37,   -57,    -56,    -18,     63,   175,    294,    385,    418],
          5 : [ 3,    3,    0,  -10,   -26,   -42,   -50,    -35,     11,     88,   186,    283,    356,    382],
          6 : [ 1,   -2,   -9,  -20,   -33,   -42,   -37,    -12,     37,    109,   192,    271,    327,    347],
          7 : [-3,  -10,  -19,  -29,   -36,   -36,   -20,     12,     63,    127,   195,    256,    299,    313],
          8 : [-5,  -10,  -18,  -24,   -26,   -20,    -1,     33,     80,    136,   194,    244,    279,    291],
          9 : [-4,   -8,  -14,  -17,   -17,    -8,    11,     43,     85,    134,   185,    228,    257,    268],
          10 : [-4,   -7,  -10,  -12,    -9,     1,    21,     51,     89,    134,   177,    215,    240,    249],
          11 : [-3,   -6,   -7,   -7,    -2,    10,    30,     58,     93,    132,   170,    202,    223,    231],
          #11: [2 13 26 50 83 126 179 240 304 367 424 469 498 508 ]'; # for ETSI class-1 169MHz 12.5k channel
          12 : [-3,   -3,   -3,   -1,     6,    19,    39,     65,     97,    130,   163,    190,    208,    214],
          13 : [-2,   -1,    0,    5,    14,    27,    47,     71,     99,    128,   156,    178,    193,    198],
          14 : [-1,    2,    5,    2,    22,    37,    55,     77,    101,    125,   147,    165,    176,    180],
          15 : [ 2,    6,   11,   20,    31,    46,    63,     82,    102,    121,   138,    151,    160,    162]
         }
    
    return [x+2**10 for x in chflt_coe_list.get(filter_k, chflt_coe_list[1])][::-1]

