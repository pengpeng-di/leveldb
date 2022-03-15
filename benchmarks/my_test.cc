#include <iostream>
#include <leveldb/db.h>
 
int main (int argc,char * argv[])
{
	leveldb::DB* db;
	leveldb::Options options;
	options.create_if_missing = true;
	std::string dbpath = "testdb";
	leveldb::Status status = leveldb::DB::Open (options, dbpath, &db);
	std::string key = "test";
	std::string val = "test_value";
	status = db->Put (leveldb::WriteOptions (), key, val);
	val.clear ();
	status = db->Get (leveldb::ReadOptions (), key, &val);
 
	std::cout << key << ": " << val << std::endl;
}