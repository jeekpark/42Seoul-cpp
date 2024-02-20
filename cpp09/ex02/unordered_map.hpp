#pragma once
#ifndef UNORDERED_MAP_CUSTOM
#define UNORDERED_MAP_CUSTOM

template<typename Tkey, typename Tvalue, typename Tcontainer = std::vector<std::pair<Tkey, Tvalue > > >
class unordered_map
{};

template<typename Tkey>
class unordered_map<Tkey, std::deque<Tkey>, std::deque<std::pair<Tkey, std::deque<Tkey> > > >
{
public:
unordered_map(void) : mMap() {}
std::deque<Tkey>& operator[](Tkey key)
{
    for (typename std::deque<std::pair<Tkey, std::deque<Tkey> > >::iterator it = mMap.begin(); it != mMap.end(); ++it)
    {
    if (it->first == key)
    {
        return it->second;
    }
    }
    mMap.push_back(std::pair<Tkey, std::deque<Tkey> >(key, std::deque<Tkey>()));
    return mMap.back().second;
}
private:
std::deque<std::pair<Tkey, std::deque<Tkey> > > mMap;
};

template<typename Tkey>
class unordered_map<Tkey, std::vector<Tkey>, std::vector<std::pair<Tkey, std::vector<Tkey> > > >
{
public:
unordered_map(void) : mMap() {}
std::vector<Tkey>& operator[](Tkey key)
{
    for (typename std::vector<std::pair<Tkey, std::vector<Tkey> > >::iterator it = mMap.begin(); it != mMap.end(); ++it)
    {
    if (it->first == key)
    {
        return it->second;
    }
    }
    mMap.push_back(std::pair<Tkey, std::vector<Tkey> >(key, std::vector<Tkey>()));
    return mMap.back().second;
}
private:
std::vector<std::pair<Tkey, std::vector<Tkey> > > mMap;
};

#endif