#include <cassert>
#include <iostream>
#include <string>
#include <leveldb/db.h>

#define ONE 1

 
int main() 
{
  leveldb::DB* db;
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
  assert(status.ok());
 
  std::string key = "test_key";
  std::string value = "test_value";
  std::string get;
 
  leveldb::Status s = db->Put(leveldb::WriteOptions(), key, value);
  
  if (s.ok()) 
	s = db->Get(leveldb::ReadOptions(), key, &get);
  if (s.ok()) 
	std::cout << "key=" << key << "\nvalue=" << get  << std::endl;
  else 
	std::cout << "failed to find the key!" << std::endl;

  #if defined(ONE)
    std::cout << "呼呼呼" << std::endl;
  #endif
 
  delete db;
 
  return 0;
}
 