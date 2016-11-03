/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * big table connector. Copyright (C)  2015
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/
#ifndef SOURCE_H_
#define SOURCE_H_

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

using namespace std;

#include "./constructs/Results.h"
#include "../data/constructs/server/ServerDefinition.h"
#include "../data/constructs/IterInfo.h"
#include "../data/constructs/column.h"

namespace scanners {
using namespace cclient::data;
using namespace cclient::data::tserver;

template<typename T, class BlockType>
class Source {
public:
    Source() {
        iters = new vector<cclient::data::IterInfo*>();
    }
    
   

    virtual void addRange(Range *range) = 0;

    /**
     * Add the list of user supplied Iterators;
     */
    void addIterators(vector<cclient::data::IterInfo*> *iterV) {
        iters->insert(iters->end(), iterV->begin(), iterV->end());
    }

    virtual Results<T, BlockType> * getResultSet() = 0;

    virtual void addResults(Results<T, BlockType> *results) = 0;

    virtual ~Source() {
        for(auto iter : *iters)
	{
	  delete iter;
	}
	delete iters;
	for(auto column : columns)
	{
	  delete column;
	}
    }
    
    vector<Column*> *getColumns()
    {
      return &columns;
    }
    
    
    vector<cclient::data::IterInfo*> *getIters()
    {
      return iters;
    }
    
    
    
    void fetchColumn(string col, string colqual="")
    {
      if (!IsEmpty(&colqual))
      {
	columns.push_back(new Column(col,colqual));
      }
      else
	columns.push_back(new Column(col));
    }
protected:
    vector<Column*> columns;
    vector<cclient::data::IterInfo*> *iters;
};
}
#endif /* SCANNER_H_ */
