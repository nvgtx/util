#ifndef _UINT128_H_
#define _UINT128_H_

class uint128
{
public:
	uint64 high;
	uint64 low;

public:

	/////////////////////////////////////////////////////////////////////////////////////
	//Constructors
	uint128()
	{
		this->high=0;
		this->low=0;
	}
	uint128(const uint128 &val)
	{
		this->high=val.high;
		this->low=val.low;
	}
	uint128(const uint64 &val)
	{
		this->high=0;
		this->low=val;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	//Basic assignment
	// =
	uint128 operator=(const uint128 &val){
		this->high=val.high;
		this->low=val.low;
		return *this;
	}
	uint128 operator=(const uint64 &val){
		this->high=0;
		this->low=val;
		return *this;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	//Arithmetic operators
	// +
	uint128 operator+(const uint128 &val){
		uint128 result;
		result.high=this->high + val.high;
		result.low=this->low + val.low;

		if(result.low < this->low){
			++result.high;
		}
		return result;
	}
	uint128 operator+(const uint64 &val){
		return (*this)+(uint128)val;
	}

	// +=
	uint128 operator+=(const uint128 &val){
		(*this)=(*this)+val;
		return *this;
	}
	uint128 operator+=(const uint64 &val){
		(*this)=(*this)+(uint128)val;
		return *this;
	}

	// ++
	uint128 operator++(){
		(*this)=(*this)+1;
		return *this;
	}
	uint128 operator++(int){
		(*this)=(*this)+1;
		return *this;
	}

	// -
	uint128 operator-(const uint128 &val){
		uint128 result;
		result.high=this->high - val.high;
		result.low=this->low - val.low;

		if(result.low > this->low){
			--result.high;
		}
		return result;
	}
	uint128 operator-(const uint64 &val){
		return (*this)-(uint128)val;
	}

	// -=
	uint128 operator-=(const uint128 &val){
		(*this)=(*this)-val;
		return *this;
	}
	uint128 operator-=(const uint64 &val){
		(*this)=(*this)-(uint128)val;
		return *this;
	}

	// --
	uint128 operator--(){
		(*this)=(*this)-1;
		return *this;
	}
	uint128 operator--(int){
		(*this)=(*this)-1;
		return *this;
	}

	// *
	uint128 operator*(const uint128 &val){
		uint128 result=0;
		uint128 i=0;

		for(i=0; i<val; i++){
			result+=(*this);
		}
		return result;
	}
	uint128 operator*(const uint64 &val){
		return (*this)*(uint128)val;
	}

	// *=
	uint128 operator*=(const uint128 &val){
		(*this)=(*this)*val;
		return *this;
	}
	uint128 operator*=(const uint64 &val){
		(*this)=(*this)*(uint128)val;
		return *this;
	}

	// %
	uint128 operator%(const uint128 &val){
		uint128 result;

		//if high-word unused
		if(val.high==0 && this->high==0)
		{
			result.high=0;
			result.low=this->low % val.low;
			return result;
		}
		// %2
		if(val.high==0 && val.low==2)
		{
			return (*this) & 0x1;
		}

		result.high=this->high;
		result.low=this->low;

		while(result>val){
			result-=val;
		}
		return result;
	}
	uint128 operator%(const uint64 &val){
		return (*this)%(uint128)val;
	}

	// %=
	uint128 operator%=(const uint128 &val){
		(*this)=(*this)%val;
		return *this;
	}
	uint128 operator%=(const uint64 &val){
		(*this)=(*this)%(uint128)val;
		return *this;
	}

	// /
	uint128 operator/(const uint128 &val){
		uint128 result;
		uint128 i=0;

		//if high-word unused
		if(val.high==0 && this->high==0)
		{
			result.high=0;
			result.low=this->low / val.low;
			return result;
		}

		result.high=this->high;
		result.low=this->low;

		for(i=0; result>=val; i++){
			result-=val;
		}
		return i;
	}
	uint128 operator/(const uint64 &val){
		return (*this)/(uint128)val;
	}

	// /=
	uint128 operator/=(const uint128 &val){
		(*this)=(*this)/val;
		return *this;
	}
	uint128 operator/=(const uint64 &val){
		(*this)=(*this)/(uint128)val;
		return *this;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	//Bitwise operators
	// <<
	uint128 operator<<(const uint128 &val){
		uint128 result;
		uint128 i=0;

		//if high-word unused
		if(val.high==0)
		{
			result.high=(this->high << val.low) | (this->low >> (sizeof(uint64)*8-val.low));
			result.low=this->low << val.low;
			return result;
		}

		result.high=this->high;
		result.low=this->low;

		for(i=0; i<val; i++){
			result.high=(result.high << 1) | (result.low >> (sizeof(uint64)*8-1));
			result.low=result.low << 1;
		}
		return result;
	}
	uint128 operator<<(const uint64 &val){
		return (*this)<<(uint128)val;
	}

	// <<=
	uint128 operator<<=(const uint128 &val){
		(*this)=(*this)<<val;
		return *this;
	}
	uint128 operator<<=(const uint64 &val){
		(*this)=(*this)<<(uint128)val;
		return *this;
	}

	// >>
	uint128 operator>>(const uint128 &val){
		uint128 result;
		uint128 i=0;

		//if high-word unused
		if(val.high==0)
		{
			result.low=(this->low >> val.low) | (this->high << (sizeof(uint64)*8-val.low));
			result.high=this->high >> val.low;
			return result;
		}

		result.high=this->high;
		result.low=this->low;

		for(i=0; i<val; i++){
			result.low=(result.low >> 1) | (result.high << (sizeof(uint64)*8-1));
			result.high=result.high >> 1;
		}
		return result;
	}
	uint128 operator>>(const uint64 &val){
		return (*this)>>(uint128)val;
	}

	// >>=
	uint128 operator>>=(const uint128 &val){
		(*this)=(*this)>>val;
		return *this;
	}
	uint128 operator>>=(const uint64 &val){
		(*this)=(*this)>>(uint128)val;
		return *this;
	}

	// ^
	uint128 operator^(const uint128 &val){
		uint128 result;
		result.high=this->high ^ val.high;
		result.low=this->low ^ val.low;
		return result;
	}
	uint128 operator^(const uint64 &val){
		return (*this)^(uint128)val;
	}

	// ^=
	uint128 operator^=(const uint128 &val){
		(*this)=(*this)^val;
		return *this;
	}
	uint128 operator^=(const uint64 &val){
		(*this)=(*this)^(uint128)val;
		return *this;
	}

	// &
	uint128 operator&(const uint128 &val){
		uint128 result;
		result.high=this->high & val.high;
		result.low=this->low & val.low;
		return result;
	}
	uint128 operator&(const uint64 &val){
		return (*this)&(uint128)val;
	}

	// &=
	uint128 operator&=(const uint128 &val){
		(*this)=(*this)&val;
		return *this;
	}
	uint128 operator&=(const uint64 &val){
		(*this)=(*this)&(uint128)val;
		return *this;
	}

	// |
	uint128 operator|(const uint128 &val){
		uint128 result;
		result.high=this->high | val.high;
		result.low=this->low | val.low;
		return result;
	}
	uint128 operator|(const uint64 &val){
		return (*this)|(uint128)val;
	}

	// |=
	uint128 operator|=(const uint128 &val){
		(*this)=(*this)|val;
		return *this;
	}
	uint128 operator|=(const uint64 &val){
		(*this)=(*this)|(uint128)val;
		return *this;
	}

	// ~
	uint128 operator~(){
		uint128 result;
		result.high=~this->high;
		result.low=~this->low;
		return result;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	//Logical operators

	// !
	//implemented in bool

	// &&
	//implemented in bool

	// ||
	//implemented in bool

	/////////////////////////////////////////////////////////////////////////////////////
	//Comparison operators / Relational operators
	// <
	const bool operator<(const uint128 &val){
		if(this->high < val.high)		{return true;}
		else if(this->high == val.high)	{if(this->low < val.low){return true;}}
		return false;
	}
	const bool operator<(const uint64 &val){
		return (*this)<(uint128)val;
	}

	// <=
	const bool operator<=(const uint128 &val){
		if(this->high < val.high)		{return true;}
		else if(this->high == val.high)	{if(this->low <= val.low){return true;}}
		return false;
	}
	const bool operator<=(const uint64 &val){
		return (*this)<=(uint128)val;
	}

	// >
	const bool operator>(const uint128 &val){
		if(this->high > val.high)		{return true;}
		else if(this->high == val.high)	{if(this->low > val.low){return true;}}
		return false;
	}
	const bool operator>(const uint64 &val){
		return (*this)>(uint128)val;
	}

	// >=
	const bool operator>=(const uint128 &val){
		if(this->high > val.high)		{return true;}
		else if(this->high == val.high)	{if(this->low >= val.low){return true;}}
		return false;
	}
	const bool operator>=(const uint64 &val){
		return (*this)>=(uint128)val;
	}

	//==
	const bool operator==(const uint128 &val){
		if(this->high == val.high && this->low == val.low){return true;}
		return false;
	}
	const bool operator==(const uint64 &val){
		return (*this)==(uint128)val;
	}

	//!=
	const bool operator!=(const uint128 &val){
		if(this->high == val.high && this->low == val.low){return false;}
		return true;
	}
	const bool operator!=(const uint64 &val){
		return (*this)!=(uint128)val;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	//Other operators
	uint128 operator&(){
		return *this;
	}
};

#endif /* _UINT128_H_ */