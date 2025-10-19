/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YSCORE_HGUARD
#define YSCORE_HGUARD loaded



#include    <stdio.h>        /* C_ANSI : strcpy, strlen, strchr, strcmp, ...  */
#include    <ySTR_solo.h>



typedef   struct   cySCORE_TB    tySCORE_TB;
struct cySCORE_TB {
   char        s_label     [LEN_TERSE];     /* unique label for functions     */
   char        s_default;                   /* default/unused symbol          */
   char        s_sample;                    /* common code for sample report  */
   char        s_print     [LEN_LABEL];     /* text for vertical header       */
   char        s_desc      [LEN_DESC];      /* description for legend         */
   char        s_style;                     /* how to convert to value shown  */
   char        s_check;                     /* use validity for this item     */
   char        s_valid     [LEN_TITLE];     /* valid code specification       */
   char        s_legend    [LEN_FULL];      /* detailed text for legend       */
};



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
/*---(special)--------------*/
char        ySCORE_exists           (void *a_cur, char a_label [LEN_TERSE], int a_src);
char        ySCORE_flag             (void *a_cur, char a_label [LEN_TERSE], int a_src);
char        ySCORE_exact            (void *a_cur, char a_label [LEN_TERSE], int a_src);
char        ySCORE_scaled           (void *a_cur, char a_label [LEN_TERSE], int a_src);
char        ySCORE_percent          (void *a_cur, char a_label [LEN_TERSE], int a_part, int a_total);
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
char        ySCORE_init             (tySCORE_TB *a_table, char a_validity, void **b_table);
char        ySCORE_clear            (void *b_cur);
char        ySCORE_wrap             (void **b_old);
/*---(done)-----------------*/



/*===[[ yENV_stats.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
/*---(clear)----------------*/
char        ySCORE_stats_clear      (void *a_cur);
/*---(set)------------------*/
char        ySCORE_stats_set        (void *a_cur, char a_label [LEN_TERSE], uchar a_stat);
/*---(more)-----------------*/
char        ySCORE_stats_inc        (void *a_cur, char a_label [LEN_TERSE]);
char        ySCORE_stats_add        (void *a_cur, char a_label [LEN_TERSE], uchar a_stat);
/*---(less)-----------------*/
char        ySCORE_stats_dec        (void *a_cur, char a_label [LEN_TERSE]);
char        ySCORE_stats_sub        (void *a_cur, char a_label [LEN_TERSE], uchar a_stat);
/*---(debugging)------------*/
char*       ySCORE_stats_show       (void *a_cur);
/*---(done)-----------------*/



#endif
/*===[[ END ]]================================================================*/
