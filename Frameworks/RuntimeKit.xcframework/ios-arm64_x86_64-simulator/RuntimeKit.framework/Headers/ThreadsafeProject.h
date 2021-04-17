//
//  ThreadsafeProject.h
//  Runtime
//
//  Created by Dylan Sale on 1/08/2014.
//  Copyright (c) 2014 Two Lives Left. All rights reserved.
//

#import "Project.h"

/**
 * Wraps a Project to make it threadsafe.
 * Will apply updates on the thread they are done on, and schedule
 * the update to happen on the wrapped project on the specified dispatch_queue.
 * This must not be used on the same thread as the queue provided or else it will deadlock.
 */
@interface ThreadsafeProject : NSObject //Implements the Project methods, but is not actually a project

+ (instancetype) threadsafeProjectWithProject:(Project*)project onQueue:(dispatch_queue_t)queue;

@property (nonatomic,readonly) NSArray *bufferNames;
@property (readonly) NSArray *buffers;
@property (nonatomic,readonly) NSArray *codeFiles;
@property (nonatomic,readonly) NSArray *dependencies;
@property (nonatomic,readonly) NSString *safeName;

@property (nonatomic, copy) ProjectCreateBufferBlock createBufferAction;

@property (nonatomic,strong) NSDate *lastSave;

@property (nonatomic,readonly) BOOL isLoaded;

- (BOOL) writeToBundlePath:(NSString*)bundlePath;

- (void) load;
- (void) unload;

- (BOOL) hasDependency:(NSString*)projectName;
- (void) addDependency:(NSString*)projectName;
- (void) removeDependency:(NSString*)projectName;

- (BOOL) hasAddon:(NSString*)addonName;
- (void) addAddon:(NSString*)addonName;
- (void) removeAddon:(NSString*)addonName;

- (BOOL) canCreateBufferNamed:(NSString*)newName;
- (BOOL) isBufferNameValid:(NSString*)bufferName;
- (BOOL) hasBufferNamed:(NSString*)bufferName;
- (id) bufferWithName:(NSString*)bufferName;
- (NSInteger) indexOfBufferNamed:(NSString*)bufferName;
- (NSString*) nameForBufferAtIndex:(NSUInteger)bufferIndex;
- (void) renameBufferAtIndex:(NSUInteger)index to:(NSString*)name;

- (BOOL) addBufferNamed:(NSString*)bufferName withContents:(NSString*)contents;
- (BOOL) insertBufferNamed:(NSString*)bufferName withContents:(NSString*)contents atIndex:(NSUInteger)index;
- (void) moveBufferFromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex;

- (BOOL) removeBufferNamed:(NSString*)bufferName;
- (BOOL) removeBufferAtIndex:(NSUInteger)index;

- (void) createIconFromImage:(UIImage *)icon;

//Subclasses may need to implement type specific versions of the following:
- (BOOL) replaceContentsOfBufferNamed:(NSString*)bufferName withContents:(NSString*)contents;
- (NSString*) contentsForBufferNamed:(NSString*)bufferName;
- (NSString*) contentsForBufferAtIndex:(NSUInteger)bufferIndex;

- (id) createBufferWithContents:(NSString*)contents;


//From Bundle
@property (nonatomic, readonly) NSString            *bundlePath;
@property (nonatomic, readonly) NSArray             *files;
@property (nonatomic, strong)   NSDictionary        *info;
@property (nonatomic, strong)   NSString            *name;
@property (nonatomic, readonly) NSArray             *validFileTypes;
@property (nonatomic, readonly) NSDate              *lastModifiedDate;

- (NSString*) fileNameFromBundlePath:(NSString*)path;
- (NSString*) fileNameAtIndex:(NSUInteger)index;

- (void) reloadFilesFromBundlePath;
- (NSMutableDictionary*) defaultInfoDictionary;

- (NSData*) serializedRepresentation;

- (BOOL) isFileValid:(NSString*)path;


@end
