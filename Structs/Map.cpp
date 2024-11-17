/*#include <string>
#include "Map.hpp"

############################   Templates should not be build in .cpp files   #####################################################################

using namespace std;

template <typename Key, typename Value>
Entry<Key, Value>::Entry()
{
    key = nullptr;
    value = nullptr;
};

template <typename Key, typename Value>
Entry<Key, Value>::Entry(const Key& key, const Value& value)
{
    SetKey(key);
    SetValue(value);
};

template <typename Key, typename Value>
Key& Entry<Key, Value>::GetKey()
{
    return key;
};

template <typename Key, typename Value>
Value& Entry<Key, Value>::GetValue()
{
    return value;
};

template <typename Key, typename Value>
void Entry<Key, Value>::SetKey(const Key& newKey)
{
    key = newKey;
};

template <typename Key, typename Value>
void Entry<Key, Value>::SetValue(const Value& newValue)
{
    value = newValue;
};



//Map


template <typename Key, typename Value>
Map<Key, Value>::Map()
{
    list = new List<Entry>();
}

template <typename Key, typename Value>
Map<Key, Value>::~Map()
{
    
}

template <typename Key, typename Value>
void Map<Key, Value>::Deconstruct()
{
    list.Deconstruct();
}

template <typename Key, typename Value>
int Map<Key, Value>::Size() const
{
    return list.Size();
}

template <typename Key, typename Value>
bool Map<Key, Value>::Empty() const
{
    return list.Empty();
}

template <typename Key, typename Value>
Map<Key, Value>::Iterator Map<Key, Value>::Find(const Key& key) const
{
    Map<Key, Value>::Iterator it;
    for (it = begin(); it != end(); ++it)
    {
        if (it->data.GetKey() == key)
            return it;
    }
    return end();
};

template <typename Key, typename Value>
Map<Key, Value>::Iterator Map<Key, Value>::AddEntry(const Key& key, const Value& value)
{
    Map<Key, Value>::Iterator it;
    for (it = begin(); it != end(); ++it)
    {
        if (it->data.GetKey() == key)
        {
            it->SetValue(value);
            return it;
        }
    }
    it = list.AddElementFront(new Entry(key, value));
    return it;
}


template <typename Key, typename Value>
void Map<Key, Value>::RemoveEntry(const Key& key)
{
    Map<Key, Value>::Iterator it;
    for (it = begin(); it != end(); ++it)
    {
        if (it->data.GetKey() == key)
        {
            list.RemoveElement(it);
        }
    }
}

template <typename Key, typename Value>
void Map<Key, Value>::RemoveEntry(const Iterator& value)
{
    Map<Key, Value>::Iterator it;
    for (it = begin(); it != end(); ++it)
    {
        if (it->data.GetValue() == value)
        {
            list.RemoveElement(it);
        }
    }
}

template <typename Key, typename Value>
Map<Key, Value>::Iterator Map<Key, Value>::begin()
{
    return list.FrontNode();
}

template <typename Key, typename Value>
Map<Key, Value>::Iterator Map<Key, Value>::end()
{
    return list.EndNode();
}
*/