#include <cstdlib>
#include <string>

#include "vega/dictionary/dictionary.h"
#include "vega/dicom/file.h"
using namespace std;
int main() {

  // read dicom file:
    vega::dictionary::Dictionary::set_dictionary("/usr/local/share/vega/dictionary.txt");
    const std::string file_name = "/home/huyle/Desktop/dataset/a/undefined_SQ_rtdose.dcm";
    vega::dicom::File file(file_name);
    vega::Formatter formatter(std::cout);
    file.data_set()->log(formatter);
    


  //modify dicom value:  
    // const string file_name = "/home/huyle/Desktop/vega/test/data/undefined_SQ_rtdose.dcm";
    // vega::dicom::File file(file_name);

    // auto manipulatorName = file.data_set()->element<vega::dictionary::PatientName>()->manipulator();
    // for (auto& name : *manipulatorName) {
    //   name = "abcdefgh";
    // }

    // auto mainipulatorPatientID = file.data_set()->element<vega::dictionary::PatientID>()->manipulator();

    // for (auto& id: *mainipulatorPatientID) {
    //   id = "18001011";  
    // }

    // file.write("/home/huyle/Desktop/dataset/a/undefined_SQ_rtdose.dcm");
  return 0;
}