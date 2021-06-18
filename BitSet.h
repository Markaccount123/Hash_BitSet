#pragma once 
#include<iostream>
#include<vector>
using namespace std;
namespace wzy
{
	//ʹ����һ�������͵�ģ����������N��ʾ��������ʾ�ж���λ
	template<size_t N>
	class bitset
	{
	public:

		bitset()
		{
			//_bits.resize(N / 8 + 1,0);
			_bits.resize((N >> 3)+ 1, 0); //��Ϊ+�����ȼ����ߣ�������Ҫ��()
		}
		//����x��λ  ��Ϊ1
		void set(size_t x)
		{
			size_t index = x >> 3; //vector���еĵڼ���char����
			size_t num = x % 8;//char���͵��еĵڼ���bitλ
			_bits[index] |= (1 << num); //��Ϊ��λ��ֻӰ����һ��bitλ
		}
		//����x��λ  ��Ϊ0
		void reset(size_t x)
		{
			size_t index = x >> 3;
			size_t num = x % 8;
			_bits[index] &= (~(1 << num));
		}

		//�����1�����棬�����0���ؼ�
		bool test(size_t x)
		{
			size_t index = x >> 3;
			size_t num = x % 8;
			return _bits[index] & (1 << num); //ȫ�㷵�ؼ�  ��һ��λ����ͷ�����
		}
	private:
		std::vector<char> _bits; //����vector����ÿһ����ŵĶ���һ��char���ͣ��൱��8��λ������ӳ��8����
	};

	//���ڶ��ͬ���������ռ���������Լ������Ǻϲ���һ��
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