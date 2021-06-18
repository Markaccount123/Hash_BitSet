#pragma once 
#include<iostream>
#include<vector>
using namespace std;
namespace wzy
{
	//使用了一个非类型的模板参数，这个N表示常数，表示有多少位
	template<size_t N>
	class bitset
	{
	public:

		bitset()
		{
			//_bits.resize(N / 8 + 1,0);
			_bits.resize((N >> 3)+ 1, 0); //因为+的优先级更高，所以需要加()
		}
		//将第x个位  置为1
		void set(size_t x)
		{
			size_t index = x >> 3; //vector当中的第几个char类型
			size_t num = x % 8;//char类型当中的第几个bit位
			_bits[index] |= (1 << num); //因为按位或只影响这一个bit位
		}
		//将第x个位  置为0
		void reset(size_t x)
		{
			size_t index = x >> 3;
			size_t num = x % 8;
			_bits[index] &= (~(1 << num));
		}

		//如果是1返回真，如果是0返回假
		bool test(size_t x)
		{
			size_t index = x >> 3;
			size_t num = x % 8;
			return _bits[index] & (1 << num); //全零返回假  有一个位非零就返回真
		}
	private:
		std::vector<char> _bits; //对于vector里面每一个存放的都是一个char类型，相当于8个位，可以映射8个数
	};

	//对于多个同名的命名空间编译器会自己把他们合并在一起
	void testbitset()
	{
		bitset<100> bs;
		bs.set(10);
		bs.set(17);
		bs.set(80);

		bs.reset(80);
		bs.set(81);
		
		cout << bs.test(10) << endl;
		cout << bs.test(17) << endl;
		cout << bs.test(80) << endl;
		cout << bs.test(81) << endl;

	}
}