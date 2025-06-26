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
   DEBUG_YENV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YENV   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring rpt_heads called without scoring table");
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return "(no table)";
   }
   /*---(defense)------------------------*/
   --rce;  if (n < 0 || n > 6) {
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return g_print;
   }
   /*---(initialize)---------------------*/
   strcpy (g_print, "");
   /*---(create line)--------------------*/
   DEBUG_YENV   yLOG_note    ("PRINT LINES...");
   for (i = 0; i < LEN_FULL; ++i) {
      /*---(test for end)----------------*/
      if (strncmp (a_table [i].s_label, "end-", 4) == 0)  break;
      /*---(prepare)---------------------*/
      l = strlen (a_table [i].s_print);
      DEBUG_YENV   yLOG_complex ("item"      , "%3d, %c/%3d, %2då%sæ", i, a_table [i].s_sample, a_table [i].s_sample, l, a_table [i].s_print);
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
   DEBUG_YENV    yLOG_exit    (__FUNCTION__);
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
   DEBUG_YENV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YENV   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring title called without scoring table");
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return "(no table)";
   }
   /*---(make base)----------------------*/
   DEBUG_YENV   yLOG_char    ("a_type"    , a_type);
   --rce;  switch (a_type) {
   case 't'  :  x_max = strlen (mySCORE.o_terse ); break;
   case 's'  :  x_max = strlen (mySCORE.o_score ); break;
   case 'r'  :  x_max = strlen (mySCORE.o_report); break;
   default   :
                   DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
                   return "(bad type)";
   }
   DEBUG_YENV   yLOG_value   ("x_max"     , x_max);
   snprintf (g_print, LEN_FULL, "%*.*s", x_max, x_max, "                                                                                                                                                                                                        ");
   DEBUG_YENV   yLOG_complex ("g_print"   , "%3då%sæ", x_max, g_print);
   /*---(create)-------------------------*/
   --rce;  for (i = 0; i < LEN_FULL; ++i) {
      /*---(test for end)----------------*/
      if (strncmp (a_table [i].s_label, "end-", 4) == 0) {
         if (g_print [x_max - 1] == '²')  g_print [x_max - 1] = '‚';
         break;
      }
      /*---(accumulate)------------------*/
      rc = yscore_pos_accum (a_table, a_type, i, &x_pos);
      DEBUG_YENV   yLOG_complex ("accum"     , "%3d) %3d, inc %3d, pos %3d", i, a_table [i].s_sample, rc, x_pos);
      /*---(print)----------------------*/
      if (a_table [i].s_sample == 0) {
         /*---(prepare)---------------------*/
         l = strlen (a_table [i].s_print);
         DEBUG_YENV   yLOG_complex ("PREFIX"    , "%3d, %2då%sæ", i, l, a_table [i].s_print);
         for (j = 0; j < l; ++j) {
            if (a_type != 's')  o = j + x_pos;
            else                o = j + x_pos - 4;
            if (o < 0 || o >= x_max) {
               DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
               strlcat (g_print, "  (out of range)", LEN_FULL);
               return g_print;
            }
            DEBUG_YENV   yLOG_complex ("fill-in"   , "%3d, %c/%3d", o, a_table [i].s_print [j], a_table [i].s_print [j]);
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
   DEBUG_YENV    yLOG_exit    (__FUNCTION__);
   return g_print;
}

char* yENV_score_title  (char a_type) { return yenv_score__title (mySCORE.m_table , a_type); }



/*====================------------------------------------====================*/
/*===----                        masking areas                         ----===*/
/*====================------------------------------------====================*/
static void      o___MASKING_______o (void) {;};

char
yenv_score__mask        (tSCORE_TABLE *a_table, char a_beg [LEN_TERSE], char a_end [LEN_TERSE], char b_terse [LEN_FULL], char b_score [LEN_FULL], char b_report [LEN_FULL])
{
   char         rce        =  -10;
   char         rc         =    0;
   int          i;
   short        bt, et;
   short        bs, es;
   short        br, er;
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring mask called without scoring table");
      return rce;
   }
   rc = yscore_pos (a_table, 0, a_beg, NULL, &bt, &bs, &br, NULL);
   --rce;  if (rc < 0 || bs < 0) {
      yURG_err ('w', "scoring mask å%sæ, begin label does not exist in scoring table", a_beg);
      return rce;
   }
   rc = yscore_pos (a_table, 0, a_end, NULL, &et, &es, &er, NULL);
   --rce;  if (rc < 0 || es < 0) {
      yURG_err ('w', "scoring mask å%sæ, ending label does not exist in scoring table", a_end);
      return rce;
   }
   if (b_terse  != NULL) { for (i = bt; i <= et; ++i)  b_terse  [i]   = '¬'; }
   if (b_score  != NULL) { for (i = bs; i <= es; ++i)  b_score  [i]   = '¬'; }
   if (b_report != NULL) { for (i = br; i <= er; ++i)  b_report [i]   = '¬'; }
   return 0;
}

char yENV_score_mask         (char a_beg [LEN_TERSE], char a_end [LEN_TERSE])  { yenv_score__mask (mySCORE.m_table , a_beg, a_end, mySCORE.o_terse, mySCORE.o_score, mySCORE.o_report); }

char yenv_score_nocheck      (void) { return yENV_score_mask ("PRá "      , "FIXES"     ); }
char yenv_score_nohacked     (void) { return yENV_score_mask ("HKá "      , "HACKED"    ); }



/*====================------------------------------------====================*/
/*===----                      auditing tables                         ----===*/
/*====================------------------------------------====================*/
static void      o___AUDITING______o (void) {;};

char
yenv_score__asample     (short n, uchar a_sample)
{
   char        rce         =  -10;
   --rce;  if (a_sample >= 127 && a_sample <= 159) {
      yURG_err ('w', "%3d) bad sample character, (%3d) char, line drawing characters disallowed", n, a_sample);
      return rce;
   }
   if (a_sample == 0 )  return RC_POSITIVE;
   if (a_sample == 1 )  return RC_POSITIVE;
   if (a_sample == 3 )  return RC_POSITIVE;
   --rce;  if (a_sample <= 32) {
      yURG_err ('w', "%3d) bad sample character, (%3d) char, control characters disallowed (0 - 32), except 0, 1, and 3", n, a_sample);
      return rce;
   }
   return RC_POSITIVE;
}

char
yenv_score__adefault    (short n, uchar a_sample, uchar a_default)
{
   char        rce         =  -10;
   --rce;  if (a_default >= 127 && a_default <= 159) {
      yURG_err ('w', "%3d) bad default character, (%3d) sample, (%3d) char, line drawing characters disallowed", n, a_sample, a_default);
      return rce;
   }
   --rce;  if (a_default < 32) {
      yURG_err ('w', "%3d) bad default character, (%3d) sample, (%3d) char, control characters disallowed (0 - 31)", n, a_sample, a_default);
      return rce;
   }
   --rce;  if (a_sample < 32 && a_default != ' ') {
      yURG_err ('w', "%3d) must use space as default, (%3d) sample", n, a_sample);
      return rce;
   }
   --rce;  if (a_sample > 32 && a_default == ' ') {
      yURG_err ('w', "%3d) space default character, (%3d) sample, not allowed for normal lines", n, a_sample);
      return rce;
   }
   return RC_POSITIVE;
}

char
yenv_score__alabel      (short n, uchar a_sample, char a_label [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         i           =    0;
   int         l           =    0;
   char       *x_valid     = NULL;
   /*---(defense)------------------------*/
   --rce;  if (a_label == NULL) {
      yURG_err ('w', "%3d) label NULL, %3d line, %c sample", n, a_sample);
      return rce;
   }
   /*---(lengths)------------------------*/
   l = strlen (a_label);
   --rce;  if (l > 9) {
      yURG_err ('w', "%3d) label too long (> 9), (%3d) sample, (%d) len", n, a_sample, l);
      return rce;
   }
   --rce;  if (a_sample > 32 && l < 1) {
      yURG_err ('w', "%3d) label too short, (%3d) sample, (%d) len", n, a_sample, l);
      return rce;
   }
   --rce;  if (a_sample == 0 && l != 4) {
      yURG_err ('w', "%3d) 0 label not 4 long, (%3d) sample, (%d) len", n, a_sample, l);
      return rce;
   }
   --rce;  if (a_sample == 1 && l != 1) {
      yURG_err ('w', "%3d) 1 label not 1 long, (%3d) sample, (%d) len", n, a_sample, l);
      return rce;
   }
   --rce;  if (a_sample == 3 && l != 3) {
      yURG_err ('w', "%3d) 3 label not 3 long, (%3d) sample, (%d) len", n, a_sample, l);
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
         yURG_err ('w', "%3d) bad label character, (%3d) sample, (%d) pos, (%3d) char not allowed å%sæ", n, a_sample, i, a_label [i], x_valid);
         return rce;
      }
   }
   /*---(specific)-----------------------*/
   x_valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   --rce;  if (a_sample == 0 && strchr (x_valid, a_label [0]) == NULL) {
      yURG_err ('w', "%3d) 0 label char one must be upper case, (%3d) sample, (%c) char", n, a_sample, a_label [0]);
      return rce;
   }
   --rce;  if (a_sample == 0 && strchr (x_valid, a_label [1]) == NULL) {
      yURG_err ('w', "%3d) 0 label char two must be upper case, (%3d) sample, (%c) char", n, a_sample, a_label [1]);
      return rce;
   }
   --rce;  if (a_sample == 0 && a_label [2] != 'á') {
      yURG_err ('w', "%3d) 0 label char two must be tick (á), (%3d) sample, (%c) char", n, a_sample, a_label [2]);
      return rce;
   }
   --rce;  if (a_sample == 0 && a_label [3] != ' ') {
      yURG_err ('w', "%3d) 0 label char four must be space, (%3d) sample, (%c) char", n, a_sample, a_label [3]);
      return rce;
   }
   /*---(complete)-----------------------*/
   return RC_POSITIVE;
}

char
yenv_score__aprint      (short n, uchar a_sample, char a_print [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         i           =    0;
   int         l           =    0;
   char       *x_valid     = NULL;
   /*---(defense)------------------------*/
   --rce;  if (a_print == NULL) {
      yURG_err ('w', "%3d) print NULL, (%3d) sample", n, a_sample);
      return rce;
   }
   /*---(lengths)------------------------*/
   l = strlen (a_print);
   --rce;  if (l > 9) {
      yURG_err ('w', "%3d) print too long (> 9), (%3d) sample, (%d) len", n, a_sample, l);
      return rce;
   }
   --rce;  if (a_sample != 0 && l > 6) {
      yURG_err ('w', "%3d) normal print too long (> 6), (%3d) sample, (%d) len", n, a_sample, l);
      return rce;
   }
   --rce;  if ((a_sample == 0 || a_sample > 32) && l < 1) {
      yURG_err ('w', "%3d) print too short, (%3d) sample, (%d) len", n, a_sample, l);
      return rce;
   }
   --rce;  if (a_sample == 1 && l != 0) {
      yURG_err ('w', "%3d) 1 print not zero, (%3d) sample, (%d) len", n, a_sample, l);
      return rce;
   }
   --rce;  if (a_sample == 3 && l != 0) {
      yURG_err ('w', "%3d) 3 print not zero, (%3d) sample, (%d) len", n, a_sample, l);
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
         return rce;
      }
   }
   /*---(complete)-----------------------*/
   return RC_POSITIVE;
}

char
yenv_score__aline       (short n, char a_label [LEN_TERSE], char a_default, char a_sample, char a_print [LEN_TERSE], char a_desc [LEN_TERSE], char a_legend [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rc          =    0;
   char        rc_final    = RC_POSITIVE;
   /*---(checks)----------------------*/
   rc = yenv_score__asample  (n, a_sample);
   if (rc < 0)  rc_final = rc;
   rc = yenv_score__adefault (n, a_sample, a_default);
   if (rc < 0)  rc_final = rc;
   rc = yenv_score__alabel   (n, a_sample, a_label);
   if (rc < 0)  rc_final = rc;
   rc = yenv_score__aprint   (n, a_sample, a_print);
   if (rc < 0)  rc_final = rc;
   /*---(complete)-----------------------*/
   return rc_final;
}

char
yenv_score__adup        (tSCORE_TABLE *a_table, char n, char a_label [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         i           =    0;
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
      return rce;
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   return RC_POSITIVE;
}

char
yenv_score__audit       (tSCORE_TABLE *a_table)
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
   DEBUG_YENV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YENV   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring audit called without scoring table");
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(line-by-line)-------------------*/
   --rce;  for (i = 0; i < LEN_FULL; ++i) {
      /*---(messages)--------------------*/
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
      /*---(test for end-list)-----------*/
      if (strncmp (a_table [i].s_label, "end-", 4) == 0) {
         x_end = 'y';
         break;
      }
      /*---(checks)----------------------*/
      rc  = yenv_score__aline    (i, a_table [i].s_label, a_table [i].s_default, a_table [i].s_sample, a_table [i].s_print, a_table [i].s_desc, a_table [i].s_legend);
      rc2 = yenv_score__adup     (a_table, i, a_table [i].s_label);
      /*---(troubles)--------------------*/
      if (rc < 0 || rc2 < 0) {
         ++x_bad;
         ++x_error;
         rc_final = rc;
      }
      /*---(done)------------------------*/
   }
   /*---(list end)-----------------------*/
   DEBUG_YENV   yLOG_char    ("x_end"     , x_end);
   --rce;  if (x_end != 'y') {
      yURG_err ('w', "table does not complete with end-line item");
      ++x_bad;
      ++x_error;
      rc_final = rce;
   } else {
      yURG_msg ('-', "proper end-line found");
   }
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
   /*---(complete)-----------------------*/
   DEBUG_YENV    yLOG_exit    (__FUNCTION__);
   return rc_final;
}

char yENV_score_audit   (void)  { return yenv_score__audit (mySCORE.m_table); }



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
   DEBUG_YENV   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   strlcpy (g_print, "", LEN_RECD);
   /*---(defense)------------------------*/
   DEBUG_YENV   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return "(null table)";
   }
   /*---(defense)------------------------*/
   DEBUG_YENV   yLOG_point   ("a_label"   , a_label);
   --rce;  if (a_label == NULL) {
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return "(null label)";
   }
   DEBUG_YENV   yLOG_info    ("a_label"   , a_label);
   --rce;  if (a_label [0] == ' ') {
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return "(spacer/gap label)";
   }
   l = strlen (a_label);
   DEBUG_YENV   yLOG_value   ("l"         , l);
   --rce;  if (l != 4 || a_label [0] == ' ' || a_label [2] != 'á' || a_label [3] != ' ') {
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
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
   DEBUG_YENV   yLOG_complex ("bounds"    , "%3db, %3de, %3d#", x_beg, x_end, x_cnt);
   --rce;  if (x_beg < 0) {
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return "(beg not found)";
   }
   --rce;  if (x_end < 0) {
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return "(end not found)";
   }
   --rce;  if (x_cnt < 1) {
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return "(count < 1)";
   }
   /*---(start)--------------------------*/
   rc = yscore_pos (a_table, 0, a_table [x_beg].s_label, NULL, &x_off, NULL, NULL, NULL);
   DEBUG_YENV   yLOG_value   ("pos"       , rc);
   --rce;  if (rc < 0) {
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return "(beg pos < 0)";
   }
   DEBUG_YENV   yLOG_value   ("x_off"     , x_off);
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
   DEBUG_YENV    yLOG_exit    (__FUNCTION__);
   return g_print;
}

char* yenv_score_legend (char a_line, char a_label [LEN_TERSE])  { return yenv_score__legend (mySCORE.m_table, a_line, a_label, mySCORE.o_terse); }



