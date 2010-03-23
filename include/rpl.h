#ifndef _RPL_H_

#define ND_RPL_MESSAGE 0x9B

enum ND_RPL_CODE {
        ND_RPL_DAG_IS=0x01,
        ND_RPL_DAG_IO=0x02,
        ND_RPL_DAO   =0x04
};

enum ND_RPL_DIO_FLAGS {
        ND_RPL_DIO_GROUNDED = 0x80,
        ND_RPL_DIO_DATRIG   = 0x40,
        ND_RPL_DIO_DASUPPORT= 0x20,
        ND_RPL_DIO_RES4     = 0x10,
        ND_RPL_DIO_RES3     = 0x08,
        ND_RPL_DIO_PRF_MASK = 0x07,  /* 3-bit preference */
};

#define DAGID_LEN 16

struct nd_rpl_dio {
        u_int8_t rpl_flags;
        u_int8_t rpl_seq;
        u_int8_t rpl_instanceid;
        u_int8_t rpl_dagrank;
        u_int8_t rpl_dagid[DAGID_LEN];
};

enum RPL_DIO_SUBOPT {
        RPL_DIO_PAD0 = 0,
        RPL_DIO_PADN = 1,
        RPL_DIO_METRICS = 2,
        RPL_DIO_DESTPREFIX=3,
};

#define RPL_DIO_LIFETIME_INFINITE   0xffffffff
#define RPL_DIO_LIFETIME_DISCONNECT 0

struct rpl_dio_destprefix {
        u_int8_t rpl_dio_type;
        u_int8_t rpl_dio_lenh;  /* easier to have two bytes */
        u_int8_t rpl_dio_lenl;  /* than to play with packing options */
        u_int8_t rpl_dio_prf;
        u_int32_t rpl_dio_prefixlifetime;  /* in seconds */
        u_int8_t rpl_dio_prefixlen;        /* in bits */
        u_int8_t rpl_dio_prefix[1];        /* variables number of bytes */
};


#define _RPL_H_
#endif /* _RPL_H_ */

/*
 * Local Variables:
 * c-basic-offset:4
 * c-style: whitesmith
 * End:
 */

