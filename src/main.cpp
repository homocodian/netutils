#include "argparserconfig/argparserconfig.hpp"
#include "checksum/checksum.hpp"
#include "macaddr/macaddr.hpp"
#include <argparse.hpp>
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  argparse::ArgumentParser parser(APP_NAME, APP_VERSION);
  configureAndParse(parser, argc, argv);

  if (parser.is_used("-b")) {
    Checksum::printRawBytes(parser.get<std::string>("-b"));
    return 0;
  }

  else if (parser.is_used("-c")) {
    Checksum::printChecksum(parser.get<std::string>("-c"),
                            parser.get<std::string>("-f"));
    return 0;
  }

  else if (parser.is_used("-vm")) {
    MacAddr::printIsMacAddrValid(parser.get<std::string>("vm"));
    return 0;
  }

  // Nothing was used → print help
  std::cout << parser;
  return 0;
}
