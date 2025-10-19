/*===[[ START ]]==============================================================*/
#include    "ySCORE.h"
#include    "ySCORE_priv.h"



char
ySCORE_init             (tySCORE_TB *a_table, char a_validity, void **b_new)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   tySCORE    *x_new       = NULL;
   int         x_tries     =    0;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(check return)-------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YSCORE   yLOG_point   ("b_new"     , b_new);
   --rce;  if (b_new == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YSCORE   yLOG_point   ("*b_new"    , *b_new);
   --rce;  if (*b_new != NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(allocate)-----------------------*/
   while (x_new == NULL) {
      ++x_tries;
      x_new = malloc (sizeof (tySCORE));
      if (x_tries > 3)   break;
   }
   DEBUG_YSCORE   yLOG_value   ("x_tries"   , x_tries);
   DEBUG_YSCORE   yLOG_point   ("x_new"     , x_new);
   --rce;  if (x_new == NULL) {
      DEBUG_YSCORE   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(set key values)-----------------*/
   x_new->m_table    = a_table;
   x_new->m_validity = a_validity;
   /*---(wipe)---------------------------*/
   rc = ySCORE_clear (x_new);
   DEBUG_YSCORE   yLOG_value   ("clear"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save pointer)-------------------*/
   *b_new = x_new;
   DEBUG_YSCORE   yLOG_point   ("*b_new"    , *b_new);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   return 1;
}

char
ySCORE_wrap             (void **b_old)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   tySCORE    *x_old       = NULL;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(check return)-------------------*/
   DEBUG_YSCORE   yLOG_point   ("b_old"     , b_old);
   --rce;  if (b_old == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YSCORE   yLOG_point   ("*b_old"    , *b_old);
   --rce;  if (*b_old == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(clear and return)---------------*/
   x_old = *b_old;
   free (x_old);
   *b_old = NULL;
   DEBUG_YSCORE   yLOG_point   ("*b_old"    , *b_old);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   return 1;
}

char
yscore_clear            (tySCORE_TB *a_table, short *r_max, char r_terse [LEN_FULL], char r_score [LEN_FULL], char r_full [LEN_FULL], char r_report [LEN_PATH], char r_poly [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         i           =    0;
   char        s           [LEN_SHORT] = "";
   char        f           [LEN_SHORT] = "";
   char        t           [LEN_SHORT] = "";
   char        r           [LEN_SHORT] = "";
   char        p           [LEN_SHORT] = "";
   char        x_terse     [LEN_FULL]  = "";
   char        x_score     [LEN_FULL]  = "";
   char        x_full      [LEN_FULL]  = "";
   char        x_report    [LEN_FULL]  = "";
   char        x_poly      [LEN_FULL]  = "";
   char        x_lead      =  'y';
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_max    != NULL)  *r_max  = -1;
   if (r_terse  != NULL)  strlcpy (r_terse , "", LEN_FULL);
   if (r_score  != NULL)  strlcpy (r_score , "", LEN_FULL);
   if (r_full   != NULL)  strlcpy (r_full  , "", LEN_FULL);
   if (r_report != NULL)  strlcpy (r_report, "", LEN_PATH);
   if (r_poly   != NULL)  strlcpy (r_poly  , "", LEN_FULL);
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring clear called without scoring table");
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(create)-------------------------*/
   for (i = 0; i < LEN_FULL; ++i) {
      DEBUG_YSCORE   yLOG_complex ("line"      , "%3d %-10.10s %c", i, a_table [i].s_label, a_table [i].s_sample);
      /*---(test for end)----------------*/
      if (strncmp (a_table [i].s_label, "end-", 4) == 0)  break;
      switch (a_table [i].s_sample) {
      case  0  :
         strlcpy (s     , a_table [i].s_label , LEN_SHORT);
         strlcpy (f     , a_table [i].s_label , LEN_SHORT);
         strlcpy (t     , ""                  , LEN_SHORT);
         strlcpy (r     , ""                  , LEN_SHORT);
         if (x_lead == 'y') {
            strlcpy (p     , "å"   , LEN_SHORT);
            x_lead = '-';
         } else {
            strlcpy (p     , "æ¬å" , LEN_SHORT);
         }
         break;
      case  1  :
         strlcpy (s     , " "   , LEN_SHORT);
         strlcpy (f     , " "   , LEN_SHORT);
         strlcpy (t     , " "   , LEN_SHORT);
         strlcpy (r     , " "   , LEN_SHORT);
         strlcpy (p     , "á"   , LEN_SHORT);
         break;
      case  3  :
         strlcpy (s     , "   " , LEN_SHORT);
         strlcpy (f     , "   " , LEN_SHORT);
         strlcpy (t     , "   " , LEN_SHORT);
         strlcpy (r     , "  "  , LEN_SHORT);
         strlcpy (p     , ""    , LEN_SHORT);
         break;
      default  :
         sprintf  (s, "%c" , a_table [i].s_default);
         sprintf  (f, "%c" , a_table [i].s_sample);
         sprintf  (t, "%c" , a_table [i].s_default);
         sprintf  (r, " %c", a_table [i].s_default);
         sprintf  (p, "%c" , a_table [i].s_default);
      }
      strlcat (x_full  , f  , LEN_FULL);
      strlcat (x_score , s  , LEN_FULL);
      strlcat (x_terse , t  , LEN_FULL);
      strlcat (x_report, r  , LEN_FULL);
      strlcat (x_poly  , p  , LEN_FULL);
   }
   /*---(finish)-------------------------*/
   strlcat (x_poly, "æ", LEN_FULL);
   /*---(save-back)----------------------*/
   if (r_max    != NULL)  *r_max  = i;
   if (r_terse  != NULL)  strlcpy (r_terse , x_terse , LEN_FULL);
   if (r_score  != NULL)  strlcpy (r_score , x_score , LEN_FULL);
   if (r_full   != NULL)  strlcpy (r_full  , x_full  , LEN_FULL);
   if (r_report != NULL)  strlcpy (r_report, x_report, LEN_PATH);
   if (r_poly   != NULL)  strlcpy (r_poly  , x_poly  , LEN_FULL);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
ySCORE_clear            (void *a_cur)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   tySCORE    *x_cur       = NULL;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(check return)-------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_cur"     , a_cur);
   --rce;  if (a_cur == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(type)---------------------------*/
   x_cur = (tySCORE*) a_cur;
   DEBUG_YSCORE   yLOG_point   ("x_cur"     , x_cur);
   /*---(call clear)---------------------*/
   rc = yscore_clear (x_cur->m_table, &(x_cur->m_max), x_cur->o_terse, x_cur->o_score, x_cur->o_full, x_cur->o_report, x_cur->o_poly);
   DEBUG_YSCORE   yLOG_value   ("clear"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit   (__FUNCTION__);
   return 1;
}

char
yscore_data      (tySCORE *a_cur, short n, char r_label [LEN_TERSE], char *r_default, char *r_sample, char r_print [LEN_TERSE], char r_desc [LEN_DESC], char r_valid [LEN_TITLE], char r_legend [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(defaults)-----------------------*/
   if (r_label   != NULL)   strcpy (r_label   , "");
   if (r_default != NULL)   *r_default = '?';
   if (r_sample  != NULL)   *r_sample  = '?';
   if (r_print   != NULL)   strcpy (r_print   , "");
   if (r_desc    != NULL)   strcpy (r_desc    , "");
   if (r_valid   != NULL)   strcpy (r_valid   , "");
   if (r_legend  != NULL)   strcpy (r_legend  , "");
   /*---(check return)-------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_cur"     , a_cur);
   --rce;  if (a_cur == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_value   ("n"         , n);
   --rce;  if (n <  0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YSCORE   yLOG_value   ("m_max"     , a_cur->m_max);
   --rce;  if (n > a_cur->m_max) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_label   != NULL)   strlcpy (r_label   , (a_cur->m_table) [n].s_label   , LEN_TERSE);
   if (r_default != NULL)   *r_default = (a_cur->m_table) [n].s_default;
   if (r_sample  != NULL)   *r_sample  = (a_cur->m_table) [n].s_sample;
   if (r_print   != NULL)   strlcpy (r_print   , (a_cur->m_table) [n].s_print   , LEN_TERSE);
   if (r_desc    != NULL)   strlcpy (r_desc    , (a_cur->m_table) [n].s_desc    , LEN_DESC);
   if (r_valid   != NULL)   strlcpy (r_valid   , (a_cur->m_table) [n].s_valid   , LEN_TITLE);
   if (r_legend  != NULL)   strlcpy (r_legend  , (a_cur->m_table) [n].s_legend  , LEN_FULL);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   return 1;
}


