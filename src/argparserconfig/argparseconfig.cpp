#include "../appinfo/appinfo.hpp"
#include <argparse.hpp>
#include <cstring>
#include <iostream>

void configureAndParse(argparse::ArgumentParser &arg_parser, int argc,
                       char const *argv[]) {

  auto &group = arg_parser.add_mutually_exclusive_group(true);

  group.add_argument("-b", "--binary")
      .help("Print raw binary bits of the input")
      .default_value(std::string(""));

  group.add_argument("-c", "--checksum")
      .help("Calculate the checksum for the given input")
      .default_value(std::string(""));

  group.add_argument("-vm", "--vmac")
      .help("Validate whether input is a MAC address")
      .default_value(std::string(""));

  arg_parser.add_argument("-f", "--format")
      .help("Checksum output format (bin or hex)")
      .default_value(std::string("hex"));

  try {
    arg_parser.parse_args(argc, argv);
  } catch (const std::exception &e) {
    std::cerr << "Error parsing arguments: " << e.what() << "\n";
    std::exit(1);
  }

  for (int i = 1; i < argc; ++i) {
    if (std::strlen(argv[i]) > 2 && argv[i][0] == '-' && argv[i][1] != '-') {
      std::cerr << "Compound short option '" << argv[i]
                << "' is not supported.\n"
                << "Try '" << AppInfo::name()
                << " --help' to see available usage.\n";
      std::exit(1);
    }
  }

  if (arg_parser.is_used("-f") && !arg_parser.is_used("-c")) {
    std::cerr << "Option '-f/--format' is only meaningful when used with "
                 "'-c/--checksum'.\n"
              << "See --help for usage details.\n";
    std::exit(1);
  }
}
