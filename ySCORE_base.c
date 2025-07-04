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





/*>    REQUEST LEGEND ===============================================================================================================================================================\n");   <* 
 *>    ²²²²²²²²²²²²²²²²²²²² type            d) directory    f) file         s) symlink      c) char dev     b) block dev    p) pipe/fifo    i) ipsoc        h) hard link    ?) illegal            <* 
 *>     ²²²²²²²²²²²²²²²²²² name            n) valid        /) pathless     -) null/empty   °) illegal                                                                            <* 
 *>     ²²²²²²²²²²²²²²²²² owner           o) valid        O) defaulted    -) null         °) illegal                                                                                            <* 
 *>     ²²²²²²²²²²²²²²²² group           g) valid        G) defaulted    -) null         °) illegal                                                                                            <* 
 *>     ²²²²²²²²²²²²²²² permissions     p) valid        P) defaulted    -) null         °) illegal                                                                                            <* 
 *>      ²²²²²²²²²²²²² major number
 *>      ²²²²²²²²²²²² major number
 *>       ²²²²²²²²²² target type     d) directory    f) file         s) symlink      c) char dev     b) block dev    p) pipe/fifo    i) ipsoc        h) hard link    ?) illegal            <*
 *>       ²²²²²²²²² target link     t) target       -) none\n");                                                                                                                          <*
 *>        ²²²²²²² epoch
 *>        ²²²²²² bytes
 *>        ²²²²² inode
 *>        ²²²² hash
 *>         ²² summary         y) complete     !) issues\n");                                                                                                                        <* 
 *>    d togp ·· ·· ···· y (file/directory example)\n");                                                                                                                                         <* 
 *>    c togp jn··· ···· y (char/block device example\n");                                                                                                                                       <* 
 *>    s t··· ··ts· ···· y (symlink/hardlink example\n");                                                                                                                                                 <*/


/*>    CHECK/RECHECK LEGEND =========================================================================================================================================================\n");   <* 
 *>    ²²²²²²²²²²²²²²²²²² name            n) valid        £) null         ©) empty        /) pathless     F) bad chars\n");                                                                     <* 
 *>    ²²²²²²²²²²²²²²²²² exists          e) existing      ) not-exist\n");                                                                                                                     <* 
 *>     ²²²²²²²²²²²²²²² actual type     d) directory    f) file         s) symlink      c) char dev     b) block dev    p) pipe/fifo    i) ipsoc        h) hard link\n");                     <* 
 *>     ²²²²²²²²²²²²²² owner           o) matches      -) no match\n");                                                                                                                      <* 
 *>     ²²²²²²²²²²²²² group           g) matches      -) no match\n");                                                                                                                      <* 
 *>     ²²²²²²²²²²²² permissions     p) matches      -) no match\n");                                                                                                                      <* 
 *>      ²²²²²²²²²² major number
 *>      ²²²²²²²²² minor number
 *>       ²²²²²²² source link
 *>       ²²²²²² source exist    s) given        -) none\n");                                                                                                                          <* 
 *>       ²²²²² source type     s) given        -) none\n");                                                                                                                          <* 
 *>        ²²² summary         y) complete     !) issues         not-exist\n");                                                                                                      <* 
 *>    n- ---- ·· ···      (file/directory does not exist yet)\n");                                                                                                                              <* 
 *>    ne dogp ···· y      (file/directory example)\n");                                                                                                                                         <* 
 *>      ²²²²²²² major number    j) matches      -) no match\n");                                                                                                                      <* 
 *>      ²²²²²² minor number    n) matches      -) no match\n");                                                                                                                      <* 
 *>        ²²² summary         y) complete     !) issues         not-exist\n");                                                                                                      <* 
 *>    ne cogp ΄jn· y    (char/block device example)\n");                                                                                                                                      <* 
 *>      ²²²²²²²²²² source name     n) valid        £) null         ©) empty        /) pathless     F) bad chars\n");                                                                     <* 
 *>      ²²²²²²²²² source exists   e) existing      ) not-exist\n");                                                                                                                     <* 
 *>      ²²²²²²²² source type     d) directory    f) file         s) symlink      c) char dev     b) block dev    p) pipe/fifo    i) ipsoc        h) hard link\n");                     <* 
 *>      ²²²²²²² source link     n) matches      -) no match\n");                                                                                                                      <* 
 *>         ²²² summary         y) complete     !) issues         not-exist\n");                                                                                                      <* 
 *>    ne s΄necl·· y    (symlink example)\n");                                                                                                                                                <* 
 *>    n- -΄nec-··      (symlink does not exist yet)\n");                                                                                                                                     <*/

/*>    UPDATE LEGEND ================================================================================================================================================================\n");   <* 
 *>    ²²²²²²²²²²²²²²² remove          e) existing     D) made dir     S) made slink   C) made char    B) made block   P) made pipe    I) made ipsoc   H) made hlink\n");                    <* 
 *>    ²²²²²²²²²²²²²² create          e) existing     D) made dir     S) made slink   C) made char    B) made block   P) made pipe    I) made ipsoc   H) made hlink\n");                    <* 
 *>     ²²²²²²²²²²²² owner           o) no action    O) updated\n");                                                                                                                       <* 
 *>     ²²²²²²²²²²²²group            o) no action    O) updated\n");                                                                                                                       <* 
 *>     ²²²²²²²²²²²perms             o) no action    O) updated\n");                                                                                                                       <* 
 *>      ²²²²²²²²²summary         y) complete     !) issues\n");                                                                                                                        <* 
 *>    DO --- y    (file/directory created)\n");                                                                                                                                         <* 
 *>    eo g   y    (file/directory exists, permissions changed)\n");                                                                                                                     <* 
 *>    S· ·   y    (symlink created)\n");                                                                                                                                                <* 
 *>    CO G   y    (char/block device created)\n");                                                                                                                                      <*/


