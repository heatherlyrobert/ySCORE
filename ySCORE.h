/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YSCORE_HGUARD
#define YSCORE_HGUARD loaded



#include    <stdio.h>        /* C_ANSI : strcpy, strlen, strchr, strcmp, ...  */
#include    <ySTR_solo.h>



struct cSCORE_TABLE {
   char        s_label     [LEN_TERSE];
   char        s_default;
   char        s_sample;  
   char        s_print     [LEN_LABEL];  
   char        s_desc      [LEN_DESC];
   char        s_valid     [LEN_TITLE];
   char        s_legend    [LEN_FULL];
};
typedef   struct   cSCORE_TABLE   tSCORE_TABLE;

typedef  struct cSCORE  tSCORE;
struct cSCORE {
   tSCORE_TABLE  *m_table;                  /* data table                     */
   char           m_validity;               /* perform validity check         */
   short          m_max;                    /* maximum entries in table       */
   char           o_terse      [LEN_FULL];
   char           o_score      [LEN_FULL];
   char           o_full       [LEN_FULL];
   char           o_report     [LEN_FULL];
   char           o_poly       [LEN_FULL];
};


struct cSCORE_STATS {
   int         s_value;
   char        s_rating;
};
typedef   struct   cSCORE_STATS   tSCORE_STATS;




/*===[[ yENV_audit.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
char        ySCORE_audit            (tSCORE *a_cur);
/*---(done)-----------------*/



/*===[[ yENV_base.c ]]========================================================*/
/*········· ´······················ ´·········································*/
/*---(done)-----------------*/
char*       ySCORE_version          (void);
/*---(done)-----------------*/



/*===[[ yENV_mark.c ]]========================================================*/
/*········· ´······················ ´·········································*/
char        ySCORE_mark             (tSCORE *a_cur, char a_label [LEN_TERSE], uchar a_mark);
char        ySCORE_value            (tSCORE *a_cur, char a_label [LEN_TERSE]);
char        ySCORE_mask             (tSCORE *a_cur, char a_beg [LEN_TERSE], char a_end [LEN_TERSE]);
/*---(done)-----------------*/



/*===[[ yENV_mark.c ]]========================================================*/
/*········· ´······················ ´·········································*/
char        ySCORE_pos              (tSCORE *a_cur, char a_label [LEN_TERSE], short *r_index, short *r_tpos, short *r_spos, short *r_rpos, short *r_ppos);
/*---(done)-----------------*/



/*===[[ yENV_rptg.c ]]========================================================*/
/*---(output)-------------------------*/
char*       ySCORE_terse            (tSCORE *a_cur);
char*       ySCORE_score            (tSCORE *a_cur);
char*       ySCORE_full             (tSCORE *a_cur);
char*       ySCORE_report           (tSCORE *a_cur);
char*       ySCORE_poly             (tSCORE *a_cur);
char*       ySCORE_title            (tSCORE *a_cur, char a_type);
char*       ySCORE_header           (tSCORE *a_cur, char n);
char*       ySCORE_legend           (tSCORE *a_cur, char a_line, char a_label [LEN_TERSE]);
/*---(done)-----------------*/



/*===[[ yENV_table.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
/*---(program)------------------------*/
char        ySCORE_init             (tSCORE_TABLE *a_table, char a_validity, tSCORE **b_table);
char        ySCORE_clear            (tSCORE *b_cur);
char        ySCORE_wrap             (tSCORE **b_old);
/*---(done)-----------------*/



#endif
/*===[[ END ]]================================================================*/
