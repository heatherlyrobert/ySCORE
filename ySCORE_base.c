/*===[[ START ]]==============================================================*/
#include    "ySCORE.h"
#include    "ySCORE_priv.h"



/*===[[ GNU GENERAL PUBLIC LICENSE (GPL) ]]===================================*/
/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */

#define  P_COPYRIGHT   \
   "copyright (c) 2025 robert.s.heatherly at balsashrike at gmail dot com"

#define  P_LICENSE     \
   "the only place you could have gotten this code is my github, my website,¦"   \
   "or illegal sharing. given that, you should be aware that this is GPL licensed."

#define  P_COPYLEFT    \
   "the GPL COPYLEFT REQUIREMENT means any modifications or derivative works¦"   \
   "must be released under the same GPL license, i.e, must be free and open."

#define  P_INCLUDE     \
   "the GPL DOCUMENTATION REQUIREMENT means that you must include the original¦" \
   "copyright notice and the full licence text with any resulting anything."

#define  P_AS_IS       \
   "the GPL NO WARRANTY CLAUSE means the software is provided without any¦"      \
   "warranty and the author cannot be held liable for damages."

#define  P_THEFT    \
   "if you knowingly violate the spirit of these ideas, i suspect you might¦"    \
   "find any number of freedom-minded hackers may take it quite personally ;)"

/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
/*===[[ GNU GENERAL PUBLIC LICENSE (GPL) ]]===================================*/



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


