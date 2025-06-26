/*===[[ START ]]==============================================================*/
#include    "ySCORE.h"
#include    "ySCORE_priv.h"



char
yscore_mark             (tSCORE_TABLE *a_table, char a_label [LEN_TERSE], uchar a_mark, char b_terse [LEN_FULL], char b_score [LEN_FULL], char b_report [LEN_FULL], char b_poly [LEN_FULL])
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
   char        x_valid     [LEN_TERSE] = "";
   char        x_final     =    1;
   /*---(header)-------------------------*/
   DEBUG_YENV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YENV   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring mark å%sæ, called without scoring table", a_label);
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(position)-----------------------*/
   rc = yscore_pos (a_table, 0, a_label, &n, &t, &s, &r, &p);
   DEBUG_YENV   yLOG_value   ("pos"       , rc);
   --rce;  if (rc < 0) {
      yURG_err ('w', "scoring mark å%sæ, label does not exist in scoring table", a_label);
      DEBUG_YENV    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(get validity)-------------------*/
   DEBUG_YENV   yLOG_value   ("a_mark"    , a_mark);
   --rce;  if (a_mark    <= 32 || a_mark == 127) {
      yURG_err ('w', "scoring mark å%sæ, called with hidden/control (%3d)", a_label, a_mark);
      a_mark = '¬';
      x_final = 0;
   }
   DEBUG_YENV   yLOG_char    ("a_mark"    , a_mark);
   rc = yscore_data (n, x_label, NULL, NULL, NULL, NULL, x_valid, NULL);
   DEBUG_YENV   yLOG_info    ("x_valid"   , x_valid);
   --rce;  if (a_mark != (uchar) '¬' && strchr (x_valid, a_mark) == NULL) {
      yURG_err ('w', "scoring mark å%sæ, called with unrecognized value (%c) å%sæ", a_label, a_mark, x_valid);
      a_mark = '¬';
      x_final = 0;
   }
   DEBUG_YENV   yLOG_char    ("a_mark"    , a_mark);
   /*---(update terse)-------------------*/
   if (b_terse != NULL) {
      DEBUG_YENV   yLOG_value   ("t"         , t);
      b_terse  [t] = a_mark;
      DEBUG_YENV   yLOG_info    ("b_terse"   , b_terse);
   }
   /*---(update score)-------------------*/
   if (b_score != NULL) {
      DEBUG_YENV   yLOG_value   ("s"         , s);
      b_score  [s] = a_mark;
      DEBUG_YENV   yLOG_info    ("b_score"   , b_score);
   }
   /*---(update report)------------------*/
   if (b_report != NULL) {
      DEBUG_YENV   yLOG_value   ("r"         , r);
      b_report [r] = a_mark;
      DEBUG_YENV   yLOG_info    ("b_report"  , b_report);
   }
   /*---(update poly)--------------------*/
   if (b_poly   != NULL) {
      DEBUG_YENV   yLOG_value   ("r"         , r);
      b_poly   [p] = a_mark;
      DEBUG_YENV   yLOG_info    ("b_poly"    , b_poly);
   }
   /*---(complete)-----------------------*/
   DEBUG_YENV    yLOG_exit    (__FUNCTION__);
   return x_final;
}

char ySCORE_mark        (char a_label [LEN_TERSE], uchar a_mark)  { return yscore_mark   (mySCORE.m_table , a_label, a_mark, mySCORE.o_terse, mySCORE.o_score, mySCORE.o_report, mySCORE.o_poly); }

char
yscore_value            (tSCORE_TABLE *a_table, char a_label [LEN_TERSE], char a_score [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   short       s           =   -1;
   char        x_value     =  '-';
   /*---(header)-------------------------*/
   DEBUG_YENV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YENV   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring value å%sæ, called without scoring table", a_label);
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return '¬';
   }
   DEBUG_YENV   yLOG_point   ("a_score"   , a_score);
   --rce;  if (a_score == NULL) {
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return '¬';
   }
   /*---(position)-----------------------*/
   rc = yscore_pos (a_table, 0, a_label, NULL, NULL, &s, NULL, NULL);
   DEBUG_YENV   yLOG_value   ("pos"       , rc);
   --rce;  if (rc < 0) {
      yURG_err ('w', "scoring value å%sæ, label does not exist in scoring table", a_label);
      DEBUG_YENV    yLOG_exitr   (__FUNCTION__, rce);
      return '¬';
   }
   DEBUG_YENV   yLOG_value   ("s"         , s);
   /*---(value)--------------------------*/
   x_value = a_score [s];
   DEBUG_YENV   yLOG_value   ("x_value"   , x_value);
   /*---(complete)-----------------------*/
   DEBUG_YENV    yLOG_exit    (__FUNCTION__);
   return x_value;
}

char ySCORE_value      (char a_label [LEN_TERSE])  { return yscore_value (mySCORE.m_table , a_label, mySCORE.o_score); }


