//
//  CraftAddon.h
//  Craft
//
//  Created by John Millard on 17/06/2016.
//  Copyright © 2016 Two Lives Left. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RuntimeKit/RuntimeKit.h>

FOUNDATION_EXPORT NSString *const kCraftAddonKey;

@interface CraftAddon : NSObject <CodeaAddon>

//For registering your custom functions and libraries
- (void) codea:(CodeaViewController*)controller didCreateLuaState:(struct lua_State*)L;

- (void) codea:(CodeaViewController*)controller didCreateFakeLuaState:(struct lua_State*)L;

//For clean up (if necessary)
- (void) codea:(CodeaViewController*)controller willCloseLuaState:(struct lua_State*)L;

//Handling changes to the viewer state (if necessary)
- (void) codea:(CodeaViewController*)controller didPause:(BOOL)pause;
- (void) codea:(CodeaViewController*)controller didChangeViewMode:(CodeaViewMode)mode;

//The reset button is pressed, this will cause:
//  willCloseLuaState and didCreateLuaState to be called again in sequence
- (void) codeaWillReset:(CodeaViewController*)controller;

//Called each frame update
- (void) codeaWillDrawFrame:(CodeaViewController*)controller withDelta:(CGFloat)deltaTime;

//Called when the addon is registered
- (void) codeaDidRegisterAddon:(CodeaViewController*)controller;

//Can be used to prevent the initialization of bullet
+ (void) setBulletPhysicsSystemEnabled:(BOOL)enabled;

+ (void) applicationDidLaunch;

@end
