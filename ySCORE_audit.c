/*===[[ START ]]==============================================================*/
#include    "ySCORE.h"
#include    "ySCORE_priv.h"



char
yscore__audit_sample    (short n, uchar a_sample)
{
   char        rce         =  -10;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   DEBUG_YSCORE   yLOG_value   ("a_sample"  , a_sample);
   --rce;  if (a_sample >= 127 && a_sample <= 159) {
      DEBUG_YSCORE    yLOG_note    ("line drawing");
      yURG_err ('w', "%3d) bad sample character, (%3d) char, line drawing characters disallowed", n, a_sample);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   if (a_sample == 0 ) {
      DEBUG_YSCORE    yLOG_note    ("block header");
      DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
      return RC_POSITIVE;
   }
   if (a_sample == 1 ) {
      DEBUG_YSCORE    yLOG_note    ("small space");
      DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
      return RC_POSITIVE;
   }
   if (a_sample == 3 ) {
      DEBUG_YSCORE    yLOG_note    ("large space");
      DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
      return RC_POSITIVE;
   }
   --rce;  if (a_sample <= 32) {
      DEBUG_YSCORE    yLOG_note    ("control character");
      yURG_err ('w', "%3d) bad sample character, (%3d) char, control characters disallowed (0 - 32), except 0, 1, and 3", n, a_sample);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return RC_POSITIVE;
}

char
yscore__audit_def       (short n, uchar a_sample, uchar a_default)
{
   char        rce         =  -10;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   DEBUG_YSCORE   yLOG_value   ("a_default" , a_default);
   --rce;  if (a_default >= 127 && a_default <= 159) {
      DEBUG_YSCORE    yLOG_note    ("line drawing");
      yURG_err ('w', "%3d) bad default character, (%3d) sample, (%3d) char, line drawing characters disallowed", n, a_sample, a_default);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (a_default < 32) {
      yURG_err ('w', "%3d) bad default character, (%3d) sample, (%3d) char, control characters disallowed (0 - 31)", n, a_sample, a_default);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (a_sample < 32 && a_default != ' ') {
      yURG_err ('w', "%3d) must use space as default, (%3d) sample", n, a_sample);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (a_sample > 32 && a_default == ' ') {
      yURG_err ('w', "%3d) space default character, (%3d) sample, not allowed for normal lines", n, a_sample);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return RC_POSITIVE;
}

char
yscore__audit_label     (short n, uchar a_sample, char a_label [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         i           =    0;
   int         l           =    0;
   char       *x_valid     = NULL;
   char        x_pre       [LEN_HUND]  = "";
   char        x_mid       [LEN_HUND]  = "";
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(prepare)------------------------*/
   sprintf (x_pre, "ySCORE, table line (%3d), type (%3d/%c),", n, a_sample, ychrvisible (a_sample));
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_label"   , a_label);
   --rce;  if (a_label == NULL) {
      yURG_err ('w', "%s label is NULL", x_pre);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YSCORE   yLOG_info    ("a_label"   , a_label);
   /*---(general lengths)----------------*/
   l = strlen (a_label);
   DEBUG_YSCORE   yLOG_value   ("l"         , l);
   --rce;  if (l == 0) {
      yURG_err ('w', "%s label is empty/blank", x_pre);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   sprintf (x_mid, "label %2då%sæ", l, a_label);
   --rce;  if (l > 9) {
      yURG_err ('w', "%s %s is too long (>9)", x_pre, x_mid);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(specific lengths)----------------*/
   --rce;  if (a_sample == 0 && l != 4) {
      yURG_err ('w', "%s %s, BLOCK type is not 4 chars long", x_pre, x_mid);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (a_sample == 1 && l != 1) {
      yURG_err ('w', "%s %s, SMALL SPACE type is not 1 char long", x_pre, x_mid);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (a_sample == 3 && l != 3) {
      yURG_err ('w', "%s %s, LARGE SPACE type is not 3 chars long", x_pre, x_mid);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(characters)---------------------*/
   switch (a_sample) {
   case  0  : x_valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZá ";  break;
   case  1  : x_valid = " ·";                            break;
   case  3  : x_valid = " ·";                            break;
   default  : x_valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";    break;
   }
   for (i = 0; i < l; ++i) {
      if (strchr (x_valid, a_label [i]) == NULL) {
         yURG_err ('w', "%s %s, pos (%3d) w/char (%3d/%c) not allowed å%sæ", x_pre, x_mid, i, (uchar) a_label [i], ychrvisible (a_label [i]), x_valid);
         DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(specific to blocks)-------------*/
   x_valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   --rce;  if (a_sample == 0 && strchr (x_valid, a_label [0]) == NULL) {
      yURG_err ('w', "%s %s, BLOCK type, pos (%3d) w/char (%3d/%c), must have upper case", x_pre, x_mid, 0, a_label [0], ychrvisible (a_label [0]));
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (a_sample == 0 && strchr (x_valid, a_label [1]) == NULL) {
      yURG_err ('w', "%s %s, BLOCK type, pos (%3d) w/char (%3d/%c), must have upper case", x_pre, x_mid, 1, a_label [1], ychrvisible (a_label [1]));
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (a_sample == 0 && a_label [2] != 'á') {
      yURG_err ('w', "%s %s, BLOCK type, pos (%3d) w/char (%3d/%c), must have tick mark (á)", x_pre, x_mid, 2, a_label [2], ychrvisible (a_label [2]));
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (a_sample == 0 && a_label [3] != ' ') {
      yURG_err ('w', "%s %s, BLOCK type, pos (%3d) w/char (%3d/%c), must have space", x_pre, x_mid, 3, a_label [3], ychrvisible (a_label [3]));
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return RC_POSITIVE;
}

char
yscore__audit_print     (short n, uchar a_sample, char a_print [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         i           =    0;
   int         l           =    0;
   char       *x_valid     = NULL;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_print"   , a_print);
   --rce;  if (a_print == NULL) {
      yURG_err ('w', "%3d) print NULL, (%3d) sample", n, a_sample);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YSCORE   yLOG_info    ("a_print"   , a_print);
   /*---(lengths)------------------------*/
   l = strlen (a_print);
   --rce;  if (l > 9) {
      yURG_err ('w', "%3d) print too long (> 9), (%3d) sample, (%d) len", n, a_sample, l);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (a_sample != 0 && l > 6) {
      yURG_err ('w', "%3d) normal print too long (> 6), (%3d) sample, (%d) len", n, a_sample, l);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if ((a_sample == 0 || a_sample > 32) && l < 1) {
      yURG_err ('w', "%3d) print too short, (%3d) sample, (%d) len", n, a_sample, l);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (a_sample == 1 && l != 0) {
      yURG_err ('w', "%3d) 1 print not zero, (%3d) sample, (%d) len", n, a_sample, l);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (a_sample == 3 && l != 0) {
      yURG_err ('w', "%3d) 3 print not zero, (%3d) sample, (%d) len", n, a_sample, l);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(characters)---------------------*/
   switch (a_sample) {
   case  0  : x_valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZ³";  break;
   default  : x_valid = "abcdefghijklmnopqrstuvwxyzŒABCDEFGHIJKLMNOPQRSTUVWXYZ";  break;
   }
   for (i = 0; i < l; ++i) {
      if (strchr (x_valid, a_print [i]) == NULL) {
         yURG_err ('w', "%3d) bad print character, (%3d) sample, (%d) pos, (%3d) char not allowed å%sæ", n, a_sample, i, a_print [i], x_valid);
         DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return RC_POSITIVE;
}

char
yscore__audit_valid     (short n, uchar a_sample, char a_valid [LEN_LABEL])
{
   return yscore_valid (a_valid, NULL);
}

char
yscore__audit_line      (short n, char a_label [LEN_TERSE], char a_default, char a_sample, char a_print [LEN_TERSE], char a_valid [LEN_LABEL], char a_desc [LEN_TERSE], char a_legend [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        rc_final    = RC_POSITIVE;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(checks)----------------------*/
   rc = yscore__audit_sample (n, a_sample);
   if (rc < 0)  rc_final = rc;
   DEBUG_YSCORE   yLOG_complex ("sample"    , "%3d, %3d", rc, rc_final);
   rc = yscore__audit_def    (n, a_sample, a_default);
   if (rc < 0)  rc_final = rc;
   DEBUG_YSCORE   yLOG_complex ("def"       , "%3d, %3d", rc, rc_final);
   rc = yscore__audit_label  (n, a_sample, a_label);
   if (rc < 0)  rc_final = rc;
   DEBUG_YSCORE   yLOG_complex ("label"     , "%3d, %3d", rc, rc_final);
   rc = yscore__audit_print  (n, a_sample, a_print);
   if (rc < 0)  rc_final = rc;
   DEBUG_YSCORE   yLOG_complex ("print"     , "%3d, %3d", rc, rc_final);
   rc = yscore__audit_valid  (n, a_sample, a_valid);
   if (rc < 0)  rc_final = rc;
   DEBUG_YSCORE   yLOG_complex ("valid"     , "%3d, %3d", rc, rc_final);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return rc_final;
}

char
yscore__audit_dup       (tSCORE_TABLE *a_table, char n, char a_label [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         i           =    0;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(range check)--------------------*/
   if (n > LEN_FULL)  n = LEN_FULL;
   /*---(line-by-line)-------------------*/
   --rce;  for (i = 0; i < n; ++i) {
      /*---(test for end-list)-----------*/
      if (strncmp (a_table [i].s_label, "end-", 4) == 0)  break;
      /*---(filter)----------------------*/
      if (a_table [i].s_sample == 1)                      continue;
      if (a_table [i].s_sample == 3)                      continue;
      if (strcmp (a_table [i].s_label, a_label) != 0)     continue;
      /*---(duplicate)-------------------*/
      yURG_err ('w', "%3d) å%sæ is a duplicate label of (%d)", n, a_label, i);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return RC_POSITIVE;
}

char
yscore__audit           (tSCORE_TABLE *a_table, char c_loud)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        rc2         =    0;
   char        rc_final    = RC_POSITIVE;
   char        x_block     =    0;
   int         i           =    0;
   char        x_end       =  '-';
   char        x_bad       =    0;
   char        x_error     =    0;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring audit called without scoring table");
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(line-by-line)-------------------*/
   --rce;  for (i = 0; i < LEN_FULL; ++i) {
      /*---(messages)--------------------*/
      if (c_loud == 'y') {
         switch (a_table [i].s_sample) {
         case  0 :
            /*---(block footer)-------------*/
            if (i != 0) {
               if  (x_bad == 0)  yURG_msg ('-', "successful, no trouble found in block");
               else              yURG_msg ('-', "failure, %d issuse found in block", x_bad);
            }
            /*---(block header)-------------*/
            yURG_msg ('>', "auditing å%sæ block on line (%d)...", a_table [i].s_label, i);
            x_bad = 0;
            break;
         default :
            if (i == 0)  yURG_msg ('>', "pseudo block, auditing å%sæ on line (%d)...", a_table [i].s_label, i);
            else         yURG_msg ('-', "%3d) reviewing å%sæ", i, a_table [i].s_label);
            break;
         }
      }
      /*---(test for end-list)-----------*/
      if (strncmp (a_table [i].s_label, "end-", 4) == 0) {
         x_end = 'y';
         break;
      }
      /*---(checks)----------------------*/
      rc  = yscore__audit_line   (i, a_table [i].s_label, a_table [i].s_default, a_table [i].s_sample, a_table [i].s_print, a_table [i].s_valid, a_table [i].s_desc, a_table [i].s_legend);
      rc2 = yscore__audit_dup    (a_table, i, a_table [i].s_label);
      /*---(troubles)--------------------*/
      if (rc < 0 || rc2 < 0) {
         ++x_bad;
         ++x_error;
         rc_final = rc;
      }
      /*---(done)------------------------*/
   }
   /*---(list end)-----------------------*/
   DEBUG_YSCORE   yLOG_char    ("x_end"     , x_end);
   --rce;  if (x_end != 'y') {
      yURG_err ('w', "table does not complete with end-line item");
      ++x_bad;
      ++x_error;
      rc_final = rce;
   } else {
      if (c_loud == 'y')  yURG_msg ('-', "proper end-line found");
   }
   if (c_loud == 'y') {
      if  (x_bad == 0)  yURG_msg ('-', "successful, no trouble found in block");
      else              yURG_msg ('-', "failure, %d issuse found in block", x_bad);
      /*---(trouble)------------------------*/
      yURG_msg ('>', "score auditing summary...");
      yURG_msg ('-', "reviewed all lines, %d lines, %d error/warn", i, x_error);
      if (rc_final < 0) {
         yURG_msg ('-', "failure, scoring table has multiple warnings that may make its functioning erratic or erroneous");
      } else {
         yURG_msg ('-', "successful, scoring table appears proper, all lines checked");
      }
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return rc_final;
}

char ySCORE_audit   (void)  { return yscore__audit (mySCORE.m_table, 'y'); }

