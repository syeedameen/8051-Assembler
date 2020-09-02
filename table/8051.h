

#ifndef _TABLE_8051_H
#define _TABLE_8051_H



enum {
    OP_NONE,            /* 1.   */
    OP_REG,             
    OP_AT_REG,
    OP_A,
    OP_C,
    OP_AB,
    OP_DPTR,
    OP_AT_A_PLUS_DPTR,      /* for index addressing a+dptr */
    OP_AT_A_PLUS_PC,        /* for index addressing a+pc */
    OP_AT_DPTR,             
    OP_DATA_16,             /* 16-bit immidate data */
    OP_CODE_ADDR,
    OP_BIT_ADDR,            /* bit address of  bit addressable register/field */
    OP_DATA,        
    OP_PAGE,                
    OP_RELADDR,             /* relative address */
    OP_SLASH_BIT_ADDR,
    OP_IRAM_ADDR
};

struct _table_8051
{
    char *name;         /* memonic name */
    char op[3];         /* opcode option */
    char range;         /* range of register or page number (r0,r1,r2,etc)*/
};

extern struct _table_8051 table_8051[];

#endif

