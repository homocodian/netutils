#pragma once

#include <string>

namespace Checksum {

void printChecksum(const std::string &rawBytes,
                   const std::string &print_format = "bin");

void printRawBytes(const std::string &input);

} // namespace Checksum
