/*===[[ START ]]==============================================================*/
#include    "ySCORE.h"
#include    "ySCORE_priv.h"




char
ySCORE_init             (tSCORE_TABLE *a_table)
{
   mySCORE.m_table = a_table;
   ySCORE_clear ();
   return 0;
}

char
yscore_clear            (tSCORE_TABLE *a_table, short *r_max, char r_terse [LEN_FULL], char r_score [LEN_FULL], char r_full [LEN_FULL], char r_report [LEN_FULL], char r_poly [LEN_FULL])
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
   DEBUG_YSCORE   yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_max    != NULL)  *r_max  = -1;
   if (r_terse  != NULL)  strlcpy (r_terse , "", LEN_FULL);
   if (r_score  != NULL)  strlcpy (r_score , "", LEN_FULL);
   if (r_full   != NULL)  strlcpy (r_full  , "", LEN_FULL);
   if (r_report != NULL)  strlcpy (r_report, "", LEN_FULL);
   if (r_poly   != NULL)  strlcpy (r_poly  , "", LEN_FULL);
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_spoint  (a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring clear called without scoring table");
      DEBUG_YSCORE   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(create)-------------------------*/
   for (i = 0; i < LEN_FULL; ++i) {
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
   if (r_report != NULL)  strlcpy (r_report, x_report, LEN_FULL);
   if (r_poly   != NULL)  strlcpy (r_poly  , x_poly  , LEN_FULL);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char ySCORE_clear            (void) { return yscore_clear (mySCORE.m_table, &(mySCORE.m_max), mySCORE.o_terse, mySCORE.o_score, mySCORE.o_full, mySCORE.o_report, mySCORE.o_poly); }

char
yscore_data      (short n, char r_label [LEN_TERSE], char *r_default, char *r_sample, char r_print [LEN_TERSE], char r_desc [LEN_DESC], char r_valid [LEN_TITLE], char r_legend [LEN_FULL])
{
   char        rce         =  -10;
   if (r_label   != NULL)   strcpy (r_label   , "");
   if (r_default != NULL)   *r_default = '?';
   if (r_sample  != NULL)   *r_sample  = '?';
   if (r_print   != NULL)   strcpy (r_print   , "");
   if (r_desc    != NULL)   strcpy (r_desc    , "");
   if (r_valid   != NULL)   strcpy (r_valid   , "");
   if (r_legend  != NULL)   strcpy (r_legend  , "");
   --rce;  if (n <  0)             return rce;
   --rce;  if (n > mySCORE.m_max)  return rce;
   if (r_label   != NULL)   strlcpy (r_label   , (mySCORE.m_table) [n].s_label   , LEN_TERSE);
   if (r_default != NULL)   *r_default = (mySCORE.m_table) [n].s_default;
   if (r_sample  != NULL)   *r_sample  = (mySCORE.m_table) [n].s_sample;
   if (r_print   != NULL)   strlcpy (r_print   , (mySCORE.m_table) [n].s_print   , LEN_TERSE);
   if (r_desc    != NULL)   strlcpy (r_desc    , (mySCORE.m_table) [n].s_desc    , LEN_DESC);
   if (r_valid   != NULL)   strlcpy (r_valid   , (mySCORE.m_table) [n].s_valid   , LEN_TITLE);
   if (r_legend  != NULL)   strlcpy (r_legend  , (mySCORE.m_table) [n].s_legend  , LEN_FULL);
   return 0;
}


