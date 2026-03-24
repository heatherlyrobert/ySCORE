/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YENV_priv_hguard
#define YENV_priv_hguard loaded



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
#define     P_VERMINOR  "2.1-, integrate into yJOBS and others"
#define     P_VERNUM    "2.1g"
#define     P_VERTXT    "added s_shown to table to enable line hiding, unit-tested"
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
#include    <stdlib.h>       /* C_ANSI : malloc                               */

#include    <yLOG.h>
#include    <yURG.h>
#include    <ySTR.h>

#include    <yDLST_solo.h>



typedef  struct cySCORE  tySCORE;
struct cySCORE {
   tySCORE_TB    *m_table;                  /* data table                     */
   char           m_validity;               /* perform validity check         */
   short          m_max;                    /* maximum entries in table       */
   char           o_terse      [LEN_FULL];
   char           o_score      [LEN_FULL];
   char           o_full       [LEN_FULL];
   char           o_report     [LEN_PATH];
   char           o_poly       [LEN_FULL];
};

extern uchar gySCORE_stats [LEN_FULL];



extern char  g_print      [LEN_RECD];



/*---(standard recturn codes)-------------------*/
#define     RC_ACK          0
#define     RC_POSITIVE     1
#define     RC_OVERRIDE     2
#define     RC_REPAIR       3
#define     RC_WARNING      4
#define     RC_FAILED       5
#define     RC_FATAL        5   /* depricated */




/*===[[ yENV_audit.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
char        yscore__audit_sample    (short n, uchar a_sample);
char        yscore__audit_def       (short n, uchar a_sample, uchar a_default);
char        yscore__audit_label     (short n, uchar s_sample, char s_label [LEN_TERSE]);
char        yscore__audit_print     (short n, uchar a_sample, char a_print [LEN_TERSE]);
char        yscore__audit_valid     (short n, uchar a_sample, char a_valid [LEN_LABEL]);
char        yscore__audit_line      (short n, char a_label [LEN_TERSE], char a_default, char a_sample, char a_print [LEN_TERSE], char a_valid [LEN_LABEL], char a_desc [LEN_TERSE], char a_legend [LEN_TERSE]);
char        yscore__audit_dup       (tySCORE_TB *a_table, char n, char a_label [LEN_TERSE]);
char        yscore__audit           (tySCORE_TB *a_table, char c_loud);
/*---(done)-----------------*/



/*===[[ yENV_mark.c ]]========================================================*/
/*········· ´······················ ´·········································*/
/*---(valid)----------------*/
char        yscore_valid            (char a_valid [LEN_LABEL], char r_valid [LEN_HUND]);
/*---(mark)-----------------*/
char        yscore_mark             (tySCORE *a_hand, tySCORE_TB *a_table, char c_validity, char a_label [LEN_TERSE], uchar a_mark, char b_terse [LEN_FULL], char b_score [LEN_FULL], char b_report [LEN_PATH], char b_poly [LEN_FULL]);
uchar       yscore_value            (tySCORE_TB *a_table, char a_label [LEN_TERSE], char a_score [LEN_FULL]);
/*---(mask)-----------------*/
char        yscore_mask             (tySCORE_TB *a_table, char a_beg [LEN_TERSE], char a_end [LEN_TERSE], char b_terse [LEN_FULL], char b_score [LEN_FULL], char b_report [LEN_PATH], char b_poly [LEN_FULL]);
char        yenv_score_nocheck      (void);
char        yenv_score_nohacked     (void);
/*---(done)-----------------*/



/*===[[ yENV_pos.c ]]=========================================================*/
/*········· ´······················ ´·········································*/
char        yscore_pos__next        (short n, char a_sample, short *b_tpos, short *b_spos, short *b_rpos, short *b_ppos);
char        yscore_pos_next         (tySCORE_TB *a_table, char a_type, short n, short *r_pos);
char        yscore_pos              (tySCORE_TB *a_table, short a_max, char a_label [LEN_TERSE], short *r_index, short *r_tpos, short *r_spos, short *r_rpos, short *r_ppos);
/*---(done)-----------------*/



/*===[[ yENV_rptg.c ]]========================================================*/
/*········· ´······················ ´·········································*/
char*       yscore_output           (tySCORE *a_hand, char a_which);
char*       yscore__title           (tySCORE *a_hand, tySCORE_TB *a_table, char a_type);
char*       yscore__header          (tySCORE_TB *a_table, char n);
char        yscore__legend_bounds   (tySCORE_TB *a_table, char a_label [LEN_TERSE], short *r_head, short *r_beg, short *r_end, short *r_cnt, short *r_npre);
char*       yscore__legend_lead     (tySCORE_TB *a_table, short a_beg, short a_cur, short a_end, short a_npre, char r_fill [LEN_SHORT], char r_cap [LEN_SHORT]);
char*       yscore__legend_detail   (tySCORE_TB *a_table, short a_cur, char a_fill [LEN_SHORT], char a_cap [LEN_SHORT]);
char*       yscore__legend_full     (tySCORE_TB *a_table, char a_section [LEN_TERSE], char a_dir);
char*       yscore__legend          (tySCORE_TB *a_table, char a_line, char a_label [LEN_TERSE], char a_terse [LEN_FULL]);
/*---(done)-----------------*/



/*===[[ yENV_table.c ]]=======================================================*/
/*········· ´······················ ´·········································*/
char        yscore_structs          (void *a_hand, tySCORE **r_hand, tySCORE_TB **r_table, short *r_max);
char        yscore_clear            (tySCORE_TB *a_table, short *r_max, char r_terse [LEN_FULL], char r_score [LEN_FULL], char r_full [LEN_FULL], char r_report [LEN_PATH], char r_poly [LEN_FULL]);
char        yscore_data             (tySCORE *a_hand, short n, char r_label [LEN_TERSE], char *r_default, char *r_sample, char r_print [LEN_TERSE], char r_desc [LEN_DESC], char r_valid [LEN_TITLE], char r_legend [LEN_FULL]);
/*---(done)-----------------*/



#endif
