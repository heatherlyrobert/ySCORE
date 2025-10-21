/*===[[ START ]]==============================================================*/
#include    "ySCORE.h"
#include    "ySCORE_priv.h"


char*
yscore_output           (tySCORE *a_hand, char a_which)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char       *x_output    = NULL;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(check return)-------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_hand"    , a_hand);
   --rce;  if (a_hand == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(no table)";
   }
   DEBUG_YSCORE   yLOG_char    ("a_which"   , a_which);
   switch (a_which) {
   case 't' :  x_output = a_hand->o_terse;    break;
   case 's' :  x_output = a_hand->o_score;    break;
   case 'f' :  x_output = a_hand->o_full;     break;
   case 'r' :  x_output = a_hand->o_report;   break;
   case 'p' :  x_output = a_hand->o_poly;     break;
   default  :  x_output = "(unknown type)";
   }
   DEBUG_YSCORE   yLOG_info    ("x_output"  , x_output);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   return x_output;
}


char*   ySCORE_terse      (void *v_hand)  { return yscore_output (v_hand, 't'); }
char*   ySCORE_score      (void *v_hand)  { return yscore_output (v_hand, 's'); }
char*   ySCORE_full       (void *v_hand)  { return yscore_output (v_hand, 'f'); }
char*   ySCORE_report     (void *v_hand)  { return yscore_output (v_hand, 'r'); }
char*   ySCORE_poly       (void *v_hand)  { return yscore_output (v_hand, 'p'); }



char*
yscore__title           (tySCORE *a_hand, tySCORE_TB *a_table, char a_type)
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
   case 't'  :  x_max = strlen (a_hand->o_terse ); break;
   case 's'  :  x_max = strlen (a_hand->o_score ); break;
   case 'r'  :  x_max = strlen (a_hand->o_report); break;
   case 'p'  :  x_max = strlen (a_hand->o_poly  ); break;
   default   :
                DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
                return "(bad type)";
   }
   DEBUG_YSCORE   yLOG_value   ("x_max"     , x_max);
   snprintf (g_print, LEN_PATH, "%*.*s", x_max, x_max, "                                                                                                                                                                                                        ");
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
               strlcat (g_print, "  (out of range)", LEN_PATH);
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
ySCORE_title            (void *v_hand, char a_type)
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
   /*---(complete)-----------------------*/
   DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
   yscore__title (x_hand, x_hand->m_table , a_type);
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
      strlcat (g_print, t  , LEN_PATH);
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return g_print;
}

char*
ySCORE_header           (void *v_hand, char n) 
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
   /*---(call header)--------------------*/
   yscore__header  (x_hand->m_table , n);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return g_print;
}

char         /*-> find bounds of legend area -----------------------[leaf···[f··]*/
yscore__legend_bounds   (tySCORE_TB *a_table, char a_section [LEN_TERSE], short *r_head, short *r_beg, short *r_end, short *r_cnt, short *r_npre)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         l           =    0;
   int         i           =    0;
   short       x_head      =   -1;
   short       x_beg       =   -1;
   short       x_end       =   -1;
   short       x_cnt       =    0;
   uchar       x_samp      =  '-';
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_head != NULL)  *r_head  = 0;
   if (r_beg  != NULL)  *r_beg   = 0;
   if (r_end  != NULL)  *r_end   = 0;
   if (r_cnt  != NULL)  *r_cnt   = 0;
   if (r_npre != NULL)  *r_npre  = 0;
   /*---(defense)------------------------*/
   DEBUG_YSCORE   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YSCORE   yLOG_point   ("a_section" , a_section);
   --rce;  if (a_section == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YSCORE   yLOG_info    ("a_section" , a_section);
   l = strlen (a_section);
   DEBUG_YSCORE   yLOG_value   ("l"         , l);
   --rce;  if (l != 4 || a_section [0] == ' ' || a_section [2] != 'á' && a_section [3] != ' ') {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(find bounds)--------------------*/
   --rce;  for (i = 0; i < LEN_FULL; ++i) {
      DEBUG_YSCORE   yLOG_complex ("line"      , "%3d, %-9.9s, %c/%4d", i, a_table [i].s_label, ychrvisible (a_table [i].s_sample), a_table [i].s_sample);
      /*---(test for end-list)-----------*/
      if (strncmp (a_table [i].s_label, "end-", 4) == 0) {
         x_end = i - 1;
         break;
      }
      /*---(find beginning)--------------*/
      if (strcmp  (a_table [i].s_label, a_section)   == 0) {
         x_head = i;
         DEBUG_YSCORE   yLOG_value   ("x_head"    , x_head);
         x_beg  = i + 1;
         DEBUG_YSCORE   yLOG_value   ("x_beg"     , x_beg);
      }
      if (x_beg < 0)  continue;
      /*---(find end)--------------------*/
      if (a_table [i].s_sample == 3) {
         x_end = i - 1;
         DEBUG_YSCORE   yLOG_value   ("x_end"     , x_end);
      }
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
      return rce;
   }
   --rce;  if (x_end < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (x_cnt < 1) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_head != NULL)  *r_head  = x_head;
   if (r_beg  != NULL)  *r_beg   = x_beg;
   if (r_end  != NULL)  *r_end   = x_end;
   if (r_cnt  != NULL)  *r_cnt   = x_cnt;
   if (r_npre != NULL)  *r_npre  = (x_end - x_beg) + 1 + 4 + 3;  /* 4 for section label, 3 more for marker */
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return 1;
}
/*>                                                                                    <* 
 *> -123456789-123456789-123456789-123456789-                                          <* 
 *>      Ô´ 6                         ´ 34       29     34 - 6 = 28 + 1 + 4 = 33       <* 
 *>                                                                                    <*/

char*
yscore__legend_lead     (tySCORE_TB *a_table, short a_beg, short a_cur, short a_end, short a_npre, char r_fill [LEN_SHORT], char r_cap [LEN_SHORT])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   static char x_print     [LEN_HUND]  = "";
   uchar       x_prev      =  '·';
   uchar       x_samp      =  '·';
   short       x_pos       =    0;
   int         i           =    0;
   uchar       x_vert      [LEN_SHORT] = "Œ";
   uchar       x_horz      [LEN_SHORT] = "²";
   uchar       x_corner    [LEN_SHORT] = "ƒ";
   uchar       x_mark      [LEN_SHORT] = "²³ ";
   uchar       x_cap       [LEN_SHORT] = ">  ";
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_fill  != NULL)   strcpy (r_fill, "");
   if (r_cap   != NULL)   strcpy (r_cap , "");
   /*---(clear print)--------------------*/
   strcpy (x_print, "    ");
   /*---(defense)------------------------*/
   --rce;  if (a_table == NULL) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(bad table)";
   }
   --rce;  if (a_beg  <= 0)     {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(a_beg <= 0)";
   }
   --rce;  if (a_cur  <= 0)     {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(a_cur <= 0)";
   }
   --rce;  if (a_end  <= 0)     {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(a_end <= 0)";
   }
   --rce;  if (a_cur  <  a_beg) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(a_cur < a_beg)";
   }
   --rce;  if (a_cur  >  a_end) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(a_cur > a_end)";
   }
   --rce;  if (a_npre <  4)     {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(a_npre < 4)";
   }
   /*---(prepare)------------------------*/
   x_prev = a_table [a_cur - 1].s_sample;
   x_samp = a_table [a_cur].s_sample;
   DEBUG_YSCORE   yLOG_complex ("a_cur"     , "%3d) %-9.9s, x_prev=%c, x_samp=%c", a_cur, a_table [a_cur].s_label, x_prev, x_samp);
   if (x_samp <= 3) {
      DEBUG_YSCORE   yLOG_exit    (__FUNCTION__);
      return "(skip)";
   }
   if (x_prev > 3) {
      strcpy (x_horz, "·");
      strcpy (x_mark, "·´ ");
      strcpy (x_corner, "á");
      strcpy (x_cap   , "´  ");
   }
   DEBUG_YSCORE   yLOG_complex ("marks"     , "corner=%s  horz=%s  mark=%s", x_corner, x_horz, x_mark);
   /*---(run list)-----------------------*/
   for (i = a_beg; i <= a_end; ++i) {
      /*---(get data)--------------------*/
      x_prev = a_table [i - 1].s_sample;
      x_samp = a_table [i].s_sample;
      /*---(set marker)------------------*/
      if      (x_prev <= 3)  strcpy (x_vert, "Œ");
      else                   strcpy (x_vert, "·");
      if      (x_samp == 1)  strcpy (x_vert, " ");
      DEBUG_YSCORE   yLOG_complex ("line"      , "%3d) %-9.9s, x_prev=%c, x_samp=%c, vert=%s", i, a_table [i].s_label, ychrvisible (x_prev), ychrvisible (x_samp), x_vert);
      /*---(pick mark)-------------------*/
      if      (i <  a_cur)  strlcat (x_print, x_vert  , LEN_HUND);
      else if (i == a_cur)  strlcat (x_print, x_corner, LEN_HUND);
      else                  strlcat (x_print, x_horz  , LEN_HUND);
      /*---(done)------------------------*/
      DEBUG_YSCORE   yLOG_info    ("x_print"   , x_print);
   }
   /*---(final mark)---------------------*/
   strlcat (x_print, x_mark  , LEN_HUND);
   DEBUG_YSCORE   yLOG_info    ("x_print"   , x_print);
   /*---(save-back)----------------------*/
   if (r_fill  != NULL)   strcpy (r_fill, x_horz);
   if (r_cap   != NULL)   strcpy (r_cap , x_cap);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return x_print;
}

char*
yscore__legend_detail   (tySCORE_TB *a_table, short a_cur, char a_fill [LEN_SHORT], char a_cap [LEN_SHORT])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        t           [LEN_FULL]  = "";
   static char x_print     [LEN_FULL]  = "";
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   strlcpy (x_print, "", LEN_FULL);
   /*---(label)--------------------------*/
   snprintf (t, 12, "%s²²²²²²²²²²²²", a_table [a_cur].s_label);
   strlcat (x_print, t    , LEN_FULL);
   /*---(print)--------------------------*/
   if (a_table [a_cur].s_print [0] != 'Œ') snprintf (t, 10, "%s²²²²²²²²²²²²", a_table [a_cur].s_print);
   else                                    snprintf (t, 10, "%s²²²²²²²²²²²²", "");
   strlcat (x_print, t    , LEN_FULL);
   /*---(description)--------------------*/
   snprintf (t, 35, "%s²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²", a_table [a_cur].s_desc);
   strlcat (x_print, t    , LEN_FULL);
   /*---(fix filler)---------------------*/
   ystrldchg (x_print, '²', a_fill [0], LEN_FULL);
   ystrldchg (x_print, '·', a_fill [0], LEN_FULL);
   ystrldchg (x_print, ' ', a_fill [0], LEN_FULL);
   /*---(legend)-------------------------*/
   snprintf (t, 104, "%s%s                                                                                          ", a_cap, a_table [a_cur].s_legend);
   strlcat (x_print, t    , LEN_FULL);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return x_print;
}

char*
yscore__legend_full     (tySCORE_TB *a_table, char a_section [LEN_TERSE], char a_dir)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   short       x_head, x_beg, x_end, x_cnt, x_npre, x_max;
   static short x_cur      =    0;
   static char  x_save     [LEN_TERSE] = "";
   char        x_fill      [LEN_TERSE] = "";
   char        x_cap       [LEN_TERSE] = "";
   char       *x_lead      = NULL;
   char       *x_detail    = NULL;
   char       *x_heads     = "   --label--  -print-  ---description---------------------  ---possible-values----------------------------------------------------------------------------------";
   int         i           =    0;
   uchar       x_samp      =  '·';
   char        t           [LEN_TERSE] = "";
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   strlcpy (g_print, "", LEN_RECD);
   /*---(bounds)-------------------------*/
   DEBUG_YSCORE   yLOG_info    ("a_section" , a_section);
   rc = yscore__legend_bounds (a_table, a_section, &x_head, &x_beg, &x_end, &x_cnt, &x_npre);
   DEBUG_YSCORE   yLOG_value   ("bounds"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(bounds failed)";
   }
   x_max = x_end + 1;
   /*---(reset on section change)--------*/
   DEBUG_YSCORE   yLOG_info    ("x_save"    , x_save);
   DEBUG_YSCORE   yLOG_char    ("a_dir"     , a_dir);
   if (strcmp (a_section, x_save) != 0) {
      DEBUG_YSCORE   yLOG_note    ("changing sections");
      x_cur = x_head;
      strcpy (x_save, a_section);
      switch (a_dir) {
      case YDLST_HEAD : case YDLST_TOPP : case YDLST_BOTT : case YDLST_TAIL :
         break;
      default :
         DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
         return "(illegal first request)";
         break;
      }
      DEBUG_YSCORE   yLOG_char    ("a_dir"     , a_dir);
   }
   DEBUG_YSCORE   yLOG_complex ("pos"       , "%3dh, %3db, %3dc, %3de, %3dx", x_head, x_beg, x_cur, x_max);
   /*---(cursor)-------------------------*/
   switch (a_dir) {
   case YDLST_HEAD  : case YDLST_TOPP  :
      x_cur = x_head;
      break;
   case YDLST_NEXT  : case YDLST_BNEXT :
      ++x_cur;
      if (x_cur < x_max && a_table [x_cur].s_sample == 1) ++x_cur;
      break;
   case YDLST_CURR  : case YDLST_LUSED :
      break;
   case YDLST_PREV  : case YDLST_BPREV :
      --x_cur;
      if (x_cur > x_head && a_table [x_cur].s_sample == 1) --x_cur;
      break;
   case YDLST_TAIL  : case YDLST_BOTT  :
      x_cur = x_max;
      break;
   default          :
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(illegal request)";
      break;
   }
   DEBUG_YSCORE   yLOG_complex ("pos"       , "%3dh, %3db, %3dc, %3de, %3dx", x_head, x_beg, x_cur, x_max);
   /*---(limits)-------------------------*/
   if (x_cur < x_head) {
      x_cur = x_head;
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(x_cur < x_head)";
   }
   if (x_cur > x_max) {
      x_cur = x_max;
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(x_cur > x_max)";
   }
   /*---(header)-------------------------*/
   if (x_cur == x_head) {
      strlcpy (g_print, a_table [x_cur].s_print, LEN_RECD);
      strlcat (g_print, "-LEGEND"              , LEN_RECD);
      strlcat (g_print, "---------------------------------------------------------------", LEN_RECD);
      g_print [x_npre - 5] = '\0';
      strlcat (g_print, ">>", LEN_RECD);
      strlcat (g_print, x_heads, LEN_RECD);
      return g_print;
   }
   /*---(footer)-------------------------*/
   if (x_cur == x_max) {
      for (i = x_head; i <= x_end; ++i) {
         x_samp = a_table [i].s_sample;
         sprintf (t, "%c", x_samp);
         switch (x_samp) {
         case  0 :  strlcat (g_print, a_table [i].s_label, LEN_RECD); break;
         case  1 :  strlcat (g_print, " "                , LEN_RECD); break;
         default :  strlcat (g_print, t                  , LEN_RECD); break;
         }
      }
      strlcat (g_print, x_heads, LEN_RECD);
      return g_print;
   }
   /*---(leader)-------------------------*/
   x_lead   = yscore__legend_lead   (a_table, x_beg, x_cur, x_end, x_npre, x_fill, x_cap);
   DEBUG_YSCORE   yLOG_value   ("lead"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(lead failed)";
   }
   /*---(leader)-------------------------*/
   x_detail = yscore__legend_detail (a_table, x_cur, x_fill, x_cap);
   DEBUG_YSCORE   yLOG_value   ("lead"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(detail failed)";
   }
   /*---(contatinate)--------------------*/
   sprintf (g_print, "%s%s", x_lead, x_detail);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return g_print;
}

char*
yscore__legend_OLD      (tySCORE_TB *a_table, char a_line, char a_label [LEN_TERSE], char a_terse [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         l           =    0;
   int         i           =    0;
   short       x_head      =   -1;
   short       x_beg       =   -1;
   short       x_end       =   -1;
   short       x_cnt       =    0;
   short       x_npre      =    0;
   short       x_off       =    0;
   uchar       x_samp      =  '-';
   char        t           [LEN_HUND]  = "";
   short       x_pos       =    0;
   char       *x_heads     = "   --label--  -print-  ---description---------------------  ---possible-values-------------------------------------------------------------";
   char        c           =    0;
   short       x_prv       =    0;
   short       x_cur       =   -1;
   /*---(header)-------------------------*/
   DEBUG_YSCORE   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   strlcpy (g_print, "", LEN_RECD);
   /*---(defense)------------------------*/
   rc = yscore__legend_bounds (a_table, a_label, &x_head, &x_beg, &x_end, &x_cnt, &x_npre);
   DEBUG_YSCORE   yLOG_value   ("bounds"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
      return "(error)";
   }
   /*---(start)--------------------------*/
   rc = yscore_pos (a_table, 0, a_table [x_beg].s_label, &x_cur, &x_off, NULL, NULL, NULL);
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
            if (a_line >  x_pos) {
               if (x_cur == x_prv + 1)  strlcat (g_print, "·"   , LEN_RECD);
               else                     strlcat (g_print, "²"   , LEN_RECD);
            }
            else                  strlcat (g_print, " "   , LEN_RECD);
            break;
         default :
            /*---(normal)----------------*/
            if      (a_line <  x_pos) {
               if (x_cur == x_prv + 1)  strlcat (g_print, "·"   , LEN_RECD);
               else                     strlcat (g_print, "Œ"   , LEN_RECD);
            }
            else if (a_line == x_pos)  strlcat (g_print, "ƒ"   , LEN_RECD);
            else if (a_line >  x_pos) {
               if (x_cur == x_prv + 1)  strlcat (g_print, "·"   , LEN_RECD);
               else                     strlcat (g_print, "²"   , LEN_RECD);
            }
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
               if (x_cur == x_prv + 1)  strlcat (g_print, "²´ " , LEN_RECD);
               else                     strlcat (g_print, "²³ " , LEN_RECD);
               snprintf (t, 12, "%s²²²²²²²²²²²²", a_table [i].s_label);
               strlcat (g_print, t    , LEN_RECD);
               if (a_table [i].s_print [0] != 'Œ') snprintf (t, 10, "%s²²²²²²²²²²²²", a_table [i].s_print);
               else                                snprintf (t, 10, "%s²²²²²²²²²²²²", "");
               strlcat (g_print, t    , LEN_RECD);
               snprintf (t, 35, "%s²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²", a_table [i].s_desc);
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
ySCORE_legend           (void *v_hand, char a_label [LEN_TERSE], char a_dir)
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
   /*---(call legend)--------------------*/
   yscore__legend_full (x_hand->m_table, a_label, a_dir);
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return g_print;
}


