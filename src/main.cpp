#include <string>
#include <memory>

#include "vega/dictionary/dictionary.h"
#include "vega/controller.h"
#include "vega/dicom/file.h"

int main(int argc, char* argv[]) {

//  vega::Controller controller(argc, argv);
//  controller.run();

   vega::dictionary::Dictionary::set_dictionary("home/huyle/Desktop/dictionary.txt");
  
  // Read the DICOM file in
  const std::string file_name = "/home/huyle/Desktop/IMG-0001-00003.dcm";
  vega::dicom::File file(file_name);
  
  // Print a human-friendly representation of the file to std::cout
  vega::Formatter formatter(std::cout);
  file.data_set()->log(formatter);
}
