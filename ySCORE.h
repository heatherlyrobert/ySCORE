/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YENV_HGUARD
#define YENV_HGUARD loaded



#include    <stdio.h>        /* C_ANSI : strcpy, strlen, strchr, strcmp, ...  */
#include    <ySTR_solo.h>



struct cENV_SCORE {
   char        s_label     [LEN_TERSE];
   char        s_default;
   char        s_sample;  
   char        s_print     [LEN_TERSE];  
   char        s_desc      [LEN_DESC];
   char        s_legend    [LEN_FULL];
};
typedef   struct   cENV_SCORE   tENV_SCORE;



/*===[[ yENV_base.c ]]========================================================*/
/*········· ´······················ ´·········································*/
char*       ySCORE_version          (void);
/*---(done)-----------------*/





/*===[[ yENV_score.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
char        yENV_score_init         (tENV_SCORE *a_table);
char        yENV_score_clear        (void);

char*       yENV_score_terse        (void);
char*       yENV_score              (void);
char*       yENV_score_full         (void);
char*       yENV_score_report       (void);

char        yENV_score_pos          (char a_label [LEN_TERSE], short *r_norm, short *r_terse, short *r_report);
char        yENV_score_mark         (char a_label [LEN_TERSE], uchar a_mark);
char        yENV_score_value        (char a_label [LEN_TERSE]);

char*       yENV_score_title        (char a_type);
char*       yENV_score_header       (char n);

char        yENV_score_mask         (char a_beg [LEN_TERSE], char a_end [LEN_TERSE]);

char        yENV_score_audit        (void);


#endif
/*===[[ END ]]================================================================*/
