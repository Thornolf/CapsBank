#include "exceptionHandler.hpp"

ExceptionHandler::ExceptionHandler(std::string errorMsg) throw() : _errorMessage(errorMsg) {}

const char	*ExceptionHandler::what() const throw()
{
  return (this->_errorMessage.c_str());
}
