#include "argparse.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Arguments {
    string file_list;
    string working_directory;
    string output_filename;
    int number_of_threads;
    int num_of_passes;
    double containment_threshold;
};


typedef Arguments Arguments;


Arguments arguments;


void parse_arguments(int argc, char *argv[]) {

    argparse::ArgumentParser parser("yacht train using indexing of sketches");
    
    parser.add_argument("file_list")
        .help("file containing list of files to be processed")
        .store_into(arguments.file_list);
    parser.add_argument("working_directory")
        .help("working directory (where temp files are generated)")
        .store_into(arguments.working_directory);
    parser.add_argument("output_filename")
        .help("output filename (where the reduced ref filenames will be written)")
        .store_into(arguments.output_filename);
    parser.add_argument("-t", "--threads")
        .help("number of threads")
        .default_value(1)
        .store_into(arguments.number_of_threads);
    parser.add_argument("-p", "--passes")
        .help("number of passes")
        .default_value(1)
        .store_into(arguments.num_of_passes);
    parser.add_argument("-c", "--containment_threshold")
        .help("containment threshold")
        .default_value(0.9)
        .store_into(arguments.containment_threshold);
    parser.parse_args(argc, argv);

    if (arguments.number_of_threads < 1) {
        throw std::runtime_error("number of threads must be at least 1");
    }

    if (arguments.num_of_passes < 1) {
        throw std::runtime_error("number of passes must be at least 1");
    }

    if (arguments.containment_threshold < 0.0 || arguments.containment_threshold > 1.0) {
        throw std::runtime_error("containment threshold must be between 0.0 and 1.0");
    }

    // store the arguments in the arguments struct
    arguments.file_list = parser.get<std::string>("file_list");
    arguments.working_directory = parser.get<std::string>("working_directory");
    arguments.output_filename = parser.get<std::string>("output_filename");
    arguments.number_of_threads = parser.get<uint>("threads");
    arguments.num_of_passes = parser.get<uint>("passes");
    arguments.containment_threshold = parser.get<double>("containment_threshold");

}


int main(int argc, char *argv[]) {

    try {
        parse_arguments(argc, argv);
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    cout << "file_list: " << arguments.file_list << endl;
    cout << "working_directory: " << arguments.working_directory << endl;
    cout << "output_filename: " << arguments.output_filename << endl;
    cout << "number_of_threads: " << arguments.number_of_threads << endl;
    cout << "num_of_passes: " << arguments.num_of_passes << endl;
    cout << "containment_threshold: " << arguments.containment_threshold << endl;

    return 0;
}