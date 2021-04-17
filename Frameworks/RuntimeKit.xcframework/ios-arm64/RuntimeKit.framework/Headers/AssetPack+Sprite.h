//
//  AssetPack+Sprite.h
//  Runtime
//
//  Created by Simeon on 17/07/13.
//  Copyright (c) 2013 Two Lives Left. All rights reserved.
//

#import "AssetPack.h"

@interface AssetPack (Sprite)

- (NSUInteger) spriteCount;
- (NSString*) retinaSpritePathAtIndex:(NSUInteger)index scale:(CGFloat)scale;
- (NSString*) spritePathAtIndex:(NSUInteger)index;
- (UIImage*) spriteImageAtIndex:(NSUInteger)index;
- (NSString*) spriteNameAtIndex:(NSUInteger)index;

- (BOOL) deleteSpriteAtIndex:(NSUInteger)index andReload:(BOOL)reload;
- (BOOL) deleteSpriteAtIndex:(NSUInteger)index;
- (BOOL) deleteSpritesAtIndices:(NSIndexSet*)set;

@end
