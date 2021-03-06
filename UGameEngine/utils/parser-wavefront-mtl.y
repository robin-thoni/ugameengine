%{
#include <QVariant>
#include <QDebug>
#include "utils/vector3d.h"
#include "utils/wavefrontobj.h"
#include "lexer-wavefront-mtl.h"



// yylex is a function generated by Flex and we must tell to Bison that it is
// defined in other place.
extern int wavefront_mtllex(void);

// Bison uses the yyerror function for informing us when a parsing error has
// occurred.
void wavefront_mtlerror(WaveFrontObj* data, const char *s);
%}

%define api.prefix {wavefront_mtl}
%define api.token.prefix {TOK_WFMTL_}

%parse-param {struct WaveFrontObj* wavefrontData}

// Here we define our custom variable types.
// Custom types must be of fixed size.
%union {
    double number;
    int integer;
    char* string;
    Vector3D* vector3d;
    QList<int>* integers;
    WaveFrontObjFaceVertex faceVertex;
    QList<WaveFrontObjFaceVertex>* face;
}

// Define the terminal expression types.
%token <number> NUMBER
%token <string> STRING
%token SLASH
%token MTLLIB
%token USEMTL
%token O
%token V
%token VT
%token VN
%token VP
%token F
%token S

%destructor { free($$); } <string>
%destructor { delete $$; } <vector3d>
%destructor { delete $$; } <integers>
%destructor { delete $$; } <face>

// Define the non-terminal expression types.
%type <vector3d> vertex
%type <faceVertex>   face_vertex
%type <face>  face_vertex_list
%type <face>  face


%%

wavefront_mtl: stmt_list {};


stmt_list: {}
            | stmt_list stmt {};

stmt: mtllib {}
            | usemtl {}
            | named_object {}
            | vertex { wavefrontData->addVertex(*$1); delete $1; }
            | texture_coordinate {}
            | vertex_normal {}
            | vertex_space {}
            | face { wavefrontData->addFace(*$1); delete $1; }
            | smooth {};

mtllib: MTLLIB STRING { free($2); };

usemtl: USEMTL STRING { free($2); };

named_object: O STRING { free($2); };

vertex: V NUMBER NUMBER NUMBER { $$ = new Vector3D($2, $3, $4); }
            | V NUMBER NUMBER NUMBER NUMBER { $$ = new Vector3D($2, $3, $4); };

texture_coordinate: VT NUMBER NUMBER {}
            | VT NUMBER NUMBER NUMBER {};

vertex_normal: VN NUMBER NUMBER NUMBER {};

vertex_space: VP NUMBER NUMBER NUMBER {};

face: F face_vertex_list { $$ = $2; };

face_vertex_list: { $$ = new QList<WaveFrontObjFaceVertex>(); }
            | face_vertex_list face_vertex { $1->append($2); $$ = $1;};

face_vertex: NUMBER { $$.vertexPosition = $1; }
            | NUMBER SLASH NUMBER { $$.vertexPosition = $1; $$.textureCoordPosition = $3; }
            | NUMBER SLASH NUMBER SLASH NUMBER { $$.vertexPosition = $1; $$.textureCoordPosition = $3; }
            | NUMBER SLASH SLASH NUMBER { $$.vertexPosition = $1; };

smooth: S NUMBER {}
            | S STRING { free($2); };

%%

void wavefront_mtlerror(WaveFrontObj* data, const char *s)
{
    data->setError("Parse error: " + QString(s) + " at line " + QString::number(wavefront_mtllineno) + " at " + QString(wavefront_mtltext));
}
