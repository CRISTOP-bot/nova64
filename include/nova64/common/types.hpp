#pragma once
#include <cstdint>
#include <stdexcept>
namespace nova64 { enum class AccessSize { U8=1,U16=2,U32=4,U64=8 }; enum class AccessType { Read,Write,Execute }; }
