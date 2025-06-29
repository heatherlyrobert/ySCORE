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
yscore_pos              (tSCORE_TABLE *a_table, short a_max, char a_label [LEN_TERSE], short *r_index, short *r_tpos, short *r_spos, short *r_rpos, short *r_ppos)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         i           =    0;
   short       t           =    0;
   short       s           =    0;
   short       r           =    0;
   short       p           =    0;
   char        x_good      =  '-';
   char        x_max       = LEN_FULL;
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
   /*---(initialize)---------------------*/
   if      (a_max >  0)  x_max = a_max;
   else if (a_max == 0)  x_max = mySCORE.m_max;
   else                  x_max = LEN_FULL;
   rc = yscore_pos__next (-1, -1, &t, &s, &r, &p);
   /*---(position)-----------------------*/
   --rce;  for (i = 0; i < x_max; ++i) {
      /*---(test for end)----------------*/
      if (strncmp (a_table [i].s_label, "end-", 4) == 0)  break;
      /*---(drop-out)--------------------*/
      if (strcmp (a_table [i].s_label, a_label) == 0) {
         DEBUG_YSCORE   yLOG_value   ("FOUND"     , i);
         x_good = 'y';
         break;
      }
      /*---(accumulate)------------------*/
      rc = yscore_pos__next (i, a_table [i].s_sample, &t, &s, &r, &p);
      if (rc < 0)             return rce;
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
   /*---(default)------------------------*/
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
yscore_pos__accum       (tSCORE_TABLE *a_table, short n, short *b_tpos, short *b_spos, short *b_rpos, short *b_ppos)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   short       t           =    0;
   short       s           =    0;
   short       r           =    0;
   short       p           =    0;
   /*---(defense)------------------------*/
   --rce;  if (a_table == NULL)                  return rce;
   --rce;  if (n       <  0   )                  return rce;
   /*---(starting point)-----------------*/
   if (b_tpos != NULL)   t  = *b_tpos;
   if (b_spos != NULL)   s  = *b_spos;
   if (b_rpos != NULL)   r  = *b_rpos;
   if (b_ppos != NULL)   p  = *b_ppos;
   /*---(specific adjustments)-----------*/
   if (n == 0)  yscore_pos__next (-1, -1, &t, &s, &r, &p);
   /*---(set increment)------------------*/
   rc = yscore_pos__next (n, a_table [n].s_sample, &t, &s, &r, &p);
   --rce;  if (rc < 0)             return rce;
   /*---(checks)-------------------------*/
   --rce;  if (t <  0)             return rce;
   --rce;  if (t >= LEN_FULL - 1)  return rce;
   --rce;  if (s <  0)             return rce;
   --rce;  if (s >= LEN_FULL - 1)  return rce;
   --rce;  if (r <  0)             return rce;
   --rce;  if (r >= LEN_FULL - 1)  return rce;
   --rce;  if (p <  0)             return rce;
   --rce;  if (p >= LEN_FULL - 1)  return rce;
   /*---(save-back)----------------------*/
   if (b_tpos != NULL)   *b_tpos = t;
   if (b_spos != NULL)   *b_spos = s;
   if (b_rpos != NULL)   *b_rpos = r;
   if (b_ppos != NULL)   *b_ppos = p;
   /*---(complete)-----------------------*/
   return 0;
}

char
yscore_pos_accum        (tSCORE_TABLE *a_table, char a_type, short n, short *r_pos)
{
   switch (a_type) {
   case 't' :  return yscore_pos__accum (a_table, n, r_pos, NULL , NULL , NULL );  break;
   case 's' :  return yscore_pos__accum (a_table, n, NULL , r_pos, NULL , NULL );  break;
   case 'r' :  return yscore_pos__accum (a_table, n, NULL , NULL , r_pos, NULL );  break;
   case 'p' :  return yscore_pos__accum (a_table, n, NULL , NULL , NULL , r_pos);  break;
   default  :  return -99;
   }
   return -10;
}



