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

  unsigned int hospitalServiceArea;
  unsigned int hospitalCounty;
  unsigned int operatingCertificateNumber;
  unsigned int facilityId;
  unsigned int facilityName;

};

typedef std::vector< dischargeRecord > dischargesRecords;

typedef std::vector< std::string > stringVector;

stringVector HospitalServiceArea;
stringVector HospitalCounties;
stringVector OperatingCertificateNumbers;
stringVector FacilityIds;
stringVector FacilityNames;

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
      newRecord.hospitalServiceArea = serviceItr - HospitalServiceArea.begin();
      }
    else
      {
      newRecord.hospitalServiceArea = HospitalServiceArea.size();
      HospitalServiceArea.push_back( inputField );
      }

    //
    //  Parse the Hospital County field
    //
    std::getline( lineStream, inputField, ',' );

    stringVector::iterator countyItr = std::find( HospitalCounties.begin(), HospitalCounties.end(), inputField );
    if( countyItr != HospitalCounties.end() )
      {
      newRecord.hospitalCounty = countyItr - HospitalCounties.begin();
      }
    else
      {
      newRecord.hospitalCounty = HospitalCounties.size();
      HospitalCounties.push_back( inputField );
      }

    //
    //  Parse the Operating Certificate Number field
    //
    std::getline( lineStream, inputField, ',' );

    stringVector::iterator operatingCertificateItr = std::find( OperatingCertificateNumbers.begin(), OperatingCertificateNumbers.end(), inputField );
    if( operatingCertificateItr != OperatingCertificateNumbers.end() )
      {
      newRecord.operatingCertificateNumber = operatingCertificateItr - OperatingCertificateNumbers.begin();
      }
    else
      {
      newRecord.operatingCertificateNumber = OperatingCertificateNumbers.size();
      OperatingCertificateNumbers.push_back( inputField );
      }

    //
    //  Parse the Facility Id field
    //
    std::getline( lineStream, inputField, ',' );

    stringVector::iterator facilityIdItr = std::find( FacilityIds.begin(), FacilityIds.end(), inputField );
    if( facilityIdItr != FacilityIds.end() )
      {
      newRecord.facilityId = facilityIdItr - FacilityIds.begin();
      }
    else
      {
      newRecord.facilityId = FacilityIds.size();
      FacilityIds.push_back( inputField );
      }

    //
    //  Parse the Facility Name field
    //
    std::getline( lineStream, inputField, ',' );

    stringVector::iterator facilityNameItr = std::find( FacilityNames.begin(), FacilityNames.end(), inputField );
    if( facilityNameItr != FacilityNames.end() )
      {
      newRecord.facilityName = facilityNameItr - FacilityNames.begin();
      }
    else
      {
      newRecord.facilityName = FacilityNames.size();
      FacilityNames.push_back( inputField );
      }


    records.push_back( newRecord );
    }

  std::cout << "Records read = " << records.size() << std::endl;

  std::cout << "First record = " << std::endl;
  std::cout << records[0].hospitalServiceArea << std::endl;

  std::cout << "Service areas " << std::endl;
  stringVector::const_iterator hsaItr = HospitalServiceArea.begin();
  while( hsaItr != HospitalServiceArea.end() )
    {
    std::cout << *hsaItr << std::endl;
    ++hsaItr;
    }

  std::cout << "Counties " << std::endl;
  stringVector::const_iterator hcItr = HospitalCounties.begin();
  while( hcItr != HospitalCounties.end() )
    {
    std::cout << *hcItr << std::endl;
    ++hcItr;
    }

  std::cout << "Operating Certificate Numbers " << std::endl;
  stringVector::const_iterator ocnItr = OperatingCertificateNumbers.begin();
  while( ocnItr != OperatingCertificateNumbers.end() )
    {
    std::cout << *ocnItr << std::endl;
    ++ocnItr;
    }

  std::cout << "Facility Ids " << std::endl;
  stringVector::const_iterator fiItr = FacilityIds.begin();
  while( fiItr != FacilityIds.end() )
    {
    std::cout << *fiItr << std::endl;
    ++fiItr;
    }

  std::cout << "Facility Names " << std::endl;
  stringVector::const_iterator fnItr = FacilityNames.begin();
  while( fnItr != FacilityNames.end() )
    {
    std::cout << *fnItr << std::endl;
    ++fnItr;
    }


  std::cout << "Headers = " << std::endl;
  std::cout << headers << std::endl;

 return 0;
}

