/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YSCORE_HGUARD
#define YSCORE_HGUARD loaded



#include    <stdio.h>        /* C_ANSI : strcpy, strlen, strchr, strcmp, ...  */
#include    <ySTR_solo.h>



struct cSCORE_TABLE {
   char        s_label     [LEN_TERSE];
   char        s_default;
   char        s_sample;  
   char        s_print     [LEN_TERSE];  
   char        s_desc      [LEN_DESC];
   char        s_valid     [LEN_LABEL];
   char        s_legend    [LEN_FULL];
};
typedef   struct   cSCORE_TABLE   tSCORE_TABLE;



/*===[[ yENV_base.c ]]========================================================*/
/*········· ´······················ ´·········································*/
/*---(done)-----------------*/





/*===[[ yENV_base.c ]]========================================================*/
/*········· ´······················ ´·········································*/
/*---(program)------------------------*/
char*       ySCORE_version          (void);
char        ySCORE_init             (tSCORE_TABLE *a_table);
char        ySCORE_clear            (void);



/*===[[ yENV_rptg.c ]]========================================================*/
/*---(output)-------------------------*/
char*       ySCORE_terse            (void);
char*       ySCORE_score            (void);
char*       ySCORE_full             (void);
char*       ySCORE_report           (void);
char*       ySCORE_poly             (void);





char        yENV_score_mark         (char a_label [LEN_TERSE], uchar a_mark);
char        yENV_score_value        (char a_label [LEN_TERSE]);

char*       yENV_score_title        (char a_type);
char*       yENV_score_header       (char n);

char        yENV_score_mask         (char a_beg [LEN_TERSE], char a_end [LEN_TERSE]);

char        yENV_score_audit        (void);




#endif
/*===[[ END ]]================================================================*/
