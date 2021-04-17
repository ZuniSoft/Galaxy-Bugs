//
//  Bundle.h
//  Codea
//
//  Created by Simeon Saint-Saëns on 2/10/11.
//  Copyright 2011 Two Lives Left. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface Bundle : NSObject
{
@protected
    NSString            *bundlePath;
    NSArray             *validFileTypes;
    NSMutableArray      *files;
    NSString            *name;
    NSMutableDictionary *info;
}

@property (nonnull, atomic, strong)       NSString            *bundlePath;
@property (nonnull, nonatomic, readonly)    NSArray             *files;
@property (nonnull, nonatomic, strong)      NSMutableDictionary *info;
@property (nonnull, nonatomic, strong)      NSString            *name;
@property (nonnull, nonatomic, readonly)    NSString            *localizedName;
@property (nullable, nonatomic, readonly)   UIImage             *icon;
@property (nonnull, nonatomic, readonly)    NSArray             *validFileTypes;
@property (nonnull, nonatomic, readonly)    NSDate              *lastModifiedDate;

+ (nullable instancetype) bundleWithPath:(nonnull NSString*)path;
+ (nullable instancetype) bundleWithPath:(nonnull NSString*)path validFileTypes:(nonnull NSArray*)validExt;

- (nullable instancetype) initWithPath:(nonnull NSString*)path validFileTypes:(nonnull NSArray*)validExt;
- (nullable instancetype) initWithData:(nonnull NSData*)data validFileTypes:(nonnull NSArray*)validExt;

- (nonnull NSString*) fileNameFromBundlePath:(nonnull NSString*)path;
- (nullable NSString*) fileNameAtIndex:(NSUInteger)index;

- (void) createIconFromImage:(nonnull UIImage *)icon;

- (void) updateBundlePath:(nonnull NSString*)updatedPath;
- (void) reloadFilesFromBundlePath;
- (nonnull NSMutableDictionary*) defaultInfoDictionary;

- (nonnull NSData*) serializedRepresentation;

- (BOOL) isFileValid:(nonnull NSString*)path;

- (void) invalidateLastModifiedDate;
- (void) updateLastModifiedDate:(nonnull NSDate *)date updateFileAttributes:(BOOL)update;
- (void) updateLastModifiedDate:(nonnull NSDate *)date;

- (void) writeInfoToBundlePath;

// For subclasses

- (void) willReloadFiles;
- (void) didLoadFile:(nonnull NSString *)path;
- (void) didReloadFiles;

@end
