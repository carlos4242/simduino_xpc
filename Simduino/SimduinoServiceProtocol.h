//
//  SimduinoProtocol.h
//  Simduino
//
//  Created by Carl Peto on 31/01/2020.
//  Copyright © 2020 Carl Peto. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SIMDUINO_GDB_PORT 7979

typedef NS_ENUM(NSUInteger, SimduinoDebugType) {
    noDebug = 0,
    debugNoWait = 1,
    debugAndWait = 2
};

@protocol SimduinoServiceProtocol

// start a simduino instance, either with a specific ELF file
// or by default if that's not specified then run a bootloader
- (void)startupSimduinoWithExecutable:(NSString * _Nullable)filename
                                debug:(SimduinoDebugType)debugIn
                            withReply:(void (^ _Nonnull)(NSString * _Nullable))ptyNameCallbackIn;


- (void)shutdownSimduino:(void (^ _Nonnull)(void))ptyClosedCallbackIn;
- (void)restartSimduino:(void (^ _Nonnull)(void))restartedCallbackIn;

- (void)loadNewExecutable:(NSString * _Nullable)filename
                withReply:(void (^ _Nonnull)(BOOL))callback;

@end

@protocol SimduinoHostProtocol<NSObject>

- (void)LChanged:(BOOL)newValue;
- (void)simduinoLogMessage:(NSString * _Nonnull)message level:(NSInteger)logLevel;

@end
