/*===[[ START ]]==============================================================*/
#include    "ySCORE.h"
#include    "ySCORE_priv.h"



tSCORE      mySCORE = { NULL, -1, "", "", "", "", "" };
char        g_print     [LEN_RECD]  = "";



/*====================------------------------------------====================*/
/*===----                            program                           ----===*/
/*====================------------------------------------====================*/
void  o___PROGRAM_________o () { return; }

static char s_version    [LEN_HUND];

char*        /*--> return versioning information ---------[ ------ [ ------ ]-*/
ySCORE_version          (void)
{
   char        t [LEN_LABEL] = "";
#if    __TINYC__ > 0
   strncpy (t, "[tcc built  ]", LEN_LABEL);
#elif  __GNUC__  > 0
   strncpy (t, "[gnu gcc    ]", LEN_LABEL);
#elif  __HEPH__  > 0
   strncpy (t, "[hephaestus ]", LEN_LABEL);
#else
   strncpy (t, "[unknown    ]", LEN_LABEL);
#endif
   snprintf (s_version, LEN_HUND, "%s   %s : %s", t, P_VERNUM, P_VERTXT);
   return s_version;
}
/*> static char         s_terse      [LEN_FULL]  = "· ·· ·· -   · ··· ·· ·· ···· -   · ··· ·· ·· -   · ··· ··· · · · -   · ··· ·· ·· -       ···· -";   <*/
/*> static char         s_score      [LEN_FULL]  = "NMá · ·· ·· -   EXá · ··· ·· ·· ···· -   PRá · ··· ·· ·· -   FXá · ··· ··· · · · -   REá · ··· ·· ·· -   JDá     HKá ···· -";   <*/
/*> static char         s_full       [LEN_FULL]  = "NMá c nb Nl ´   EXá r ogp jn rt ebih ´   PRá r ogp jn rt ´   FXá F yyy rcu R C U ´   REá r ogp jn rt ´   JDá Ï   HKá ebih ´";   <*/
/*> static char         s_report     [LEN_FULL]  = " ·  · ·  · ·  -   ·  · · ·  · ·  · ·  · · · ·  -   ·  · · ·  · ·  · ·  -   ·  · · ·  · · ·  ·  ·  ·  -   ·  · · ·  · ·  · ·  -       · · · ·  -";   <*/

/*> static char         s_ttitle     [LEN_FULL]  = "NAME²²²²‚   EXPECT²²²²²²²²²²²‚   CHECK²²²²²²²‚   FIXES²²²²²²²²²²²‚   RECHECK²²²²²‚   ³   HACK²‚";                                                   <* 
 *> static char         s_stitle     [LEN_FULL]  = "NAME²²²²²²²²‚   EXPECT²²²²²²²²²²²²²²²‚   CHECK²²²²²²²²²²²‚   FIXES²²²²²²²²²²²²²²²‚   RECHECK²²²²²²²²²‚   ³²²²‚   HACK²²²²²‚";                       <* 
 *> static char         s_rtitle     [LEN_FULL]  = " NAME²²²²²²²²²‚   EXPECT²²²²²²²²²²²²²²²²²²²²²²²‚   CHECK²²²²²²²²²²²²²²²‚   FIXES²²²²²²²²²²²²²²²²²²²²²‚   RECHECK²²²²²²²²²²²²²‚   ³   HACK²²²²²‚";   <*/

/*> static tSCORE_TABLE  *mySCORE.m_table   = NULL;                                           <*/
/*> static char         s_TERSE      [LEN_FULL]  = "";                                <*/
/*> static char         s_SCORE      [LEN_FULL]  = "";                                <*/
/*> static char         s_FULL       [LEN_FULL]  = "";                                <*/
/*> static char         s_REPORT     [LEN_FULL]  = "";                                <*/



/*                                               1         2         3         4         5         6         7         8         9            */
/*                                     -123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789   */
/*                                     --------request---------   cfg   ----check----   flg   -fix-   ---recheck---   f   hacked         */





/*>    REQUEST LEGEND ===============================================================================================================================================================\n");   <* 
 *>    ƒ²²²²²²²²²²²²²²²²²²²² type            d) directory    f) file         s) symlink      c) char dev     b) block dev    p) pipe/fifo    i) ipsoc        h) hard link    ?) illegal            <* 
 *>    Œ ƒ²²²²²²²²²²²²²²²²²² name            n) valid        /) pathless     -) null/empty   °) illegal                                                                            <* 
 *>    Œ Œƒ²²²²²²²²²²²²²²²²² owner           o) valid        O) defaulted    -) null         °) illegal                                                                                            <* 
 *>    Œ ŒŒƒ²²²²²²²²²²²²²²²² group           g) valid        G) defaulted    -) null         °) illegal                                                                                            <* 
 *>    Œ ŒŒŒƒ²²²²²²²²²²²²²²² permissions     p) valid        P) defaulted    -) null         °) illegal                                                                                            <* 
 *>    Œ ŒŒŒŒ ƒ²²²²²²²²²²²²² major number
 *>    Œ ŒŒŒŒ Œƒ²²²²²²²²²²²² major number
 *>    Œ ŒŒŒŒ ŒŒ ƒ²²²²²²²²²² target type     d) directory    f) file         s) symlink      c) char dev     b) block dev    p) pipe/fifo    i) ipsoc        h) hard link    ?) illegal            <*
 *>    Œ ŒŒŒŒ ŒŒ Œƒ²²²²²²²²² target link     t) target       -) none\n");                                                                                                                          <*
 *>    Œ ŒŒŒŒ ŒŒ ŒŒ ƒ²²²²²²² epoch
 *>    Œ ŒŒŒŒ ŒŒ ŒŒ Œƒ²²²²²² bytes
 *>    Œ ŒŒŒŒ ŒŒ ŒŒ ŒŒƒ²²²²² inode
 *>    Œ ŒŒŒŒ ŒŒ ŒŒ ŒŒŒƒ²²²² hash
 *>    Œ ŒŒŒŒ ŒŒ ŒŒ ŒŒŒŒ ƒ²² summary         y) complete     !) issues\n");                                                                                                                        <* 
 *>    d togp ·· ·· ···· y (file/directory example)\n");                                                                                                                                         <* 
 *>    c togp jn··· ···· y (char/block device example\n");                                                                                                                                       <* 
 *>    s t··· ··ts· ···· y (symlink/hardlink example\n");                                                                                                                                                 <*/


/*>    CHECK/RECHECK LEGEND =========================================================================================================================================================\n");   <* 
 *>    ƒ²²²²²²²²²²²²²²²²²² name            n) valid        £) null         ©) empty        /) pathless     F) bad chars\n");                                                                     <* 
 *>    Œƒ²²²²²²²²²²²²²²²²² exists          e) existing      ) not-exist\n");                                                                                                                     <* 
 *>    ŒŒ ƒ²²²²²²²²²²²²²²² actual type     d) directory    f) file         s) symlink      c) char dev     b) block dev    p) pipe/fifo    i) ipsoc        h) hard link\n");                     <* 
 *>    ŒŒ Œƒ²²²²²²²²²²²²²² owner           o) matches      -) no match\n");                                                                                                                      <* 
 *>    ŒŒ ŒŒƒ²²²²²²²²²²²²² group           g) matches      -) no match\n");                                                                                                                      <* 
 *>    ŒŒ ŒŒŒƒ²²²²²²²²²²²² permissions     p) matches      -) no match\n");                                                                                                                      <* 
 *>    ŒŒ ŒŒŒŒ ƒ²²²²²²²²²² major number
 *>    ŒŒ ŒŒŒŒ Œƒ²²²²²²²²² minor number
 *>    ŒŒ ŒŒŒŒ ŒŒ ƒ²²²²²²² source link
 *>    ŒŒ ŒŒŒŒ ŒŒ Œƒ²²²²²² source exist    s) given        -) none\n");                                                                                                                          <* 
 *>    ŒŒ ŒŒŒŒ ŒŒ ŒŒƒ²²²²² source type     s) given        -) none\n");                                                                                                                          <* 
 *>    ŒŒ ŒŒŒŒ ŒŒ ŒŒŒ ƒ²²² summary         y) complete     !) issues         not-exist\n");                                                                                                      <* 
 *>    n- ---- ·· ···      (file/directory does not exist yet)\n");                                                                                                                              <* 
 *>    ne dogp ···· y      (file/directory example)\n");                                                                                                                                         <* 
 *>    ŒŒ ŒŒŒŒ ƒ²²²²²²² major number    j) matches      -) no match\n");                                                                                                                      <* 
 *>    ŒŒ ŒŒŒŒ Œƒ²²²²²² minor number    n) matches      -) no match\n");                                                                                                                      <* 
 *>    ŒŒ ŒŒŒŒ ŒŒ  ƒ²²² summary         y) complete     !) issues         not-exist\n");                                                                                                      <* 
 *>    ne cogp ´jn· y    (char/block device example)\n");                                                                                                                                      <* 
 *>    ŒŒ Œ ƒ²²²²²²²²²² source name     n) valid        £) null         ©) empty        /) pathless     F) bad chars\n");                                                                     <* 
 *>    ŒŒ Œ Œƒ²²²²²²²²² source exists   e) existing      ) not-exist\n");                                                                                                                     <* 
 *>    ŒŒ Œ ŒŒƒ²²²²²²²² source type     d) directory    f) file         s) symlink      c) char dev     b) block dev    p) pipe/fifo    i) ipsoc        h) hard link\n");                     <* 
 *>    ŒŒ Œ ŒŒŒƒ²²²²²²² source link     n) matches      -) no match\n");                                                                                                                      <* 
 *>    ŒŒ Œ ŒŒŒŒ   ƒ²²² summary         y) complete     !) issues         not-exist\n");                                                                                                      <* 
 *>    ne s´necl·· y    (symlink example)\n");                                                                                                                                                <* 
 *>    n- -´nec-··      (symlink does not exist yet)\n");                                                                                                                                     <*/

/*>    UPDATE LEGEND ================================================================================================================================================================\n");   <* 
 *>    ƒ²²²²²²²²²²²²²²² remove          e) existing     D) made dir     S) made slink   C) made char    B) made block   P) made pipe    I) made ipsoc   H) made hlink\n");                    <* 
 *>    Œƒ²²²²²²²²²²²²²² create          e) existing     D) made dir     S) made slink   C) made char    B) made block   P) made pipe    I) made ipsoc   H) made hlink\n");                    <* 
 *>    ŒŒ ƒ²²²²²²²²²²²² owner           o) no action    O) updated\n");                                                                                                                       <* 
 *>    ŒŒ Œƒ²²²²²²²²²²²²group            o) no action    O) updated\n");                                                                                                                       <* 
 *>    ŒŒ ŒŒƒ²²²²²²²²²²²perms             o) no action    O) updated\n");                                                                                                                       <* 
 *>    ŒŒ ŒŒŒ ƒ²²²²²²²²²summary         y) complete     !) issues\n");                                                                                                                        <* 
 *>    DO --- y    (file/directory created)\n");                                                                                                                                         <* 
 *>    eo g   y    (file/directory exists, permissions changed)\n");                                                                                                                     <* 
 *>    S· ·   y    (symlink created)\n");                                                                                                                                                <* 
 *>    CO G   y    (char/block device created)\n");                                                                                                                                      <*/




/*====================------------------------------------====================*/
/*===----                         helpers                              ----===*/
/*====================------------------------------------====================*/
static void      o___HELPERS____________o (void) {;}



/*====================------------------------------------====================*/
/*===----                       marking scores                         ----===*/
/*====================------------------------------------====================*/
static void      o___MARKING_______o (void) {;};



/*====================------------------------------------====================*/
/*===----                        reporting support                     ----===*/
/*====================------------------------------------====================*/
static void      o___REPORT________o (void) {;};

char*
yenv_score__header      (tSCORE_TABLE *a_table, char n)
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

char* yENV_score_header  (char n)   { return yenv_score__header    (mySCORE.m_table , n); }

char*
yenv_score__title       (tSCORE_TABLE *a_table, char a_type)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         x_max       =    0;
   int         i           =    0;
   int         x_pos       =    0;
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
   case 't'  :  x_max = strlen (mySCORE.o_terse ); break;
   case 's'  :  x_max = strlen (mySCORE.o_score ); break;
   case 'r'  :  x_max = strlen (mySCORE.o_report); break;
   default   :
                   DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
                   return "(bad type)";
   }
   DEBUG_YSCORE   yLOG_value   ("x_max"     , x_max);
   snprintf (g_print, LEN_FULL, "%*.*s", x_max, x_max, "                                                                                                                                                                                                        ");
   DEBUG_YSCORE   yLOG_complex ("g_print"   , "%3då%sæ", x_max, g_print);
   /*---(create)-------------------------*/
   --rce;  for (i = 0; i < LEN_FULL; ++i) {
      /*---(test for end)----------------*/
      if (strncmp (a_table [i].s_label, "end-", 4) == 0) {
         if (g_print [x_max - 1] == '²')  g_print [x_max - 1] = '‚';
         break;
      }
      /*---(accumulate)------------------*/
      rc = yscore_pos_accum (a_table, a_type, i, &x_pos);
      DEBUG_YSCORE   yLOG_complex ("accum"     , "%3d) %3d, inc %3d, pos %3d", i, a_table [i].s_sample, rc, x_pos);
      /*---(print)----------------------*/
      if (a_table [i].s_sample == 0) {
         /*---(prepare)---------------------*/
         l = strlen (a_table [i].s_print);
         DEBUG_YSCORE   yLOG_complex ("PREFIX"    , "%3d, %2då%sæ", i, l, a_table [i].s_print);
         for (j = 0; j < l; ++j) {
            if (a_type != 's')  o = j + x_pos;
            else                o = j + x_pos - 4;
            if (o < 0 || o >= x_max) {
               DEBUG_YSCORE   yLOG_exitr   (__FUNCTION__, rce);
               strlcat (g_print, "  (out of range)", LEN_FULL);
               return g_print;
            }
            DEBUG_YSCORE   yLOG_complex ("fill-in"   , "%3d, %c/%3d", o, a_table [i].s_print [j], a_table [i].s_print [j]);
            g_print [o] = a_table [i].s_print [j];
         }
         if (a_type != 's')  o = x_pos;
         else                o = x_pos - 4;
         for (j = o + l; j < x_max; ++j)   g_print [j] = '²';
      }
      if (a_table [i].s_sample == 3) {
         o = x_pos - 3;
         if (o > 0 && g_print [o - 1] == '²')  g_print [o - 1] = '‚';
         if (g_print [o + 0] == '²')  g_print [o + 0] = ' ';
         if (g_print [o + 1] == '²')  g_print [o + 1] = ' ';
         if (g_print [o + 2] == '²')  g_print [o + 2] = ' ';
      }
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return g_print;
}

char* yENV_score_title  (char a_type) { return yenv_score__title (mySCORE.m_table , a_type); }



/*====================------------------------------------====================*/
/*===----                      auditing tables                         ----===*/
/*====================------------------------------------====================*/
static void      o___AUDITING______o (void) {;};


/*====================------------------------------------====================*/
/*===----                       legend version                         ----===*/
/*====================------------------------------------====================*/
static void      o___LEGEND________o (void) {;};

char*
yenv_score__legend      (tSCORE_TABLE *a_table, char a_line, char a_label [LEN_TERSE], char a_terse [LEN_FULL])
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
               strlcat (g_print, "²² ", LEN_RECD);
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
      snprintf (t, 19, "%s²LEGEND²²²²²²²²²²²²²²²²²²²²", a_table [x_beg].s_print);
      strlcpy (g_print, t, LEN_RECD);
      strlcat (g_print, ">>", LEN_RECD);
      strlcat (g_print, x_heads, LEN_RECD);
   }
   /*---(complete)-----------------------*/
   DEBUG_YSCORE    yLOG_exit    (__FUNCTION__);
   return g_print;
}

char* yenv_score_legend (char a_line, char a_label [LEN_TERSE])  { return yenv_score__legend (mySCORE.m_table, a_line, a_label, mySCORE.o_terse); }



