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


#define ParseFieldString(name) \
    { \
    std::getline( lineStream, inputField, ',' ); \
    stringVector::iterator serviceItr = std::find( name.begin(), name.end(), inputField ); \
    if( serviceItr != name.end() )   \
      {   \
      newRecord.name = serviceItr - name.begin();   \
      }   \
    else   \
      {   \
      newRecord.name = name.size();   \
      name.push_back( inputField );   \
      } \
    }

#define PrintTable(name) \
  { \
  std::cout << "#name" << std::endl; \
  stringVector::const_iterator nameItr = name.begin(); \
  while( nameItr != name.end() ) \
    { \
    std::cout << *nameItr << std::endl; \
    ++nameItr; \
    } \
  }



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

  std::string inputString;
  std::string inputField;

  dischargeRecord newRecord;


  while( !inputFile.eof() )
    {
    std::getline( inputFile, inputString );
    std::stringstream lineStream( inputString );

    ParseFieldString(HospitalServiceArea);
    ParseFieldString(HospitalCounty);
    ParseFieldString(OperatingCertificateNumber);
    ParseFieldString(FacilityId);
    ParseFieldString(FacilityName);

    records.push_back( newRecord );
    }


  PrintTable(HospitalServiceArea);
  PrintTable(HospitalCounty);
  PrintTable(OperatingCertificateNumber);
  PrintTable(FacilityId);
  PrintTable(FacilityName);

  std::cout << "Headers = " << std::endl;
  std::cout << headers << std::endl;

  std::cout << "Records read = " << records.size() << std::endl;

 return 0;
}

