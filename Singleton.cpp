/*
题目: 设计一个类，我们只能生成该类的
一个实例。
*/

class Singleton {
public:
	static Singleton& getInstance() {
		static Singleton m_instance;
		return m_instance;
	}

	// 禁止拷贝与赋值
	Singleton(const Singleton& s) = delete;
	Singleton& operator=(const Singleton& s) = delete;

	~Singleton(){};

private:
	Singleton(){};
};

