#pragma once

#include <cstddef>
#include <list>
#include <utility>

template<typename Tkey, typename Tvalue, typename Tcontainer = std::list<std::pair<Tkey, std::list<Tkey> > > >
class unordered_map
{};

template<typename Tkey>
class unordered_map<Tkey, std::list<Tkey>, std::list<std::pair<Tkey, std::list<Tkey> > > >
{
public:
  unordered_map(void) : mMap() {}
  std::list<Tkey>& operator[](Tkey key)
  {
    for (typename std::list<std::pair<Tkey, std::list<Tkey> > >::iterator it = mMap.begin(); it != mMap.end(); ++it)
    {
      if (it->first == key)
      {
        return it->second;
      }
    }
    mMap.push_back(std::pair<Tkey, std::list<Tkey> >(key, std::list<Tkey>()));
    return mMap.back().second;
  }
private:
  std::list<std::pair<Tkey, std::list<Tkey> > > mMap;
};

