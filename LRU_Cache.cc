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
using namespace std;
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
			int r = mit->second->second;
			lru_list.erase(mit->second);
			lru_list.push_front(make_pair(key, r));
			cache[key] = lru_list.begin();
            return r;
        }
    }
    
    void set(int key, int value) {
		if(get(key) != -1)
		{
			mit = cache.find(key);
            mit->second->second = value;
		}
        else
        {
            if(num < max)
            {
                lru_list.push_front(make_pair(key, value));
				cache[key] = lru_list.begin();
                num++;
            }else{
				mit = cache.find(lru_list.back().first);
				cache.erase(mit);
				lru_list.pop_back();
                lru_list.push_front(make_pair(key, value));
				cache[key] = lru_list.begin();
                num++;
            }

        }
    }

private:
    int num;
    int max;
	typedef list<pair<int, int> > ListType;
    ListType lru_list;
	ListType::iterator lit;
    map<int, ListType::iterator> cache;
    map<int, ListType::iterator>::iterator mit;
};
