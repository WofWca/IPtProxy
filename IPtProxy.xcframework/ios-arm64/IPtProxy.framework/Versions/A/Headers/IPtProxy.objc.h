// Objective-C API for talking to github.com/tladesignz/IPtProxy.git Go package.
//   gobind -lang=objc github.com/tladesignz/IPtProxy.git
//
// File is generated by gobind. Do not edit.

#ifndef __IPtProxy_H__
#define __IPtProxy_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"


@protocol IPtProxySnowflakeClientConnected;
@class IPtProxySnowflakeClientConnected;

@protocol IPtProxySnowflakeClientConnected <NSObject>
/**
 * Connected - callback method to handle snowflake proxy client connections.
 */
- (void)connected;
@end

@interface IPtProxy : NSObject
/**
 * StateLocation - Override TOR_PT_STATE_LOCATION, which defaults to "$TMPDIR/pt_state".
 */
+ (NSString* _Nonnull) stateLocation;
+ (void) setStateLocation:(NSString* _Nonnull)v;

@end

/**
 * IsPortAvailable - Checks to see if a given port is not in use.

@param port The port to check.
 */
FOUNDATION_EXPORT BOOL IPtProxyIsPortAvailable(long port);

/**
 * IsSnowflakeProxyRunning - Checks to see if a snowflake proxy is running in your app.
 */
FOUNDATION_EXPORT BOOL IPtProxyIsSnowflakeProxyRunning(void);

/**
 * MeekPort - Port where Obfs4proxy will provide its Meek service.
Only use this after calling StartObfs4Proxy! It might have changed after that!
 */
FOUNDATION_EXPORT long IPtProxyMeekPort(void);

/**
 * Obfs2Port - Port where Obfs4proxy will provide its Obfs2 service.
Only use this property after calling StartObfs4Proxy! It might have changed after that!
 */
FOUNDATION_EXPORT long IPtProxyObfs2Port(void);

/**
 * Obfs3Port - Port where Obfs4proxy will provide its Obfs3 service.
Only use this property after calling StartObfs4Proxy! It might have changed after that!
 */
FOUNDATION_EXPORT long IPtProxyObfs3Port(void);

/**
 * Obfs4Port - Port where Obfs4proxy will provide its Obfs4 service.
Only use this property after calling StartObfs4Proxy! It might have changed after that!
 */
FOUNDATION_EXPORT long IPtProxyObfs4Port(void);

/**
 * Obfs4ProxyVersion - The version of Obfs4Proxy bundled with IPtProxy.
 */
FOUNDATION_EXPORT NSString* _Nonnull IPtProxyObfs4ProxyVersion(void);

/**
 * Obfs4proxyLogFile - The log file name used by Obfs4proxy.

The Obfs4proxy log file can be found at `filepath.Join(StateLocation, Obfs4proxyLogFile())`.
 */
FOUNDATION_EXPORT NSString* _Nonnull IPtProxyObfs4proxyLogFile(void);

/**
 * ScramblesuitPort - Port where Obfs4proxy will provide its Scramblesuit service.
Only use this property after calling StartObfs4Proxy! It might have changed after that!
 */
FOUNDATION_EXPORT long IPtProxyScramblesuitPort(void);

/**
 * SnowflakePort - Port where Snowflake will provide its service.
Only use this property after calling StartSnowflake! It might have changed after that!
 */
FOUNDATION_EXPORT long IPtProxySnowflakePort(void);

/**
 * SnowflakeVersion - The version of Snowflake bundled with IPtProxy.
 */
FOUNDATION_EXPORT NSString* _Nonnull IPtProxySnowflakeVersion(void);

/**
 * StartObfs4Proxy - Start the Obfs4Proxy.

This will test, if the default ports are available. If not, it will increment them until there is.
Only use the port properties after calling this, they might have been changed!

@param logLevel Log level (ERROR/WARN/INFO/DEBUG). Defaults to ERROR if empty string.

@param enableLogging Log to TOR_PT_STATE_LOCATION/obfs4proxy.log.

@param unsafeLogging Disable the address scrubber.

@param proxy HTTP, SOCKS4 or SOCKS5 proxy to be used behind Obfs4proxy. E.g. "socks5://127.0.0.1:12345"

@return Port number where Obfs4Proxy will listen on for Obfs4(!), if no error happens during start up.

	If you need the other ports, check MeekPort, Obfs2Port, Obfs3Port and ScramblesuitPort properties!
 */
FOUNDATION_EXPORT long IPtProxyStartObfs4Proxy(NSString* _Nullable logLevel, BOOL enableLogging, BOOL unsafeLogging, NSString* _Nullable proxy);

/**
 * StartSnowflake - Start the Snowflake client.

@param ice Comma-separated list of ICE servers.

@param url URL of signaling broker.

@param front Front domain.

@param ampCache OPTIONAL. URL of AMP cache to use as a proxy for signaling.

	Only needed when you want to do the rendezvous over AMP instead of a domain fronted server.

@param logFile Name of log file. OPTIONAL. Defaults to no log.

@param logToStateDir Resolve the log file relative to Tor's PT state dir.

@param keepLocalAddresses Keep local LAN address ICE candidates.

@param unsafeLogging Prevent logs from being scrubbed.

@param maxPeers Capacity for number of multiplexed WebRTC peers. DEFAULTs to 1 if less than that.

@return Port number where Snowflake will listen on, if no error happens during start up.
 */
FOUNDATION_EXPORT long IPtProxyStartSnowflake(NSString* _Nullable ice, NSString* _Nullable url, NSString* _Nullable front, NSString* _Nullable ampCache, NSString* _Nullable logFile, BOOL logToStateDir, BOOL keepLocalAddresses, BOOL unsafeLogging, long maxPeers);

/**
 * StartSnowflakeProxy - Start the Snowflake proxy.

@param capacity Maximum concurrent clients. OPTIONAL. Defaults to 10, if 0.

@param broker Broker URL. OPTIONAL. Defaults to https://snowflake-broker.torproject.net/, if empty.

@param relay WebSocket relay URL. OPTIONAL. Defaults to wss://snowflake.bamsoftware.com/, if empty.

@param stun STUN URL. OPTIONAL. Defaults to stun:stun.stunprotocol.org:3478, if empty.

@param natProbe OPTIONAL. Defaults to https://snowflake-broker.torproject.net:8443/probe, if empty.

@param logFile Name of log file. OPTIONAL. Defaults to STDERR.

@param keepLocalAddresses Keep local LAN address ICE candidates.

@param unsafeLogging Prevent logs from being scrubbed.

@param clientConnected A delegate which is called when a client successfully connected.

	Will be called on its own thread! You will need to switch to your own UI thread,
	if you want to do UI stuff!! OPTIONAL
 */
FOUNDATION_EXPORT void IPtProxyStartSnowflakeProxy(long capacity, NSString* _Nullable broker, NSString* _Nullable relay, NSString* _Nullable stun, NSString* _Nullable natProbe, NSString* _Nullable logFile, BOOL keepLocalAddresses, BOOL unsafeLogging, id<IPtProxySnowflakeClientConnected> _Nullable clientConnected);

/**
 * StopObfs4Proxy - Stop the Obfs4Proxy.
 */
FOUNDATION_EXPORT void IPtProxyStopObfs4Proxy(void);

/**
 * StopSnowflake - Stop the Snowflake client.
 */
FOUNDATION_EXPORT void IPtProxyStopSnowflake(void);

/**
 * StopSnowflakeProxy - Stop the Snowflake proxy.
 */
FOUNDATION_EXPORT void IPtProxyStopSnowflakeProxy(void);

@class IPtProxySnowflakeClientConnected;

/**
 * SnowflakeClientConnected - Interface to use when clients connect
to the snowflake proxy. For use with StartSnowflakeProxy
 */
@interface IPtProxySnowflakeClientConnected : NSObject <goSeqRefInterface, IPtProxySnowflakeClientConnected> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * Connected - callback method to handle snowflake proxy client connections.
 */
- (void)connected;
@end

#endif
