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

#ifndef STRUCTURE_DEFS_H_
#define STRUCTURE_DEFS_H_

#include <string>

using namespace std;

#define METADATA_TABLET_COLUMN_FAMILY string("~tab")
#define METADATA_CURRENT_LOCATION_COLUMN_FAMILY string("loc")
#define METADATA_FUTURE_LOCATION_COLUMN_FAMILY string("future")
#define METADATA_LAST_LOCATION_COLUMN_FAMILY string("last")
#define METADATA_PREV_ROW_COLUMN_CQ string("~pr")
#define METADATA_TABLE_ID string("!0")


#endif
