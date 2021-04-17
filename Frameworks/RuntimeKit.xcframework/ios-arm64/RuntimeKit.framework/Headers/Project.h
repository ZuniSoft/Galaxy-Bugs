//
//  Project.h
//  Codea
//
//  Created by Dylan Sale on 26/01/12.
//  Copyright (c) 2012 Two Lives Left. All rights reserved.
//

#import "Bundle.h"

typedef void(^ProjectCreateBufferBlock)(id _Nonnull buffer);

@interface Project : Bundle
{
@protected
    NSMutableArray *bufferNames;
    NSMutableArray *buffers;
}

@property (nonatomic,readonly,nonnull) NSArray<NSString*> *bufferNames;
@property (readonly,nonnull) NSArray *buffers;
@property (nonatomic,readonly,nonnull) NSArray<NSString*> *codeFiles;
@property (nonatomic,readonly,nonnull) NSArray<NSString*> *dependencies;
@property (nonatomic,readonly,nonnull) NSArray<NSString*> *addons;
@property (nonatomic,readonly,nonnull) NSString *safeName;

@property (nonatomic,copy,nullable) ProjectCreateBufferBlock createBufferAction;

@property (nonatomic,strong,nullable) NSDate *lastSave;

@property (nonatomic,readonly) BOOL isLoaded;

//Creates a copy of the project by opening the bundle again and loading it.
+ (nonnull instancetype) projectWithProject:(nonnull Project*)project;
+ (nullable instancetype) projectWithBundlePath:(nonnull NSString *)path;

- (BOOL) writeToBundlePath:(nonnull NSString*)bundlePath;

- (void) load;
- (void) unload;

- (BOOL) hasDependency:(nonnull NSString*)projectName;
- (void) addDependency:(nonnull NSString*)projectName;
- (void) removeDependency:(nonnull NSString*)projectName;

- (BOOL) hasAddon:(nonnull NSString*)addonName;
- (void) addAddon:(nonnull NSString*)addonName;
- (void) removeAddon:(nonnull NSString*)addonName;

- (BOOL) canRenameBufferNamed:(nonnull NSString*)name toName:(nonnull NSString*)newName;
- (BOOL) canCreateBufferNamed:(nonnull NSString*)newName;
- (BOOL) isBufferNameValid:(nonnull NSString*)bufferName;
- (BOOL) hasBufferNamed:(nonnull NSString*)bufferName;
- (nullable id) bufferWithName:(nonnull NSString*)bufferName;
- (NSInteger) indexOfBufferNamed:(nonnull NSString*)bufferName;
- (nullable NSString*) nameForBufferAtIndex:(NSUInteger)bufferIndex;
- (void) renameBufferAtIndex:(NSUInteger)index to:(nonnull NSString*)name;

- (BOOL) addBufferNamed:(nonnull NSString*)bufferName withContents:(nullable NSString*)contents;
- (BOOL) insertBufferNamed:(nonnull NSString*)bufferName withContents:(nullable NSString*)contents atIndex:(NSUInteger)index;
- (void) moveBufferFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex;

- (BOOL) removeBufferNamed:(nonnull NSString*)bufferName;
- (BOOL) removeBufferAtIndex:(NSUInteger)index;

//Subclasses may need to implement type specific versions of the following:
- (BOOL) replaceContentsOfBufferNamed:(nonnull NSString*)bufferName withContents:(nullable NSString*)contents;
- (nullable NSString*) contentsForBufferNamed:(nonnull NSString*)bufferName;
- (nullable NSString*) contentsForBufferAtIndex:(NSUInteger)bufferIndex;

- (nonnull id) createBufferWithContents:(nonnull NSString*)contents;

+ (nonnull NSArray<NSString*> *) supportedAssetFileExtensions;
+ (nonnull NSArray<NSString*> *) supportedFileExtensions;

- (nonnull NSString *) stringRepresentation;

@end
