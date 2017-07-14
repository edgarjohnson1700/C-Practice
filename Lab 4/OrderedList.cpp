//
//  OrderedList.cpp
//  Lab 4
//
//  Created by dummy on 10/9/15.
//  Copyright (c) 2015 Edgar Johnson. All rights reserved.
//

#ifndef ORDEREDLIST_CPP
#define ORDEREDLIST_CPP



#include "OrderedList.h"


//---------------------------------

template <typename DataType, typename KeytType>
OrderedList<DataType,KeytType>:: OrderedList (int maxNumber)
: List<DataType>(maxNumber)

{}
//-----------------------------------

template<typename DataType, typename KeyType>
void OrderedList<DataType, KeyType>:: insert(const DataType &newDataItem) throw (logic_error)
{
    if (size >= maxSize)
        throw logic_error("list is full");
        
        if (binarySearch(newDataItem.getKey(), cursor))
            dataItems[cursor] = newDataItem;
            else
            {
                for(int j = size - 1; j > cursor; --j)
                    dataItems[j+1] = dataItems[j];
                    ++cursor;
                dataItems[cursor] = newDataItem;
                ++size;
            }
}
//------------------------------------

template <typename DataType, typename KeyType>
bool OrderedList<DataType,KeyType>:: retrieve (const KeyType & searchKey, DataType & searchDataItem)
{
    int holdCursor = cursor;
    bool result = false;
    if (binarySearch(searchKey, cursor))
    {
        searchDataItem = dataItems[cursor];
        result = true;
        
    }
    else
    {
        cursor = holdCursor;
        result = false;
    }
    return result;
}
//-----------------------------------------

template <typename DataType, typename KeyType>
void OrderedList<DataType,KeyType>:: replace(const DataType & newDataItem)
throw (logic_error)
{
    if(size == 0)
        throw logic_error("list is empty");
        if(newDataItem.getKey() == dataItems[cursor].getKey())
            dataItems[cursor] = newDataItem;
            else
            {
                remove();
                insert(newDataItem);
            }
}
//------------------------------------------

template <typename DataType, typename KeyType>
void OrderedList<DataType, KeyType>:: showStructure() const
{
    if(size == 0)
        cout << "Empty list" << endl;
    else
    {
        cout << "size = " << size
        << " cursor = " << cursor << endl;
        for(int j = 0; j < maxSize; ++j)
            cout << j << "\t";
        cout << endl;
        for(int j = 0; j < size; ++j)
        {
            if(j == cursor)
                cout << "[" << dataItems[j].getKey() << "]\t";
            else
                cout << dataItems[j].getKey() << "\t";
        }
        cout << endl;
    }
}
//------------------------------------------

template <typename DataType, typename KeyType>
bool OrderedList<DataType, KeyType>:: binarySearch(KeyType searchKey, int &index)
{
    int low = 0, high = size - 1;
    bool result;
    while (low <= high)
    {
        index = (low + high)/2;
        if(searchKey < dataItems[index].getKey())
            high = index - 1;
        else if(searchKey > dataItems[index].getKey())
            low = index + 1;
        else
            break;
    }
    if(low <= high)
        result = true;
    else
    {
        index = high;
        result = false;
    }
    return result;
    
}
//----------------------------------------------

template <typename DataType, typename KeyType>
void OrderedList<DataType, KeyType>:: merge(const OrderedList<DataType, KeyType> & fromL) throw (logic_error)
{
    int j = size - 1, k = fromL.size -1, m = size + fromL.size - 1;
    if(size + fromL.size > maxSize)
        throw logic_error("merged items do not fit within list");
        
        while ((j >= 0) && (k >= 0))
            if (fromL.dataItems[k].getKey() == dataItems[j].getKey())
                throw logic_error("list are supposed to have no common keys");
                else if(fromL.dataItems[k].getKey() > dataItems[j].getKey())
                    dataItems[m--] = fromL.dataItems[k--];
                    else
                        dataItems[m--] = dataItems[j--];
                        for (m = k; m >= 0; m--)
                            dataItems[m] = fromL.dataItems[m];
                            
                            size += fromL.size;
                            
                            if(size != 0)
                                cursor = 0;
                                }
//-------------------------------------------------

template <typename DataType, typename KeyType>
bool OrderedList<DataType, KeyType>:: isSubset (const OrderedList<DataType, KeyType> &subList)
{
    int j = 0, k = 0;
    bool result = false;
    
    while((j < size) && (k < subList.size))
    {
        if(dataItems[j].getKey() < subList.dataItems[k].getKey())
            j++;
        else if (dataItems[j].getKey() == subList.dataItems[k].getKey())
        {
            j++;
            k++;
        }
        else
            result = false;
    }
    if (k == subList.size)
        result = true;
    else
        result = false;
    
    return result;
}

#endif