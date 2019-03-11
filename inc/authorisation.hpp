#ifndef		_AUTHORISATION_HPP_
# define	_AUTHORISATION_HPP_

class		Authorisation {
public:
  bool		withdrawRequest() const;
  Authorisation();
  virtual ~Authorisation();
};

#endif		/* _AUTHORISATION_HPP_ */
