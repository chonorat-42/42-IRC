#ifndef USEREXCEPTIONS_HPP
#define USEREXCEPTIONS_HPP
#include <exception>
#include <string>

class UserConnectionException : public std::exception
{
	private:
		std::string message;
	public:
		UserConnectionException(const std::string& str) throw() ;
		~UserConnectionException() throw();
		const char *what() const throw();
};

class UserBuildException : public std::exception
{
	private:
		std::string message;
	public:
		UserBuildException(const std::string& str) throw() ;
		~UserBuildException() throw();
		const char *what() const throw();
};

class UserCacheException : public std::exception
{
	private:
		size_t userId;
		std::string message;
	public:
		UserCacheException(size_t userId, const std::string& str) throw() ;
		~UserCacheException() throw();
		const char *what() const throw();
};

#endif
