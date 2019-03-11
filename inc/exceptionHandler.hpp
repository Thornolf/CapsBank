#ifndef		_EXCEPTION_HANDLER_HPP_
# define	_EXCEPTION_HANDLER_HPP_

#include <exception>
#include <string>

class ExceptionHandler : public std::exception
  {
    public:
      ExceptionHandler(std::string error) throw();
      virtual ~ExceptionHandler() throw() {};
      virtual const char *what() const throw();

    private:
      const std::string	_errorMessage;
};

#endif		/* _EXCEPTION_HANDLER_HPP_ */
