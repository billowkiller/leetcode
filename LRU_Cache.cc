/*
 * =====================================================================================
 *
 *       Filename:  LRU_Cache.cc
 *
 *    Description:  Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 
 *
 *        Version:  1.0
 *        Created:  04/25/2014 09:47:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  billowkiller (), billowkiller@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <map>
#include <list>
class LRUCache{
public:
    LRUCache(int capacity):num(0),max(capacity) {
        
    }
    
    int get(int key) {
        mit = cache.find(key);
        if(mit == cache.end())
            return -1;
        else
        {

            return mit->second;
        }
    }
    
    void set(int key, int value) {
        mit = cache.find(key);
        if(mit != cache.end())
            mit->second = value;
        else
        {
            if(num < capacity)
            {
                cache[key] = value;
                lru_list.push_back(make_pair(key, false));
                num++;
            }else{
                for(lit = lru_list->rbegin(); lit!=lru_list->rend(); lit++)
                {
                    if(lit->second==false)
                    {
                        cache.erase(cache.find(lit->first));

                    }
                }
            }

        }
    }

private:
    int num;
    int max;
    list<pair<int, bool>> lru_list;
    list<pair<int, bool>>::iterator lit;
    map<int, int> cache;
    map<int, int>::iterator mit;
};
