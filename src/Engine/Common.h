#pragma once

#include <iostream>
/*
#include <list>
#include <vector>
#include <map>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
*/
//#include <windows.h>
/*#include <gl\glew.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include "GL\glfw.h"
*/


#include <fstream>
#include <sstream>
#include <cerrno>

//#include <GLFW/glfw3.h>


//#pragma warning(push, 0)
#include <entityx/entityx.h>
#include <entityx/deps/Dependencies.h>
//#pragma warning(pop)


//#define internal static
#define local_persist static
#define global_variable static

#define Pi32 3.141519265359f

#define GRAVITY -9.81f
#define BUFFER_OFFSET(i) ((char *)NULL + (i))

using std::cerr;
using std::cout;
using std::endl;

namespace ex = entityx;

typedef std::string String;

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef int32 bool32;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef size_t memory_index;

typedef float real32;
typedef double real64;
