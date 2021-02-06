// This is my first cpp stuff



#include <iostream>
#include <boost/program_options.hpp>


using namespace std;
namespace po = boost::program_options;


po::variables_map getProgramOptions(const int argc, const char* const* argv) {
    po::options_description program_options("Read EXIF Headers");

    program_options.add_options()
        ("help,h", "Display the help message.")
        ("name,n", po::value<string>()->default_value("na"), "Select Name to Search For.")
        ("dir,d", po::value<string>()->default_value("./"), "Select Directory to Search In.")
        ("recursive,r", po::value<bool>()->default_value("True"), "Search Recursive.");
    
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, program_options), vm);
    po::notify(vm);    

    // output help
    if (vm.count("help")) {
        cout << program_options << "\n";
    }

    return vm;
}

void printHeader(){
    cout<<"+++++++++++++++++++++++"<<endl;
    cout<<"+++  exif meta tool +++"<<endl;
    cout<<"+++++++++++++++++++++++"<<endl;
}

int main(int argc, char *argv[]) {

    // print header
    printHeader;

    // parse cmd line params
    po::variables_map vm = getProgramOptions(argc, argv);

    // loop over files and extract exif info and store in array
    cout << "Name:" << vm["name"].as<string>() << endl;
    cout << "Dir:" << vm["dir"].as<string>() << endl;
    cout << "Recursive:" << vm["recursive"].as<bool>() << endl;

    // check array and report the oldest time stamp/file


    
    return 0;

}
