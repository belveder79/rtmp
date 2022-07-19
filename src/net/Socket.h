// PHZ
// 2018-5-15

#ifndef XOP_SOCKET_H
#define XOP_SOCKET_H

#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(ANDROID)
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#if !defined(__APPLE__)
  #include <netinet/ether.h>
  #include <netpacket/packet.h>
  #include <net/route.h>
#endif
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <net/if.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/select.h>
#define SOCKET int
#define INVALID_SOCKET  (-1)
#define SOCKET_ERROR    (-1)

#define DLL_API

#elif defined(WIN32) || defined(_WIN32)
#define FD_SETSIZE      1024
#define WIN32_LEAN_AND_MEAN
#ifndef _WINSOCK_DEPRECATED_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#endif
#include <WinSock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#define SHUT_RD 0
#define SHUT_WR 1
#define SHUT_RDWR 2

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

#else

#endif

#if defined(ANDROID)
	#include <android/log.h>
	#ifndef MODULE_NAME
		#define MODULE_NAME "RTMPSERVER"
	#endif
#endif

#include <cstdint>
#include <cstring>

#endif // _XOP_SOCKET_H
