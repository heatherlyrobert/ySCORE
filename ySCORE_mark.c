/*===[[ START ]]==============================================================*/
#include    "ySCORE.h"
#include    "ySCORE_priv.h"



/*
 *  use forgiving interpretations every time.  ySCORE is useful,
 *  but it should not cause an application to fail if it is
 *  configured improperly.
 */



char
yscore_valid            (char a_valid [LEN_TITLE], char r_valid [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_valid     [LEN_HUND]  = "";
   int         i           =    0;
   int         l           =    0;
   char        t           [LEN_HUND]  = "";
   uchar       x_curr      =  '·';
   uchar       x_dash      =  '·';
   uchar       x_next      =  '·';
   uchar      *x_range     = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzèéêëìíîïðñòóôõö÷øùúûüýþÿ";
   uchar      *x_beg       = NULL;
   uchar      *x_end       = NULL;
   int         x_sub       =    0;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_valid != NULL)  strlcpy (r_valid, "", LEN_HUND);
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_valid"   , a_valid);
   --rce;  if (a_valid == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YSCORE   yLOG_info    ("a_valid"   , a_valid);
   /*---(translate)----------------------*/
   l = strlen (a_valid);
   --rce;  for (i = 0; i < l; ++i) {
      /*---(prepare characters)----------*/
      x_curr = a_valid [i];
      x_next = x_dash = ' ';
      if (l > i + 2) {
         x_dash = a_valid [i + 1];
         x_next = a_valid [i + 2];
      }
      DEBUG_YSCORE   yLOG_complex ("loop"      , "%3d, %3d, %c, %c, %c", l, i, x_curr, x_dash, x_next);
      if (x_curr == ' ')  continue;
      /*---(check for control)-----------*/
      if (x_curr == 0  || x_next == 0  ) {
         DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      if (x_curr <= 32 || x_curr == 127) {
         DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      /*---(character range)-------------*/
      if (x_next != ' ' && x_dash == '-') {
         DEBUG_YSCORE   yLOG_note    ("identified potenial range");
         x_beg = strchr (x_range, x_curr);
         x_end = strchr (x_range, x_next);
         if (x_beg != NULL && x_end != NULL) {
            if (x_end >= x_beg) {
               strlcpy (t, x_beg, x_end - x_beg + 2);
               i += 2;
            } else {
               DEBUG_YSCORE   yLOG_note    ("changed to single character");
               sprintf (t, "%c", x_curr);
            }
         } else {
            DEBUG_YSCORE   yLOG_note    ("changed to single character");
            sprintf (t, "%c", x_curr);
         }
      }
      /*---(single character)------------*/
      else {
         DEBUG_YSCORE   yLOG_note    ("identified single character");
         sprintf (t, "%c", x_curr);
      }
      /*---(concatinate)-----------------*/
      strlcat (x_valid, t, LEN_HUND);
      DEBUG_YSCORE   yLOG_info    ("x_valid"   , x_valid);
      /*---(done)------------------------*/
   }
   /*---(save-back)----------------------*/
   if (r_valid != NULL)  strlcpy (r_valid, x_valid, LEN_HUND);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   return 1;
}



/*====================------------------------------------====================*/
/*===----                      individual marks                        ----===*/
/*====================------------------------------------====================*/
static void      o___MARK__________o (void) {;};

char
yscore_mark             (tSCORE *a_cur, tSCORE_TABLE *a_table, char c_validity, char a_label [LEN_TERSE], uchar a_mark, char b_terse [LEN_FULL], char b_score [LEN_FULL], char b_report [LEN_FULL], char b_poly [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   short       n           =   -1;
   short       t           =   -1;
   short       s           =   -1;
   short       r           =   -1;
   short       p           =   -1;
   char        x_label     [LEN_TERSE] = "";
   char        x_valid     [LEN_TITLE] = "";
   char        x_full      [LEN_HUND]  = "";
   char        x_final     =    1;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring mark å%sæ, called without scoring table", a_label);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(position)-----------------------*/
   rc = yscore_pos (a_table, 0, a_label, &n, &t, &s, &r, &p);
   DEBUG_YSCORE   yLOG_value   ("pos"       , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(get mark in general)------------*/
   DEBUG_YSCORE   yLOG_value   ("a_mark"    , a_mark);
   --rce;  if (a_mark    <= 32 || a_mark == 127) {
      yURG_err ('w', "scoring mark å%sæ, called with hidden/control (%3d)", a_label, a_mark);
      a_mark = '¤';
      x_final = 0;
   }
   DEBUG_YSCORE   yLOG_char    ("a_mark"    , a_mark);
   /*---(get validity)-------------------*/
   DEBUG_YSCORE   yLOG_char    ("m_validity", c_validity);
   if (c_validity == 'y') {
      rc = yscore_data (a_cur, n, x_label, NULL, NULL, NULL, NULL, x_valid, NULL);
      DEBUG_YSCORE   yLOG_info    ("x_valid"   , x_valid);
      rc = yscore_valid (x_valid, x_full);
      --rce;  if (a_mark != (uchar) '¤' && strchr (x_full, a_mark) == NULL) {
         yURG_err ('w', "scoring mark å%sæ, called with unrecognized value (%c) å%sæ", a_label, a_mark, x_valid);
         a_mark = '¤';
         x_final = 0;
      }
   }
   /*---(update terse)-------------------*/
   if (b_terse != NULL) {
      DEBUG_YSCORE   yLOG_value   ("t"         , t);
      b_terse  [t] = a_mark;
      DEBUG_YSCORE   yLOG_info    ("b_terse"   , b_terse);
   }
   /*---(update score)-------------------*/
   if (b_score != NULL) {
      DEBUG_YSCORE   yLOG_value   ("s"         , s);
      b_score  [s] = a_mark;
      DEBUG_YSCORE   yLOG_info    ("b_score"   , b_score);
   }
   /*---(update report)------------------*/
   if (b_report != NULL) {
      DEBUG_YSCORE   yLOG_value   ("r"         , r);
      b_report [r] = a_mark;
      DEBUG_YSCORE   yLOG_info    ("b_report"  , b_report);
   }
   /*---(update poly)--------------------*/
   if (b_poly   != NULL) {
      DEBUG_YSCORE   yLOG_value   ("r"         , r);
      b_poly   [p] = a_mark;
      DEBUG_YSCORE   yLOG_info    ("b_poly"    , b_poly);
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return x_final;
}

char
ySCORE_mark             (void *a_cur, char a_label [LEN_TERSE], uchar a_mark)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   tSCORE     *x_cur       = NULL;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(check return)-------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_cur"     , a_cur);
   --rce;  if (a_cur == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(type)---------------------------*/
   x_cur = (tSCORE*) a_cur;
   DEBUG_YSCORE   yLOG_point   ("x_cur"     , x_cur);
   /*---(call mark)----------------------*/
   rc = yscore_mark   (x_cur, x_cur->m_table, x_cur->m_validity, a_label, a_mark, x_cur->o_terse, x_cur->o_score, x_cur->o_report, x_cur->o_poly);
   DEBUG_YSCORE   yLOG_value   ("mark"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   return rc;
}

uchar
yscore_value            (tSCORE_TABLE *a_table, char a_label [LEN_TERSE], char a_score [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   short       s           =   -1;
   uchar       x_value     =  '-';
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring value å%sæ, called without scoring table", a_label);
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return '¤';
   }
   DEBUG_YSCORE   yLOG_point   ("a_score"   , a_score);
   --rce;  if (a_score == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return '¤';
   }
   /*---(position)-----------------------*/
   rc = yscore_pos (a_table, 0, a_label, NULL, NULL, &s, NULL, NULL);
   DEBUG_YSCORE   yLOG_value   ("pos"       , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE    yLOG_exitr   (__FUNCTION__, rce);
      return '¤';
   }
   DEBUG_YSCORE   yLOG_value   ("s"         , s);
   /*---(value)--------------------------*/
   x_value = a_score [s];
   DEBUG_YSCORE   yLOG_value   ("x_value"   , x_value);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return x_value;
}

uchar
ySCORE_value            (void *a_cur, char a_label [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   tSCORE     *x_cur       = NULL;
   short       x_mark      =    0;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(check return)-------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_cur"     , a_cur);
   --rce;  if (a_cur == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return '¤';
   }
   /*---(type)---------------------------*/
   x_cur = (tSCORE*) a_cur;
   DEBUG_YSCORE   yLOG_point   ("x_cur"     , x_cur);
   /*---(call value)---------------------*/
   x_mark = yscore_value (x_cur->m_table , a_label, x_cur->o_score);
   DEBUG_YSCORE   yLOG_char    ("mark"      , x_mark);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   return x_mark;
}



/*====================------------------------------------====================*/
/*===----                        masking areas                         ----===*/
/*====================------------------------------------====================*/
static void      o___MASKING_______o (void) {;};

char
yscore_mask             (tSCORE_TABLE *a_table, char a_beg [LEN_TERSE], char a_end [LEN_TERSE], char b_terse [LEN_FULL], char b_score [LEN_FULL], char b_report [LEN_FULL], char b_poly [LEN_FULL])
{
   char         rce        =  -10;
   char         rc         =    0;
   int          i;
   short        bt, et;
   short        bs, es;
   short        br, er;
   short        bp, ep;
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "ySCORE, scoring mask called without configuring scoring table (ySCORE_init)");
      return rce;
   }
   rc = yscore_pos (a_table, 0, a_beg, NULL, &bt, &bs, &br, &bp);
   --rce;  if (rc < 0 || bs < 0) {
      return rce;
   }
   rc = yscore_pos (a_table, 0, a_end, NULL, &et, &es, &er, &ep);
   --rce;  if (rc < 0 || es < 0) {
      return rce;
   }
   --rce;  if (bs > es) {
      yURG_err ('w', "ySCORE, scoring mask ending å%sæ is before beginning å%sæ", a_end, a_beg);
      return rce;
   }
   if (b_terse  != NULL) { for (i = bt; i <= et; ++i)  b_terse  [i]   = '¬'; }
   if (b_score  != NULL) { for (i = bs; i <= es; ++i)  b_score  [i]   = '¬'; }
   if (b_report != NULL) { for (i = br; i <= er; ++i)  b_report [i]   = '¬'; }
   if (b_poly   != NULL) { for (i = bp; i <= ep; ++i)  b_poly   [i]   = '¬'; }
   return 0;
}

char
ySCORE_mask             (void *a_cur, char a_beg [LEN_TERSE], char a_end [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   tSCORE     *x_cur       = NULL;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(check return)-------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_cur"     , a_cur);
   --rce;  if (a_cur == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(type)---------------------------*/
   x_cur = (tSCORE*) a_cur;
   DEBUG_YSCORE   yLOG_point   ("x_cur"     , x_cur);
   /*---(call mask)----------------------*/
   rc = yscore_mask (x_cur->m_table, a_beg, a_end, x_cur->o_terse, x_cur->o_score, x_cur->o_report, x_cur->o_poly);
   DEBUG_YSCORE   yLOG_value   ("mask"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   return 1;
}


