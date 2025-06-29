/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YENV_priv_hguard
#define YENV_priv_hguard loaded



/*===[[ ONE_LINERS ]]=========================================================*/
/*                      ´·········1·········2·········3·········4·········5·········6·········7*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*········· ··········· ´·····························´········································*/
#define     P_FOCUS     ""
#define     P_NICHE     ""
#define     P_SUBJECT   "application scorecard"
#define     P_PURPOSE   "provide summnary application scorecard for complex actions"
/*········· ··········· ´·····························´········································*/
#define     P_NAMESAKE  "theia-euryphaessa (wide-shinning)"
#define     P_PRONOUCE  "thee·uh yur·ee·fray·shee·uh"
#define     P_HERITAGE  "goddess of sight and the light of the clear blue sky"
#define     P_BRIEFLY   "light of the clear blue sky"
#define     P_IMAGERY   "glittering woman, mother of helios (sun), selene (moon), and eos (dawn)"
#define     P_REASON    "the goddess of clarity which is the purpose of a scorecard"
/*········· ··········· ´·····························´········································*/
#define     P_ONELINE   P_NAMESAKE " " P_SUBJECT
/*········· ··········· ´·····························´········································*/
#define     P_BASENAME  "ySCORE"
#define     P_HOMEDIR   "/home/system/ySCORE.application_scorecard"
#define     P_FULLPATH  "/usr/local/lib64/libySCORE.so"
#define     P_SUFFIX    "···"
#define     P_CONTENT   "···"
/*········· ··········· ´·····························´········································*/
#define     P_SYSTEM    "gnu/linux   (powerful, ubiquitous, technical, and hackable)"
#define     P_LANGUAGE  "ansi-c      (wicked, limitless, universal, and everlasting)"
#define     P_COMPILER  "gcc 5.3.0"
#define     P_CODESIZE  "small       (appoximately 1,000 slocl)"
/*········· ··········· ´·····························´········································*/
#define     P_AUTHOR    "heatherlyrobert"
#define     P_CREATED   "2025-06"
/*········· ··········· ´·····························´········································*/
#define     P_VERMAJOR  "2.--, production"
#define     P_VERMINOR  "2.0-, drawing from yENV in separate library"
#define     P_VERNUM    "2.0d"
#define     P_VERTXT    "audit migrated and updated, and unit tested"
/*········· ··········· ´·····························´········································*/
#define     P_PRIORITY  "direct, simple, brief, vigorous, and lucid (h.w. fowler)"
#define     P_PRINCIPAL "[grow a set] and build your wings on the way down (r. bradbury)"
#define     P_REMINDER  "there are many better options, but i *own* every byte of this one"
/*········· ··········· ´·····························´········································*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/



/*===[[ END_HEADER ]]=========================================================*/

/*345678901-12345678901-123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/

#include    <stdio.h>        /* C_ANSI : strcpy, strlen, strchr, strcmp, ...  */
#include    <string.h>       /* C_ANSI : printf, snprintf, fgets, fopen, ...  */

#include    <yLOG.h>
#include    <yURG.h>
#include    <ySTR.h>


typedef  struct cSCORE  tSCORE;
struct cSCORE {
   tSCORE_TABLE  *m_table;                  /* data table                     */
   short          m_max;                    /* maximum entries in table       */
   char        o_terse      [LEN_FULL];
   char        o_score      [LEN_FULL];
   char        o_full       [LEN_FULL];
   char        o_report     [LEN_FULL];
   char        o_poly       [LEN_FULL];
};
extern      tSCORE      mySCORE;


extern char  g_print      [LEN_RECD];



/*> extern const tSCORE_TABLE mySCORE_test [LEN_FULL];                                <*/



/*---(standard recturn codes)-------------------*/
#define     RC_ACK          0
#define     RC_POSITIVE     1
#define     RC_OVERRIDE     2
#define     RC_REPAIR       3
#define     RC_WARNING      4
#define     RC_FAILED       5
#define     RC_FATAL        5   /* depricated */



/*===[[ yENV_table.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
char        yscore_data      (short n, char r_label [LEN_TERSE], char *r_default, char *r_sample, char r_print [LEN_TERSE], char r_desc [LEN_DESC], char r_valid [LEN_LABEL], char r_legend [LEN_FULL]);
/*---(done)-----------------*/



/*===[[ yENV_pos.c ]]=========================================================*/
/*········· ´······················ ´·········································*/
/*---(basics)---------------*/
char        yscore_pos__next        (short n, char a_sample, short *b_tpos, short *b_spos, short *b_rpos, short *b_ppos);
char        yscore_pos              (tSCORE_TABLE *a_table, short a_max, char a_label [LEN_TERSE], short *r_index, short *r_tpos, short *r_spos, short *r_rpos, short *r_ppos);
/*---(accum)----------------*/
char        yscore_pos__accum       (tSCORE_TABLE *a_table, short n, short *b_tpos, short *b_spos, short *b_rpos, short *b_ppos);
char        yscore_pos_accum        (tSCORE_TABLE *a_table, char a_type, short n, short *r_pos);
/*---(done)-----------------*/



/*===[[ yENV_mark.c ]]========================================================*/
/*········· ´······················ ´·········································*/
/*---(valid)----------------*/
char        yscore_valid            (char a_valid [LEN_LABEL], char r_valid [LEN_HUND]);
/*---(mark)-----------------*/
char        yscore_mark             (tSCORE_TABLE *a_table, char a_label [LEN_TERSE], uchar a_mark, char b_terse [LEN_FULL], char b_score [LEN_FULL], char b_report [LEN_FULL], char b_poly [LEN_FULL]);
char        yscore_value            (tSCORE_TABLE *a_table, char a_label [LEN_TERSE], char a_score [LEN_FULL]);
/*---(mask)-----------------*/
char        yscore_mask             (tSCORE_TABLE *a_table, char a_beg [LEN_TERSE], char a_end [LEN_TERSE], char b_terse [LEN_FULL], char b_score [LEN_FULL], char b_report [LEN_FULL], char b_poly [LEN_FULL]);
/*---(done)-----------------*/



/*===[[ yENV_mark.c ]]========================================================*/
/*········· ´······················ ´·········································*/
char        yscore__audit_sample    (short n, uchar a_sample);
char        yscore__audit_def       (short n, uchar a_sample, uchar a_default);
char        yscore__audit_label     (short n, uchar s_sample, char s_label [LEN_TERSE]);
char        yscore__audit_print     (short n, uchar a_sample, char a_print [LEN_TERSE]);
char        yscore__audit_valid     (short n, uchar a_sample, char a_valid [LEN_LABEL]);
char        yscore__audit_line      (short n, char a_label [LEN_TERSE], char a_default, char a_sample, char a_print [LEN_TERSE], char a_valid [LEN_LABEL], char a_desc [LEN_TERSE], char a_legend [LEN_TERSE]);
char        yscore__audit_dup       (tSCORE_TABLE *a_table, char n, char a_label [LEN_TERSE]);
char        yscore__audit           (tSCORE_TABLE *a_table, char c_loud);
/*---(done)-----------------*/



/*===[[ yENV_score.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
/*---(program)--------------*/
char        yscore_clear            (tSCORE_TABLE *a_table, short *r_max, char r_terse [LEN_FULL], char r_score [LEN_FULL], char r_full [LEN_FULL], char r_report [LEN_FULL], char r_poly [LEN_FULL]);
char        yenv_score_clear        (void);
/*---(quick)----------------*/
char*       yenv_score_terse        (void);
char*       yenv_score              (void);
char*       yenv_score_full         (void);
char*       yenv_score_report       (void);
/*---(reporting)------------*/
char*       yenv_score_header       (char n);
char*       yenv_score_title        (char a_type);
/*---(masking)--------------*/
char        yenv_score_mask         (char a_beg [LEN_TERSE], char a_end [LEN_TERSE]);
char        yenv_score_nocheck      (void);
char        yenv_score_nohacked     (void);
/*---(auditing)-------------*/
char        yenv_score_audit        (void);
/*---(legend)---------------*/
char*       yenv_score__legend      (tSCORE_TABLE *a_table, char a_line, char a_label [LEN_TERSE], char a_terse [LEN_FULL]);
char*       yenv_score_legend       (char a_line, char a_label [LEN_TERSE]);
/*---(done)-----------------*/



/*===[[ yENV_test.c ]]========================================================*/
/*········· ´······················ ´·········································*/
/*> char        yscore_unit_quiet       (void);                                       <*/
/*> char        yscore_unit_loud        (void);                                       <*/
/*> char        yscore_unit_end         (void);                                       <*/
/*---(done)-----------------*/


#endif
