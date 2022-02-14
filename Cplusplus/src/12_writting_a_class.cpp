#include <iostream>

class Log
{
public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;
private:
	int m_logLevel = LogLevelInfo;
public:
	void setLogLevel(int level)
	{
		m_logLevel = level;
	}

	void Error(const char* message)
	{
		if (m_logLevel >= LogLevelError)
			std::cout << "[ERROR]: " << message << std::endl;
	}
	void Warn(const char* message)
	{
		if (m_logLevel >= LogLevelWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}
	void Info(const char* message)
	{
		if (m_logLevel >= LogLevelInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}
};

int writting_a_class()
{
	Log log;
	log.setLogLevel(log.LogLevelInfo);
	log.Warn("Hello");
	log.Error("Hello");
	log.Info("Hello");
	std::cin.get();
	return 0;
}