 ///
 /// @file    string.cc
 /// @author  zhy(GitHub:Charles-joy)
 /// @date    2018-04-11 23:01:19
 ///

#include <string.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
class String
{
public:
		String()
		: _pstr(new char[1])
		{
			_pstr[0]='\0';
			cout << "String () 无参 _pstr =" << _pstr << endl; 
		}
		String(const char *pstr)
		: _pstr(new char[strlen(pstr)+1]())
		{
			strcpy(_pstr,pstr);
			cout << "String(const String *pstr)"  << endl;
		}

		String(const String &rhs)
		: _pstr(new char[strlen(rhs._pstr)+1]())
		{
			strcpy(_pstr,rhs._pstr);
			cout << "String(const String &rhs)" << endl;
		}

		String & operator =(const String & rhs)
		{
			strcpy(_pstr,rhs._pstr);
			cout << "String & operator =(const String & rhs)"  << endl;
			return (*this);
		}

		~String()
		{
			delete  []_pstr;
			cout << "~String()" << endl;
		}

		void print()
		{
		
			cout << _pstr << endl;

		}

private:
		char * _pstr;
};

int main (void)
{

	String str1;
	str1.print();

	String str2 ="Hello,world";
	String str3("wangdao");

	str2.print();
	str3.print();

	String str4=str3;
	str4.print();

	str4=str2;
	str4.print();

	return 0;

}
