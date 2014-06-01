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
#include <vector>

int main( int argc, const char * argv[] )
{

  std::string inputFilename = argv[1];

  std::ifstream inputFile { inputFilename };

  std::vector< std::string > records;

  std::string headers;

  std::getline( inputFile, headers );

  std::cout << "Headers = " << std::endl;
  std::cout << headers << std::endl;

  std::string inputString;

  while( !inputFile.eof() )
    {
    std::getline( inputFile, inputString );
    records.push_back( inputString );
    }

  std::cout << "Records read = " << records.size() << std::endl;


  return 0;
}

