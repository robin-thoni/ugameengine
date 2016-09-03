%{
// In this section we can add all needed headers, from Qt or another libraries.
//#include <QtScript>
#include <QVariant>
#include <QDebug>

// Also, we must add the parser's header where are defined the tokens.
#include "utils/vector3d.h"
#include "parser-wavefront-obj.h"

#define TOKEN(type) \
  TOK_##type

%}

%option noyywrap
%option prefix="wavefront_obj"

%%

 /* Whitespace */
[ \t]+       {                           }

 /* Newline */
\n|\n\r      { ++wavefront_objlineno;    }

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
-?[0-9]+(.[0-9]+)?     { wavefront_objlval.number=atof(yytext); return TOKEN(NUMBER); }

 /* String */
[^\n\r\t ]+  { wavefront_objlval.string = strcpy((char*)malloc(strlen(yytext)), yytext); return TOKEN(STRING);  }


%%
