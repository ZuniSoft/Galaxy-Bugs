//
//  ShaderBundle.h
//  Codea
//
//  Created by Simeon on 30/09/12.
//  Copyright (c) 2012 Developer. All rights reserved.
//

#import "Bundle.h"

struct lua_State;

@interface ShaderBundle : Bundle
{
    NSArray *buffers;
    NSArray *bufferNames;
}

@property (nonatomic,readonly) id vertexShader;
@property (nonatomic,readonly) id fragmentShader;
@property (nonatomic,strong) UIImage *icon;

@property (nonatomic,readonly) NSArray *bufferNames;
@property (readonly) NSArray *buffers;

@property (nonatomic,readonly) BOOL isLoaded;

+ (id) shader;
+ (id) shaderWithPath:(NSString *)path;
- (id) initWithPath:(NSString *)path;

- (NSString*) contentsForBufferAtIndex:(NSUInteger)bufferIndex;
- (NSString*) contentsForVertexBuffer;
- (NSString*) contentsForFragmentBuffer;

- (void) loadFromShader:(ShaderBundle*)shader;

- (BOOL) save;

- (void) unload;
- (void) load;

- (int) pushToLuaState:(struct lua_State*)L;

@end
