#include "macaddr.hpp"
#include "../termutils/termutils.hpp"
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

namespace MacAddr {
// private helper functions
namespace {
bool isMacValid(const std::string &mac) {
  static const std::regex valid_mac_pattern(
      "^(?:(?:[0-9A-Fa-f]{2}[:-]){5}[0-9A-Fa-f]{2}"
      "|(?:[0-9a-fA-F]{4}\\.){2}[0-9a-fA-F]{4})$");

  return std::regex_match(mac, valid_mac_pattern);
}

bool isBroadcast(const std::string &mac) {
  static const std::regex broadcast_mac_pattern("^(?:(?:[fF]{2}[:-]){5}[fF]{2}$"
                                                "|(?:[fF]{4}\\.){2}[fF]{4})$");
  return std::regex_match(mac, broadcast_mac_pattern);
}
} // namespace

void printIsMacAddrValid(const std::string &mac) {
  std::string _mac = mac;

  if (termutils::isPiped() && _mac.empty()) {
    std::ostringstream os;
    os << std::cin.rdbuf();
    _mac = os.str();
    if (!_mac.empty() && _mac.back() == '\n') {
      _mac.pop_back();
    }
  }

  if (_mac.empty()) {
    std::cerr << "Argument is required\n";
    std::exit(1);
  }

  std::cout << (isMacValid(_mac) ? "valid" : "Invalid") << " ("
            << (isBroadcast(_mac) ? "Broadcast" : "Multicast") << ")" << "\n";
}
} // namespace MacAddr
