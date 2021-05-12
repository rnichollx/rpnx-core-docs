/**
 @file rpnx/experimental/network.hpp

 This file provides networking support.
*/

#ifndef RPNX_DOC_CONVEYOR_HPP
#define RPNX_DOC_CONVEYOR_HPP

#include <filesystem>
#include <string>
#include <optional>
#include <memory>
#include <utility>

namespace rpnx::experimental
{
	/** 
	    @class ip4_address network.hpp rpnx/experimental/network.hpp
		This class represents an IPv4 address in binary format.
	*/
	class ip4_address
	{
	public:
		
		/** Returns the native IP address representation.
		    Note: This is struct in_addr on Windows, Mac, and Linux.
			The format of struct in_addr differs depending on your operating system.
		*/
		IMPLEMENTATION_DEFINED native() const;
		
		constexpr ip4_address();
		constexpr ip4_address(ip4_address const &);
		constexpr ip4_address(std::uint8_t a, std::uint8_t b, std::uint8_t c, std::uint8_t d);
		constexpr ip4_address(std::array<std::uint8_t, 4>);
		constexpr ip4_address(std::array<std::byte, 4>);
		
		constexpr ip4_address operator |(ip4_address const &) const noexcept;
		constexpr ip4_address operator ^(ip4_address const &) const noexcept;
		constexpr ip4_address operator &(ip4_address const &) const noexcept;
		
		
		constexpr bool operator==(ip4_address const &) const noexcept;
		constexpr bool operator!=(ip4_address const &) const noexcept;
		constexpr bool operator<(ip4_address const &) const noexcept;
		constexpr bool operator<=(ip4_address const &) const noexcept;		
		constexpr bool operator>(ip4_address const &) const noexcept;
		constexpr bool operator>=(ip4_address const &) const noexcept;
		
		/** Returns the byte in the IPv4 address in text-order */
		std::uint8_t & operator[](int index) noexcept;
		
		/** Returns the byte in the IPv4 address in text-order.
            Out of bounds access is undefined behavior. */
		std::uint8_t const & operator[](int index) const noexcept;
		
		/** Returns the byte in the IPv4 address in text-order.
		*/
		std::uint8_t & at(int index);
		
		/** Returns the byte in the IPv4 address in text-order.
		*/
		std::uint8_t const & at(int index) const;
	};
	
	class ip6_address
	{
	public:
		
		/** Returns the native IPv6 address representation.
			The format of struct in_addr differs depending on your operating system.
            Note: On Windows, this returns IN6_ADDR, which contains a union. 
            On compilers that don't support type-punning in C++, the active union 
            field is the .Byte representation.
		*/
		IMPLEMENTATION_DEFINED native() const;
		
		constexpr ip6_address();
		constexpr ip6_address(ip6_address const &);
		constexpr ip6_address(std::array<std::uint8_t, 16>);
		constexpr ip6_address(std::array<std::byte, 16>);
		
		constexpr ip6_address operator |(ip6_address const &) const noexcept;
		constexpr ip6_address operator ^(ip6_address const &) const noexcept;
		constexpr ip6_address operator &(ip6_address const &) const noexcept;
		
		
		constexpr bool operator==(ip6_address const &) const noexcept;
		constexpr bool operator!=(ip6_address const &) const noexcept;
		constexpr bool operator<(ip6_address const &) const noexcept;
		constexpr bool operator<=(ip6_address const &) const noexcept;		
		constexpr bool operator>(ip6_address const &) const noexcept;
		constexpr bool operator>=(ip6_address const &) const noexcept;
		
		/** Returns the byte in the IPv6 address in text-order */
		std::uint8_t & operator[](int index) noexcept;
		
		/** Returns the byte in the IPv6 address in text-order.
            Out of bounds access is undefined behavior. */
		std::uint8_t const & operator[](int index) const noexcept;
		
		/** Returns the byte in the IPv6 address in text-order.
		*/
		std::uint8_t & at(int index);
		
		/** Returns the byte in the IPv6 address in text-order.
		*/
		std::uint8_t const & at(int index) const;
	};
	
	class ip4_endpoint
	{
		public:
		ip4_address& address();
		uint16_t & port();
		ip4_address const & address() const;
		uint16_t const & port() const;
	};
	class ip6_endpoint;
    
    /** This class represents an accepting (server) socket 
        capable of operating in asynchronous mode.
    
    */
    class async_ip6_tcp_acceptor
    {
        
    };
    
    /** This is an asynchronous I/O generator for a async_ip6_tcp_acceptor.
        While this object exists, accept events are generated on the socket.
        
        Note that the lifetime of such events is bound to the async service,
        or, if transferred, to the handling agents.
    
    */
    class async_ip6_tcp_autoacceptor
    {
        
    };


}

#endif
