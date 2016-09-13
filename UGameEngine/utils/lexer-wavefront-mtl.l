%{
// In this section we can add all needed headers, from Qt or another libraries.
//#include <QtScript>
#include <QVariant>
#include <QDebug>

// Also, we must add the parser's header where are defined the tokens.
#include "utils/vector3d.h"
#include "utils/wavefrontobj.h"
#include "parser-wavefront-mtl.h"

#define TOKEN(type) \
  TOK_WFMTL_##type

%}

%option noyywrap
%option nounput
%option prefix="wavefront_mtl"

%%

 /* Whitespace */
[ \t]+       {                           }

 /* Newline */
\n|\n\r      { ++wavefront_mtllineno;    }

 /* Comment */
"#"[^\n\r]*  {                        }

 /* Material library */
"mtllib"     { return TOKEN(MTLLIB);  }

 /* Use material */
"usemtl"     { return TOKEN(USEMTL);  }

 /* Named object */
"o"     { return TOKEN(O);  }

 /* Vertex */
"v"     { return TOKEN(V);  }

 /* Texture coordinate */
"vt"     { return TOKEN(VT);  }

 /* Vertex normal */
"vn"     { return TOKEN(VN);  }

 /* Parameter space vertices */
"vp"     { return TOKEN(VP);  }

 /* Face */
"f"     { return TOKEN(F);  }

 /* Smooth */
"s"     { return TOKEN(S);  }

 /* Slash */
"/"     { return TOKEN(SLASH);  }

 /* Number */
-?[0-9]+(.[0-9]+)?     { wavefront_mtllval.number=atof(yytext); return TOKEN(NUMBER); }

 /* String */
[^\n\r\t ]+  { wavefront_mtllval.string = strcpy((char*)malloc(strlen(yytext) + 1), yytext); return TOKEN(STRING);  }


%%
