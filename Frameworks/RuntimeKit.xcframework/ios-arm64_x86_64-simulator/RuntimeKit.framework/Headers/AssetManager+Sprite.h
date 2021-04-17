//
//  AssetManager+Sprite.h
//  Runtime
//
//  Created by Simeon on 27/07/13.
//  Copyright (c) 2013 Two Lives Left. All rights reserved.
//

#import "AssetManager.h"

@class CCTexture2D;
@class TextureCache;

@interface AssetManager (Sprite)

@property (nonatomic, readonly) NSArray *includedSpritePacks;
@property (nonatomic, readonly) NSArray *userSpritePacks;
@property (nonatomic, readonly) NSArray *availableSpritePacks;

- (CCTexture2D*) spriteTextureFromString:(NSString*)spriteString cache:(TextureCache*)cache;
- (CCTexture2D*) spriteTextureFromString:(NSString*)spriteString width:(CGFloat)width cache:(TextureCache*)cache;
- (CCTexture2D*) spriteTextureFromString:(NSString*)spriteString width:(CGFloat)width height:(CGFloat)height cache:(TextureCache*)cache;

- (CCTexture2D*) spriteTextureFromPath:(NSString*)spritePath cache:(TextureCache*)cache;
- (CCTexture2D*) spriteTextureFromPath:(NSString*)spritePath width:(CGFloat)width cache:(TextureCache*)cache;
- (CCTexture2D*) spriteTextureFromPath:(NSString*)spritePath width:(CGFloat)width height:(CGFloat)height cache:(TextureCache*)cache;

- (UIImage*) spriteImageFromString:(NSString*)spriteString;
- (UIImage*) spriteImageFromString:(NSString*)spriteString atHeight:(CGFloat)height;
- (UIImage*) spriteImageFromString:(NSString*)spriteString atWidth:(CGFloat)width;

@end
