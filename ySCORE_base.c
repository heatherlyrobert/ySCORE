/*===[[ START ]]==============================================================*/
#include    "ySCORE.h"
#include    "ySCORE_priv.h"



char  g_print   [LEN_RECD] = "";



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

/*
 * tables rules...
 *
 *    labels are only 1 to 9 characters, best if all caps
 *    last entry in labels is "end-list" as sentinel
 *
 *    default entries are used to create starting point
 *
 *    sample entries are used to show full version
 *       0) indicates 4 character block headers (two upper case followed by '�' and ' ')
 *       1) indicates single character spacer (none of the other fields will be used
 *       3) indicates three character spacer
 *
 *    valid is to limit options, but i may remove as it can be fussy
 *
 *    print field is for creating headers
 *       block headers are horizontal on top line
 *       line headers are vertical 1 to 6 characters
 *
 *    description is short helper
 *
 *    long is used for legends telling the various content meanings
 *
 *    decided NOT to have valid values checked as is creates another
 *    level of thing that might fail -- scoring should not fail
 *
 *
 */

const static tENV_SCORE s_audits [LEN_FULL] = {

   /*===[[ NAME ]]==========================================================*/
   { "NM� "     , ' ' ,  0  , "NAME"     , ""                                 , ""                                                                                },
   /*===[[ REQUEST TYPE ]]==================================================*/
   { "NCONF"    , '�' , 'c' , "conf"     , "naming�standard�applied"          , "�) illegal   -) wild      n) normal    s) standard  l) local     c) central"     }, 
   { "NDIR"     , '�' , 'd' , "dir"      , "directory�requested"              , "�) null      �) empty     /) pathless  D) passed"                                },
   { "NFILE"    , '�' , 'f' , "file"     , "file�name�requested"              , "�) null      �) empty     /) pathed    F) passed    -) skipped"                  },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ NAMING ]]========================================================*/
   { "NFULL"    , '�' , 'n' , "full"     , "name�quality�checking"            , "�) null      /) not abs   �) hidden    �) bad char  n) passed"                   },
   { "NSTYLE"   , '�' , 'b' , "style"    , "naming�style"                     , "d) dir       f) file      b) both"                                               },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ STANDARDS ]]=====================================================*/
   { "NDOTS"    , '�' , 'n' , "ndots"    , "file�name�separators"             , "�) skipped   �) none      <) too few   >) too many  n) passed"                   },
   { "NPREFIX"  , '�' , 'p' , "prefix"   , "required�prefix"                  , "�) skipped   �) failed    u) user      p) passed"                                },
   { "NSUFFIX"  , '�' , 's' , "suffix"   , "required�suffix"                  , "�) skipped   �) failed    s) passed"                                             },
   { "NDESC"    , '�' , 'd' , "desc"     , "remaining�description"            , "�) skipped   �) failed    d) passed"                                             },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ LOCATION ]]======================================================*/
   { "NLOC"     , '�' , 'h' , "loc"      , "file�location�type"               , "�) skipped   �) failed    r) root      h) home      e) etc       s) spool"       },
   { "NUSE"     , '�' , 'H' , "usable"   , "file�location�usable"             , "�) skipped   �) failed    R) root      H) home      E) etc       S) spool"       },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ REQUEST ]]=======================================================*/
   { "NAME"     , '-' , '�' , "������"   , "[[�name�judgement�]]"             , "-) unknown   �) failed    �) passed"                                             },
   { "   "      , ' ' ,  3  , ""         , ""                                 , ""                                                                                },

   /*===[[ REQUEST ]]=======================================================*/
   { "EX� "     , ' ' ,  0  , "EXPECT"   , ""                                 , ""                                                                                },
   /*===[[ REQUEST TYPE ]]==================================================*/
   { "ETYPE"    , '�' , 'r' , "type"     , "expected file type"               , "d) dir   r) reg   s) sym   h) hard  c) char  b) block p) pipe  i) ipsoc ?) WTF"  },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ REQUEST CHARS ]]=================================================*/
   { "EOWNER"   , '�' , 'o' , "owner"    , "expected owner"                   , "o) standard   �) numeric    O) default    -) skipped"                            },
   { "EGROUP"   , '�' , 'g' , "group"    , "expected group"                   , "g) standard   �) numeric    G) default    -) skipped"                            },
   { "EPERMS"   , '�' , 'p' , "perms"    , "expected permissions"             , "p) standard   �) non-std    P) default    -) skipped"                            },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ REQUEST DEVICE ]]================================================*/
   { "EMAJOR"   , '�' , 'j' , "major"    , "expected owner"                   , "j) in-range   -) skipped"                                                        },
   { "EMINOR"   , '�' , 'n' , "minor"    , "expected group"                   , "n) in-range   -) skipped"                                                        },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ REQUEST LINK ]]==================================================*/
   { "ETTYPE"   , '�' , 'r' , "ttype"    , "expected link target type"        , "d) dir   r) reg   s) sym   h) hard  c) char  b) block p) pipe  i) ipsoc ?) WTF"  },
   { "ETARGET"  , '�' , 't' , "target"   , "expected link target"             , "/) not-abs    #) bad chars  t) accepted   -) skipped"                            },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ REQUEST EXTENDED ]]==============================================*/
   { "EEPOCH"   , '�' , 'e' , "epoch"    , "expected update time"             , "e) accepted   -) skipped"                                                        },
   { "EBYTES"   , '�' , 'b' , "bytes"    , "expected size in bytes"           , "b) accepted   -) skipped"                                                        },
   { "EINODE"   , '�' , 'i' , "inode"    , "expected inode"                   , "i) accepted   -) skipped"                                                        },
   { "EHASH"    , '�' , 'h' , "hash"     , "expected file SHA hash"           , "h) accepted   -) skipped"                                                        },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ REQUEST ]]=======================================================*/
   { "EXPECT"   , '-' , '�' , "������"   , "judgement on request"             , "�) passed"                                                                       },
   { "   "      , ' ' ,  3  , ""         , ""                                 , ""                                                                                },

   /*===[[ PRECHECK ]]======================================================*/
   { "PR� "     , ' ' ,  0  , "CHECK"    , ""                                 , ""                                                                                },
   /*===[[ CHECK TYPE ]]====================================================*/
   { "CTYPE"    , '�' , 'r' , "type"     , "checked file type"                , "same as expected type, lower case if matching, upper case if not-match"          },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ CHECK CHARS ]]===================================================*/
   { "COWNER"   , '�' , 'o' , "owner"    , "checked owner"                    , "o) match      O) not-match"                                                      },
   { "CGROUP"   , '�' , 'g' , "group"    , "checked group"                    , "g) match      G) not-match"                                                      },
   { "CPERMS"   , '�' , 'p' , "perms"    , "checked permissions"              , "p) match      P) not-match"                                                      },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ CHECK DEVICE ]]==================================================*/
   { "CMAJOR"   , '�' , 'j' , "major"    , "checked owner"                    , "j) match      J) not-match"                                                      },
   { "CMINOR"   , '�' , 'n' , "minor"    , "checked group"                    , "n) match      N) not-match"                                                      },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ CHECK LINK ]]====================================================*/
   { "CTTYPE"   , '�' , 'r' , "ttype"    , "checked link target type"         , "t) match      T) not-match"                                                      },
   { "CTARGET"  , '�' , 't' , "target"   , "checked link target"              , "t) match      T) not-match"                                                      },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ CHECK JUDGE ]]===================================================*/
   { "CHECK"    , '-' , '�' , "������"   , "judgement on check"               , "-) skipped    �) passed"                                                         },
   { "   "      , ' ' ,  3  , ""         , ""                                 , ""                                                                                },

   /*===[[ FIXES ]]=========================================================*/
   { "FX� "     , ' ' ,  0  , "FIXES"    , ""                                 , ""                                                                                },
   /*===[[ REQUEST ]]=======================================================*/
   { "EFLAG"    , '�' , 'F' , "flag"     , "fix/forcing flag interpretation"  , "-) none allowed  f) allow fix     F) allow create  !) can even remove"           },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ CONFIGURATION ]]=================================================*/
   { "CONFC"    , '�' , 'y' , "check"    , "judgement on request"             , "y) precheck    -) not-requested"                                                 },
   { "CONFF"    , '�' , 'y' , "force"    , "judgement on request"             , "y) create, if must   !) remove, if must   -) not-requested"                      },
   { "CONFX"    , '�' , 'y' , "fix"      , "judgement on request"             , "y) fix, if must      -) not-requested"                                           },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ FIX/FORCES ]]====================================================*/
   { "FDEL"     , '�' , 'r' , "remove"   , "need forced deletion"             , "r) requires deletion   -) not needed"                                            },
   { "FADD"     , '�' , 'c' , "create"   , "need forced creation"             , "c) requires creation   -) not needed"                                            },
   { "FUPD"     , '�' , 'u' , "update"   , "need forced updates"              , "u) requires updates    -) not needed"                                            },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ ACTUAL ]]========================================================*/
   { "REMOVE"   , '�' , 'R' , "REMOVE"   , "actual deletion"                  , "R) really removed    ?) non-existant      !) not enough force  -) not needed"    },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   { "CREATE"   , '�' , 'C' , "CREATE"   , "actual creation"                  , "C) really created    ?) already exists    !) not enough force  -) not needed"    },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   { "UPDATE"   , '�' , 'U' , "UPDATE"   , "actual updates"                   , "U) really updated    !) not enough force  -) not needed"                         },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ RE-CHECK JUDGE ]]================================================*/
   { "FIXES"    , '-' , '�' , "������"   , "judgement on fixes"               , "-) skipped    �) passed"                                                         },
   { "   "      , ' ' ,  3  , ""         , ""                                 , ""                                                                                },

   /*===[[ RECHECK ]]=======================================================*/
   { "RE� "     , ' ' ,  0  , "RECHECK"  , ""                                 , ""                                                                                },
   /*===[[ RE-CHECK TYPE ]]=================================================*/
   { "RTYPE"    , '�' , 'r' , "type"     , "checked file type"                , "same as expected type, lower case if matching, upper case if not-match"          },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ RE-CHECK CHARS ]]================================================*/
   { "ROWNER"   , '�' , 'o' , "owner"    , "re-checked owner"                 , "o) match      O) not-match"                                                      },
   { "RGROUP"   , '�' , 'g' , "group"    , "re-checked group"                 , "g) match      G) not-match"                                                      },
   { "RPERMS"   , '�' , 'p' , "perms"    , "re-checked permissions"           , "p) match      P) not-match"                                                      },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ RE-CHECK DEVICE ]]===============================================*/
   { "RMAJOR"   , '�' , 'j' , "major"    , "re-checked owner"                 , "j) match      J) not-match"                                                      },
   { "RMINOR"   , '�' , 'n' , "minor"    , "re-checked group"                 , "n) match      N) not-match"                                                      },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ RE-CHECK LINK ]]=================================================*/
   { "RTTYPE"   , '�' , 'r' , "ttype"    , "re-checked link target type"      , "t) match      T) not-match"                                                      },
   { "RTARGET"  , '�' , 't' , "target"   , "re-checked link target"           , "t) match      T) not-match"                                                      },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ RE-CHECK JUDGE ]]================================================*/
   { "RECHECK"  , '-' , '�' , "������"   , "judgement on re-check"            , "�) passed"                                                                       },
   { "   "      , ' ' ,  3  , ""         , ""                                 , ""                                                                                },

   /*===[[ FINAL ]]=========================================================*/
   { "JD� "     , ' ' ,  0  , "�"        , ""                                 , ""                                                                                },
   /*===[[ FINAL JUDGE ]]===================================================*/
   { "FINAL"    , '�' , '�' , "FINAL"    , "final judgement"                  , "�) passed"                                                                       },
   { "   "      , ' ' ,  3  , ""         , ""                                 , ""                                                                                },

   /*===[[ HACKED ]]========================================================*/
   { "HK� "     , ' ' ,  0  , "HACK"     , ""                                 , ""                                                                                },
   /*===[[ HACKING CHECK ]]=================================================*/
   { "AEPOCH"   , '�' , 'e' , "epoch"    , "check update time"                , "e) matches    E) not-match"                                                      },
   { "ABYTES"   , '�' , 'b' , "bytes"    , "check size in bytes"              , "b) matches    B) not-match"                                                      },
   { "AINODE"   , '�' , 'i' , "inode"    , "check inode"                      , "i) matches    I) not-match"                                                      },
   { "AHASH"    , '�' , 'h' , "hash"     , "check file SHA hash"              , "h) matches    H) not-match"                                                      },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""                                                                                },
   /*===[[ HACKING FINAL ]]=================================================*/
   { "HACKED"   , '-' , '�' , "������"   , "final hacking judgement"          , "-) skipped    �) passed"                                                         },

   /*===[[ END-OF-LIST ]]===================================================*/
   { "end-list" , '�' , '�' , ""         , "end-of-entries"                   , ""                                                                                },

   /*===[[ DONE ]]==========================================================*/
};
static char         s_terse      [LEN_FULL]  = "� �� �� -   � ��� �� �� ���� -   � ��� �� �� -   � ��� ��� � � � -   � ��� �� �� -   �   ���� -";
static char         s_score      [LEN_FULL]  = "NM� � �� �� -   EX� � ��� �� �� ���� -   PR� � ��� �� �� -   FX� � ��� ��� � � � -   RE� � ��� �� �� -   JD� �   HK� ���� -";
static char         s_full       [LEN_FULL]  = "NM� c nb Nl �   EX� r ogp jn rt ebih �   PR� r ogp jn rt �   FX� F yyy rcu R C U �   RE� r ogp jn rt �   JD� �   HK� ebih �";
static char         s_report     [LEN_FULL]  = " �  � �  � �  -   �  � � �  � �  � �  � � � �  -   �  � � �  � �  � �  -   �  � � �  � � �  �  �  �  -   �  � � �  � �  � �  -   �   � � � �  -";

static char         s_ttitle     [LEN_FULL]  = "NAME�����   EXPECT������������   CHECK��������   FIXES������������   RECHECK������   �   HACK��";
static char         s_stitle     [LEN_FULL]  = "NAME���������   EXPECT����������������   CHECK������������   FIXES����������������   RECHECK����������   �����   HACK������";
static char         s_rtitle     [LEN_FULL]  = " NAME����������   EXPECT������������������������   CHECK����������������   FIXES����������������������   RECHECK��������������   �   HACK������";

static tENV_SCORE  *s_TABLE   = NULL;
static char         s_TERSE      [LEN_FULL]  = "";
static char         s_SCORE      [LEN_FULL]  = "";
static char         s_FULL       [LEN_FULL]  = "";
static char         s_REPORT     [LEN_FULL]  = "";



/*                                               1         2         3         4         5         6         7         8         9            */
/*                                     -123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789   */
/*                                     --------request---------   cfg   ----check----   flg   -fix-   ---recheck---   f   hacked         */





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




/*====================------------------------------------====================*/
/*===----                         helpers                              ----===*/
/*====================------------------------------------====================*/
static void      o___HELPERS____________o (void) {;}

char* yenv_score_terse  (void)  { return s_terse; }
char* yENV_score_terse  (void)  { return s_TERSE; }

char* yenv_score        (void)  { return s_score; }
char* yENV_score        (void)  { return s_SCORE; }

char* yenv_score_full   (void)  { return s_full; }
char* yENV_score_full   (void)  { return s_FULL; }

char* yenv_score_report (void)  { return s_report; }
char* yENV_score_report (void)  { return s_REPORT; }




/*====================------------------------------------====================*/
/*===----                        program level                         ----===*/
/*====================------------------------------------====================*/
static void      o___PROGRAM_______o (void) {;};

char
yENV_score_init         (tENV_SCORE *a_table)
{
   s_TABLE = a_table;
   yENV_score_clear ();
   return 0;
}

char
yenv_score__clear       (tENV_SCORE *a_table, char r_terse [LEN_FULL], char r_score [LEN_FULL], char r_full [LEN_FULL], char r_report [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   int         i           =    0;
   char        s           [LEN_SHORT] = "";
   char        f           [LEN_SHORT] = "";
   char        t           [LEN_SHORT] = "";
   char        r           [LEN_SHORT] = "";
   char        x_terse     [LEN_FULL]  = "";
   char        x_score     [LEN_FULL]  = "";
   char        x_full      [LEN_FULL]  = "";
   char        x_report    [LEN_FULL]  = "";
   /*---(header)-------------------------*/
   DEBUG_YENV   yLOG_senter  (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YENV   yLOG_spoint  (a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring clear called without scoring table");
      DEBUG_YENV   yLOG_sexitr  (__FUNCTION__, rce);
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
         break;
      case  1  :
         strlcpy (s     , " "   , LEN_SHORT);
         strlcpy (f     , " "   , LEN_SHORT);
         strlcpy (t     , " "   , LEN_SHORT);
         strlcpy (r     , " "   , LEN_SHORT);
         break;
      case  3  :
         strlcpy (s     , "   " , LEN_SHORT);
         strlcpy (f     , "   " , LEN_SHORT);
         strlcpy (t     , "   " , LEN_SHORT);
         strlcpy (r     , "  "  , LEN_SHORT);
         break;
      default  :
         sprintf  (s, "%c" , a_table [i].s_default);
         sprintf  (f, "%c" , a_table [i].s_sample);
         sprintf  (t, "%c" , a_table [i].s_default);
         sprintf  (r, " %c", a_table [i].s_default);
      }
      strlcat (x_full  , f  , LEN_FULL);
      strlcat (x_score , s  , LEN_FULL);
      strlcat (x_terse , t  , LEN_FULL);
      strlcat (x_report, r  , LEN_FULL);
   }
   /*---(save-back)----------------------*/
   if (r_terse  != NULL)  strlcpy (r_terse , x_terse , LEN_FULL);
   if (r_score  != NULL)  strlcpy (r_score , x_score , LEN_FULL);
   if (r_full   != NULL)  strlcpy (r_full  , x_full  , LEN_FULL);
   if (r_report != NULL)  strlcpy (r_report, x_report, LEN_FULL);
   /*---(complete)-----------------------*/
   DEBUG_YENV   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char yenv_score_clear        (void) { return yenv_score__clear (s_audits, s_terse, s_score, s_full, s_report); }
char yENV_score_clear        (void) { return yenv_score__clear (s_TABLE , s_TERSE, s_SCORE, s_FULL, s_REPORT); }



/*====================------------------------------------====================*/
/*===----                       positioning                            ----===*/
/*====================------------------------------------====================*/
static void      o___POSITION______o (void) {;};

char
yenv_score__inc         (char a_sample, char *b_tpos, short *b_spos, short *b_rpos)
{
   /*---(locals)-----------+-----+-----+-*/
   char        t           =    0;
   char        s           =    0;
   char        r           =    0;
   /*---(set increment)------------------*/
   switch (a_sample) {
   case  0  :   t = 0;   s = 4;   r = 0;   break;
   case  1  :   t = 1;   s = 1;   r = 1;   break;
   case  3  :   t = 3;   s = 3;   r = 2;   break;
   default  :   t = 1;   s = 1;   r = 2;   break;
   }
   /*---(save-back)----------------------*/
   if (b_tpos != NULL)   *b_tpos += t;
   if (b_spos != NULL)   *b_spos += s;
   if (b_rpos != NULL)   *b_rpos += r;
   /*---(complete)-----------------------*/
   return 0;
}

char
yenv_score__accum       (tENV_SCORE *a_table, short n, short *b_tpos, short *b_spos, short *b_rpos)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   short       t           =    0;
   short       s           =    0;
   short       r           =    0;
   /*---(defense)------------------------*/
   --rce;  if (a_table == NULL)                  return rce;
   /*---(starting point)-----------------*/
   if (b_tpos != NULL)   t  = *b_tpos;
   if (b_spos != NULL)   s  = *b_spos;
   if (b_rpos != NULL)   r  = *b_rpos;
   /*---(specific adjustments)-----------*/
   if (n == 0)  r += 1;
   /*---(set increment)------------------*/
   rc = yenv_score__inc (a_table [n].s_sample, &t, &s, &r);
   --rce;  if (rc < 0)             return rce;
   /*---(checks)-------------------------*/
   --rce;  if (t <  0)             return rce;
   --rce;  if (t >= LEN_FULL - 1)  return rce;
   --rce;  if (s <  0)             return rce;
   --rce;  if (s >= LEN_FULL - 1)  return rce;
   --rce;  if (r <  0)             return rce;
   --rce;  if (r >= LEN_FULL - 1)  return rce;
   /*---(save-back)----------------------*/
   if (b_tpos != NULL)   *b_tpos = t;
   if (b_spos != NULL)   *b_spos = s;
   if (b_rpos != NULL)   *b_rpos = r;
   /*---(complete)-----------------------*/
   return 0;
}

char
yenv_score_accum        (tENV_SCORE *a_table, char a_type, short n, short *r_pos)
{
   switch (a_type) {
   case 't' :  return yenv_score__accum (a_table, n, r_pos, NULL , NULL );  break;
   case 's' :  return yenv_score__accum (a_table, n, NULL , r_pos, NULL );  break;
   case 'r' :  return yenv_score__accum (a_table, n, NULL , NULL , r_pos);  break;
   default  :  return -99;
   }
}

char
yenv_score__pos         (tENV_SCORE *a_table, char a_label [LEN_TERSE], short *r_tpos, short *r_spos, short *r_rpos)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         i           =    0;
   short       t           =    0;
   short       s           =    0;
   short       r           =    0;
   char        x_good      =  '-';
   /*---(header)-------------------------*/
   DEBUG_YENV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YENV   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring pos called without scoring table");
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(default)------------------------*/
   if (r_tpos != NULL)  *r_tpos = -1;
   if (r_spos != NULL)  *r_spos = -1;
   if (r_rpos != NULL)  *r_rpos = -1;
   /*---(defense)------------------------*/
   DEBUG_YENV   yLOG_point   ("a_label"   , a_label);
   --rce;  if (a_label == NULL || a_label [0] == '\0') {
      DEBUG_YENV    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YENV   yLOG_info    ("a_label"   , a_label);
   /*---(position)-----------------------*/
   for (i = 0; i < LEN_FULL; ++i) {
      /*---(test for end)----------------*/
      if (strncmp (a_table [i].s_label, "end-", 4) == 0)  break;
      /*---(drop-out)--------------------*/
      if (strcmp (a_table [i].s_label, a_label) == 0) {
         DEBUG_YENV   yLOG_value   ("FOUND"     , i);
         x_good = 'y';
         break;
      }
      /*---(accumulate)------------------*/
      rc = yenv_score__inc (a_table [i].s_sample, &t, &s, &r);
      --rce;  if (rc < 0)             return rce;
   }
   ++r;
   /*---(check for trouble)--------------*/
   DEBUG_YENV   yLOG_value   ("s"         , s);
   DEBUG_YENV   yLOG_value   ("t"         , t);
   DEBUG_YENV   yLOG_value   ("r"         , r);
   --rce;  if (x_good != 'y') {
      DEBUG_YENV    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(default)------------------------*/
   if (r_tpos != NULL)  *r_tpos = t;
   if (r_spos != NULL)  *r_spos = s;
   if (r_rpos != NULL)  *r_rpos = r;
   /*---(complete)-----------------------*/
   DEBUG_YENV    yLOG_exit    (__FUNCTION__);
   return 0;
}

char yenv_score_pos    (char a_label [LEN_TERSE], short *r_norm, short *r_terse, short *r_report)  { return yenv_score__pos (s_audits, a_label, r_norm, r_terse, r_report); }
char yENV_score_pos    (char a_label [LEN_TERSE], short *r_norm, short *r_terse, short *r_report)  { return yenv_score__pos (s_TABLE , a_label, r_norm, r_terse, r_report); }



/*====================------------------------------------====================*/
/*===----                       marking scores                         ----===*/
/*====================------------------------------------====================*/
static void      o___MARKING_______o (void) {;};

char
yenv_score__mark         (tENV_SCORE *a_table, char a_label [LEN_TERSE], uchar a_mark, char b_terse [LEN_FULL], char b_score [LEN_FULL], char b_report [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   short       t           =   -1;
   short       s           =   -1;
   short       r           =   -1; /*---(header)-------------------------*/
   DEBUG_YENV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YENV   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring mark �%s�, called without scoring table", a_label);
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YENV   yLOG_value   ("a_mark"    , a_mark);
   --rce;  if (a_mark    <= 32 || (a_mark >= 127 && a_mark <= 159)) {
      yURG_err ('w', "scoring mark �%s�, called with illegal value (%3d)", a_label, a_mark);
      DEBUG_YENV    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YENV   yLOG_char    ("a_mark"    , a_mark);
   /*---(position)-----------------------*/
   rc = yenv_score__pos (a_table, a_label, &t, &s, &r);
   DEBUG_YENV   yLOG_value   ("pos"       , rc);
   --rce;  if (rc < 0) {
      yURG_err ('w', "scoring mark �%s�, label does not exist in scoring table", a_label);
      DEBUG_YENV    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(update terse)-------------------*/
   if (b_terse != NULL) {
      DEBUG_YENV   yLOG_value   ("t"         , t);
      b_terse  [t] = a_mark;
      DEBUG_YENV   yLOG_info    ("b_terse"   , b_terse);
   }
   /*---(update score)-------------------*/
   if (b_score != NULL) {
      DEBUG_YENV   yLOG_value   ("s"         , s);
      b_score  [s] = a_mark;
      DEBUG_YENV   yLOG_info    ("b_score"   , b_score);
   }
   /*---(update report)------------------*/
   if (b_report != NULL) {
      DEBUG_YENV   yLOG_value   ("r"         , r);
      b_report [r] = a_mark;
      DEBUG_YENV   yLOG_info    ("b_report"  , b_report);
   }
   /*---(complete)-----------------------*/
   DEBUG_YENV    yLOG_exit    (__FUNCTION__);
   return 0;
}

char yenv_score_mark    (char a_label [LEN_TERSE], uchar a_mark)  { return yenv_score__mark  (s_audits, a_label, a_mark, s_terse, s_score, s_report); }
char yENV_score_mark    (char a_label [LEN_TERSE], uchar a_mark)  { return yenv_score__mark  (s_TABLE , a_label, a_mark, s_TERSE, s_SCORE, s_REPORT); }

char
yenv_score__value       (tENV_SCORE *a_table, char a_label [LEN_TERSE], char a_score [LEN_FULL])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   short       s           =   -1;
   char        x_value     =  '-';
   /*---(header)-------------------------*/
   DEBUG_YENV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YENV   yLOG_point   ("a_table"   , a_table);
   --rce;  if (a_table == NULL) {
      yURG_err ('w', "scoring value �%s�, called without scoring table", a_label);
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YENV   yLOG_point   ("a_score"   , a_score);
   --rce;  if (a_score == NULL) {
      DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(position)-----------------------*/
   rc = yenv_score__pos (a_table, a_label, NULL, &s, NULL);
   DEBUG_YENV   yLOG_value   ("pos"       , rc);
   --rce;  if (rc < 0) {
      yURG_err ('w', "scoring value �%s�, label does not exist in scoring table", a_label);
      DEBUG_YENV    yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YENV   yLOG_value   ("s"         , s);
   /*---(value)--------------------------*/
   x_value = a_score [s];
   DEBUG_YENV   yLOG_value   ("x_value"   , x_value);
   /*---(complete)-----------------------*/
   DEBUG_YENV    yLOG_exit    (__FUNCTION__);
   return x_value;
}

char yenv_score_value  (char a_label [LEN_TERSE])  { return yenv_score__value (s_audits, a_label, s_score); }
char yENV_score_value  (char a_label [LEN_TERSE])  { return yenv_score__value (s_TABLE , a_label, s_SCORE); }



/*====================------------------------------------====================*/
/*===----                        reporting support                     ----===*/
/*====================------------------------------------====================*/
static void      o___REPORT________o (void) {;};

char*
yenv_score__header      (tENV_SCORE *a_table, char n)
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
      DEBUG_YENV   yLOG_complex ("item"      , "%3d, %c/%3d, %2d�%s�", i, a_table [i].s_sample, a_table [i].s_sample, l, a_table [i].s_print);
      /*---(normal stuff)---------------*/
      switch (a_table [i].s_sample) {
      case  0  : strcpy   (t, ""); break;
      case  1  : strcpy (t, " " ); break;
      case  3  : strcpy (t, "  "); break;
      default  :
                 if      (n == 0)   strcpy   (t, " -");
                 else if (n >  l)   strlcpy  (t, " �", LEN_SHORT);
                 else             { o = l - n; sprintf  (t, " %c", a_table [i].s_print [o]); }
      }
      strlcat (g_print, t  , LEN_FULL);
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   DEBUG_YENV    yLOG_exit    (__FUNCTION__);
   return g_print;
}

char* yenv_score_header  (char n)   { return yenv_score__header    (s_audits, n); }
char* yENV_score_header  (char n)   { return yenv_score__header    (s_TABLE , n); }

char*
yenv_score__title       (tENV_SCORE *a_table, char a_type)
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
   case 't'  :  if (a_table == s_audits)   x_max = strlen (s_terse ); else x_max = strlen (s_TERSE );  break;
   case 's'  :  if (a_table == s_audits)   x_max = strlen (s_score ); else x_max = strlen (s_SCORE );  break;
   case 'r'  :  if (a_table == s_audits)   x_max = strlen (s_report); else x_max = strlen (s_REPORT);  break;
   default   :
                   DEBUG_YENV   yLOG_exitr   (__FUNCTION__, rce);
                   return "(bad type)";
   }
   DEBUG_YENV   yLOG_value   ("x_max"     , x_max);
   snprintf (g_print, LEN_FULL, "%*.*s", x_max, x_max, "                                                                                                                                                                                                        ");
   DEBUG_YENV   yLOG_complex ("g_print"   , "%3d�%s�", x_max, g_print);
   /*---(create)-------------------------*/
   --rce;  for (i = 0; i < LEN_FULL; ++i) {
      /*---(test for end)----------------*/
      if (strncmp (a_table [i].s_label, "end-", 4) == 0) {
         if (g_print [x_max - 1] == '�')  g_print [x_max - 1] = '�';
         break;
      }
      /*---(accumulate)------------------*/
      rc = yenv_score_accum (a_table, a_type, i, &x_pos);
      DEBUG_YENV   yLOG_complex ("accum"     , "%3d) %3d, inc %3d, pos %3d", i, a_table [i].s_sample, rc, x_pos);
      /*---(print)----------------------*/
      if (a_table [i].s_sample == 0) {
         /*---(prepare)---------------------*/
         l = strlen (a_table [i].s_print);
         DEBUG_YENV   yLOG_complex ("PREFIX"    , "%3d, %2d�%s�", i, l, a_table [i].s_print);
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
         for (j = o + l; j < x_max; ++j)   g_print [j] = '�';
      }
      if (a_table [i].s_sample == 3) {
         o = x_pos - 3;
         if (o > 0 && g_print [o - 1] == '�')  g_print [o - 1] = '�';
         if (g_print [o + 0] == '�')  g_print [o + 0] = ' ';
         if (g_print [o + 1] == '�')  g_print [o + 1] = ' ';
         if (g_print [o + 2] == '�')  g_print [o + 2] = ' ';
      }
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   DEBUG_YENV    yLOG_exit    (__FUNCTION__);
   return g_print;
}

char* yenv_score_title  (char a_type) { return yenv_score__title (s_audits, a_type); }
char* yENV_score_title  (char a_type) { return yenv_score__title (s_TABLE , a_type); }



/*====================------------------------------------====================*/
/*===----                        masking areas                         ----===*/
/*====================------------------------------------====================*/
static void      o___MASKING_______o (void) {;};

char
yenv_score__mask        (tENV_SCORE *a_table, char a_beg [LEN_TERSE], char a_end [LEN_TERSE], char b_terse [LEN_FULL], char b_score [LEN_FULL], char b_report [LEN_FULL])
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
   rc = yenv_score__pos (a_table, a_beg, &bt, &bs, &br);
   --rce;  if (rc < 0 || bs < 0) {
      yURG_err ('w', "scoring mask �%s�, begin label does not exist in scoring table", a_beg);
      return rce;
   }
   rc = yenv_score__pos (a_table, a_end, &et, &es, &er);
   --rce;  if (rc < 0 || es < 0) {
      yURG_err ('w', "scoring mask �%s�, ending label does not exist in scoring table", a_end);
      return rce;
   }
   if (b_terse  != NULL) { for (i = bt; i <= et; ++i)  b_terse  [i]   = '�'; }
   if (b_score  != NULL) { for (i = bs; i <= es; ++i)  b_score  [i]   = '�'; }
   if (b_report != NULL) { for (i = br; i <= er; ++i)  b_report [i]   = '�'; }
   return 0;
}

char yenv_score_mask         (char a_beg [LEN_TERSE], char a_end [LEN_TERSE])  { yenv_score__mask (s_audits, a_beg, a_end, s_terse, s_score, s_report); }
char yENV_score_mask         (char a_beg [LEN_TERSE], char a_end [LEN_TERSE])  { yenv_score__mask (s_TABLE , a_beg, a_end, s_TERSE, s_SCORE, s_REPORT); }

char yenv_score_nocheck      (void) { return yenv_score_mask ("PR� "      , "FIXES"     ); }
char yenv_score_nohacked     (void) { return yenv_score_mask ("HK� "      , "HACKED"    ); }



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
   case  0  : x_valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZ� ";  break;
   case  1  : x_valid = " �";                            break;
   case  3  : x_valid = " �";                            break;
   default  : x_valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";    break;
   }
   for (i = 0; i < l; ++i) {
      if (strchr (x_valid, a_label [i]) == NULL) {
         yURG_err ('w', "%3d) bad label character, (%3d) sample, (%d) pos, (%3d) char not allowed �%s�", n, a_sample, i, a_label [i], x_valid);
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
   --rce;  if (a_sample == 0 && a_label [2] != '�') {
      yURG_err ('w', "%3d) 0 label char two must be tick (�), (%3d) sample, (%c) char", n, a_sample, a_label [2]);
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
   case  0  : x_valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZ�";  break;
   default  : x_valid = "abcdefghijklmnopqrstuvwxyz�ABCDEFGHIJKLMNOPQRSTUVWXYZ";  break;
   }
   for (i = 0; i < l; ++i) {
      if (strchr (x_valid, a_print [i]) == NULL) {
         yURG_err ('w', "%3d) bad print character, (%3d) sample, (%d) pos, (%3d) char not allowed �%s�", n, a_sample, i, a_print [i], x_valid);
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
yenv_score__adup        (tENV_SCORE *a_table, char n, char a_label [LEN_TERSE])
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
      yURG_err ('w', "%3d) �%s� is a duplicate label of (%d)", n, a_label, i);
      return rce;
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   return RC_POSITIVE;
}

char
yenv_score__audit       (tENV_SCORE *a_table)
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
         yURG_msg ('>', "auditing �%s� block on line (%d)...", a_table [i].s_label, i);
         x_bad = 0;
         break;
      default :
         if (i == 0)  yURG_msg ('>', "pseudo block, auditing �%s� on line (%d)...", a_table [i].s_label, i);
         else         yURG_msg ('-', "%3d) reviewing �%s�", i, a_table [i].s_label);
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

char yenv_score_audit   (void)  { return yenv_score__audit (s_audits); }
char yENV_score_audit   (void)  { return yenv_score__audit (s_TABLE); }



/*====================------------------------------------====================*/
/*===----                       legend version                         ----===*/
/*====================------------------------------------====================*/
static void      o___LEGEND________o (void) {;};

char*
yenv_score__legend      (tENV_SCORE *a_table, char a_line, char a_label [LEN_TERSE], char a_terse [LEN_FULL])
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
   --rce;  if (l != 4 || a_label [0] == ' ' || a_label [2] != '�' || a_label [3] != ' ') {
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
   rc = yenv_score__pos (a_table, a_table [x_beg].s_label, &x_off, NULL, NULL);
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
            if (a_line >  x_pos)  strlcat (g_print, "�"   , LEN_RECD);
            else                  strlcat (g_print, " "   , LEN_RECD);
            break;
         default :
            /*---(normal)----------------*/
            if      (a_line <  x_pos)  strlcat (g_print, "�"   , LEN_RECD);
            else if (a_line == x_pos)  strlcat (g_print, "�"   , LEN_RECD);
            else if (a_line >  x_pos)  strlcat (g_print, "�"   , LEN_RECD);
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
               strlcat (g_print, "�� ", LEN_RECD);
               snprintf (t, 12, "%s������������", a_table [i].s_label);
               strlcat (g_print, t    , LEN_RECD);
               if (a_table [i].s_print [0] != '�') snprintf (t, 10, "%s������������", a_table [i].s_print);
               else                                snprintf (t, 10, "%s������������", "");
               strlcat (g_print, t    , LEN_RECD);
               snprintf (t, 26, "%s������������������������������������", a_table [i].s_desc);
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
      snprintf (t, 19, "%s�LEGEND��������������������", a_table [x_beg].s_print);
      strlcpy (g_print, t, LEN_RECD);
      strlcat (g_print, ">>", LEN_RECD);
      strlcat (g_print, x_heads, LEN_RECD);
   }
   /*---(complete)-----------------------*/
   DEBUG_YENV    yLOG_exit    (__FUNCTION__);
   return g_print;
}

char* yenv_score_legend (char a_line, char a_label [LEN_TERSE])  { return yenv_score__legend (s_audits, a_line, a_label, s_terse); }



