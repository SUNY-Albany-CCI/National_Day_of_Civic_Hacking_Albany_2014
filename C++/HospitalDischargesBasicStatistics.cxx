/*=========================================================================
 *
 *  Copyright by contributors
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include <string>
#include <iterator>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>


class dischargeRecord
{
public:

  unsigned int HospitalServiceArea;
  unsigned int HospitalCounty;
  unsigned int OperatingCertificateNumber;
  unsigned int FacilityId;
  unsigned int FacilityName;

};

typedef std::vector< dischargeRecord > dischargesRecords;

typedef std::vector< std::string > stringVector;

stringVector HospitalServiceArea;
stringVector HospitalCounty;
stringVector OperatingCertificateNumber;
stringVector FacilityId;
stringVector FacilityName;

int main( int argc, const char * argv[] )
{

  std::string inputFilename = argv[1];

  std::ifstream inputFile { inputFilename };

  dischargesRecords records;

  std::string headers;

  std::getline( inputFile, headers );

  std::cout << "Headers = " << std::endl;
  std::cout << headers << std::endl;

  std::string inputString;

  dischargeRecord newRecord;

  std::string inputField;

  while( !inputFile.eof() )
    {
    std::getline( inputFile, inputString );
    std::stringstream lineStream( inputString );

    //
    //  Parse the Hospital Service Area field
    //
    std::getline( lineStream, inputField, ',' );

    stringVector::iterator serviceItr = std::find( HospitalServiceArea.begin(), HospitalServiceArea.end(), inputField );
    if( serviceItr != HospitalServiceArea.end() )
      {
      newRecord.HospitalServiceArea = serviceItr - HospitalServiceArea.begin();
      }
    else
      {
      newRecord.HospitalServiceArea = HospitalServiceArea.size();
      HospitalServiceArea.push_back( inputField );
      }

    //
    //  Parse the Hospital County field
    //
    std::getline( lineStream, inputField, ',' );

    stringVector::iterator countyItr = std::find( HospitalCounty.begin(), HospitalCounty.end(), inputField );
    if( countyItr != HospitalCounty.end() )
      {
      newRecord.HospitalCounty = countyItr - HospitalCounty.begin();
      }
    else
      {
      newRecord.HospitalCounty = HospitalCounty.size();
      HospitalCounty.push_back( inputField );
      }

    //
    //  Parse the Operating Certificate Number field
    //
    std::getline( lineStream, inputField, ',' );

    stringVector::iterator operatingCertificateItr = std::find( OperatingCertificateNumber.begin(), OperatingCertificateNumber.end(), inputField );
    if( operatingCertificateItr != OperatingCertificateNumber.end() )
      {
      newRecord.OperatingCertificateNumber = operatingCertificateItr - OperatingCertificateNumber.begin();
      }
    else
      {
      newRecord.OperatingCertificateNumber = OperatingCertificateNumber.size();
      OperatingCertificateNumber.push_back( inputField );
      }

    //
    //  Parse the Facility Id field
    //
    std::getline( lineStream, inputField, ',' );

    stringVector::iterator facilityIdItr = std::find( FacilityId.begin(), FacilityId.end(), inputField );
    if( facilityIdItr != FacilityId.end() )
      {
      newRecord.FacilityId = facilityIdItr - FacilityId.begin();
      }
    else
      {
      newRecord.FacilityId = FacilityId.size();
      FacilityId.push_back( inputField );
      }

    //
    //  Parse the Facility Name field
    //
    std::getline( lineStream, inputField, ',' );

    stringVector::iterator facilityNameItr = std::find( FacilityName.begin(), FacilityName.end(), inputField );
    if( facilityNameItr != FacilityName.end() )
      {
      newRecord.FacilityName = facilityNameItr - FacilityName.begin();
      }
    else
      {
      newRecord.FacilityName = FacilityName.size();
      FacilityName.push_back( inputField );
      }


    records.push_back( newRecord );
    }

  std::cout << "Records read = " << records.size() << std::endl;

  std::cout << "First record = " << std::endl;
  std::cout << records[0].HospitalServiceArea << std::endl;

  std::cout << "Service areas " << std::endl;
  stringVector::const_iterator hsaItr = HospitalServiceArea.begin();
  while( hsaItr != HospitalServiceArea.end() )
    {
    std::cout << *hsaItr << std::endl;
    ++hsaItr;
    }

  std::cout << "Counties " << std::endl;
  stringVector::const_iterator hcItr = HospitalCounty.begin();
  while( hcItr != HospitalCounty.end() )
    {
    std::cout << *hcItr << std::endl;
    ++hcItr;
    }

  std::cout << "Operating Certificate Numbers " << std::endl;
  stringVector::const_iterator ocnItr = OperatingCertificateNumber.begin();
  while( ocnItr != OperatingCertificateNumber.end() )
    {
    std::cout << *ocnItr << std::endl;
    ++ocnItr;
    }

  std::cout << "Facility Ids " << std::endl;
  stringVector::const_iterator fiItr = FacilityId.begin();
  while( fiItr != FacilityId.end() )
    {
    std::cout << *fiItr << std::endl;
    ++fiItr;
    }

  std::cout << "Facility Names " << std::endl;
  stringVector::const_iterator fnItr = FacilityName.begin();
  while( fnItr != FacilityName.end() )
    {
    std::cout << *fnItr << std::endl;
    ++fnItr;
    }


  std::cout << "Headers = " << std::endl;
  std::cout << headers << std::endl;

 return 0;
}

