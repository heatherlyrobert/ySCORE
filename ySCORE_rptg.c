/*===[[ START ]]==============================================================*/
#include    "ySCORE.h"
#include    "ySCORE_priv.h"


char*
yscore_output           (tySCORE *a_cur, char a_which)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *x_output    = NULL;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(check return)-------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_cur"     , a_cur);
   --rce;  if (a_cur == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(no table)";
   }
   DEBUG_YSCORE   yLOG_char    ("a_which"   , a_which);
   switch (a_which) {
   case 't' :  x_output = a_cur->o_terse;    break;
   case 's' :  x_output = a_cur->o_score;    break;
   case 'f' :  x_output = a_cur->o_full;     break;
   case 'r' :  x_output = a_cur->o_report;   break;
   case 'p' :  x_output = a_cur->o_poly;     break;
   default  :  x_output = "(unknown type)";
   }
   DEBUG_YSCORE   yLOG_info    ("x_output"  , x_output);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   return x_output;
}


char*   ySCORE_terse      (void *a_cur)  { return yscore_output (a_cur, 't'); }
char*   ySCORE_score      (void *a_cur)  { return yscore_output (a_cur, 's'); }
char*   ySCORE_full       (void *a_cur)  { return yscore_output (a_cur, 'f'); }
char*   ySCORE_report     (void *a_cur)  { return yscore_output (a_cur, 'r'); }
char*   ySCORE_poly       (void *a_cur)  { return yscore_output (a_cur, 'p'); }



char*
yscore__title           (tySCORE *a_cur, tySCORE_TB *a_table, char a_type)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         x_max       =    0;
   int         i           =    0;
   int         x_curr      =    0;
   int         x_prev      =    0;
   int         l           =    0;
   int         o           =    0;
   int         j           =    0;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring title called without scoring table");
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(no table)";
   }
   /*---(make base)----------------------*/
   DEBUG_YSCORE   yLOG_char    ("a_type"    , a_type);
   --rce;  switch (a_type) {
   case 't'  :  x_max = strlen (a_cur->o_terse ); break;
   case 's'  :  x_max = strlen (a_cur->o_score ); break;
   case 'r'  :  x_max = strlen (a_cur->o_report); break;
   case 'p'  :  x_max = strlen (a_cur->o_poly  ); break;
   default   :
                   DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
                   return "(bad type)";
   }
   DEBUG_YSCORE   yLOG_value   ("x_max"     , x_max);
   snprintf (g_print, LEN_FULL, "%*.*s", x_max, x_max, "                                                                                                                                                                                                        ");
   DEBUG_YSCORE   yLOG_complex ("g_print"   , "%3då%sæ", x_max, g_print);
   /*---(prepare)------------------------*/
   rc = yscore_pos_next  (a_table, a_type, -1, &x_curr);
   x_prev = x_curr;
   /*---(create)-------------------------*/
   --rce;  for (i = 0; i < LEN_FULL; ++i) {
      /*---(test for end)----------------*/
      if (strncmp (a_table [i].s_label, "end-", 4) == 0) {
         DEBUG_YSCORE   yLOG_note    ("hit end-list");
         if (strchr ("² ", g_print [x_max - 1]) != NULL)  g_print [x_max - 1] = '‚';
         break;
      }
      /*---(accumulate)------------------*/
      rc = yscore_pos_next  (a_table, a_type, i, &x_curr);
      DEBUG_YSCORE   yLOG_complex ("accum"     , "%3d) %3d, inc %3d, pos %3d", i, a_table [i].s_sample, rc, x_curr);
      /*---(block)----------------------*/
      if (a_table [i].s_sample == 0) {
         DEBUG_YSCORE   yLOG_note    ("BLOCK hit");
         /*---(prepare)---------------------*/
         l = strlen (a_table [i].s_print);
         DEBUG_YSCORE   yLOG_complex ("PREFIX"    , "%3d, %2då%sæ", i, l, a_table [i].s_print);
         for (j = 0; j < l; ++j) {
            if (a_type == 'r')  o = x_curr + j;
            else                o = x_prev + j;
            if (o < 0 || o >= x_max) {
               DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
               strlcat (g_print, "  (out of range)", LEN_FULL);
               return g_print;
            }
            DEBUG_YSCORE   yLOG_complex ("fill-in"   , "%3d, %c/%3d", o, a_table [i].s_print [j], a_table [i].s_print [j]);
            g_print [o] = a_table [i].s_print [j];
         }
         if (a_type == 'r')  o = x_curr;
         else                o = x_prev;
         for (j = o + l; j < x_max; ++j)  {
            if (strchr ("² ", g_print [j]) != NULL)  g_print [j] = '²';
         }
      }
      /*---(large space)----------------*/
      if (a_table [i].s_sample == 3) {
         DEBUG_YSCORE   yLOG_note    ("LARGE SPACE hit");
         l = strlen (a_table [i].s_print);
         if      (a_type == 'r')  o = x_curr - 3;
         else if (a_type == 'p')  o = x_prev;
         else                     o = x_prev - 1;
         for (j = o + l; j < x_max; ++j) {
            if (strchr ("² ", g_print [j]) != NULL)  g_print [j] = ' ';
         }
         if (strchr ("² ", g_print [o]) != NULL)  g_print [o] = '‚';
      }
      /*---(save position)---------------*/
      x_prev = x_curr;
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return g_print;
}

char*
ySCORE_title            (void *a_cur, char a_type)
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
      return "(no table)";
   }
   /*---(type)---------------------------*/
   x_cur = (tySCORE*) a_cur;
   DEBUG_YSCORE   yLOG_point   ("x_cur"     , x_cur);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   yscore__title (x_cur, x_cur->m_table , a_type);
   /*---(complete)-----------------------*/
   return g_print;
}

char*
yscore__header          (tySCORE_TB *a_table, char n)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         i           =    0;
   int         l           =    0;
   int         o           =    0;
   char        t           [LEN_SHORT] = "";
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring rpt_heads called without scoring table");
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(no table)";
   }
   /*---(defense)------------------------*/
   --rce;  if (n < 0 || n > 6) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return g_print;
   }
   /*---(initialize)---------------------*/
   strcpy (g_print, "");
   /*---(create line)--------------------*/
   DEBUG_YSCORE   yLOG_note    ("PRINT LINES...");
   for (i = 0; i < LEN_FULL; ++i) {
      /*---(test for end)----------------*/
      if (strncmp (a_table [i].s_label, "end-", 4) == 0)  break;
      /*---(prepare)---------------------*/
      l = strlen (a_table [i].s_print);
      DEBUG_YSCORE   yLOG_complex ("item"      , "%3d, %c/%3d, %2då%sæ", i, a_table [i].s_sample, a_table [i].s_sample, l, a_table [i].s_print);
      /*---(normal stuff)---------------*/
      switch (a_table [i].s_sample) {
      case  0  : strcpy   (t, ""); break;
      case  1  : strcpy (t, " " ); break;
      case  3  : strcpy (t, "  "); break;
      default  :
                 if      (n == 0)   strcpy   (t, " -");
                 else if (n >  l)   strlcpy  (t, " ·", LEN_SHORT);
                 else             { o = l - n; sprintf  (t, " %c", a_table [i].s_print [o]); }
      }
      strlcat (g_print, t  , LEN_FULL);
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return g_print;
}

char*
ySCORE_header           (void *a_cur, char n) 
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
      return "(no table)";
   }
   /*---(type)---------------------------*/
   x_cur = (tySCORE*) a_cur;
   DEBUG_YSCORE   yLOG_point   ("x_cur"     , x_cur);
   /*---(call header)--------------------*/
   yscore__header  (x_cur->m_table , n);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return g_print;
}

char*
yscore__legend          (tySCORE_TB *a_table, char a_line, char a_label [LEN_TERSE], char a_terse [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         l           =    0;
   int         i           =    0;
   short       x_beg       =   -1;
   short       x_end       =   -1;
   short       x_cnt       =    0;
   short       x_off       =    0;
   uchar       x_samp      =  '-';
   char        t           [LEN_HUND]  = "";
   short       x_pos       =    0;
   char       *x_heads     = "   --label--  -print-  ---description------------  ---possible-values-------------------------------------------------------------";
   char        c           =    0;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   strlcpy (g_print, "", LEN_RECD);
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(null table)";
   }
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_label"   , a_label);
   --rce;  if (a_label == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(null label)";
   }
   DEBUG_YSCORE   yLOG_info    ("a_label"   , a_label);
   --rce;  if (a_label [0] == ' ') {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(spacer/gap label)";
   }
   l = strlen (a_label);
   DEBUG_YSCORE   yLOG_value   ("l"         , l);
   --rce;  if (l != 4 || a_label [0] == ' ' || a_label [2] != 'á' || a_label [3] != ' ') {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(label not lead)";
   }
   /*---(find bounds)--------------------*/
   --rce;  for (i = 0; i < LEN_FULL; ++i) {
      /*---(test for end-list)-----------*/
      if (strncmp (a_table [i].s_label, "end-", 4) == 0) {
         x_end = i - 1;
         break;
      }
      x_samp = a_table [i].s_sample;
      /*---(find beginning)--------------*/
      if (strcmp  (a_table [i].s_label, a_label)   == 0)  x_beg = i;
      if (x_beg < 0)  continue;
      /*---(find end)--------------------*/
      if (a_table [i].s_sample == 3)                      x_end = i - 1;
      if (x_end > 0)  break;
      /*---(count)-----------------------*/
      x_samp = a_table [i].s_sample;
      if (x_samp > 3)  ++x_cnt;
      /*---(done)------------------------*/
   }
   /*---(check for trouble)--------------*/
   DEBUG_YSCORE   yLOG_complex ("bounds"    , "%3db, %3de, %3d#", x_beg, x_end, x_cnt);
   --rce;  if (x_beg < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(beg not found)";
   }
   --rce;  if (x_end < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(end not found)";
   }
   --rce;  if (x_cnt < 1) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(count < 1)";
   }
   /*---(start)--------------------------*/
   rc = yscore_pos (a_table, 0, a_table [x_beg].s_label, NULL, &x_off, NULL, NULL, NULL);
   DEBUG_YSCORE   yLOG_value   ("pos"       , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(beg pos < 0)";
   }
   DEBUG_YSCORE   yLOG_value   ("x_off"     , x_off);
   /*---(leads)--------------------------*/
   if (a_line > 0 && a_line <= x_cnt) {
      x_pos = x_cnt;
      for (i = x_beg; i <= x_end; ++i) {
         x_samp = a_table [i].s_sample;
         switch (x_samp) {
         case  0 :
            strlcat (g_print, "    ", LEN_RECD);
            break;
         case  1 :
            if (a_line >  x_pos)  strlcat (g_print, "²"   , LEN_RECD);
            else                  strlcat (g_print, " "   , LEN_RECD);
            break;
         default :
            /*---(normal)----------------*/
            if      (a_line <  x_pos)  strlcat (g_print, "Œ"   , LEN_RECD);
            else if (a_line == x_pos)  strlcat (g_print, "ƒ"   , LEN_RECD);
            else if (a_line >  x_pos)  strlcat (g_print, "²"   , LEN_RECD);
            /*---(accum)-----------------*/
            --x_pos;
            break;
            /*---(done)------------------*/
         }
      }
   }
   /*---(legend)-------------------------*/
   if (a_line > 0 && a_line <= x_cnt) {
      x_pos = x_cnt;
      for (i = x_beg; i <= x_end; ++i) {
         x_samp = a_table [i].s_sample;
         if (x_samp > 3) {
            if (a_line == x_pos) {
               strlcat (g_print, "²´ ", LEN_RECD);
               snprintf (t, 12, "%s²²²²²²²²²²²²", a_table [i].s_label);
               strlcat (g_print, t    , LEN_RECD);
               if (a_table [i].s_print [0] != 'Œ') snprintf (t, 10, "%s²²²²²²²²²²²²", a_table [i].s_print);
               else                                snprintf (t, 10, "%s²²²²²²²²²²²²", "");
               strlcat (g_print, t    , LEN_RECD);
               snprintf (t, 26, "%s²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²", a_table [i].s_desc);
               strlcat (g_print, t    , LEN_RECD);
               snprintf (t, 83, ">  %s                                                                                          ", a_table [i].s_legend);
               strlcat (g_print, t    , LEN_RECD);
            }
            --x_pos;
         }
      }
   }
   /*---(display)------------------------*/
   if (a_line == 0) {
      for (i = x_beg; i <= x_end; ++i) {
         x_samp = a_table [i].s_sample;
         sprintf (t, "%c", x_samp);
         switch (x_samp) {
         case  0 :  strlcat (g_print, a_table [i].s_label, LEN_RECD); break;
         case  1 :  strlcat (g_print, " "                , LEN_RECD); break;
         default :  strlcat (g_print, t                  , LEN_RECD); break;
         }
      }
      /*---(header)----------------------*/
      strlcat (g_print, x_heads, LEN_RECD);
      /*---(done)------------------------*/
   }
   /*---(display)------------------------*/
   if (a_line == x_cnt + 1) {
      c = 0;
      for (i = x_beg; i <= x_end; ++i) {
         x_samp = a_table [i].s_sample;
         switch (x_samp) {
         case  0 :  c += 4; break;
         case  1 :  c += 1; break;
         default :  c += 1; break;
         }
      }
      strlcpy (g_print, a_table [x_beg].s_print, LEN_RECD);
      strlcat (g_print, "²LEGEND"              , LEN_RECD);
      strlcat (g_print, "²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²", LEN_RECD);
      g_print [c - 2] = '\0';
      strlcat (g_print, ">>", LEN_RECD);
      strlcat (g_print, x_heads, LEN_RECD);
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return g_print;
}

char*
ySCORE_legend           (void *a_cur, char a_line, char a_label [LEN_TERSE])
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
      return "(no table)";
   }
   /*---(type)---------------------------*/
   x_cur = (tySCORE*) a_cur;
   DEBUG_YSCORE   yLOG_point   ("x_cur"     , x_cur);
   /*---(call legend)--------------------*/
   yscore__legend (x_cur->m_table, a_line, a_label, x_cur->o_terse);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return g_print;
}


