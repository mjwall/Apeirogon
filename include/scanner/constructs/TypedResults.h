/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TYPEDRESULTS_H_
#define TYPEDRESULTS_H_

#include "Results.h"
namespace scanners
{
template<class T, class TypeTo>
class TypedResults : public ResultIter<T>
{

protected:
    TypeTo *myVal;
    T yourVal;
public:

    TypedResults (void *copyResultSet) :
        ResultIter<T> (reinterpret_cast<ResultIter<T>*> (copyResultSet))
    {

    }

    TypedResults (ResultBlock<T> *copyResultSet) :
        ResultIter<T> (copyResultSet)
    {

    }

    TypeTo &
    operator* ()
    {
        yourVal = ResultIter<T>::operator* ();
        myVal = reinterpret_cast<TypeTo*> (&yourVal);
        return *myVal;
    }
    virtual
    ~TypedResults ()
    {

    }
};
}
#endif /* TYPEDRESULTS_H_ */
