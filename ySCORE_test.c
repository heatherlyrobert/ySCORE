/*===[[ START ]]==============================================================*/
#include    "ySCORE.h"
#include    "ySCORE_priv.h"



char       /*----: set up programgents/debugging -----------------------------*/
yscore_unit_quiet    (void)
{
   char       *x_args [1]  = { "ySCORE" };
   return 0;
}

char       /*----: set up programgents/debugging -----------------------------*/
yscore_unit_loud     (void)
{
   char       *x_args [3]  = { "ySCORE_unit","@@kitchen", "@@yscore" };
   yURG_logger (3, x_args);
   yURG_urgs   (3, x_args);
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
yscore_unit_end      (void)
{
   yLOGS_end     ();
   return 0;
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
 *       0) indicates 4 character block headers (two upper case followed by 'á' and ' ')
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

const tSCORE_TABLE mySCORE_test [LEN_FULL] = {

   /*===[[ NAME ]]==========================================================*/
   { "NMá "     , ' ' ,  0  , "NAME"                             , ""         , ""         , ""                                                                                },
   /*===[[ REQUEST TYPE ]]==================================================*/
   { "NCONF"    , '·' , 'c' , "conf"     , "naming²standard²applied"          , "·°-nslc"   , "°) illegal   -) wild      n) normal    s) standard  l) local     c) central"     }, 
   { "NDIR"     , '·' , 'd' , "dir"      , "directory²requested"              , "·°£/D"     , "°) null      £) empty     /) pathless  D) passed"                                },
   { "NFILE"    , '·' , 'f' , "file"     , "file²name²requested"              , "·°£/F-"    , "°) null      £) empty     /) pathed    F) passed    -) skipped"                  },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ NAMING ]]========================================================*/
   { "NFULL"    , '·' , 'n' , "full"     , "name²quality²checking"            , "·°/´¢n"    , "°) null      /) not abs   ´) hidden    ¢) bad char  n) passed"                   },
   { "NSTYLE"   , '·' , 'b' , "style"    , "naming²style"                     , "·dfb"      , "d) dir       f) file      b) both"                                               },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ STANDARDS ]]=====================================================*/
   { "NDOTS"    , '·' , 'n' , "ndots"    , "file²name²separators"             , "·°<>n"     , "·) skipped   °) none      <) too few   >) too many  n) passed"                   },
   { "NPREFIX"  , '·' , 'p' , "prefix"   , "required²prefix"                  , "·°up"      , "·) skipped   °) failed    u) user      p) passed"                                },
   { "NSUFFIX"  , '·' , 's' , "suffix"   , "required²suffix"                  , "·°s"       , "·) skipped   °) failed    s) passed"                                             },
   { "NDESC"    , '·' , 'd' , "desc"     , "remaining²description"            , "·°d"       , "·) skipped   °) failed    d) passed"                                             },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ LOCATION ]]======================================================*/
   { "NLOC"     , '·' , 'h' , "loc"      , "file²location²type"               , "·°rhes"    , "·) skipped   °) failed    r) root      h) home      e) etc       s) spool"       },
   { "NUSE"     , '·' , 'H' , "usable"   , "file²location²usable"             , "·°RHES"    , "·) skipped   °) failed    R) root      H) home      E) etc       S) spool"       },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ REQUEST ]]=======================================================*/
   { "NAME"     , '-' , '´' , "ŒŒŒŒŒŒ"   , "[[²name²judgement²]]"             , "-°´"       , "-) unknown   °) failed    ´) passed"                                             },
   { "   "      , ' ' ,  3  , ""         , ""                                 , ""          , ""                                                                                },

   /*===[[ REQUEST ]]=======================================================*/
   { "EXá "     , ' ' ,  0  , "EXPECT"                           , ""         , ""          , ""                                                                                },
   /*===[[ REQUEST TYPE ]]==================================================*/
   { "ETYPE"    , '·' , 'r' , "type"     , "expected file type"               , "·drshcbpi?", "d) dir   r) reg   s) sym   h) hard  c) char  b) block p) pipe  i) ipsoc ?) WTF"  },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ REQUEST CHARS ]]=================================================*/
   { "EOWNER"   , '·' , 'o' , "owner"    , "expected owner"                   , "·oöo-"     , "o) standard   ö) numeric    O) default    -) skipped"                            },
   { "EGROUP"   , '·' , 'g' , "group"    , "expected group"                   , "·gêG-"     , "g) standard   ò) numeric    G) default    -) skipped"                            },
   { "EPERMS"   , '·' , 'p' , "perms"    , "expected permissions"             , "·p÷P-"     , "p) standard   ÷) non-std    P) default    -) skipped"                            },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ REQUEST DEVICE ]]================================================*/
   { "EMAJOR"   , '·' , 'j' , "major"    , "expected owner"                   , "·j-"       , "j) in-range   -) skipped"                                                        },
   { "EMINOR"   , '·' , 'n' , "minor"    , "expected group"                   , "·n-"       , "n) in-range   -) skipped"                                                        },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ REQUEST LINK ]]==================================================*/
   { "ETTYPE"   , '·' , 'r' , "ttype"    , "expected link target type"        , "·drshcbpi?", "d) dir   r) reg   s) sym   h) hard  c) char  b) block p) pipe  i) ipsoc ?) WTF"  },
   { "ETARGET"  , '·' , 't' , "target"   , "expected link target"             , "·/#t-"     , "/) not-abs    #) bad chars  t) accepted   -) skipped"                            },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ REQUEST EXTENDED ]]==============================================*/
   { "EEPOCH"   , '·' , 'e' , "epoch"    , "expected update time"             , "·e-"       , "e) accepted   -) skipped"                                                        },
   { "EBYTES"   , '·' , 'b' , "bytes"    , "expected size in bytes"           , "·b-"       , "b) accepted   -) skipped"                                                        },
   { "EINODE"   , '·' , 'i' , "inode"    , "expected inode"                   , "·i-"       , "i) accepted   -) skipped"                                                        },
   { "EHASH"    , '·' , 'h' , "hash"     , "expected file SHA hash"           , "·h-"       , "h) accepted   -) skipped"                                                        },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ REQUEST ]]=======================================================*/
   { "EXPECT"   , '-' , '´' , "ŒŒŒŒŒŒ"   , "judgement on request"             , "-°´"       , "´) passed"                                                                       },
   { "   "      , ' ' ,  3  , ""         , ""                                 , ""          , ""                                                                                },

   /*===[[ FINAL ]]=========================================================*/
   { "JDá "     , ' ' ,  0  , "³"                                , ""         , ""          , ""                                                                                },
   /*===[[ FINAL JUDGE ]]===================================================*/
   { "FINAL"    , ' ' , 'Ï' , "FINAL"    , "final judgement"                  , " °Ï"       , "Ï) passed"                                                                       },

   /*===[[ END-OF-LIST ]]===================================================*/
   { "end-list" , '·' , '·' , ""         , "end-of-entries"                   , ""          , ""                                                                                },
};


/*> tSCORE_TABLE mySCORE_yjobs [LEN_FULL] = {                                                                                                                                      <* 
 *>                                                                                                                                                                                <* 
 *>    /+===[[ NAME ]]==========================================================+/                                                                                                 <* 
 *>    { "NMá "     , ' ' ,  0  , "NAME"     , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ REQUEST TYPE ]]==================================================+/                                                                                                 <* 
 *>    { "NCONF"    , '·' , 'c' , "conf"     , "naming²standard²applied"          ,    0 , "°) illegal   -) wild      n) normal    s) standard  l) local     c) central"     },    <* 
 *>    { "NDIR"     , '·' , 'd' , "dir"      , "directory²requested"              ,    0 , "°) null      £) empty     /) pathless  D) passed"                                },    <* 
 *>    { "NFILE"    , '·' , 'f' , "file"     , "file²name²requested"              ,    0 , "°) null      £) empty     /) pathed    F) passed    -) skipped"                  },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ NAMING ]]========================================================+/                                                                                                 <* 
 *>    { "NFULL"    , '·' , 'n' , "full"     , "name²quality²checking"            ,    0 , "°) null      /) not abs   ´) hidden    ¢) bad char  n) passed"                   },    <* 
 *>    { "NSTYLE"   , '·' , 'b' , "style"    , "naming²style"                     ,    0 , "d) dir       f) file      b) both"                                               },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ STANDARDS ]]=====================================================+/                                                                                                 <* 
 *>    { "NDOTS"    , '·' , 'n' , "ndots"    , "file²name²separators"             ,    0 , "·) skipped   °) none      <) too few   >) too many  n) passed"                   },    <* 
 *>    { "NPREFIX"  , '·' , 'p' , "prefix"   , "required²prefix"                  ,    0 , "·) skipped   °) failed    u) user      p) passed"                                },    <* 
 *>    { "NSUFFIX"  , '·' , 's' , "suffix"   , "required²suffix"                  ,    0 , "·) skipped   °) failed    s) passed"                                             },    <* 
 *>    { "NDESC"    , '·' , 'd' , "desc"     , "remaining²description"            ,    0 , "·) skipped   °) failed    d) passed"                                             },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ LOCATION ]]======================================================+/                                                                                                 <* 
 *>    { "NLOC"     , '·' , 'h' , "loc"      , "file²location²type"               ,    0 , "·) skipped   °) failed    r) root      h) home      e) etc       s) spool"       },    <* 
 *>    { "NUSE"     , '·' , 'H' , "usable"   , "file²location²usable"             ,    0 , "·) skipped   °) failed    R) root      H) home      E) etc       S) spool"       },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ REQUEST ]]=======================================================+/                                                                                                 <* 
 *>    { "NAME"     , '-' , '´' , "ŒŒŒŒŒŒ"   , "[[²name²judgement²]]"             ,    0 , "-) unknown   °) failed    ´) passed"                                             },    <* 
 *>    { "   "      , ' ' ,  3  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>                                                                                                                                                                                <* 
 *>    /+===[[ REQUEST ]]=======================================================+/                                                                                                 <* 
 *>    { "EXá "     , ' ' ,  0  , "EXPECT"   , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ REQUEST TYPE ]]==================================================+/                                                                                                 <* 
 *>    { "ETYPE"    , '·' , 'r' , "type"     , "expected file type"               ,    0 , "d) dir   r) reg   s) sym   h) hard  c) char  b) block p) pipe  i) ipsoc ?) WTF"  },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ REQUEST CHARS ]]=================================================+/                                                                                                 <* 
 *>    { "EOWNER"   , '·' , 'o' , "owner"    , "expected owner"                   ,    0 , "o) standard   ö) numeric    O) default    -) skipped"                            },    <* 
 *>    { "EGROUP"   , '·' , 'g' , "group"    , "expected group"                   ,    0 , "g) standard   ò) numeric    G) default    -) skipped"                            },    <* 
 *>    { "EPERMS"   , '·' , 'p' , "perms"    , "expected permissions"             ,    0 , "p) standard   ÷) non-std    P) default    -) skipped"                            },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ REQUEST DEVICE ]]================================================+/                                                                                                 <* 
 *>    { "EMAJOR"   , '·' , 'j' , "major"    , "expected owner"                   ,    0 , "j) in-range   -) skipped"                                                        },    <* 
 *>    { "EMINOR"   , '·' , 'n' , "minor"    , "expected group"                   ,    0 , "n) in-range   -) skipped"                                                        },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ REQUEST LINK ]]==================================================+/                                                                                                 <* 
 *>    { "ETTYPE"   , '·' , 'r' , "ttype"    , "expected link target type"        ,    0 , "d) dir   r) reg   s) sym   h) hard  c) char  b) block p) pipe  i) ipsoc ?) WTF"  },    <* 
 *>    { "ETARGET"  , '·' , 't' , "target"   , "expected link target"             ,    0 , "/) not-abs    #) bad chars  t) accepted   -) skipped"                            },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ REQUEST EXTENDED ]]==============================================+/                                                                                                 <* 
 *>    { "EEPOCH"   , '·' , 'e' , "epoch"    , "expected update time"             ,    0 , "e) accepted   -) skipped"                                                        },    <* 
 *>    { "EBYTES"   , '·' , 'b' , "bytes"    , "expected size in bytes"           ,    0 , "b) accepted   -) skipped"                                                        },    <* 
 *>    { "EINODE"   , '·' , 'i' , "inode"    , "expected inode"                   ,    0 , "i) accepted   -) skipped"                                                        },    <* 
 *>    { "EHASH"    , '·' , 'h' , "hash"     , "expected file SHA hash"           ,    0 , "h) accepted   -) skipped"                                                        },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ REQUEST ]]=======================================================+/                                                                                                 <* 
 *>    { "EXPECT"   , '-' , '´' , "ŒŒŒŒŒŒ"   , "judgement on request"             ,    0 , "´) passed"                                                                       },    <* 
 *>    { "   "      , ' ' ,  3  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>                                                                                                                                                                                <* 
 *>    /+===[[ PRECHECK ]]======================================================+/                                                                                                 <* 
 *>    { "PRá "     , ' ' ,  0  , "CHECK"    , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ CHECK TYPE ]]====================================================+/                                                                                                 <* 
 *>    { "CTYPE"    , '·' , 'r' , "type"     , "checked file type"                ,    0 , "same as expected type, lower case if matching, upper case if not-match"          },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ CHECK CHARS ]]===================================================+/                                                                                                 <* 
 *>    { "COWNER"   , '·' , 'o' , "owner"    , "checked owner"                    ,    0 , "o) match      O) not-match"                                                      },    <* 
 *>    { "CGROUP"   , '·' , 'g' , "group"    , "checked group"                    ,    0 , "g) match      G) not-match"                                                      },    <* 
 *>    { "CPERMS"   , '·' , 'p' , "perms"    , "checked permissions"              ,    0 , "p) match      P) not-match"                                                      },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ CHECK DEVICE ]]==================================================+/                                                                                                 <* 
 *>    { "CMAJOR"   , '·' , 'j' , "major"    , "checked owner"                    ,    0 , "j) match      J) not-match"                                                      },    <* 
 *>    { "CMINOR"   , '·' , 'n' , "minor"    , "checked group"                    ,    0 , "n) match      N) not-match"                                                      },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ CHECK LINK ]]====================================================+/                                                                                                 <* 
 *>    { "CTTYPE"   , '·' , 'r' , "ttype"    , "checked link target type"         ,    0 , "t) match      T) not-match"                                                      },    <* 
 *>    { "CTARGET"  , '·' , 't' , "target"   , "checked link target"              ,    0 , "t) match      T) not-match"                                                      },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ CHECK JUDGE ]]===================================================+/                                                                                                 <* 
 *>    { "CHECK"    , '-' , '´' , "ŒŒŒŒŒŒ"   , "judgement on check"               ,    0 , "-) skipped    ´) passed"                                                         },    <* 
 *>    { "   "      , ' ' ,  3  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>                                                                                                                                                                                <* 
 *>    /+===[[ FIXES ]]=========================================================+/                                                                                                 <* 
 *>    { "FXá "     , ' ' ,  0  , "FIXES"    , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ REQUEST ]]=======================================================+/                                                                                                 <* 
 *>    { "EFLAG"    , '·' , 'F' , "flag"     , "fix/forcing flag interpretation"  ,    0 , "-) none allowed  f) allow fix     F) allow create  !) can even remove"           },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ CONFIGURATION ]]=================================================+/                                                                                                 <* 
 *>    { "CONFC"    , '·' , 'y' , "check"    , "judgement on request"             ,    0 , "y) precheck    -) not-requested"                                                 },    <* 
 *>    { "CONFF"    , '·' , 'y' , "force"    , "judgement on request"             ,    0 , "y) create, if must   !) remove, if must   -) not-requested"                      },    <* 
 *>    { "CONFX"    , '·' , 'y' , "fix"      , "judgement on request"             ,    0 , "y) fix, if must      -) not-requested"                                           },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ FIX/FORCES ]]====================================================+/                                                                                                 <* 
 *>    { "FDEL"     , '·' , 'r' , "remove"   , "need forced deletion"             ,    0 , "r) requires deletion   -) not needed"                                            },    <* 
 *>    { "FADD"     , '·' , 'c' , "create"   , "need forced creation"             ,    0 , "c) requires creation   -) not needed"                                            },    <* 
 *>    { "FUPD"     , '·' , 'u' , "update"   , "need forced updates"              ,    0 , "u) requires updates    -) not needed"                                            },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ ACTUAL ]]========================================================+/                                                                                                 <* 
 *>    { "REMOVE"   , '·' , 'R' , "REMOVE"   , "actual deletion"                  ,    0 , "R) really removed    ?) non-existant      !) not enough force  -) not needed"    },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    { "CREATE"   , '·' , 'C' , "CREATE"   , "actual creation"                  ,    0 , "C) really created    ?) already exists    !) not enough force  -) not needed"    },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    { "UPDATE"   , '·' , 'U' , "UPDATE"   , "actual updates"                   ,    0 , "U) really updated    !) not enough force  -) not needed"                         },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ RE-CHECK JUDGE ]]================================================+/                                                                                                 <* 
 *>    { "FIXES"    , '-' , '´' , "ŒŒŒŒŒŒ"   , "judgement on fixes"               ,    0 , "-) skipped    ´) passed"                                                         },    <* 
 *>    { "   "      , ' ' ,  3  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>                                                                                                                                                                                <* 
 *>    /+===[[ RECHECK ]]=======================================================+/                                                                                                 <* 
 *>    { "REá "     , ' ' ,  0  , "RECHECK"  , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ RE-CHECK TYPE ]]=================================================+/                                                                                                 <* 
 *>    { "RTYPE"    , '·' , 'r' , "type"     , "checked file type"                ,    0 , "same as expected type, lower case if matching, upper case if not-match"          },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ RE-CHECK CHARS ]]================================================+/                                                                                                 <* 
 *>    { "ROWNER"   , '·' , 'o' , "owner"    , "re-checked owner"                 ,    0 , "o) match      O) not-match"                                                      },    <* 
 *>    { "RGROUP"   , '·' , 'g' , "group"    , "re-checked group"                 ,    0 , "g) match      G) not-match"                                                      },    <* 
 *>    { "RPERMS"   , '·' , 'p' , "perms"    , "re-checked permissions"           ,    0 , "p) match      P) not-match"                                                      },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ RE-CHECK DEVICE ]]===============================================+/                                                                                                 <* 
 *>    { "RMAJOR"   , '·' , 'j' , "major"    , "re-checked owner"                 ,    0 , "j) match      J) not-match"                                                      },    <* 
 *>    { "RMINOR"   , '·' , 'n' , "minor"    , "re-checked group"                 ,    0 , "n) match      N) not-match"                                                      },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ RE-CHECK LINK ]]=================================================+/                                                                                                 <* 
 *>    { "RTTYPE"   , '·' , 'r' , "ttype"    , "re-checked link target type"      ,    0 , "t) match      T) not-match"                                                      },    <* 
 *>    { "RTARGET"  , '·' , 't' , "target"   , "re-checked link target"           ,    0 , "t) match      T) not-match"                                                      },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ RE-CHECK JUDGE ]]================================================+/                                                                                                 <* 
 *>    { "RECHECK"  , '-' , '´' , "ŒŒŒŒŒŒ"   , "judgement on re-check"            ,    0 , "´) passed"                                                                       },    <* 
 *>    { "   "      , ' ' ,  3  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>                                                                                                                                                                                <* 
 *>    /+===[[ FINAL ]]=========================================================+/                                                                                                 <* 
 *>    { "JDá "     , ' ' ,  0  , "³"        , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ FINAL JUDGE ]]===================================================+/                                                                                                 <* 
 *>    { "FINAL"    , ' ' , 'Ï' , "FINAL"    , "final judgement"                  ,    0 , "Ï) passed"                                                                       },    <* 
 *>    { "   "      , ' ' ,  3  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>                                                                                                                                                                                <* 
 *>    /+===[[ HACKED ]]========================================================+/                                                                                                 <* 
 *>    { "HKá "     , ' ' ,  0  , "HACK"     , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ HACKING CHECK ]]=================================================+/                                                                                                 <* 
 *>    { "AEPOCH"   , '·' , 'e' , "epoch"    , "check update time"                ,    0 , "e) matches    E) not-match"                                                      },    <* 
 *>    { "ABYTES"   , '·' , 'b' , "bytes"    , "check size in bytes"              ,    0 , "b) matches    B) not-match"                                                      },    <* 
 *>    { "AINODE"   , '·' , 'i' , "inode"    , "check inode"                      ,    0 , "i) matches    I) not-match"                                                      },    <* 
 *>    { "AHASH"    , '·' , 'h' , "hash"     , "check file SHA hash"              ,    0 , "h) matches    H) not-match"                                                      },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                },    <* 
 *>    /+===[[ HACKING FINAL ]]=================================================+/                                                                                                 <* 
 *>    { "HACKED"   , '-' , '´' , "ŒŒŒŒŒŒ"   , "final hacking judgement"          ,    0 , "-) skipped    ´) passed"                                                         },    <* 
 *>                                                                                                                                                                                <* 
 *>    /+===[[ END-OF-LIST ]]===================================================+/                                                                                                 <* 
 *>    { "end-list" , '·' , '·' , ""         , "end-of-entries"                   ,    0 , ""                                                                                },    <* 
 *>                                                                                                                                                                                <* 
 *>    /+===[[ DONE ]]==========================================================+/                                                                                                 <* 
 *> };                                                                                                                                                                             <*/

/*> tSCORE_TABLE mySCORE_poly [LEN_FULL] = {                                                                                                                                                           <* 
 *>                                                                                                                                                                                                    <* 
 *>    /+===[[ GROUP ONE -- COMPLEXITY ]]============================+/                                                                                                                                <* 
 *>    { "COá "     , ' ' ,  0  , "COMPLEXITY"                         , ""       ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "ONE"      , '·' , '·' , "one"      , "one line function"                ,    0 , "y)yes      ·)normal"                                                                                 },    <* 
 *>    { "SCOPE"    , '·' , 'g' , "scope"    , "function²scope"                   ,    0 , "e)extern   g)global   f)file     s)static   u)unit"                                                  },    <* 
 *>    { "RTYPE"    , '·' , 'c' , "rtype"    , "return type"                      ,    0 , "s)string   c)char     v)void     p)point    n)number   o)other    _)title"                           },    <* 
 *>    { "PROTO"    , '·' , '·' , "proto"    , "prototype location"               ,    0 , "g)global   f)file     -)none"                                                                        },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "PAUDIT"   , '·' , '·' , "paudit"   , "audit of params"                  ,    0 , "tbd"                                                                                                 },    <* 
 *>    { "PARAMS"   , '·' , '·' , "params"   , "number of parameters"             ,    0 , "?)WTF      0)void     1-3)low    4-6)mid    7-9)high   #)huge"                                       },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "PIN"      , '·' , '·' , "pin"      , "incomming parameters   (a)"       ,    0 , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },    <* 
 *>    { "POUT"     , '·' , '·' , "pout"     , "outgoing parameters    (r)"       ,    0 , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },    <* 
 *>    { "PBOTH"    , '·' , '·' , "pboth"    , "both in/out parameters (b)"       ,    0 , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },    <* 
 *>    { "PCONF"    , '·' , '·' , "pconf"    , "run-time configuration (c)"       ,    0 , "?)WTF      0)none     1-3)ok     4+)high"                                                            },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "PNUM"     , '·' , '·' , "pnum"     , "params use number pointers"       ,    0 , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },    <* 
 *>    { "PMULTI"   , '·' , '·' , "pmulti"   , "params use multiple pointers"     ,    0 , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },    <* 
 *>    { "PFUNC"    , '·' , '·' , "pfunc"    , "function pointers      (f)"       ,    0 , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "PSTRUC"   , '·' , '·' , "pstruc"   , "params use structures"            ,    0 , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "TOTAL"    , '·' , '·' , "total"    , "total actual lines (div 5)"       ,    0 , "1-4)small  5-9)mod    A-D)full   E-H)large  I-N)huge   O-Z)SCARY  #)JESUS"                           },    <* 
 *>    { "DEBUG"    , '·' , '·' , "debug"    , "debugging lines (% total)"        ,    0 , "0-1)tiny   2-4)avg    5-7)high   A)warning"                                                          },    <* 
 *>    { "CODE"     , '·' , '·' , "code"     , "lines of code logical (% total)"  ,    0 , "1-3)low    4-7)avg    8-9)high   A)warning"                                                          },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "LVARS"    , '·' , '·' , "lvars"    , "number of local vars used"        ,    0 , "0)none     1-3)few    4-6)avg    7-9)heavy  A-Z)SCARY  #)JESUS"                                      },    <* 
 *>    { "FVARS"    , '·' , '·' , "fvars"    , "number of file/static vars used"  ,    0 , "0)none     1-3)few    4-6)avg    7-9)heavy  A-Z)SCARY  #)JESUS"                                      },    <* 
 *>    { "GVARS"    , '·' , '·' , "gvars"    , "number of global vars used"       ,    0 , "0)none     1-2)avg    3-6)lots   7-9)heavy  A-Z)SCARY  #)JESUS"                                      },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "INDENT"   , '·' , '·' , "indent"   , "depth of indentation"             ,    0 , "0)none     1)avg      2-4)lots   5+)SCARY"                                                           },    <* 
 *>    { "LOOP"     , '·' , '·' , "loop"     , "number of loops"                  ,    0 , "0)none     1)avg      2-4)lots   5+)SCARY"                                                           },    <* 
 *>    { "CHOICE"   , '·' , '·' , "choice"   , "number of choices/decisions"      ,    0 , "0)none     1-3)avg    4-9)lots   A-Z)SCARY  #)JESUS"                                                 },    <* 
 *>    { "RETURN"   , '·' , '·' , "return"   , "number of return/exit points"     ,    0 , "0)WTF      1)perfect  2-5)avg    6+)SCARY"                                                           },    <* 
 *>    { "RERROR"   , '·' , '·' , "rerror"   , "return with errors"               ,    0 , "0)none     1-3)avg    4-6)logs   9+)major"                                                           },    <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "MEMORY"   , '·' , '·' , "memory"   , "memory management used"           ,    0 , "-)none     #)in-use"                                                                                 },    <* 
 *>    { "   "      , ' ' ,  3  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>                                                                                                                                                                                                    <* 
 *>    /+===[[ GROUP TWO -- INTEGRATION ]]===========================+/                                                                                                                                <* 
 *>    { "INá "     , ' ' ,  0  , "INTEGRATION"                        , ""       ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "CALLED"   , '·' , '·' ,  "called"   , "called by anything else"         ,    0 , "" },                                                                                                       <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "FCALL"    , '·' , '·' ,  "Fcall"    , "called by in-file functions"     ,    0 , "" },                                                                                                       <* 
 *>    { "GCALL"    , '·' , '·' ,  "Gcall"    , "called by global functions"      ,    0 , "" },                                                                                                       <* 
 *>    { "XCALL"    , '·' , '·' ,  "Xcall"    , "called by external programs"     ,    0 , "" },                                                                                                       <* 
 *>    { "REURS"    , '·' , '·' ,  "recurs"   , "function is recursive"           ,    0 , "" },                                                                                                       <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "CALLTO"   , '·' , '·' ,  "callto"   , "calls to any/all functions"      ,    0 , "" },                                                                                                       <* 
 *>    { "DFUNC"    , '·' , '·' ,  "Dfuncs"   , "calls to debugging functions"    ,    0 , "" },                                                                                                       <* 
 *>    { "RFUNC"    , '·' , '·' ,  "Rfuncs"   , "calls to real/non-debug"         ,    0 , "" },                                                                                                       <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "FFUNC"    , '·' , '·' ,  "Ffunc"    , "calls to in-file functions"      ,    0 , "" },                                                                                                       <* 
 *>    { "GFUNC"    , '·' , '·' ,  "Gfunc"    , "calls to global functions"       ,    0 , "" },                                                                                                       <* 
 *>    { "CSTD"     , '·' , '·' ,  "cstd"     , "calls to c-std libraries"        ,    0 , "" },                                                                                                       <* 
 *>    { "YLIB"     , '·' , '·' ,  "ylib"     , "calls to my custom libraries"    ,    0 , "" },                                                                                                       <* 
 *>    { "VIKEYS"   , '·' , '·' ,  "vikeys"   , "calls to vi-keys libraries"      ,    0 , "" },                                                                                                       <* 
 *>    { "OFUNC"    , '·' , '·' ,  "Ofunc"    , "calls to other libraries"        ,    0 , "" },                                                                                                       <* 
 *>    { "MYSTRY"   , '·' , '·' ,  "mystry"   , "calls to unknown functions"      ,    0 , "" },                                                                                                       <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "INPUT"    , '·' , '·' ,  "input"    , "stdin and file input"            ,    0 , "" },                                                                                                       <* 
 *>    { "OUTPUT"   , '·' , '·' ,  "output"   , "stdout and file output"          ,    0 , "" },                                                                                                       <* 
 *>    { "SYSTEM"   , '·' , '·' ,  "system"   , "unix process or system calls"    ,    0 , "" },                                                                                                       <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "NCURSE"   , '·' , '·' ,  "ncurse"   , "ncurses function calls"          ,    0 , "" },                                                                                                       <* 
 *>    { "OPENGL"   , '·' , '·' ,  "opengl"   , "opengl function calls"           ,    0 , "" },                                                                                                       <* 
 *>    { "WINDOW"   , '·' , '·' ,  "window"   , "x11 and like functions calls"    ,    0 , "" },                                                                                                       <* 
 *>    { "YGRAPH"   , '·' , '·' ,  "ygraph"   , "my x11/opengl support libs"      ,    0 , "" },                                                                                                       <* 
 *>    { "   "      , ' ' ,  3  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>                                                                                                                                                                                                    <* 
 *>    /+===[[ GROUP THREE -- WATCH POINTS ]]========================+/                                                                                                                                <* 
 *>    { "WAá "     , ' ' ,  0  , "WATCH-POINTS"                       , ""       ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "DACTIV"   , '·' , '·' ,  "Dactiv"   , "debugging is used"               ,    0 , "" },                                                                                                       <* 
 *>    { "DSTYLE"   , '·' , '·' ,  "Dstyle"   , "debugging style"                 ,    0 , "" },                                                                                                       <* 
 *>    { "DMACRO"   , '·' , '·' ,  "Dmacro"   , "debugging macros used"           ,    0 , "" },                                                                                                       <* 
 *>    { "DMATCH"   , '·' , '·' ,  "Dmatch"   , "debugging enter/exit match"      ,    0 , "" },                                                                                                       <* 
 *>    { "DWARN"    , '·' , '·' ,  "Dwarn"    , "debugging trouble marker"        ,    0 , "" },                                                                                                       <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "MACROS"   , '·' , '·' ,  "macros"   , "potential #define macros"        ,    0 , "" },                                                                                                       <* 
 *>    { "MFILE"    , '·' , '·' ,  "mfile"    , "in-file #define macro use"       ,    0 , "" },                                                                                                       <* 
 *>    { "MPROJ"    , '·' , '·' ,  "mproj"    , "global #define macro use"        ,    0 , "" },                                                                                                       <* 
 *>    { "MCSTD"    , '·' , '·' ,  "mcstd"    , "cstd #define macro use"          ,    0 , "" },                                                                                                       <* 
 *>    { "MYLOB"    , '·' , '·' ,  "mylib"    , "ylib #define macro use"          ,    0 , "" },                                                                                                       <* 
 *>    { "MVIKEY"   , '·' , '·' ,  "mvikey"   , "vikeys #define macro use"        ,    0 , "" },                                                                                                       <* 
 *>    { "MOTHER"   , '·' , '·' ,  "mother"   , "unknown/other macros"            ,    0 , "" },                                                                                                       <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "VMASK"    , '·' , '·' ,  "vmask"    , "vars masking other vars"         ,    0 , "" },                                                                                                       <* 
 *>    { "MMASK"    , '·' , '·' ,  "mmask"    , "macros masking other macros"     ,    0 , "" },                                                                                                       <* 
 *>    { "FMASK"    , '·' , '·' ,  "fmask"    , "funcs masking other funcs"       ,    0 , "" },                                                                                                       <* 
 *>    { "LSTAT"    , '·' , '·' ,  "lstat"    , "local static variables"          ,    0 , "" },                                                                                                       <* 
 *>    { " "        , ' ' ,  1  , ""         , ""                                 ,    0 , ""                                                                                                    },    <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>    { "UNITS"    , '·' , '·' ,  "units"    , "count of unit tests used"        ,    0 , "" },                                                                                                       <* 
 *>    { "SCRPS"    , '·' , '·' ,  "scrps"    , "count of unit scripts used"      ,    0 , "" },                                                                                                       <* 
 *>    { "STEPS"    , '·' , '·' ,  "steps"    , "count of unit steps used"        ,    0 , "" },                                                                                                       <* 
 *>    { "STRING"   , '·' , '·' ,  "string"   , "count of string tests"           ,    0 , "" },                                                                                                       <* 
 *>    /+-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- +/   <* 
 *>                                                                                                                                                                                                    <* 
 *>    /+===[[ END-OF-LIST ]]===================================================+/                                                                                                                     <* 
 *>    { "end-list" , '·' , '·' , ""         , "end-of-entries"                   ,    0 , ""                                                                                                    },    <* 
 *>                                                                                                                                                                                                    <* 
 *>    /+===[[ DONE ]]==========================================================+/                                                                                                                     <* 
 *> };                                                                                                                                                                                                 <*/
