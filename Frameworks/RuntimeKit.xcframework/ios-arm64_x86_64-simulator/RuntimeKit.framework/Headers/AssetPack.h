//
//  AssetPack.h
//  Runtime
//
//  Created by John Millard on 15/06/13.
//  Copyright (c) 2013 Two Lives Left. All rights reserved.
//

#import "Bundle.h"

@interface AssetPack : Bundle

@property (nonatomic, assign) BOOL userPack;

// Different common filters used by categories
@property (nonatomic, readonly) NSArray *spriteFiles;
@property (nonatomic, readonly) NSArray *soundFiles;
@property (nonatomic, readonly) NSArray *musicFiles;
@property (nonatomic, readonly) NSArray *textFiles;
@property (nonatomic, readonly) NSArray *modelFiles;

- (NSArray*) filterFilesWithExtensions:(NSArray*)extensions;
- (BOOL) supportsAssetType:(NSString*)assetType;

- (NSArray*) assetNames;
- (NSArray*) filterAssetNamesWithExtensions:(NSArray*)extensions;

- (BOOL) deleteAssetAtIndex:(NSInteger)index andReload:(BOOL)reload;
- (BOOL) deleteAssetAtIndex:(NSInteger)index;
- (BOOL) deleteAssetsAtIndices:(NSIndexSet*)set;

- (BOOL) addAssetFromPath:(NSString*)path;
- (BOOL) addAssetFromPath:(NSString*)path shouldOverwrite:(BOOL)overwrite;
- (BOOL) addAssetsFromPaths:(NSArray*)paths shouldOverwrite:(BOOL)overwrite;
- (BOOL) containsDuplicateAsset:(NSString*)path;

- (NSString*) assetPathForKey:(NSString*)key mustExist:(BOOL)exist;
- (NSString*) assetPathForKey:(NSString*)key limitedToExtensions:(NSArray*)extensions  mustExist:(BOOL)exist;

+ (NSArray*) supportedExtensionsFromAssetTypes:(NSArray *)types;
+ (NSArray*) supportedExtensionsFromAssetType:(NSString *)type;

+ (NSString*) typeFromAssetExtension:(NSString*)ext;
+ (NSString*) typeFromAssetFile:(NSString*)path;

+ (NSArray *) allFileExtensions;
+ (NSArray *) assetFileExtensions;
+ (NSArray *) spriteFileExtensions;
+ (NSArray *) soundFileExtensions;
+ (NSArray *) musicFileExtensions;
+ (NSArray *) shaderFileExtensions;
+ (NSArray *) textFileExtensions;
+ (NSArray *) modelFileExtensions;

@end
