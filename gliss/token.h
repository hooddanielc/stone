#pragma once

#include <ostream>
#include <string>
#include <utility>
#include <map>
#include "glsl-lang.h"

namespace gliss {

using token_t = glsl::token_t;

using symbol_t = glsl::symbol_t;

inline static bool is_global_type(glsl::token_t::kind_t kind) {
  static const std::vector<glsl::token_t::kind_t> types = {
    glsl::token_t::VOID,
    glsl::token_t::FLOAT,
    glsl::token_t::DOUBLE,
    glsl::token_t::INT,
    glsl::token_t::UINT,
    glsl::token_t::BOOL,
    glsl::token_t::VEC2,
    glsl::token_t::VEC3,
    glsl::token_t::VEC4,
    glsl::token_t::DVEC2,
    glsl::token_t::DVEC3,
    glsl::token_t::DVEC4,
    glsl::token_t::BVEC2,
    glsl::token_t::BVEC3,
    glsl::token_t::BVEC4,
    glsl::token_t::IVEC2,
    glsl::token_t::IVEC3,
    glsl::token_t::IVEC4,
    glsl::token_t::UVEC2,
    glsl::token_t::UVEC3,
    glsl::token_t::UVEC4,
    glsl::token_t::MAT2,
    glsl::token_t::MAT3,
    glsl::token_t::MAT4,
    glsl::token_t::MAT2X2,
    glsl::token_t::MAT2X3,
    glsl::token_t::MAT2X4,
    glsl::token_t::MAT3X2,
    glsl::token_t::MAT3X3,
    glsl::token_t::MAT3X4,
    glsl::token_t::MAT4X2,
    glsl::token_t::MAT4X3,
    glsl::token_t::MAT4X4,
    glsl::token_t::DMAT2,
    glsl::token_t::DMAT3,
    glsl::token_t::DMAT4,
    glsl::token_t::DMAT2X2,
    glsl::token_t::DMAT2X3,
    glsl::token_t::DMAT2X4,
    glsl::token_t::DMAT3X2,
    glsl::token_t::DMAT3X3,
    glsl::token_t::DMAT3X4,
    glsl::token_t::DMAT4X2,
    glsl::token_t::DMAT4X3,
    glsl::token_t::DMAT4X4,
    glsl::token_t::ATOMIC_UINT,
    glsl::token_t::SAMPLER1D,
    glsl::token_t::SAMPLER2D,
    glsl::token_t::SAMPLER3D,
    glsl::token_t::SAMPLERCUBE,
    glsl::token_t::SAMPLER1DSHADOW,
    glsl::token_t::SAMPLER2DSHADOW,
    glsl::token_t::SAMPLERCUBESHADOW,
    glsl::token_t::SAMPLER1DARRAY,
    glsl::token_t::SAMPLER2DARRAY,
    glsl::token_t::SAMPLER1DARRAYSHADOW,
    glsl::token_t::SAMPLER2DARRAYSHADOW,
    glsl::token_t::SAMPLERCUBEARRAY,
    glsl::token_t::SAMPLERCUBEARRAYSHADOW,
    glsl::token_t::ISAMPLER1D,
    glsl::token_t::ISAMPLER2D,
    glsl::token_t::ISAMPLER3D,
    glsl::token_t::ISAMPLERCUBE,
    glsl::token_t::ISAMPLER1DARRAY,
    glsl::token_t::ISAMPLER2DARRAY,
    glsl::token_t::ISAMPLERCUBEARRAY,
    glsl::token_t::USAMPLER1D,
    glsl::token_t::USAMPLER2D,
    glsl::token_t::USAMPLER3D,
    glsl::token_t::USAMPLERCUBE,
    glsl::token_t::USAMPLER1DARRAY,
    glsl::token_t::USAMPLER2DARRAY,
    glsl::token_t::USAMPLERCUBEARRAY,
    glsl::token_t::SAMPLER2DRECT,
    glsl::token_t::SAMPLER2DRECTSHADOW,
    glsl::token_t::ISAMPLER2DRECT,
    glsl::token_t::USAMPLER2DRECT,
    glsl::token_t::SAMPLERBUFFER,
    glsl::token_t::ISAMPLERBUFFER,
    glsl::token_t::USAMPLERBUFFER,
    glsl::token_t::SAMPLER2DMS,
    glsl::token_t::ISAMPLER2DMS,
    glsl::token_t::USAMPLER2DMS,
    glsl::token_t::SAMPLER2DMSARRAY,
    glsl::token_t::ISAMPLER2DMSARRAY,
    glsl::token_t::USAMPLER2DMSARRAY,
    glsl::token_t::IMAGE1D,
    glsl::token_t::IIMAGE1D,
    glsl::token_t::UIMAGE1D,
    glsl::token_t::IMAGE2D,
    glsl::token_t::IIMAGE2D,
    glsl::token_t::UIMAGE2D,
    glsl::token_t::IMAGE3D,
    glsl::token_t::IIMAGE3D,
    glsl::token_t::UIMAGE3D,
    glsl::token_t::IMAGE2DRECT,
    glsl::token_t::IIMAGE2DRECT,
    glsl::token_t::UIMAGE2DRECT,
    glsl::token_t::IMAGECUBE,
    glsl::token_t::IIMAGECUBE,
    glsl::token_t::UIMAGECUBE,
    glsl::token_t::IMAGEBUFFER,
    glsl::token_t::IIMAGEBUFFER,
    glsl::token_t::UIMAGEBUFFER,
    glsl::token_t::IMAGE1DARRAY,
    glsl::token_t::IIMAGE1DARRAY,
    glsl::token_t::UIMAGE1DARRAY,
    glsl::token_t::IMAGE2DARRAY,
    glsl::token_t::IIMAGE2DARRAY,
    glsl::token_t::UIMAGE2DARRAY,
    glsl::token_t::IMAGECUBEARRAY,
    glsl::token_t::IIMAGECUBEARRAY,
    glsl::token_t::UIMAGECUBEARRAY,
    glsl::token_t::IMAGE2DMS,
    glsl::token_t::IIMAGE2DMS,
    glsl::token_t::UIMAGE2DMS,
    glsl::token_t::IMAGE2DMSARRAY,
    glsl::token_t::IIMAGE2DMSARRAY,
    glsl::token_t::UIMAGE2DMSARRAY,
    glsl::token_t::TYPE_NAME
  };

  return std::find(types.begin(), types.end(), kind) != types.end();
}

static token_t::kind_t get_textual_token(const std::string &str) {
  static const std::map<std::string, symbol_t::kind_t> keywords = {
    { "const", symbol_t::kind_t::CONST },
    { "uniform", symbol_t::kind_t::UNIFORM },
    { "buffer", symbol_t::kind_t::BUFFER },
    { "shared", symbol_t::kind_t::SHARED },
    { "coherent", symbol_t::kind_t::COHERENT },
    { "volatile", symbol_t::kind_t::VOLATILE },
    { "restrict", symbol_t::kind_t::RESTRICT },
    { "readonly", symbol_t::kind_t::READONLY },
    { "writeonly", symbol_t::kind_t::WRITEONLY },
    { "atomic_uint", symbol_t::kind_t::ATOMIC_UINT },
    { "layout", symbol_t::kind_t::LAYOUT },
    { "centroid", symbol_t::kind_t::CENTROID },
    { "flat", symbol_t::kind_t::FLAT },
    { "smooth", symbol_t::kind_t::SMOOTH },
    { "noperspective", symbol_t::kind_t::NOPERSPECTIVE },
    { "patch", symbol_t::kind_t::PATCH },
    { "sample", symbol_t::kind_t::SAMPLE },
    { "break", symbol_t::kind_t::BREAK },
    { "continue", symbol_t::kind_t::CONTINUE },
    { "do", symbol_t::kind_t::DO },
    { "for", symbol_t::kind_t::FOR },
    { "while", symbol_t::kind_t::WHILE },
    { "switch", symbol_t::kind_t::SWITCH },
    { "case", symbol_t::kind_t::CASE },
    { "default", symbol_t::kind_t::DEFAULT },
    { "if", symbol_t::kind_t::IF },
    { "else", symbol_t::kind_t::ELSE },
    { "subroutine", symbol_t::kind_t::SUBROUTINE },
    { "in", symbol_t::kind_t::IN },
    { "out", symbol_t::kind_t::OUT },
    { "inout", symbol_t::kind_t::INOUT },
    { "float", symbol_t::kind_t::FLOAT },
    { "double", symbol_t::kind_t::DOUBLE },
    { "int", symbol_t::kind_t::INT },
    { "void", symbol_t::kind_t::VOID },
    { "bool", symbol_t::kind_t::BOOL },
    { "true", symbol_t::kind_t::BOOLCONSTANT },
    { "false", symbol_t::kind_t::BOOLCONSTANT },
    { "invariant", symbol_t::kind_t::INVARIANT },
    { "precise", symbol_t::kind_t::PRECISE },
    { "discard", symbol_t::kind_t::DISCARD },
    { "return", symbol_t::kind_t::RETURN },
    { "mat2", symbol_t::kind_t::MAT2 },
    { "mat3", symbol_t::kind_t::MAT3 },
    { "mat4", symbol_t::kind_t::MAT4 },
    { "dmat2", symbol_t::kind_t::DMAT2 },
    { "dmat3", symbol_t::kind_t::DMAT3 },
    { "dmat4", symbol_t::kind_t::DMAT4 },
    { "mat2x2", symbol_t::kind_t::MAT2X2 },
    { "mat2x3", symbol_t::kind_t::MAT2X3 },
    { "mat2x4", symbol_t::kind_t::MAT2X4 },
    { "dmat2x2", symbol_t::kind_t::DMAT2X2 },
    { "dmat2x3", symbol_t::kind_t::DMAT2X3 },
    { "dmat2x4", symbol_t::kind_t::DMAT2X4 },
    { "mat3x2", symbol_t::kind_t::MAT3X2 },
    { "mat3x3", symbol_t::kind_t::MAT3X3 },
    { "mat3x4", symbol_t::kind_t::MAT3X4 },
    { "dmat3x2", symbol_t::kind_t::DMAT3X2 },
    { "dmat3x3", symbol_t::kind_t::DMAT3X3 },
    { "dmat3x4", symbol_t::kind_t::DMAT3X4 },
    { "mat4x2", symbol_t::kind_t::MAT4X2 },
    { "mat4x3", symbol_t::kind_t::MAT4X3 },
    { "mat4x4", symbol_t::kind_t::MAT4X4 },
    { "dmat4x2", symbol_t::kind_t::DMAT4X2 },
    { "dmat4x3", symbol_t::kind_t::DMAT4X3 },
    { "dmat4x4", symbol_t::kind_t::DMAT4X4 },
    { "vec2", symbol_t::kind_t::VEC2 },
    { "vec3", symbol_t::kind_t::VEC3 },
    { "vec4", symbol_t::kind_t::VEC4 },
    { "ivec2", symbol_t::kind_t::IVEC2 },
    { "ivec3", symbol_t::kind_t::IVEC3 },
    { "ivec4", symbol_t::kind_t::IVEC4 },
    { "bvec2", symbol_t::kind_t::BVEC2 },
    { "bvec3", symbol_t::kind_t::BVEC3 },
    { "bvec4", symbol_t::kind_t::BVEC4 },
    { "dvec2", symbol_t::kind_t::DVEC2 },
    { "dvec3", symbol_t::kind_t::DVEC3 },
    { "dvec4", symbol_t::kind_t::DVEC4 },
    { "uint", symbol_t::kind_t::UINT },
    { "uvec2", symbol_t::kind_t::UVEC2 },
    { "uvec3", symbol_t::kind_t::UVEC3 },
    { "uvec4", symbol_t::kind_t::UVEC4 },
    { "precision", symbol_t::kind_t::PRECISION },
    { "sampler1D", symbol_t::kind_t::SAMPLER1D },
    { "sampler2D", symbol_t::kind_t::SAMPLER2D },
    { "sampler3D", symbol_t::kind_t::SAMPLER3D },
    { "samplerCube", symbol_t::kind_t::SAMPLERCUBE },
    { "sampler1DShadow", symbol_t::kind_t::SAMPLER1DSHADOW },
    { "sampler2DShadow", symbol_t::kind_t::SAMPLER2DSHADOW },
    { "samplerCubeShadow", symbol_t::kind_t::SAMPLERCUBESHADOW },
    { "sampler1DArray", symbol_t::kind_t::SAMPLER1DARRAY },
    { "sampler2DArray", symbol_t::kind_t::SAMPLER2DARRAY },
    { "sampler1DArrayShadow", symbol_t::kind_t::SAMPLER1DARRAYSHADOW },
    { "sampler2DArrayShadow", symbol_t::kind_t::SAMPLER2DARRAYSHADOW },
    { "isampler1D", symbol_t::kind_t::ISAMPLER1D },
    { "isampler2D", symbol_t::kind_t::ISAMPLER2D },
    { "isampler3D", symbol_t::kind_t::ISAMPLER3D },
    { "isamplerCube", symbol_t::kind_t::ISAMPLERCUBE },
    { "isampler1DArray", symbol_t::kind_t::ISAMPLER1DARRAY },
    { "isampler2DArray", symbol_t::kind_t::ISAMPLER2DARRAY },
    { "usampler1D", symbol_t::kind_t::USAMPLER1D },
    { "usampler2D", symbol_t::kind_t::USAMPLER2D },
    { "usampler3D", symbol_t::kind_t::USAMPLER3D },
    { "usamplerCube", symbol_t::kind_t::USAMPLERCUBE },
    { "usampler1DArray", symbol_t::kind_t::USAMPLER1DARRAY },
    { "usampler2DArray", symbol_t::kind_t::USAMPLER2DARRAY },
    { "sampler2DRect", symbol_t::kind_t::SAMPLER2DRECT },
    { "sampler2DRectShadow", symbol_t::kind_t::SAMPLER2DRECTSHADOW },
    { "isampler2DRect", symbol_t::kind_t::ISAMPLER2DRECT },
    { "usampler2DRect", symbol_t::kind_t::USAMPLER2DRECT },
    { "samplerBuffer", symbol_t::kind_t::SAMPLERBUFFER },
    { "isamplerBuffer", symbol_t::kind_t::ISAMPLERBUFFER },
    { "usamplerBuffer", symbol_t::kind_t::USAMPLERBUFFER },
    { "sampler2DMS", symbol_t::kind_t::SAMPLER2DMS },
    { "isampler2DMS", symbol_t::kind_t::ISAMPLER2DMS },
    { "usampler2DMS", symbol_t::kind_t::USAMPLER2DMS },
    { "sampler2DMSArray", symbol_t::kind_t::SAMPLER2DMSARRAY },
    { "isampler2DMSArray", symbol_t::kind_t::ISAMPLER2DMSARRAY },
    { "usampler2DMSArray", symbol_t::kind_t::USAMPLER2DMSARRAY },
    { "samplerCubeArray", symbol_t::kind_t::SAMPLERCUBEARRAY },
    { "samplerCubeArrayShadow", symbol_t::kind_t::SAMPLERCUBEARRAYSHADOW },
    { "isamplerCubeArray", symbol_t::kind_t::ISAMPLERCUBEARRAY },
    { "usamplerCubeArray", symbol_t::kind_t::USAMPLERCUBEARRAY },
    { "image1D", symbol_t::kind_t::IMAGE1D },
    { "iimage1D", symbol_t::kind_t::IIMAGE1D },
    { "uimage1D", symbol_t::kind_t::UIMAGE1D },
    { "image2D", symbol_t::kind_t::IMAGE2D },
    { "iimage2D", symbol_t::kind_t::IIMAGE2D },
    { "uimage2D", symbol_t::kind_t::UIMAGE2D },
    { "image3D", symbol_t::kind_t::IMAGE3D },
    { "iimage3D", symbol_t::kind_t::IIMAGE3D },
    { "uimage3D", symbol_t::kind_t::UIMAGE3D },
    { "image2DRect", symbol_t::kind_t::IMAGE2DRECT },
    { "iimage2DRect", symbol_t::kind_t::IIMAGE2DRECT },
    { "uimage2DRect", symbol_t::kind_t::UIMAGE2DRECT },
    { "imageCube", symbol_t::kind_t::IMAGECUBE },
    { "iimageCube", symbol_t::kind_t::IIMAGECUBE },
    { "uimageCube", symbol_t::kind_t::UIMAGECUBE },
    { "imageBuffer", symbol_t::kind_t::IMAGEBUFFER },
    { "iimageBuffer", symbol_t::kind_t::IIMAGEBUFFER },
    { "uimageBuffer", symbol_t::kind_t::UIMAGEBUFFER },
    { "image1DArray", symbol_t::kind_t::IMAGE1DARRAY },
    { "iimage1DArray", symbol_t::kind_t::IIMAGE1DARRAY },
    { "uimage1DArray", symbol_t::kind_t::UIMAGE1DARRAY },
    { "image2DArray", symbol_t::kind_t::IMAGE2DARRAY },
    { "iimage2DArray", symbol_t::kind_t::IIMAGE2DARRAY },
    { "uimage2DArray", symbol_t::kind_t::UIMAGE2DARRAY },
    { "imageCubeArray", symbol_t::kind_t::IMAGECUBEARRAY },
    { "iimageCubeArray", symbol_t::kind_t::IIMAGECUBEARRAY },
    { "uimageCubeArray", symbol_t::kind_t::UIMAGECUBEARRAY },
    { "image2DMS", symbol_t::kind_t::IMAGE2DMS },
    { "iimage2DMS", symbol_t::kind_t::IIMAGE2DMS },
    { "uimage2DMS", symbol_t::kind_t::UIMAGE2DMS },
    { "image2DMSArray", symbol_t::kind_t::IMAGE2DMSARRAY },
    { "iimage2DMSArray", symbol_t::kind_t::IIMAGE2DMSARRAY },
    { "uimage2DMSArray", symbol_t::kind_t::UIMAGE2DMSARRAY },
    { "struct", symbol_t::kind_t::STRUCT },
    { "lowp", symbol_t::kind_t::LOW_PRECISION },
    { "mediump", symbol_t::kind_t::MEDIUM_PRECISION },
    { "highp", symbol_t::kind_t::HIGH_PRECISION },
    { "varying", symbol_t::kind_t::OUT },
    { "attribute", symbol_t::kind_t::IN },
    { "common", symbol_t::kind_t::__break__ },
    { "partition", symbol_t::kind_t::__break__ },
    { "active", symbol_t::kind_t::__break__ },
    { "asm", symbol_t::kind_t::__break__ },
    { "class", symbol_t::kind_t::__break__ },
    { "union", symbol_t::kind_t::__break__ },
    { "enum", symbol_t::kind_t::__break__ },
    { "typedef", symbol_t::kind_t::__break__ },
    { "template", symbol_t::kind_t::__break__ },
    { "this", symbol_t::kind_t::__break__ },
    { "resource", symbol_t::kind_t::__break__ },
    { "goto", symbol_t::kind_t::__break__ },
    { "inline", symbol_t::kind_t::__break__ },
    { "noinline", symbol_t::kind_t::__break__ },
    { "public", symbol_t::kind_t::__break__ },
    { "static", symbol_t::kind_t::__break__ },
    { "extern", symbol_t::kind_t::__break__ },
    { "external", symbol_t::kind_t::__break__ },
    { "interface", symbol_t::kind_t::__break__ },
    { "long", symbol_t::kind_t::__break__ },
    { "short", symbol_t::kind_t::__break__ },
    { "half", symbol_t::kind_t::__break__ },
    { "fixed", symbol_t::kind_t::__break__ },
    { "unsigned", symbol_t::kind_t::__break__ },
    { "superp", symbol_t::kind_t::__break__ },
    { "input", symbol_t::kind_t::__break__ },
    { "output", symbol_t::kind_t::__break__ },
    { "hvec2", symbol_t::kind_t::__break__ },
    { "hvec3", symbol_t::kind_t::__break__ },
    { "hvec4", symbol_t::kind_t::__break__ },
    { "fvec2", symbol_t::kind_t::__break__ },
    { "fvec3", symbol_t::kind_t::__break__ },
    { "fvec4", symbol_t::kind_t::__break__ },
    { "sampler3DRect", symbol_t::kind_t::__break__ },
    { "filter", symbol_t::kind_t::__break__ },
    { "sizeof", symbol_t::kind_t::__break__ },
    { "cast", symbol_t::kind_t::__break__ },
    { "namespace", symbol_t::kind_t::__break__ },
    { "using", symbol_t::kind_t::__break__ }
  };

  auto iter = keywords.find(str);
  if (iter != keywords.end()) {
    if (iter->second == symbol_t::kind_t::__break__) {
      throw std::runtime_error("reserved keyword unsupported " + str);
    }

    return static_cast<token_t::kind_t>(iter->second);
  }

  return token_t::IDENTIFIER;
}

}   // gliss