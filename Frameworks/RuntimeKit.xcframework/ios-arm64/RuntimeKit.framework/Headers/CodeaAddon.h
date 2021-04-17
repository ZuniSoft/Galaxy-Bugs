//
//  CodeaAddon.h
//  Runtime
//
//  Created by Simeon on 5/04/13.
//  Copyright (c) 2013 Two Lives Left. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CodeaViewController;
struct lua_State;

@protocol CodeaAddon <NSObject>

//For registering your custom functions and libraries
- (void) codea:(CodeaViewController*)controller didCreateLuaState:(struct lua_State*)L;

@optional

//For registering fake custom functions and libraries (if they need to be called outside setup)
- (void) codea:(CodeaViewController*)controller didCreateFakeLuaState:(struct lua_State*)L;

//For clean up (if necessary)
- (void) codea:(CodeaViewController*)controller willCloseLuaState:(struct lua_State*)L;

//Handling changes to the viewer state (if necessary)
- (void) codea:(CodeaViewController*)controller didPause:(BOOL)pause;
- (void) codea:(CodeaViewController*)controller didChangeViewMode:(CodeaViewMode)mode;

//The reset button is pressed, this will cause:
//  willCloseCodeaLuaState and didCreateCodeaLuaState to be called again in sequence
- (void) codeaWillReset:(CodeaViewController*)controller;

//Called each frame update
- (void) codeaWillDrawFrame:(CodeaViewController*)controller withDelta:(CGFloat)deltaTime;

//Called after initial setup
- (void) codeaDidFinishSetup:(CodeaViewController*)controller;

//Called when the addon is registered
- (void) codeaDidRegisterAddon:(CodeaViewController*)controller;

@end
