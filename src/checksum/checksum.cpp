#include "../termutils/termutils.hpp"
#include <bitset>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace Checksum {

// private helper functions
namespace {
std::string getRawBits(const std::string &str) {
  std::string bits;
  bits.reserve(str.size() * 8);

  for (unsigned char c : str) {
    bits += std::bitset<8>(c).to_string(); // append 8 raw bits
  }

  return bits;
}

uint16_t computeChecksum(const std::string &rawBits) {
  uint32_t acc = 0;
  std::vector<std::bitset<16>> words;

  // Form 16-bit words (2 bytes). Since it's bits, take 16 at a time.
  for (size_t i = 0; i < rawBits.size(); i += 16) {
    std::string chunk = rawBits.substr(i, 16);

    // If last chunk < 16 bits, pad with zeros on the right
    if (chunk.size() < 16) {
      chunk.append(16 - chunk.size(), '0');
    }

    words.emplace_back(chunk);
  }

  // 1’s complement sum + wrap carry
  for (const auto &w : words) {
    acc += w.to_ulong();
    acc = (acc & 0xFFFF) + (acc >> 16); // carry wrap-around
  }

  // Final 1’s complement + mask to 16 bits
  return static_cast<uint16_t>(~acc & 0xFFFF);
}
} // namespace

void printChecksum(const std::string &rawBytes,
                   const std::string &print_format = "bin") {

  if (print_format != "hex" && print_format != "bin") {
    std::cerr << "Invalid print format for checksum\n";
    std::exit(1);
  }

  std::string _rawBytes = rawBytes;

  if (termutils::isPiped() && _rawBytes.empty()) {
    std::ostringstream os;
    os << std::cin.rdbuf();
    _rawBytes = os.str();
    if (!_rawBytes.empty() && _rawBytes.back() == '\n') {
      _rawBytes.pop_back();
    }
  }

  if (_rawBytes.empty()) {
    std::cerr << "No input provided\n";
    std::exit(1);
  }

  auto checksum = computeChecksum(_rawBytes);

  if (print_format == "hex") {
    std::cout << std::hex << checksum << "\n";
  } else {
    std::cout << std::bitset<16>(checksum) << "\n";
  }
}

void printRawBytes(const std::string &input) {
  std::string _input = input;

  if (termutils::isPiped() && _input.empty()) {
    std::ostringstream os;
    os << std::cin.rdbuf();

    _input = os.str();
    if (!_input.empty() && _input.back() == '\n') {
      _input.pop_back();
    }
  }

  if (_input.empty()) {
    std::cerr << "No input provided\n";
    std::exit(1);
  }

  std::cout << getRawBits(_input) << "\n";
}

} // namespace Checksum
