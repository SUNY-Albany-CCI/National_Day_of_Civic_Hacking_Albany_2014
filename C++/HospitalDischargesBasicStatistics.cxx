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

};

typedef std::vector< dischargeRecord > dischargesRecords;

typedef std::vector< std::string > stringVector;

stringVector HospitalServiceArea;
stringVector HospitalCounties;

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

 return 0;
}

