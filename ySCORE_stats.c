/*===[[ START ]]==============================================================*/
#include    "ySCORE.h"
#include    "ySCORE_priv.h"



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



uchar   gySCORE_stats [LEN_FULL];




/*====================------------------------------------====================*/
/*===----                      individual marks                        ----===*/
/*====================------------------------------------====================*/
static void      o___MARK__________o (void) {;};

char         /*--> driver for value changes to a single entry ----------------*/
yscore_stats            (void *v_hand, char a_label [LEN_TERSE], char a_how, uchar a_stat)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   tySCORE    *x_hand      = NULL;
   tySCORE_TB *x_table     = NULL;
   short       n           =   -1;
   char        x_def       =  '·';
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(return)-------------------------*/
   rc = yscore_structs (v_hand, &x_hand, &x_table, NULL);
   DEBUG_YSCORE   yLOG_value   ("structs"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(position)-----------------------*/
   rc = yscore_pos (x_table, 0, a_label, &n, NULL, NULL, NULL, NULL);
   DEBUG_YSCORE   yLOG_value   ("pos"       , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YSCORE   yLOG_value   ("n"         , n);
   /*---(set value)----------------------*/
   x_def = x_table [n].s_default;
   DEBUG_YSCORE   yLOG_char    ("x_def"     , x_def);
   DEBUG_YSCORE   yLOG_char    ("a_how"     , a_how);
   DEBUG_YSCORE   yLOG_char    ("a_stat"    , a_stat);
   --rce;  switch (a_how) {
   case 'c'  : gySCORE_stats [n] =  x_def;   break;
   case 's'  : gySCORE_stats [n] =  a_stat;  break;
   case '+'  : gySCORE_stats [n] += a_stat;  break;
   case '-'  : gySCORE_stats [n] -= a_stat;  break;
   default   :
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return 1;
}

char         /*--> set existing value to new one -----------------------------*/
ySCORE_stats_set        (void *v_hand, char a_label [LEN_TERSE], uchar a_stat)
{
   return yscore_stats   (v_hand, a_label, 's', a_stat);
}

char         /*--> add new value to existing --------------------------------*/
ySCORE_stats_add        (void *v_hand, char a_label [LEN_TERSE], uchar a_stat)
{
   return yscore_stats   (v_hand, a_label, '+', a_stat);
}

char         /*--> increase value by one -------------------------------------*/
ySCORE_stats_inc        (void *v_hand, char a_label [LEN_TERSE])
{
   return yscore_stats   (v_hand, a_label, '+', 1);
}

char         /*--> subtract new value from existing --------------------------*/
ySCORE_stats_sub        (void *v_hand, char a_label [LEN_TERSE], uchar a_stat)
{
   return yscore_stats   (v_hand, a_label, '-', a_stat);
}

char         /*--> decrease value by one -------------------------------------*/
ySCORE_stats_dec        (void *v_hand, char a_label [LEN_TERSE])
{
   return yscore_stats   (v_hand, a_label, '-', 1);
}

uchar        /*--> return current value --------------------------------------*/
ySCORE_stats_value      (void *v_hand, char a_label [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   tySCORE    *x_hand      = NULL;
   tySCORE_TB *x_table     = NULL;
   short       n           =   -1;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(return)-------------------------*/
   rc = yscore_structs (v_hand, &x_hand, &x_table, NULL);
   DEBUG_YSCORE   yLOG_value   ("structs"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(position)-----------------------*/
   rc = yscore_pos (x_table, 0, a_label, &n, NULL, NULL, NULL, NULL);
   DEBUG_YSCORE   yLOG_value   ("pos"       , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YSCORE   yLOG_value   ("n"         , n);
   /*---(set value)----------------------*/
   rc = gySCORE_stats [n];
   DEBUG_YSCORE   yLOG_value   ("rc"        , rc);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return rc;
}

char         /*--> set all values back to table defaults ---------------------*/
ySCORE_stats_clear      (void *v_hand)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   tySCORE    *x_hand      = NULL;
   tySCORE_TB *x_table     = NULL;
   short       x_max       =    0;
   int         i           =    0;
   char        x_def       =  '·';
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(return)-------------------------*/
   rc = yscore_structs (v_hand, &x_hand, &x_table, &x_max);
   DEBUG_YSCORE   yLOG_value   ("structs"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(clear all)----------------------*/
   for (i = 0; i < x_max; ++i) {
      x_def = x_table [i].s_default;
      DEBUG_YSCORE   yLOG_complex ("line"      , "%3d %-10.10s %c", i, x_table [i].s_label, x_def);
      gySCORE_stats [i] = x_def;
   }
   gySCORE_stats [i] = '\0';
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   return 1;
}

char*        /*--> create human-readable view of stats for debugging ---------*/
ySCORE_stats_show       (void *v_hand)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   tySCORE    *x_hand      = NULL;
   tySCORE_TB *x_table     = NULL;
   short       x_max       =    0;
   int         i           =    0;
   uchar       x_def       =  '·';
   static char t           [LEN_FULL]  = "";
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(return)-------------------------*/
   rc = yscore_structs (v_hand, &x_hand, &x_table, &x_max);
   DEBUG_YSCORE   yLOG_value   ("structs"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare list)-------------------*/
   for (i = 0; i < x_max; ++i) {
      x_def = x_table [i].s_default;
      DEBUG_YSCORE   yLOG_complex ("line"      , "%3d %-10.10s %c", i, x_table [i].s_label, x_def);
      if (gySCORE_stats [i] == x_def)  t [i] = x_def;
      else                             t [i] = '°';
   }
   t [i] = '\0';
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   return t;
}



