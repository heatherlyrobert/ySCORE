/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YSCORE_HGUARD
#define YSCORE_HGUARD loaded



/*===[[ GNU GENERAL PUBLIC LICENSE (GPL) ]]===================================*/
/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */

#define  P_COPYRIGHT   \
   "copyright (c) 2025 robert.s.heatherly at balsashrike at gmail dot com"

#define  P_LICENSE     \
   "the only place you could have gotten this code is my github, my website,¦"   \
   "or illegal sharing. given that, you should be aware that this is GPL licensed."

#define  P_COPYLEFT    \
   "the GPL COPYLEFT REQUIREMENT means any modifications or derivative works¦"   \
   "must be released under the same GPL license, i.e, must be free and open."

#define  P_INCLUDE     \
   "the GPL DOCUMENTATION REQUIREMENT means that you must include the original¦" \
   "copyright notice and the full licence text with any resulting anything."

#define  P_AS_IS       \
   "the GPL NO WARRANTY CLAUSE means the software is provided without any¦"      \
   "warranty and the author cannot be held liable for damages."

#define  P_THEFT    \
   "if you knowingly violate the spirit of these ideas, i suspect you might¦"    \
   "find any number of freedom-minded hackers may take it quite personally ;)"

/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
/*===[[ GNU GENERAL PUBLIC LICENSE (GPL) ]]===================================*/



#include    <stdio.h>        /* C_ANSI : strcpy, strlen, strchr, strcmp, ...  */
#include    <ySTR_solo.h>



typedef   struct   cySCORE_TB    tySCORE_TB;
struct cySCORE_TB {
   char        s_shown;                     /* visible vs internal use only   */
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
char        ySCORE_audit            (void *v_hand);
/*---(done)-----------------*/



/*===[[ yENV_base.c ]]========================================================*/
/*········· ´······················ ´·········································*/
/*---(done)-----------------*/
char*       ySCORE_version          (void);
/*---(done)-----------------*/



/*===[[ yENV_mark.c ]]========================================================*/
/*········· ´······················ ´·········································*/
char        ySCORE_mark             (void *v_hand, char a_label [LEN_TERSE], uchar a_mark);
uchar       ySCORE_value            (void *v_hand, char a_label [LEN_TERSE]);
char        ySCORE_mask             (void *v_hand, char a_beg [LEN_TERSE], char a_end [LEN_TERSE]);
/*---(special)--------------*/
char        ySCORE_exists           (void *v_hand, char a_label [LEN_TERSE], int a_src);
char        ySCORE_flag             (void *v_hand, char a_label [LEN_TERSE], int a_src);
char        ySCORE_exact            (void *v_hand, char a_label [LEN_TERSE], int a_src);
char        ySCORE_scaled           (void *v_hand, char a_label [LEN_TERSE], int a_src);
char        ySCORE_percent          (void *v_hand, char a_label [LEN_TERSE], int a_part, int a_total);
/*---(done)-----------------*/



/*===[[ yENV_mark.c ]]========================================================*/
/*········· ´······················ ´·········································*/
char        ySCORE_pos              (void *v_hand, char a_label [LEN_TERSE], short *r_index, short *r_tpos, short *r_spos, short *r_rpos, short *r_ppos);
/*---(done)-----------------*/



/*===[[ yENV_rptg.c ]]========================================================*/
/*---(output)-------------------------*/
char*       ySCORE_terse            (void *v_hand);
char*       ySCORE_score            (void *v_hand);
char*       ySCORE_full             (void *v_hand);
char*       ySCORE_report           (void *v_hand);
char*       ySCORE_poly             (void *v_hand);
char*       ySCORE_title            (void *v_hand, char a_type);
char*       ySCORE_header           (void *v_hand, char n);
char*       ySCORE_legend           (void *v_hand, char a_label [LEN_TERSE], char a_dir);
/*---(done)-----------------*/



/*===[[ yENV_table.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
/*---(program)------------------------*/
char        ySCORE_init             (tySCORE_TB *a_table, char a_validity, void **b_table);
char        ySCORE_clear            (void *b_cur);
char        ySCORE_wrap             (void **b_old);
/*---(entries)------------------------*/
short       ySCORE_count            (void *v_hand);
short       ySCORE_by_index         (void *v_hand, short a_index, char r_label [LEN_TERSE], char *r_default, char *r_sample, char r_print [LEN_LABEL], char r_desc [LEN_DESC], char *r_style, char *r_check, char r_valid [LEN_TITLE], char r_legend [LEN_FULL]);
short       ySCORE_by_cursor        (void *v_hand, char a_dir, char r_label [LEN_TERSE], char *r_default, char *r_sample, char r_print [LEN_LABEL], char r_desc [LEN_DESC], char *r_style, char *r_check, char r_valid [LEN_TITLE], char r_legend [LEN_FULL]);
/*---(done)-----------------*/



/*===[[ yENV_stats.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
/*---(clear)----------------*/
char        ySCORE_stats_clear      (void *v_hand);
/*---(set)------------------*/
char        ySCORE_stats_set        (void *v_hand, char a_label [LEN_TERSE], uchar a_stat);
uchar       ySCORE_stats_value      (void *v_hand, char a_label [LEN_TERSE]);
/*---(more)-----------------*/
char        ySCORE_stats_inc        (void *v_hand, char a_label [LEN_TERSE]);
char        ySCORE_stats_add        (void *v_hand, char a_label [LEN_TERSE], uchar a_stat);
/*---(less)-----------------*/
char        ySCORE_stats_dec        (void *v_hand, char a_label [LEN_TERSE]);
char        ySCORE_stats_sub        (void *v_hand, char a_label [LEN_TERSE], uchar a_stat);
/*---(debugging)------------*/
char*       ySCORE_stats_show       (void *v_hand);
/*---(done)-----------------*/



#endif
/*===[[ END ]]================================================================*/
