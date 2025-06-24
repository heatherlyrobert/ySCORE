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
#define     P_VERNUM    "2.0a"
#define     P_VERTXT    "initial movement of code"
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



extern char  g_print   [LEN_RECD];



/*===[[ yENV_score.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
/*---(program)--------------*/
char        yenv_score_clear        (void);
/*---(quick)----------------*/
char*       yenv_score_terse        (void);
char*       yenv_score              (void);
char*       yenv_score_full         (void);
char*       yenv_score_report       (void);
/*---(marking)--------------*/
char        yenv_score_pos          (char a_label [LEN_TERSE], short *r_norm, short *r_terse, short *r_report);
char        yenv_score_mark         (char a_label [LEN_TERSE], uchar a_mark);
char        yenv_score_value        (char a_label [LEN_TERSE]);
/*---(reporting)------------*/
char*       yenv_score_header       (char n);
char*       yenv_score_title        (char a_type);
/*---(masking)--------------*/
char        yenv_score_mask         (char a_beg [LEN_TERSE], char a_end [LEN_TERSE]);
char        yenv_score_nocheck      (void);
char        yenv_score_nohacked     (void);
/*---(auditing)-------------*/
char        yenv_score__asample     (short n, uchar a_sample);
char        yenv_score__adefault    (short n, uchar a_sample, uchar a_default);
char        yenv_score__alabel      (short n, uchar s_sample, char s_label [LEN_TERSE]);
char        yenv_score__aprint      (short n, uchar a_sample, char a_print [LEN_TERSE]);
char        yenv_score__aline       (short n, char a_label [LEN_TERSE], char a_default, char a_sample, char a_print [LEN_TERSE], char a_desc [LEN_TERSE], char a_legend [LEN_TERSE]);
char        yenv_score__adup        (tENV_SCORE *a_table, char n, char a_label [LEN_TERSE]);
char        yenv_score_audit        (void);
/*---(legend)---------------*/
char*       yenv_score__legend      (tENV_SCORE *a_table, char a_line, char a_label [LEN_TERSE], char a_terse [LEN_FULL]);
char*       yenv_score_legend       (char a_line, char a_label [LEN_TERSE]);
/*---(done)-----------------*/



#endif
