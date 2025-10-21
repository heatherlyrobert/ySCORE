/*===[[ START ]]==============================================================*/
#include    "ySCORE.h"
#include    "ySCORE_priv.h"




/*====================------------------------------------====================*/
/*===----                       positioning                            ----===*/
/*====================------------------------------------====================*/
static void      o___POSITION______o (void) {;};

char
yscore_pos__next        (short n, char a_sample, short *b_tpos, short *b_spos, short *b_rpos, short *b_ppos)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =  '-';
   char        t           =    0;
   char        s           =    0;
   char        r           =    0;
   char        p           =    0;
   /*> char        x_lead      =  '-';                                                <*/
   /*---(defense)------------------------*/
   if (n < 0) {  /*  initialize */
      if (b_tpos != NULL)   *b_tpos = 0;
      if (b_spos != NULL)   *b_spos = 0;
      if (b_rpos != NULL)   *b_rpos = 0;
      if (b_ppos != NULL)   *b_ppos = 0;
      return 0;
   }
   /*---(set increment)------------------*/
   switch (a_sample) {
   case  0  :   t = 0;   s = 4;   r = 1;   p = 1;   break;
   case  1  :   t = 1;   s = 1;   r = 1;   p = 1;   break;
   case  3  :   t = 3;   s = 3;   r = 1;   p = 2;   break;
   default  :   t = 1;   s = 1;   r = 2;   p = 1;   break;
   }
   /*---(save-back)----------------------*/
   if (b_tpos != NULL)   *b_tpos += t;
   if (b_spos != NULL)   *b_spos += s;
   if (b_rpos != NULL)   *b_rpos += r;
   if (b_ppos != NULL)   *b_ppos += p;
   /*---(complete)-----------------------*/
   return 1;
}

char
yscore_pos_next         (tySCORE_TB *a_table, char a_type, short n, short *r_pos)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(defense)------------------------*/
   --rce;  if (a_table == NULL)  return rce;
   /*---(next)---------------------------*/
   --rce;  switch (a_type) {
   case 't' :  return yscore_pos__next (n, a_table [n].s_sample, r_pos, NULL , NULL , NULL );  break;
   case 's' :  return yscore_pos__next (n, a_table [n].s_sample, NULL , r_pos, NULL , NULL );  break;
   case 'r' :  return yscore_pos__next (n, a_table [n].s_sample, NULL , NULL , r_pos, NULL );  break;
   case 'p' :  return yscore_pos__next (n, a_table [n].s_sample, NULL , NULL , NULL , r_pos);  break;
   default  :  return rce;
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
yscore_pos              (tySCORE_TB *a_table, short a_max, char a_label [LEN_TERSE], short *r_index, short *r_tpos, short *r_spos, short *r_rpos, short *r_ppos)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         i           =    0;
   short       t           =   -1;
   short       s           =   -1;
   short       r           =   -1;
   short       p           =   -1;
   char        x_good      =  '-';
   short       x_max       = LEN_FULL;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_index != NULL)  *r_index = -1;
   if (r_tpos  != NULL)  *r_tpos  = -1;
   if (r_spos  != NULL)  *r_spos  = -1;
   if (r_rpos  != NULL)  *r_rpos  = -1;
   if (r_ppos  != NULL)  *r_ppos  = -1;
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "ySCORE, scoring pos called for without configuring a scoring table (ySCORE_init)");
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YSCORE   yLOG_point   ("a_label"   , a_label);
   --rce;  if (a_label == NULL || strlen (a_label) <= 0) {
      yURG_err ('w', "ySCORE, scoring pos called, but called with label NULL/empty (illegal)");
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YSCORE   yLOG_info    ("a_label"   , a_label);
   --rce;  if (a_label [0] == ' ') {
      yURG_err ('w', "ySCORE, scoring pos called for a non-unique spacer label (illegal)");
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(set max)------------------------*/
   if      (a_max >  0)  x_max = a_max;
   else                  x_max = LEN_FULL;
   DEBUG_YSCORE   yLOG_value   ("x_max"     , x_max);
   /*---(initialize)---------------------*/
   rc = yscore_pos__next (-1, -1, &t, &s, &r, &p);
   DEBUG_YSCORE   yLOG_value   ("intial"    , rc);
   /*---(position)-----------------------*/
   --rce;  for (i = 0; i < x_max; ++i) {
      DEBUG_YSCORE   yLOG_complex ("check"     , "%3d) %s", i, a_table [i].s_label);
      /*---(test for end)----------------*/
      if (strncmp (a_table [i].s_label, "end-", 4) == 0) {
         DEBUG_YSCORE   yLOG_note    ("hit end of table sentinel");
         break;
      }
      /*---(drop-out)--------------------*/
      if (strcmp (a_table [i].s_label, a_label) == 0) {
         DEBUG_YSCORE   yLOG_value   ("FOUND"     , i);
         x_good = 'y';
         break;
      }
      /*---(accumulate)------------------*/
      rc = yscore_pos__next (i, a_table [i].s_sample, &t, &s, &r, &p);
      DEBUG_YSCORE   yLOG_value   ("next"      , rc);
      if (rc < 0) {
         DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      /*---(done)------------------------*/
   }
   /*---(check for trouble)--------------*/
   DEBUG_YSCORE   yLOG_value   ("i"         , i);
   DEBUG_YSCORE   yLOG_value   ("s"         , s);
   DEBUG_YSCORE   yLOG_value   ("t"         , t);
   DEBUG_YSCORE   yLOG_value   ("r"         , r);
   DEBUG_YSCORE   yLOG_value   ("p"         , p);
   --rce;  if (x_good != 'y') {
      yURG_err ('w', "ySCORE, scoring pos called, but label å%sæ does not exist in scoring table", a_label);
      DEBUG_YSCORE    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_index != NULL)  *r_index = i;
   if (r_tpos  != NULL)  *r_tpos  = t;
   if (r_spos  != NULL)  *r_spos  = s;
   if (r_rpos  != NULL)  *r_rpos  = r;
   if (r_ppos  != NULL)  *r_ppos  = p;
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return 1;
}

char
ySCORE_pos              (void *v_hand, char a_label [LEN_TERSE], short *r_index, short *r_tpos, short *r_spos, short *r_rpos, short *r_ppos)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   tySCORE    *x_hand      = NULL;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(return)-------------------------*/
   rc = yscore_structs (v_hand, &x_hand, NULL, NULL);
   DEBUG_YSCORE   yLOG_value   ("structs"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(call pos)-----------------------*/
   rc = yscore_pos (x_hand->m_table, x_hand->m_max, a_label, r_index, r_tpos, r_spos, r_rpos, r_ppos);
   DEBUG_YSCORE   yLOG_value   ("pos"       , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   return 1;
}




