//
//  CodeaScriptExecute.h
//  Codea
//
//  Created by Simeon Saint-Saëns on 9/20/11.
//  Copyright 2011 Two Lives Left. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CodeaLuaState.h"

@class Project;

@protocol ScriptValidateErrorDelegate <NSObject>
- (void) error:(LuaError)error inBuffer:(NSString*)bufferName inProject:(NSString*)projectPath;

- (void) error:(LuaError)error inBuffer:(NSString*)bufferName inDependentProject:(NSString*)projectName forProject:(NSString*)projectPath;

- (void) shouldClearErrorForBuffer:(NSString*)bufferName inProject:(NSString*)projectPath;

- (void) shouldClearErrorForBuffer:(NSString*)bufferName inDependentProject:(NSString*)projectName forProject:(NSString*)projectPath;

@end

@interface CodeaScriptExecute : NSObject

@property(nonatomic, weak) id<ScriptValidateErrorDelegate> errorDelegate;

- (id) initWithCodeaContext:(id)context;
- (BOOL) validateProject:(Project*)project;
- (BOOL) runProject:(Project*)project;

@end
