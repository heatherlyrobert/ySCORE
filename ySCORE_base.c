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
 *>    ��������������������� type            d) directory    f) file         s) symlink      c) char dev     b) block dev    p) pipe/fifo    i) ipsoc        h) hard link    ?) illegal            <* 
 *>    � ������������������� name            n) valid        /) pathless     -) null/empty   �) illegal                                                                            <* 
 *>    � ������������������� owner           o) valid        O) defaulted    -) null         �) illegal                                                                                            <* 
 *>    � ������������������� group           g) valid        G) defaulted    -) null         �) illegal                                                                                            <* 
 *>    � ������������������� permissions     p) valid        P) defaulted    -) null         �) illegal                                                                                            <* 
 *>    � ���� �������������� major number
 *>    � ���� �������������� major number
 *>    � ���� �� ����������� target type     d) directory    f) file         s) symlink      c) char dev     b) block dev    p) pipe/fifo    i) ipsoc        h) hard link    ?) illegal            <*
 *>    � ���� �� ����������� target link     t) target       -) none\n");                                                                                                                          <*
 *>    � ���� �� �� �������� epoch
 *>    � ���� �� �� �������� bytes
 *>    � ���� �� �� �������� inode
 *>    � ���� �� �� �������� hash
 *>    � ���� �� �� ���� ��� summary         y) complete     !) issues\n");                                                                                                                        <* 
 *>    d togp �� �� ���� y (file/directory example)\n");                                                                                                                                         <* 
 *>    c togp jn��� ���� y (char/block device example\n");                                                                                                                                       <* 
 *>    s t��� ��ts� ���� y (symlink/hardlink example\n");                                                                                                                                                 <*/


/*>    CHECK/RECHECK LEGEND =========================================================================================================================================================\n");   <* 
 *>    ������������������� name            n) valid        �) null         �) empty        /) pathless     F) bad chars\n");                                                                     <* 
 *>    ������������������� exists          e) existing     �) not-exist\n");                                                                                                                     <* 
 *>    �� ���������������� actual type     d) directory    f) file         s) symlink      c) char dev     b) block dev    p) pipe/fifo    i) ipsoc        h) hard link\n");                     <* 
 *>    �� ���������������� owner           o) matches      -) no match\n");                                                                                                                      <* 
 *>    �� ���������������� group           g) matches      -) no match\n");                                                                                                                      <* 
 *>    �� ���������������� permissions     p) matches      -) no match\n");                                                                                                                      <* 
 *>    �� ���� ����������� major number
 *>    �� ���� ����������� minor number
 *>    �� ���� �� �������� source link
 *>    �� ���� �� �������� source exist    s) given        -) none\n");                                                                                                                          <* 
 *>    �� ���� �� �������� source type     s) given        -) none\n");                                                                                                                          <* 
 *>    �� ���� �� ��� ���� summary         y) complete     !) issues       � not-exist\n");                                                                                                      <* 
 *>    n- ---- �� ��� �    (file/directory does not exist yet)\n");                                                                                                                              <* 
 *>    ne dogp ���� y      (file/directory example)\n");                                                                                                                                         <* 
 *>    �� ���� �������� major number    j) matches      -) no match\n");                                                                                                                      <* 
 *>    �� ���� �������� minor number    n) matches      -) no match\n");                                                                                                                      <* 
 *>    �� ���� ��  ���� summary         y) complete     !) issues       � not-exist\n");                                                                                                      <* 
 *>    ne cogp �jn� y    (char/block device example)\n");                                                                                                                                      <* 
 *>    �� � ����������� source name     n) valid        �) null         �) empty        /) pathless     F) bad chars\n");                                                                     <* 
 *>    �� � ����������� source exists   e) existing     �) not-exist\n");                                                                                                                     <* 
 *>    �� � ����������� source type     d) directory    f) file         s) symlink      c) char dev     b) block dev    p) pipe/fifo    i) ipsoc        h) hard link\n");                     <* 
 *>    �� � ����������� source link     n) matches      -) no match\n");                                                                                                                      <* 
 *>    �� � ����   ���� summary         y) complete     !) issues       � not-exist\n");                                                                                                      <* 
 *>    ne s�necl�� y    (symlink example)\n");                                                                                                                                                <* 
 *>    n- -�nec-�� �    (symlink does not exist yet)\n");                                                                                                                                     <*/

/*>    UPDATE LEGEND ================================================================================================================================================================\n");   <* 
 *>    ���������������� remove          e) existing     D) made dir     S) made slink   C) made char    B) made block   P) made pipe    I) made ipsoc   H) made hlink\n");                    <* 
 *>    ���������������� create          e) existing     D) made dir     S) made slink   C) made char    B) made block   P) made pipe    I) made ipsoc   H) made hlink\n");                    <* 
 *>    �� ������������� owner           o) no action    O) updated\n");                                                                                                                       <* 
 *>    �� ��������������group            o) no action    O) updated\n");                                                                                                                       <* 
 *>    �� ��������������perms             o) no action    O) updated\n");                                                                                                                       <* 
 *>    �� ��� ����������summary         y) complete     !) issues\n");                                                                                                                        <* 
 *>    DO --- y    (file/directory created)\n");                                                                                                                                         <* 
 *>    eo g   y    (file/directory exists, permissions changed)\n");                                                                                                                     <* 
 *>    S� �   y    (symlink created)\n");                                                                                                                                                <* 
 *>    CO G   y    (char/block device created)\n");                                                                                                                                      <*/


