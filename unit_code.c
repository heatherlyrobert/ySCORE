#include    "unit_code.h"


static char u_home  [LEN_FULL]  = "";


char       /*----: set up programgents/debugging -----------------------------*/
yscore__unit_quiet      (void)
{
   char       *x_args [1]  = { "ySCORE" };
   getcwd (u_home, LEN_PATH);
   return 0;
}

char       /*----: set up programgents/debugging -----------------------------*/
yscore__unit_loud       (void)
{
   char       *x_args [3]  = { "ySCORE_unit","@@kitchen", "@@yscore" };
   getcwd (u_home, LEN_PATH);
   yURG_logger (3, x_args);
   yURG_urgs   (3, x_args);
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
yscore__unit_end        (void)
{
   chdir (u_home);
   yLOGS_end     ();
   return 0;
}



const tySCORE_TB mySCORE_test [LEN_FULL] = {
   /*===[[ NAME ]]=========== print======= description========================= style check valid============== legend====== ============ ============ ============ ============ ============ ============   */
   { 'Ï' , "NMá "     , '>' ,  0  , "NAME"                             , ""         , ' ' , ' ' , ""                , ""                                                                                          },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "NCONF"    , '·' , 'c' , "conf"     , "naming²standard²applied"          , '·' , '·' , "·°-nslc"         , "°) illegal   -) wild      n) normal    s) standard  l) local     c) central"               }, 
   { 'Ï' , "NDIR"     , '·' , 'd' , "dir"      , "directory²requested"              , '·' , '·' , "·°£/D"           , "°) null      £) empty     /) pathless  D) passed"                                          },
   { 'Ï' , "NFILE"    , '·' , 'f' , "file"     , "file²name²requested"              , '·' , '·' , "·°£/F-"          , "°) null      £) empty     /) pathed    F) passed    -) skipped"                            },
   { '>' , "NEXTRA"   , '·' , '-' , "extra"    , "just a hidden line"               , '·' , '·' , "·°abcdef"        , "°) null      £) empty     /) pathed    F) passed    -) skipped"                            },
   { 'Ï' , " "        , '´' ,  1  , ""         , ""                                 , ' ' , ' ' , ""                , ""                                                                                          },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "NFULL"    , '·' , 'n' , "full"     , "name²quality²checking"            , '·' , '·' , "·°/´¢n"          , "°) null      /) not abs   ´) hidden    ¢) bad char  n) passed"                             },
   { 'Ï' , "NSTYLE"   , '·' , 'b' , "style"    , "naming²style"                     , '·' , '·' , "·dfb"            , "d) dir       f) file      b) both"                                                         },
   { 'Ï' , " "        , '´' ,  1  , ""         , ""                                 , ' ' , ' ' , ""                , ""                                                                                          },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "NDOTS"    , '·' , 'n' , "ndots"    , "file²name²separators"             , '·' , '·' , "·°<>n"           , "·) skipped   °) none      <) too few   >) too many  n) passed"                             },
   { 'Ï' , "NPREFIX"  , '·' , 'p' , "prefix"   , "required²prefix"                  , '·' , '·' , "·°up"            , "·) skipped   °) failed    u) user      p) passed"                                          },
   { 'Ï' , "NSUFFIX"  , '·' , 's' , "suffix"   , "required²suffix"                  , '·' , '·' , "·°s"             , "·) skipped   °) failed    s) passed"                                                       },
   { 'Ï' , "NDESC"    , '·' , 'd' , "desc"     , "remaining²description"            , '·' , '·' , "·°d"             , "·) skipped   °) failed    d) passed"                                                       },
   { 'Ï' , " "        , '´' ,  1  , ""         , ""                                 , ' ' , ' ' , ""                , ""                                                                                          },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "NLOC"     , '·' , 'h' , "loc"      , "file²location²type"               , '·' , '·' , "·°rhes"          , "·) skipped   °) failed    r) root      h) home      e) etc       s) spool"                 },
   { 'Ï' , "NUSE"     , '·' , 'H' , "usable"   , "file²location²usable"             , '·' , '·' , "·°RHES"          , "·) skipped   °) failed    R) root      H) home      E) etc       S) spool"                 },
   { 'Ï' , " "        , '´' ,  1  , ""         , ""                                 , ' ' , ' ' , ""                , ""                                                                                          },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "NAME"     , '-' , '´' , "ŒŒŒŒŒŒ"   , "[[²name²judgement²]]"             , '·' , '·' , "-°´"             , "-) unknown   °) failed    ´) passed"                                                       },
   { 'Ï' , "   "      , ' ' ,  3  , ""         , ""                                 , ' ' , ' ' , ""                , ""                                                                                          },

   /*===[[ REQUEST ]]======== print======= description========================= style check valid============== legend====== ============ ============ ============ ============ ============ ============   */
   { 'Ï' , "EXá "     , '>' ,  0  , "EXPECT"                           , ""         , ' ' , ' ' , ""                , ""                                                                                          },
   { 'Ï' , "ETYPE"    , '·' , 'r' , "type"     , "expected file type"               , '·' , '·' , "·drshcbpi?"      , "d) dir   r) reg   s) sym   h) hard  c) char  b) block p) pipe  i) ipsoc ?) WTF"            },
   { 'Ï' , " "        , '´' ,  1  , ""         , ""                                 , ' ' , ' ' , ""                , ""                                                                                          },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "EOWNER"   , '·' , 'o' , "owner"    , "expected owner"                   , '·' , '·' , "·oöo-"           , "o) standard   ö) numeric    O) default    -) skipped"                                      },
   { 'Ï' , "EGROUP"   , '·' , 'g' , "group"    , "expected group"                   , '·' , '·' , "·gêG-"           , "g) standard   ò) numeric    G) default    -) skipped"                                      },
   { 'Ï' , "EPERMS"   , '·' , 'p' , "perms"    , "expected permissions"             , '·' , '·' , "·p÷P-"           , "p) standard   ÷) non-std    P) default    -) skipped"                                      },
   { 'Ï' , " "        , '´' ,  1  , ""         , ""                                 , ' ' , ' ' , ""                , ""                                                                                          },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "EMAJOR"   , '·' , 'j' , "major"    , "expected owner"                   , '·' , '·' , "·j-"             , "j) in-range   -) skipped"                                                                  },
   { 'Ï' , "EMINOR"   , '·' , 'n' , "minor"    , "expected group"                   , '·' , '·' , "·n-"             , "n) in-range   -) skipped"                                                                  },
   { 'Ï' , " "        , '´' ,  1  , ""         , ""                                 , ' ' , ' ' , ""                , ""                                                                                          },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "ETTYPE"   , '·' , 'r' , "ttype"    , "expected link target type"        , '·' , '·' , "·drshcbpi?"      , "d) dir   r) reg   s) sym   h) hard  c) char  b) block p) pipe  i) ipsoc ?) WTF"            },
   { 'Ï' , "ETARGET"  , '·' , 't' , "target"   , "expected link target"             , '·' , '·' , "·/#t-"           , "/) not-abs    #) bad chars  t) accepted   -) skipped"                                      },
   { 'Ï' , " "        , '´' ,  1  , ""         , ""                                 , ' ' , ' ' , ""                , ""                                                                                          },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "EEPOCH"   , '·' , 'e' , "epoch"    , "expected update time"             , '·' , '·' , "·e-"             , "e) accepted   -) skipped"                                                                  },
   { 'Ï' , "EBYTES"   , '·' , 'b' , "bytes"    , "expected size in bytes"           , '·' , '·' , "·b-"             , "b) accepted   -) skipped"                                                                  },
   { 'Ï' , "EINODE"   , '·' , 'i' , "inode"    , "expected inode"                   , '·' , '·' , "·i-"             , "i) accepted   -) skipped"                                                                  },
   { 'Ï' , "EHASH"    , '·' , 'h' , "hash"     , "expected file SHA hash"           , '·' , '·' , "·h-"             , "h) accepted   -) skipped"                                                                  },
   { 'Ï' , " "        , '´' ,  1  , ""         , ""                                 , ' ' , ' ' , ""                , ""                                                                                          },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "EXPECT"   , '-' , '´' , "ŒŒŒŒŒŒ"   , "judgement on request"             , '·' , '·' , "-°´"             , "´) passed"                                                                                 },
   { 'Ï' , "   "      , ' ' ,  3  , ""         , ""                                 , ' ' , ' ' , ""                , ""                                                                                          },

   /*===[[ JUDGE ]]========== print======= description========================= style check valid============== legend====== ============ ============ ============ ============ ============ ============   */
   { 'Ï' , "JDá "     , '>' ,  0  , "³"                                , ""         , ' ' , ' ' , ""                , ""                                                                                          },
   { 'Ï' , "FINAL"    , ' ' , 'Ï' , "FINAL"    , "final judgement"                  , '·' , '·' , " °Ï"             , "Ï) passed"                                                                                 },

   /*===[[ END-OF-LIST ]]==== print======= description========================= style check valid============== legend====== ============ ============ ============ ============ ============ ============   */
   { 'Ï' , "end-list" , ' ' , '·' , ""         , "end-of-entries"                   , ' ' , '·' , ""                , ""                                                                                          },
};



const tySCORE_TB mySCORE_poly [LEN_FULL] = {
   /*===[[ COMPLEXITY ]]===== print======= description========================= style check valid============== legend====== ============ ============ ============ ============ ============ ============   */
   { 'Ï' , "COá "     , 'á' ,  0  , "COMPLEXITY"                         , ""       , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "ONE"      , '·' , '-' , "one"      , "one²line²function"                , '·' , '·' , "·y"              , "y)yes      ·)normal"                                                                                 },
   { 'Ï' , "SCOPE"    , '·' , 'g' , "scope"    , "function²scope"                   , '·' , '·' , "·°egfsu"         , "e)extern   g)global   f)file     s)static   u)unit"                                                  },
   { 'Ï' , "RTYPE"    , '·' , 'c' , "rtype"    , "function²return²type"             , '·' , '·' , "·°scvpno_"       , "s)string   c)char     v)void     p)point    n)number   o)other    _)title"                           },
   { 'Ï' , "PROTO"    , '·' , 'g' , "proto"    , "prototype²location"               , '·' , '·' , "·°gf-"           , "g)global   f)file     -)none"                                                                        },
   { 'Ï' , " "        , '´' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "PAUDIT"   , '·' , 'y' , "paudit"   , "audit²of²parameters"              , '·' , '·' , "·"               , "tbd"                                                                                                 },
   { 'Ï' , "PARAMS"   , '·' , 'A' , "params"   , "number²of²parameters"             , '·' , '·' , "·°?0-9#"         , "?)WTF      0)void     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { 'Ï' , " "        , '´' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "PIN"      , '·' , '4' , "pin"      , "param²incomming²²²(a)"            , '·' , '·' , "·°?0-9#"         , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { 'Ï' , "POUT"     , '·' , '3' , "pout"     , "param²outgoing²²²²(r)"            , '·' , '·' , "·°?0-9#"         , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { 'Ï' , "PBOTH"    , '·' , '2' , "pboth"    , "param²both²in/out²(b)"            , '·' , '·' , "·°?0-9#"         , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { 'Ï' , "PCONF"    , '·' , '1' , "pconf"    , "param²for²config²²(c)"            , '·' , '·' , "·°?0-9#"         , "?)WTF      0)none     1-3)ok     4+)high"                                                            },
   { 'Ï' , " "        , '´' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "PNUM"     , '·' , '2' , "pnum"     , "param²number²pointers"            , '·' , '·' , "·°?0-9#"         , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { 'Ï' , "PMULTI"   , '·' , '3' , "pmulti"   , "param²multiple²pointers"          , '·' , '·' , "·°?0-9#"         , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { 'Ï' , "PFUNC"    , '·' , '4' , "pfunc"    , "param²function²pointers"          , '·' , '·' , "·°?0-9#"         , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "PSTRUC"   , '·' , '1' , "pstruc"   , "param²struct²pointers"            , '·' , '·' , "·°?0-9#"         , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "TOTAL"    , '·' , '9' , "total"    , "total²actual²lines"               , '·' , '·' , "·°0-9A-Z#"       , "1-4)small  5-9)mod    A-D)full   E-H)large  I-N)huge   O-Z)SCARY  #)JESUS"                           },
   { 'Ï' , "DEBUG"    , '·' , '3' , "debug"    , "pct²debugging²lines"              , '·' , '·' , "·°0-9A"          , "0-1)tiny   2-4)avg    5-7)high   A)warning"                                                          },
   { 'Ï' , "CODE"     , '·' , '6' , "code"     , "pct²code²lines"                   , '·' , '·' , "·°0-9A"          , "1-3)low    4-7)avg    8-9)high   A)warning"                                                          },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "LVARS"    , '·' , '1' , "lvars"    , "num²local²vars²used"              , '·' , '·' , "·°0-9A-Z#"       , "0)none     1-3)few    4-6)avg    7-9)heavy  A-Z)SCARY  #)JESUS"                                      },
   { 'Ï' , "FVARS"    , '·' , '2' , "fvars"    , "num²file²vars²used"               , '·' , '·' , "·°0-9A-Z#"       , "0)none     1-3)few    4-6)avg    7-9)heavy  A-Z)SCARY  #)JESUS"                                      },
   { 'Ï' , "GVARS"    , '·' , '3' , "gvars"    , "num²global²vars²used"             , '·' , '·' , "·°0-9A-Z#"       , "0)none     1-2)avg    3-6)lots   7-9)heavy  A-Z)SCARY  #)JESUS"                                      },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "INDENT"   , '·' , '1' , "indent"   , "depth²of²indentation"             , '·' , '·' , "·°0-9A-Z#"       , "0)none     1)avg      2-4)lots   5+)SCARY"                                                           },
   { 'Ï' , "LOOP"     , '·' , '2' , "loop"     , "num²looping²statements"           , '·' , '·' , "·°0-9A-Z#"       , "0)none     1)avg      2-4)lots   5+)SCARY"                                                           },
   { 'Ï' , "CHOICE"   , '·' , '3' , "choice"   , "num²choices/decisions"            , '·' , '·' , "·°0-9A-Z#"       , "0)none     1-3)avg    4-9)lots   A-Z)SCARY  #)JESUS"                                                 },
   { 'Ï' , "RETURN"   , '·' , '4' , "return"   , "num²normal²returns"               , '·' , '·' , "·°0-9A-Z#"       , "0)WTF      1)perfect  2-5)avg    6+)SCARY"                                                           },
   { 'Ï' , "RERROR"   , '·' , '5' , "rerror"   , "num²return²with²errors"           , '·' , '·' , "·°0-9A-Z#"       , "0)none     1-3)avg    4-6)logs   9+)major"                                                           },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "MEMORY"   , '·' , 'y' , "memory"   , "memory²management²used"           , '·' , '·' , "·°-#"            , "-)none     #)in-use"                                                                                 },
   { 'Ï' , "   "      , ' ' ,  3  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },

   /*===[[ INTEGRATION ]]==== print======= description========================= style check valid============== legend====== ============ ============ ============ ============ ============ ============   */
   { 'Ï' , "INá "     , ' ' ,  0  , "INTEGRATION"                        , ""       , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "CALLED"   , '·' , '·' ,  "called"   , "called by anything else"         , '·' , '·' , ""                , "" },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "FCALL"    , '·' , '·' ,  "fcall"    , "called by in-file functions"     , '·' , '·' , ""                , "" },
   { 'Ï' , "GCALL"    , '·' , '·' ,  "gcall"    , "called by global functions"      , '·' , '·' , ""                , "" },
   { 'Ï' , "XCALL"    , '·' , '·' ,  "xcall"    , "called by external programs"     , '·' , '·' , ""                , "" },
   { 'Ï' , "REURS"    , '·' , '·' ,  "recurs"   , "function is recursive"           , '·' , '·' , ""                , "" },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "CALLTO"   , '·' , '·' ,  "callto"   , "calls to any/all functions"      , '·' , '·' , ""                , "" },
   { 'Ï' , "DFUNC"    , '·' , '·' ,  "dfuncs"   , "calls to debugging functions"    , '·' , '·' , ""                , "" },
   { 'Ï' , "RFUNC"    , '·' , '·' ,  "rfuncs"   , "calls to real/non-debug"         , '·' , '·' , ""                , "" },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "FFUNC"    , '·' , '·' ,  "ffuncs"   , "calls to in-file functions"      , '·' , '·' , ""                , "" },
   { 'Ï' , "GFUNC"    , '·' , '·' ,  "gfuncs"   , "calls to global functions"       , '·' , '·' , ""                , "" },
   { 'Ï' , "CSTD"     , '·' , '·' ,  "cstd"     , "calls to c-std libraries"        , '·' , '·' , ""                , "" },
   { 'Ï' , "YLIB"     , '·' , '·' ,  "ylib"     , "calls to my custom libraries"    , '·' , '·' , ""                , "" },
   { 'Ï' , "VIKEYS"   , '·' , '·' ,  "vikeys"   , "calls to vi-keys libraries"      , '·' , '·' , ""                , "" },
   { 'Ï' , "OFUNC"    , '·' , '·' ,  "ofuncs"   , "calls to other libraries"        , '·' , '·' , ""                , "" },
   { 'Ï' , "MYSTRY"   , '·' , '·' ,  "mystry"   , "calls to unknown functions"      , '·' , '·' , ""                , "" },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "INPUT"    , '·' , '·' ,  "input"    , "stdin and file input"            , '·' , '·' , ""                , "" },
   { 'Ï' , "OUTPUT"   , '·' , '·' ,  "output"   , "stdout and file output"          , '·' , '·' , ""                , "" },
   { 'Ï' , "SYSTEM"   , '·' , '·' ,  "system"   , "unix process or system calls"    , '·' , '·' , ""                , "" },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "MSGS"     , '·' , '·' ,  "umsgs"    , "yURG_msg messages"               , '·' , '·' , ""                , "" },
   { 'Ï' , "ERRS"     , '·' , '·' ,  "uerrs"    , "yURG_err messages"               , '·' , '·' , ""                , "" },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "NCURSE"   , '·' , '·' ,  "ncurse"   , "ncurses function calls"          , '·' , '·' , ""                , "" },
   { 'Ï' , "OPENGL"   , '·' , '·' ,  "opengl"   , "opengl function calls"           , '·' , '·' , ""                , "" },
   { 'Ï' , "WINDOW"   , '·' , '·' ,  "window"   , "x11 and like functions calls"    , '·' , '·' , ""                , "" },
   { 'Ï' , "YGRAPH"   , '·' , '·' ,  "ygraph"   , "my x11/opengl support libs"      , '·' , '·' , ""                , "" },
   { 'Ï' , "   "      , ' ' ,  3  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },

   /*===[[ WATCH-POINTS ]]=== print======= description========================= style check valid============== legend====== ============ ============ ============ ============ ============ ============   */
   { 'Ï' , "WAá "     , ' ' ,  0  , "WATCH-POINTS"                       , ""       , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { '>' , "DCOUNT"   , '·' , '·' ,  "dcount"   , "debugging total lines"           , '·' , '·' , ""                , "" },
   { 'Ï' , "DACTIV"   , '·' , '·' ,  "dactiv"   , "debugging is used"               , '·' , '·' , ""                , "" },
   { 'Ï' , "DSTYLE"   , '·' , '·' ,  "dstyle"   , "debugging style"                 , '·' , '·' , ""                , "" },
   { 'Ï' , "DMACRO"   , '·' , '·' ,  "dmacro"   , "debugging macros used"           , '·' , '·' , ""                , "" },
   { 'Ï' , "DMATCH"   , '·' , '·' ,  "dmatch"   , "debugging enter/exit match"      , '·' , '·' , ""                , "" },
   { '>' , "DEXTRA"   , '·' , '·' ,  "dextra"   , "debugging lines with prefixes"   , '·' , '·' , ""                , "" },
   { 'Ï' , "DWARN"    , '·' , '·' ,  "dwarn"    , "debugging trouble marker"        , '·' , '·' , ""                , "" },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "MACROS"   , '·' , '·' ,  "macros"   , "potential #define macros"        , '·' , '·' , ""                , "" },
   { 'Ï' , "MFILE"    , '·' , '·' ,  "mfile"    , "in-file #define macro use"       , '·' , '·' , ""                , "" },
   { 'Ï' , "MPROJ"    , '·' , '·' ,  "mproj"    , "global #define macro use"        , '·' , '·' , ""                , "" },
   { 'Ï' , "MCSTD"    , '·' , '·' ,  "mcstd"    , "cstd #define macro use"          , '·' , '·' , ""                , "" },
   { 'Ï' , "MYLIB"    , '·' , '·' ,  "mylib"    , "ylib #define macro use"          , '·' , '·' , ""                , "" },
   { 'Ï' , "MVIKEY"   , '·' , '·' ,  "mvikey"   , "vikeys #define macro use"        , '·' , '·' , ""                , "" },
   { 'Ï' , "MOTHER"   , '·' , '·' ,  "mother"   , "unknown/other macros"            , '·' , '·' , ""                , "" },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "VMASK"    , '·' , '·' ,  "vmask"    , "vars masking other vars"         , '·' , '·' , ""                , "" },
   { 'Ï' , "MMASK"    , '·' , '·' ,  "mmask"    , "macros masking other macros"     , '·' , '·' , ""                , "" },
   { 'Ï' , "FMASK"    , '·' , '·' ,  "fmask"    , "funcs masking other funcs"       , '·' , '·' , ""                , "" },
   { 'Ï' , "LSTAT"    , '·' , '·' ,  "lstat"    , "local static variables"          , '·' , '·' , ""                , "" },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                                    },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "UNITS"    , '·' , '·' ,  "units"    , "count of unit tests used"        , '·' , '·' , ""                , "" },
   { 'Ï' , "SCRPS"    , '·' , '·' ,  "scrps"    , "count of unit scripts used"      , '·' , '·' , ""                , "" },
   { 'Ï' , "STEPS"    , '·' , '·' ,  "steps"    , "count of unit steps used"        , '·' , '·' , ""                , "" },
   { 'Ï' , "STRING"   , '·' , '·' ,  "string"   , "count of string tests"           , '·' , '·' , ""                , "" },

   /*===[[ END-OF_LIST ]]==== print======= description========================= style check valid============== legend====== ============ ============ ============ ============ ============ ============   */
   { 'Ï' , "end-list" , '·' , '·' , ""         , "end-of-entries"                   , '·' , '·' , ""                , ""                                                                                                    },
};



const tySCORE_TB mySCORE_audit_good  [LEN_FULL] = {
   /*===[[ NAME ]]=========== print======= description========================= style check valid============== legend====== ============ ============ ============ ============ ============ ============   */
   { 'Ï' , "NMá "     , ' ' ,  0  , "NAME"                             , ""         , '·' , '·' , ""         ,       ""                                                                                },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "NCONF"    , '·' , 'c' , "conf"     , "naming²standard²applied"          , '·' , '·' , "·°-nslc"         , "°) illegal   -) wild      n) normal    s) standard  l) local     c) central"     }, 
   { 'Ï' , "NDIR"     , '·' , 'd' , "dir"      , "directory²requested"              , '·' , '·' , "·°£/D"           , "°) null      £) empty     /) pathless  D) passed"                                },
   { 'Ï' , "NFILE"    , '·' , 'f' , "file"     , "file²name²requested"              , '·' , '·' , "·°£/F-"          , "°) null      £) empty     /) pathed    F) passed    -) skipped"                  },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "NFULL"    , '·' , 'n' , "full"     , "name²quality²checking"            , '·' , '·' , "·°/´¢n"          , "°) null      /) not abs   ´) hidden    ¢) bad char  n) passed"                   },
   { 'Ï' , "NSTYLE"   , '·' , 'b' , "style"    , "naming²style"                     , '·' , '·' , "·dfb"            , "d) dir       f) file      b) both"                                               },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "NDOTS"    , '·' , 'n' , "ndots"    , "file²name²separators"             , '·' , '·' , "·°<>n"           , "·) skipped   °) none      <) too few   >) too many  n) passed"                   },
   { 'Ï' , "NPREFIX"  , '·' , 'p' , "prefix"   , "required²prefix"                  , '·' , '·' , "·°up"            , "·) skipped   °) failed    u) user      p) passed"                                },
   { 'Ï' , "NSUFFIX"  , '·' , 's' , "suffix"   , "required²suffix"                  , '·' , '·' , "·°s"             , "·) skipped   °) failed    s) passed"                                             },
   { 'Ï' , "NDESC"    , '·' , 'd' , "desc"     , "remaining²description"            , '·' , '·' , "·°d"             , "·) skipped   °) failed    d) passed"                                             },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "NLOC"     , '·' , 'h' , "loc"      , "file²location²type"               , '·' , '·' , "·°rhes"          , "·) skipped   °) failed    r) root      h) home      e) etc       s) spool"       },
   { 'Ï' , "NUSE"     , '·' , 'H' , "usable"   , "file²location²usable"             , '·' , '·' , "·°RHES"          , "·) skipped   °) failed    R) root      H) home      E) etc       S) spool"       },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "NAME"     , '-' , '´' , "ŒŒŒŒŒŒ"   , "[[²name²judgement²]]"             , '·' , '·' , "-°´"             , "-) unknown   °) failed    ´) passed"                                             },
   { 'Ï' , "   "      , ' ' ,  3  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                },

   /*===[[ END-OF_LIST ]]==== print======= description========================= style check valid============== legend====== ============ ============ ============ ============ ============ ============   */
   { 'Ï' , "end-list" , '·' , '·' , ""         , "end-of-entries"                   , '·' , '·' , ""                , ""                                                                                                    },
};

const tySCORE_TB mySCORE_audit_issues [LEN_FULL] = {
   /*===[[ NAME ]]=========== print======= description========================= style check valid============== legend====== ============ ============ ============ ============ ============ ============   */
   { 'Ï' , "NMá"      , ' ' ,  0  , "NAME"                             , ""         , '·' , '·' , ""         ,       ""                                                                                },
   /*--label----- def-- samp- print------- description------------------------- style check valid-------------- legend------ ------------ ------------ ------------ ------------ ------------ ------------   */
   { 'Ï' , "N_CONF"   , '·' , 'c' , "conf"     , "naming²standard²applied"          , '·' , '·' , "·°-nslc"         , "°) illegal   -) wild      n) normal    s) standard  l) local     c) central"     }, 
   { 'Ï' , "ndir"     , '·' , 'd' , "dir"      , "directory²requested"              , '·' , '·' , "·°£/D"           , "°) null      £) empty     /) pathless  D) passed"                                },
   { 'Ï' , ""         , '·' , 'f' , "file"     , "file²name²requested"              , '·' , '·' , "·°£/F-"          , "°) null      £) empty     /) pathed    F) passed    -) skipped"                  },
   { 'Ï' , " "        , ' ' ,  1  , ""         , ""                                 , '·' , '·' , ""                , ""                                                                                },

   /*===[[ END-OF_LIST ]]==== print======= description========================= style check valid============== legend====== ============ ============ ============ ============ ============ ============   */
   { 'Ï' , "end-list" , '·' , '·' , ""         , "end-of-entries"                   , '·' , '·' , ""                , ""                                                                                                    },
};

