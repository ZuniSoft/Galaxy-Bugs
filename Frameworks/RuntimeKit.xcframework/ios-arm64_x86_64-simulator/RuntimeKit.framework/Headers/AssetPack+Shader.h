//
//  AssetPack+Shader.h
//  Runtime
//
//  Created by Simeon on 24/08/13.
//  Copyright (c) 2013 Two Lives Left. All rights reserved.
//

#import "AssetPack.h"
#import "ShaderBundle.h"

@interface AssetPack (Shader)

- (ShaderBundle*) createShaderNamed:(NSString*)name withTemplate:(ShaderBundle*)shaderTemplate;
- (ShaderBundle*) createDefaultShaderNamed:(NSString*)name;

- (ShaderBundle*) shaderNamed:(NSString*)name;

@end
