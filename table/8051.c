/**
 * 8051 Assembler 
 * Author:  SYEED MOHD AMEEN                                                                      DATE: 01-09-2020
 * Email:   ameensyeed2@gmail.com
 * License: GNU GPLv3
*/

/************************************************************************************/
/*                             8051 OPCODE TABLE                                    */
/************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "8051.h"

struct _table_8051 table_8051[] = 
{
    /*  all 255 opcode for 8051 microcontroller */
    /*  memonic op1,op2,op3  */
    {"nop",     {OP_NONE,         OP_NONE,          OP_NONE},        -1},                 //0x00      nop 
    {"ajmp",    {OP_PAGE,         OP_NONE,          OP_NONE},         0},                 //0x01      ajmp page-address 
    {"ljmp",    {OP_CODE_ADDR,    OP_NONE,          OP_NONE},        -1},                 //0x02      ljmp 16-address
    {"rr",      {OP_A,            OP_NONE,          OP_NONE},        -1},                 //0x03      rr a
    {"inc",     {OP_A,            OP_NONE,          OP_NONE},        -1},                 //0x04      inc a 
    {"inc",     {OP_IRAM_ADDR,    OP_NONE,          OP_NONE},        -1},                 //0x05      inc direct_address 
    {"inc",     {OP_AT_REG,       OP_NONE,          OP_NONE},         0},                 //0x06      inc @r0
    {"inc",     {OP_AT_REG,       OP_NONE,          OP_NONE},         1},                 //0x07      inc @r1
    {"inc",     {OP_REG,          OP_NONE,          OP_NONE},         0},                 //0x08      inc r0
    {"inc",     {OP_REG,          OP_NONE,          OP_NONE},         1},                 //0x09      inc r1
    {"inc",     {OP_REG,          OP_NONE,          OP_NONE},         2},                 //0x0a      inc r2
    {"inc",     {OP_REG,          OP_NONE,          OP_NONE},         3},                 //0x0b      inc r3
    {"inc",     {OP_REG,          OP_NONE,          OP_NONE},         4},                 //0x0c      inc r4
    {"inc",     {OP_REG,          OP_NONE,          OP_NONE},         5},                 //0x0d      inc r5 
    {"inc",     {OP_REG,          OP_NONE,          OP_NONE},         6},                 //0x0e      inc r6 
    {"inc",     {OP_REG,          OP_NONE,          OP_NONE},         7},                 //0x0f      inc r7
    
    {"jbc",     {OP_BIT_ADDR,     OP_RELADDR,       OP_NONE},         -1},                //0x10      jbc bit-address relative-address 
    {"acall",   {OP_PAGE,         OP_NONE,          OP_NONE},          0},                //0x11      acall page-address 
    {"lcall",   {OP_CODE_ADDR,    OP_NONE,          OP_NONE},          1},                //0x12      lcall 16-address
    {"rrc",     {OP_A,            OP_NONE,          OP_NONE},         -1},                //0x13      rrc a 
    {"dec",     {OP_A,            OP_NONE,          OP_NONE},         -1},                //0x14      dec a
    {"dec",     {OP_IRAM_ADDR,    OP_NONE,          OP_NONE},         -1},                //0x15      dec direct-address 
    {"dec",     {OP_AT_REG,       OP_NONE,          OP_NONE},          0},                //0x16      dec @r0
    {"dec",     {OP_AT_REG,       OP_NONE,          OP_NONE},          1},                //0x17      dec @r1 
    {"dec",     {OP_REG,          OP_NONE,          OP_NONE},          0},                //0x18      dec r0 
    {"dec",     {OP_REG,          OP_NONE,          OP_NONE},          1},                //0x19      dec r1 
    {"dec",     {OP_REG,          OP_NONE,          OP_NONE},          2},                //0x1a      dec r2 
    {"dec",     {OP_REG,          OP_NONE,          OP_NONE},          3},                //0x1b      dec r3 
    {"dec",     {OP_REG,          OP_NONE,          OP_NONE},          4},                //0x1c      dec r4 
    {"dec",     {OP_REG,          OP_NONE,          OP_NONE},          5},                //0x1d      dec r5 
    {"dec",     {OP_REG,          OP_NONE,          OP_NONE},          6},                //0x1e      dec r6 
    {"dec",     {OP_REG,          OP_NONE,          OP_NONE},          7},                //0x1f      dec r7
    
    {"jb",      {OP_BIT_ADDR,     OP_RELADDR,       OP_NONE},         -1},              //0x20      jb bit-address,relative-address 
    {"ajmp",    {OP_PAGE,         OP_NONE,          OP_NONE},         -1},              //0x21      ajmp page-address 
    {"ret",     {OP_NONE,         OP_NONE,          OP_NONE},          1},              //0x22      ret 
    {"rl",      {OP_A,            OP_NONE,          OP_NONE},         -1},              //0x23      rl a 
    {"add",     {OP_A,            OP_DATA,          OP_NONE},         -1},              //0x24      add a,#data 
    {"add",     {OP_A,            OP_IRAM_ADDR,     OP_NONE},          1},              //0x25      add a,diret-address 
    {"add",     {OP_A,            OP_AT_REG,        OP_NONE},          0},              //0x26      add a,@r0
    {"add",     {OP_A,            OP_AT_REG,        OP_NONE},          1},              //0x27      add a,@r1 
    {"add",     {OP_A,            OP_REG,           OP_NONE},          0},              //0x28      add a,r0 
    {"add",     {OP_A,            OP_REG,           OP_NONE},          1},              //0x29      add a,r1 
    {"add",     {OP_A,            OP_REG,           OP_NONE},          2},              //0x2a      add a,r2 
    {"add",     {OP_A,            OP_REG,           OP_NONE},          3},              //0x2b      add a,r3 
    {"add",     {OP_A,            OP_REG,           OP_NONE},          4},              //0x2c      add a,r4 
    {"add",     {OP_A,            OP_REG,           OP_NONE},          5},              //0x2d      add a,r5 
    {"add",     {OP_A,            OP_REG,           OP_NONE},          6},              //0x2e      add a,r6 
    {"add",     {OP_A,            OP_REG,           OP_NONE},          7},              //0x2f      add a,r7 
    
    {"jnb",     {OP_BIT_ADDR,     OP_RELADDR,       OP_NONE},         -1},            //0x30      jnb bit-address relative-address 
    {"acall",   {OP_PAGE,         OP_NONE,          OP_NONE},         -1},            //0x31      acall page-address 
    {"reti",    {OP_NONE,         OP_NONE,          OP_NONE},         -1},            //0x32      reti     
    {"rlc",     {OP_A,            OP_NONE,          OP_NONE},         -1},            //0x33      rlc a
    {"addc",    {OP_A,            OP_DATA,          OP_NONE},         -1},            //0x34      addc a,#data 
    {"addc",    {OP_A,            OP_IRAM_ADDR,     OP_NONE},          0},            //0x35      addc a,direct-address 
    {"addc",    {OP_A,            OP_AT_REG,        OP_NONE},          0},            //0x36      addc a,@r0 
    {"addc",    {OP_A,            OP_AT_REG,        OP_NONE},          1},            //0x37      addc a,@r1 
    {"addc",    {OP_A,            OP_REG,           OP_NONE},          0},            //0x38      addc a,r0 
    {"addc",    {OP_A,            OP_REG,           OP_NONE},          1},            //0x39      addc a,r1 
    {"addc",    {OP_A,            OP_REG,           OP_NONE},          2},            //0x3a      addc a,r2 
    {"addc",    {OP_A,            OP_REG,           OP_NONE},          3},            //0x3b      addc a,r3 
    {"addc",    {OP_A,            OP_REG,           OP_NONE},          4},            //0x3c      addc a,r4 
    {"addc",    {OP_A,            OP_REG,           OP_NONE},          5},            //0x3d      addc a,r5 
    {"addc",    {OP_A,            OP_REG,           OP_NONE},          6},            //0x3e      addc a,r6 
    {"addc",    {OP_A,            OP_REG,           OP_NONE},          7},            //0x3f      addc a,r7
        
    {"jc",      {OP_BIT_ADDR,     OP_RELADDR,       OP_NONE},         -1},           //0x40      jc bit-address,relative-address 
    {"ajmp",    {OP_PAGE,         OP_NONE,          OP_NONE},         -1},           //0x41      ajmp page-address 
    {"orl",     {OP_IRAM_ADDR,    OP_A,             OP_NONE},         -1},           //0x42      orl direct-address,a 
    {"orl",     {OP_IRAM_ADDR,    OP_DATA,          OP_NONE},         -1},           //0x43      orl direct-address,#data 
    {"orl",     {OP_A,            OP_DATA,          OP_NONE},         -1},           //0x44      orl a,#data 
    {"orl",     {OP_A,            OP_IRAM_ADDR,     OP_NONE},         -1},           //0x45      orl a,direct-address
    {"orl",     {OP_A,            OP_AT_REG,        OP_NONE},          0},           //0x46      orl a,@r0 
    {"orl",     {OP_A,            OP_AT_REG,        OP_NONE},          1},           //0x47      orl a,@r1 
    {"orl",     {OP_A,            OP_REG,           OP_NONE},          0},           //0x48      orl a,r0 
    {"orl",     {OP_A,            OP_REG,           OP_NONE},          1},           //0x49      orl a,r1 
    {"orl",     {OP_A,            OP_REG,           OP_NONE},          2},           //0x4a      orl a,r2
    {"orl",     {OP_A,            OP_REG,           OP_NONE},          3},           //0x4b      orl a,r3 
    {"orl",     {OP_A,            OP_REG,           OP_NONE},          4},           //0x4c      orl a,r4 
    {"orl",     {OP_A,            OP_REG,           OP_NONE},          5},           //0x4d      orl a,r5 
    {"orl",     {OP_A,            OP_REG,           OP_NONE},          6},           //0x4e      orl a,r6 
    {"orl",     {OP_A,            OP_REG,           OP_NONE},          7},           //0x4f      orl a,r7 
    
    {"jnc",     {OP_RELADDR,      OP_NONE,          OP_NONE},         -1},           //0x50      jnc relative-address 
    {"acall",   {OP_PAGE,         OP_NONE,          OP_NONE},         -1},           //0x51      acall page-address 
    {"anl",     {OP_IRAM_ADDR,    OP_A,             OP_NONE},         -1},           //0x52      anl direct-address,a 
    {"anl",     {OP_IRAM_ADDR,    OP_DATA,          OP_NONE},         -1},           //0x53      anl direct-address,#data
    {"anl",     {OP_A,            OP_DATA,          OP_NONE},         -1},           //0x54      anl a,#data
    {"anl",     {OP_A,            OP_IRAM_ADDR,     OP_NONE},         -1},           //0x55      anl a,direct-address
    {"anl",     {OP_A,            OP_AT_REG,        OP_NONE},          0},           //0x56      anl a,@r0
    {"anl",     {OP_A,            OP_AT_REG,        OP_NONE},          1},           //0X57      anl a,@r1
    {"anl",     {OP_A,            OP_REG,           OP_NONE},          0},           //0x58      anl a,r0 
    {"anl",     {OP_A,            OP_REG,           OP_NONE},          1},           //0x59      anl a,r1 
    {"anl",     {OP_A,            OP_REG,           OP_NONE},          2},           //0x5a      anl a,r2 
    {"anl",     {OP_A,            OP_REG,           OP_NONE},          3},           //0x5b      anl a,r3 
    {"anl",     {OP_A,            OP_REG,           OP_NONE},          4},           //0x5c      anl a,r4 
    {"anl",     {OP_A,            OP_REG,           OP_NONE},          5},           //0x5d      anl a,r5 
    {"anl",     {OP_A,            OP_REG,           OP_NONE},          6},           //0x5e      anl a       ,r6 
    {"anl",     {OP_A,            OP_REG,           OP_NONE},          7},           //0x5f      anl a,r7 
    
    {"jz",      {OP_RELADDR,       OP_NONE,         OP_NONE},         -1},           //0x60      jz relative-address 
    {"ajmp",    {OP_PAGE,          OP_NONE,         OP_NONE},         -1},           //0x61      ajmp page-address 
    {"xrl",     {OP_IRAM_ADDR,     OP_A,            OP_NONE},         -1},           //0x62      xrl direct-address,a
    {"xrl",     {OP_IRAM_ADDR,     OP_DATA,         OP_NONE},         -1},           //0x63      xrl direct-address,#data
    {"xrl",     {OP_A,             OP_DATA,         OP_NONE},         -1},           //0x64      xrl a,#data
    {"xrl",     {OP_A,             OP_IRAM_ADDR,    OP_NONE},         -1},           //0x65      xrl a,direct-address 
    {"xrl",     {OP_A,             OP_AT_REG,       OP_NONE},          0},           //0x66      xrl a,@r0
    {"xrl",     {OP_A,             OP_AT_REG,       OP_AT_REG},        1},           //0x67      xrl a,@r1 
    {"xrl",     {OP_A,             OP_REG,          OP_NONE},          0},           //0x68      xrl a,r0 
    {"xrl",     {OP_A,             OP_REG,          OP_NONE},          1},           //0x69      xrl a,r1 
    {"xrl",     {OP_A,             OP_REG,          OP_NONE},          2},           //0x6a      xrl a,r2 
    {"xrl",     {OP_A,             OP_REG,          OP_NONE},          3},           //0x6b      xrl a,r3 
    {"xrl",     {OP_A,             OP_REG,          OP_NONE},          4},           //0x6c      xrl a,r4 
    {"xrl",     {OP_A,             OP_REG,          OP_NONE},          5},           //0x6d      xrl a,r5 
    {"xrl",     {OP_A,             OP_REG,          OP_NONE},          6},           //0x6e      xrl a,r6 
    {"xrl",     {OP_A,             OP_REG,          OP_NONE},          7},           //0x6f      xrl a,r7 
    
    {"jnz",     {OP_RELADDR,       OP_NONE,         OP_NONE},         -1},          //0x70      jnz realtive-address 
    {"acall",   {OP_PAGE,          OP_NONE,         OP_NONE},         -1},          //0x71      acalll page-address 
    {"orl",     {OP_C,             OP_BIT_ADDR,     OP_NONE},         -1},          //0x72      orl c bit-address 
    {"jmp",     {OP_AT_A_PLUS_DPTR,OP_NONE,         OP_NONE},         -1},          //0x73      jmp @a+dptr
    {"mov",     {OP_A,             OP_DATA,         OP_NONE},         -1},          //0x74      mov a,#data
    {"mov",     {OP_IRAM_ADDR,     OP_DATA,         OP_NONE},         -1},          //0x75      mov direct-address,#data 
    {"mov",     {OP_AT_REG,        OP_DATA,         OP_NONE},          0},          //0x76      mov @r0,#data
    {"mov",     {OP_AT_REG,        OP_DATA,         OP_NONE},          1},          //0x77      mov @r1,#data 
    {"mov",     {OP_REG,           OP_DATA,         OP_NONE},          0},          //0x78      mov r0,#data
    {"mov",     {OP_REG,           OP_DATA,         OP_NONE},          1},          //0x79      mov r1,#data 
    {"mov",     {OP_REG,           OP_DATA,         OP_NONE},          2},          //0x7a      mov r2,#data
    {"mov",     {OP_REG,           OP_DATA,         OP_NONE},          3},          //0x7b      mov r3,#data
    {"mov",     {OP_REG,           OP_DATA,         OP_NONE},          4},          //0x7c      mov r4,#data 
    {"mov",     {OP_REG,           OP_DATA,         OP_NONE},          5},          //0x7d      mov r5,#data 
    {"mov",     {OP_REG,           OP_DATA,         OP_NONE},          6},          //0x7e      mov r6,#data 
    {"mov",     {OP_REG,           OP_DATA,         OP_NONE},          7},          //0x7f      mov r7,#data

    {"sjmp",    {OP_RELADDR,    OP_NONE,            OP_NONE},         -1},          //0x80      sjmp relative-address 
    {"ajmp",    {OP_PAGE,       OP_NONE,            OP_NONE},         -1},          //0x81      ajmp page-address 
    {"anl",     {OP_C,          OP_BIT_ADDR,        OP_NONE},         -1},          //0x82      anl c,bit-address 
    {"movc",    {OP_A,          OP_AT_A_PLUS_PC,    OP_NONE},         -1},          //0x83      movc a,@a+pc
    {"div",     {OP_AB,         OP_NONE,            OP_NONE},         -1},          //0x84      div ab 
    {"mov",     {OP_IRAM_ADDR,  OP_IRAM_ADDR,       OP_NONE},         -1},          //0x85      mov direct-address,direct-address 
    {"mov",     {OP_IRAM_ADDR,  OP_AT_REG,          OP_NONE},          0},          //0x86      mov direct-address,@r0
    {"mov",     {OP_IRAM_ADDR,  OP_AT_REG,          OP_NONE},          1},          //0x87      mov direct-address,@r1 
    {"mov",     {OP_IRAM_ADDR,  OP_REG,             OP_NONE},          0},          //0x88      mov direct-address,r0 
    {"mov",     {OP_IRAM_ADDR,  OP_REG,             OP_NONE},          1},          //0x89      mov direct-address,r1 
    {"mov",     {OP_IRAM_ADDR,  OP_REG,             OP_NONE},          2},          //0x8a      mov direct-address,r2 
    {"mov",     {OP_IRAM_ADDR,  OP_REG,             OP_NONE},          3},          //0x8b      mov direct-address,r3 
    {"mov",     {OP_IRAM_ADDR,  OP_REG,             OP_NONE},          4},          //0x8c      mov direct-address,r4 
    {"mov",     {OP_IRAM_ADDR,  OP_REG,             OP_NONE},          5},          //0x8d      mov direct-address,r5 
    {"mov",     {OP_IRAM_ADDR,  OP_REG,             OP_NONE},          6},          //0x8e      mov direct-address,r6 
    {"mov",     {OP_IRAM_ADDR,  OP_REG,             OP_NONE},          7},          //0x8f      mov direct-address,r7 

    {"mov",     {OP_DPTR,       OP_DATA_16,         OP_NONE},         -1},         //0x90      mov dptr,#16-data
    {"acall",   {OP_PAGE,       OP_NONE,            OP_NONE},         -1},         //0x91      acall page-address 
    {"mov",     {OP_BIT_ADDR,   OP_C,               OP_NONE},         -1},         //0x92      mov bit-address,carry
    {"movc",    {OP_A,          OP_AT_A_PLUS_DPTR,  OP_NONE},         -1},         //0x93      movc a,@a+dptr
    {"subb",    {OP_A,          OP_DATA,            OP_NONE},         -1},         //0x94      subb a,#data
    {"subb",    {OP_A,          OP_IRAM_ADDR,       OP_NONE},         -1},         //0x95      subb a,direct-address 
    {"subb",    {OP_A,          OP_AT_REG,          OP_NONE},          0},         //0x96      subb a,@r0
    {"subb",    {OP_A,          OP_AT_REG,          OP_NONE},          1},         //0x97      subb a,@r1
    {"subb",    {OP_A,          OP_REG,             OP_NONE},          0},         //0x98      subb a,r0
    {"subb",    {OP_A,          OP_REG,             OP_NONE},          1},         //0x99      subb a,r1 
    {"subb",    {OP_A,          OP_REG,             OP_NONE},          2},         //0x9a      subb a,r2 
    {"subb",    {OP_A,          OP_REG,             OP_NONE},          3},         //0x9b      subb a,r3 
    {"subb",    {OP_A,          OP_REG,             OP_NONE},          4},         //0x9c      subb a,r4 
    {"subb",    {OP_A,          OP_REG,             OP_NONE},          5},         //0x9d      subb a,r5 
    {"subb",    {OP_A,          OP_REG,             OP_NONE},          6},         //0x9e      subb a,r6 
    {"subb",    {OP_A,          OP_REG,             OP_NONE},          7},         //0x9f      subb a, r7 

    {"orl",     {OP_C,          OP_BIT_ADDR,        OP_NONE},         -1},        //0xa0      orl c,bit-address
    {"ajmp",    {OP_PAGE,       OP_PAGE,            OP_NONE},         -1},        //0xa1      ajmp page-address
    {"mov",     {OP_C,          OP_BIT_ADDR,        OP_NONE},         -1},        //0xa2      mov c,bit-address
    {"inc",     {OP_DPTR,       OP_NONE,            OP_NONE},         -1},        //0xa3      inc dptr
    {"mul",     {OP_AB,         OP_NONE,            OP_NONE},         -1},        //0xa4      mul ab 
    {""},                                                                         //0xa5      
    {"mov",     {OP_AT_REG,     OP_IRAM_ADDR,       OP_NONE},          0},        //0xa6      mov @r0,direct-address 
    {"mov",     {OP_AT_REG,     OP_IRAM_ADDR,       OP_NONE},          1},        //0xa7      mov @r1,direct-address 
    {"mov",     {OP_REG,        OP_IRAM_ADDR,       OP_NONE},          0},        //0xa8      mov r0,direct-address
    {"mov",     {OP_REG,        OP_IRAM_ADDR,       OP_NONE},          1},        //0xa9      mov r1,direct-address 
    {"mov",     {OP_REG,        OP_IRAM_ADDR,       OP_NONE},          2},        //0xaa      mov r2,direct-address 
    {"mov",     {OP_REG,        OP_IRAM_ADDR,       OP_NONE},          3},        //0xab      mov r3,direct-address
    {"mov",     {OP_REG,        OP_IRAM_ADDR,       OP_NONE},          4},        //0xac      mov r4,direct-address 
    {"mov",     {OP_REG,        OP_IRAM_ADDR,       OP_NONE},          5},        //0xad      mov r5,direct-address 
    {"mov",     {OP_REG,        OP_IRAM_ADDR,       OP_NONE},          6},        //0xae      mov r6,direct-address 
    {"mov",     {OP_REG,        OP_IRAM_ADDR,       OP_NONE},          7},        //0xaf      mov r7,direct-  address

    {"anl",     {OP_C,          OP_BIT_ADDR,        OP_NONE},         -1},        //0xb0      anl c,bit-address 
    {"acall",   {OP_PAGE,       OP_NONE,            OP_NONE},          0},        //0xb1      acall page-addrss 
    {"cpl",     {OP_BIT_ADDR,   OP_NONE,            OP_NONE},         -1},        //0xb2      cpl bit-address 
    {"cpl",     {OP_C,          OP_NONE,            OP_NONE},         -1},        //0xb3      cpl c
    {"cjne",    {OP_A,          OP_DATA,            OP_RELADDR},      -1},        //0xb4      cjne a,#data,relative-address
    {"cjne",    {OP_A,          OP_IRAM_ADDR,       OP_NONE},         -1},        //0xb5      cjne a,direct-address,relative-address 
    {"cjne",    {OP_AT_REG,     OP_DATA,            OP_RELADDR},       0},        //0xb6      cjne @r0,#data,relative-address
    {"cjne",    {OP_AT_REG,     OP_DATA,            OP_RELADDR},       1},        //0xb7      cjne @r1,#data,relative-address
    {"cjne",    {OP_REG,        OP_DATA,            OP_RELADDR},       0},        //0xb8      cjne r0,#data,relative-address
    {"cjne",    {OP_REG,        OP_DATA,            OP_RELADDR},       1},        //0xb9      cjne r1,#data,relative-address
    {"cjne",    {OP_REG,        OP_DATA,            OP_RELADDR},       2},        //0xba      cjne r2,#data,relative-address 
    {"cjne",    {OP_REG,        OP_DATA,            OP_RELADDR},       3},        //0xbb      cjne r3,#data,reletive-address 
    {"cjne",    {OP_REG,        OP_DATA,            OP_RELADDR},       4},        //0xbc      cjne r4,#data,relative-address
    {"cjne",    {OP_REG,        OP_DATA,            OP_RELADDR},       5},        //0xbd      cjne r5,#data,relative-address
    {"cjne",    {OP_REG,        OP_DATA,            OP_RELADDR},       6},        //0xbe      cjne r6,#data,relative-address
    {"cjne",    {OP_REG,        OP_DATA,            OP_RELADDR},       7},        //0xbf      cjne r7,#data,relative- address

    {"push",    {OP_IRAM_ADDR,  OP_NONE,            OP_NONE},         -1},        //0xc0      push direct-address
    {"ajmp",    {OP_PAGE,       OP_NONE,            OP_NONE},         -1},        //0xc1      ajmp page-address
    {"clr",     {OP_BIT_ADDR,   OP_NONE,            OP_NONE},         -1},        //0xc2      clr bit-address
    {"clr",     {OP_C,          OP_NONE,            OP_NONE},         -1},        //0xc3      clr c 
    {"swap",    {OP_A,          OP_NONE,            OP_NONE},         -1},        //0xc4      swap a
    {"xch",     {OP_A,          OP_IRAM_ADDR,       OP_NONE},        -1},         //0xc5      xch a,direct-address
    {"xch",     {OP_A,          OP_AT_REG,          OP_NONE},          0},        //0xc6      xch a,@r0 
    {"xch",     {OP_A,          OP_AT_REG,          OP_NONE},          1},        //0xc7      xch a,@r1
    {"xch",     {OP_A,          OP_REG,             OP_NONE},          0},        //0xc8      xch a,r0
    {"xch",     {OP_A,          OP_REG,             OP_NONE},          1},        //0xc9      xch a,r1 
    {"xch",     {OP_A,          OP_REG,             OP_NONE},          2},        //0xca      xch a,r2 
    {"xch",     {OP_A,          OP_REG,             OP_NONE},          3},        //0xcb      xch a,r3 
    {"xch",     {OP_A,          OP_REG,             OP_NONE},          4},        //0xcc      xch a,r4 
    {"xch",     {OP_A,          OP_REG,             OP_NONE},          5},        //0xcd      xch a,r5 
    {"xch",     {OP_A,          OP_REG,             OP_NONE},          6},        //0xce      xch a,r6 
    {"xch",     {OP_A,          OP_REG,             OP_NONE},          7},        //0xcf      xc  h a,r7
    {"pop",     {OP_IRAM_ADDR,  OP_NONE,            OP_NONE},         -1},        //0xd0      pop direct-address
    {"acall",   {OP_PAGE,       OP_NONE,            OP_NONE},         -1},        //0xd1      acall page-address 
    {"setb",    {OP_BIT_ADDR,   OP_NONE,            OP_NONE},         -1},        //0xd2      setb bit-address 
    {"setb",    {OP_C,          OP_NONE,            OP_NONE},         -1},        //0xd3      setb c 
    {"da",      {OP_A,          OP_NONE,            OP_NONE},         -1},        //0xd4      da a 
    {"djnz",    {OP_IRAM_ADDR,  OP_RELADDR,         OP_NONE},         -1},        //0xd5      djnz direct-address,relative-address
    {"xchd",    {OP_A,          OP_AT_REG,          OP_NONE},          0},        //0xd6      xchd a,@r0 
    {"xchd",    {OP_A,          OP_AT_REG,          OP_NONE},          1},        //0xd7      xchd a,@r1
    {"djnz",    {OP_REG,        OP_RELADDR,         OP_NONE},          0},        //0xd8      djnz r0,relative-address
    {"djnz",    {OP_REG,        OP_RELADDR,         OP_NONE},          1},        //0xd9      djnz r1,relative-address 
    {"djnz",    {OP_REG,        OP_RELADDR,         OP_NONE},          2},        //0xda      djnz r2,relative-address
    {"djnz",    {OP_REG,        OP_RELADDR,         OP_NONE},          3},        //0xdb      djnz r3,relative-address 
    {"djnz",    {OP_REG,        OP_RELADDR,         OP_NONE},          4},        //0xdc      djnz r4,relative-address
    {"djnz",    {OP_REG,        OP_RELADDR,         OP_NONE},          5},        //0xdd      djnz r5,relative-address 
    {"djnz",    {OP_REG,        OP_RELADDR,         OP_NONE},          6},        //0xde      djnz r6,relative-address
    {"djnz",    {OP_REG,        OP_RELADDR,         OP_NONE},          7},        //0xdf      djnz r7,relative-   address

    {"movx",    {OP_A,          OP_DPTR,            OP_NONE},         -1},        //0xe0      movx a,@dptr
    {"ajmp",    {OP_PAGE,       OP_NONE,            OP_NONE},         -1},        //0xe1      ajmp page-address
    {"movx",    {OP_A,          OP_AT_REG,          OP_NONE},          0},        //0xe2      movx a,@r0 
    {"movx",    {OP_A,          OP_AT_REG,          OP_NONE},          1},        //0xe3      movx a,@r1
    {"clr",     {OP_A,          OP_NONE,            OP_NONE},         -1},        //0xe4      clr a 
    {"mov",     {OP_A,          OP_IRAM_ADDR,       OP_NONE},         -1},        //0xe5      mov a,direct-address
    {"mov",     {OP_A,          OP_AT_REG,          OP_NONE},          0},        //0xe6      mov a,@r0
    {"mov",     {OP_A,          OP_AT_REG,          OP_NONE},          1},        //0xe7      mov a,@r1
    {"mov",     {OP_A,          OP_REG,             OP_NONE},          0},        //0xe8      mov a,r0 
    {"mov",     {OP_A,          OP_REG,             OP_NONE},          1},        //0xe9      mov a,r1 
    {"mov",     {OP_A,          OP_REG,             OP_NONE},          2},        //0xea      mov a,r2 
    {"mov",     {OP_A,          OP_REG,             OP_NONE},          3},        //0xeb      mov a,r3 
    {"mov",     {OP_A,          OP_REG,             OP_NONE},          4},        //0xec      mov a,r4 
    {"mov",     {OP_A,          OP_REG,             OP_NONE},          5},        //0xed      mov a,r5 
    {"mov",     {OP_A,          OP_REG,             OP_NONE},          6},        //0xee      mov a,r6 
    {"mov",     {OP_A,          OP_REG,             OP_NONE},          7},        //0xef      mo  v a,r7 

    {"movx",    {OP_AT_DPTR,    OP_A,               OP_NONE},         -1},        //0xf0      movx @dptr,a 
    {"acall",   {OP_PAGE,       OP_NONE,            OP_NONE},         -1},        //0xf1      acall page-address 
    {"movx",    {OP_AT_REG,     OP_A,               OP_NONE},          0},        //0xf2      movx @r0,a 
    {"movx",    {OP_AT_REG,     OP_A,               OP_NONE},          1},        //0xf3      movx @r1,a 
    {"cpl",     {OP_A,          OP_NONE,            OP_NONE},         -1},        //0xf4      cpl a
    {"mov",     {OP_IRAM_ADDR,  OP_A,               OP_NONE},         -1},        //0xf5      mov direct-address,a
    {"mov",     {OP_AT_REG,     OP_A,               OP_NONE},          0},        //0xf6      mov @r0,a 
    {"mov",     {OP_AT_REG,     OP_A,               OP_NONE},          1},        //0xf7      mov @r1,a  
    {"mov",     {OP_REG,        OP_A,               OP_NONE},          0},        //0xf8      mov r0,a 
    {"mov",     {OP_REG,        OP_A,               OP_NONE},          1},        //0xf9      mov r1,a 
    {"mov",     {OP_REG,        OP_A,               OP_NONE},          2},        //0xfa      mov r2,a 
    {"mov",     {OP_REG,        OP_A,               OP_NONE},          3},        //0xfb      mov r3,a 
    {"mov",     {OP_REG,        OP_A,               OP_NONE},          4},        //0xfc      mov r4,a 
    {"mov",     {OP_REG,        OP_A,               OP_NONE},          5},        //0xfd      mov r5,a 
    {"mov",     {OP_REG,        OP_A,               OP_NONE},          6},        //0xfe      mov r6,a 
    {"mov",     {OP_REG,        OP_A,               OP_NONE},          7},        //0xff      mov r7,a 
        

};