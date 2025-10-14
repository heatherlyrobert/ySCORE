/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YSCORE_HGUARD
#define YSCORE_HGUARD loaded



#include    <stdio.h>        /* C_ANSI : strcpy, strlen, strchr, strcmp, ...  */
#include    <ySTR_solo.h>



typedef   struct   cSCORE_TABLE   tSCORE_TABLE;
struct cSCORE_TABLE {
   char        s_label     [LEN_TERSE];
   char        s_default;
   char        s_sample;  
   char        s_print     [LEN_LABEL];  
   char        s_desc      [LEN_DESC];
   char        s_valid     [LEN_TITLE];
   char        s_legend    [LEN_FULL];
};


/*> struct cSCORE_STATS {                                                             <* 
 *>    int         s_value;                                                           <* 
 *>    char        s_rating;                                                          <* 
 *> };                                                                                <* 
 *> typedef   struct   cSCORE_STATS   tSCORE_STATS;                                   <*/




/*===[[ yENV_audit.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
char        ySCORE_audit            (void *a_cur);
/*---(done)-----------------*/



/*===[[ yENV_base.c ]]========================================================*/
/*········· ´······················ ´·········································*/
/*---(done)-----------------*/
char*       ySCORE_version          (void);
/*---(done)-----------------*/



/*===[[ yENV_mark.c ]]========================================================*/
/*········· ´······················ ´·········································*/
char        ySCORE_mark             (void *a_cur, char a_label [LEN_TERSE], uchar a_mark);
uchar       ySCORE_value            (void *a_cur, char a_label [LEN_TERSE]);
char        ySCORE_mask             (void *a_cur, char a_beg [LEN_TERSE], char a_end [LEN_TERSE]);
/*---(done)-----------------*/



/*===[[ yENV_mark.c ]]========================================================*/
/*········· ´······················ ´·········································*/
char        ySCORE_pos              (void *a_cur, char a_label [LEN_TERSE], short *r_index, short *r_tpos, short *r_spos, short *r_rpos, short *r_ppos);
/*---(done)-----------------*/



/*===[[ yENV_rptg.c ]]========================================================*/
/*---(output)-------------------------*/
char*       ySCORE_terse            (void *a_cur);
char*       ySCORE_score            (void *a_cur);
char*       ySCORE_full             (void *a_cur);
char*       ySCORE_report           (void *a_cur);
char*       ySCORE_poly             (void *a_cur);
char*       ySCORE_title            (void *a_cur, char a_type);
char*       ySCORE_header           (void *a_cur, char n);
char*       ySCORE_legend           (void *a_cur, char a_line, char a_label [LEN_TERSE]);
/*---(done)-----------------*/



/*===[[ yENV_table.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
/*---(program)------------------------*/
char        ySCORE_init             (tSCORE_TABLE *a_table, char a_validity, void **b_table);
char        ySCORE_clear            (void *b_cur);
char        ySCORE_wrap             (void **b_old);
/*---(done)-----------------*/



#endif
/*===[[ END ]]================================================================*/
