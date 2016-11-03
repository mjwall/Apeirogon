/**
 * Hello, this is Apeirogon, a free and open implementation of a c++
 * big table connector. Copyright (C)  2016
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
#ifndef UTIL_BTREE_SAFE_BTREE_MAP_H__
#define UTIL_BTREE_SAFE_BTREE_MAP_H__

#include <functional>
#include <memory>
#include <utility>

#include "btree_container.h"
#include "btree_map.h"
#include "safe_btree.h"

namespace btree
{

// The safe_btree_map class is needed mainly for its constructors.
  template<typename Key, typename Value, typename Compare = std::less<Key>,
      typename Alloc = std::allocator<std::pair<const Key, Value> >,
      int TargetNodeSize = 256>
    class safe_btree_map : public btree_map_container<
	safe_btree<btree_map_params<Key, Value, Compare, Alloc, TargetNodeSize> > >
    {

      typedef safe_btree_map<Key, Value, Compare, Alloc, TargetNodeSize> self_type;
      typedef btree_map_params<Key, Value, Compare, Alloc, TargetNodeSize> params_type;
      typedef safe_btree<params_type> btree_type;
      typedef btree_map_container<btree_type> super_type;

    public:
      typedef typename btree_type::key_compare key_compare;
      typedef typename btree_type::allocator_type allocator_type;

    public:
      // Default constructor.
      safe_btree_map (const key_compare &comp = key_compare (),
		      const allocator_type &alloc = allocator_type ()) :
	  super_type (comp, alloc)
      {
      }

      // Copy constructor.
      safe_btree_map (const self_type &x) :
	  super_type (x)
      {
      }

      // Range constructor.
      template<class InputIterator>
	safe_btree_map (InputIterator b, InputIterator e,
			const key_compare &comp = key_compare (),
			const allocator_type &alloc = allocator_type ()) :
	    super_type (b, e, comp, alloc)
	{
	}
    };

  template<typename K, typename V, typename C, typename A, int N>
    inline void
    swap (safe_btree_map<K, V, C, A, N> &x, safe_btree_map<K, V, C, A, N> &y)
    {
      x.swap (y);
    }

} // namespace btree

#endif  // UTIL_BTREE_SAFE_BTREE_MAP_H__
