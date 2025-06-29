


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



const tSCORE_TABLE mySCORE_test [LEN_FULL] = {

   /*===[[ NAME ]]==========================================================*/
   { "NM� "     , ' ' ,  0  , "NAME"                             , ""         , ""         , ""                                                                                },
   /*===[[ REQUEST TYPE ]]==================================================*/
   { "NCONF"    , '�' , 'c' , "conf"     , "naming�standard�applied"          , "��-nslc"   , "�) illegal   -) wild      n) normal    s) standard  l) local     c) central"     }, 
   { "NDIR"     , '�' , 'd' , "dir"      , "directory�requested"              , "���/D"     , "�) null      �) empty     /) pathless  D) passed"                                },
   { "NFILE"    , '�' , 'f' , "file"     , "file�name�requested"              , "���/F-"    , "�) null      �) empty     /) pathed    F) passed    -) skipped"                  },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ NAMING ]]========================================================*/
   { "NFULL"    , '�' , 'n' , "full"     , "name�quality�checking"            , "��/��n"    , "�) null      /) not abs   �) hidden    �) bad char  n) passed"                   },
   { "NSTYLE"   , '�' , 'b' , "style"    , "naming�style"                     , "�dfb"      , "d) dir       f) file      b) both"                                               },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ STANDARDS ]]=====================================================*/
   { "NDOTS"    , '�' , 'n' , "ndots"    , "file�name�separators"             , "��<>n"     , "�) skipped   �) none      <) too few   >) too many  n) passed"                   },
   { "NPREFIX"  , '�' , 'p' , "prefix"   , "required�prefix"                  , "��up"      , "�) skipped   �) failed    u) user      p) passed"                                },
   { "NSUFFIX"  , '�' , 's' , "suffix"   , "required�suffix"                  , "��s"       , "�) skipped   �) failed    s) passed"                                             },
   { "NDESC"    , '�' , 'd' , "desc"     , "remaining�description"            , "��d"       , "�) skipped   �) failed    d) passed"                                             },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ LOCATION ]]======================================================*/
   { "NLOC"     , '�' , 'h' , "loc"      , "file�location�type"               , "��rhes"    , "�) skipped   �) failed    r) root      h) home      e) etc       s) spool"       },
   { "NUSE"     , '�' , 'H' , "usable"   , "file�location�usable"             , "��RHES"    , "�) skipped   �) failed    R) root      H) home      E) etc       S) spool"       },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ REQUEST ]]=======================================================*/
   { "NAME"     , '-' , '�' , "������"   , "[[�name�judgement�]]"             , "-��"       , "-) unknown   �) failed    �) passed"                                             },
   { "   "      , ' ' ,  3  , ""         , ""                                 , ""          , ""                                                                                },

   /*===[[ REQUEST ]]=======================================================*/
   { "EX� "     , ' ' ,  0  , "EXPECT"                           , ""         , ""          , ""                                                                                },
   /*===[[ REQUEST TYPE ]]==================================================*/
   { "ETYPE"    , '�' , 'r' , "type"     , "expected file type"               , "�drshcbpi?", "d) dir   r) reg   s) sym   h) hard  c) char  b) block p) pipe  i) ipsoc ?) WTF"  },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ REQUEST CHARS ]]=================================================*/
   { "EOWNER"   , '�' , 'o' , "owner"    , "expected owner"                   , "�o�o-"     , "o) standard   �) numeric    O) default    -) skipped"                            },
   { "EGROUP"   , '�' , 'g' , "group"    , "expected group"                   , "�g�G-"     , "g) standard   �) numeric    G) default    -) skipped"                            },
   { "EPERMS"   , '�' , 'p' , "perms"    , "expected permissions"             , "�p�P-"     , "p) standard   �) non-std    P) default    -) skipped"                            },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ REQUEST DEVICE ]]================================================*/
   { "EMAJOR"   , '�' , 'j' , "major"    , "expected owner"                   , "�j-"       , "j) in-range   -) skipped"                                                        },
   { "EMINOR"   , '�' , 'n' , "minor"    , "expected group"                   , "�n-"       , "n) in-range   -) skipped"                                                        },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ REQUEST LINK ]]==================================================*/
   { "ETTYPE"   , '�' , 'r' , "ttype"    , "expected link target type"        , "�drshcbpi?", "d) dir   r) reg   s) sym   h) hard  c) char  b) block p) pipe  i) ipsoc ?) WTF"  },
   { "ETARGET"  , '�' , 't' , "target"   , "expected link target"             , "�/#t-"     , "/) not-abs    #) bad chars  t) accepted   -) skipped"                            },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ REQUEST EXTENDED ]]==============================================*/
   { "EEPOCH"   , '�' , 'e' , "epoch"    , "expected update time"             , "�e-"       , "e) accepted   -) skipped"                                                        },
   { "EBYTES"   , '�' , 'b' , "bytes"    , "expected size in bytes"           , "�b-"       , "b) accepted   -) skipped"                                                        },
   { "EINODE"   , '�' , 'i' , "inode"    , "expected inode"                   , "�i-"       , "i) accepted   -) skipped"                                                        },
   { "EHASH"    , '�' , 'h' , "hash"     , "expected file SHA hash"           , "�h-"       , "h) accepted   -) skipped"                                                        },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ REQUEST ]]=======================================================*/
   { "EXPECT"   , '-' , '�' , "������"   , "judgement on request"             , "-��"       , "�) passed"                                                                       },
   { "   "      , ' ' ,  3  , ""         , ""                                 , ""          , ""                                                                                },

   /*===[[ FINAL ]]=========================================================*/
   { "JD� "     , ' ' ,  0  , "�"                                , ""         , ""          , ""                                                                                },
   /*===[[ FINAL JUDGE ]]===================================================*/
   { "FINAL"    , '�' , '�' , "FINAL"    , "final judgement"                  , "���"       , "�) passed"                                                                       },

   /*===[[ END-OF-LIST ]]===================================================*/
   { "end-list" , '�' , '�' , ""         , "end-of-entries"                   , ""          , ""                                                                                },
};



const tSCORE_TABLE mySCORE_poly [LEN_FULL] = {

   /*===[[ GROUP ONE -- COMPLEXITY ]]============================*/
   { "CO� "     , ' ' ,  0  , "COMPLEXITY"                         , ""       , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   -valid-----   -legend----------------------------------------------------------------------------------------------- */
   { "ONE"      , '�' , '-' , "one"      , "one�line�function"                , "�y"        , "y)yes      �)normal"                                                                                 },
   { "SCOPE"    , '�' , 'g' , "scope"    , "function�scope"                   , "��egfsu"   , "e)extern   g)global   f)file     s)static   u)unit"                                                  },
   { "RTYPE"    , '�' , 'c' , "rtype"    , "function�return�type"             , "��scvpno_" , "s)string   c)char     v)void     p)point    n)number   o)other    _)title"                           },
   { "PROTO"    , '�' , 'g' , "proto"    , "prototype�location"               , "��gf-"     , "g)global   f)file     -)none"                                                                        },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "PAUDIT"   , '�' , 'y' , "paudit"   , "audit�of�parameters"              , "�"         , "tbd"                                                                                                 },
   { "PARAMS"   , '�' , 'A' , "params"   , "number�of�parameters"             , "��?0-9#"   , "?)WTF      0)void     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "PIN"      , '�' , '4' , "pin"      , "param�incomming���(a)"            , "��?0-9#"   , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { "POUT"     , '�' , '3' , "pout"     , "param�outgoing����(r)"            , "��?0-9#"   , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { "PBOTH"    , '�' , '2' , "pboth"    , "param�both�in/out�(b)"            , "��?0-9#"   , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { "PCONF"    , '�' , '1' , "pconf"    , "param�for�config��(c)"            , "��?0-9#"   , "?)WTF      0)none     1-3)ok     4+)high"                                                            },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "PNUM"     , '�' , '2' , "pnum"     , "param�number�pointers"            , "��?0-9#"   , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { "PMULTI"   , '�' , '3' , "pmulti"   , "param�multiple�pointers"          , "��?0-9#"   , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { "PFUNC"    , '�' , '4' , "pfunc"    , "param�function�pointers"          , "��?0-9#"   , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "PSTRUC"   , '�' , '1' , "pstruc"   , "param�struct�pointers"            , "��?0-9#"   , "?)WTF      0)none     1-3)low    4-6)mid    7-9)high   #)huge"                                       },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "TOTAL"    , '�' , '9' , "total"    , "total�actual�lines"               , "��0-9A-Z#" , "1-4)small  5-9)mod    A-D)full   E-H)large  I-N)huge   O-Z)SCARY  #)JESUS"                           },
   { "DEBUG"    , '�' , '3' , "debug"    , "pct�debugging�lines"              , "��0-9A"    , "0-1)tiny   2-4)avg    5-7)high   A)warning"                                                          },
   { "CODE"     , '�' , '6' , "code"     , "pct�code�lines"                   , "��0-9A"    , "1-3)low    4-7)avg    8-9)high   A)warning"                                                          },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "LVARS"    , '�' , '1' , "lvars"    , "num�local�vars�used"              , "��0-9A-Z#" , "0)none     1-3)few    4-6)avg    7-9)heavy  A-Z)SCARY  #)JESUS"                                      },
   { "FVARS"    , '�' , '2' , "fvars"    , "num�file�vars�used"               , "��0-9A-Z#" , "0)none     1-3)few    4-6)avg    7-9)heavy  A-Z)SCARY  #)JESUS"                                      },
   { "GVARS"    , '�' , '3' , "gvars"    , "num�global�vars�used"             , "��0-9A-Z#" , "0)none     1-2)avg    3-6)lots   7-9)heavy  A-Z)SCARY  #)JESUS"                                      },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "INDENT"   , '�' , '1' , "indent"   , "depth�of�indentation"             , "��0-9A-Z#" , "0)none     1)avg      2-4)lots   5+)SCARY"                                                           },
   { "LOOP"     , '�' , '2' , "loop"     , "num�looping�statements"           , "��0-9A-Z#" , "0)none     1)avg      2-4)lots   5+)SCARY"                                                           },
   { "CHOICE"   , '�' , '3' , "choice"   , "num�choices/decisions"            , "��0-9A-Z#" , "0)none     1-3)avg    4-9)lots   A-Z)SCARY  #)JESUS"                                                 },
   { "RETURN"   , '�' , '4' , "return"   , "num�normal�returns"               , "��0-9A-Z#" , "0)WTF      1)perfect  2-5)avg    6+)SCARY"                                                           },
   { "RERROR"   , '�' , '5' , "rerror"   , "num�return�with�errors"           , "��0-9A-Z#" , "0)none     1-3)avg    4-6)logs   9+)major"                                                           },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "MEMORY"   , '�' , 'y' , "memory"   , "memory�management�used"           , "��-#"      , "-)none     #)in-use"                                                                                 },
   { "   "      , ' ' ,  3  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */

   /*===[[ GROUP TWO -- INTEGRATION ]]===========================*/
   { "IN� "     , ' ' ,  0  , "INTEGRATION"                        , ""       , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "CALLED"   , '�' , '�' ,  "called"   , "called by anything else"         , ""          , "" },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "FCALL"    , '�' , '�' ,  "fcall"    , "called by in-file functions"     , ""          , "" },
   { "GCALL"    , '�' , '�' ,  "gcall"    , "called by global functions"      , ""          , "" },
   { "XCALL"    , '�' , '�' ,  "xcall"    , "called by external programs"     , ""          , "" },
   { "REURS"    , '�' , '�' ,  "recurs"   , "function is recursive"           , ""          , "" },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "CALLTO"   , '�' , '�' ,  "callto"   , "calls to any/all functions"      , ""          , "" },
   { "DFUNC"    , '�' , '�' ,  "dfuncs"   , "calls to debugging functions"    , ""          , "" },
   { "RFUNC"    , '�' , '�' ,  "rfuncs"   , "calls to real/non-debug"         , ""          , "" },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "FFUNC"    , '�' , '�' ,  "ffuncs"   , "calls to in-file functions"      , ""          , "" },
   { "GFUNC"    , '�' , '�' ,  "gfuncs"   , "calls to global functions"       , ""          , "" },
   { "CSTD"     , '�' , '�' ,  "cstd"     , "calls to c-std libraries"        , ""          , "" },
   { "YLIB"     , '�' , '�' ,  "ylib"     , "calls to my custom libraries"    , ""          , "" },
   { "VIKEYS"   , '�' , '�' ,  "vikeys"   , "calls to vi-keys libraries"      , ""          , "" },
   { "OFUNC"    , '�' , '�' ,  "ofuncs"   , "calls to other libraries"        , ""          , "" },
   { "MYSTRY"   , '�' , '�' ,  "mystry"   , "calls to unknown functions"      , ""          , "" },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "INPUT"    , '�' , '�' ,  "input"    , "stdin and file input"            , ""          , "" },
   { "OUTPUT"   , '�' , '�' ,  "output"   , "stdout and file output"          , ""          , "" },
   { "SYSTEM"   , '�' , '�' ,  "system"   , "unix process or system calls"    , ""          , "" },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "MSGS"     , '�' , '�' ,  "umsgs"    , "yURG_msg messages"               , ""          , "" },
   { "ERRS"     , '�' , '�' ,  "uerrs"    , "yURG_err messages"               , ""          , "" },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "NCURSE"   , '�' , '�' ,  "ncurse"   , "ncurses function calls"          , ""          , "" },
   { "OPENGL"   , '�' , '�' ,  "opengl"   , "opengl function calls"           , ""          , "" },
   { "WINDOW"   , '�' , '�' ,  "window"   , "x11 and like functions calls"    , ""          , "" },
   { "YGRAPH"   , '�' , '�' ,  "ygraph"   , "my x11/opengl support libs"      , ""          , "" },
   { "   "      , ' ' ,  3  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */

   /*===[[ GROUP THREE -- WATCH POINTS ]]========================*/
   { "WA� "     , ' ' ,  0  , "WATCH-POINTS"                       , ""       , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "DACTIV"   , '�' , '�' ,  "dactiv"   , "debugging is used"               , ""          , "" },
   { "DSTYLE"   , '�' , '�' ,  "dstyle"   , "debugging style"                 , ""          , "" },
   { "DMACRO"   , '�' , '�' ,  "dmacro"   , "debugging macros used"           , ""          , "" },
   { "DMATCH"   , '�' , '�' ,  "dmatch"   , "debugging enter/exit match"      , ""          , "" },
   { "DWARN"    , '�' , '�' ,  "dwarn"    , "debugging trouble marker"        , ""          , "" },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "MACROS"   , '�' , '�' ,  "macros"   , "potential #define macros"        , ""          , "" },
   { "MFILE"    , '�' , '�' ,  "mfile"    , "in-file #define macro use"       , ""          , "" },
   { "MPROJ"    , '�' , '�' ,  "mproj"    , "global #define macro use"        , ""          , "" },
   { "MCSTD"    , '�' , '�' ,  "mcstd"    , "cstd #define macro use"          , ""          , "" },
   { "MYLIB"    , '�' , '�' ,  "mylib"    , "ylib #define macro use"          , ""          , "" },
   { "MVIKEY"   , '�' , '�' ,  "mvikey"   , "vikeys #define macro use"        , ""          , "" },
   { "MOTHER"   , '�' , '�' ,  "mother"   , "unknown/other macros"            , ""          , "" },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "VMASK"    , '�' , '�' ,  "vmask"    , "vars masking other vars"         , ""          , "" },
   { "MMASK"    , '�' , '�' ,  "mmask"    , "macros masking other macros"     , ""          , "" },
   { "FMASK"    , '�' , '�' ,  "fmask"    , "funcs masking other funcs"       , ""          , "" },
   { "LSTAT"    , '�' , '�' ,  "lstat"    , "local static variables"          , ""          , "" },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                                    },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */
   { "UNITS"    , '�' , '�' ,  "units"    , "count of unit tests used"        , ""          , "" },
   { "SCRPS"    , '�' , '�' ,  "scrps"    , "count of unit scripts used"      , ""          , "" },
   { "STEPS"    , '�' , '�' ,  "steps"    , "count of unit steps used"        , ""          , "" },
   { "STRING"   , '�' , '�' ,  "string"   , "count of string tests"           , ""          , "" },
   /*-label----   def   sam   -print----   -description----------------------   stat   -legend----------------------------------------------------------------------------------------------- */

   /*===[[ END-OF-LIST ]]===================================================*/
   { "end-list" , '�' , '�' , ""         , "end-of-entries"                   , ""          , ""                                                                                                    },

   /*===[[ DONE ]]==========================================================*/
};



const tSCORE_TABLE mySCORE_audit_good  [LEN_FULL] = {

   /*===[[ NAME ]]==========================================================*/
   { "NM� "     , ' ' ,  0  , "NAME"                             , ""         , ""         , ""                                                                                },
   /*===[[ REQUEST TYPE ]]==================================================*/
   { "NCONF"    , '�' , 'c' , "conf"     , "naming�standard�applied"          , "��-nslc"   , "�) illegal   -) wild      n) normal    s) standard  l) local     c) central"     }, 
   { "NDIR"     , '�' , 'd' , "dir"      , "directory�requested"              , "���/D"     , "�) null      �) empty     /) pathless  D) passed"                                },
   { "NFILE"    , '�' , 'f' , "file"     , "file�name�requested"              , "���/F-"    , "�) null      �) empty     /) pathed    F) passed    -) skipped"                  },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ NAMING ]]========================================================*/
   { "NFULL"    , '�' , 'n' , "full"     , "name�quality�checking"            , "��/��n"    , "�) null      /) not abs   �) hidden    �) bad char  n) passed"                   },
   { "NSTYLE"   , '�' , 'b' , "style"    , "naming�style"                     , "�dfb"      , "d) dir       f) file      b) both"                                               },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ STANDARDS ]]=====================================================*/
   { "NDOTS"    , '�' , 'n' , "ndots"    , "file�name�separators"             , "��<>n"     , "�) skipped   �) none      <) too few   >) too many  n) passed"                   },
   { "NPREFIX"  , '�' , 'p' , "prefix"   , "required�prefix"                  , "��up"      , "�) skipped   �) failed    u) user      p) passed"                                },
   { "NSUFFIX"  , '�' , 's' , "suffix"   , "required�suffix"                  , "��s"       , "�) skipped   �) failed    s) passed"                                             },
   { "NDESC"    , '�' , 'd' , "desc"     , "remaining�description"            , "��d"       , "�) skipped   �) failed    d) passed"                                             },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ LOCATION ]]======================================================*/
   { "NLOC"     , '�' , 'h' , "loc"      , "file�location�type"               , "��rhes"    , "�) skipped   �) failed    r) root      h) home      e) etc       s) spool"       },
   { "NUSE"     , '�' , 'H' , "usable"   , "file�location�usable"             , "��RHES"    , "�) skipped   �) failed    R) root      H) home      E) etc       S) spool"       },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },
   /*===[[ REQUEST ]]=======================================================*/
   { "NAME"     , '-' , '�' , "������"   , "[[�name�judgement�]]"             , "-��"       , "-) unknown   �) failed    �) passed"                                             },
   { "   "      , ' ' ,  3  , ""         , ""                                 , ""          , ""                                                                                },

   /*===[[ END-OF-LIST ]]===================================================*/
   { "end-list" , '�' , '�' , ""         , "end-of-entries"                   , ""          , ""                                                                                                    },

   /*===[[ DONE ]]==========================================================*/
};

const tSCORE_TABLE mySCORE_audit_issues [LEN_FULL] = {

   /*===[[ NAME ]]==========================================================*/
   { "NM�"      , ' ' ,  0  , "NAME"                             , ""         , ""         , ""                                                                                },
   /*===[[ REQUEST TYPE ]]==================================================*/
   { "N_CONF"   , '�' , 'c' , "conf"     , "naming�standard�applied"          , "��-nslc"   , "�) illegal   -) wild      n) normal    s) standard  l) local     c) central"     }, 
   { "ndir"     , '�' , 'd' , "dir"      , "directory�requested"              , "���/D"     , "�) null      �) empty     /) pathless  D) passed"                                },
   { ""         , '�' , 'f' , "file"     , "file�name�requested"              , "���/F-"    , "�) null      �) empty     /) pathed    F) passed    -) skipped"                  },
   { " "        , ' ' ,  1  , ""         , ""                                 , ""          , ""                                                                                },

   /*===[[ END-OF-LIST ]]===================================================*/
   { "end-list" , '�' , '�' , ""         , "end-of-entries"                   , ""          , ""                                                                                                    },

   /*===[[ DONE ]]==========================================================*/
};


