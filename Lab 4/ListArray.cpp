#ifndef LISTARRAY_CPP
#define LISTARRAY_CPP

//using namespace std;


#include <iostream>
#include "ListArray.h"
#include <stdexcept>


template <typename DateType>
List<DateType>::List(int maxNumber)

:maxSize(maxNumber),
size(0),
cursor(-1)
{
    dataItems = new DateType[maxSize];
}
//-----------------------------------------
template <typename DataType>
List<DataType>::List (const List & source)
: maxSize(source.maxSize),
size(source.size),
cursor(source.cursor)
{
    dataItems = new DataType[maxSize];
    for(int i = 0; i < size; i++)
    {
        dataItems[i] = source.dataItems[i];
    }
    
}
//------------------------------------------
template <typename DataType>
List<DataType> & List<DataType>::operator = (const List &source)
{
    if(source.maxSize > maxSize)
    {
        delete [] dataItems;
        dataItems = new DataType[maxSize];
    }
    
    maxSize = source.maxSize;
    size = source.size;
    cursor = source.cursor;
    
    for(int i = 0; i < size; i++)
        dataItems[i] = source.dataItems[i];
    return * this;
}
//---------------------------------------------------
template <typename Datatype>
List<Datatype>::~List()
{
    delete [] dataItems;
}
//----------------------------------------------------
template <typename DataType>
void List<DataType>::insert(const DataType &newDataItem)
throw (logic_error)
{
    int j;
    if(size >= maxSize)
        throw logic_error("list is full\n");
        
        for(j = size; j > cursor+1; j--)
            dataItems[j] = dataItems[j - 1];
            size++;
    dataItems[++cursor] = newDataItem;
}
//------------------------------------------------
template <typename DataType>
void List<DataType>::remove() throw(logic_error)
{
    int j;
    if(size == 0)
        throw logic_error("size == 0\n");
        for(j = cursor; j < size-1; j++)
            dataItems[j] = dataItems[j+1];
            size--;
    if(size == 0)
        cursor = -1;
        else if(size == cursor)
            cursor = 0;
            }
//-----------------------------------------------
template<typename Datatype>
void List<Datatype>::replace(const Datatype &newDataItem)
throw(logic_error)
{
    if(size == 0)
        throw logic_error("size == 0");
        
        dataItems[cursor] = newDataItem;
        }
//------------------------------------------------
template<typename DataType>
void List<DataType>::clear ()
{
    size = 0;
    cursor = -1;
}
//-------------------------------------------
template <typename DataType>
bool List<DataType>::isEmpty () const
{
    return(size == 0);
}
//--------------------------------------------
template<typename DataType>
bool List<DataType>::isFull() const
{
    return(size == maxSize);
}
//--------------------------------------------
template<typename DataType>
void List<DataType>::gotoBeginning() throw(logic_error)
{
    if(size == 0)
        throw logic_error("list is empty");
        
        cursor = 0;
        }
//----------------------------------------------
template<typename DataType>
void List<DataType>::gotoEnd()throw(logic_error)
{
    if(size == 0)
        throw logic_error("list is empty");
        
        cursor = size -1;
        }
//-----------------------------------------------
template<typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)
{
    if(size == 0)
        throw logic_error("list is empty");
        if(cursor != size -1)
        {
            cursor++;
            return true;
        }
        else
            return false;
}
//------------------------------------------------------
template<typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error)
{
    if(size == 0)
        throw logic_error("list is empty");
        if(cursor != 0)
        {
            cursor--;
            return true;
        }
        else
            return false;
}
//---------------------------------------------------------
template<typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error)
{
    if(size == 0)
        throw logic_error("list is empty\n");
        return dataItems[cursor];
}
//------------------------------------------------------
template<typename DataType>
void List<DataType>::showStructure() const
{
    int j;
    if(size == 0)
        cout << "empty list" << endl;
    else
    {
        cout << "size =" << size
        << "cursor =" << cursor << endl;
        for(j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        for(j = 0; j < size; j++)
            if(j == cursor)
            {
                cout << "[";
                cout << dataItems[j]
#ifdef ORDERDLIST_CPP
                .getKey()
#endif
                ;
                cout << "j";
                cout << "\t";
            }
        cout << endl;
    }
}
//------------------------------------------------------
//
//     In-lab operations
//
//-------------------------------------------------------

template<typename DataType>
void List<DataType>::moveToNth(int n)throw(logic_error)
{
    int j;
    DataType temp;
    
    if(size == 0)
        throw logic_error("list is empty");
        if(n >= size|| n < 0)
            throw logic_error("n is not in valid range");
            
            temp = dataItems[cursor];
            if(n < cursor)
                for(j = cursor-1; j >= n; j--)
                    dataItems[j+1] = dataItems[j];
                    else
                        for(j = cursor; j < n; j++)
                            dataItems[j] = dataItems[j+1];
                            dataItems[n] = temp;
                            cursor = n;
                            
                            }
//--------------------------------------------------------

template<typename DataType>
bool List<DataType>::find(const DataType &searchDataItem) throw(logic_error)
{
    if(size == 0)
        throw logic_error("list is empty");
        
        while(cursor < size && dataItems[cursor] != searchDataItem)
            cursor++;
    if(cursor < size)
        return true;
    else
    {
        cursor--;
        return false;
    }
}
#endif


















