//
//  ProjectAddon.m
//  CodeaProject
//
//  Created by Simeon Saint-Saens on 17/3/19.
//  Copyright © 2019 Two Lives Left. All rights reserved.
//

#import "ProjectAddon.h"

#include "ModuleIncludes.h"

#import "ProjectModule.h"

@interface ProjectAddon ()
    @property (nullable, nonatomic, assign) lua_State* L;
    @property (nullable, nonatomic, weak) CodeaViewController* controller;
@end

@implementation ProjectAddon

+ (NSArray*) defaultModules
{
    return @[
             [ProjectModule new],
            ];
}
    
- (void)codea:(CodeaViewController *)controller didCreateLuaState:(struct lua_State *)L {
    self.L = L;
    self.controller = controller;
    
    for(id<Module> module in [ProjectAddon defaultModules]) {
        [module registerForAddon:self];
    }
}
    
- (void)codeaWillDrawFrame:(CodeaViewController *)controller withDelta:(CGFloat)deltaTime {
}
    
- (void)codeaDidFinishSetup:(CodeaViewController *)controller {
    if( self.ready ) {
        self.ready(self);
    }
}
    
@end
