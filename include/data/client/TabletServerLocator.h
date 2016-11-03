/*
 * Copyright (c) 2016 Marc Parisi marc.parisi@gmail.com
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef TABLETSERVERLOCATOR_H_
#define TABLETSERVERLOCATOR_H_

#include <map>
#include <sstream>
#include "ExtentLocator.h"
#include "../constructs/client/Instance.h"
#include "TabletLocationObtainer.h"
using namespace std;

namespace cclient {
namespace impl {

class TabletServerLocator: public TabletLocator {
public:
    TabletServerLocator(string tableId, TabletLocator *parent,
                        TabletLocationObtainer *locator, Instance *inst);
    virtual ~TabletServerLocator();
    
    virtual list<TabletLocation*> locations(AuthInfo *credentials)
    {
      
      stringstream metadataRow;

        metadataRow << tableId << ';';
        
        
        TabletLocation *location = parent->locateTablet(credentials,
                                   metadataRow.str(), false, true);
	
	list<TabletLocation*> locations = locator->findTablet(credentials,
                                              location, metadataRow.str(), lastTabletRow, parent);
	return locations;
    } 

    TabletLocation *locateTablet(AuthInfo *creds, string row, bool skipRow,
                                 bool retry) {

        string modifiedRow;

        if (skipRow) {

            char *backing = new char[row.length() + 1];
            memset(backing, 0x01, row.length() + 1);
            memcpy(backing, row.c_str(), row.length());
            modifiedRow = string(backing);
            delete[] backing;
        } else
            modifiedRow = row;

        // check cached

        stringstream metadataRow;

        metadataRow << tableId << ';' << modifiedRow;

        TabletLocation *parentLocation = parent->locateTablet(creds,
                                   metadataRow.str(), false, retry);

        if (NULL != parentLocation) {
            list<TabletLocation*> locations = locator->findTablet(creds,
                                              parentLocation, metadataRow.str(), lastTabletRow, parent);
	    TabletLocation *returnLocation = NULL;
            for (auto location : locations) {

                if (location->getExtent()->getPrevEndRow().length() == 0
                        || location->getExtent()->getPrevEndRow()
                        < modifiedRow) {
                    returnLocation = location;
		  break;
                } else {
                    cout << "could not find location" << endl;
                    exit(1);
                }
            }
            for (auto loc : locations) {
	      if (returnLocation != loc)
	      {
		delete loc;
	      }
	    }
	    delete parentLocation;
            if (NULL != returnLocation)
	      return returnLocation;	
	    else
	      throw new ClientException("Could not find tablet");

        } else {
            cout << "could not find location" << endl;
            exit(1);
        }		

        return 0;

    }

    inline void binMutations(AuthInfo *credentials, vector<Mutation*> *mutations,
                      map<string, TabletServerMutations*> *binnedMutations,
                      set<string> *locations, vector<Mutation*> *failures) {
        map<string, TabletServerMutations*>::iterator it;
        for (Mutation *m : *mutations) {
            TabletLocation *loc = locateTablet(credentials, m->getRow(), false,false);

            TabletServerMutations *tsm = NULL;
            it = binnedMutations->find(loc->getLocation());
            if (it != binnedMutations->end()) {
                tsm = it->second;
            }

            if (NULL == tsm) {
                locations->insert(loc->getLocation());
                tsm = new TabletServerMutations(loc->getSession());
                binnedMutations->insert(
                    std::make_pair(loc->getLocation(), tsm));
            }

            tsm->addMutation(loc->getExtent(), m);
	    
	    loc->setExtent(0);
	    delete loc;
        }
    }

    vector<Range*> binRanges(AuthInfo *credentials, vector<Range*> *ranges,
                             set<string> *locations,
                             map<string,
                             map<KeyExtent*, vector<Range*>,
                             pointer_comparator<KeyExtent*> > > *binnedRanges) {

        string startRow = "";
        vector<Range*> failures;
        vector<TabletLocation*> tabletLocations;
        for (auto range : *ranges) {
            if (range->getStartKey() != NULL) {
                startRow = string(range->getStartKey()->getRow().first,
                                  range->getStartKey()->getRow().second);
            }

            TabletLocation *loc = locateTablet(credentials, startRow, false,
                                               false);

            if (NULL == loc) {
                failures.push_back(range);
                continue;
            }

            tabletLocations.push_back(loc);
            string stopKey = "";
            if (range->getStopKey() != NULL)
                stopKey = string(range->getStopKey()->getRow().first,
                                 range->getStopKey()->getRow().second);
            string extentEndRow = loc->getExtent()->getEndRow();

            while (!range->getInfiniteStopKey() && stopKey >= extentEndRow) {
                loc = locateTablet(credentials, extentEndRow, true, false);
                if (NULL == loc) {
                    break;
                }
                tabletLocations.push_back(loc);

                extentEndRow = loc->getExtent()->getEndRow();

                if (extentEndRow.length() == 0)
                    break;

            }
            for (auto locs : tabletLocations) {
                locations->insert(loc->getLocation());
                (*binnedRanges)[loc->getLocation()][locs->getExtent()].push_back(
                    range);
            }

        }
        return failures;
    }

    void invalidateCache(KeyExtent failedExtent) {
    }

    void invalidateCache() {
    }

    void invalidateCache(vector<KeyExtent> keySet) {
    }

protected:
    string lastTabletRow;
    string tableId;
    TabletLocator *parent;
    TabletLocationObtainer *locator;
    Instance *instance;
};

} /* namespace data */
} /* namespace cclient */
#endif /* TABLETSERVERLOCATOR_H_ */
